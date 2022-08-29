#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct barrett_reduction {
    unsigned mod;
    uint64_t div;

    barrett_reduction(unsigned m) : mod(m), div(-1LLU / m) {}

    unsigned operator()(uint64_t a) const {
#ifdef __SIZEOF_INT128__
        uint64_t q = uint64_t(__uint128_t(div) * a >> 64);
        uint64_t r = a - q * mod;
        return unsigned(r < mod ? r : r - mod);
#endif
        return unsigned(a % mod);
    }
};

template<const int &MOD, const barrett_reduction &barrett>
struct _b_int {
    int val;

    _b_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _b_int(uint64_t v) {
        if (v >= uint64_t(MOD)) v %= MOD;
        val = int(v);
    }

    _b_int(int v) : _b_int(int64_t(v)) {}
    _b_int(unsigned v) : _b_int(uint64_t(v)) {}

    static int inv_mod(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _b_int& operator+=(const _b_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    _b_int& operator-=(const _b_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x) {
#if !defined(_WIN32) || defined(_WIN64)
        return barrett(x);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * MOD for this to work, so that x / MOD fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (MOD));
        return rem;
    }

    _b_int& operator*=(const _b_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    _b_int& operator/=(const _b_int &other) {
        return *this *= other.inv();
    }

    friend _b_int operator+(const _b_int &a, const _b_int &b) { return _b_int(a) += b; }
    friend _b_int operator-(const _b_int &a, const _b_int &b) { return _b_int(a) -= b; }
    friend _b_int operator*(const _b_int &a, const _b_int &b) { return _b_int(a) *= b; }
    friend _b_int operator/(const _b_int &a, const _b_int &b) { return _b_int(a) /= b; }

    _b_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _b_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _b_int operator++(int) { _b_int before = *this; ++*this; return before; }
    _b_int operator--(int) { _b_int before = *this; --*this; return before; }

    _b_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    friend bool operator==(const _b_int &a, const _b_int &b) { return a.val == b.val; }
    friend bool operator!=(const _b_int &a, const _b_int &b) { return a.val != b.val; }
    friend bool operator<(const _b_int &a, const _b_int &b) { return a.val < b.val; }
    friend bool operator>(const _b_int &a, const _b_int &b) { return a.val > b.val; }
    friend bool operator<=(const _b_int &a, const _b_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _b_int &a, const _b_int &b) { return a.val >= b.val; }

    _b_int inv() const {
        return inv_mod(val);
    }

    _b_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _b_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _b_int &m) {
        return os << m.val;
    }

    friend istream& operator>>(istream &is, _b_int &m) {
        int64_t x;
        is >> x;
        m = x;
        return is;
    }
};

int MOD = 2;
barrett_reduction barrett(MOD);
using barrett_int = _b_int<MOD, barrett>;


vector<barrett_int> _factorial = {1}, _inv_factorial = {1};

void prepare_factorials(int64_t maximum) {
    static int64_t prepared_maximum = 0;

    if (maximum <= prepared_maximum)
        return;

    // Prevent increasing maximum by only 1 each time.
    maximum += maximum / 100;
    _factorial.resize(maximum + 1);
    _inv_factorial.resize(maximum + 1);

    for (int64_t i = prepared_maximum + 1; i <= maximum; i++)
        _factorial[i] = i * _factorial[i - 1];

    _inv_factorial[maximum] = _factorial[maximum].inv();

    for (int64_t i = maximum - 1; i > prepared_maximum; i--)
        _inv_factorial[i] = (i + 1) * _inv_factorial[i + 1];

    prepared_maximum = maximum;
}

barrett_int factorial(int64_t n) {
    if (n < 0) return 0;
    prepare_factorials(n);
    return _factorial[n];
}

barrett_int inv_factorial(int64_t n) {
    if (n < 0) return 0;
    prepare_factorials(n);
    return _inv_factorial[n];
}

barrett_int choose(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    prepare_factorials(n);
    return _factorial[n] * _inv_factorial[r] * _inv_factorial[n - r];
}

barrett_int permute(int64_t n, int64_t r) {
    if (r < 0 || r > n) return 0;
    prepare_factorials(n);
    return _factorial[n] * _inv_factorial[n - r];
}

barrett_int inv_choose(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    prepare_factorials(n);
    return _inv_factorial[n] * _factorial[r] * _factorial[n - r];
}

barrett_int inv_permute(int64_t n, int64_t r) {
    assert(0 <= r && r <= n);
    prepare_factorials(n);
    return _inv_factorial[n] * _factorial[n - r];
}

int main() {
    int N;
    cin >> N >> MOD;
    barrett = barrett_reduction(MOD);
    barrett_int total = 0;

    for (int chains = 1; chains <= N; chains++) {
        barrett_int inv_N_1 = barrett_int(N - 1).inv();
        barrett_int N_1_pow = barrett_int(N - 1).pow(chains);
        barrett_int N_chains_pow = 1;

        for (int singles = 0; singles <= chains - (chains < N); singles++) {
            int k = N - singles;
            int twos = chains - singles;

            if (k >= 2 * twos) {
                barrett_int ways = choose(N, singles);
                ways *= permute(k, 2 * twos) * inv_factorial(twos);
                ways *= factorial(k - 2 * twos + twos - 1) * inv_factorial(twos - 1);
                total += ways * N_1_pow * N_chains_pow;
            }

            N_1_pow *= inv_N_1;
            N_chains_pow *= N - chains;
        }
    }

    cout << total << '\n';
}