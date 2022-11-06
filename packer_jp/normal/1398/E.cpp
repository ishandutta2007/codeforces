#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define bit(n) (1LL << (n))
#define cdiv(a, b) (((a) - 1) / (b) + 1)
#define dump(x) cerr << #x " = " << (x) << endl
using vint = vector<int>;
using vvint = vector<vint>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int sign(int x) { return (x > 0) - (x < 0); }
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

template<typename F> long long discrete_binary_search(long long ok, long long ng, F is_ok) {
    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        (is_ok(mid) ? ok : ng) = mid;
    }
    return ok;
}

signed main() {
    int n;
    cin >> n;
    vint tp(n), d(n);
    vint v;
    rep(i, n) {
        cin >> tp[i] >> d[i];
        v.emplace_back(abs(d[i]));
    }
    sort(all(v)), reverse(all(v)), uniq(v);
    map<int, int> mp;
    rep(i, v.size()) { mp[v[i]] = i; }
    fenwick_tree<rsq> ftf(v.size()), ftl(v.size());
    fenwick_tree<rsq> ftfs(v.size()), ftls(v.size());
    int cur = 0;
    rep(i, n) {
        cur += d[i];
        if (tp[i]) {
            if (d[i] > 0) { ftl.add(mp[abs(d[i])], 1); }
            else { ftl.add(mp[abs(d[i])], -1); }
            ftls.add(mp[abs(d[i])], d[i]);
        } else {
            if (d[i] > 0) { ftf.add(mp[abs(d[i])], 1); }
            else { ftf.add(mp[abs(d[i])], -1); }
            ftfs.add(mp[abs(d[i])], d[i]);
        }
        int k = ftl.get_sum(v.size());
        int x = discrete_binary_search(v.size(), -1, [&](int x) {
            return ftf.get_sum(x) + ftl.get_sum(x) >= k;
        });
        if (k == 0) {
            cout << cur << endl;
        } else if (ftl.get_sum(x) == k) {
            int xf = discrete_binary_search(v.size(), -1, [&](int x) {
                return ftf.get_sum(x) >= 1;
            });
            int xl = discrete_binary_search(v.size(), -1, [&](int x) {
                return ftl.get_sum(x) >= k - 1;
            });
            cout << cur + ftfs.get_sum(xf) + ftls.get_sum(xl) << endl;
        } else {
            cout << cur + ftfs.get_sum(x) + ftls.get_sum(x) << endl;
        }
    }
}