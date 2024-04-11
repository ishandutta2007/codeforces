#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

namespace internal {

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
// NOTE: reconsider after Ice Lake
struct barrett {
    unsigned int _m;
    unsigned long long im;

    // @param m `1 <= m < 2^31`
    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    // @return m
    unsigned int umod() const { return _m; }

    // @param a `0 <= a < m`
    // @param b `0 <= b < m`
    // @return `a * b % m`
    unsigned int mul(unsigned int a, unsigned int b) const {
        // [1] m = 1
        // a = b = im = 0, so okay

        // [2] m >= 2
        // im = ceil(2^64 / m)
        // -> im * m = 2^64 + r (0 <= r < m)
        // let z = a*b = c*m + d (0 <= c, d < m)
        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im
        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2
        // ((ab * im) >> 64) == c or c + 1
        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
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
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

}  // namespace internal

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal



namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }
    static_modint(bool v) { _v = ((unsigned int)(v) % umod()); }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
    using mint = dynamic_modint;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }
    dynamic_modint(bool v) { _v = ((unsigned int)(v) % mod()); }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt = 998244353;

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

namespace internal {

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void butterfly(std::vector<mint>& a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static bool first = true;
    static mint sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]
    if (first) {
        first = false;
        mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_e[i] = es[i] * now;
            now *= ies[i];
        }
    }
    for (int ph = 1; ph <= h; ph++) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint now = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p] * now;
                a[i + offset] = l + r;
                a[i + offset + p] = l - r;
            }
            now *= sum_e[bsf(~(unsigned int)(s))];
        }
    }
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
void butterfly_inv(std::vector<mint>& a) {
    static constexpr int g = internal::primitive_root<mint::mod()>;
    int n = int(a.size());
    int h = internal::ceil_pow2(n);

    static bool first = true;
    static mint sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
    if (first) {
        first = false;
        mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
        int cnt2 = bsf(mint::mod() - 1);
        mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
        for (int i = cnt2; i >= 2; i--) {
            // e^(2^i) == 1
            es[i - 2] = e;
            ies[i - 2] = ie;
            e *= e;
            ie *= ie;
        }
        mint now = 1;
        for (int i = 0; i <= cnt2 - 2; i++) {
            sum_ie[i] = ies[i] * now;
            now *= es[i];
        }
    }

    for (int ph = h; ph >= 1; ph--) {
        int w = 1 << (ph - 1), p = 1 << (h - ph);
        mint inow = 1;
        for (int s = 0; s < w; s++) {
            int offset = s << (h - ph + 1);
            for (int i = 0; i < p; i++) {
                auto l = a[i + offset];
                auto r = a[i + offset + p];
                a[i + offset] = l + r;
                a[i + offset + p] =
                    (unsigned long long)(mint::mod() + l.val() - r.val()) *
                    inow.val();
            }
            inow *= sum_ie[bsf(~(unsigned int)(s))];
        }
    }
}

}  // namespace internal

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(std::vector<mint> a, std::vector<mint> b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (std::min(n, m) <= 60) {
        if (n < m) {
            std::swap(n, m);
            std::swap(a, b);
        }
        std::vector<mint> ans(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i + j] += a[i] * b[j];
            }
        }
        return ans;
    }
    int z = 1 << internal::ceil_pow2(n + m - 1);
    a.resize(z);
    internal::butterfly(a);
    b.resize(z);
    internal::butterfly(b);
    for (int i = 0; i < z; i++) {
        a[i] *= b[i];
    }
    internal::butterfly_inv(a);
    a.resize(n + m - 1);
    mint iz = mint(z).inv();
    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
    return a;
}

template <unsigned int mod = 998244353,
          class T,
          std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    using mint = static_modint<mod>;
    std::vector<mint> a2(n), b2(m);
    for (int i = 0; i < n; i++) {
        a2[i] = mint(a[i]);
    }
    for (int i = 0; i < m; i++) {
        b2[i] = mint(b[i]);
    }
    auto c2 = convolution(move(a2), move(b2));
    std::vector<T> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        c[i] = c2[i].val();
    }
    return c;
}

