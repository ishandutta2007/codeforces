#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define reps(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
#define uniq(a) (a).erase(unique(all(a)), (a).end())
#define bit(n) (1LL << (n))
#define dump(a) cerr << #a " = " << (a) << endl
using vll = vector<ll>;
using pll = pair<ll, ll>;
template <typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr ll DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr ll DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
ll sign(ll a) { return (a > 0) - (a < 0); }
ll cdiv(ll a, ll b) { return (a - 1 + b) / b; }
template <typename T> T sq(T a) { return a * a; }
template <typename T, typename U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T, typename U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &a) {
    os << "(" << a.first << ", " << a.second << ")";
    return os;
}
template <typename T, typename U, typename V> ostream &operator<<(ostream &os, const tuple<T, U, V> &a) {
    auto [t, u, v] = a;
    os << "(" << t << ", " << u << ", " << v << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) { os << *itr << (next(itr) != a.end() ? ", " : ""); }
    os << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const deque<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) { os << *itr << (next(itr) != a.end() ? ", " : ""); }
    os << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) { os << *itr << (next(itr) != a.end() ? ", " : ""); }
    os << "}";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) { os << *itr << (next(itr) != a.end() ? ", " : ""); }
    os << "}";
    return os;
}
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) { os << *itr << (next(itr) != a.end() ? ", " : ""); }
    os << "}";
    return os;
}
struct setup {
    static constexpr ll PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

int main() {
    ll n, k, x;
    cin >> n >> k >> x;
    vll a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    vll dif;
    ll ans = 0;
    rep(i, n - 1) {
        if (a[i + 1] - a[i] > x) dif.emplace_back(a[i + 1] - a[i]), ans++;
    }
    sort(all(dif));
    for (ll d : dif) {
        ll s = cdiv(d, x);
        if (k >= s - 1) {
            ans--;
            k -= s - 1;
        }
    }
    cout << ans + 1 << endl;
}