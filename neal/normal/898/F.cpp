#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
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

namespace FFT {
    // This is noticeably faster than std::complex for some reason.
    template<typename float_t>
    struct complex {
        float_t x, y;

        complex<float_t>(float_t _x = 0, float_t _y = 0) : x(_x), y(_y) {}

        float_t real() const { return x; }
        float_t imag() const { return y; }

        void real(float_t _x) { x = _x; }
        void imag(float_t _y) { y = _y; }

        complex<float_t>& operator+=(const complex<float_t> &other) { x += other.x; y += other.y; return *this; }
        complex<float_t>& operator-=(const complex<float_t> &other) { x -= other.x; y -= other.y; return *this; }

        complex<float_t> operator+(const complex<float_t> &other) const { return complex<float_t>(*this) += other; }
        complex<float_t> operator-(const complex<float_t> &other) const { return complex<float_t>(*this) -= other; }

        complex<float_t> operator*(const complex<float_t> &other) const {
            return {x * other.x - y * other.y, x * other.y + other.x * y};
        }

        complex<float_t> operator*(float_t mult) const {
            return {x * mult, y * mult};
        }

        friend complex<float_t> conj(const complex<float_t> &c) {
            return {c.x, -c.y};
        }

        friend ostream& operator<<(ostream &os, const complex<float_t> &c) {
            return os << '(' << c.x << ", " << c.y << ')';
        }
    };

    template<typename float_t>
    complex<float_t> polar(float_t magnitude, float_t angle) {
        return {magnitude * cos(angle), magnitude * sin(angle)};
    }

    using float_t = double;

    const float_t ONE = 1;
    const float_t PI = acos(-ONE);

