#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e6 + 5;

int n;
ll a[N], r1, r2, r3, d, dp[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[1][0] = r1 * a[1] + r3;
    dp[1][1] = 2 * d + r1 + min(r1 * a[1] + r1, r2);

    for (int i = 2; i <= n; i++) {
        ll min_val = r1 + min(r1 * a[i] + r1, r2);

        dp[i][0] = min(dp[i - 1][1] + min_val + d, d + r1 * a[i] + r3 + min(dp[i - 1][0], dp[i - 1][1]));
        dp[i][1] = min_val + 3 * d + dp[i - 1][0];
    }

    ll ans = min(dp[n][0], dp[n][1]);

    ll sum = min(r1 * a[n] + r3, 2 * d + r1 + min(r1 * a[n] + r1, r2));
    for (int i = n - 1; i >= 1; i--) {
        sum += min(r1 * a[i] + r3, r1 + min(r1 * a[i] + r1, r2));
        ans = min(ans, 2 * (n - i) * d + (i != 1) * d + sum + min(dp[i - 1][1], dp[i - 1][0]));
    }

    cout << ans << '\n';
    return 0;
}