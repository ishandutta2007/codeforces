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
#include <numeric>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;
    vector<int> t(n);
    range(i, n) cin >> t[i];
    sort(all(t));
    int k = n * 3 + 5;
    vector<vector<int>> dp(k, vector<int>(n + 1, INFi));
    dp[0][0] = 0;
    int ans = INFi;
    for (int i = 1; i < k; ++i) {
        dp[i][0] = 0;
        for (int e = 1; e <= n; ++e) {
            for (int c = 0; c < i; ++c) {
                if (dp[c][e - 1] == INFi) continue;
                dp[i][e] = min(dp[c][e - 1] + abs(i - t[e - 1]), dp[i][e]);
            }
        }
        ans = min(ans, dp[i][n]);
    }
    cout << ans << "\n";
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