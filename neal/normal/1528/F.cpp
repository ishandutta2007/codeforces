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
        // Make sure MOD is prime, which is necessary for the inverse algorithm below.
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

        while (v >= SAVE_INV) {
            product *= MOD - MOD / v;
            v = MOD % v;
        }

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


int highest_bit(int x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}

template<const int &MOD>
struct NTT {
    using ntt_int = _m_int<MOD>;

    vector<ntt_int> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    ntt_int root;

    void reset() {
        roots = {0, 1};
        max_size = -1;
    }

    static bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }

    static int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return max(n, 1);
    }

    // Given n (a power of two), finds k such that n == 1 << k.
    static int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }

    // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
    // This makes even-odd div-conquer much easier.
    void bit_reorder(int n, vector<ntt_int> &values) {
        if (int(bit_reverse.size()) != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);

            for (int i = 1; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) | ((i & 1) << (length - 1));
        }

        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }

    void find_root() {
        max_size = 1 << __builtin_ctz(MOD - 1);
        root = 2;

        // Find a max_size-th primitive root of MOD.
        while (!(root.pow(max_size) == 1 && root.pow(max_size / 2) != 1))
            root++;
    }

    void prepare_roots(int n) {
        if (max_size < 0)
            find_root();

        assert(n <= max_size);

        if (int(roots.size()) >= n)
            return;

        int length = get_length(int(roots.size()));
        roots.resize(n);

        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th primitive roots of MOD.
        while (1 << length < n) {
            // z is a 2^(length + 1)-th primitive root of MOD.
            ntt_int z = root.pow(max_size >> (length + 1));

            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * z;
            }

            length++;
        }
    }

    void fft_iterative(int n, vector<ntt_int> &values) {
        assert(is_power_of_two(n));
        prepare_roots(n);
        bit_reorder(n, values);

        for (int len = 1; len < n; len *= 2)
            for (int start = 0; start < n; start += 2 * len)
                for (int i = 0; i < len; i++) {
                    ntt_int even = values[start + i];
                    ntt_int odd = values[start + len + i] * roots[len + i];
                    values[start + len + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }

    void invert_fft(int n, vector<ntt_int> &values) {
        ntt_int inv_n = ntt_int(n).inv();

        for (int i = 0; i < n; i++)
            values[i] *= inv_n;

        reverse(values.begin() + 1, values.end());
        fft_iterative(n, values);
    }

    const int FFT_CUTOFF = 150;

    // Note: `circular = true` can be used for a 2x speedup when only the `max(n, m) - min(n, m) + 1` fully overlapping
    // ranges are needed. It computes results using indices modulo the power-of-two FFT size; see the brute force below.
    template<typename T>
    vector<T> mod_multiply(const vector<T> &_left, const vector<T> &_right, bool circular = false) {
        if (_left.empty() || _right.empty())
            return {};

        vector<ntt_int> left(_left.begin(), _left.end());
        vector<ntt_int> right(_right.begin(), _right.end());

        int n = int(left.size());
        int m = int(right.size());

        int output_size = circular ? round_up_power_two(max(n, m)) : n + m - 1;

        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            auto &&mod_output_size = [&](int x) {
                return x < output_size ? x : x - output_size;
            };

            static const uint64_t U64_BOUND = numeric_limits<uint64_t>::max() - uint64_t(MOD) * MOD;
            vector<uint64_t> result(output_size, 0);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    int index = mod_output_size(i + j);
                    result[index] += uint64_t(left[i]) * uint64_t(right[j]);

                    if (result[index] > U64_BOUND)
                        result[index] %= MOD;
                }

            for (uint64_t &x : result)
                if (x >= MOD)
                    x %= MOD;

            return vector<T>(result.begin(), result.end());
        }

        int N = round_up_power_two(output_size);
        left.resize(N, 0);
        right.resize(N, 0);

        if (left == right) {
            fft_iterative(N, left);
            right = left;
        } else {
            fft_iterative(N, left);
            fft_iterative(N, right);
        }

        for (int i = 0; i < N; i++)
            left[i] *= right[i];

        invert_fft(N, left);
        return vector<T>(left.begin(), left.begin() + output_size);
    }

    template<typename T>
    vector<T> mod_power(const vector<T> &v, int exponent) {
        assert(exponent >= 0);
        vector<T> result = {1};

        if (exponent == 0)
            return result;

        for (int k = highest_bit(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);

            if (exponent >> k & 1)
                result = mod_multiply(result, v);
        }

        return result;
    }

    // Multiplies many polynomials whose total degree is n in O(n log^2 n).
    template<typename T>
    vector<T> mod_multiply_all(const vector<vector<T>> &polynomials) {
        if (polynomials.empty())
            return {1};

        struct compare_size {
            bool operator()(const vector<T> &x, const vector<T> &y) {
                return x.size() > y.size();
            }
        };

        priority_queue<vector<T>, vector<vector<T>>, compare_size> pq(polynomials.begin(), polynomials.end());

        while (pq.size() > 1) {
            vector<T> a = pq.top(); pq.pop();
            vector<T> b = pq.top(); pq.pop();
            pq.push(mod_multiply(a, b));
        }

        return pq.top();
    }
};

NTT<MOD> ntt;


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, K;
    cin >> N >> K;
    vector<mod_int> poly1(K + 1), poly2(K + 1);
    mod_int inv_j_factorial = 1;

    for (int j = 0; j <= K; j++) {
        inv_j_factorial /= max(j, 1);
        poly1[j] = (j % 2 == 0 ? +1 : -1) * inv_j_factorial;
        poly2[j] = mod_int(j).pow(K) * inv_j_factorial;
    }

    // stirling_second[d] = S(K, d)
    vector<mod_int> stirling_second = ntt.mod_multiply(poly1, poly2);
    mod_int n_perm_d = 1;
    mod_int total = 0;

    for (int d = 1; d <= min(N, K); d++) {
        n_perm_d *= N - d + 1;
        total += n_perm_d * stirling_second[d] * mod_int(N + 1).pow(N - d);
    }

    cout << total << '\n';
}