std::vector<long long> convolution_ll(const std::vector<long long>& a,
                                      const std::vector<long long>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};

    static constexpr unsigned long long MOD1 = 754974721;  // 2^24
    static constexpr unsigned long long MOD2 = 167772161;  // 2^25
    static constexpr unsigned long long MOD3 = 469762049;  // 2^26
    static constexpr unsigned long long M2M3 = MOD2 * MOD3;
    static constexpr unsigned long long M1M3 = MOD1 * MOD3;
    static constexpr unsigned long long M1M2 = MOD1 * MOD2;
    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;

    static constexpr unsigned long long i1 =
        internal::inv_gcd(MOD2 * MOD3, MOD1).second;
    static constexpr unsigned long long i2 =
        internal::inv_gcd(MOD1 * MOD3, MOD2).second;
    static constexpr unsigned long long i3 =
        internal::inv_gcd(MOD1 * MOD2, MOD3).second;

    auto c1 = convolution<MOD1>(a, b);
    auto c2 = convolution<MOD2>(a, b);
    auto c3 = convolution<MOD3>(a, b);

    std::vector<long long> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        unsigned long long x = 0;
        x += (c1[i] * i1) % MOD1 * M2M3;
        x += (c2[i] * i2) % MOD2 * M1M3;
        x += (c3[i] * i3) % MOD3 * M1M2;
        // B = 2^63, -B <= x, r(real value) < B
        // (x, x - M, x - 2M, or x - 3M) = r (mod 2B)
        // r = c1[i] (mod MOD1)
        // focus on MOD1
        // r = x, x - M', x - 2M', x - 3M' (M' = M % 2^64) (mod 2B)
        // r = x,
        //     x - M' + (0 or 2B),
        //     x - 2M' + (0, 2B or 4B),
        //     x - 3M' + (0, 2B, 4B or 6B) (without mod!)
        // (r - x) = 0, (0)
        //           - M' + (0 or 2B), (1)
        //           -2M' + (0 or 2B or 4B), (2)
        //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)
        // we checked that
        //   ((1) mod MOD1) mod 5 = 2
        //   ((2) mod MOD1) mod 5 = 3
        //   ((3) mod MOD1) mod 5 = 4
        long long diff =
            c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));
        if (diff < 0) diff += MOD1;
        static constexpr unsigned long long offset[5] = {
            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
        x -= offset[diff % 5];
        c[i] = x;
    }

    return c;
}

}  // namespace atcoder
using namespace atcoder;



