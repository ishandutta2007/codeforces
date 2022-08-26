#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <random>
#include <chrono>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
using namespace std;

const int INFi = 1e9;

void solve() {
    string s;
    cin >> s;
    vector<vector<int>> cnt(10);
    range(i, (int) s.size()) {
        cnt[s[i] - '0'].push_back(i);
    }
    int ans = 0;
    range(i, 10) ans = max(ans, (int) cnt[i].size());
    range(i, 10) {
        range(j, i) {
            int cc = 0;
            vector<int> b;
            merge(all(cnt[i]), all(cnt[j]), back_inserter(b));
            int prev = -1;
            for (auto &x: b) {
                if (s[x] - '0' != prev) {
                    cc++;
                    prev = s[x] - '0';
                }
            }
            ans = max(ans, cc - cc % 2);
        }
    }
    cout << (int) s.size() - ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}