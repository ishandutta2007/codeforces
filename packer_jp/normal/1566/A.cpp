#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
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

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, s;
        cin >> n >> s;
        cout << s / (1 + n / 2) << endl;
    }
}