// https://nyaannyaan.github.io/library/fps/formal-power-series.hpp.html
namespace po167{

long long rev(long long a,long long MOD){
    long long D=1,C=MOD-2;
    while(C){
        if(C&1) D=(D*a)%MOD;
        C>>=1;
        a=(a*a)%MOD;
    }
    return D;
}
template <unsigned int mod = 998244353>
std::vector<long long> add_Polynomial(std::vector<long long> &p,std::vector<long long> &q){
	std::vector<long long> r(std::max(p.size(),q.size()));
	for(int i=0;i<(int)r.size();i++){
		if((int)p.size()>i) r[i]=p[i];
		if((int)q.size()>i) r[i]=(r[i]+q[i])%mod;
	}
	return r;
}
template <unsigned int mod = 998244353>
std::vector<long long> sub_Polynomial(std::vector<long long> &p,std::vector<long long> &q){
	std::vector<long long> r(std::max(p.size(),q.size()));
	for(int i=0;i<(int)r.size();i++){
		if((int)p.size()>i) r[i]=p[i];
		if((int)q.size()>i) r[i]=(r[i]-q[i]);
        if(r[i]<0) r[i]=(r[i]%mod+mod)%mod;
	}
	return r;
}
template <unsigned int mod = 998244353>
long long substitution_Polynomial(std::vector<long long> &p,long long x){
	long long ans=0;
	long long D=1;
	for(int i=0;i<p.size();i++){
		ans=(ans+(D*p[i])%mod)%mod;
		D=(D*x)%mod;
	}
	return ans;
}
template <unsigned int mod = 998244353>
std::vector<long long> differential_Polynomial(std::vector<long long> &p){
	int N=p.size();
	std::vector<long long> r(N);
	for(int i=1;i<N;i++){
		r[i-1]=((long long)(i)*p[i])%mod;
	}
	return r;
}

template <unsigned int mod = 998244353>
std::vector<long long> Integral_Polynomial(std::vector<long long> &p){
	int N=p.size();
	std::vector<long long> r(1+N);
	std::vector<long long> rev(N+1,1);
	for(int i=0;i<N;i++){
		if(i+1>1){
			rev[i+1]=(mod-((mod/(i+1))*rev[mod%(i+1)])%mod)%mod;
		}
		r[i+1]=(rev[i+1]*p[i])%mod;
	}
	return r;
}


template <class T>
std::vector<T> slice_vec(std::vector<T> &p,int S){
	if(S>=(int)(p.size())) return p;
	std::vector<T> r(S);
	for(int i=0;i<S;i++) r[i]=p[i];
	return r;
}
// return f^{-1} mod x^{L}
// https://judge.yosupo.jp/submission/79004
template <unsigned int mod = 998244353>
std::vector<long long> inv_FPS(int N,int L,std::vector<long long> &p){
	assert((int)p.size()==N);
	assert(0<N);
	assert(p[0]%mod!=0);
	std::vector<long long> q={1},tmp,tmp2;
	long long D=p[0];
	long long C=mod-2;
	while(C){
		if(C&1){
			q[0]=(q[0]*D)%mod;
		}
		C>>=1;
		D=(D*D)%mod;
	}
	int S=1;
	while(S<L){
		S*=2;
		tmp.assign(S,0);
		for(int i=0;i<std::min((int)(p.size()),S);i++) tmp[i]=p[i];
		tmp2=convolution<mod>(tmp,convolution<mod>(q,q));
		for(int i=0;i<S;i++){
			if(i*2<S) tmp[i]=(2ll*q[i]-tmp2[i]+mod)%mod;
			else tmp[i]=(-tmp2[i]+mod)%mod;
		}
		swap(tmp,q);
	}
	std::vector<long long> ans(S);
	for(int i=0;i<S;i++) ans[i]=q[i];
	return ans;
}
// return log f(x)
// https://judge.yosupo.jp/submission/79008
template <unsigned int mod = 998244353>
std::vector<long long> log_FPS(int N,int L,std::vector<long long> &p){
	assert(p[0]==1);
	auto tmp=convolution<mod>(differential_Polynomial<mod>(p),inv_FPS<mod>(N,L,p));
	auto tmp3=Integral_Polynomial<mod>(tmp);
	return slice_vec(tmp3,L);
}
// return e^{f(x)}
template <unsigned int mod = 998244353>
std::vector<long long> exp_FPS(int N,int L,std::vector<long long> &p){
	assert((int)p.size()==N);
	assert(0<N);
	assert(p[0]%mod==0);
	std::vector<long long> q={1},tmp,tmp2,tmp3;
	int S=1;
	while(S<L){
		S*=2;
		tmp=slice_vec(p,S);
        tmp2=log_FPS<mod>(S/2,S,q);
        tmp3=sub_Polynomial<mod>(tmp,tmp2);
        tmp3[0]++;
        tmp=convolution<mod>(q,tmp3);
        for(int i=0;i<S;i++){
            if(i==(int)(q.size())) q.push_back(tmp[i]);
            else q[i]=tmp[i];
        }
	}
	std::vector<long long> ans(S);
	for(int i=0;i<S;i++) ans[i]=q[i];
	return ans;
}

//if all zero:
// return {0}
std::vector<long long> zero_cut(std::vector<long long> &p){
    int ind=0;
    for(int i=0;i<(int)(p.size());i++){
        if(p[i]!=0) ind=i;
    }
    return slice_vec(p,ind+1);
}
//return {a,b} (p=aq+b)
//https://judge.yosupo.jp/submission/79020
template <unsigned int mod = 998244353>
std::pair<std::vector<long long>,std::vector<long long>> div_FPS(std::vector<long long> &p,std::vector<long long> &q){
    int N=p.size(),M=q.size();
	if(N<M){
        return {{0},p};
    }
    auto f=p,g=q;
    std::reverse(f.begin(),f.end());
    std::reverse(g.begin(),g.end());
    auto tmp=convolution<mod>(f,inv_FPS(M,N-M+1,g));
    auto ans1=slice_vec(tmp,N-M+1);
    std::reverse(ans1.begin(),ans1.end());
    tmp=convolution(ans1,q);
    std::vector<long long> ans2(M-1);
    for(int i=0;i<M-1;i++) ans2[i]=(p[i]-tmp[i]+mod)%mod;
    return std::make_pair(zero_cut(ans1),zero_cut(ans2));
}
//return [f(p[0]),f(p[1])...f(p[M-1])]
//https://judge.yosupo.jp/submission/79035
template <unsigned int mod = 998244353>
std::vector<long long> Multipoint_Evaluation(std::vector<long long> f,std::vector<long long>p){
    int M=p.size();
	if(M==0){
		return {};
	}
    std::vector<int> size={M};
    int ind=0;
    while(size[ind]!=1){
        size.push_back((size[ind]+1)/2);
        ind++;
    }
    ind++;
    std::vector<std::vector<std::vector<long long>>> divisor(ind),remain(ind);
    for(int i=0;i<ind;i++){
        divisor[i].resize(size[i]);
        if(i==0){
            for(int j=0;j<M;j++){
                divisor[i][j]={mod-p[j],1};
            }
        }else{
            for(int j=0;j<size[i];j++){
                if(j!=size[i]-1||size[i-1]%2==0){
                    divisor[i][j]=convolution<mod>(divisor[i-1][j*2],divisor[i-1][j*2+1]);
                }else{
                    divisor[i][j]=divisor[i-1][size[i-1]-1];
                }
            }
        }
    }
    for(int i=ind-1;i>=0;i--){
        remain[i].resize(size[i]);
        if(i==ind-1){
            remain[i][0]=div_FPS<mod>(f,divisor[ind-1][0]).second;
        }else{
            for(int j=0;j<size[i];j++){
                if(j!=size[i]-1||size[i]%2==0){
                    remain[i][j]=div_FPS(remain[i+1][j/2],divisor[i][j]).second;
                }else{
                    remain[i][j]=remain[i+1][j/2];
                }
            }
        }
    }
    std::vector<long long> ans(M);
    for(int i=0;i<M;i++) ans[i]=remain[0][i][0];
    return ans;
}

template <unsigned int mod = 998244353>
std::vector<long long> multiplication_FPS(std::vector<std::vector<long long>> &p){
    std::queue<std::vector<long long>> pq;
    int N=p.size();
    for(int i=0;i<N;i++) pq.push(p[i]);
    for(int i=1;i<N;i++){
        auto l=pq.front();
        pq.pop();
        auto r=pq.front();
        pq.pop();
        pq.push(convolution<mod>(l,r));
    }
    return pq.front();
}
struct frac_fps{
    std::vector<long long> ch;
    std::vector<long long> mo;
};
template <unsigned int mod = 998244353>
frac_fps add_frac_fps(frac_fps &l,frac_fps &r){
    auto tmp1=convolution<mod>(l.ch,r.mo);
    auto tmp2=convolution<mod>(l.mo,r.ch);
    return {add_Polynomial<mod>(tmp1,tmp2),convolution<mod>(l.mo,r.mo)};
}
template <unsigned int mod = 998244353>
std::vector<long long> Polynomial_Interpolation(std::vector<long long> &x,std::vector<long long> &y){
    int N=x.size();
    assert(x.size()==y.size());
    std::vector<std::vector<long long>> p(N);
    for(int i=0;i<N;i++){
        p[i]={(mod-x[i])%mod,1};
    }
    auto tmp1=multiplication_FPS<mod>(p);
    auto div=differential_Polynomial<mod>(tmp1);
    auto val=Multipoint_Evaluation<mod>(div,x);
    std::queue<frac_fps> q;
    for(int i=0;i<N;i++) q.push({{y[i]},{(mod-(val[i]*x[i])%mod)%mod,val[i]}});
    for(int i=1;i<N;i++){
        frac_fps l=q.front();
        q.pop();
        frac_fps r=q.front();
        q.pop();
        q.push(add_frac_fps<mod>(l,r));
    }
    long long D=1;
    auto ans=q.front().ch;
    for(int i=0;i<N;i++){
        D=(D*val[i])%mod;
    }
    D=rev(D,mod);
    for(int i=0;i<N;i++) ans[i]=(ans[i]*D)%mod;
    return ans;
}
}