    vector<complex<float_t>> roots = {{0, 0}, {1, 0}};
    vector<int> bit_reverse;

    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }

    int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return max(n, 1);
    }

    // Given n (a power of two), finds k such that n == 1 << k.
    int get_length(int n) {
        assert(is_power_of_two(n));
        return __builtin_ctz(n);
    }

    // Rearranges the indices to be sorted by lowest bit first, then second lowest, etc., rather than highest bit first.
    // This makes even-odd div-conquer much easier.
    void bit_reorder(int n, vector<complex<float_t>> &values) {
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

    void prepare_roots(int n) {
        if (int(roots.size()) >= n)
            return;

        int length = get_length(int(roots.size()));
        roots.resize(n);

        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th roots of unity.
        while (1 << length < n) {
            float_t min_angle = 2 * PI / (1 << (length + 1));

            for (int i = 0; i < 1 << (length - 1); i++) {
                int index = (1 << (length - 1)) + i;
                roots[2 * index] = roots[index];
                roots[2 * index + 1] = polar(ONE, min_angle * (2 * i + 1));
            }

            length++;
        }
    }

    void fft_iterative(int n, vector<complex<float_t>> &values) {
        assert(is_power_of_two(n));
        prepare_roots(n);
        bit_reorder(n, values);

        for (int len = 1; len < n; len *= 2)
            for (int start = 0; start < n; start += 2 * len)
                for (int i = 0; i < len; i++) {
                    const complex<float_t> &even = values[start + i];
                    complex<float_t> odd = values[start + len + i] * roots[len + i];
                    values[start + len + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }

    inline complex<float_t> extract(int n, const vector<complex<float_t>> &values, int index, int side) {
        if (side == -1) {
            // Return the product of 0 and 1.
            int other = (n - index) & (n - 1);
            return (conj(values[other] * values[other]) - values[index] * values[index]) * complex<float_t>(0, 0.25);
        }

        int other = (n - index) & (n - 1);
        int sign = side == 0 ? +1 : -1;
        complex<float_t> multiplier = side == 0 ? complex<float_t>(0.5, 0) : complex<float_t>(0, -0.5);
        return multiplier * complex<float_t>(values[index].real() + values[other].real() * sign,
                                             values[index].imag() - values[other].imag() * sign);
    }

    void invert_fft(int n, vector<complex<float_t>> &values) {
        assert(n >= 2);

        for (int i = 0; i < n; i++)
            values[i] = conj(values[i]) * (ONE / n);

        for (int i = 0; i < n / 2; i++) {
            complex<float_t> first = values[i] + values[n / 2 + i];
            complex<float_t> second = (values[i] - values[n / 2 + i]) * roots[n / 2 + i];
            values[i] = first + second * complex<float_t>(0, 1);
        }

        fft_iterative(n / 2, values);

        for (int i = n - 1; i >= 0; i--)
            values[i] = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
    }

    const int FFT_CUTOFF = 150;
    const double SPLIT_CUTOFF = 2e15;
    const int SPLIT_BASE = 1 << 15;

    template<typename T_out, typename T_in>
    vector<T_out> square(const vector<T_in> &input) {
        if (input.empty())
            return {};

        int n = int(input.size());

#ifdef NEAL
        // Sanity check to make sure I'm not forgetting to split.
        double max_value = *max_element(input.begin(), input.end());
        assert(n * max_value * max_value < SPLIT_CUTOFF);
#endif

        // Brute force when n is small enough.
        if (n < 1.5 * FFT_CUTOFF) {
            vector<T_out> result(2 * n - 1);

            for (int i = 0; i < n; i++) {
                result[2 * i] += T_out(input[i]) * input[i];

                for (int j = i + 1; j < n; j++)
                    result[i + j] += T_out(2) * input[i] * input[j];
            }

            return result;
        }

        int N = round_up_power_two(n);
        assert(N >= 2);
        prepare_roots(2 * N);
        vector<complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i += 2)
            values[i / 2] = complex<float_t>(input[i], i + 1 < n ? input[i + 1] : 0);

        fft_iterative(N, values);

        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            complex<float_t> even = extract(N, values, i, 0);
            complex<float_t> odd = extract(N, values, i, 1);
            complex<float_t> aux = even * even + odd * odd * roots[N + i] * roots[N + i];
            complex<float_t> tmp = even * odd;
            values[i] = aux - complex<float_t>(0, 2) * tmp;
            values[j] = conj(aux) - complex<float_t>(0, 2) * conj(tmp);
        }

        for (int i = 0; i < N; i++)
            values[i] = conj(values[i]) * (ONE / N);

        fft_iterative(N, values);
        vector<T_out> result(2 * n - 1);

        for (int i = 0; i < int(result.size()); i++) {
            float_t value = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
            result[i] = T_out(is_integral<T_out>::value ? round(value) : value);
        }

        return result;
    }

    // Note: `circular = true` can be used for a 2x speedup when only the `max(n, m) - min(n, m) + 1` fully overlapping
    // ranges are needed. It computes results using indices modulo the power-of-two FFT size; see the brute force below.
    template<typename T_out, typename T_in>
    vector<T_out> multiply(const vector<T_in> &left, const vector<T_in> &right, bool circular = false) {
        if (left.empty() || right.empty())
            return {};

        if (left == right && !circular)
            return square<T_out>(left);

        int n = int(left.size());
        int m = int(right.size());

#ifdef NEAL
        // Sanity check to make sure I'm not forgetting to split.
        double max_left = *max_element(left.begin(), left.end());
        double max_right = *max_element(right.begin(), right.end());
        assert(max(n, m) * max_left * max_right < SPLIT_CUTOFF);
#endif

        int output_size = circular ? round_up_power_two(max(n, m)) : n + m - 1;

        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            auto &&mod_output_size = [&](int x) {
                return x < output_size ? x : x - output_size;
            };

            vector<T_out> result(output_size, 0);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    result[mod_output_size(i + j)] += T_out(left[i]) * right[j];

            return result;
        }

        int N = round_up_power_two(output_size);
        vector<complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i++)
            values[i].real(left[i]);

        for (int i = 0; i < m; i++)
            values[i].imag(right[i]);

        fft_iterative(N, values);

        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            complex<float_t> product_i = extract(N, values, i, -1);
            values[i] = product_i;
            values[j] = conj(product_i);
        }

        invert_fft(N, values);
        vector<T_out> result(output_size, 0);

        for (int i = 0; i < output_size; i++)
            result[i] = T_out(is_integral<T_out>::value ? round(values[i].real()) : values[i].real());

        return result;
    }

    // Note: `circular = true` can be used for a 2x speedup when only the `max(n, m) - min(n, m) + 1` fully overlapping
    // ranges are needed. It computes results using indices modulo the power-of-two FFT size; see the brute force below.
    vector<int> mod_multiply(const vector<int> &left, const vector<int> &right, int mod, bool split, bool circular = false) {
        if (left.empty() || right.empty())
            return {};

        int n = int(left.size());
        int m = int(right.size());

        for (int i = 0; i < n; i++)
            assert(0 <= left[i] && left[i] < mod);

        for (int i = 0; i < m; i++)
            assert(0 <= right[i] && right[i] < mod);

#ifdef NEAL
        // Sanity check to make sure I'm not forgetting to split.
        assert(split || (double) max(n, m) * mod * mod < SPLIT_CUTOFF);
#endif

        int output_size = circular ? round_up_power_two(max(n, m)) : n + m - 1;

        // Brute force when either n or m is small enough. Brute force up to higher values when split = true.
        if (min(n, m) < (split ? 2 : 1) * FFT_CUTOFF) {
            auto &&mod_output_size = [&](int x) {
                return x < output_size ? x : x - output_size;
            };

            const uint64_t U64_BOUND = numeric_limits<uint64_t>::max() - uint64_t(mod) * mod;
            vector<uint64_t> result(output_size, 0);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    int index = mod_output_size(i + j);
                    result[index] += uint64_t(left[i]) * right[j];

                    if (result[index] > U64_BOUND)
                        result[index] %= mod;
                }

            for (uint64_t &x : result)
                if (x >= uint64_t(mod))
                    x %= mod;

            return vector<int>(result.begin(), result.end());
        }

        if (!split) {
            const vector<uint64_t> &product = multiply<uint64_t>(left, right, circular);
            vector<int> result(output_size, 0);

            for (int i = 0; i < output_size; i++)
                result[i] = int(product[i] % mod);

            return result;
        }

        int N = round_up_power_two(output_size);
        vector<complex<float_t>> left_fft(N, 0), right_fft(N, 0);

        for (int i = 0; i < n; i++) {
            left_fft[i].real(left[i] % SPLIT_BASE);
            left_fft[i].imag(left[i] / SPLIT_BASE);
        }

        fft_iterative(N, left_fft);

        if (left == right) {
            copy(left_fft.begin(), left_fft.end(), right_fft.begin());
        } else {
            for (int i = 0; i < m; i++) {
                right_fft[i].real(right[i] % SPLIT_BASE);
                right_fft[i].imag(right[i] / SPLIT_BASE);
            }

            fft_iterative(N, right_fft);
        }

        vector<complex<float_t>> product(N);
        vector<int> result(output_size, 0);

        for (int exponent = 0; exponent <= 2; exponent++) {
            uint64_t multiplier = 1;

            for (int k = 0; k < exponent; k++)
                multiplier = multiplier * SPLIT_BASE % mod;

            fill(product.begin(), product.end(), 0);

            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                    if (x + y == exponent)
                        for (int i = 0; i < N; i++)
                            product[i] += extract(N, left_fft, i, x) * extract(N, right_fft, i, y);

            invert_fft(N, product);

            for (int i = 0; i < output_size; i++) {
                uint64_t value = uint64_t(round(product[i].real()));
                result[i] = int((result[i] + value % mod * multiplier) % mod);
            }
        }

        return result;
    }

    vector<int> mod_power(const vector<int> &v, int exponent, int mod, bool split) {
        assert(exponent >= 0);
        vector<int> result = {1};

        if (exponent == 0)
            return result;

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result = mod_multiply(result, result, mod, split);

            if (exponent >> k & 1)
                result = mod_multiply(result, v, mod, split);
        }

        return result;
    }

    // Multiplies many polynomials whose total degree is n in O(n log^2 n).
    vector<int> mod_multiply_all(const vector<vector<int>> &polynomials, int mod, bool split) {
        if (polynomials.empty())
            return {1};

        struct compare_size {
            bool operator()(const vector<int> &x, const vector<int> &y) {
                return x.size() > y.size();
            }
        };

        priority_queue<vector<int>, vector<vector<int>>, compare_size> pq(polynomials.begin(), polynomials.end());

        while (pq.size() > 1) {
            vector<int> a = pq.top(); pq.pop();
            vector<int> b = pq.top(); pq.pop();
            pq.push(mod_multiply(a, b, mod, split));
        }

        return pq.top();
    }
}


