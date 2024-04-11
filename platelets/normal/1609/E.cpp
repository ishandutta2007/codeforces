#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using uint = unsigned;
using ull = unsigned ll;

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
        ull z = (ull)a * b, x = (unsigned __int128)z * im >> 64; uint v = z - x * m;
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
template<int id> struct dynamic_modint {
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
template<int id> barrett dynamic_modint<id>::bt = 998244353;
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
#define lc o * 2
#define rc o * 2 + 1
#define lch l, mid, lc
#define rch mid + 1, r, rc
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define pop __builtin_popcount
#define llpop __builtin_popcountll
#define ctz __builtin_ctz
#define llctz __builtin_ctzll
#define clz __builtin_clz
#define llclz __builtin_clzll
#define par __builtin_parity
#define llpar __builtin_parityll

template<class T> T& cmin(T& a, const T& b) { if(b < a) a = b; return a; }
template<class T> T& cmax(T& a, const T& b) { if(a < b) a = b; return a; }

using lf = double;
// using P = pair<int, int>;
using V = vector<int>;
// using cmp = complex<lf>;

const int N = 1e5 + 5;

int n, q, a[N * 4], b[N * 4], c[N * 4];
int a1[N * 4], a2[N * 4], c1[N * 4], c2[N * 4], b1[N * 4], b2[N * 4];
char s[N];

void pu(int o) {
    a1[o] = min(a1[lc], a1[rc]) + a[o];
    c1[o] = min(c1[lc], c1[rc]) + c[o];
    a2[o] = min(a2[lc] + b[rc], a2[rc]) + a[o];
    c2[o] = min(c2[lc], c2[rc] + b[lc]) + c[o];
    b1[o] = min({b1[lc], b1[rc], c1[lc] + a1[rc]}) + a[o] + c[o];
    b2[o] = min({b2[lc], b2[rc], a2[lc] + c2[rc]}) + a[o] + c[o];
}
void updA(int L, int R, int v, int l, int r, int o) {
    if(L <= l && r <= R) return a[o] += v, a1[o] += v, a2[o] += v, b1[o] += v, b2[o] += v, void();
    if(L <= mid) updA(L, R, v, lch);
    if(R > mid) updA(L, R, v, rch);
    pu(o);
}
void updB(int p, int v, int l, int r, int o) {
    b[o] += v;
    if(l < r) p <= mid ? updB(p, v, lch) : updB(p, v, rch), pu(o);
}
void updC(int L, int R, int v, int l, int r, int o) {
    if(L <= l && r <= R) return c[o] += v, c1[o] += v, c2[o] += v, b1[o] += v, b2[o] += v, void();
    if(L <= mid) updC(L, R, v, lch);
    if(R > mid) updC(L, R, v, rch);
    pu(o);
}
void ins(int i, int v) {
    if(s[i] == 'a' && i < n) updA(i + 1, n, v, 1, n, 1);
    if(s[i] == 'b') updB(i, v, 1, n, 1);
    if(s[i] == 'c' && i > 1) updC(1, i - 1, v, 1, n, 1);
}
void solve() {
    scanf("%d%d%s", &n, &q, s + 1);
    rep(i, 1, n) ins(i, 1);
    int x; char c;
    while(q--) {
        scanf("%d %c", &x, &c), ins(x, -1), s[x] = c, ins(x, 1);
        printf("%d\n", min(b1[1], b2[1]));
    }
}
int main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef local
    freopen("in", "r", stdin);
#endif
    int T;
    for(T = 1; T--; solve());
}