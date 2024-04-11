#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
static_assert(sizeof(int) == 4 && sizeof(long long) == 8);

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template <uint32_t mod>
struct modnum {
    // change these if you need another size of integers
    static constexpr inline uint32_t MOD = mod;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using i32 = int32_t;
    using i64 = int64_t;
    static_assert(mod > 0 && mod < UINT_MAX / 2);

    u32 n;

    constexpr modnum() : n(0) {}
    constexpr modnum(u64 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(u32 v) : n(v >= mod ? v % mod : v) {}
    constexpr modnum(i64 v) : modnum(v >= 0 ? u64(v) : u64(mod + v % int(mod))) {}
    constexpr modnum(i32 v) : modnum(v >= 0 ? u32(v) : u32(mod + v % int(mod))) {}
    explicit constexpr operator int() const { return n; }
    explicit constexpr operator bool() const { return n != 0; }

    static constexpr u32 fit(u32 x) { return x >= mod ? x - mod : x; }
    static constexpr int modinv(u32 x) {
        int nx = 1, ny = 0;
        u32 y = mod;
        while (x) {
            auto k = y / x;
            y = y % x;
            ny = ny - k * nx;
            swap(x, y), swap(nx, ny);
        }
        return ny < 0 ? mod + ny : ny;
    }
    friend constexpr modnum modpow(modnum b, int64_t e) {
        modnum p = 1;
        while (e > 0) {
            if (e & 1)
                p = p * b;
            if (e >>= 1)
                b = b * b;
        }
        return p;
    }

    constexpr modnum inv() const { return modinv(n); }
    constexpr modnum operator-() const { return n == 0 ? n : mod - n; }
    constexpr modnum operator+() const { return *this; }
    constexpr modnum operator++(int) { return n = fit(n + 1), *this - 1; }
    constexpr modnum operator--(int) { return n = fit(mod + n - 1), *this + 1; }
    constexpr modnum& operator++() { return n = fit(n + 1), *this; }
    constexpr modnum& operator--() { return n = fit(mod + n - 1), *this; }
    constexpr modnum& operator+=(modnum v) { return n = fit(n + v.n), *this; }
    constexpr modnum& operator-=(modnum v) { return n = fit(mod + n - v.n), *this; }
    constexpr modnum& operator*=(modnum v) { return n = (u64(n) * v.n) % mod, *this; }
    constexpr modnum& operator/=(modnum v) { return *this *= v.inv(); }

    friend constexpr modnum operator+(modnum lhs, modnum rhs) { return lhs += rhs; }
    friend constexpr modnum operator-(modnum lhs, modnum rhs) { return lhs -= rhs; }
    friend constexpr modnum operator*(modnum lhs, modnum rhs) { return lhs *= rhs; }
    friend constexpr modnum operator/(modnum lhs, modnum rhs) { return lhs /= rhs; }

    friend string to_string(modnum v) { return to_string(v.n); }
    friend constexpr bool operator==(modnum lhs, modnum rhs) { return lhs.n == rhs.n; }
    friend constexpr bool operator!=(modnum lhs, modnum rhs) { return lhs.n != rhs.n; }
    friend ostream& operator<<(ostream& out, modnum v) { return out << v.n; }
    friend istream& operator>>(istream& in, modnum& v) {
        i64 n;
        return in >> n, v = modnum(n), in;
    }
};

template <typename T>
struct Binomial {
    static T fac(int n) {
        ensure_factorial(n);
        return n < 0 ? 0 : fact[n];
    }

    static T invfac(int n) {
        ensure_factorial(n);
        return n < 0 ? 0 : ifact[n];
    }

    static T choose(int n, int k) {
        ensure_factorial(n);
        return n < 0 || k < 0 || k > n ? 0 : fact[n] * ifact[k] * ifact[n - k];
    }

    static T choose(const vector<int>& ks) {
        int n = 0;
        for (int k : ks) {
            n += k;
            if (k < 0) {
                return 0;
            }
        }
        ensure_factorial(n);
        T ans = fact[n];
        for (int k : ks) {
            ans *= ifact[k];
        }
        return ans;
    }

    static T multinomial(const vector<int>& ks) { return choose(ks); }

    static T rising(int n, int k) { // 1 for k=0
        ensure_factorial(n + k - 1);
        return n <= 0 || k < 0 ? 0 : fact[n + k - 1] * ifact[n - 1];
    }

    static T falling(int n, int k) { // 1 for k=0, same as arrange(n, k)
        ensure_factorial(n);
        return n < 0 || k < 0 || k > n ? 0 : fact[n] * ifact[n - k];
    }

    static T arrange(int n, int k) {
        ensure_factorial(n);
        return n < 0 || k < 0 || k > n ? 0 : fact[n] * ifact[n - k];
    }

    static T catalan(int n) {
        ensure_factorial(2 * n + 1);
        return n < 0 ? 0 : fact[2 * n] * ifact[n] * ifact[n + 1];
    }

    // {i1+...+ik=n}  catalan(ij)
    static T catalan_conv(int n, int k) {
        ensure_factorial(2 * n + k);
        return n < 0 || k < 1 ? 0 : choose(2 * n + k - 1, n) * k * inv(n + k);
    }

    // Chance of k successes in a binomial(n,p) (n events, success with probability p)
    static T binomial_success(int n, int k, T p) {
        return n < 0 || k < 0 ? 0 : choose(n, k) * binpow(p, k) * binpow(1 - p, n - k);
    }

