#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using uint = unsigned;
using ull = uint64_t;

constexpr ll safe_mod(ll x, ll m) { return x %= m, x < 0 ? x + m : x; }
constexpr ll pow_mod_constexpr(ll x, ll n, int m) {
    if(m == 1) return 0;
    uint _m = m; ull r = 1, _x = safe_mod(x, m);
    for(; n; n >>= 1, _x = _x * _x % _m) if(n & 1) r = r * _x % m;
    return r;
}
constexpr bool is_prime_constexpr(int n) {
    if(n <= 1) return false;
    if(n == 2 || n == 7 || n == 61) return true;
    if(n % 2 == 0) return false;
    ll d = n - 1; while(~d & 1) d /= 2;
    for(ll a : {2, 7, 61}) {
        ll t = d, y = pow_mod_constexpr(a, t, n);
        while(t != n - 1 && y != 1 && y != n - 1) y = y * y % n, t <<= 1;
        if(y != n - 1 && t % 2 == 0) return false;
    }
    return true;
}
constexpr pair<ll, ll> inv_gcd(ll a, ll b) {
    a = safe_mod(a, b);
    if(a == 0) return {b, 0};
    ll s = b, t = a, m0 = 0, m1 = 1;
    while(t) {
        ll u = s / t; s -= t * u, m0 -= m1 * u;
        ll tmp = s; s = t, t = tmp, tmp = m0, m0 = m1, m1 = tmp;
    }
    if(m0 < 0) m0 += b / s;
    return {s, m0};
}
struct barrett {
    uint m; ull im;
    barrett(uint m) :m(m), im(~0ull / m + 1) {}
    uint mul(uint a, uint b) const {
        ull z = (ull)a * b, x = (__uint128_t)z * im >> 64; uint v = z - x * m;
        return m <= v ? v + m : v;
    }
};
template<int m> struct static_modint {
    using mint = static_modint;
  public:
    static mint raw(int v) { mint x; return x._v = v, x; }
    static_modint() :_v(0) {}
    template<class T> static_modint(T v) { ll x = v % m; _v = x < 0 ? x + m : x; }
    uint val()const { return _v; }
    mint& operator++() { if(++_v == m) _v = 0; return *this; }
    mint& operator--() { if(!_v--) _v = m - 1; return *this; }
    mint operator++(int) { mint res = *this; ++*this; return res; }
    mint operator--(int) { mint res = *this; --*this; return res; }
    mint& operator+=(const mint& rhs) { _v += rhs._v; if(_v >= m) _v -= m; return *this; }
    mint& operator-=(const mint& rhs) { _v -= rhs._v; if(_v >= m) _v += m; return *this; }
    mint& operator*=(const mint& rhs) { ull z = _v; z *= rhs._v, _v = z % m; return *this; }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+()const { return *this; }
    mint operator-()const { return mint() - *this; }
    mint pow(ll n)const { assert(0 <= n); mint x = *this, r = 1; for(; n; n >>= 1, x *= x) if(n & 1) r *= x; return r; }
    mint inv() const{ if(prime) { assert(_v); return pow(m - 2); } else { auto eg = inv_gcd(_v, m); assert(eg.first == 1); return eg.second; } }
    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }
  private:
    uint _v;
    static constexpr bool prime = is_prime_constexpr(m);
};
struct dynamic_modint {
    using mint = dynamic_modint;
  public:
    static void set_mod(int m) { assert(1 <= m), bt = barrett(m); }
    static mint raw(int v) { mint x; return x._v = v, x; }
    dynamic_modint() :_v(0) {}
    template<class T> dynamic_modint(T v) { ll x = v % (int)bt.m; _v = x < 0 ? x + bt.m : x; }
    uint val()const { return _v; }
    mint& operator++() { if(++_v == bt.m) _v = 0; return *this; }
    mint& operator--() { if(!_v--) _v = bt.m - 1; return *this; }
    mint operator++(int) { mint res = *this; ++*this; return res; }
    mint operator--(int) { mint res = *this; --*this; return res; }
    mint& operator+=(const mint& rhs) { _v += rhs._v; if(_v >= bt.m) _v -= bt.m; return *this; }
    mint& operator-=(const mint& rhs) { _v += bt.m - rhs._v; if(_v >= bt.m) _v -= bt.m; return *this; }
    mint& operator*=(const mint& rhs) { _v = bt.mul(_v, rhs._v); return *this; }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+()const { return *this; }
    mint operator-()const { return mint() - *this; }
    mint pow(ll n)const { assert(0 <= n); mint x = *this, r = 1; for(; n; n >>= 1, x *= x) if(n & 1) r *= x; return r; }
    mint inv()const { auto eg = inv_gcd(_v, bt.m); assert(eg.first == 1); return eg.second; }
    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }
  private:
    uint _v;
    static barrett bt;
};
barrett dynamic_modint::bt = 998244353;
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define fi first 
#define se second
#define all(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())
#define mid ((l + r) >> 1)
#define lc (o << 1)
#define rc (o << 1 | 1)
#define lch l, mid, lc
#define rch mid + 1, r, rc
#define lb lower_bound
#define ub upper_bound
#define bs binary_search

