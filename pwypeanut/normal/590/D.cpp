#include <bits/stdc++.h>
using namespace std;

int N, K, S, arr[155], dp[2][155][12005];

int main() {
    scanf("%d%d%d", &N, &K, &S);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    S = min(S, N * (N-1) / 2);
    memset(dp, 127, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= S; k++) {
                dp[i % 2][j][k] = dp[!(i % 2)][j][k];
                if (j > 0 && k >= (i - j)) dp[i % 2][j][k] = min(dp[!(i % 2)][j][k], dp[!(i % 2)][j - 1][k - (i - j)] + arr[i - 1]);
                //printf("%d %d %d = %d\n", i, j, k, dp[i % 2][j][k]);
            }
        }
    }
    int ans = 2000000000;
    for (int i = 0; i <= S; i++) ans = min(ans, dp[N % 2][K][i]);
    printf("%d\n", ans);
}