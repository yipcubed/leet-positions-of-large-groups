#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/positions-of-large-groups/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string &s) {
        vector<vector<int>> v;
        if (s.size() < 3) return v;
        int start = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] != s[start]) {
                if (i - start > 2) {
                    v.push_back(vector<int>{start, i - 1});
                }
                start = i;
            }
        }
        // last one
        if (s.length() - 1 - start >= 2) {
            v.push_back(vector<int>{start, static_cast<int>(s.length() - 1)});
        }
        return v;
    }
};

void test1() {
    string s1 = "abbxxxxzzy";

    cout << "[[3 6]] ? " << Solution().largeGroupPositions(s1) << endl;
}

void test2() {

}

void test3() {

}