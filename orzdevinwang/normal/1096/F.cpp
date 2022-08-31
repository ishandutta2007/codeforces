#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--) 
#define ll long long
#define db double
#define mod 998244353
const int N = 1e6 + 7;
int n, m, a[N], qz[N], mp[N], cnt[N], jc[N];
int sz[N], ans;
int qpow(int x, int y) {
    int res = 1;
    for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
    return res;
}
int ny(int x) { return qpow(x, mod - 2); }
void add(int x, int y) { for(; x <= n; x += x & -x) sz[x] += y; }
int query(int x) {
    int sum = 0;
    for(; x; x -= x & -x) sum += sz[x];
    return sum;
}
int main() {
    scanf("%d", &n);
    jc[0] = 1;
    L(i, 1, n) jc[i] = 1ll * jc[i - 1] * i % mod;
    L(i, 1, n) {
        scanf("%d", &a[i]);
        if(a[i] == -1) ++m;
        else mp[a[i]] = 1;
        qz[i] = m;
    }
    L(i, 1, n) cnt[i] = cnt[i - 1] + (mp[i] == 0);
    L(i, 1, n) if(a[i] != -1) (ans += i - qz[i] - query(a[i]) - 1) %= mod, add(a[i], 1); //  
    (ans += 1ll * m * (m - 1) / 2 % mod * ny(2) % mod) %= mod; // 0  0
    L(i, 1, n) { // 0
        if(a[i] != -1) {
            (ans += 1ll * ny(m) * (m - cnt[a[i]]) % mod * qz[i] % mod) %= mod; // 
            (ans += 1ll * ny(m) * cnt[a[i]] % mod * (m - qz[i]) % mod) %= mod; // 
        }
    }
    printf("%d\n", ans);
    return 0;
}