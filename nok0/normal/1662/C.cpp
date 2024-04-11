#line 1 "c.cpp"
/*	author:  Kite_kuma
    created: 2022.04.29 15:02:17 */

#line 1 "Library/kuma_template.hpp"
// #ifdef LOCAL
// #define _GLIBCXX_DEBUG
// #endif
#include <bits/stdc++.h>

#define foa(s, v) for (auto &s : v)
#define all(v)    (v).begin(), (v).end()
#define rall(v)   (v).rbegin(), (v).rend()
#define pcnt(n)   __builtin_popcountll((long long)n)

#define REPname(a, b, c, d, e, ...)  e
#define rep(...)                     REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define REP0(x)                      for (int Counter_in_rep_macro = 0; Counter_in_rep_macro < (x); ++Counter_in_rep_macro)
#define REP1(i, x)                   for (int i = 0; i < (x); ++i)
#define REP2(i, l, r)                for (int i = (l); i < (r); ++i)
#define REP3(i, l, r, c)             for (int i = (l); i < (r); i += (c))
#define DREPname(a, b, c, d, e, ...) e
#define drep(...)                    DREPname(__VA_ARGS__, DREP3, DREP2, DREP1)(__VA_ARGS__)
#define DREP1(i, x)                  for (int i = (x)-1; i >= 0; --i)
#define DREP2(i, l, r)               for (int i = (r)-1; i >= (l); --i)
#define DREP3(i, l, r, c)            for (int i = (r)-1; i >= (l); i -= (c))

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vvvi = std::vector<std::vector<std::vector<int>>>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
template<class T = ll>
using V = std::vector<T>;
template<class T = ll>
using VV = V<V<T>>;
template<class T = ll>
using VVV = V<V<V<T>>>;
template<class T = ll>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template<class T = ll>
using pqdn = std::priority_queue<T>;

constexpr int inf = 1000'000'000;
constexpr long long INF = 1000'000'000'000'000'000LL;
constexpr int mod_1000000007 = 1000000007;
constexpr int mod_998244353 = 998244353;
const long double pi = acosl(-1.);
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T0, class T1, class T2>
inline bool in_range(T0 x, T1 lef, T2 rig) {
    return ((lef <= x) && (x < rig));
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

void Yes(bool flag = true) { std::cout << (flag ? "Yes" : "No") << '\n'; }
void YES(bool flag = true) { std::cout << (flag ? "YES" : "NO") << '\n'; }

template<class T>
void drop(T answer) {
    std::cout << answer << '\n';
    exit(0);
}

void err(bool flag = true) {
    if (!flag) return;
    std::cout << -1 << '\n';
    exit(0);
}

template<class T>
void vout(std::vector<T> const &v, bool vertically = 0) {
    if (vertically) {
        for (auto const &a : v) {
            std::cout << a << '\n';
        }
        return;
    }
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << (*it);
        if (it != v.end() - 1) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';
    return;
}

inline void print() { std::cout << '\n'; }
template<class T>
inline void print(const T &x) {
    std::cout << x << '\n';
    return;
}
template<typename Head, typename... Tail>
void print(const Head &H, const Tail &...T) {
    std::cout << H << " ";
    print(T...);
}

template<class T>
void add(std::vector<T> &v, T value) {
    for (auto &a : v) a += value;
    return;
}

template<class T>
T dup(T a, T b) {
    assert(b > 0);
    return (a + b - 1) / b;
}

template<class T>
T greatest_lower_multiple(T x, T d) {
    if (d == 0) return 0;
    if (d < 0) d *= -1;
    T y = x % d;
    if (y < 0) y += d;
    return x - y;
}

template<class T>
T least_upper_multiple(T x, T d) {
    return -greatest_lower_multiple(-x, d);
}

long long pow_ll(long long a, long long n) {
    if (n == 0) return 1LL;
    if (a == 0) return 0LL;
    if (a == 1) return 1LL;
    if (a == -1) return (n & 1LL) ? -1LL : 1LL;
    long long ret = 1;
    while (n--) ret *= a;
    return ret;
}

long long modpow(long long a, long long n, long long mod) {  // a^n mod
    assert(n >= 0 && mod);
    if (mod == 1) return 0LL;
    long long res = 1;
    a %= mod;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res < 0 ? res + mod : res;
}

// return x which satisfies a * x % mod == gcd(a, mod)
// not (mod | a)
long long modinv(long long a, const long long &mod) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        std::swap(a, b);
        u -= t * v;
        std::swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

template<class T>
int lb(const std::vector<T> &a, const T x) {
    return (int)std::distance(a.begin(), std::lower_bound(a.begin(), a.end(), x));
}
template<class T>
int ub(const std::vector<T> &a, const T x) {
    return (int)std::distance(a.begin(), std::upper_bound(a.begin(), a.end(), x));
}
template<class T>
void unq_sort(std::vector<T> &a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}
template<class T>
std::vector<int> press(std::vector<T> &a) {
    auto vec = a;
    unq_sort(vec);
    std::vector<int> ret;
    for (auto &v : a) ret.push_back(lb(vec, v));
    return ret;
}

#define VEC(type, name, size) \
    vector<type> name(size);  \
    scanner::INPUT(name)
#define VVEC(type, name, h, w)                     \
    vector<vector<type>> name(h, vector<type>(w)); \
    scanner::INPUT(name)
#define INT(...)     \
    int __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
    long long __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define STR(...)        \
    string __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define CHR(...)      \
    char __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define DBL(...)        \
    double __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
    long double __VA_ARGS__; \
    scanner::INPUT(__VA_ARGS__)
#define TPL3(type0, type1, type2, name)   \
    std::tuple<type0, type1, type2> name; \
    scanner::INPUT(name);
#define TPL4(type0, type1, type2, type3, name)   \
    std::tuple<type0, type1, type2, type3> name; \
    scanner::INPUT(name);

namespace scanner {
template<class T>
void scan(T &a) {
    std::cin >> a;
}

template<class T, class L>
void scan(std::pair<T, L> &p) {
    scan(p.first);
    scan(p.second);
}

template<class T0, class T1, class T2>
void scan(std::tuple<T0, T1, T2> &p) {
    T0 t0;
    T1 t1;
    T2 t2;
    scan(t0);
    scan(t1);
    scan(t2);
    p = std::make_tuple(t0, t1, t2);
}

template<class T0, class T1, class T2, class T3>
void scan(std::tuple<T0, T1, T2, T3> &p) {
    T0 t0;
    T1 t1;
    T2 t2;
    T3 t3;
    scan(t0);
    scan(t1);
    scan(t2);
    scan(t3);
    p = std::make_tuple(t0, t1, t2, t3);
}

template<class T>
void scan(std::vector<T> &a) {
    for (auto &i : a) scan(i);
}

void INPUT() {}
template<class Head, class... Tail>
void INPUT(Head &head, Tail &...tail) {
    scan(head);
    INPUT(tail...);
}
}  // namespace scanner

template<typename T1, typename T2>
std::istream &operator>>(std::istream &is, std::pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T1, typename T2>
std::ostream &std::operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
    os << p.first << " " << p.second;
    return os;
}
template<class T>
std::ostream &std::operator<<(std::ostream &os, const std::vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (i) os << " ";
        os << v[i];
    }
    return os;
}

