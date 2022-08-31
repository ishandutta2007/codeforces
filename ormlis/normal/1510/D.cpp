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

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 1e7 + 100;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, d; cin >> n >> d;
    vector<vector<int>> p(n + 1, vector<int> (10, -1));
    vector<vector<int>> was(n + 1, vector<int> (10, -1));
    vector<vector<ld>> dp(n + 1, vector<ld> (10, -INF));
    dp[0][1] = log(1);
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        dp[i] = dp[i - 1];
        range(j, 10) p[i][j] = j;
        range(j, 10) {
            if (dp[i - 1][j] == -INF) continue;
            int w = (j * x) % 10;
            ld cur = log(x) + dp[i - 1][j];
            if (dp[i][w] <= cur) {
                dp[i][w] = cur;
                was[i][w] = x;
                p[i][w] = j;
            }
        }
    }
    if (dp[n][d] == -INF) {
        cout << "-1\n";
        return;
    }
    vector<int> res;
    for(int i = n; i >= 1; --i) {
        if (was[i][d] != -1) res.push_back(was[i][d]);
        d = p[i][d];
    }
    if (res.empty()) {
        cout << "-1\n";
        return;
    }
    cout << res.size() << '\n';
    for(auto &x : res) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}