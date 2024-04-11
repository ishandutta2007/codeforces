#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, r1, r2, r3, d;
int a[N];

// cost 0 : dead
// cost 1 : not dead
long long cost[2][N];
long long dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 0;
    r1 = min(r1, r3);
    for (int i = 1; i <= n; i++) {
        cost[0][i] = 1ll * r1 * a[i] + r3;
        cost[1][i] = min(1ll * r2, 1ll * (a[i] + 1) * r1);
        dp[i] = dp[i - 1] + min(cost[0][i], 2ll * d + cost[1][i] + r1);
        if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + 2ll * d + cost[1][i] + cost[1][i - 1] + 2ll * r1);
        // cout << i << ' ' << dp[i] << ' ' << cost[0][i] << ' ' << cost[1][i] << endl;
    }
    long long res = dp[n];
    long long sum = min(cost[0][n], cost[1][n] + 2ll * d + r1);
    for (int i = n - 1; i; i--) {
        sum += min(cost[0][i], cost[1][i] + r1);
        long long now = dp[i - 1] + 1ll * (n - i) * d;
        res = min(res, now + sum);
    }
    cout << res + 1ll * (n - 1) * d << endl;
    return 0;
}