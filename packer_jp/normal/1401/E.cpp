#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define bit(n) (1LL << (n))
#define dump(x) cerr << #x " = " << (x) << endl
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int sign(int x) { return (x > 0) - (x < 0); }
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int cdiv(int a, int b) { return (a - 1 + b) / b; }
template<typename T> void fin(T mes) {
    cout << mes << endl;
    exit(0);
}
template<typename T, typename U> bool chmax(T &a, const U &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> bool chmin(T &a, const U &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &rhs) {
    os << "(" << rhs.first << ", " << rhs.second << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const deque<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const set<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

template<typename M>
struct fenwick_tree {
    using T = typename M::T;
    int n;
    std::vector<T> data;
    fenwick_tree(int n) : n(n), data(n + 1, M::id()) {}
    void add(int i, const T &x) { for (i++; i <= n; i += i & -i) { data[i] = M::op(data[i], x); }}
    T get_sum(int i) const {
        T ret = M::id();
        for (; i > 0; i -= i & -i) { ret = M::op(ret, data[i]); }
        return ret;
    }
    T get_sum(int l, int r) const {
        return M::op(get_sum(r), M::inv(get_sum(l)));
    }
};

struct rsq {
    using T = int;
    static T id() { return 0; }
    static T op(const T &a, const T &b) { return a + b; }
    static T inv(const T &a) { return -a; }
};

signed main() {
    int n, m;
    cin >> n >> m;
    vint lx(n + 2), rx(n + 2), y(n + 2);
    vint x(m + 2), ly(m + 2), ry(m + 2);
    rep(i, n) { cin >> y[i] >> lx[i] >> rx[i]; }
    lx[n] = 0, rx[n] = 1e6, y[n] = 0;
    lx[n + 1] = 0, rx[n + 1] = 1e6, y[n + 1] = 1e6;
    rep(i, m) { cin >> x[i] >> ly[i] >> ry[i]; }
    ly[m] = 0, ry[m] = 1e6, x[m] = 0;
    ly[m + 1] = 0, ry[m + 1] = 1e6, x[m + 1] = 1e6;
    fenwick_tree<rsq> ft(1100000);
    vector<tuple<int, int, int>> vs;
    rep(i, n + 2) { vs.emplace_back(y[i], 1, i); }
    rep(i, m + 2) {
        vs.emplace_back(ly[i], 0, i);
        vs.emplace_back(ry[i], 2, i);
    }
    sort(all(vs));
    int ans = 0;
    for (int i = 0; i < vs.size(); i++) {
        int type = get<1>(vs[i]), idx = get<2>(vs[i]);
        if (type == 0) {
            ft.add(x[idx], 1);
        } else if (type == 1) {
            ans += max(0LL, ft.get_sum(lx[idx], rx[idx] + 1) - 1);
        } else {
            ft.add(x[idx], -1);
        }
    }
    ans -= m + 1;
    cout << ans << endl;
}