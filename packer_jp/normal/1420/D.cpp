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

template<int MOD = 1000000007>
struct mod_int {
    int val;
    mod_int(long long val_ = 0) : val(val_ % MOD) { if (val < 0) { val += MOD; }}
    bool operator==(const mod_int &rhs) const { return val == rhs.val; }
    bool operator!=(const mod_int &rhs) const { return std::rel_ops::operator!=(*this, rhs); }
    mod_int &operator+=(const mod_int &rhs) {
        if ((val += rhs.val) >= MOD) { val -= MOD; }
        return *this;
    }
    mod_int &operator-=(const mod_int &rhs) {
        if ((val += MOD - rhs.val) >= MOD) { val -= MOD; }
        return *this;
    }
    mod_int &operator*=(const mod_int &rhs) {
        val = (int) ((long long) val * rhs.val % MOD);
        return *this;
    }
    mod_int &operator/=(const mod_int &rhs) { return *this *= rhs.inv(); }
    mod_int operator+() const { return *this; }
    mod_int operator-() const { return -val; }
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
    mod_int operator+(const mod_int &rhs) const { return mod_int(*this) += rhs; }
    mod_int operator-(const mod_int &rhs) const { return mod_int(*this) -= rhs; }
    mod_int operator*(const mod_int &rhs) const { return mod_int(*this) *= rhs; }
    mod_int operator/(const mod_int &rhs) const { return mod_int(*this) /= rhs; }
    mod_int inv() const {
        assert(val != 0);
        int a = val, b = MOD, x = 1, u = 0;
        while (b) {
            int t = a / b;
            std::swap(a -= t * b, b);
            std::swap(x -= t * u, u);
        }
        return x;
    }
    mod_int pow(long long n) const {
        if (n < 0) { return pow(-n).inv(); }
        mod_int ret = 1, mul = *this;
        while (n) {
            if (n & 1) { ret *= mul; }
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend std::istream &operator>>(std::istream &is, mod_int &rhs) {
        long long v;
        is >> v;
        rhs = v;
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mod_int &rhs) { return os << rhs.val; }
    struct combination {
        std::vector<mod_int> fact{1, 1}, f_inv{1, 1}, inv{0, 1};
        void calc(int n) {
            fact.resize(n + 1), f_inv.resize(n + 1), inv.resize(n + 1);
            for (int i = 2; i <= n; i++) {
                fact[i] = fact[i - 1] * i;
                inv[i] = -inv[MOD % i] * (MOD / i);
                f_inv[i] = f_inv[i - 1] * inv[i];
            }
        }
        mod_int P(int n, int r) { return r < 0 || n < r ? 0 : fact[n] * f_inv[n - r]; }
        mod_int C(int n, int r) { return r < 0 || n < r ? 0 : fact[n] * f_inv[r] * f_inv[n - r]; }
        mod_int H(int n, int r) { return C(n + r - 1, r); }
    };
};
using mint = mod_int<998244353>;

struct fast_io {
    static constexpr int SIZE_IN = 1 << 26, SIZE_OUT = 1 << 26;
    char data_in[SIZE_IN], data_out[SIZE_OUT], *p_in, *p_out, s[30];
    fast_io() { fread(data_in, 1, SIZE_IN, stdin), p_in = data_in, p_out = data_out; }
    ~fast_io() { fwrite(data_out, 1, p_out - data_out, stdout); }
    void putchar(char x) { *p_out++ = x; }
    template<typename T> void putint(T x) {
        if (x < 0) { *p_out++ = '-', x = -x; }
        int i = 0;
        do { s[i++] = x % 10 + '0'; } while (x /= 10);
        while (i--) { *p_out++ = s[i]; }
    }
    template<typename T=int> T getint() {
        while (!isdigit(*p_in) && *p_in != '-') { p_in++; }
        bool negative = *p_in == '-';
        T ret = negative ? 0 : *p_in - '0';
        while (isdigit(*++p_in)) { (ret *= 10) += *p_in - '0'; };
        return negative ? -ret : ret;
    }
} io;

signed main() {
    int n = io.getint(), k = io.getint();
    vint l(n), r(n);
    rep(i, n) { l[i] = io.getint(), r[i] = io.getint(); }
    vector<pint> ev;
    rep(i, n) { ev.emplace_back(l[i], 0); }
    rep(i, n) { ev.emplace_back(r[i], 1); }
    sort(all(ev));
    mint ans = 0;
    mint::combination comb;
    comb.calc(n);
    int cur = 0;
    for (auto[x, t]:ev) {
        if (t == 0) { ans += comb.C(cur, k - 1), cur++; }
        if (t == 1) { cur--; }
    }
    io.putint(ans.val), io.putchar('\n');
}