#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

template<const int &MOD>
struct _m_int {
    int val;

    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

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

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit unsigned int.
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
        bool first = true;

        while (p > 0) {
            if (p & 1) {
                result = first ? a : result * a;
                first = false;
            }

            p >>= 1;

            if (p > 0)
                a *= a;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};

extern const int MOD = 1e9 + 7;
using mod_int = _m_int<MOD>;


int main() {
    int64_t M;
    cin >> M;
    mod_int MM = M;
    mod_int coef[4] = {MM * (MM + 1) * (MM + 2), 3 * MM + 4, -(3 * MM + 6), 2};

    for (int d = 0; d < 4; d++)
        coef[d] /= 6;

    mod_int sum[4] = {0, 0, 0, 0};
    int64_t maximum = sqrt(M);

    for (int64_t x = 0; x <= maximum; x++) {
        mod_int mult = x == 0 ? 1 : 2;

        for (int d = 0; d < 4; d++)
            sum[d] += mult * mod_int(x * x).pow(d);
    }

    int64_t x_max = maximum;
    mod_int answer = 0;

    for (int64_t y = 0; y <= maximum; y++) {
        mod_int k = y == 0 ? 0 : 2 * y - 1;

        coef[0] = coef[3] * k.pow(3) + coef[2] * k.pow(2) + coef[1] * k + coef[0];
        coef[1] = 3 * coef[3] * k.pow(2) + 2 * coef[2] * k + coef[1];
        coef[2] = 3 * coef[3] * k + coef[2];
        coef[3] = coef[3];

        while (x_max >= 0 && x_max * x_max + y * y > M) {
            mod_int mult = x_max == 0 ? 1 : 2;

            for (int d = 0; d < 4; d++)
                sum[d] -= mult * mod_int(x_max * x_max).pow(d);

            x_max--;
        }

        mod_int mult = y == 0 ? 1 : 2;

        for (int d = 0; d < 4; d++)
            answer += mult * coef[d] * sum[d];
    }

    cout << answer << '\n';
}