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
    int n, k, z;
    cin >> n >> k >> z;
    vector<vector<int>> dp(z + 1, vector<int>(n, -INFi));
    vector<int> a(n);
    range(i, n) cin >> a[i];
    dp[0][0] = a[0];
    for (int i = 1; i <= k; ++i) {
        dp[0][i] = dp[0][i - 1] + a[i];
    }
    int ans = dp[0][k];
    for (int e = 1; e <= z; ++e) {
        for (int i = 0; i < n; ++i) {
            if (i != n - 1 && dp[e - 1][i + 1] != -INFi)
                dp[e][i] = max(dp[e][i], dp[e - 1][i + 1] + a[i]);
            if (i != 0 && dp[e][i - 1] != -INFi) dp[e][i] = max(dp[e][i], dp[e][i - 1] + a[i]);
        }
        if (k - e * 2 >= 0) ans = max(ans, dp[e][k - e * 2]);
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