namespace po167{
struct combination{
	int upper;
	long long MOD;
	std::vector<long long> fact;
	std::vector<long long> rev;
	std::vector<long long> fact_rev;
	combination(int max,long long mod):upper(max),MOD(mod),fact(max+1),rev(max+1),fact_rev(max+1){
		for(long long i=0;i<=max;i++){
			if(i<2){
				fact[i]=1;
				fact_rev[i]=1;
				rev[i]=1;
				continue;
			}
			fact[i]=(fact[i-1]*i)%mod;
			rev[i]=mod-((mod/i)*rev[mod%i])%mod;
			fact_rev[i]=(fact_rev[i-1]*rev[i])%mod;
		}
	}
	long long Comb(int x,int y){
		assert(upper>=x);
		if (x<y||y<0||x<0) return 0;
		return (((fact_rev[y]*fact_rev[x-y])%MOD)*fact[x])%MOD;
	}
	long long P(int x,int y){
		assert(upper>=x);
		if (x<y||y<0||x<0) return 0;
		return (fact_rev[x-y]*fact[x])%MOD;
	}
};
}
using po167::combination;



void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll n;
	cin>>n;
	vector<ll> pow2(n+1,1);
	ll rev=(mod+1)/2;
	//ll Z=1;
	rep(i,n) pow2[i+1]=(pow2[i]*rev)%mod;
	combination table(n,mod);
	vector<ll> A(n+1),B(n+1);
	rep(i,n+1){
		A[i]=table.fact_rev[i];
		if(i&1) continue;
		B[i]=(pow2[i/2]*table.fact_rev[i/2])%mod;
		//Z=(Z*rev)%mod;
	}
	auto C=convolution<mod>(A,B);
	ll ans=0;
	for(ll x=0;x*4<=n;x++){
		ll tmp=(table.Comb(n-2*x,2*x)*table.fact[x*2])%mod;
		tmp=(tmp*table.fact_rev[x])%mod;
		//tmp=(tmp*pow2[x])%mod;

		
		tmp=(tmp*table.fact[n-4*x])%mod;
		tmp=(tmp*C[n-4*x])%mod;
		ans=(ans+tmp)%mod;
	}
	cout<<(ans+mod)%mod<<"\n";
}