namespace viewer {
void view(const long long &e) {
    if (e == INF)
        std::cerr << "INF";
    else if (e == -INF)
        std::cerr << "-INF";
    else
        std::cerr << e;
}

void view(const int &e) {
    if (e == inf)
        std::cerr << "inf";
    else if (e == -inf)
        std::cerr << "-inf";
    else
        std::cerr << e;
}

template<typename T>
void view(const T &e) {
    std::cerr << e;
}

template<typename T, typename U>
void view(const std::pair<T, U> &p) {
    std::cerr << "(";
    view(p.first);
    std::cerr << ", ";
    view(p.second);
    std::cerr << ")";
}

template<class T0, class T1, class T2>
void view(const std::tuple<T0, T1, T2> &p) {
    std::cerr << "(";
    view(std::get<0>(p));
    std::cerr << ", ";
    view(std::get<1>(p));
    std::cerr << ", ";
    view(std::get<2>(p));
    std::cerr << ")";
}

template<class T0, class T1, class T2, class T3>
void view(const std::tuple<T0, T1, T2, T3> &p) {
    std::cerr << "(";
    view(std::get<0>(p));
    std::cerr << ", ";
    view(std::get<1>(p));
    std::cerr << ", ";
    view(std::get<2>(p));
    std::cerr << ", ";
    view(std::get<3>(p));
    std::cerr << ")";
}

template<typename T>
void view(const std::set<T> &s) {
    if (s.empty()) {
        std::cerr << "{ }";
        return;
    }
    std::cerr << "{ ";
    for (auto &t : s) {
        view(t);
        std::cerr << ", ";
    }
    std::cerr << "\b\b }";
}

template<typename T>
void view(const std::unordered_set<T> &s) {
    if (s.empty()) {
        std::cerr << "{ }";
        return;
    }
    std::cerr << "{ ";
    for (auto &t : s) {
        view(t);
        std::cerr << ", ";
    }
    std::cerr << "\b\b }";
}

template<typename T>
void view(const std::multiset<T> &s) {
    if (s.empty()) {
        std::cerr << "{ }";
        return;
    }
    std::cerr << "{ ";
    for (auto &t : s) {
        view(t);
        std::cerr << ", ";
    }
    std::cerr << "\b\b }";
}

template<typename T>
void view(const std::unordered_multiset<T> &s) {
    if (s.empty()) {
        std::cerr << "{ }";
        return;
    }
    std::cerr << "{ ";
    for (auto &t : s) {
        view(t);
        std::cerr << ", ";
    }
    std::cerr << "\b\b }";
}

template<typename T>
void view(const std::vector<T> &v) {
    if (v.empty()) {
        std::cerr << "{ }";
        return;
    }
    std::cerr << "{ ";
    for (const auto &e : v) {
        view(e);
        std::cerr << ", ";
    }
    std::cerr << "\b\b }";
}

template<typename T, std::size_t ary_size>
void view(const std::array<T, ary_size> &v) {
    if (v.empty()) {
        std::cerr << "{ }";
        return;
    }
    std::cerr << "{ ";
    for (const auto &e : v) {
        view(e);
        std::cerr << ", ";
    }
    std::cerr << "\b\b }";
}

template<typename T>
void view(const std::vector<std::vector<T>> &vv) {
    std::cerr << "{\n";
    for (const auto &v : vv) {
        std::cerr << "\t";
        view(v);
        std::cerr << '\n';
    }
    std::cerr << "}";
}

template<typename T, typename U>
void view(const std::vector<std::pair<T, U>> &v) {
    std::cerr << "{\n";
    for (const auto &c : v) {
        std::cerr << "\t(";
        view(c.first);
        std::cerr << ", ";
        view(c.second);
        std::cerr << ")\n";
    }
    std::cerr << "}";
}

template<class T0, class T1, class T2>
void view(const std::vector<std::tuple<T0, T1, T2>> &v) {
    if (v.empty()) {
        std::cerr << "{ }";
        return;
    }
    std::cerr << '{';
    for (const auto &t : v) {
        std::cerr << "\n\t";
        view(t);
        std::cerr << ",";
    }
    std::cerr << "\n}";
}

template<class T0, class T1, class T2, class T3>
void view(const std::vector<std::tuple<T0, T1, T2, T3>> &v) {
    if (v.empty()) {
        std::cerr << "{ }";
        return;
    }
    std::cerr << '{';
    for (const auto &t : v) {
        std::cerr << "\n\t";
        view(t);
        std::cerr << ",";
    }
    std::cerr << "\n}";
}

template<typename T, typename U>
void view(const std::map<T, U> &m) {
    std::cerr << "{\n";
    for (const auto &t : m) {
        std::cerr << "\t[";
        view(t.first);
        std::cerr << "] : ";
        view(t.second);
        std::cerr << '\n';
    }
    std::cerr << "}";
}

template<typename T, typename U>
void view(const std::unordered_map<T, U> &m) {
    std::cerr << "{\n";
    for (const auto &t : m) {
        std::cerr << "\t[";
        view(t.first);
        std::cerr << "] : ";
        view(t.second);
        std::cerr << '\n';
    }
    std::cerr << "}";
}
}  // namespace viewer

