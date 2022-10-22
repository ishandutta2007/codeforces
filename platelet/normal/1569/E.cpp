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
template<int m> struct static_modint {
    using mint = static_modint;
  public:
    static mint raw(int v) { mint x; return x._v = v, x; }
    static_modint() : _v(0) {}
    template<class T> static_modint(T v) { ll x = v % m; _v = x < 0 ? x + m : x; }
    uint val() const { return _v; }
    mint& operator++() { if(++_v == m) _v = 0; return *this; }
    mint& operator--() { if(!_v--) _v = m - 1; return *this; }
    mint operator++(int) { mint res = *this; ++*this; return res; }
    mint operator--(int) { mint res = *this; --*this; return res; }
    mint& operator+=(const mint& rhs) { _v += rhs._v; if(_v >= m) _v -= m; return *this; }
    mint& operator-=(const mint& rhs) { _v -= rhs._v; if(_v >= m) _v += m; return *this; }
    mint& operator*=(const mint& rhs) { ull z = _v; z *= rhs._v, _v = z % m; return *this; }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(ll n) const { assert(0 <= n); mint x = *this, r = 1; for(; n; n >>= 1, x *= x) if(n & 1) r *= x; return r; }
    mint inv() const { if(prime) { assert(_v); return pow(m - 2); } else { auto eg = inv_gcd(_v, m); assert(eg.first == 1); return eg.second; } }
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
int read() { int x; scanf("%d", &x); return x; }
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using arr = array<int8_t, 16>;
using mint = static_modint<998244353>;

int half; mint a, H;
arr nw;
map<int, arr> p[16];

int winner(const array<int8_t, 16>& x) {
    return min_element(&x[0], &x[half]) - &x[0];
}
void dfs(int i, mint h) {
    if(i == 1) return void(p[winner(nw)][h.val()] = nw);
    vector<int> v;
    For(j, 0, half) if(!nw[j]) v.pb(j);
    For(S, 0, 1 << i / 2) {
        mint nh = h;
        For(j, 0, i / 2) {
            int t = j * 2 + (S >> j & 1);
            nw[v[t]] = i + 1, nw[v[t ^ 1]] = 0;
            nh += (v[t] + 1) * a.pow(i + 1);
        }
        dfs(i / 2, nh);
    }
    for(int j : v) nw[j] = 0;
}
void prt(arr x) {
    For(j, 0, half) cout << (int)x[j] << ' ';
    For(j, 0, half) cout << (int)nw[j] << ' ';
    exit(0);
}
void Dfs(int i, mint h) {
    if(i == 1) {
        int t = winner(nw);
        For(j, 0, half) {
            int x = (H - h - (j + 1) * a - (t + 1 + half) * a * a).val();
            int y = (H - h - (j + 1) * a * a - (t + 1 + half) * a).val();
            if(p[j].count(x)) p[j][x][j] = 1, nw[t] = 2, prt(p[j][x]);
            if(p[j].count(y)) p[j][y][j] = 2, nw[t] = 1, prt(p[j][y]);
        }
        return;
    }
    vector<int> v;
    For(j, 0, half) if(!nw[j]) v.pb(j);
    For(S, 0, 1 << i / 2) {
        mint nh = h;
        For(j, 0, i / 2) {
            int t = j * 2 + (S >> j & 1);
            nw[v[t]] = i + 1, nw[v[t ^ 1]] = 0;
            nh += (v[t] + 1 + half) * a.pow(i + 1);
        }
        Dfs(i / 2, nh);
    }
    for(int j : v) nw[j] = 0;
}
int main() {
    half = 1 << read() - 1, a = read(), H = read();
    dfs(half, 0), Dfs(half, 0), puts("-1");
}