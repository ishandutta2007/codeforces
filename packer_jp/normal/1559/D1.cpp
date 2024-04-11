#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
constexpr ll dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr ll dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr ull bit(int n) { return 1ull << n; }
constexpr ll sign(ll a) { return (a > 0) - (a < 0); }
constexpr ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
constexpr ll cdiv(ll a, ll b) { return -fdiv(-a, b); }
template <typename T> constexpr T sq(const T &a) { return a * a; }
template <typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename U> bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <typename T, typename U> bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) { os << *itr << (next(itr) != a.end() ? ", " : ""); }
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
        int v;
        itr(int v) : v(v) {}
        void operator++() { ++v; }
        int operator*() const { return v; }
        bool operator!=(const itr &i) const { return v != i.v; }
    };
    int l, r;
    rep(int r) : l(min(0, r)), r(r) {}
    rep(int l, int r) : l(min(l, r)), r(r) {}
    itr begin() const { return l; };
    itr end() const { return r; };
};
struct per {
    struct itr {
        int v;
        itr(int v) : v(v) {}
        void operator++() { --v; }
        int operator*() const { return v; }
        bool operator!=(const itr &i) const { return v != i.v; }
    };
    int l, r;
    per(int r) : l(min(0, r)), r(r) {}
    per(int l, int r) : l(min(l, r)), r(r) {}
    itr begin() const { return r - 1; };
    itr end() const { return l - 1; };
};
struct io_setup {
    static constexpr ll PREC = 20;
    io_setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} iOS;

struct uf {
    int n;
    vector<int> ps;
    uf(int n) : n(n), ps(n, -1) {}
    int find(int i) {
        if (ps[i] < 0) return i;
        return ps[i] = find(ps[i]);
    }
    int size(int i) { return -ps[find(i)]; }
    void unite(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return;
        if (-ps[i] < -ps[j]) swap(i, j);
        ps[i] += ps[j];
        ps[j] = i;
    }
    bool same(int i, int j) { return find(i) == find(j); }
    vector<vector<int>> groups() {
        vector<vector<int>> ret(n);
        for (int i : rep(n)) ret[find(i)].push_back(i);
        ret.erase(remove_if(all(ret), [](const vector<int> &v) { return v.empty(); }), ret.end());
        return ret;
    }
};

int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    uf ufx(n), ufy(n);
    for (ll i : rep(x)) {
        ll u, v;
        cin >> u >> v, --u, --v;
        ufx.unite(u, v);
    }
    for (ll i : rep(y)) {
        ll u, v;
        cin >> u >> v, --u, --v;
        ufy.unite(u, v);
    }
    vector<pll> ans;
    for (ll i : rep(n)) {
        for (ll j : rep(n)) {
            if (!ufx.same(i, j) && !ufy.same(i, j)) {
                ufx.unite(i, j);
                ufy.unite(i, j);
                ans.emplace_back(i, j);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto [i, j] : ans) cout << i + 1 << " " << j + 1 << endl;
}