// when compiling : g++ foo.cpp -DLOCAL
#ifdef LOCAL
void debug_out() {}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    viewer::view(H);
    std::cerr << ", ";
    debug_out(T...);
}
#define debug(...)                                                \
    do {                                                          \
        std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
        debug_out(__VA_ARGS__);                                   \
        std::cerr << "\b\b]\n";                                   \
    } while (0)
#define dump(x)                                      \
    do {                                             \
        std::cerr << __LINE__ << " " << #x << " : "; \
        viewer::view(x);                             \
        std::cerr << '\n';                           \
    } while (0)

#else
#define debug(...) (void(0))
#define dump(x)    (void(0))
#endif

struct fast_io {
    fast_io() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(15);
        srand((unsigned)time(NULL));
    }
} fast_io_;

using namespace std;
#line 5 "c.cpp"

#pragma region modint

const int mod = mod_998244353;

template<int mod>
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    ModInt pow(long long n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
    friend istream &operator>>(istream &is, ModInt &a) {
        long long t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }
    static int get_mod() { return mod; }
};
using mint = ModInt<mod>;

#pragma endregion

#pragma region matrix

template<typename T>
struct Matrix {
    std::vector<std::vector<T>> A;

private:
    static Matrix I(size_t n) {
        Matrix mat(n);
        for (int i = 0; i < n; i++) mat[i][i] = 1;
        return mat;
    }

public:
    Matrix() = default;

