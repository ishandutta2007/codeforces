#include<bits/stdc++.h>
#define N 110000
#define mod 1000000007
#define int long long
using namespace std;
bool Prime[N];
int n, p[N], mu[N], tot;
void xxs() {
    mu[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!Prime[i]) p[++tot] = i, mu[i] = mod - 1;
        for(int j = 1; j <= tot && p[j] * i <= n; j++) {
            Prime[p[j] * i] = 1;
            if(i % p[j] == 0) {
                mu[p[j] * i] = 0;
                break;
            }
            mu[p[j] * i] = 1ll * mu[p[j]] * mu[i] % mod;
        }
    }
    for(int i = 1; i <= n; i++) (mu[i] += mu[i - 1]) %= mod;
}
int qpow(int x, int y) {
    if(!x) return 0;
    int Ans = 1;
    for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) Ans = 1ll * Ans * x % mod;
    return Ans;
}
int ny(int x) {
    return qpow(x, mod - 2);
}
signed main() {
    scanf("%lld", &n);
    xxs();
    int Ans = 0;
    for(int l = 2, r; l <= n; l = r + 1) {
        r = n / (n / l);
        (Ans += 1ll * (mu[r] - mu[l - 1] + mod) % mod * ny(mod + 1 - 1ll * ny(n / l) * n % mod) % mod) %= mod;
    }
    (Ans += 1) %= mod; 
    printf("%lld\n", Ans);
    return 0;
}