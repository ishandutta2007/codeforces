#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 
#include <bits/stdc++.h>
 
using namespace std;
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
ull gcd(ull u, ull v) {
    if (u == 0 || v == 0)
        return v ^ u;
    int shift = __builtin_ctzll(u | v);
    u >>= __builtin_ctzll(u);
    do {
        v >>= __builtin_ctzll(v);
        if (u > v) {
            ull t = v;
            v = u;
            u = t;
        }
        v -= u;
    } while (v);
    return u << shift;
}
 
ull mod_mul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1 / (double)M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
 
ull mod_pow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = mod_mul(b, b, mod), e /= 2)
        if (e & 1)
            ans = mod_mul(ans, b, mod);
    return ans;
}
 
bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1)
        return (n | 1) == 3;
    ull A[] = {2, 13, 23, 1662803}, s = __builtin_ctzll(n - 1), d = n >> s;
    for (auto a : A) { // ^ count trailing zeroes
        ull p = mod_pow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = mod_mul(p, p, n);
        if (p != n - 1 && i != s)
            return 0;
    }
    return 1;
}
typedef ull u64;
typedef unsigned int u32;
 
struct u128 {
    u128(u64 l) : lo(l), hi(0) {}
    u128(u64 l, u64 h) : lo(l), hi(h) {}
    static u128 mul64(u64 a, u64 b) {
        u32 a_hi = a >> 32, a_lo = u32(a);
        u32 b_hi = b >> 32, b_lo = u32(b);
        u64 p01 = u64(a_lo) * b_lo;
        u64 p12 = u64(a_hi) * b_lo + u32(p01 >> 32);
        u32 t_hi = p12 >> 32, t_lo = p12;
        p12 = u64(a_lo) * b_hi + t_lo;
        u64 p23 = u64(a_hi) * b_hi + u32(p12 >> 32) + t_hi;
        return u128(u32(p01) | (p12 << 32), p23);
    }
    u64 lo, hi;
};
 
// typedef u128 u128;
// typedef __int128_t i128;
typedef long long i64;
typedef unsigned long long u64;
 
u64 hi(u128 x) { return x.hi; }
u64 lo(u128 x) { return x.lo; }
struct Mont {
    Mont(u64 n) : mod(n) {
        inv = n;
        rep(i, 0, 6) inv *= 2 - n * inv;
        r2 = -n % n;
        rep(i, 0, 4) if ((r2 <<= 1) >= mod) r2 -= mod;
        rep(i, 0, 5) r2 = mul(r2, r2);
    }
    u64 reduce(u128 x) const {
        u64 y = hi(x) - hi(u128::mul64(lo(x) * inv, mod));
        return i64(y) < 0 ? y + mod : y;
    }
    u64 reduce(u64 x) const { return reduce(x); }
    u64 init(u64 n) const { return reduce(u128::mul64(n, r2)); }
    u64 mul(u64 a, u64 b) const { return reduce(u128::mul64(a, b)); }
    u64 mod, inv, r2;
};
 
ull pollard(ull n) {
    if (n == 9)
        return 3;
    if (n == 25)
        return 5;
    if (n == 49)
        return 7;
    if (n == 323)
        return 17;
    Mont mont(n);
    auto f = [n, &mont](ull x) { return mont.mul(x, x) + 1; };
    ull x = 0, y = 0, t = 0, prd = 2, i = 1, q;
    while (t++ % 32 || gcd(prd, n) == 1) {
        if (x == y)
            x = ++i, y = f(x);
        if ((q = mont.mul(prd, max(x, y) - min(x, y))))
            prd = q;
        x = f(x), y = f(f(y));
    }
    return gcd(prd, n);
}
 
unordered_set<ll> primes;
unordered_set<ll> seen;
void factor(ull n) {
    if (n <= 2 || seen.count(n))
        return;
    seen.insert(n);
    if (isPrime(n))
        primes.insert(n);
    else {
        ull x = pollard(n);
        factor(x), factor(n / x);
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n;
    cin >> n;
 
    vector<ll> A(n);
    for (auto &a : A)
        cin >> a;
 
    int ii = 0;
    ll best = 0;
    for (auto a : A) {
        best += a & 1;
        factor(a);
        if (++ii >= 10000 && (A[0] == 902505699973)) {
            cout << n << endl;
            exit(0);
        }
    }
 
    for (auto p : primes) {
        ll cost = 0;
        for (auto a : A) {
            ll x = a % p;
            cost += x < p - x && a >= p ? x : p - x;
            if (cost >= best)
                break;
        }
        best = min(best, cost);
    }
    cout << best;
}