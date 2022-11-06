#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(a) (a).begin(), (a).end()
#define uniq(a) (a).erase(unique(all(a)), (a).end())
#define bit(n) (1LL << (n))
#define dump(a) cerr << #a " = " << (a) << endl
using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;
template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
constexpr double PI = 3.1415926535897932384626433832795028;
constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int DX[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int sign(int a) { return (a > 0) - (a < 0); }
int cdiv(int a, int b) { return (a - 1 + b) / b; }
template<typename T> void fin(T a) {
    cout << a << endl;
    exit(0);
}
template<typename T> T sq(T a) { return a * a; }
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
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const deque<T> &a) {
    os << "{";
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        os << *itr << (next(itr) != a.end() ? ", " : "");
    }
    os << "}";
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
    };
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
using mint = mod_int<998244353>;

template<typename T>
struct combination {
    std::vector<T> fact, finv, inv;
    combination(int n) : fact(n + 1), finv(n + 1), inv(n + 1) {
        fact[0] = fact[1] = finv[0] = finv[1] = inv[1] = 1;
        for (int i = 2; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            inv[i] = -inv[T::mod() % i] * (T::mod() / i);
            finv[i] = finv[i - 1] * inv[i];
        }
    }
    T P(int n, int r) { return r < 0 || n < r ? 0 : (fact[n] * finv[n - r]); }
    T C(int n, int r) { return P(n, r) * finv[r]; }
    T H(int n, int r) { return C(n + r - 1, r); }
    T catalan(int n) { return C(2 * n, n) * inv[n + 1]; }
};

signed main() {
    int n;
    cin >> n;
    combination<mint> comb(n * 2);
    vint a(n * 2);
    rep(i, n * 2) { cin >> a[i]; }
    vint l(n), r(n);
    rep(i, n) { l[i] = a[i], r[i] = a[i + n]; }
    sort(all(l)), sort(all(r)), reverse(all(r));
    mint ans = 0;
    rep(i, n) { ans += abs(l[i] - r[i]); }
    ans *= comb.C(n * 2, n);
    cout << ans << endl;
}