#include <chrono>
#include <random>

struct bignum {
    static const int SECTION = 4;
    static const int BASE = pow(10, SECTION);
    static const int DOUBLE_DIV_SECTIONS = 5;

    static const int BIGNUM_FFT_CUTOFF = 1500;
    static const int KARATSUBA_CUTOFF = 150;
    static const uint64_t U64_BOUND = numeric_limits<uint64_t>::max() - uint64_t(BASE) * BASE;
    static const uint64_t BASE_OVERFLOW_CUTOFF = numeric_limits<uint64_t>::max() / BASE;

    using value_t = uint16_t;

    vector<value_t> values;

    bignum(uint64_t x = 0) {
        init(x);
    }

    bignum(string str) {
        int len = int(str.size());
        int num_values = max((len + SECTION - 1) / SECTION, 1);
        values.assign(num_values, 0);

        int counter = 0;
        int index = 0;
        value_t p10 = 1;

        for (int i = len - 1; i >= 0; i--) {
            assert('0' <= str[i] && str[i] <= '9');
            values[index] += p10 * (str[i] - '0');

            if (++counter >= SECTION) {
                counter = 0;
                index++;
                p10 = 1;
            } else {
                p10 *= 10;
            }
        }

        trim_check();
    }

    explicit operator uint64_t() const {
        uint64_t integer_value = 0;

        for (int i = int(values.size()) - 1; i >= 0; i--)
            integer_value = BASE * integer_value + values[i];

        return integer_value;
    }

