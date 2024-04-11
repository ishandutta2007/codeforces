#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> ans(n);
    vector<int> ans2(n);
    vector<int> cur;
    vector<int> cur2;
    int last = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (cur.empty() || cur.back() != i + 1 || s[i + 1] != s[i]) {
            if (cur.empty()) cur2.push_back(0);
            else if (s[cur.back()] != s[i]) cur2.push_back(cur.size());
            else cur2.push_back(cur2.back());
            cur.push_back(i);
        } else {
            if (cur.size() == 1) {
                cur.clear();
                cur2.clear();
            } else if (cur2.back() == 0 || s[cur[cur2.back()-1]] < s[i]) {
                cur.pop_back();
                cur2.pop_back();
            } else {
                cur.push_back(i);
                cur2.push_back(cur2.back());
            }
        }
        string answw = "";
        if (cur.size() > 10) {
            for (int j = (int) cur.size() - 1; j >= (int) cur.size() - 5; --j) answw += s[cur[j]];
            answw += "...";
            answw += s[cur[1]];
            answw += s[cur[0]];
        } else {
            for (auto &j: cur) answw += s[j];
            reverse(all(answw));
        }
        ans[i] = answw;
        ans2[i] = cur.size();
    }
    range(i, n) cout << ans2[i] << " " << ans[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}