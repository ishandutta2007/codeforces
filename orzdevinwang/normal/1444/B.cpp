#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
const int N = 1e6 + 7;
const int mod = 998244353;
int n;
ll a[N], ans;
int qpow(int x, int y) {
    int res = 1;
    for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
    return res;
}
int main() {
    scanf("%d", &n);
    L(i, 1, n * 2) scanf("%lld", &a[i]);
    sort(a + 1, a + n * 2 + 1);
    L(i, 1, n) (ans += mod - a[i]) %= mod;
    L(i, n + 1, n * 2) (ans += a[i]) %= mod;
    L(i, 1, n) ans = 1ll * ans * qpow(i, mod - 2) % mod;
    L(i, n + 1, n * 2) ans = 1ll * ans * i % mod; 
    printf("%lld\n", ans);
    return 0;
}