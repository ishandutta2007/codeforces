#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--) 
#define ll long long 
#define db double 
#define pb(a) push_back(a)
#define sz(a) (int)(a.size())
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
int n, k, dz[N], jc[N], prod, ans;
int qpow(int x, int y) {
    int res = 1;
    for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
    return res;
}
int ny(int x) { return qpow(x, mod -2); }
int main() {
    scanf("%d%d", &n, &k);
    jc[0] = 1;
    L(i, 1, k + 1) jc[i] = 1ll * jc[i - 1] * i % mod;
    prod = n;
    L(i, 1, k + 1) dz[i] = (dz[i - 1] + qpow(i, k)) % mod, prod = 1ll * prod * (n - i) % mod;
    if(n <= k + 1) return printf("%d\n", dz[n]), 0;
    L(i, 0, k + 1) {
        int res = 1ll * ((k - i + 1) % 2 == 0 ? 1 : mod - 1) * dz[i] % mod * prod % mod * ny(n - i) % mod;
        (ans += 1ll * res * ny(1ll * jc[i] * jc[k + 1 - i] % mod) % mod) %= mod;
    }
    printf("%d\n", ans);
    return 0;
}