#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


// This is noticeably faster than using std::complex for some reason.
template<typename float_t>
struct complex {
    float_t x, y;

    complex<float_t>(float_t _x = 0, float_t _y = 0) : x(_x), y(_y) {}

    float_t real() const {
        return x;
    }

    void real(float_t _x) {
        x = _x;
    }

    float_t imag() const {
        return y;
    }

    void imag(float_t _y) {
        y = _y;
    }

    complex<float_t>& operator+=(const complex<float_t> &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    complex<float_t>& operator-=(const complex<float_t> &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    complex<float_t> operator+(const complex<float_t> &other) const {
        return complex<float_t>(*this) += other;
    }

    complex<float_t> operator-(const complex<float_t> &other) const {
        return complex<float_t>(*this) -= other;
    }

    complex<float_t> operator*(const complex<float_t> &other) const {
        return {x * other.x - y * other.y, x * other.y + other.x * y};
    }
};

template<typename float_t>
complex<float_t> conj(const complex<float_t> &c) {
    return {c.x, -c.y};
}

template<typename float_t>
complex<float_t> polar(float_t magnitude, float_t angle) {
    return {magnitude * cos(angle), magnitude * sin(angle)};
}

template<typename float_t>
ostream& operator<<(ostream &stream, const complex<float_t> &c) {
    return stream << '(' << c.x << ", " << c.y << ')';
}


namespace FFT {
    typedef double float_t;
    const float_t ONE = 1;
    const float_t PI = acos(-ONE);

    vector<complex<float_t>> roots;
    vector<int> bit_reverse;

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
    template<typename complex_array>
    void bit_reorder(int n, complex_array &&values) {
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

    void prepare_roots(int n) {
        if ((int) roots.size() >= n)
            return;

        if (roots.empty())
            roots = {{0, 0}, {1, 0}};

        int length = get_length(roots.size());
        roots.resize(n);

        // The roots array is set up such that for a given power of two n >= 2, roots[n / 2] through roots[n - 1] are
        // the first half of the n-th roots of unity.
        while (1 << length < n) {
            double min_angle = 2 * PI / (1 << (length + 1));

            for (int i = 0; i < 1 << (length - 1); i++) {
                int index = (1 << (length - 1)) + i;
                roots[2 * index] = roots[index];
                roots[2 * index + 1] = polar(ONE, min_angle * (2 * i + 1));
            }

            length++;
        }
    }

    template<typename complex_array>
    void fft_recursive(int n, complex_array &&values, int depth = 0) {
        if (n <= 1)
            return;

        if (depth == 0) {
            assert(is_power_of_two(n));
            prepare_roots(n);
            bit_reorder(n, values);
        }

        n /= 2;
        fft_recursive(n, values, depth + 1);
        fft_recursive(n, values + n, depth + 1);

        for (int i = 0; i < n; i++) {
            const complex<float_t> &even = values[i];
            complex<float_t> odd = values[n + i] * roots[n + i];
            values[n + i] = even - odd;
            values[i] = even + odd;
        }
    }

    // Iterative version of fft_recursive above.
    template<typename complex_array>
    void fft_iterative(int N, complex_array &&values) {
        assert(is_power_of_two(N));
        prepare_roots(N);
        bit_reorder(N, values);

        for (int n = 1; n < N; n *= 2)
            for (int start = 0; start < N; start += 2 * n)
                for (int i = 0; i < n; i++) {
                    const complex<float_t> &even = values[start + i];
                    complex<float_t> odd = values[start + n + i] * roots[n + i];
                    values[start + n + i] = even - odd;
                    values[start + i] = even + odd;
                }
    }

    inline complex<float_t> extract(int N, const vector<complex<float_t>> &values, int index, int side) {
        if (side == -1) {
            // Return the product of 0 and 1.
            int other = (N - index) & (N - 1);
            return (conj(values[other] * values[other]) - values[index] * values[index]) * complex<float_t>(0, 0.25);
        }

        int other = (N - index) & (N - 1);
        int sign = side == 0 ? +1 : -1;
        complex<float_t> multiplier = side == 0 ? complex<float_t>(0.5, 0) : complex<float_t>(0, -0.5);
        return multiplier * complex<float_t>(values[index].real() + values[other].real() * sign,
                                             values[index].imag() - values[other].imag() * sign);
    }

    void invert_fft(int N, vector<complex<float_t>> &values) {
        assert(N >= 2);

        for (int i = 0; i < N; i++)
            values[i] = conj(values[i]) * (ONE / N);

        for (int i = 0; i < N / 2; i++) {
            complex<float_t> first = values[i] + values[N / 2 + i];
            complex<float_t> second = (values[i] - values[N / 2 + i]) * roots[N / 2 + i];
            values[i] = first + second * complex<float_t>(0, 1);
        }

        fft_recursive(N / 2, values.begin());

        for (int i = N - 1; i >= 0; i--)
            values[i] = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
    }

    const int FFT_CUTOFF = 150;
    const double SPLIT_CUTOFF = 2e15;
    const int SPLIT_BASE = 1 << 15;

    template<typename T_out, typename T_in>
    vector<T_out> square(const vector<T_in> &input) {
        int n = input.size();

#ifdef NEAL
        // Sanity check to make sure I'm not forgetting to split.
        double max_value = *max_element(input.begin(), input.end());
        assert(n * max_value * max_value < SPLIT_CUTOFF);
#endif

        // Brute force when n is small enough.
        if (n < 1.5 * FFT_CUTOFF) {
            vector<T_out> result(2 * n - 1);

            for (int i = 0; i < n; i++) {
                result[2 * i] += (T_out) input[i] * input[i];

                for (int j = i + 1; j < n; j++)
                    result[i + j] += (T_out) 2 * input[i] * input[j];
            }

            return result;
        }

        int N = round_up_power_two(n);
        assert(N >= 2);
        prepare_roots(2 * N);
        vector<complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i += 2)
            values[i / 2] = complex<float_t>(input[i], i + 1 < n ? input[i + 1] : 0);

        fft_iterative(N, values.begin());

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

        fft_recursive(N, values.begin());
        vector<T_out> result(2 * n - 1);

        for (int i = 0; i < (int) result.size(); i++) {
            float_t value = i % 2 == 0 ? values[i / 2].real() : values[i / 2].imag();
            result[i] = is_integral<T_out>::value ? round(value) : value;
        }

        return result;
    }

    template<typename T_out, typename T_in>
    vector<T_out> multiply(const vector<T_in> &left, const vector<T_in> &right) {
        if (left == right)
            return square<T_out>(left);

        int n = left.size();
        int m = right.size();

#ifdef NEAL
        // Sanity check to make sure I'm not forgetting to split.
        double max_left = *max_element(left.begin(), left.end());
        double max_right = *max_element(right.begin(), right.end());
        assert(max(n, m) * max_left * max_right < SPLIT_CUTOFF);
#endif

        // Brute force when either n or m is small enough.
        if (min(n, m) < FFT_CUTOFF) {
            vector<T_out> result(n + m - 1);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    result[i + j] += (T_out) left[i] * right[j];

            return result;
        }

        int N = round_up_power_two(n + m - 1);
        vector<complex<float_t>> values(N, 0);

        for (int i = 0; i < n; i++)
            values[i].real(left[i]);

        for (int i = 0; i < m; i++)
            values[i].imag(right[i]);

        fft_iterative(N, values.begin());

        for (int i = 0; i <= N / 2; i++) {
            int j = (N - i) & (N - 1);
            complex<float_t> product_i = extract(N, values, i, -1);
            values[i] = product_i;
            values[j] = conj(product_i);
        }

        invert_fft(N, values);
        vector<T_out> result(n + m - 1);

        for (int i = 0; i < (int) result.size(); i++)
            result[i] = is_integral<T_out>::value ? round(values[i].real()) : values[i].real();

        return result;
    }

    template<typename T>
    vector<T> mod_multiply(const vector<T> &left, const vector<T> &right, T mod, bool split = false) {
        int n = left.size();
        int m = right.size();

        for (int i = 0; i < n; i++)
            assert(0 <= left[i] && left[i] < mod);

        for (int i = 0; i < m; i++)
            assert(0 <= right[i] && right[i] < mod);

#ifdef NEAL
        // Sanity check to make sure I'm not forgetting to split.
        assert(split || (double) max(n, m) * mod * mod < SPLIT_CUTOFF);
#endif

        // Brute force when either n or m is small enough. Brute force up to higher values when split = true.
        if (min(n, m) < (split ? 2 : 1) * FFT_CUTOFF) {
            const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) mod * mod;
            vector<uint64_t> result(n + m - 1);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    result[i + j] += (uint64_t) left[i] * right[j];

                    if (result[i + j] > ULL_BOUND)
                        result[i + j] %= mod;
                }

            for (int i = 0; i < (int) result.size(); i++)
                if (result[i] >= (uint64_t) mod)
                    result[i] %= mod;

            return vector<T>(result.begin(), result.end());
        }

        if (!split) {
            const vector<uint64_t> &product = multiply<uint64_t>(left, right);
            vector<T> result(n + m - 1);

            for (int i = 0; i < (int) result.size(); i++)
                result[i] = product[i] % mod;

            return result;
        }

        int N = round_up_power_two(n + m - 1);
        vector<complex<float_t>> left_fft(N, 0), right_fft(N, 0);

        for (int i = 0; i < n; i++) {
            left_fft[i].real(left[i] % SPLIT_BASE);
            left_fft[i].imag(left[i] / SPLIT_BASE);
        }

        fft_iterative(N, left_fft.begin());

        if (left == right) {
            copy(left_fft.begin(), left_fft.end(), right_fft.begin());
        } else {
            for (int i = 0; i < m; i++) {
                right_fft[i].real(right[i] % SPLIT_BASE);
                right_fft[i].imag(right[i] / SPLIT_BASE);
            }

            fft_iterative(N, right_fft.begin());
        }

        vector<complex<float_t>> product(N);
        vector<T> result(n + m - 1);

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

            for (int i = 0; i < (int) result.size(); i++) {
                uint64_t value = round(product[i].real());
                result[i] = (result[i] + value % mod * multiplier) % mod;
            }
        }

