#include <bits/stdc++.h>
using namespace std;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define uniq(a) (a).erase(unique(all(a)), (a).end())
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
constexpr double PI = 3.14159265358979323846;
constexpr ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr ll dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr ll sign(ll a) { return (a > 0) - (a < 0); }
constexpr ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
constexpr ll cdiv(ll a, ll b) { return -fdiv(-a, b); }
constexpr ull bit(int n) { return 1ull << n; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &a) {
    os << "(" << a.first << ", " << a.second << ")";
    return os;
}
template <typename T, typename U, typename V> ostream &operator<<(ostream &os, const tuple<T, U, V> &a) {
    os << "(" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : "");
    os << ")";
    return os;
}
#ifdef ONLINE_JUDGE
#define dump(...) (void(0))
#else
void debug() { cerr << endl; }
template <typename Head, typename... Tail> void debug(Head &&head, Tail &&... tail) {
    cerr << head;
    if (sizeof...(Tail)) cerr << ", ";
    debug(tail...);
}
#define dump(...) cerr << __LINE__ << ": " << #__VA_ARGS__ << " = ", debug(__VA_ARGS__)
#endif
template <typename T> constexpr T mypow(T x, ll n) {
    T ret = 1;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}
constexpr ll modpow(ll x, ll n, ll mod) {
    x %= mod;
    ll ret = 1;
    while (n) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
        x %= mod;
        ret %= mod;
    }
    return ret;
}
template <typename T> T xor64(T lb, T ub) {
    static ull x = 88172645463325252ull;
    x ^= x << 7;
    return lb + (x ^= x >> 9) % (ub - lb);
}
constexpr ll safemod(ll x, ll mod) { return (x % mod + mod) % mod; }
template <typename T> constexpr T sq(const T &a) { return a * a; }
template <typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename U> bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <typename T, typename U> bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <typename T> T make_vector(T &&a) { return a; }
template <typename... Ts> auto make_vector(int h, Ts &&... ts) { return vector(h, make_vector(ts...)); }
struct rep {
    struct itr {
        ll v;
        itr(ll v) : v(v) {}
        void operator++() { ++v; }
        ll operator*() const { return v; }
        bool operator!=(itr i) const { return v < *i; }
    };
    ll l, r;
    rep(ll l, ll r) : l(l), r(r) {}
    rep(ll r) : rep(0, r) {}
    itr begin() const { return l; };
    itr end() const { return r; };
};
struct per {
    struct itr {
        ll v;
        itr(ll v) : v(v) {}
        void operator++() { --v; }
        ll operator*() const { return v; }
        bool operator!=(itr i) const { return v > *i; }
    };
    ll l, r;
    per(ll l, ll r) : l(l), r(r) {}
    per(ll r) : per(0, r) {}
    itr begin() const { return r - 1; };
    itr end() const { return l - 1; };
};
struct io_setup {
    static constexpr int PREC = 20;
    io_setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} iOS;
template <ll MOD = 1000000007> struct modint {
    ll val;
    modint(ll val = 0) : val(val >= 0 ? val % MOD : (MOD - (-val) % MOD) % MOD) {}
    static ll mod() { return MOD; }
    modint inv() const {
        ll a = val, b = MOD, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }
    modint pow(ll k) const {
        modint ret = 1, mul = val;
        while (k) {
            if (k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }
    modint &operator+=(const modint &a) {
        if ((val += a.val) >= MOD) val -= MOD;
        return *this;
    }
    modint &operator-=(const modint &a) {
        if ((val += MOD - a.val) >= MOD) val -= MOD;
        return *this;
    }
    modint &operator*=(const modint &a) {
        (val *= a.val) %= MOD;
        return *this;
    }
    modint &operator/=(const modint &a) { return *this *= a.inv(); }
    modint operator+() const { return *this; }
    modint operator-() const { return modint(-val); }
    friend bool operator==(const modint &a, const modint &b) { return a.val == b.val; }
    friend bool operator!=(const modint &a, const modint &b) { return rel_ops::operator!=(a, b); }
    friend modint operator+(const modint &a, const modint &b) { return modint(a) += b; }
    friend modint operator-(const modint &a, const modint &b) { return modint(a) -= b; }
    friend modint operator*(const modint &a, const modint &b) { return modint(a) *= b; }
    friend modint operator/(const modint &a, const modint &b) { return modint(a) /= b; }
    friend istream &operator>>(istream &is, modint &a) {
        ll val;
        is >> val;
        a = modint(val);
        return is;
    }
    friend ostream &operator<<(ostream &os, const modint &a) { return os << a.val; }
};
template <typename F> ll bisect(ll ok, ll ng, F f) {
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
int main() {
    ll n;
    cin >> n;
    vll m(n), k(n);
    for (ll i : rep(n)) { cin >> m[i] >> k[i], --m[i]; }
    vll ans;
    pll opt = {0, 1};
    vector<pll> ord(2e5);
    for (ll i : rep(1, 21)) {
        for (ll j : rep(2e5)) ord[j] = {0, j};
        for (ll j : rep(n)) ord[m[j]].first += min(k[j], i);
        sort(all(ord)), reverse(all(ord));
        pll cur = {0, i};
        for (ll j : rep(i)) { cur.first += ord[j].first; }
        if (opt.first * cur.second < cur.first * opt.second) {
            opt = cur;
            vll v;
            for (ll j : rep(i)) { v.push_back(ord[j].second); }
            ans = v;
        }
    }
    cout << ans.size() << endl;
    for (ll ai : ans) cout << ai + 1 << " ";
    cout << endl;
}