    // ** Partitions of an integer

    static T binpow(T v, int64_t e) {
        T ans = 1;
        while (e > 0) {
            ans = (e & 1) ? v * ans : ans;
            v *= v, e >>= 1;
        }
        return ans;
    }

    static T inv(int n) { return n <= 0 ? 0 : fact[n - 1] * ifact[n]; }

    // * Cache
    static inline vector<T> fact = {1, 1};
    static inline vector<T> ifact = {1, 1};

    static void ensure_factorial(int n) {
        if (int m = (int)fact.size(); n >= m) {
            n = 1 << (8 * sizeof(int) - __builtin_clz(n - 1));
            fact.resize(n + 1);
            ifact.resize(n + 1);
            for (int i = m; i <= n; i++) {
                fact[i] = T(i) * fact[i - 1];
            }
            ifact[n] = T(1) / fact[n];
            for (int i = n; i > m; i--) {
                ifact[i - 1] = T(i) * ifact[i];
            }
        }
    }
};

// Base include
namespace fft {

template <typename T>
struct my_complex {
    using self = my_complex<T>;
    T x, y;
    constexpr my_complex(T x_ = T(0), T y_ = T(0)) : x(x_), y(y_) {}

    constexpr T& real() { return x; }
    constexpr T& imag() { return y; }
    constexpr const T& real() const { return x; }
    constexpr const T& imag() const { return y; }
    constexpr void real(T v) { x = v; }
    constexpr void imag(T v) { y = v; }
    constexpr friend auto real(self a) { return a.x; }
    constexpr friend auto imag(self a) { return a.y; }
    constexpr self rot_ccw(self a) { return self(-a.y, a.x); }
    constexpr self rot_cw(self a) { return self(a.y, -a.x); }
    constexpr friend auto abs(self a) { return sqrt(norm(a)); }
    constexpr friend auto arg(self a) { return atan2(a.y, a.x); }
    constexpr friend auto norm(self a) { return a.x * a.x + a.y * a.y; }
    constexpr friend auto conj(self a) { return self(a.x, -a.y); }
    constexpr friend auto inv(self a) { return self(a.x / norm(a), -a.y / norm(a)); }
    constexpr friend auto polar(T r, T theta = T()) {
        return self(r * cos(theta), r * sin(theta));
    }
    constexpr T& operator[](int i) { assert(i == 0 || i == 1), *(&x + i); }
    constexpr const T& operator[](int i) const { assert(i == 0 || i == 1), *(&x + i); }

    constexpr self& operator+=(self b) { return *this = *this + b; }
    constexpr self& operator-=(self b) { return *this = *this - b; }
    constexpr self& operator*=(self b) { return *this = *this * b; }
    constexpr self& operator/=(self b) { return *this = *this / b; }

    constexpr friend self operator*(self a, T b) { return self(a.x * b, a.y * b); }
    constexpr friend self operator*(T a, self b) { return self(a * b.x, a * b.y); }
    constexpr friend self operator/(self a, T b) { return self(a.x / b, a.y / b); }
    constexpr friend self operator/(T a, self b) { return a * inv(b); }
    constexpr friend self operator+(self a) { return self(a.x, a.y); }
    constexpr friend self operator-(self a) { return self(-a.x, -a.y); }
    constexpr friend self operator+(self a, self b) { return self(a.x + b.x, a.y + b.y); }
    constexpr friend self operator-(self a, self b) { return self(a.x - b.x, a.y - b.y); }
    constexpr friend self operator/(self a, self b) { return a * inv(b); }
    constexpr friend self operator*(self a, self b) {
        return self(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
    }
};

using default_complex = my_complex<double>;
constexpr double TAU = 6.283185307179586476925286766559;

int next_two(int32_t N) { return N > 1 ? 8 * sizeof(N) - __builtin_clz(N - 1) : 0; }

template <typename T, typename D>
constexpr T fft_round(D coefficient) {
    return is_integral<T>::value ? llround(coefficient) : coefficient;
}

template <typename T>
void trim_vector(vector<T>& v) {
    if constexpr (is_floating_point<T>::value)
        while (!v.empty() && abs(v.back()) <= 30 * numeric_limits<T>::epsilon())
            v.pop_back();
    else
        while (!v.empty() && v.back() == T(0))
            v.pop_back();
}

template <typename T>
auto naive_multiply(const vector<T>& a, const vector<T>& b) {
    int A = (int)a.size(), B = (int)b.size(), C = A && B ? A + B - 1 : 0;
    vector<T> c(C);
    for (int i = 0; i < A && B; i++)
        for (int j = 0; j < B; j++)
            c[i + j] += a[i] * b[j];
    trim_vector(c);
    return c;
}

struct fft_reverse_cache {
    static inline vector<vector<int>> rev;

    static const int* get(int N) {
        int n = next_two(N), r = (int)rev.size();
        rev.resize(max(r, n + 1));
        if (rev[n].empty()) {
            int R = 1 << n;
            rev[n].assign(R, 0);
            for (int i = 0; i < N; i++) {
                rev[n][i] = (rev[n][i >> 1] | ((i & 1) << n)) >> 1;
            }
        }
        return rev[n].data();
    }
};

template <typename T>
struct root_of_unity {};

template <typename D>
struct root_of_unity<my_complex<D>> {
    static auto get(int n) {
        assert(n > 0);
        return my_complex<D>(cos(TAU / n), sin(TAU / n));
    }
};

template <typename C>
struct fft_roots_cache {
    static inline vector<C> root = vector<C>(2, C(1));
    static inline vector<C> invroot = vector<C>(2, C(1));
    static inline vector<C> scratch_a, scratch_b;

