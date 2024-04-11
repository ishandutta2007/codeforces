#include <bits/stdc++.h>

using namespace std;

const int N = 710;

int n;
int a[N];
bool dp[2][N][N];
bool can[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    memset(dp, 1, sizeof dp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            can[i][j] = __gcd(a[i], a[j]) > 1;
            if (i <= j) {
                dp[0][i][j] = dp[1][i][j] = 0;
            }
        }
    }
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int m = l; m <= r && (!dp[0][l][r] || !dp[1][l][r]); m++) {
                if (dp[1][l][m - 1] && dp[0][m + 1][r]) {
                    if (can[l - 1][m] || l - 1 == 0) {
                        dp[0][l][r] = 1;
                    }
                    if (can[m][r + 1] || r + 1 == n + 1) {
                        dp[1][l][r] = 1;
                    }
                }
            }
            // cout << l << " " << r << " " << dp[0][l][r] << " " << dp[1][l][r] << endl;
        }
    }
    if (dp[0][1][n] || dp[1][1][n]) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}