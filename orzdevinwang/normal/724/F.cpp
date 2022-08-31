#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 1111;
const int M = 12;
int n, d, mod, f[N], g[N];
int qpow(int x, int y) {
    int res = 1;
    for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
    return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int dp[M][N], ans;
int main() { 
    scanf("%d%d%d", &n, &d, &mod);
    if(n <= 2) return puts("1"), 0;
    dp[0][0] = 1;
    L(i, 1, n / 2) {
        if(i == 1) f[i] = 1;
        else f[i] = dp[d - 1][i - 1];
        g[0] = 1; 
        L(t, 1, d) g[t] = 1ll * g[t - 1] * (f[i] + t - 1) % mod * ny(t) % mod;
        R(t, d, 1) L(p, 1, t) L(j, i * p, n) (dp[t][j] += 1ll * g[p] * dp[t - p][j - i * p] % mod) %= mod; 
    }
    int ans = dp[d][n - 1];
    if(n % 2 == 0) (ans += mod - 1ll * dp[d - 1][n / 2 - 1] * (dp[d - 1][n / 2 - 1] - 1) / 2 % mod) %= mod;
    printf("%d\n", ans);
    return 0;
}