    void trim_check() {
        while (values.size() > 1 && values.back() == 0)
            values.pop_back();

        if (values.empty())
            values = {0};
    }

    void checked_add(size_t position, value_t add) {
        if (position >= values.size())
            values.resize(position + 1, 0);

        values[position] += add;
    }

    void init(uint64_t x) {
        values.clear();

        do {
            checked_add(values.size(), x % BASE);
            x /= BASE;
        } while (x > 0);
    }

    string to_string() const {
        string result = "";

        for (value_t v : values)
            for (int i = 0; i < SECTION; i++) {
                result += v % 10 + '0';
                v /= 10;
            }

        while (result.size() > 1 && result.back() == '0')
            result.pop_back();

        reverse(result.begin(), result.end());
        return result;
    }

    int compare(const bignum &other) const {
        int n = int(values.size());
        int m = int(other.values.size());

        if (n != m)
            return n < m ? -1 : +1;

        for (int i = n - 1; i >= 0; i--)
            if (values[i] != other.values[i])
                return values[i] < other.values[i] ? -1 : +1;

        return 0;
    }

    bool operator<(const bignum &other) const { return compare(other) < 0; }
    bool operator>(const bignum &other) const { return compare(other) > 0; }
    bool operator<=(const bignum &other) const { return compare(other) <= 0; }
    bool operator>=(const bignum &other) const { return compare(other) >= 0; }
    bool operator==(const bignum &other) const { return compare(other) == 0; }
    bool operator!=(const bignum &other) const { return compare(other) != 0; }

    // Multiplies this number by BASE^p.
    bignum operator<<(int p) const {
        assert(p >= 0);
        int n = int(values.size());

        bignum result;
        result.values.resize(n + p, 0);

        for (int i = 0; i < n; i++)
            result.values[i + p] = values[i];

        result.trim_check();
        return result;
    }

    // Divides this number by BASE^p.
    bignum operator>>(int p) const {
        assert(p >= 0);
        int n = int(values.size());

        if (p >= n)
            return bignum(0);

        bignum result;
        result.values.resize(n - p);

        for (int i = 0; i < n - p; i++)
            result.values[i] = values[i + p];

        result.trim_check();
        return result;
    }

