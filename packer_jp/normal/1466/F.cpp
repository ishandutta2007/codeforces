#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(a) (a).begin(), (a).end()
#define uniq(a) (a).erase(unique(all(a)), (a).end())
#define dump(a) cerr << #a " = " << (a) << endl
using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int bit(int n) { return 1LL << n; }
int sign(int a) { return (a > 0) - (a < 0); }
int cdiv(int a, int b) { return (a - 1 + b) / b; }
template<typename T> T sq(T a) { return a * a; }
template<typename T> void fin(T a) {
    cout << a << endl;
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
template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &a) {
    os << "(" << a.first << ", " << a.second << ")";
    return os;
}
template<typename T, typename U, typename V> ostream &operator<<(ostream &os, const tuple<T, U, V> &a) {
    os << "(" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const deque<T> &a) {
    os << "(";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const set<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    }
} setup;

template<int MOD = 1000000007>
struct mod_int {
    int v;
    mod_int(long long v_ = 0) : v(v_ % MOD) { if (v < 0) { v += MOD; }}
    static int mod() { return MOD; }
    int val() const { return v; }
    mod_int &operator+=(const mod_int &a) {
        if ((v += a.v) >= MOD) { v -= MOD; }
        return *this;
    }
    mod_int &operator-=(const mod_int &a) {
        if ((v += MOD - a.v) >= MOD) { v -= MOD; }
        return *this;
    }
    mod_int &operator*=(const mod_int &a) {
        v = (int) ((long long) v * a.v % MOD);
        return *this;
    }
    mod_int &operator/=(const mod_int &a) { return *this *= a.inv(); }
    mod_int operator+() const { return *this; }
    mod_int operator-() const { return -v; }
    mod_int operator++() { return *this += 1; }
    mod_int operator--() { return *this -= 1; }
    mod_int operator++(signed) {
        const mod_int ret(*this);
        ++*this;
        return ret;
    }
    mod_int operator--(signed) {
        const mod_int ret(*this);
        --*this;
        return ret;
    }
    mod_int inv() const {
        int a = v, b = MOD, x = 1, u = 0;
        while (b) {
            int t = a / b;
            std::swap(a -= t * b, b), std::swap(x -= t * u, u);
        }
        return x;
    }
    mod_int pow(long long n) const {
        if (n < 0) { return pow(-n).inv(); }
        mod_int ret = 1, mul = *this;
        while (n) {
            if (n & 1) { ret *= mul; }
            mul *= mul, n >>= 1;
        }
        return ret;
    }
    friend bool operator==(const mod_int &a, const mod_int &b) { return a.v == b.v; }
    friend bool operator!=(const mod_int &a, const mod_int &b) { return std::rel_ops::operator!=(a, b); }
    friend mod_int operator+(mod_int a, const mod_int &b) { return a += b; }
    friend mod_int operator-(mod_int a, const mod_int &b) { return a -= b; }
    friend mod_int operator*(mod_int a, const mod_int &b) { return a *= b; }
    friend mod_int operator/(mod_int a, const mod_int &b) { return a /= b; }
    friend std::istream &operator>>(std::istream &is, mod_int &a) {
        long long v;
        is >> v, a = v;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mod_int &a) { return os << a.v; }
};
using mint = mod_int<>;

template<typename S>
struct union_find_tree {
    using T = typename S::T;
    std::vector<int> par, sz;
    std::vector<T> val;
    union_find_tree(const std::vector<T> &val) : par(val.size(), -1), sz(val.size(), 1), val(val) {}
    union_find_tree(int n, const T &x = {}) : union_find_tree(std::vector<T>(n, x)) {}
    int root(int i) {
        if (par[i] == -1) { return i; }
        else { return par[i] = root(par[i]); }
    }
    void unite(int i, int j) {
        if ((i = root(i)) == (j = root(j))) { return; }
        if (sz[i] < sz[j]) { std::swap(i, j); }
        sz[i] += sz[j];
        S::merge(val[i], val[j]);
        par[j] = i;
    }
    bool same(int i, int j) { return root(i) == root(j); }
    int size(int i) { return sz[root(i)]; }
    T &operator[](int i) { return val[root(i)]; }
};

struct S {
    struct T {};
    static void merge(T &a, const T &b) {
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    vector x(n, vint(2));
    rep(i, n) {
        int k;
        cin >> k;
        if (k == 1) {
            cin >> x[i][1];
        } else {
            cin >> x[i][0] >> x[i][1];
        }
    }
    union_find_tree<S> uf(m + 1);
    vint ans;
    rep(i, n) {
        if (!uf.same(x[i][0], x[i][1])) {
            uf.unite(x[i][0], x[i][1]);
            ans.emplace_back(i);
        }
    }
    cout << mint(2).pow(ans.size()) << " " << ans.size() << endl;
    rep(i, ans.size()) { cout << ans[i] + 1 << " "; }
    cout << endl;
}