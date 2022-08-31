#include<bits/stdc++.h>
#define N 2510
#define M 100010
#define mod 1000000007
using namespace std;
int qpow(int x, int y) {
    if(x == 0) return 0;
    int res = 1;
    for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
    return res;
}
int n, s, qny, a[N], dp[M], cc, ans, maxn;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), s = (a[i] + s) % mod, maxn = max(maxn, a[i]);
    dp[1] = 1ll * qpow(s, mod - 2) * (s - 1) % mod * (s - 1) % mod;
    cc = (dp[1] - 1) % mod;
    for(int i = 2; i <= maxn; i++) {
        dp[i] = (cc + dp[i - 1]) % mod;
        cc = (cc - 1ll * qpow((s - i + mod) % mod, mod - 2) * (s - 1) % mod + mod) % mod;
    }
    for(int i = 1; i <= n; i++) ans = (ans + dp[a[i]]) % mod;
    printf("%d\n", ans);
    return 0;
}