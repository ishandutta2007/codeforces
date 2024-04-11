#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 2e5 + 5, P = 998244353;

int n, fac[N], ifac[N];
int lim, rev[1 << 18], w[1 << 18], a[1 << 18], b[1 << 18];

int add(int a, int b) { return (a += b) < P ? a : a - P; }
int sub(int a, int b) { return (a -= b) < 0 ? a + P : a; }
ll Pow(ll a, int n, ll r = 1) {
    for(; n; n >>= 1, a = a * a % P)
    if(n & 1) r = r * a % P;
    return r;
}
void NTT(int a[], bool t) {
    For(i, 0, lim) if(rev[i] < i) swap(a[i], a[rev[i]]);
    for(int i = 1; i < lim; i <<= 1)
    for(int j = 0; j < lim; j += i << 1) For(k, j, j + i) {
        int x = a[k], y = (ll)a[k + i] * w[i + k - j] % P;
        a[k] = add(x, y), a[k + i] = sub(x, y);
    }
    if(t) return;
    reverse(a + 1, a + lim);
    ll inv = Pow(lim, P - 2);
    For(i, 0, lim) a[i] = a[i] * inv % P;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 0, n) fac[i] = i ? (ll)fac[i - 1] * i % P : 1;
    per(i, n + 1, 1) ifac[i - 1] = i > n ? Pow(fac[n], P - 2) : (ll)ifac[i] * i % P;
    for(lim = 1; lim <= n; lim <<= 1);
    rep(i, 0, n >> 1) i && (a[i] = (ll)fac[n / 2 - i] * ifac[i + n / 2] % P * fac[i + n / 2 - 1] % P), b[i] = ifac[i];
    For(i, 0, lim) rev[i] = rev[i >> 1] >> 1 | (i & 1 ? lim >> 1 : 0);
    for(int i = 1; i < lim; i <<= 1) {
        ll wn = Pow(3, P / 2 / i);
        For(j, 0, i) w[i + j] = j ? w[i + j - 1] * wn % P : 1;
    }
    NTT(a, 1), NTT(b, 1);
    For(i, 0, lim) a[i] = (ll)a[i] * b[i] % P;
    NTT(a, 0);
    rep(i, 1, n + 1 >> 1) {
        int ans = (a[(n + 1 >> 1) - i] + (ll)fac[n - 1] * ifac[n - i] - (ll)fac[n >> 1] * ifac[(n + 1 >> 1) - i]) % P;
        cout << sub(fac[n - 1], ll(ans < 0 ? ans + P : ans) * fac[n - i] % P) << ' ';
    }
    rep(i, 1, n >> 1) cout << "0 ";
}