template<class T> T& cmin(T& a, const T& b) { if(b < a) a = b; return a; }
template<class T> T& cmax(T& a, const T& b) { if(a < b) a = b; return a; }

// #pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int N = 2e5 + 5;

int n, q, pos[N], st[18][N];
ll ans[N * 5];
vector<tuple<int, int, int>> event[N];
vector<pair<int, int>> segment[N], query[N];

struct {
    ll c[N][2];
    void add(int i, int v) {
        ll v2 = (ll)i * v;
        for(; i <= n; i += i & -i) c[i][0] += v, c[i][1] += v2;
    }
    ll qry(int i) {
        ll r = 0, r2 = 0;
        for(int j = i; j; j &= j - 1) r += c[j][0], r2 += c[j][1];
        return r * (i + 1) - r2;
    }
} A, B;

void solve() {
    cin >> n >> q;
    rep(i, 1, n) cin >> st[0][i], pos[st[0][i]] = i;
    rep(i, 1, 17) rep(j, 1 << i, n) st[i][j] = max(st[i - 1][j], st[i - 1][j - (1 << i - 1)]);
    rep(i, 1, n) per(j, n / i, i + 1) {
        int l = pos[i], r = pos[j];
        if(l > r) swap(l, r);
        l = min(l, pos[i * j]), r = max(r, pos[i * j]);
        int z = __lg(r - l + 1);
        int mx = max(st[z][r], st[z][l + (1 << z) - 1]);
        if(mx <= i * j) segment[i * j].eb(l, r);
    }
    rep(i, 1, n) {
        int L = pos[i], R = pos[i];
        per(k, 17, 0) {
            if(L >= 1 << k && st[k][L] <= i) L -= 1 << k;
            if(n - R + 1 >= 1 << k && st[k][R + (1 << k) - 1] <= i) R += 1 << k;
        }
        R--;
        sort(all(segment[i]), greater());
        int mn = R + 1;
        int ls = 0;
        for(auto [l, r] : segment[i]) {
            if(mn <= R) event[ls].eb(mn, R, 1), event[l].eb(mn, R, -1);
            mn = min(mn, r), ls = l;
        }
        if(mn <= R) event[ls].eb(mn, R, 1), event[L].eb(mn, R, -1);
    }
    int l, r;
    rep(i, 1, q) cin >> l >> r, query[l].eb(r, i);
    per(i, n, 1) {
        for(auto [l, r, v] : event[i]) A.add(l, v), A.add(r + 1, -v), B.add(l, v * i), B.add(r + 1, -v * i);
        for(auto [r, id] : query[i]) ans[id] = B.qry(r) - A.qry(r) * (i - 1);
    }
    rep(i, 1, q) cout << ans[i] << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    for(T = 1; T--; solve());
}