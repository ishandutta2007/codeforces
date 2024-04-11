#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<const int64_t &MOD>
struct _m_int {
    int64_t val;

    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

    static int64_t inv_mod(int64_t a, int64_t m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int64_t g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int64_t q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const { return val; }
    explicit operator int64_t() const { return val; }

    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static uint64_t fast_mod(uint64_t x, uint64_t m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    _m_int& operator*=(const _m_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }

    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }

    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }

    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const _m_int &other) const { return val == other.val; }
    bool operator!=(const _m_int &other) const { return val != other.val; }

    _m_int inv() const {
        return inv_mod(val);
    }

    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _m_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};

int64_t EVEN_MOD = 1 << 20;
using even_int = _m_int<EVEN_MOD>;

int64_t ODD_MOD = EVEN_MOD + 1;
using odd_int = _m_int<ODD_MOD>;

// https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
namespace walsh_hadamard {
    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }

    int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return max(n, 1);
    }

    template<typename T>
    typename enable_if<is_integral<T>::value>::type divide_all(int n, vector<T> &values) {
        for (int i = 0; i < n; i++)
            values[i] >>= __builtin_ctz(n);
    }

    template<typename T>
    typename enable_if<!is_integral<T>::value>::type divide_all(int n, vector<T> &values) {
        T inv_n = T(1) / n;

        for (int i = 0; i < n; i++)
            values[i] *= inv_n;
    }

    template<typename T>
    void fwht_xor(int n, vector<T> &values, bool inverse = false) {
        assert(is_power_of_two(n));
        assert((int) values.size() >= n);

        for (int len = 1; len < n; len *= 2)
            for (int start = 0; start < n; start += 2 * len)
                for (int i = start; i < start + len; i++) {
                    T u = values[i];
                    const T &v = values[i + len];
                    values[i] = u + v;
                    values[i + len] = u - v;
                }

        if (inverse)
            divide_all(n, values);
    }

    // Warning: make sure to select the type `T_out` so that it can contain N^2 * max(left) * max(right).
    // One option is to use doubles and round at the end, since we are simply dividing by a power of two to finish.
    template<typename T_out, typename T_in>
    vector<T_out> xor_convolution(const vector<T_in> &_left, const vector<T_in> &_right) {
        if (_left.empty() || _right.empty())
            return {};

        vector<T_out> left(_left.begin(), _left.end());
        vector<T_out> right(_right.begin(), _right.end());

        int n = left.size();
        int m = right.size();

        int N = round_up_power_two(max(n, m));
        left.resize(N, 0);
        right.resize(N, 0);

        if (left == right) {
            fwht_xor(N, left);
            right = left;
        } else {
            fwht_xor(N, left);
            fwht_xor(N, right);
        }

        for (int i = 0; i < N; i++)
            left[i] *= right[i];

        fwht_xor(N, left, true);
        return left;
    }
}

int64_t inv_mod(int64_t a, int64_t m) {
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    int64_t g = m, r = a, x = 0, y = 1;

    while (r != 0) {
        int64_t q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }

    assert(g == 1);
    assert(y == m || y == -m);
    return x < 0 ? x + m : x;
}

// Returns a number that is a1 mod m1 and a2 mod m2. Assumes m1 and m2 are relatively prime.
int64_t chinese_remainder_theorem(int64_t a1, int64_t m1, int64_t a2, int64_t m2) {
    // assert(__gcd(m1, m2) == 1);
    int64_t k = (a2 - a1) % m2 * inv_mod(m1, m2) % m2;
    int64_t result = a1 + k * m1;

    if (result < 0)
        result += m1 * m2;

    assert(0 <= result && result < m1 * m2);
    assert(result % m1 == a1 && result % m2 == a2);
    return result;
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    int64_t T;
    cin >> M >> T >> ODD_MOD;
    N = 1 << M;
    EVEN_MOD = N;

    while (ODD_MOD % 2 == 0) {
        ODD_MOD /= 2;
        EVEN_MOD *= 2;
    }

    vector<even_int> E_even(N);
    vector<odd_int> E_odd(N);

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        E_even[i] = e;
        E_odd[i] = e;
    }

    vector<int> B(M + 1);

    for (int i = 0; i <= M; i++)
        cin >> B[i];

    vector<even_int> transition_even(N, 0);
    vector<odd_int> transition_odd(N, 0);

    for (int i = 0; i < N; i++) {
        transition_even[i] = B[__builtin_popcount(i)];
        transition_odd[i] = B[__builtin_popcount(i)];
    }

    walsh_hadamard::fwht_xor(N, E_even);
    walsh_hadamard::fwht_xor(N, E_odd);
    walsh_hadamard::fwht_xor(N, transition_even);
    walsh_hadamard::fwht_xor(N, transition_odd);

    for (int i = 0; i < N; i++) {
        E_even[i] *= transition_even[i].pow(T);
        E_odd[i] *= transition_odd[i].pow(T);
    }

    walsh_hadamard::fwht_xor(N, E_even);
    walsh_hadamard::fwht_xor(N, E_odd, true);

    dbg(EVEN_MOD, ODD_MOD);

    for (int i = 0; i < N; i++) {
        assert(E_even[i].val % N == 0);
        dbg(i, E_even[i], E_odd[i]);
        E_even[i].val /= N;
        dbg(i, E_even[i], E_odd[i]);
        int64_t answer = chinese_remainder_theorem(E_even[i].val, EVEN_MOD / N, E_odd[i].val, ODD_MOD);
        cout << answer << '\n';
    }
}