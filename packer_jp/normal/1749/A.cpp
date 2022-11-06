#include <bits/stdc++.h>
using namespace std;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define uniq(a) (a).erase(unique(all(a)), (a).end())
#define t0 first
#define t1 second
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
constexpr double pi = 3.14159265358979323846;
constexpr ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr ll dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr ll sign(ll a) { return (a > 0) - (a < 0); }
constexpr ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
constexpr ll cdiv(ll a, ll b) { return -fdiv(-a, b); }
constexpr ll pw(ll n) { return 1ll << n; }
constexpr ll flg(ll n) { return 63 - __builtin_clzll(n); }
constexpr ll clg(ll n) { return flg(n - 1) + 1; }
constexpr ll safemod(ll x, ll mod) { return (x % mod + mod) % mod; }
template <typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
template <typename T> constexpr T sq(const T &a) { return a * a; }
template <typename T, typename U> constexpr bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <typename T, typename U> constexpr bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
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

template <typename M> struct modint {
    ll val;
    modint(ll val = 0) : val(val >= 0 ? val % M::mod : (M::mod - (-val) % M::mod) % M::mod) {}
    static ll mod() { return M::mod; }
    modint inv() const {
        ll a = val, b = M::mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return u;
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
        if ((val += a.val) >= M::mod) val -= M::mod;
        return *this;
    }
    modint &operator-=(const modint &a) {
        if ((val += M::mod - a.val) >= M::mod) val -= M::mod;
        return *this;
    }
    modint &operator*=(const modint &a) {
        (val *= a.val) %= M::mod;
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

struct _998244353 {
    constexpr static ll mod = 998244353;
};
struct _1000000007 {
    constexpr static ll mod = 1000000007;
};
using modint998244353 = modint<_998244353>;
using modint1000000007 = modint<_1000000007>;

struct arbitrary {
    static ll mod;
};
ll arbitrary::mod;

template <typename V> struct fenwick_tree {
    vector<V> data;
    fenwick_tree(ll n) : data(n + 1, V()) {}
    void add(ll i, const V &x) {
        for (++i; i < (ll)data.size(); i += i & -i) data[i] += x;
    }
    V sum(ll i) const {
        V ret = V();
        for (; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }
    V sum(ll l, ll r) const { return sum(r) - sum(l); }
};
template <typename P> struct unionfind {
    using V = typename P::V;
    ll n;
    vector<ll> ps;
    vector<V> val;
    unionfind(const vector<V> &val) : n(val.size()), ps(n, -1), val(val) {}
    unionfind(ll n, const V &a = {}) : unionfind(vector<V>(n, a)) {}
    ll find(ll i) {
        if (ps[i] < 0) return i;
        return ps[i] = find(ps[i]);
    }
    ll size(ll i) { return -ps[find(i)]; }
    void unite(ll i, ll j) {
        if ((i = find(i)) == (j = find(j))) return;
        if (-ps[i] < -ps[j]) swap(i, j);
        ps[i] += ps[j];
        P::merge(val[i], val[j]);
        ps[j] = i;
    }
    bool same(ll i, ll j) { return find(i) == find(j); }
    V &operator[](ll i) { return val[find(i)]; }
    vector<vector<ll>> groups() {
        vector<vector<ll>> ret(n);
        for (ll i : rep(n)) ret[find(i)].push_back(i);
        ret.erase(remove_if(all(ret), [](const vector<ll> &v) { return v.empty(); }), ret.end());
        return ret;
    }
};
struct normal_uf {
    using V = struct {};
    static void merge(V &a, const V &b) {}
};
template <typename V> V xor64(V lb, V ub) {
    static ull x = 88172645463325252ull;
    x ^= x << 7;
    return lb + (x ^= x >> 9) % (ub - lb);
}
template <typename V> vector<V> prime_factorize(V n) {
    vector<V> ret;
    for (V i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n != 1) ret.push_back(n);
    return ret;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        set<ll> a, b;
        for (ll i : rep(m)) {
            ll x, y;
            cin >> x >> y;
            a.insert(x);
            b.insert(y);
        }
        if (a.size() < n || b.size() < n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}