    Matrix(std::vector<std::vector<T>> &vvec) { A = vvec; }

    Matrix(size_t n, size_t m) : A(n, std::vector<T>(m, 0)) {}

    Matrix(size_t n, size_t m, T init) : A(n, std::vector<T>(m, init)) {}

    Matrix(size_t n, std::vector<T> &vec) : A(n, vec) {}

    Matrix(size_t n) : A(n, std::vector<T>(n, 0)) {}

    int height() const { return A.size(); }

    int width() const { return A[0].size(); }

    inline const std::vector<T> &operator[](int k) const { return A[k]; }

    inline std::vector<T> &operator[](int k) { return A[k]; }

    Matrix &operator+=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];
        return *this;
    }

    Matrix &operator-=(const Matrix &B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];
        return *this;
    }

    Matrix &operator*=(const Matrix &B) {
        size_t n = height(), m = B.width(), p = width();
        assert(p == B.height());
        std::vector<std::vector<T>> C(n, std::vector<T>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < p; k++) C[i][j] += (*this)[i][k] * B[k][j];
        A.swap(C);
        return (*this);
    }

    Matrix &operator^=(long long k) {
        Matrix B = Matrix::I(height());
        while (k > 0) {
            if (k & 1) B *= (*this);
            *this *= *this;
            k >>= 1;
        }
        A.swap(B.A);
        return *this;
    }

    bool operator==(const Matrix &B) {
        size_t n = height(), m = width();
        if (n != B.height() or m != B.width()) return false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if ((*this)[i][j] != B[i][j]) return false;
        return true;
    }

    Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }

    Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }

    Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }

    Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }

    Matrix &operator+=(const T &t) {
        int n = height(), m = width();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] += t;
        return *this;
    }

    Matrix &operator-=(const T &t) {
        int n = height(), m = width();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] -= t;
        return *this;
    }

    Matrix &operator*=(const T &t) {
        int n = height(), m = width();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] *= t;
        return *this;
    }

    Matrix &operator/=(const T &t) {
        int n = height(), m = width();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] /= t;
        return *this;
    }

    Matrix operator+(const T &t) const { return (Matrix(*this) += t); }

    Matrix operator-(const T &t) const { return (Matrix(*this) -= t); }

    Matrix operator*(const T &t) const { return (Matrix(*this) *= t); }

    Matrix operator/(const T &t) const { return (Matrix(*this) /= t); }

    friend std::ostream &operator<<(std::ostream &os, Matrix &p) {
        size_t n = p.height(), m = p.width();
        for (int i = 0; i < n; i++) {
            os << '[';
            for (int j = 0; j < m; j++) os << p[i][j] << (j == m - 1 ? "]\n" : ",");
        }
        return (os);
    }

    T determinant() {
        Matrix B(*this);
        size_t n = height(), m = width();
        assert(n == m);
        T ret = 1;
        for (int i = 0; i < n; i++) {
            int idx = -1;
            for (int j = i; j < n; j++)
                if (B[j][i] != 0) idx = j;
            if (idx == -1) return 0;
            if (i != idx) {
                ret *= -1;
                swap(B[i], B[idx]);
            }
            ret *= B[i][i];
            T vv = B[i][i];
            for (int j = 0; j < n; j++) B[i][j] /= vv;
            for (int j = i + 1; j < n; j++) {
                T a = B[j][i];
                for (int k = 0; k < n; k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return ret;
    }
};

#pragma endregion

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int k;
    cin >> k;
    Matrix<mint> movemat(n), deg(n);
    rep(i, n) deg[i][i] = -1;
    Matrix<mint> md(n + n);
    rep(m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        movemat[a][b] += 1;
        movemat[b][a] += 1;
        deg[a][a] += 1;
        deg[b][b] += 1;
    }
    rep(i, n) md[i][i + n] = 1;
    rep(i, n) md[i + n][i] = -deg[i][i];
    rep(i, n) rep(j, n) md[i][j] = movemat[i][j];

    Matrix<mint> a0(n);
    rep(i, n) a0[i][i] = 1;
    Matrix<mint> a1 = movemat;
    Matrix<mint> a2 = movemat * movemat;
    rep(i, n) a2[i][i] -= deg[i][i] + 1;

    Matrix<mint> b1(n, n + n);

    rep(i, n) rep(j, n) {
        b1[i][j] = a2[i][j];
        b1[i][j + n] = a1[i][j];
    }

    Matrix<mint> bk = b1 * (md ^ (k - 1));
    debug(bk.A);
    mint ans = 0;
    rep(i, n) ans += bk[i][i + n];
    print(ans);
}