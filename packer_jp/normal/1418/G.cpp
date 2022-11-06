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
template<typename T> T sq(T x) { return x * x; }
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
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &rhs) {
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
struct lazy_segment_tree {
    using T = typename M::T;
    using E = typename M::E;
    int n;
    std::vector<T> data;
    std::vector<E> lazy;
    lazy_segment_tree(int n) : n(n), data(n << 1, M::id_T()), lazy(n << 1, M::id_E()) {}
    lazy_segment_tree(const std::vector<T> &src) : n(src.size()), data(n << 1), lazy(n << 1, M::id_E()) {
        std::copy(src.begin(), src.end(), data.begin() + n);
        for (int i = n - 1; i > 0; i--) { data[i] = M::op_TT(data[i << 1 | 0], data[i << 1 | 1]); }
    }
    void propagate(int i) {
        if (i < 1) { return; }
        data[i] = M::op_TE(data[i], lazy[i]);
        if (i < n) {
            lazy[i << 1 | 0] = M::op_EE(lazy[i << 1 | 0], lazy[i]);
            lazy[i << 1 | 1] = M::op_EE(lazy[i << 1 | 1], lazy[i]);
        }
        lazy[i] = M::id_E();
    }
    void apply(int l, int r, const E &x) {
        l += n, r += n - 1;
        for (int i = std::__lg(r); i > 0; i--) {
            propagate(l >> i);
            propagate(r >> i);
        }
        auto update = [&](int i) { lazy[i] = M::op_EE(lazy[i], x), propagate(i); };
        for (int i = l, j = r + 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1) { update(i++); }
            if (j & 1) { update(--j); }
        }
        while (l >>= 1, r >>= 1) {
            data[l] = M::op_TT(M::op_TE(data[l << 1 | 0], lazy[l << 1 | 0]),
                               M::op_TE(data[l << 1 | 1], lazy[l << 1 | 1]));
            data[r] = M::op_TT(M::op_TE(data[r << 1 | 0], lazy[r << 1 | 0]),
                               M::op_TE(data[r << 1 | 1], lazy[r << 1 | 1]));
        }
    }
    T fold(int l, int r) {
        l += n, r += n - 1;
        for (int i = std::__lg(r); i > 0; i--) { propagate(l >> i), propagate(r >> i); }
        T a = M::id_T(), b = M::id_T();
        for (r++; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { propagate(l), a = M::op_TT(a, data[l++]); }
            if (r & 1) { propagate(--r), b = M::op_TT(data[r], b); }
        }
        return M::op_TT(a, b);
    }
};

struct rminq_and_raq {
    using T = pair<int, int>;
    using E = int;
    static T id_T() { return {INT_MAX * 2LL, 0}; };
    static E id_E() { return 0; };
    static T op_TT(const T &a, const T &b) {
        if (a.first < b.first) { return a; }
        else if (a.first > b.first) { return b; }
        else { return {a.first, a.second + b.second}; }
    }
    static E op_EE(const E &a, const E &b) { return a + b; }
    static T op_TE(const T &a, const E &b) { return {a.first + b, a.second}; }
};

signed main() {
    int n;
    cin >> n;
    vint a(n);
    rep(i, n) { cin >> a[i], a[i]--; }
    int ans = 0;
    vector qs(n, queue<int>());
    vector<pint> src(n, {INT_MAX, 1});
    lazy_segment_tree<rminq_and_raq> lst(src);
    rep(i, n) {
        qs[a[i]].emplace(i);
        if (qs[a[i]].size() == 4) {
            int idx = qs[a[i]].front();
            lst.apply(idx, idx + 1, INT_MAX);
            lst.apply(0, idx + 1, 3);
            qs[a[i]].pop();
        }
        if (qs[a[i]].size() == 3) {
            int idx = qs[a[i]].front();
            lst.apply(idx, idx + 1, -INT_MAX);
            lst.apply(0, idx + 1, -3);
        }
        lst.apply(0, i + 1, 1);
        pint m = lst.fold(0, n);
        if (m.first == 0) { ans += m.second; }
    }
    cout << ans << endl;
}