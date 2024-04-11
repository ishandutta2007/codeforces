#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

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

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
}

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

extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;


const int BITS = 53;

template<typename T>
struct xor_basis {
    // A list of basis values sorted in decreasing order, where each value has a unique highest bit.
    // We use a static array instead of a vector for better performance.
    T basis[BITS];
    int n = 0;

    T min_value(T start) const {
        if (n == BITS)
            return 0;

        for (int i = 0; i < n; i++)
            start = min(start, start ^ basis[i]);

        return start;
    }

    T max_value(T start = 0) const {
        if (n == BITS)
            return ((T) 1 << BITS) - 1;

        for (int i = 0; i < n; i++)
            start = max(start, start ^ basis[i]);

        return start;
    }

    bool add(T x) {
        x = min_value(x);

        if (x == 0)
            return false;

        basis[n++] = x;

        // Insertion sort.
        for (int k = n - 1; k > 0 && basis[k] > basis[k - 1]; k--)
            swap(basis[k], basis[k - 1]);

        return true;
    }

    void merge(const xor_basis<T> &other) {
        for (int i = 0; i < other.n && n < BITS; i++)
            add(other.basis[i]);
    }

    void merge(const xor_basis<T> &a, const xor_basis<T> &b) {
        if (a.n > b.n) {
            *this = a;
            merge(b);
        } else {
            *this = b;
            merge(a);
        }
    }
};


void row_reduce(vector<int64_t> &basis) {
    int B = basis.size();

    for (int i = 0; i < B; i++)
        for (int j = i + 1; j < B; j++)
            basis[i] = min(basis[i], basis[i] ^ basis[j]);
}

vector<int64_t> generate_all(vector<int64_t> basis, int M) {
    row_reduce(basis);
    int B = basis.size();
    vector<int64_t> change(B + 1, 0);
    int64_t prefix = 0;

    for (int i = 0; i < B; i++) {
        prefix ^= basis[i];
        change[i] = prefix;
    }

    change[B] = prefix;
    vector<int64_t> counts(M + 1, 0);
    int64_t value = 0;

    if (B < 8) {
        for (int mask = 0; mask < 1 << B; mask++) {
            counts[__builtin_popcountll(value)]++;
            value ^= change[__builtin_ctz(mask + 1)];
        }
    } else {
        static const int JUMP = 32;

        for (int mask = 0; mask < 1 << B; mask += JUMP) {
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[1];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[2];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[1];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[3];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[1];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[2];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[1];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[4];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[1];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[2];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[1];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[3];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[1];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[2];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[1];
            counts[__builtin_popcountll(value)]++; value ^= change[0];
            counts[__builtin_popcountll(value)]++; value ^= change[__builtin_ctz(mask + JUMP)];
        }
    }

    return counts;
}

vector<int64_t> build_orthogonal(vector<int64_t> basis, int M) {
    row_reduce(basis);
    int B = basis.size();
    vector<int> highest_bit(B, -1);
    vector<bool> bit_covered(M, false);

    for (int i = 0; i < B; i++) {
        highest_bit[i] = 63 - __builtin_clzll(basis[i]);
        bit_covered[highest_bit[i]] = true;
    }

    vector<int64_t> orthogonal;

    for (int bit = M - 1; bit >= 0; bit--)
        if (!bit_covered[bit]) {
            int64_t value = 1LL << bit;

            for (int i = 0; i < B; i++)
                value |= (basis[i] >> bit & 1) << highest_bit[i];

            orthogonal.push_back(value);
        }

    return orthogonal;
}

vector<int64_t> generate_from_orthogonal(vector<int64_t> basis, int M) {
    row_reduce(basis);
    int B = basis.size();
    vector<int64_t> orthogonal = build_orthogonal(basis, M);
    vector<int64_t> orthogonal_counts = generate_all(orthogonal, M);
    vector<int64_t> counts(M + 1, 0);

    vector<vector<int64_t>> choose(M + 1);

    for (int n = 0; n <= M; n++) {
        choose[n].resize(n + 1);
        choose[n][0] = choose[n][n] = 1;

        for (int r = 1; r < n; r++)
            choose[n][r] = choose[n - 1][r - 1] + choose[n - 1][r];
    }

    auto &&get_choose = [&](int n, int r) -> int64_t {
        if (r < 0 || r > n) return 0;
        return choose[n][r];
    };

    for (int c = 0; c <= M; c++) {
        vector<int64_t> w(M + 1, 0);

        for (int d = 0; d <= M; d++)
            for (int j = 0; j <= d; j++)
                w[d] += (j % 2 == 0 ? 1 : -1) * get_choose(d, j) * get_choose(M - d, c - j);

        for (int d = 0; d <= M; d++)
            counts[c] += orthogonal_counts[d] * w[d];

        assert((counts[c] & ((1LL << (M - B)) - 1)) == 0);
        counts[c] >>= M - B;
    }

    return counts;
}

int main() {
    int N, M;
    IO::read_int(N, M);
    xor_basis<int64_t> basis_obj;

    for (int i = 0; i < N; i++) {
        int64_t a;
        IO::read_int(a);
        basis_obj.add(a);
    }

    int B = basis_obj.n;
    vector<int64_t> basis(basis_obj.basis, basis_obj.basis + B);

    vector<int64_t> answers = B <= M / 2 ? generate_all(basis, M) : generate_from_orthogonal(basis, M);

    for (int i = 0; i <= M; i++) {
        mod_int answer = answers[i];
        answer *= mod_int(2).pow(N - B);
        cout << answer << (i < M ? ' ' : '\n');
    }
}