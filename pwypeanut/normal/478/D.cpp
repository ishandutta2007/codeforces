#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int R, G, H, cur, dp[2][400005];

int main() {
    scanf("%d%d", &R, &G);
    for (H = 1; ; H++) {
        cur += H;
        if (cur > R + G) {
            cur -= H;
            H--;
            break;
        }
    }
    dp[0][R] = 1;
    for (int i = 1; i <= H; i++) {
        for (int j = 0; j <= R; j++) {
            dp[1][j] = dp[0][j + i];
            dp[1][j] += dp[0][j];
            dp[1][j] %= MOD;
            //printf("%d %d: %d\n", i, j, dp[1][j]);
        }
        for (int j = 0; j <= R; j++) dp[0][j] = dp[1][j];
    }
    int minR = cur - G;
    int ans = 0;
    for (int i = 0; i <= R - minR; i++) {
        ans += dp[0][i];
        ans %= MOD;
    }
    printf("%d\n", ans);
}