    static auto get(int N) {
        for (int k = (int)root.size(); k < N; k *= 2) {
            root.resize(2 * k);
            invroot.resize(2 * k);
            auto z = root_of_unity<C>::get(2 * k);
            auto iz = C(1) / z;
            for (int i = k / 2; i < k; i++) {
                root[2 * i] = root[i];
                root[2 * i + 1] = root[i] * z;
                invroot[2 * i] = invroot[i];
                invroot[2 * i + 1] = invroot[i] * iz;
            }
        }
        return make_pair(cref(root), cref(invroot));
    }

    static auto get_scratch(int N) {
        if (int(scratch_a.size()) < N) {
            scratch_a.resize(N);
            scratch_b.resize(N);
        }
        return make_pair(ref(scratch_a), ref(scratch_b));
    }
};

template <typename T>
void fft_bit_reverse(vector<T>& a, int N) {
    auto rev = fft_reverse_cache::get(N);
    for (int i = 0; i < N; i++) {
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
}

template <bool inverse, typename T>
void fft_transform(vector<T>& a, int N, bool reverse = true) {
    if (reverse) {
        fft_bit_reverse(a, N);
    }
    auto [root, invroot] = fft_roots_cache<T>::get(N);
    for (int k = 1; k < N; k *= 2) {
        for (int i = 0; i < N; i += 2 * k) {
            for (int l = i, r = i + k, j = 0; j < k; j++, l++, r++) {
                auto z = inverse ? invroot[j + k] : root[j + k];
                auto t = a[r] * z;
                a[r] = a[l] - t;
                a[l] = a[l] + t;
            }
        }
    }
    if constexpr (inverse) {
        auto inv = T(1) / T(N);
        for (int i = 0; i < N; i++) {
            a[i] *= inv;
        }
    }
}

} // namespace fft

// NTT with modnums
namespace fft {

template <uint32_t MOD>
struct root_of_unity<modnum<MOD>> {
    using type = modnum<MOD>;
    static constexpr int ntt_primitive_root(int p) {
        if (p == 2 || p == 3)
            return p - 1;
        if (p == 167772161 || p == 469762049 || p == 998244353)
            return 3;
        if (p == 1000000007)
            return 5;
        assert(p % 2 == 1);

        auto modpow = [](int base, int64_t e, int mod) {
            int x = 1;
            base = base % mod;
            while (e > 0) {
                if (e & 1)
                    x = int64_t(x) * int64_t(base) % mod;
                if (e >>= 1)
                    base = int64_t(base) * int64_t(base) % mod;
            }
            return x;
        };

        int divs[20] = {2};
        int cnt = 1;
        int x = (p - 1) / 2; // phi(p)
        while (x % 2 == 0) {
            x /= 2;
        }
        for (int i = 3; i * i <= x; i += 2) {
            if (x % i == 0) {
                divs[cnt++] = i;
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) {
            divs[cnt++] = x;
        }
        for (int g = 2;; g++) {
            bool ok = true;
            for (int i = 0; i < cnt; i++) {
                if (modpow(g, (p - 1) / divs[i], p) == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return g;
            }
        }
        __builtin_unreachable();
    }
    static type get(int n) {
        modnum<MOD> g = ntt_primitive_root(MOD);
        assert(n > 0 && (MOD - 1) % n == 0 && "Modulus cannot handle NTT this large");
        return modpow(g, int64_t(MOD - 1) / n);
    }
};

template <uint32_t MOD>
auto ntt_multiply(const vector<modnum<MOD>>& a, const vector<modnum<MOD>>& b) {
    using T = modnum<MOD>;
    if (a.empty() || b.empty()) {
        return vector<T>();
    }
    int A = (int)a.size(), B = (int)b.size();
    int S = A + B - 1, s = next_two(S), N = 1 << s;
    if (1.0 * A * B <= 2.5 * N * s) {
        return naive_multiply(a, b);
    }

    auto fb = fft_roots_cache<T>::get_scratch(N).second;
    vector<T> c(N);
    copy_n(begin(a), A, begin(c));
    copy_n(begin(b), B, begin(fb));
    fill_n(begin(fb) + B, N - B, T(0));
    fft_transform<0>(c, N);
    fft_transform<0>(fb, N);
    for (int i = 0; i < N; i++) {
        c[i] = c[i] * fb[i];
    }
    fft_transform<1>(c, N);
    trim_vector(c);
    return c;
}

} // namespace fft

// Core operations, multiplication, fft
namespace polymath {
#define TTT template <typename T>

static mt19937 rng(random_device{}());

// TODO: Fill in core FFT functions
TTT void bitr(vector<T>& u) { fft::fft_bit_reverse(u, u.size()); }
TTT void fft(vector<T>& u) { fft::fft_transform<0>(u, u.size()); }
TTT void ifft(vector<T>& u) { fft::fft_transform<1>(u, u.size()); }
TTT void sfft(vector<T>& u) { fft::fft_transform<0>(u, u.size()), bitr(u); }
TTT void sifft(vector<T>& u) { fft::fft_transform<1>(u, u.size(), false); }
TTT auto convolve(const vector<T>& a, const vector<T>& b) {
    return fft::ntt_multiply(a, b);
}
TTT auto rand_poly(int n) {
    static uniform_int_distribution<int> dist(1, T::MOD - 1);
    vector<T> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = T(dist(rng));
    }
    return v;
}

// Utility stuff, then elementary operations, then FFT and power series operations

TTT int size(const vector<T>& u) { return (int)u.size(); }
TTT int deg(const vector<T>& u) { return size(u) - 1; }

TTT auto& reverse(vector<T>& u) { return reverse(begin(u), end(u)), u; }
TTT auto& grow(vector<T>& u, int n) { return u.resize(max(size(u), n)), u; }
TTT auto& resize(vector<T>& u, int n) { return u.resize(n), u; }
TTT auto& shrink(vector<T>& u, int n) { return u.resize(min(size(u), n)), u; }
TTT auto& trim(vector<T>& u, int upto = 0) {
    while (size(u) > upto && u.back() == T(0))
        u.pop_back();
    return u;
}

TTT auto grown(vector<T> u, int n) { return grow(u, n), u; }
TTT auto resized(vector<T> u, int n) { return resize(u, n), u; }
TTT auto shrunk(vector<T> u, int n) { return shrink(u, n), u; }
TTT auto trimmed(vector<T> u) { return trim(u), u; }

TTT auto& operator+=(vector<T>& u, T value) { return grow(u, 1), u[0] += value, u; }
TTT auto& operator-=(vector<T>& u, T value) { return grow(u, 1), u[0] -= value, u; }
TTT auto& operator*=(vector<T>& u, T value) {
    for (int i = 0; i < size(u); i++)
        u[i] *= value;
    return u;
}
TTT auto& operator/=(vector<T>& u, T value) { return u *= T(1) / value, u; }
TTT auto& operator+=(vector<T>& u, const vector<T>& v) {
    grow(u, size(v));
    for (int i = 0; i < size(v); i++)
        u[i] += v[i];
    return u;
}
TTT auto& operator-=(vector<T>& u, const vector<T>& v) {
    grow(u, size(v));
    for (int i = 0; i < size(v); i++)
        u[i] -= v[i];
    return u;
}
TTT auto& operator*=(vector<T>& u, const vector<T>& v) { return u = convolve(u, v), u; }

TTT auto operator-(vector<T> u) {
    for (int i = 0; i < size(u); i++)
        u[i] = -u[i];
    return u;
}

TTT auto operator+(vector<T> u, T value) { return u += value, u; }
TTT auto operator-(vector<T> u, T value) { return u -= value, u; }
TTT auto operator*(vector<T> u, T value) { return u *= value, u; }
TTT auto operator+(T value, vector<T> u) { return u += value, u; }
TTT auto operator-(T value, vector<T> u) { return u -= value, u; }
TTT auto operator*(T value, vector<T> u) { return u *= value, u; }
TTT auto operator/(vector<T> u, T value) { return u /= value, u; }
TTT auto operator+(vector<T> u, const vector<T>& v) { return u += v, u; }
TTT auto operator-(vector<T> u, const vector<T>& v) { return u -= v, u; }
TTT auto operator*(const vector<T>& u, const vector<T>& v) { return convolve(u, v); }

TTT auto& pointwise_inplace(vector<T>& u, const vector<T>& o) {
    grow(u, size(o));
    for (int i = 0; i < size(o); i++)
        u[i] *= o[i];
    return u;
}
TTT auto pointwise(vector<T> u, const vector<T>& o) { return pointwise_inplace(u, o), u; }

TTT auto inner_product(const vector<T>& u, const vector<T>& v) {
    T sum = 0;
    for (int i = 0, n = min(size(u), size(v)); i < n; i++)
        sum += u[i] * v[i];
    return sum;
}

TTT auto& rem_shift(vector<T>& u, int s) {
    return u.erase(begin(u), begin(u) + min(size(u), s)), u;
}
TTT auto& add_shift(vector<T>& u, int s, T add = T(0)) {
    return u.insert(begin(u), s, add), u;
}

TTT auto& operator>>=(vector<T>& u, int s) { return rem_shift(u, s); }
TTT auto& operator<<=(vector<T>& u, int s) { return add_shift(u, s); }
TTT auto operator>>(vector<T> u, int s) { return u >>= s, u; }
TTT auto operator<<(vector<T> u, int s) { return u <<= s, u; }

TTT auto& derivative_inplace(vector<T>& u) {
    for (int i = 1; i < size(u); i++)
        u[i - 1] = T(i) * u[i];
    return size(u) > 0 ? u.pop_back(), u : u;
}
TTT auto derivative(vector<T> u) { return derivative_inplace(u), u; }

TTT auto& integral_inplace(vector<T>& u, T zero = 0) {
    u.push_back(T(0));
    for (int i = size(u) - 1; i > 0; i--)
        u[i] = u[i - 1] / T(i);
    return u[0] = zero, u;
}
TTT auto integral(vector<T> u) { return integral_inplace(u), u; }

TTT auto eval(const vector<T>& u, T x) {
    T sum = 0;
    for (int i = size(u) - 1; i >= 0; i--)
        sum = u[i] + sum * x;
    return sum;
}

} // namespace polymath

// Series inverse, exp, log, pow, division, composition
namespace polymath {

TTT auto inverse(const vector<T>& u, int n = -1) {
    assert(size(u) > 0 && u[0] != T(0));
    n = n < 0 ? size(u) : n;

    vector<T> ans(n, T(1) / u[0]);

    for (int d = 1; d < n; d *= 2) {
        vector<T> f(2 * d), g(2 * d);

        for (int j = 0; j < min(2 * d, size(u)); j++)
            f[j] = u[j];
        for (int j = 0; j < d; j++)
            g[j] = ans[j];

        fft(f), fft(g);
        for (int j = 0; j < 2 * d; j++)
            f[j] *= g[j];

        ifft(f);
        for (int j = 0; j < d; j++)
            f[j] = 0;

        fft(f);
        for (int j = 0; j < 2 * d; j++)
            f[j] *= g[j];

        ifft(f);
        for (int j = d; j < min(2 * d, n); j++)
            ans[j] = -f[j];
    }

    return ans;
}

TTT auto exp(const vector<T>& u, int n = -1) {
    assert(size(u) == 0 || u[0] == T(0));
    n = n < 0 ? size(u) : n;

    vector<T> b{1, size(u) > 1 ? u[1] : 0}, c{1}, z1, z2{1, 1};
    b.reserve(n);

    for (int m = 2; m < n; m *= 2) {
        auto y = b;
        resize(y, 2 * m);
        sfft(y);

        z1 = move(z2);
        vector<T> z(m);
        for (int i = 0; i < m; ++i)
            z[i] = y[i] * z1[i];
        sifft(z);
        fill(begin(z), begin(z) + m / 2, T(0));
        sfft(z);
        for (int i = 0; i < m; ++i)
            z[i] *= -z1[i];
        sifft(z);

        c.insert(end(c), begin(z) + m / 2, end(z));
        z2 = c;
        resize(z2, 2 * m);
        sfft(z2);

        vector<T> x(begin(u), begin(u) + min(size(u), m));
        resize(x, m);
        derivative_inplace(x);
        x.push_back(T(0));

        sfft(x);
        for (int i = 0; i < m; ++i)
            x[i] *= y[i];
        sifft(x);

        x -= derivative(b);
        resize(x, 2 * m);
        for (int i = 0; i < m - 1; ++i)
            x[m + i] = x[i], x[i] = T(0);

        sfft(x);
        for (int i = 0; i < 2 * m; ++i)
            x[i] *= z2[i];
        sifft(x);

        x.pop_back();
        integral_inplace(x);
        for (int i = m; i < min(size(u), 2 * m); ++i)
            x[i] += u[i];
        fill(begin(x), begin(x) + m, T(0));

        sfft(x);
        for (int i = 0; i < 2 * m; ++i)
            x[i] *= y[i];
        sifft(x);

        b.insert(end(b), begin(x) + m, end(x));
    }

    resize(b, n);
    return b;
}

TTT auto log(const vector<T>& u, int n = -1) {
    assert(size(u) > 0 && u[0] == 1);
    n = n < 0 ? size(u) : n;
    auto v = derivative(u) * inverse(u, n);
    resize(integral_inplace(v), n - 1);
    return v;
}

TTT auto pow(const vector<T>& u, int64_t k, int n = -1) {
    n = n < 0 ? size(u) : n;
    if (k == 0) {
        return resized(vector<T>{1}, n);
    } else if (k == 1) {
        return resized(u, n);
    } else if (k == 2) {
        return resized(u * u, n);
    } else if (k < 0) {
        return inverse(pow(u, -k, n));
    }

    for (int i = 0; i < size(u) && i * k < n; i++) {
        if (u[i] != 0) {
            auto ans = exp(T(k) * log((u >> i) / u[i], n)) * modpow(u[i], k);
            resize(ans <<= i * k, n);
            return ans;
        }
    }

    return vector<T>(n, 0);
}

TTT auto operator/(vector<T> u, vector<T> v) {
    trim(u), trim(v);
    assert(size(v) > 0);

    if (size(u) < size(v)) {
        return vector<T>();
    } else {
        int n = size(u) - size(v) + 1;
        reverse(u), reverse(v);
        auto q = u * inverse(v, n);
        shrink(q, n), reverse(q), trim(q);
        return q;
    }
}

TTT auto operator%(vector<T> u, vector<T> v) { return u -= v * (u / v), trim(u), u; }
TTT auto& operator/=(vector<T>& u, vector<T> v) { return u = u / move(v), u; }
TTT auto& operator%=(vector<T>& u, vector<T> v) { return u = u % move(v), u; }

TTT auto divrem(vector<T> u, vector<T> v) {
    auto q = u / v;
    u -= q * v, trim(u);
    return make_pair(move(q), move(u));
}

// Composition p(q(x)), naively quadratic, complexity O(n log n)
TTT auto naive_composition(const vector<T>& p, vector<T> q, int n = -1) {
    n = n < 0 ? (size(p) - 1) * (size(q) - 1) + 1 : n;
    if (n == 0) {
        return vector<T>();
    }

    trim(q);
    vector<T> ans(n), u{1};
    u.reserve(n);

    for (int i = 0; i < min(n, size(p)); i++) {
        ans += p[i] * u, u = shrunk(u * q, n);
    }

    return ans;
}

// Composition p(q(x)), square-root decomposition, complexity O((n log n)^3/2)
TTT auto sqrt_composition(const vector<T>& p, vector<T> q, int n = -1) {
    // Source: https://judge.yosupo.jp/submission/43112
    n = n < 0 ? (size(p) - 1) * (size(q) - 1) + 1 : n;
    if (n == 0) {
        return vector<T>();
    }

    trim(q);
    int k = sqrt(n);
    int d = n / k + (k * k < n);

    vector<vector<T>> small(d + 1);
    small[0] = {1}, small[1] = shrunk(q, n);
    for (int i = 2; i <= d; i++) {
        small[i] = small[i / 2] * small[(i + 1) / 2];
        shrink(small[i], n);
    }

    vector<vector<T>> fi(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < d && i * d + j < min(n, size(p)); j++) {
            int x = i * d + j;
            fi[i] += p[x] * small[j];
        }
    }

