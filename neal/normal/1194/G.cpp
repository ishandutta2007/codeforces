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

template<const int &MOD>
struct _m_int {
    int val;

    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

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
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
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

    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }

    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];

    static void prepare_inv() {
        // Ensures that MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    _m_int inv() const {
        if (save_inv[1] == 0)
            prepare_inv();

        if (val < SAVE_INV)
            return save_inv[val];

        _m_int product = 1;
        int v = val;

        do {
            product *= MOD - MOD / v;
            v = MOD % v;
        } while (v >= SAVE_INV);

        return product * save_inv[v];
    }

    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);

        _m_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

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

template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];

extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;

template<typename T_int>
T_int integer_pow(T_int a, int p) {
    T_int result = 1;

    while (p > 0) {
        if (p & 1)
            result *= a;

        p >>= 1;
        a *= a;
    }

    return result;
}


const int N_MAX = 100;
const int MASK_MAX = 81;
const int DIFF_MAX = 8;

mod_int dp[MASK_MAX + 1][N_MAX][3][2 * DIFF_MAX + 1];

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    string number;
    cin >> number;
    int N = int(number.size());
    mod_int equal = 0;

    for (auto &ch : number)
        equal = 10 * equal + (ch - '0');

    int x, y;
    int numers, denoms, nd;

    auto get_bit = [&](int mask, int val) -> int {
        if ((mask >> val & 1) == 0)
            return 0;

        return 1 << __builtin_popcount(mask & ((1 << val) - 1));
    };

    auto solve = y_combinator([&](auto self, int index, int diff, int n_mask, int d_mask, bool n_match, bool d_match) -> mod_int {
        if (index >= N)
            return diff == 0 && (n_mask & d_mask) != 0;

        if (abs(diff) > DIFF_MAX || (n_match && !d_match))
            return 0;

        int combined_mask = 0;

        if ((n_mask & d_mask) == 0) {
            for (int i = 0; i < nd; i++)
                combined_mask = 3 * combined_mask + (n_mask >> i & 1) + 2 * (d_mask >> i & 1);

            combined_mask++;
        }

        mod_int &ans = dp[combined_mask][index][n_match + d_match][diff + DIFF_MAX];

        if (ans.val >= 0)
            return ans;

        ans = 0;

        for (int n_digit = 0; n_digit <= 9; n_digit++) {
            if (n_match && n_digit > number[index] - '0')
                continue;

            for (int d_digit = 0; d_digit <= 9; d_digit++) {
                if (d_match && d_digit > number[index] - '0')
                    continue;

                int new_diff = 10 * diff + n_digit * y - d_digit * x;

                if (abs(new_diff) > DIFF_MAX)
                    continue;

                ans += self(index + 1, new_diff, n_mask | get_bit(numers, n_digit), d_mask | get_bit(denoms, d_digit),
                            n_match && n_digit == number[index] - '0', d_match && d_digit == number[index] - '0');
            }
        }

        return ans;
    });

    mod_int total = 0;

    for (x = 1; x <= 9; x++)
        for (y = x + 1; y <= 9; y++) {
            if (__gcd(x, y) != 1)
                continue;

            numers = denoms = 0;

            for (int k = 1; k * y <= 9; k++) {
                numers |= 1 << (k * x);
                denoms |= 1 << (k * y);
            }

            nd = __builtin_popcount(numers);

            for (int mask = 0; mask <= integer_pow(3, nd); mask++)
                memset(dp[mask], -1, sizeof(dp[mask]));

            total += solve(0, 0, 0, 0, true, true);
        }

    total = 2 * total + equal;
    cout << total << '\n';
}