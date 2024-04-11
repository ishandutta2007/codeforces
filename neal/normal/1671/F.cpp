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
#include <unordered_map>
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
template<typename T>
struct lagrange {
    int n, offset;
    vector<T> values;

    lagrange(const vector<T> &_values = {}, int _offset = 0) {
        init(_values, _offset);
    }

    void init(const vector<T> &_values, int _offset = 0) {
        values = _values;
        n = int(values.size());
        offset = _offset;
    }

    T interpolate(T x) {
        x -= offset;

        if (0 <= x && x < n && x == int(x))
            return values[int(x)];

        T result = 0, product = 1;

        // for (int i = 0; i < n; i++) {
        //     T product = values[i];

        //     for (int j = 0; j < n; j++)
        //         if (i != j)
        //             product *= T(x - j) / (i - j);

        //     result += product;
        // }

        for (int i = 1; i < n; i++)
            product *= T(x - i) / (-i);

        for (int i = 0; i < n; i++) {
            result += product * values[i];

            if (i < n - 1) {
                product *= T(x - i) / (x - (i + 1));
                product *= T(i + 1 - n) / (i + 1);
            }
        }

        return result;
    }
};


const int KX_MAX = 11;
const int N_MAX = 3 * KX_MAX;

lagrange<mod_int> solver[KX_MAX + 1][KX_MAX + 1];
vector<mod_int> kx_values[KX_MAX + 1][KX_MAX + 1];

unordered_map<int64_t, mod_int> dp[N_MAX + 1][KX_MAX + 1][KX_MAX + 1][N_MAX];

mod_int recurse(int n, int64_t mask, int inversions, int consecutive, int previous) {
    if (inversions < 0 || consecutive < 0 || consecutive > inversions)
        return 0;

    if (mask == (1LL << n) - 1)
        return inversions == 0 && consecutive == 0;

    int minimum_inversions = 0;

    for (int x = 0; mask >> x; x++)
        if ((mask >> x & 1) == 0) {
            minimum_inversions += __builtin_popcountll(mask >> x);

            if (minimum_inversions > inversions)
                return 0;
        }

    while (previous > 0 && (mask >> (previous - 1) & 1))
        previous--;

    auto &dp_map = dp[n][inversions][consecutive][previous];

    if (dp_map.find(mask) != dp_map.end())
        return dp_map[mask];

    mod_int ans = 0;

    for (int x = 0; x < n; x++)
        if ((mask >> x & 1) == 0) {
            int new_inversions = __builtin_popcountll(mask >> x);
            int new_consecutive = x < previous;
            ans += recurse(n, mask | 1LL << x, inversions - new_inversions, consecutive - new_consecutive, x);
        }

    return dp_map[mask] = ans;
}

mod_int solve(int n, int k, int x) {
    return recurse(n, 0, k, x, 0);
}

void precompute() {
    for (int k = 1; k <= KX_MAX; k++)
        for (int x = 1; x <= KX_MAX; x++) {
            kx_values[k][x] = {};

            for (int n = 0; n <= N_MAX; n++)
                kx_values[k][x].push_back(solve(n, k, x));

            vector<mod_int> truncated(kx_values[k][x].begin() + k + x, kx_values[k][x].end());
            solver[k][x].init(truncated, k + x);

            if (k >= x)
                assert(kx_values[k][x][k + x] != 0);
        }
}

void run_case() {
    int n, k, x;
    cin >> n >> k >> x;

    if (n < k + x)
        cout << kx_values[k][x][n] << '\n';
    else
        cout << solver[k][x].interpolate(n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    precompute();

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}