    // Returns the bignum represented by values[a, b).
    bignum range(int a, int b = -1) const {
        if (b == -1)
            b = int(values.size());

        assert(a <= b);
        bignum result;
        result.values.resize(b - a);

        for (int i = 0; i < b - a; i++)
            result.values[i] = values[i + a];

        result.trim_check();
        return result;
    }

    bignum& operator+=(const bignum &other) {
        int n = int(other.values.size());

        for (int i = 0, carry = 0; i < n || carry > 0; i++) {
            checked_add(i, (i < n ? other.values[i] : 0) + carry);

            if (values[i] >= BASE) {
                values[i] -= BASE;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        trim_check();
        return *this;
    }

    bignum& operator-=(const bignum &other) {
        assert(*this >= other);
        int n = int(other.values.size());

        for (int i = 0, carry = 0; i < n || carry > 0; i++) {
            unsigned subtract = (i < n ? other.values[i] : 0) + carry;

            if (values[i] < subtract) {
                values[i] += BASE - subtract;
                carry = 1;
            } else {
                values[i] -= subtract;
                carry = 0;
            }
        }

        trim_check();
        return *this;
    }

    friend bignum operator+(const bignum &a, const bignum &b) { return bignum(a) += b; }
    friend bignum operator-(const bignum &a, const bignum &b) { return bignum(a) -= b; }

    friend bignum operator*(const bignum &a, const bignum &b) {
        int n = int(a.values.size());
        int m = int(b.values.size());

        if (n > m)
            return b * a;

        if (n > KARATSUBA_CUTOFF && n + m > BIGNUM_FFT_CUTOFF) {
            const vector<uint64_t> &multiplication = FFT::multiply<uint64_t>(a.values, b.values);
            int N = int(multiplication.size());
            bignum product = 0;
            uint64_t carry = 0;

            for (int i = 0; i < N || carry > 0; i++) {
                uint64_t value = (i < N ? multiplication[i] : 0) + carry;
                carry = value / BASE;
                value %= BASE;
                product.checked_add(i, value);
            }

            product.trim_check();
            return product;
        }

        if (n > KARATSUBA_CUTOFF) {
            // Karatsuba algorithm.
            int mid = n / 2;
            const bignum &a1 = a.range(0, mid);
            const bignum &a2 = a.range(mid, n);
            const bignum &b1 = b.range(0, mid);
            const bignum &b2 = b.range(mid, m);

            const bignum &x = a2 * b2;
            const bignum &z = a1 * b1;
            const bignum &y = (a1 + a2) * (b1 + b2) - x - z;
            return (x << 2 * mid) + (y << mid) + z;
        }

        // Standard quadratic-time multiplication, optimized for minimal division.
        bignum product;
        product.values.resize(n + m - 1, 0);
        uint64_t value = 0, carry = 0;

        for (int index_sum = 0; index_sum < n + m - 1 || carry > 0; index_sum++) {
            value = carry % BASE;
            carry /= BASE;

            for (int i = max(0, index_sum - (m - 1)); i <= min(n - 1, index_sum); i++) {
                value += uint64_t(a.values[i]) * b.values[index_sum - i];

                if (value > U64_BOUND) {
                    carry += value / BASE;
                    value %= BASE;
                }
            }

            carry += value / BASE;
            value %= BASE;
            product.checked_add(index_sum, value);
        }

        product.trim_check();
        return product;
    }

    bignum& operator*=(const bignum &other) {
        return *this = *this * other;
    }

    bignum operator*(uint64_t mult) const {
        if (mult == 0)
            return 0;

        if (mult >= BASE_OVERFLOW_CUTOFF)
            return *this * bignum(mult);

        int n = int(values.size());

        bignum product;
        product.values.resize(n + 1, 0);
        uint64_t carry = 0;

        for (int i = 0; i < n || carry > 0; i++) {
            uint64_t value = mult * (i < n ? values[i] : 0) + carry;
            carry = value / BASE;
            value %= BASE;
            product.checked_add(i, value);
        }

        product.trim_check();
        return product;
    }

    bignum& operator*=(uint64_t mult) {
        return *this = *this * mult;
    }

    double estimate_div(const bignum &other) const {
        int n = int(values.size());
        int m = int(other.values.size());
        double estimate = 0, other_estimate = 0;
        int count = 0, other_count = 0;

        double p_base = 1;

        for (int i = n - 1; i >= 0 && count < DOUBLE_DIV_SECTIONS; i--) {
            estimate = estimate + p_base * values[i];
            p_base /= BASE;
            count++;
        }

        p_base = 1;

        for (int i = m - 1; i >= 0 && other_count < DOUBLE_DIV_SECTIONS; i--) {
            other_estimate = other_estimate + p_base * other.values[i];
            p_base /= BASE;
            other_count++;
        }

        return estimate / other_estimate * pow(BASE, n - m);
    }

    pair<bignum, bignum> div_mod(const bignum &other) const {
        assert(other > 0);

        int n = int(values.size());
        int m = int(other.values.size());
        bignum quotient = 0;
        bignum remainder = *this;

        for (int i = n - m; i >= 0; i--) {
            // This is possible due to remainder.trim_check() below.
            if (i >= int(remainder.values.size()))
                continue;

            bignum chunk = remainder.range(i);

            // Compute int(chunk / other) precisely.
            int div = int(chunk.estimate_div(other) + 1e-7);
            bignum mult = other * div;

            while (div > 0 && mult > chunk) {
                // cerr << "Decrementing " << div << " (" << i << ")" << '\n';;
                mult -= other;
                div--;
            }

            while (div < BASE - 1 && mult + other <= chunk) {
                // cerr << "Incrementing " << div << " (" << i << ")" << '\n';
                mult += other;
                div++;
            }

            remainder -= mult << i;
            remainder.trim_check();

            if (div > 0)
                quotient.checked_add(i, div);
        }

        quotient.trim_check();
        remainder.trim_check();
        return make_pair(quotient, remainder);
    }

    friend bignum operator/(const bignum &a, const bignum &b) { return a.div_mod(b).first; }
    friend bignum operator%(const bignum &a, const bignum &b) { return a.div_mod(b).second; }

    bignum& operator/=(const bignum &other) { return *this = *this / other; }
    bignum& operator%=(const bignum &other) { return *this = *this % other; }

    pair<bignum, uint64_t> div_mod(uint64_t denom) const {
        assert(denom > 0);

        // Make sure denom * BASE doesn't overflow.
        if (denom >= BASE_OVERFLOW_CUTOFF) {
            pair<bignum, bignum> p = div_mod(bignum(denom));
            return make_pair(p.first, uint64_t(p.second));
        }

        int n = int(values.size());
        bignum quotient = 0;
        uint64_t remainder = 0;

        for (int i = n - 1; i >= 0; i--) {
            remainder = BASE * remainder + values[i];

            if (remainder >= denom) {
                quotient.checked_add(i, remainder / denom);
                remainder %= denom;
            }
        }

        quotient.trim_check();
        return make_pair(quotient, remainder);
    }

    bignum operator/(uint64_t denom) const {
        return div_mod(denom).first;
    }

    uint64_t operator%(uint64_t denom) const {
        assert(denom > 0);

        if (BASE % denom == 0) {
            assert(!values.empty());
            return values[0] % denom;
        }

        // Make sure denom * BASE doesn't overflow.
        if (denom >= BASE_OVERFLOW_CUTOFF)
            return uint64_t(div_mod(bignum(denom)).second);

        int n = int(values.size());
        uint64_t remainder = 0;

        for (int i = n - 1; i >= 0; i--) {
            remainder = BASE * remainder + values[i];

            if (remainder >= BASE_OVERFLOW_CUTOFF)
                remainder %= denom;
        }

        remainder %= denom;
        return remainder;
    }

    bignum& operator/=(uint64_t denom) { return *this = *this / denom; }
    bignum& operator%=(uint64_t denom) { return *this = *this % denom; }

    bignum& operator++() { return *this += 1; }
    bignum& operator--() { return *this -= 1; }

    bignum operator++(int) { bignum before = *this; ++*this; return before; }
    bignum operator--(int) { bignum before = *this; --*this; return before; }

    bignum power(int exponent) const {
        assert(exponent >= 0);
        bignum result = 1;

        if (exponent == 0)
            return result;

        for (int k = 31 - __builtin_clz(exponent); k >= 0; k--) {
            result *= result;

            if (exponent >> k & 1)
                result *= *this;
        }

        return result;
    }

    friend ostream& operator<<(ostream &os, const bignum &x) {
        return os << x.to_string();
    }

    static bignum mod_pow(bignum a, bignum b, const bignum &mod) {
        vector<bool> bits;

        while (b != 0) {
            bits.push_back(b % 2);
            b /= 2;
        }

        int n = int(bits.size());
        int k = 1;

        while (2 * k << k < n)
            k++;

        vector<bignum> cached(1 << k);
        cached[0] = 1;
        cached[1] = a;

        for (int i = 2; i < 1 << k; i++)
            cached[i] = cached[i - 1] * a % mod;

        bignum result = 1;
        int power = 0;

        for (int i = n - 1; i >= 0; i--) {
            power = 2 * power + bits[i];
            result = result * result % mod;

            if (2 * power >= 1 << k || i == 0) {
                result = result * cached[power] % mod;
                power = 0;
            }
        }

        return result;
    }

    bool miller_rabin(int iterations = 20) const {
        const bignum &n = *this;

        if (n < 2)
            return false;

        static const uint64_t SMALL_PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        uint64_t product = 1;

        for (uint64_t p : SMALL_PRIMES) {
            if (n == p)
                return true;

            product *= p;
        }

        uint64_t remainder = n % product;

        for (uint64_t p : SMALL_PRIMES)
            if (remainder % p == 0)
                return false;

        int r = 0;
        bignum d = n - 1;

        while (d % 2 == 0) {
            r++;
            d /= 2;
        }

        auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
        static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
        uint64_t a_max = n < bignum(UINT64_MAX) + 2 ? uint64_t(n - 2) : UINT64_MAX;
        assert(n - 2 >= a_max);

        for (int k = 0; k < iterations; k++) {
            bignum a = uniform_int_distribution<uint64_t>(2, a_max)(rng);
            bignum x = mod_pow(a, d, n);

            if (x == 1 || x == n - 1)
                continue;

            bool witness = true;

            for (int i = 0; i < r - 1 && witness; i++) {
                x = x * x % n;

                if (x == n - 1)
                    witness = false;
            }

            if (witness)
                return false;
        }

        return true;
    }
};

template<const int &MOD>
struct _m_int {
    int val;

    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
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
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit unsigned int.
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

extern const int MOD = 2147482819;
using mod_int = _m_int<MOD>;


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    auto &&valid = [](const string &str) {
        if (str.empty())
            return false;

        return str.front() != '0' || str.size() == 1;
    };

    string S;
    cin >> S;
    int N = int(S.size());
    vector<mod_int> p10(N + 1, 1);

    for (int i = 0; i < N; i++)
        p10[i + 1] = 10 * p10[i];

    vector<mod_int> prefix_value(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_value[i + 1] = 10 * prefix_value[i] + (S[i] - '0');

    auto &&substring_value = [&](int start, int end) {
        return prefix_value[end] - prefix_value[start] * p10[end - start];
    };

    for (int equals = N - 1; equals > 0; equals--) {
        int len = N - equals;
        vector<int> options;

        for (int diff = -2; diff <= 2; diff++) {
            options.push_back(len + diff);
            options.push_back(equals - len + diff);
        }

        for (int plus : options)
            if (0 < plus && plus < equals && equals < N) {
                if (substring_value(0, plus) + substring_value(plus, equals) == substring_value(equals, N)) {
                    string a = S.substr(0, plus);
                    string b = S.substr(plus, equals - plus);
                    string c = S.substr(equals);

                    if (valid(a) && valid(b) && valid(c) && bignum(a) + bignum(b) == bignum(c)) {
                        cout << a << '+' << b << '=' << c << '\n';
                        return 0;
                    }
                }
            }
    }

    assert(false);
}