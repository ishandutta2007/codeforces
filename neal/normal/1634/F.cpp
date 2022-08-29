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
        if (v >= MOD) v %= MOD;
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

int MOD = 1;
barrett_reduction barrett(1);
using barrett_int = _b_int<MOD, barrett>;


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q;
    cin >> N >> Q >> MOD;
    barrett = barrett_reduction(MOD);
    vector<barrett_int> A(N);

    for (auto &a : A)
        cin >> a;

    for (int i = 0; i < N; i++) {
        barrett_int b;
        cin >> b;
        A[i] -= b;
    }

    vector<barrett_int> D(N);
    int zero_count = 0;

    for (int i = 0; i < N; i++) {
        D[i] = A[i];

        if (i >= 1)
            D[i] -= A[i - 1];

        if (i >= 2)
            D[i] -= A[i - 2];

        zero_count += D[i] == 0;
    }

    vector<barrett_int> F = {1, 1};
    F.resize(N);

    for (int i = 2; i < N; i++)
        F[i] = F[i - 1] + F[i - 2];

    auto add = [&](int index, barrett_int change) -> void {
        zero_count -= D[index] == 0;
        D[index] += change;
        zero_count += D[index] == 0;
    };

    for (int q = 0; q < Q; q++) {
        char c;
        int L, R;
        cin >> c >> L >> R;
        L--;
        int sign = c == 'A' ? +1 : -1;
        add(L, sign * F[0]);

        // if (L + 1 < R)
        //     add(L + 1, sign * (F[1] - F[0]));

        if (R < N)
            add(R, sign * (-F[R - L]));

        if (R + 1 < N)
            add(R + 1, sign * (-F[R - L - 1]));

        cout << (zero_count == N ? "YES" : "NO") << '\n';
    }
}