        return result;
    }
}


#include <chrono>
#include <random>

struct bignum {
    static const int SECTION = 4;
    static const int BASE = pow(10, SECTION);
    static const int DOUBLE_DIV_SECTIONS = 5;

    static const int FFT_CUTOFF = 1500;
    static const int KARATSUBA_CUTOFF = 150;
    static const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) BASE * BASE;
    static const uint64_t BASE_OVERFLOW_CUTOFF = numeric_limits<uint64_t>::max() / BASE;

    typedef uint16_t value_t;

    vector<value_t> values;

    bignum(uint64_t x = 0) {
        init(x);
    }

    bignum(string str) {
        int len = str.length();
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

        for (int i = (int) values.size() - 1; i >= 0; i--)
            integer_value = BASE * integer_value + values[i];

        return integer_value;
    }

    void trim_check() {
        while (values.size() > 1 && values.back() == 0)
            values.pop_back();

        if (values.empty())
            values = {0};
    }

    void checked_add(unsigned position, value_t add) {
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

        while (result.length() > 1 && result.back() == '0')
            result.pop_back();

        reverse(result.begin(), result.end());
        return result;
    }

    int compare(const bignum &other) const {
        int n = values.size();
        int m = other.values.size();

        if (n != m)
            return n < m ? -1 : +1;

        for (int i = n - 1; i >= 0; i--)
            if (values[i] != other.values[i])
                return values[i] < other.values[i] ? -1 : +1;

        return 0;
    }

    bool operator<(const bignum &other) const {
        return compare(other) < 0;
    }

    bool operator>(const bignum &other) const {
        return compare(other) > 0;
    }

    bool operator<=(const bignum &other) const {
        return compare(other) <= 0;
    }

    bool operator>=(const bignum &other) const {
        return compare(other) >= 0;
    }

    bool operator==(const bignum &other) const {
        return compare(other) == 0;
    }

    bool operator!=(const bignum &other) const {
        return compare(other) != 0;
    }

    // Multiplies this number by BASE^p.
    bignum operator<<(int p) const {
        assert(p >= 0);
        int n = values.size();

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
        int n = values.size();

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
            b = values.size();

        assert(a <= b);
        bignum result;
        result.values.resize(b - a);

        for (int i = 0; i < b - a; i++)
            result.values[i] = values[i + a];

        result.trim_check();
        return result;
    }

    bignum& operator+=(const bignum &other) {
        int n = other.values.size();

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

    bignum operator+(const bignum &other) const {
        return bignum(*this) += other;
    }

    bignum& operator-=(const bignum &other) {
        assert(*this >= other);
        int n = other.values.size();

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

    bignum operator-(const bignum &other) const {
        return bignum(*this) -= other;
    }

    bignum operator*(const bignum &other) const {
        const bignum *a = this, *b = &other;
        int n = a->values.size();
        int m = b->values.size();

        if (n > m) {
            swap(a, b);
            swap(n, m);
        }

        if (n > KARATSUBA_CUTOFF && n + m > FFT_CUTOFF) {
            const vector<uint64_t> &multiplication = FFT::multiply<uint64_t>(a->values, b->values);
            int N = multiplication.size();
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
            const bignum &a1 = a->range(0, mid);
            const bignum &a2 = a->range(mid, n);
            const bignum &b1 = b->range(0, mid);
            const bignum &b2 = b->range(mid, m);

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
                value += (uint64_t) a->values[i] * b->values[index_sum - i];

                if (value > ULL_BOUND) {
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

        int n = values.size();

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
        int n = values.size();
        int m = other.values.size();
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

        int n = values.size();
        int m = other.values.size();
        bignum quotient = 0;
        bignum remainder = *this;

        for (int i = n - m; i >= 0; i--) {
            // This is possible due to remainder.trim_check() below.
            if (i >= (int) remainder.values.size())
                continue;

            bignum chunk = remainder.range(i);

            // Compute int(chunk / other) precisely.
            int div = chunk.estimate_div(other) + 1e-7;
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

    bignum operator/(const bignum &other) const {
        return div_mod(other).first;
    }

    bignum operator%(const bignum &other) const {
        return div_mod(other).second;
    }

    bignum& operator/=(const bignum &other) {
        return *this = *this / other;
    }

    bignum& operator%=(const bignum &other) {
        return *this = *this % other;
    }

    pair<bignum, uint64_t> div_mod(uint64_t denom) const {
        assert(denom > 0);

        // Make sure denom * BASE doesn't overflow.
        if (denom >= BASE_OVERFLOW_CUTOFF) {
            pair<bignum, bignum> p = div_mod(bignum(denom));
            return make_pair(p.first, (uint64_t) p.second);
        }

        int n = values.size();
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
            return (uint64_t) div_mod(bignum(denom)).second;

        int n = values.size();
        uint64_t remainder = 0;

        for (int i = n - 1; i >= 0; i--) {
            remainder = BASE * remainder + values[i];

            if (remainder >= BASE_OVERFLOW_CUTOFF)
                remainder %= denom;
        }

        remainder %= denom;
        return remainder;
    }

    bignum& operator/=(uint64_t denom) {
        return *this = *this / denom;
    }

    bignum& operator%=(uint64_t denom) {
        return *this = *this % denom;
    }

    bignum power(unsigned exponent) const {
        bignum result = 1;

        for (int k = 31; k >= 0; k--) {
            result *= result;

            if (exponent & 1U << k)
                result *= *this;
        }

        return result;
    }

    static bignum mod_pow(bignum a, bignum b, const bignum &mod) {
        vector<bool> bits;

        while (b != 0) {
            bits.push_back(b % 2);
            b /= 2;
        }

        int n = bits.size();
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

        static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));
        uint64_t a_max = n < bignum(UINT64_MAX) + 2 ? (uint64_t) n - 2 : UINT64_MAX;
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;
    int threes = (log10(input[0] - '0') + input.length() - 1) / log10(3);
    bignum value = bignum(3).power(threes);
    bignum number = input;

    while (value < number) {
        value *= 3;
        threes++;
    }

    int answer = 3 * threes;

    for (int twos = 1; twos <= 2; twos++) {
        value /= 3;
        value += value;
        threes--;

        if (value >= number)
            answer = min(answer, 3 * threes + 2 * twos);
    }

    cout << max(answer, 1) << '\n';
    return 0;
}