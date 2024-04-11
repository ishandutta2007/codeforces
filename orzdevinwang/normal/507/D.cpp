#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
#define db double
using namespace std;
const int N = 1005;
const int K = 105;
int n, k, mod, dp[N][N], bs[N], gs[N], ans;
signed main() {
    scanf("%d%d%d", &n, &k, &mod);
    bs[0] = gs[0] = 1;
    L(i, 1, n) bs[i] = 1ll * bs[i - 1] * 10 % mod, gs[i] = 1ll * gs[i - 1] * 10 % k;
    L(i, 1, 9) dp[1][i % k]++, dp[1][i % k] %= mod;
    L(i, 2, n) {
        L(j, 1, k) L(d, (i == n), 9) (dp[i][(gs[i - 1] * d + j) % k] += dp[i - 1][j]) %= mod;
        L(d, 1, 9) (dp[i][gs[i - 1] * d % k] += 1) %= mod;
    }
    ans = dp[n][0];
    L(i, 1, n - 1) (ans += 9ll * bs[n - i - 1] % mod * dp[i][0] % mod) %= mod;
    printf("%d\n", ans % mod);
    return 0;
}