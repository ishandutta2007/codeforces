#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
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
    size_t input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

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

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = char((lookup_value & 15) + '0');
            number_buffer[length++] = char((lookup_value >> 4) + '0');
        }

        if (number != 0 || length == 0)
            write_char(char(number + '0'));

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}

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

extern const int MOD = 998244353;
using mod_int = _m_int<MOD>;


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

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
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


const int L_MAX = 5e5 + 5;

int main() {
    IO::init();

    int N, X, Y;
    IO::read_int(N, X, Y);
    vector<mod_int> lines(X + 1, 0);

    for (int i = 0; i <= N; i++) {
        int a;
        IO::read_int(a);
        lines[a] = 1;
    }

    vector<mod_int> rev_lines = lines;
    reverse(rev_lines.begin(), rev_lines.end());
    vector<mod_int> product = ntt.mod_multiply(lines, rev_lines);
    vector<int> answers(L_MAX, -1);

    for (int f = Y + 1; f < L_MAX; f++)
        if (f - Y <= X && product[X + f - Y] != 0)
            for (int x = f; x < L_MAX; x += f)
                answers[x] = 2 * f;

    int Q;
    IO::read_int(Q);

    for (int q = 0; q < Q; q++) {
        int len;
        IO::read_int(len);
        len /= 2;
        IO::write_int(answers[len], q < Q - 1 ? ' ' : '\n');
    }
}