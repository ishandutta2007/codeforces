#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

template<class T> T& cmin(T& a, const T& b) { if(b < a) a = b; return a; }
template<class T> T& cmax(T& a, const T& b) { if(a < b) a = b; return a; }

#ifndef local
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace std;
using ll = long long;

const int N = 3e5 + 5, P = 998244353;

int n, fac[N], ifac[N], f[N], a[1 << 20], b[1 << 20];

int lim = 1, w[23], iw[23];

inline int add(int a, int b) { return (a += b) < P ? a : a - P; }
inline int sub(int a, int b) { return (a -= b) < 0 ? a + P : a; }
ll Pow(ll a, int n, ll r = 1) {
    for(; n; n >>= 1, a = a * a % P)
    if(n & 1) r = r * a % P;
    return r;
}
void prework() {
    ll es[22], ies[22];
    ll e = 15311432, ie = 469870224;
    per(i, 21, 0) es[i] = e, ies[i] = ie, e = e * e % P, ie = ie * ie % P;
    ll now = 1, inow = 1;
    rep(i, 0, 21) {
        w[i] = es[i] * now % P, iw[i] = ies[i] * inow % P;
        (now *= ies[i]) %= P, (inow *= es[i]) %= P;
    }
}
void DIF(int a[]) {
    for(int i = lim >> 1, l = 1; i; i >>= 1, l <<= 1) {
        ll now = 1;
        For(j, 0, l) {
            int pos = j * i * 2;
            For(k, pos, pos + i) {
                int x = a[k], y = a[k + i] * now % P;
                a[k] = add(x, y), a[k + i] = sub(x, y);
            }
            (now *= w[__builtin_ctz(~j)]) %= P;
        }
    }
}
void IDIF(int a[]) {
    for(int i = 1, l = lim >> 1; l; i <<= 1, l >>= 1) {
        ll now = 1;
        For(j, 0, l) {
            int pos = j * i * 2;
            For(k, pos, pos + i) {
                int x = a[k], y = a[k + i];
                a[k] = add(x, y), a[k + i] = (x - y + P) * now % P;
            }
            (now *= iw[__builtin_ctz(~j)]) %= P;
        }
    }
    ll inv = Pow(lim, P - 2);
    For(i, 0, lim) a[i] = a[i] * inv % P;
}
ll C(int n, int m) {
    return (ll)fac[n] * ifac[m] % P * ifac[n - m] % P;
}

void solve() {
    cin >> n;
    lim = 1;
    while(lim <= n * 2) lim <<= 1;
    memset(a, 0, lim << 2);
    memset(b, 0, lim << 2);
    fac[0] = 1;
    rep(i, 1, n) fac[i] = (ll)fac[i - 1] * i % P;
    ifac[n] = Pow(fac[n], P - 2);
    per(i, n, 1) ifac[i - 1] = (ll)ifac[i] * i % P;
    f[0] = 1;
    rep(i, 1, n) f[i] = f[i - 1] * (i * 2 - 1LL) % P;
    ll inv = 1;
    rep(i, 0, n) {
        a[i] = ifac[i];
        if(~i & 1) b[i] = ifac[i / 2] * inv % P, inv = inv * (P - P / 2) % P;
    }
    DIF(a), DIF(b);
    For(i, 0, lim) a[i] = (ll)a[i] * b[i] % P;
    IDIF(a);
    rep(i, 0, n) a[i] = (ll)a[i] * fac[i] % P;
    ll ans = 0;
    rep(i, 0, n / 4)
        ans = (ans + C(n - i * 2, i * 2) * f[i] % P * a[n - i * 4] % P * Pow(2, i)) % P;
    cout << ans << '\n';
}
int main() {
    prework();
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) solve();
}