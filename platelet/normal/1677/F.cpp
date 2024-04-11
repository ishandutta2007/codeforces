#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#pragma GCC target("avx,avx2")

using namespace std;
using ll = long long;

const int N = 1e5 + 32, P = 998244353;

int n, k, p, fac[N], ifac[N], S[N];
alignas(32) int c[N], A[N];
int pre[N], pre1[N], suf[N], suf1[N];
int lim, rev[1 << 18], a[1 << 18], b[1 << 18], w[1 << 18];

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

using v8i = __attribute((vector_size(32))) int;
using v4l = __attribute((vector_size(32))) long long;

inline constexpr v8i set1(int v) {
    return (v8i){v, v, v, v, v, v, v, v};
}
struct mint8 {
    #define min8 __builtin_ia32_pminud256
    #define mul8 (v8i)__builtin_ia32_pmuludq256
    #define flip(x) __builtin_ia32_pshufd256(x, 0xb1)
    v8i v;
    static constexpr int invi = -998244351, shl32i = 932051910;
    static constexpr v8i m1 = set1(P), m2 = set1(P << 1),
        inv = set1(invi), invn = set1(-invi), shl32 = set1(shl32i);
    inline mint8() {}
    inline mint8(v8i v) :v(v) {}
    inline mint8(v8i prod0, v8i prod1) {
        prod0 = v8i((v4l)prod0 + (v4l)mul8(mul8(prod0, invn), m1));
        prod1 = v8i((v4l)prod1 + (v4l)mul8(mul8(prod1, invn), m1));
        v = __builtin_ia32_pblendd256(flip(prod0), prod1, 0xaa);
    }
    friend inline mint8 operator +(mint8 lhs, mint8 rhs) {
        v8i res = lhs.v + rhs.v;
        return min8(res, res - m2);
    }
    friend inline mint8 operator -(mint8 lhs, mint8 rhs) {
        v8i res = lhs.v - rhs.v;
        return min8(res, res + m2);
    }
    friend inline mint8 operator *(mint8 lhs, mint8 rhs) {
        return mint8(mul8(lhs.v, rhs.v), mul8(flip(lhs.v), flip(rhs.v)));
    }
    inline void shiftL32() {
        *this = mint8(mul8(v, shl32), mul8(flip(v), shl32));
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> p;
    rep(i, 1, n) cin >> c[i];
    rep(i, 0, k) fac[i] = i ? (ll)fac[i - 1] * i % P : 1;
    per(i, k + 1, 1) ifac[i - 1] = i > k ? Pow(fac[k], P - 2) : (ll)ifac[i] * i % P;
    for(lim = 1; lim <= k << 1; lim <<= 1);
    For(i, 0, lim) rev[i] = rev[i >> 1] >> 1 | (i & 1 ? lim >> 1 : 0);
    for(int i = 1; i < lim; i <<= 1) {
        ll wn = Pow(3, P / 2 / i), p = 1;
        For(j, 0, i) w[i + j] = p, p = p * wn % P;
    }
    rep(i, 0, k) a[i] = Pow(i, k) * ifac[i] % P, b[i] = i & 1 ? P - ifac[i] : ifac[i];
    NTT(a, 1), NTT(b, 1);
    For(i, 0, lim) a[i] = (ll)a[i] * b[i] % P;
    NTT(a, 0);
    ll powp = 1;
    rep(i, 1, k) (powp *= p) %= P, S[i] = (ll)a[i] * powp % P;
    rep(i, 0, n - 1) {
        pre[i + 1] = pre[i] * (c[i] + 1LL) % P + 1;
        pre1[i + 1] = (pre1[i] * (c[i] + 1LL) + pre[i] * (ll)c[i]) % P;
    }
    per(i, n + 1, 2) {
        suf[i - 1] = suf[i] * (c[i] + 1LL) % P + 1;
        suf1[i - 1] = (suf1[i] * (c[i] + 1LL) + suf[i] * (ll)c[i]) % P;
    }
    ll sum1 = 0, sum2 = 0;
    rep(i, 1, n) {
        sum1 += A[i] = ((ll)pre[i] * suf[i] + (ll)pre1[i] * suf[i] + (ll)pre[i] * suf1[i]) % P;
        A[i] = (ll)A[i] * Pow(p, c[i] + 1) % P;
    }
    mem(a, 0), mem(b, 0);
    rep(i, 0, k) b[i] = fac[i] * Pow(P + 1 - p, P - 2 - i) % P;
    rep(i, 1, k) sum2 = (sum2 + ((ll)p * b[i] + (ll)i * b[i - 1]) % P * S[i]) % P;
    sum1 = sum1 % P * sum2 % P;
    rep(i, 1, n) c[i]++;
    swap(A[0], A[n]), swap(c[0], c[n]);
    for(int js = 0; js < n; js += 5000) {
        mint8 p[625], t[625], one(set1(301989884));
        rep(j, 0, 624) p[j] = ((mint8*)&A[js])[j], t[j] = ((mint8*)&c[js])[j], t[j].shiftL32();
        rep(i, 0, k) {
            mint8 sum(set1(0));
            rep(j, 0, 624) sum = sum + p[j], p[j] = p[j] * t[j], t[j] = t[j] - one;
            ll res = a[i];
            rep(j, 0, 7) res += sum.v[j];
            a[i] = res % P;
        }
    }
    powp = Pow(powp, P - 2);
    per(i, k, 0) {
        a[i] = a[i] * powp % P * ifac[i] % P;
        b[i] = (ll)b[i] * ifac[i] % P;
        (powp *= p) %= P;
    }
    NTT(a, 1), NTT(b, 1);
    For(i, 0, lim) a[i] = (ll)a[i] * b[i] % P;
    NTT(a, 0);
    rep(i, 1, k) sum1 = (sum1 - (ll)S[i] * a[i] % P * fac[i]) % P;
    cout << (sum1 + P) % P;
}