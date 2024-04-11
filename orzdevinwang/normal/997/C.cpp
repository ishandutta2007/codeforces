#include<bits/stdc++.h>
#define mod 998244353
#define N 1100000
using namespace std;
int qpow(int aa, int bb) {
    int res = 1;
    while(bb) {
        if(bb & 1) res = 1ll * res * aa % mod;
        aa = 1ll * aa * aa % mod, bb >>= 1;
    }
    return res;
}
int ny(int aa) {
    return qpow(aa, mod-2);
}
int n, ans, jc[N], res;
int C(int aa, int bb) {
    return 1ll * jc[aa] * ny(jc[bb]) % mod * ny(jc[aa-bb]) % mod;
}
int fp(int aa) {
    return (aa & 1 ? mod - 1 : 1);
}
int main() {
    scanf("%d", &n);
    jc[0] = 1;
    for(int i = 1; i <= n; i++) jc[i] = 1ll * jc[i-1] * i % mod;
    res = 0;
    for(int i = 1; i <= n; i++) 
        res = (res + 1ll * C(n, i) * fp(i) % mod * qpow(3, (1ll * n * (n - i) + i) % (mod - 1)) % mod) % mod;
    ans = res * 2 % mod, res = 0;
    for(int i = 1; i <= n; i++) {
        res = (res + 1ll * C(n, i) * fp(i) % mod * (qpow((qpow(3, n-i) - 1) % mod, n) - qpow(qpow(3,n - i), n) + mod)) % mod;
    }
    // for(int i = 1; i <= n; i++) 
    //     for(int j = 1; j <= n; j++) 
    //         res = (res + 1ll * C(n,i) * C(n,j) % mod * qpow(3, (n-i) * (n-j) % (mod - 1)) % mod * fp(i+j) % mod) % mod; 
    ans = (ans + 3ll * res % mod) % mod;
    printf("%d\n",(mod - ans) % mod);
    return 0;
}