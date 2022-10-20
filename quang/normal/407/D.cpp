#include <bits/stdc++.h>

using namespace std;

const int N = 410;

short last[N][N * N];
short dp[2][N][N];
int a[N][N];
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    for (int col = 1, cur = 0; col <= m; col++, cur ^= 1) {
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                dp[cur][i][j] = dp[cur ^ 1][i][j];
                if (i == j) dp[cur][i][j] = max(dp[cur][i][j], last[i][a[i][col]]);
                else {
                    dp[cur][i][j] = max(dp[cur][i][j], dp[cur][i + 1][j]);
                    dp[cur][i][j] = max(dp[cur][i][j], dp[cur][i][j - 1]);
                    dp[cur][i][j] = max(dp[cur][i][j], last[i][a[j][col]]);
                    dp[cur][i][j] = max(dp[cur][i][j], last[j][a[i][col]]);
                    if (a[i][col] == a[j][col]) dp[cur][i][j] = col;
                }
                res = max(res, len * (col - dp[cur][i][j]));
            }
        }
        for (int i = 1; i <= n; i++) {
            last[i][a[i][col]] = col;
        }
    }
    cout << res << endl;
    return 0;
}