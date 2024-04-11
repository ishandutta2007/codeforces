#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

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
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }

        if (number != 0 || length == 0)
            write_char(number + '0');

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
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}

const int MOD = 998244353;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;

        if (v >= MOD)
            v %= MOD;

        val = v;
    }

    static int mod_inv(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const {
        return val;
    }

    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mod_int& operator-=(const mod_int &other) {
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

    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }

    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }

    mod_int inv() const {
        return mod_inv(val);
    }

    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};

vector<mod_int> inv, factorial, inv_factorial;

void prepare_factorials(int maximum) {
    inv.assign(maximum + 1, 1);

    // Make sure MOD is prime, which is necessary for the inverse algorithm below.
    for (int p = 2; p * p <= MOD; p++)
        assert(MOD % p != 0);

    for (int i = 2; i <= maximum; i++)
        inv[i] = inv[MOD % i] * (MOD - MOD / i);

    factorial.resize(maximum + 1);
    inv_factorial.resize(maximum + 1);
    factorial[0] = inv_factorial[0] = 1;

    for (int i = 1; i <= maximum; i++) {
        factorial[i] = i * factorial[i - 1];
        inv_factorial[i] = inv[i] * inv_factorial[i - 1];
    }
}

mod_int choose(long long n, long long r) {
    if (r < 0 || r > n)
        return 0;

    return factorial[n] * inv_factorial[r] * inv_factorial[n - r];
}

mod_int inv_choose(long long n, long long r) {
    assert(0 <= r && r <= n);
    return inv_factorial[n] * factorial[r] * factorial[n - r];
}

mod_int permute(long long n, long long k) {
    if (k < 0 || k > n)
        return 0;

    return factorial[n] * inv_factorial[n - k];
}

mod_int inv_permute(long long n, long long k) {
    assert(0 <= k && k <= n);
    return inv_factorial[n] * factorial[n - k];
}

namespace NTT {
    vector<mod_int> roots = {0, 1};
    vector<int> bit_reverse;
    int max_size = -1;
    mod_int root;

    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }

    int round_up_power_two(int n) {
        assert(n > 0);

        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return n;
    }

    // Given n (a power of two), finds k such that n == 1 << k.
    int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }

    // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
    // This makes even-odd div-conquer much easier.
    void bit_reorder(int n, vector<mod_int> &values) {
        if ((int) bit_reverse.size() != n) {
            bit_reverse.assign(n, 0);
            int length = get_length(n);

            for (int i = 0; i < n; i++)
                bit_reverse[i] = (bit_reverse[i >> 1] >> 1) + ((i & 1) << (length - 1));
        }

        for (int i = 0; i < n; i++)
            if (i < bit_reverse[i])
                swap(values[i], values[bit_reverse[i]]);
    }

    void find_root() {
        int order = MOD - 1;
        max_size = 1;

        while (order % 2 == 0) {
            order /= 2;
            max_size *= 2;
        }

        root = 2;

        // Find a max_size-th primitive root of MOD.
        while (!(root.pow(max_size) == 1 && root.pow(max_size / 2) != 1))
            root++;
    }

    void prepare_roots(int n) {
        if (max_size < 0)
            find_root();

        assert(n <= max_size);

        if ((int) roots.size() >= n)
            return;

        int length = get_length(roots.size());
        roots.resize(n);

        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th primitive roots of MOD.
        while (1 << length < n) {
            // z is a 2^(length + 1)-th primitive root of MOD.
            mod_int z = root.pow(max_size >> (length + 1));

            for (int i = 1 << (length - 1); i < 1 << length; i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * z;
            }

            length++;
        }
    }

    void fft_iterative(int N, vector<mod_int> &values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);

        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    mod_int even = values[start + i];
                    mod_int odd = values[start + n + i] * roots[n + i];
                    values[start + n + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }

    const int FFT_CUTOFF = 150;

    vector<mod_int> mod_multiply(vector<mod_int> left, vector<mod_int> right) {
        int n = left.size();
        int m = right.size();

        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;
            vector<uint64_t> result(n + m - 1);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) ((int) left[i]) * ((int) right[j]);

                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= MOD;
                }

            for (uint64_t &x : result)
                if (x >= MOD)
                    x %= MOD;

            return vector<mod_int>(result.begin(), result.end());
        }

        int N = round_up_power_two(n + m - 1);
        left.resize(N);
        right.resize(N);

        bool equal = left == right;
        fft_iterative(N, left);

        if (equal)
            right = left;
        else
            fft_iterative(N, right);

        mod_int inv_N = mod_int(N).inv();

        for (int i = 0; i < N; i++)
            left[i] *= right[i] * inv_N;

        reverse(left.begin() + 1, left.end());
        fft_iterative(N, left);
        left.resize(n + m - 1);
        return left;
    }

    vector<mod_int> mod_power(const vector<mod_int> &v, int exponent) {
        assert(exponent >= 0);
        vector<mod_int> result = {1};

        if (exponent == 0)
            return result;

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result);

            if (exponent >> k & 1)
                result = mod_multiply(result, v);
        }

        return result;
    }
}


void add(vector<mod_int> &answers, const vector<mod_int> &product, size_t offset) {
    answers.resize(max(answers.size(), product.size() + offset), 0);

    for (size_t i = 0; i < product.size(); i++)
        answers[offset + i] += product[i];
}

int main() {
    IO::init();

    int N, K;
    IO::read_int(N, K);
    prepare_factorials(N);
    vector<int> A(N), B(K);

    for (auto &a : A)
        IO::read_int(a);

    for (auto &b : B)
        IO::read_int(b);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<mod_int> single_poly, double_poly;
    vector<mod_int> answers, product = {1};

    for (int k = 0, current = 0; k < K; k++) {
        int single_count = 0, double_count = 0;

        while (current < N && A[current] < B[k]) {
            int end = current;

            while (end < N && A[current] == A[end])
                end++;

            if (end - current == 1)
                single_count++;
            else
                double_count += 2;

            current = end;
        }

        single_poly.resize(single_count + 1);
        double_poly.resize(double_count + 1);
        mod_int pow2 = 1;

        for (int i = 0; i <= single_count; i++) {
            single_poly[i] = choose(single_count, i) * pow2;
            pow2 += pow2;
        }

        for (int i = 0; i <= double_count; i++)
            double_poly[i] = choose(double_count, i);

        product = NTT::mod_multiply(product, NTT::mod_multiply(single_poly, double_poly));
        add(answers, product, B[k] + 1);
    }

    int Q;
    IO::read_int(Q);

    for (int q = 0; q < Q; q++) {
        int perimeter;
        IO::read_int(perimeter);
        int goal = perimeter / 2;
        mod_int answer = goal < (int) answers.size() ? answers[goal] : 0;
        IO::write_int((int) answer, '\n');
    }
}