    vector<T> ans(n), big = {1};
    for (int i = 0; i < k; i++) {
        fi[i] = shrunk(fi[i] * big, n);
        ans += fi[i];
        big = shrunk(big * small[d], n);
    }
    return ans;
}

TTT auto composition(const vector<T>& u, const vector<T>& v, int n = -1) {
    return sqrt_composition(u, v, n);
}

} // namespace polymath

// Polynomial gcd, resultant
namespace polymath {

TTT struct polymat {
    bool identity = false;
    vector<T> a0, a1, b0, b1;

    polymat() : identity(true) {}
    explicit polymat(vector<T> v) : a1({1}), b0({1}), b1(move(v)) {}

    polymat(vector<T> a0_, vector<T> a1_, vector<T> b0_, vector<T> b1_)
        : identity(false), a0(move(a0_)), a1(move(a1_)), b0(move(b0_)), b1(move(b1_)) {}

    friend polymat operator*(const polymat& lhs, const polymat& rhs) {
        if (lhs.identity || rhs.identity)
            return lhs.identity ? rhs : lhs;
        return polymat{
            trimmed(lhs.a0 * rhs.a0 + lhs.a1 * rhs.b0), //
            trimmed(lhs.a0 * rhs.a1 + lhs.a1 * rhs.b1), //
            trimmed(lhs.b0 * rhs.a0 + lhs.b1 * rhs.b0), //
            trimmed(lhs.b0 * rhs.a1 + lhs.b1 * rhs.b1), //
        };
    }

    auto multiply(const vector<T>& a, const vector<T>& b) {
        if (identity)
            return make_pair(a, b);
        return make_pair(trimmed(a0 * a + a1 * b), trimmed(b0 * a + b1 * b));
    }
};

TTT auto halfgcd(const vector<T>& p0, const vector<T>& p1) {
    int m = size(p0) >> 1;
    if (size(p1) <= m) {
        return polymat<T>();
    }

    polymat<T> R = halfgcd(p0 >> m, p1 >> m);
    auto [a, b] = R.multiply(p0, p1);
    if (size(b) <= m) {
        return R;
    }

    auto [q, r] = divrem(a, b);

    polymat<T> Q(-q);
    int k = (m << 1) - size(b) + 1;
    if (size(r) <= k) {
        return Q * R;
    }

    return halfgcd(b >> k, r >> k) * Q * R;
}

TTT auto cogcd(const vector<T>& p0, const vector<T>& p1) {
    polymat<T> M = halfgcd(p0, p1);
    auto [a, b] = M.multiply(p0, p1);
    if (size(b) == 0) {
        return M;
    }

    auto [q, r] = divrem(a, b);
    polymat<T> Q(-q);
    if (size(r) == 0) {
        return Q * M;
    }

    return cogcd(b, r) * Q * M;
}

TTT auto exgcd(vector<T> a, vector<T> b, vector<T>& x, vector<T>& y) {
    // ax + by = monic gcd(a,b)
    trim(a), trim(b);
    if (size(a) == 0 || size(b) == 0) {
        x = y = {1};
        return size(b) == 0 ? a : b;
    }

    if (size(a) > size(b)) {
        auto c = cogcd(a, b);
        x = move(c.a0), y = move(c.a1);
    } else if (size(a) < size(b)) {
        auto c = cogcd(b, a);
        x = move(c.a1), y = move(c.a0);
    } else {
        auto [q, r] = divrem(a, b);
        auto c = cogcd(b, r) * polymat<T>(-q);
        x = move(c.a0), y = move(c.a1);
    }
    auto g = trimmed(a * x + b * y);

    if (auto v = g.back(); v != T(1)) {
        x /= v, y /= v, g /= v;
    }
    return g;
}

TTT auto gcd(vector<T> a, vector<T> b) {
    while (size(a) > 0) {
        b %= a;
        swap(a, b);
    }
    return size(b) == 0 ? b : b / b.back();
}

TTT auto naive_gcd(vector<T> a, vector<T> b, vector<T>& x, vector<T>& y) {
    if (size(a) == 0 && size(b) == 0) {
        x = y = {};
        return vector<T>();
    }
    vector<T> xn = {1}, yn = {};
    x = {}, y = {1};
    while (size(a) > 0) {
        auto [q, r] = divrem(b, a);
        b = move(r);
        x = x - q * xn, trim(x);
        y = y - q * yn, trim(y);
        swap(a, b);
        swap(x, xn);
        swap(y, yn);
    }
    if (auto v = b.back(); v != T(1)) {
        x /= v, y /= v, b /= v;
    }
    return b;
}

TTT auto resultant(const vector<T>& a, const vector<T>& b) {
    int A = size(a), B = size(b);
    if (B == 0) {
        return T();
    } else if (B == 1) {
        return modpow(b[0], A - 1);
    } else {
        auto c = a % b;
        A -= size(c);
        int sign = ((A - 1) & (B - 1) & 1) ? -1 : 1;
        auto mul = modpow(b[0], A - 1) * sign;
        return mul * resultant(b, c);
    }
}

} // namespace polymath

// Multipoint evaluation, interpolation
namespace polymath {

constexpr int MULTIEVAL_THRESHOLD = 300;

TTT auto multieval(const vector<T>& p, const vector<T>& x) {
    // Source: https://github.com/Aeren1564/Algorithms
    int S = size(x);
    if (size(p) <= MULTIEVAL_THRESHOLD || size(x) <= MULTIEVAL_THRESHOLD) {
        vector<T> ans(S);
        for (int i = 0; i < S; i++) {
            ans[i] = eval(p, x[i]);
        }
        return ans;
    }

    vector<vector<T>> st(2 * S);

    y_combinator([&](auto self, int u, int l, int r) -> void {
        if (r - l == 1) {
            st[u] = {-x[l], 1};
        } else {
            int m = l + ((r - l) >> 1), v = u + ((m - l) << 1);
            self(u + 1, l, m), self(v, m, r);
            st[u] = st[u + 1] * st[v];
        }
    })(0, 0, S);

    vector<T> ans(S);

    y_combinator([&](auto self, int u, int l, int r, vector<T> f) -> void {
        f %= st[u];
        if (size(f) <= MULTIEVAL_THRESHOLD) {
            for (int i = l; i < r; i++) {
                ans[i] = eval(f, x[i]);
            }
        } else if (r - l == 1) {
            ans[l] = f[0];
        } else {
            int m = l + ((r - l) >> 1), v = u + ((m - l) << 1);
            self(u + 1, l, m, f), self(v, m, r, move(f));
        }
    })(0, 0, S, p);

    return ans;
}

TTT auto interpolate(const vector<T>& x, const vector<T>& y) {
    // Source: https://github.com/Aeren1564/Algorithms
    assert(size(x) == size(y));
    int S = size(x);
    if (S == 0) {
        return vector<T>();
    }

    vector<vector<T>> st(2 * S);

    y_combinator([&](auto self, int u, int l, int r) -> void {
        if (r - l == 1) {
            st[u] = {-x[l], 1};
        } else {
            int m = l + ((r - l) >> 1), v = u + ((m - l) << 1);
            self(u + 1, l, m), self(v, m, r);
            st[u] = st[u + 1] * st[v];
        }
    })(0, 0, S);

    vector<T> val(S);

    y_combinator([&](auto self, int u, int l, int r, vector<T> f) -> void {
        f %= st[u];
        if (size(f) <= MULTIEVAL_THRESHOLD) {
            for (int i = l; i < r; i++) {
                val[i] = eval(f, x[i]);
            }
        } else if (r - l == 1) {
            val[l] = f[0];
        } else {
            int m = l + ((r - l) >> 1), v = u + ((m - l) << 1);
            self(u + 1, l, m, f), self(v, m, r, move(f));
        }
    })(0, 0, S, derivative(st[0]));

    for (int i = 0; i < S; i++) {
        val[i] = y[i] / val[i];
    }

    return y_combinator([&](auto self, int u, int l, int r) -> vector<T> {
        if (r - l == 1) {
            return vector<T>{val[l]};
        } else {
            int m = l + ((r - l) >> 1), v = u + ((m - l) << 1);
            return self(u + 1, l, m) * st[v] + self(v, m, r) * st[u + 1];
        }
    })(0, 0, S);
}

} // namespace polymath

// Famous series, taylor shift. Functions return polynomial with degree n (i.e. size n+1)
namespace polymath::series {

TTT auto convert_to_ogf(vector<T> egf) {
    for (int i = 0, n = egf.size(); i < n; i++) {
        egf[i] *= Binomial<T>::fac(i);
    }
    return egf;
}

TTT auto convert_to_egf(vector<T> ogf) {
    for (int i = 0, n = ogf.size(); i < n; i++) {
        ogf[i] *= Binomial<T>::invfac(i);
    }
    return ogf;
}

TTT auto alternating(vector<T> series, int first_negative) {
    for (int i = first_negative, n = size(series); i < n; i += 2) {
        series[i] = -series[i];
    }
    return series;
}

// (x-x0)(x-x1)(x-x2)... Time: O(n log n)
TTT auto with_roots(const vector<T>& roots) {
    int n = roots.size();
    if (n == 0) {
        return vector<T>{1};
    }

    queue<vector<T>> Q;

    for (int i = 0; i < n; i++) {
        Q.push({-roots[i], 1});
    }
    while (Q.size() > 1u) {
        auto u = move(Q.front());
        Q.pop();
        auto v = move(Q.front());
        Q.pop();
        Q.push(u * v);
    }

    return move(Q.front());
}

// Find p(x+a). Time: O(n log n)
TTT auto taylor_shift(vector<T> p, T a) {
    int n = size(p);
    p = convert_to_ogf(move(p));
    reverse(p);
    vector<T> g(n, 1);
    for (int i = 1; i < n; i++) {
        g[i] = g[i - 1] * a * Binomial<T>::inv(i);
    }
    p = p * g;
    shrink(p, n);
    reverse(p);
    return convert_to_egf(move(p));
}

// e^x = SUM x^k/k!
TTT auto exponential(int n) {
    vector<T> etox(n + 1);
    for (int i = n; i >= 0; i--) {
        etox[i] = Binomial<T>::invfac(i);
    }
    return etox;
}

// SUM x^k/k
TTT auto harmonic(int n, T zero = 0) {
    vector<T> ans(n + 1);
    ans[0] = zero;
    for (int i = 1; i <= n; i++) {
        ans[i] = Binomial<T>::inv(i);
    }
    return ans;
}

// SUM k^m x^k
TTT auto mth_powers(int n, int m) {
    vector<T> ans(n + 1);
    for (int i = 0; i <= n; i++) {
        ans[i] = modpow(T(i), m);
    }
    return ans;
}

// x(x+1)(x+2)...(x+n-1). Time: O(n log n).
TTT auto rising_factorial(int n) {
    if (n == 0) {
        return vector<T>{1};
    }
    int lg = 31 - __builtin_clz(n);
    vector<T> f = {0, 1};
    for (int i = lg - 1; i >= 0; i--) {
        int k = n >> i;
        f *= taylor_shift(f, T(k >> 1));
        if (k & 1) {
            f = (f << 1) + T(k - 1) * f;
        }
    }
    return f;
}

// x(x-1)(x-2)...(x-n+1). Time: O(n log n)
TTT auto falling_factorial(int n) {
    return alternating(rising_factorial<T>(n), 1 + n % 2);
}

// Faulhaber on exponent: faul[i] = 1^i + 2^i + ... + m^i. Time: O(n log n)
TTT auto faulhaber(int n, int m) {
    n += 1;              // include n
    vector<T> ex(n + 1); // e^x = SUM x^k/k!
    for (int i = n; i >= 0; i--) {
        ex[i] = Binomial<T>::invfac(i);
    }
    vector<T> den(n);
    for (int i = n - 1; i >= 0; i--) {
        den[i] = -ex[i + 1];
    }
    vector<T> num(n);
    T p = 1;
    for (int i = 0; i < n; i++) {
        p *= m + 1;
        num[i] = ex[i + 1] * (1 - p);
    }
    return convert_to_ogf(resized(num * inverse(den, n), n));
}

// Unsigned Stirling 1st kind, fixed n. Time: O(n log n)
TTT auto stirling_1st(int n) { return rising_factorial<T>(n); }

// Unsigned Stirling 1st kind, fixed k. Time: O(n log n)
TTT auto stirling_1st(int n, int k) {
    return convert_to_ogf(pow(harmonic<T>(n), k) * Binomial<T>::invfac(k));
}

// Stirling 2nd kind, fixed n. Time: O(n log n)
TTT auto stirling_2nd(int n) {
    auto a = alternating(exponential<T>(n), 1);
    auto b = convert_to_egf(mth_powers<T>(n, n));
    return resized(a * b, n + 1);
}

// Stirling 2nd kind, fixed k. Time: O(n log n)
TTT auto stirling_2nd(int n, int k) {
    return convert_to_ogf(pow(exponential<T>(n) - T(1), k) * Binomial<T>::invfac(k));
}

// Bell numbers: number of partitions of a set of n elements. Time: O(n log n)
TTT auto bell(int n) { return convert_to_ogf(exp(exponential<T>(n) - T(1))); }

// Partition number: number of unrestricted partitions of integer n. Time: O(n log n)
TTT auto partitions(int n) {
    vector<T> p(n + 1);
    for (int k = 0, t = 1; k * (3 * k - 1) / 2 <= n; k++, t = -t) {
        p[k * (3 * k - 1) / 2] = t;
    }
    for (int k = 1, t = -1; k * (3 * k + 1) / 2 <= n; k++, t = -t) {
        p[k * (3 * k + 1) / 2] = t;
    }
    return inverse(p, n + 1);
}

// Bernoulli numbers OGF. Time: O(n log n)
TTT auto bernoulli(int n) {
    return convert_to_ogf(inverse((exponential<T>(n + 2) >> 1)));
}

// Eulerian numbers, fixed n. eulerian[k] = A(n,k). Time: O(n log n)
TTT auto eulerian(int n) {
    return resized(mth_powers<T>(n, n) * pow<T>({1, -1}, n + 1, n + 1), n + 1);
}

// TODO: Eulerian OGF for fixed k?

TTT auto sine(int n) {
    vector<T> ans(n + 1);
    for (int i = 1; i <= n; i += 2) {
        ans[i] = (i & 2) ? -Binomial<T>::invfac(i) : Binomial<T>::invfac(i);
    }
    return ans;
}

TTT auto cosine(int n) {
    vector<T> ans(n + 1);
    for (int i = 0; i <= n; i += 2) {
        ans[i] = (i & 2) ? -Binomial<T>::invfac(i) : Binomial<T>::invfac(i);
    }
    return ans;
}

TTT auto secant(int n) { return inverse(cosine<T>(n)); }

TTT auto tangent(int n) { return resized(sine<T>(n) * secant<T>(n), n + 1); }

// Euler number E(n): number of alternating permutations of size n. Time: O(n log n)
TTT auto euler_alternating(int n) {
    auto v = secant<T>(n) + tangent<T>(n);
    return convert_to_ogf(resized(v * v, n + 1));
}

} // namespace polymath::series

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, a, b;
    cin >> N >> a >> b;

    if (a == 0 || b == 0 || a+b-1 > N) {
      std::cout << "0\n";
      return 0;
    }

    --N;
    using num = modnum<998244353>;
    auto stirling = polymath::series::falling_factorial<num>(N);
    std::cout << polymath::series::stirling_1st<num>(N)[a+b-2] * Binomial<num>::choose(a+b-2, a-1) << '\n';
    return 0;
}