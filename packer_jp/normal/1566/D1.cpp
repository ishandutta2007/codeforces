#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define uniq(a) (a).erase(unique(all(a)), (a).end())
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
constexpr ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr ll dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr ll sign(ll a) { return (a > 0) - (a < 0); }
constexpr ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
constexpr ll cdiv(ll a, ll b) { return -fdiv(-a, b); }
constexpr ull bit(int n) { return 1ull << n; }
template <typename T> constexpr T sq(const T &a) { return a * a; }
template <typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename U> bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <typename T, typename U> bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &a) {
    os << "(" << a.first << ", " << a.second << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : ")");
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : ")");
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : ")");
    return os;
}
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); ++itr) os << *itr << (next(itr) != a.end() ? ", " : ")");
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

template <typename S> struct segtree {
    using V = typename S::val_t;
    int n, size;
    vector<V> val;
    segtree(int n) : segtree(vector(n, S::e())) {}
    segtree(const vector<V> &src) : n(src.size()) {
        for (size = 1; size < n; size <<= 1) {}
        val.resize(size << 1);
        copy(all(src), val.begin() + size);
        for (int i : per(1, size)) val[i] = S::op(val[i << 1 | 0], val[i << 1 | 1]);
    }
    void set(int i, const V &a) {
        val[i += size] = a;
        while (i >>= 1) val[i] = S::op(val[i << 1 | 0], val[i << 1 | 1]);
    }
    V get(int i) const { return val[i + size]; }
    V prod(int l, int r) const {
        V a = S::e(), b = S::e();
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) a = S::op(a, val[l++]);
            if (r & 1) b = S::op(val[--r], b);
        }
        return S::op(a, b);
    }
    template <typename F> int max_right(int l, F f) const {
        if (l == n) return n;
        V a = S::e();
        l += size;
        do {
            while (~l & 1) l >>= 1;
            if (!f(S::op(a, val[l]))) {
                while (l < size) {
                    l = l << 1;
                    if (f(S::op(a, val[l]))) a = S::op(a, val[l++]);
                }
                return l - size;
            }
            a = S::op(a, val[l++]);
        } while ((l & -l) != l);
        return n;
    }
    template <typename F> int min_left(int r, F f) const {
        if (r == 0) return 0;
        V a = S::e();
        r += size;
        do {
            r--;
            while (r > 1 && r & 1) r >>= 1;
            if (!f(S::op(val[r], a))) {
                while (r < size) {
                    r = r << 1 | 1;
                    if (f(S::op(val[r], a))) a = S::op(val[r--], a);
                }
                return r + 1 - size;
            }
            a = S::op(val[r], a);
        } while ((r & -r) != r);
        return 0;
    }
};

struct sum_monoid {
    using val_t = ll;
    static val_t op(val_t a, val_t b) { return a + b; }
    static val_t e() { return 0; }
};

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vll a(m);
        for (ll i : rep(m)) cin >> a[i];
        vll b(a);
        sort(all(b)), uniq(b);
        map<ll, ll> zat;
        for (ll i : rep(b.size())) zat[b[i]] = i;
        segtree<sum_monoid> rsq(zat.size());
        ll ans = 0;
        for (ll i : rep(m)) {
            ll cur = zat[a[i]];
            ans += rsq.prod(0, cur);
            rsq.set(cur, rsq.get(cur) + 1);
        }
        cout << ans << endl;
    }
}