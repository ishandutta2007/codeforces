#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define make_pair mp 
#define first x
#define second y
#define pb(a) push_back(a)
#define sz(a) (int)(a.size()) 
#define mod 998244353 
const int N = 2e5 + 7;
int n, k, ans; 
ll tk;
int qpow(int x, int y) {
    if(x == 0) return 0;
    int res = 1;
    for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
    return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int jc[N], njc[N];
int C(int x, int y) { return 1ll * jc[x] * njc[x - y] % mod * njc[y] % mod; }
int get(int x) { return 1ll * qpow(n - x, n) * C(n, n - x) % mod; }
int main() {
    scanf("%d%lld", &n, &tk);
    jc[0] = njc[0] = 1;
    L(i, 1, n) jc[i] = 1ll * jc[i - 1] * i % mod, njc[i] = ny(jc[i]);
    if(tk > 1ll * n) return printf("0\n"), 0;
    k = tk;
    if(k == 0) return printf("%d\n", jc[n]), 0;
    L(i, k, n) (ans += 1ll * ((i - k) % 2 == 1 ? mod - 1 : 1) * C(i, k) % mod * get(i) % mod) %= mod;
    printf("%d\n", ans * 2 % mod);
    return 0;
}