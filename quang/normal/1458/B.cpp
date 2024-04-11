#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int a[N], b[N];
int dp[2][N][N * N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        tot += b[i];
    }
    int cur = 0;
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++, cur ^= 1) {
        for (int j = 0; j <= i + 1; j++) {
            for (int k = 0; k < N * N; k++) {
                dp[cur ^ 1][j][k] = -1;
            }
        }
        for (int j = 0; j <= i; j++) {
            for (int k = j; k < N * N; k++) {
                if (dp[cur][j][k] == -1) continue;
                dp[cur ^ 1][j][k] = max(dp[cur ^ 1][j][k], dp[cur][j][k]);
                if (k + a[i] < N * N) {
                    dp[cur ^ 1][j + 1][k + a[i]] = max(dp[cur ^ 1][j + 1][k + a[i]], dp[cur][j][k] + b[i]);
                }
            }
        }
    }
    for (int j = 1; j <= n; j++) {
        int res = 0;
        for (int k = 0; k < N * N; k++) {
            if (dp[cur][j][k] == -1) continue;
            res = max(res, min(k * 2, dp[cur][j][k] + tot));
        }
        cout << res / 2 << '.' << (res % 2 ? 5 : 0) << ' ';
    }
    cout << '\n';
    return 0;
}