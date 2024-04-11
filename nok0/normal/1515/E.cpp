/**
 *	author: nok0
 *	created: 2021.05.03 00:39:57
**/
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

namespace atcoder {

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

}  // namespace atcoder

namespace atcoder {

namespace internal {

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if(x < 0) x += m;
	return x;
}

// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
// NOTE: reconsider after Ice Lake
struct barrett {
	unsigned int _m;
	unsigned long long im;

	// @param m `1 <= m < 2^31`
	explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

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
		if(_m <= v) v += _m;
		return v;
	}
};

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
	if(m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	unsigned long long y = safe_mod(x, m);
	while(n) {
		if(n & 1) r = (r * y) % _m;
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
	if(n <= 1) return false;
	if(n == 2 || n == 7 || n == 61) return true;
	if(n % 2 == 0) return false;
	long long d = n - 1;
	while(d % 2 == 0) d /= 2;
	constexpr long long bases[3] = {2, 7, 61};
	for(long long a : bases) {
		long long t = d;
		long long y = pow_mod_constexpr(a, t, n);
		while(t != n - 1 && y != 1 && y != n - 1) {
			y = y * y % n;
			t <<= 1;
		}
		if(y != n - 1 && t % 2 == 0) {
			return false;
		}
	}
	return true;
}
template <int n>
constexpr bool is_prime = is_prime_constexpr(n);

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
	a = safe_mod(a, b);
	if(a == 0) return {b, 0};

	// Contracts:
	// [1] s - m0 * a = 0 (mod b)
	// [2] t - m1 * a = 0 (mod b)
	// [3] s * |m1| + t * |m0| <= b
	long long s = b, t = a;
	long long m0 = 0, m1 = 1;

	while(t) {
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
	if(m0 < 0) m0 += b / s;
	return {s, m0};
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int primitive_root_constexpr(int m) {
	if(m == 2) return 1;
	if(m == 167772161) return 3;
	if(m == 469762049) return 3;
	if(m == 754974721) return 11;
	if(m == 998244353) return 3;
	int divs[20] = {};
	divs[0] = 2;
	int cnt = 1;
	int x = (m - 1) / 2;
	while(x % 2 == 0) x /= 2;
	for(int i = 3; (long long)(i)*i <= x; i += 2) {
		if(x % i == 0) {
			divs[cnt++] = i;
			while(x % i == 0) {
				x /= i;
			}
		}
	}
	if(x > 1) {
		divs[cnt++] = x;
	}
	for(int g = 2;; g++) {
		bool ok = true;
		for(int i = 0; i < cnt; i++) {
			if(pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
				ok = false;
				break;
			}
		}
		if(ok) return g;
	}
}
template <int m>
constexpr int primitive_root = primitive_root_constexpr(m);

// @param n `n < 2^32`
// @param m `1 <= m < 2^32`
// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)
unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
	unsigned long long ans = 0;
	while(true) {
		if(a >= m) {
			ans += n * (n - 1) / 2 * (a / m);
			a %= m;
		}
		if(b >= m) {
			ans += n * (b / m);
			b %= m;
		}

		unsigned long long y_max = a * n + b;
		if(y_max < m) break;
		// y_max < m * (n + 1)
		// floor(y_max / m) <= n
		n = (unsigned long long)(y_max / m);
		b = (unsigned long long)(y_max % m);
		std::swap(m, a);
	}
	return ans;
}

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
	int x = 0;
	while((1U << x) < (unsigned int)(n)) x++;
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

}  // namespace atcoder

namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T>
using is_modint = std::is_base_of<modint_base, T>;
template <class T>
using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)> * = nullptr>
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
	template <class T, internal::is_signed_int_t<T> * = nullptr>
	static_modint(T v) {
		long long x = (long long)(v % (long long)(umod()));
		if(x < 0) x += umod();
		_v = (unsigned int)(x);
	}
	template <class T, internal::is_unsigned_int_t<T> * = nullptr>
	static_modint(T v) {
		_v = (unsigned int)(v % umod());
	}

	unsigned int val() const { return _v; }

	mint &operator++() {
		_v++;
		if(_v == umod()) _v = 0;
		return *this;
	}
	mint &operator--() {
		if(_v == 0) _v = umod();
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

	mint &operator+=(const mint &rhs) {
		_v += rhs._v;
		if(_v >= umod()) _v -= umod();
		return *this;
	}
	mint &operator-=(const mint &rhs) {
		_v -= rhs._v;
		if(_v >= umod()) _v += umod();
		return *this;
	}
	mint &operator*=(const mint &rhs) {
		unsigned long long z = _v;
		z *= rhs._v;
		_v = (unsigned int)(z % umod());
		return *this;
	}
	mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

	mint operator+() const { return *this; }
	mint operator-() const { return mint() - *this; }

	mint pow(long long n) const {
		assert(0 <= n);
		mint x = *this, r = 1;
		while(n) {
			if(n & 1) r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}
	mint inv() const {
		if(prime) {
			assert(_v);
			return pow(umod() - 2);
		} else {
			auto eg = internal::inv_gcd(_v, m);
			assert(eg.first == 1);
			return eg.second;
		}
	}

	friend mint operator+(const mint &lhs, const mint &rhs) {
		return mint(lhs) += rhs;
	}
	friend mint operator-(const mint &lhs, const mint &rhs) {
		return mint(lhs) -= rhs;
	}
	friend mint operator*(const mint &lhs, const mint &rhs) {
		return mint(lhs) *= rhs;
	}
	friend mint operator/(const mint &lhs, const mint &rhs) {
		return mint(lhs) /= rhs;
	}
	friend bool operator==(const mint &lhs, const mint &rhs) {
		return lhs._v == rhs._v;
	}
	friend bool operator!=(const mint &lhs, const mint &rhs) {
		return lhs._v != rhs._v;
	}

private:
	unsigned int _v;
	static constexpr unsigned int umod() { return m; }
	static constexpr bool prime = internal::is_prime<m>;
};

template <int id>
struct dynamic_modint : internal::modint_base {
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
	template <class T, internal::is_signed_int_t<T> * = nullptr>
	dynamic_modint(T v) {
		long long x = (long long)(v % (long long)(mod()));
		if(x < 0) x += mod();
		_v = (unsigned int)(x);
	}
	template <class T, internal::is_unsigned_int_t<T> * = nullptr>
	dynamic_modint(T v) {
		_v = (unsigned int)(v % mod());
	}

	unsigned int val() const { return _v; }

	mint &operator++() {
		_v++;
		if(_v == umod()) _v = 0;
		return *this;
	}
	mint &operator--() {
		if(_v == 0) _v = umod();
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

	mint &operator+=(const mint &rhs) {
		_v += rhs._v;
		if(_v >= umod()) _v -= umod();
		return *this;
	}
	mint &operator-=(const mint &rhs) {
		_v += mod() - rhs._v;
		if(_v >= umod()) _v -= umod();
		return *this;
	}
	mint &operator*=(const mint &rhs) {
		_v = bt.mul(_v, rhs._v);
		return *this;
	}
	mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }

	mint operator+() const { return *this; }
	mint operator-() const { return mint() - *this; }

	mint pow(long long n) const {
		assert(0 <= n);
		mint x = *this, r = 1;
		while(n) {
			if(n & 1) r *= x;
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

	friend mint operator+(const mint &lhs, const mint &rhs) {
		return mint(lhs) += rhs;
	}
	friend mint operator-(const mint &lhs, const mint &rhs) {
		return mint(lhs) -= rhs;
	}
	friend mint operator*(const mint &lhs, const mint &rhs) {
		return mint(lhs) *= rhs;
	}
	friend mint operator/(const mint &lhs, const mint &rhs) {
		return mint(lhs) /= rhs;
	}
	friend bool operator==(const mint &lhs, const mint &rhs) {
		return lhs._v == rhs._v;
	}
	friend bool operator!=(const mint &lhs, const mint &rhs) {
		return lhs._v != rhs._v;
	}

private:
	unsigned int _v;
	static internal::barrett bt;
	static unsigned int umod() { return bt.umod(); }
};
template <int id>
internal::barrett dynamic_modint<id>::bt(998244353);

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class>
struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

namespace internal {

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
void butterfly(std::vector<mint> &a) {
	static constexpr int g = internal::primitive_root<mint::mod()>;
	int n = int(a.size());
	int h = internal::ceil_pow2(n);

	static bool first = true;
	static mint sum_e[30];  // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]
	if(first) {
		first = false;
		mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
		int cnt2 = bsf(mint::mod() - 1);
		mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
		for(int i = cnt2; i >= 2; i--) {
			// e^(2^i) == 1
			es[i - 2] = e;
			ies[i - 2] = ie;
			e *= e;
			ie *= ie;
		}
		mint now = 1;
		for(int i = 0; i <= cnt2 - 2; i++) {
			sum_e[i] = es[i] * now;
			now *= ies[i];
		}
	}
	for(int ph = 1; ph <= h; ph++) {
		int w = 1 << (ph - 1), p = 1 << (h - ph);
		mint now = 1;
		for(int s = 0; s < w; s++) {
			int offset = s << (h - ph + 1);
			for(int i = 0; i < p; i++) {
				auto l = a[i + offset];
				auto r = a[i + offset + p] * now;
				a[i + offset] = l + r;
				a[i + offset + p] = l - r;
			}
			now *= sum_e[bsf(~(unsigned int)(s))];
		}
	}
}

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
void butterfly_inv(std::vector<mint> &a) {
	static constexpr int g = internal::primitive_root<mint::mod()>;
	int n = int(a.size());
	int h = internal::ceil_pow2(n);

	static bool first = true;
	static mint sum_ie[30];  // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]
	if(first) {
		first = false;
		mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1
		int cnt2 = bsf(mint::mod() - 1);
		mint e = mint(g).pow((mint::mod() - 1) >> cnt2), ie = e.inv();
		for(int i = cnt2; i >= 2; i--) {
			// e^(2^i) == 1
			es[i - 2] = e;
			ies[i - 2] = ie;
			e *= e;
			ie *= ie;
		}
		mint now = 1;
		for(int i = 0; i <= cnt2 - 2; i++) {
			sum_ie[i] = ies[i] * now;
			now *= es[i];
		}
	}

	for(int ph = h; ph >= 1; ph--) {
		int w = 1 << (ph - 1), p = 1 << (h - ph);
		mint inow = 1;
		for(int s = 0; s < w; s++) {
			int offset = s << (h - ph + 1);
			for(int i = 0; i < p; i++) {
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

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> convolution_naive(const std::vector<mint> &a, const std::vector<mint> &b) {
	int n = int(a.size()), m = int(b.size());
	std::vector<mint> ans(n + m - 1);
	if(n < m) {
		for(int j = 0; j < m; j++) {
			for(int i = 0; i < n; i++) {
				ans[i + j] += a[i] * b[j];
			}
		}
	} else {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				ans[i + j] += a[i] * b[j];
			}
		}
	}
	return ans;
}

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> convolution_fft(std::vector<mint> a, std::vector<mint> b) {
	int n = int(a.size()), m = int(b.size());
	int z = 1 << internal::ceil_pow2(n + m - 1);
	a.resize(z);
	internal::butterfly(a);
	b.resize(z);
	internal::butterfly(b);
	for(int i = 0; i < z; i++) {
		a[i] *= b[i];
	}
	internal::butterfly_inv(a);
	a.resize(n + m - 1);
	mint iz = mint(z).inv();
	for(int i = 0; i < n + m - 1; i++) a[i] *= iz;
	return a;
}

}  // namespace internal

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> convolution(std::vector<mint> &&a, std::vector<mint> &&b) {
	int n = int(a.size()), m = int(b.size());
	if(!n || !m) return {};
	if(std::min(n, m) <= 60) return convolution_naive(a, b);
	return internal::convolution_fft(a, b);
}

template <class mint, internal::is_static_modint_t<mint> * = nullptr>
std::vector<mint> convolution(const std::vector<mint> &a, const std::vector<mint> &b) {
	int n = int(a.size()), m = int(b.size());
	if(!n || !m) return {};
	if(std::min(n, m) <= 60) return convolution_naive(a, b);
	return internal::convolution_fft(a, b);
}

template <unsigned int mod = 998244353,
          class T,
          std::enable_if_t<internal::is_integral<T>::value> * = nullptr>
std::vector<T> convolution(const std::vector<T> &a, const std::vector<T> &b) {
	int n = int(a.size()), m = int(b.size());
	if(!n || !m) return {};

	using mint = static_modint<mod>;
	std::vector<mint> a2(n), b2(m);
	for(int i = 0; i < n; i++) {
		a2[i] = mint(a[i]);
	}
	for(int i = 0; i < m; i++) {
		b2[i] = mint(b[i]);
	}
	auto c2 = convolution(move(a2), move(b2));
	std::vector<T> c(n + m - 1);
	for(int i = 0; i < n + m - 1; i++) {
		c[i] = c2[i].val();
	}
	return c;
}

std::vector<long long> convolution_ll(const std::vector<long long> &a,
                                      const std::vector<long long> &b) {
	int n = int(a.size()), m = int(b.size());
	if(!n || !m) return {};

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
	for(int i = 0; i < n + m - 1; i++) {
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
		if(diff < 0) diff += MOD1;
		static constexpr unsigned long long offset[5] = {
		    0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};
		x -= offset[diff % 5];
		c[i] = x;
	}

	return c;
}

}  // namespace atcoder

using namespace atcoder;

#pragma region Macros
// rep macro
#define foa(v, a) for(auto &v : a)
#define REPname(a, b, c, d, e, ...) e
#define REP(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define REP0(x) for(int i = 0; i < (x); ++i)
#define REP1(i, x) for(int i = 0; i < (x); ++i)
#define REP2(i, l, r) for(int i = (l); i < (r); ++i)
#define REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))
#define REPSname(a, b, c, ...) c
#define REPS(...) REPSname(__VA_ARGS__, REPS1, REPS0)(__VA_ARGS__)
#define REPS0(x) for(int i = 1; i <= (x); ++i)
#define REPS1(i, x) for(int i = 1; i <= (x); ++i)
#define RREPname(a, b, c, d, e, ...) e
#define RREP(...) RREPname(__VA_ARGS__, RREP3, RREP2, RREP1, RREP0)(__VA_ARGS__)
#define RREP0(x) for(int i = (x)-1; i >= 0; --i)
#define RREP1(i, x) for(int i = (x)-1; i >= 0; --i)
#define RREP2(i, r, l) for(int i = (r)-1; i >= (l); --i)
#define RREP3(i, r, l, c) for(int i = (r)-1; i >= (l); i -= (c))
#define RREPSname(a, b, c, ...) c
#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS__)
#define RREPS0(x) for(int i = (x); i >= 1; --i)
#define RREPS1(i, x) for(int i = (x); i >= 1; --i)

// name macro
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;

// input macro
template <class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
	for(T &i : v) is >> i;
	return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
	std::string s;
	is >> s;
	__int128_t ret = 0;
	for(int i = 0; i < s.length(); i++)
		if('0' <= s[i] and s[i] <= '9')
			ret = 10 * ret + s[i] - '0';
	a = ret * (s[0] == '-' ? -1 : 1);
	return is;
}

namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template <class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template <class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
}  // namespace scanner
#define VEC(type, name, size)     \
	std::vector<type> name(size); \
	scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
	std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
	scanner::INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
	std::string __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)

// output-macro
template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
	for(int i = 0; i < int(a.size()); ++i) {
		if(i) os << " ";
		os << a[i];
	}
	return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
	std::ostream::sentry s(dest);
	if(s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while(tmp != 0);
		if(value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if(dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}
template <class T>
void print(const T a) { std::cout << a << '\n'; }
template <class Head, class... Tail>
void print(Head H, Tail... T) {
	std::cout << H << ' ';
	print(T...);
}
template <class T>
void printel(const T a) { std::cout << a << '\n'; }
template <class T>
void printel(const std::vector<T> &a) {
	for(const auto &v : a)
		std::cout << v << '\n';
}
template <class Head, class... Tail>
void printel(Head H, Tail... T) {
	std::cout << H << '\n';
	printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "NO\n"; }
void err(const bool b = true) {
	if(b) {
		std::cout << "-1\n", exit(0);
	}
}

//debug macro
namespace debugger {
template <class T>
void view(const std::vector<T> &a) {
	std::cerr << "{ ";
	for(const auto &v : a) {
		std::cerr << v << ", ";
	}
	std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
	std::cerr << "{\n";
	for(const auto &v : a) {
		std::cerr << "\t";
		view(v);
		std::cerr << "\n";
	}
	std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
	std::cerr << "{\n";
	for(const auto &p : a) std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &p : m) std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::pair<T, U> &p) { std::cerr << "(" << p.first << ", " << p.second << ")"; }
template <class T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &v : s) {
		view(v);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}

template <class T>
void view(const T &e) { std::cerr << e; }
}  // namespace debugger
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	debugger::view(H);
	std::cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                                \
	do {                                                          \
		std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(false)
#else
#define debug(...) (void(0))
#endif

// vector macro
template <class T>
int lb(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x))); }
template <class T>
int ub(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x))); }
template <class T>
void UNIQUE(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<T> press(std::vector<T> &a) {
	auto res = a;
	UNIQUE(res);
	for(auto &v : a)
		v = lb(res, v);
	return res;
}
#define SORTname(a, b, c, ...) c
#define SORT(...) SORTname(__VA_ARGS__, SORT1, SORT0, ...)(__VA_ARGS__)
#define SORT0(a) std::sort((a).begin(), (a).end())
#define SORT1(a, c) std::sort((a).begin(), (a).end(), [](const auto x, const auto y) { return x c y; })
template <class T>
void ADD(std::vector<T> &a, const T x) {
	for(auto &v : a) v += x;
}
template <class T>
void SUB(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v -= x;
}
template <class T>
void MUL(std::vector<T> &a, const T x) {
	for(auto &v : a) v *= x;
}
template <class T>
void DIV(std::vector<T> &a, const T x) {
	for(auto &v : a) v /= x;
}

// math macro
template <class T, class U>
inline bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <class T, class U>
inline bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <class T>
T divup(T x, T y) { return (x + y - 1) / y; }
template <class T>
T POW(T a, long long n) {
	T ret = 1;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}
// modpow
long long POW(long long a, long long n, const int mod) {
	long long ret = 1;
	while(n) {
		if(n & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ret;
}

// others
struct fast_io {
	fast_io() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} fast_io_;
const int inf = 1e9;
const ll INF = 1e18;
#pragma endregion

#pragma region Math Formal Power Series
enum Mode {
	FAST = 1,
	NAIVE = -1,
};
template <class T, Mode mode = FAST>
struct FormalPowerSeries : std::vector<T> {
	using std::vector<T>::vector;
	using std::vector<T>::size;
	using std::vector<T>::resize;
	using std::vector<T>::begin;
	using std::vector<T>::insert;
	using std::vector<T>::erase;
	using F = FormalPowerSeries;
	using S = std::vector<std::pair<int, T>>;

	F &operator+=(const F &g) {
		for(int i = 0; i < int(std::min((*this).size(), g.size())); i++) (*this)[i] += g[i];
		return *this;
	}

	F &operator+=(const T &t) {
		assert(int((*this).size()));
		(*this)[0] += t;
		return *this;
	}

	F &operator-=(const F &g) {
		for(int i = 0; i < int(std::min((*this).size(), g.size())); i++) (*this)[i] -= g[i];
		return *this;
	}

	F &operator-=(const T &t) {
		assert(int((*this).size()));
		(*this)[0] -= t;
		return *this;
	}

	F &operator*=(const T &t) {
		for(int i = 0; i < int((*this).size()); ++i) (*this)[i] *= t;
		return *this;
	}

	F &operator/=(const T &t) {
		T div = t.inv();
		for(int i = 0; i < int((*this).size()); ++i) (*this)[i] *= div;
		return *this;
	}

	F &operator>>=(const int sz) {
		assert(sz >= 0);
		int n = (*this).size();
		(*this).erase((*this).begin(), (*this).begin() + std::min(sz, n));
		(*this).resize(n);
		return *this;
	}

	F &operator<<=(const int sz) {
		assert(sz >= 0);
		int n = (*this).size();
		(*this).insert((*this).begin(), sz, T(0));
		(*this).resize(n);
		return *this;
	}

	F &operator%=(const F &g) { return *this -= *this / g * g; }

	F &operator=(const std::vector<T> &v) {
		int n = (*this).size();
		for(int i = 0; i < n; ++i) (*this)[i] = v[i];
		return *this;
	}

	F operator-() const {
		F ret = *this;
		return ret * -1;
	}

	F &operator*=(const F &g) {
		if(mode == FAST) {
			int n = (*this).size();
			auto tmp = atcoder::convolution(*this, g);
			for(int i = 0; i < n; ++i) (*this)[i] = tmp[i];
			return *this;
		} else {
			int n = (*this).size(), m = g.size();
			for(int i = n - 1; i >= 0; --i) {
				(*this)[i] *= g[0];
				for(int j = 1; j < std::min(i + 1, m); j++)
					(*this)[i] += (*this)[i - j] * g[j];
			}
			return *this;
		}
	}

	F &operator/=(const F &g) {
		if((*this).size() < g.size()) {
			(*this).assign((*this).size(), T(0));
			return *this;
		}
		if(mode == FAST) {
			int old = (*this).size();
			int n = (*this).size() - g.size() + 1;
			*this = ((*this).rev().pre(n) * g.rev().inv(n));
			(*this).rev_inplace();
			(*this).resize(old);
			return *this;
		} else {
			assert(g[0] != T(0));
			T ig0 = g[0].inv();
			int n = (*this).size(), m = g.size();
			for(int i = 0; i < n; ++i) {
				for(int j = 1; j < std::min(i + 1, m); ++j)
					(*this)[i] -= (*this)[i - j] * g[j];
				(*this)[i] *= ig0;
			}
			return *this;
		}
	}

	F &operator*=(S g) {
		int n = (*this).size();
		auto [d, c] = g.front();
		if(!d)
			g.erase(g.begin());
		else
			c = 0;
		for(int i = n - 1; i >= 0; --i) {
			(*this)[i] *= c;
			for(auto &[j, b] : g) {
				if(j > i) break;
				(*this)[i] += (*this)[i - j] * b;
			}
		}
		return *this;
	}

	F &operator/=(S g) {
		int n = (*this).size();
		auto [d, c] = g.front();
		assert(!d and c != 0);
		T ic = c.inv();
		g.erase(g.begin());
		for(int i = 0; i < n; ++i) {
			for(auto &[j, b] : g) {
				if(j > i) break;
				(*this)[i] -= (*this)[i - j] * b;
			}
			(*this)[i] *= ic;
		}
		return *this;
	}

	F operator+(const F &g) const { return F(*this) += g; }

	F operator+(const T &t) const { return F(*this) += t; }

	F operator-(const F &g) const { return F(*this) -= g; }

	F operator-(const T &t) const { return F(*this) -= t; }

	F operator*(const F &g) const { return F(*this) *= g; }

	F operator*(const T &t) const { return F(*this) *= t; }

	F operator/(const F &g) const { return F(*this) /= g; }

	F operator/(const T &t) const { return F(*this) /= t; }

	F operator%(const F &g) const { return F(*this) %= g; }

	F operator*=(const S &g) const { return F(*this) *= g; }

	F operator/=(const S &g) const { return F(*this) /= g; }

	F pre(int d) const { return F((*this).begin(), (*this).begin() + std::min((int)(*this).size(), d)); }

	F &shrink() {
		while(!(*this).empty() and (*this).back() == T(0)) (*this).pop_back();
		return *this;
	}

	F &rev_inplace() {
		reverse((*this).begin(), (*this).end());
		return *this;
	}
	F rev() const { return F(*this).rev_inplace(); }

	// *=(1 + cz^d)
	F &multiply(const int d, const T c) {
		int n = (*this).size();
		if(c == T(1))
			for(int i = n - d - 1; i >= 0; --i)
				(*this)[i + d] += (*this)[i];
		else if(c == T(-1))
			for(int i = n - d - 1; i >= 0; --i)
				(*this)[i + d] -= (*this)[i];
		else
			for(int i = n - d - 1; i >= 0; --i)
				(*this)[i + d] += (*this)[i] * c;
		return *this;
	}
	// /=(1 + cz^d)
	F &divide(const int d, const T c) {
		int n = (*this).size();
		if(c == T(1))
			for(int i = 0; i < n - d; ++i) (*this)[i + d] -= (*this)[i];
		else if(c == T(-1))
			for(int i = 0; i < n - d; ++i) (*this)[i + d] += (*this)[i];
		else
			for(int i = 0; i < n - d; ++i) (*this)[i + d] -= (*this)[i] * c;
		return *this;
	}

	//(N)
	T eval(const T &t) const {
		int n = (*this).size();
		T res = 0, tmp = 1;
		for(int i = 0; i < n; ++i) res += (*this)[i] * tmp, tmp *= t;
		return res;
	}

	F inv(int deg = -1) const {
		int n = (*this).size();
		assert(mode == FAST and n and (*this)[0] != 0);
		if(deg == -1) deg = n;
		assert(deg > 0);
		F res{(*this)[0].inv()};
		while(int(res.size()) < deg) {
			int m = res.size();
			F f((*this).begin(), (*this).begin() + std::min(n, m * 2)), r(res);
			f.resize(m * 2), atcoder::internal::butterfly(f);
			r.resize(m * 2), atcoder::internal::butterfly(r);
			for(int i = 0; i < m * 2; ++i) f[i] *= r[i];
			atcoder::internal::butterfly_inv(f);
			f.erase(f.begin(), f.begin() + m);
			f.resize(m * 2), atcoder::internal::butterfly(f);
			for(int i = 0; i < m * 2; ++i) f[i] *= r[i];
			atcoder::internal::butterfly_inv(f);
			T iz = T(m * 2).inv();
			iz *= -iz;
			for(int i = 0; i < m; ++i) f[i] *= iz;
			res.insert(res.end(), f.begin(), f.begin() + m);
		}
		res.resize(deg);
		return res;
	}

	//(N)
	F &diff_inplace() {
		int n = (*this).size();
		for(int i = 1; i < n; ++i) (*this)[i - 1] = (*this)[i] * i;
		(*this)[n - 1] = 0;
		return *this;
	}
	F diff() const { F(*this).diff_inplace(); }

	//(N)
	F &integral_inplace() {
		int n = (*this).size(), mod = T::mod();
		std::vector<T> inv(n);
		{
			inv[1] = 1;
			for(int i = 2; i < n; ++i)
				inv[i] = T(mod) - inv[mod % i] * (mod / i);
		}
		for(int i = n - 2; i >= 0; --i) (*this)[i + 1] = (*this)[i] * inv[i + 1];
		(*this)[0] = 0;
		return *this;
	}
	F integral() const { return F(*this).integral_inplace(); }

	//(NlogN)
	F &log_inplace() {
		int n = (*this).size();
		assert(n and (*this)[0] == 1);
		F f_inv = (*this).inv();
		(*this).diff_inplace();
		(*this) *= f_inv;
		(*this).integral_inplace();
		return *this;
	}
	F log() const { return F(*this).log_inplace(); }

	//(NlogN)
	F &deriv_inplace() {
		int n = (*this).size();
		assert(n);
		for(int i = 2; i < n; ++i) (*this)[i] *= i;
		(*this).erase((*this).begin());
		(*this).push_back(0);
		return *this;
	}
	F deriv() const { return F(*this).deriv_inplace(); }

	//(NlogN)
	F &exp_inplace() {
		int n = (*this).size();
		assert(n and (*this)[0] == 0);
		F g{1};
		(*this)[0] = 1;
		F h_drv((*this).deriv());
		for(int m = 1; m < n; m *= 2) {
			F f((*this).begin(), (*this).begin() + m);
			f.resize(2 * m), atcoder::internal::butterfly(f);
			auto mult_f = [&](F &p) {
				p.resize(2 * m);
				atcoder::internal::butterfly(p);
				for(int i = 0; i < 2 * m; ++i) p[i] *= f[i];
				atcoder::internal::butterfly_inv(p);
				p /= 2 * m;
			};
			if(m > 1) {
				F g_(g);
				g_.resize(2 * m), atcoder::internal::butterfly(g_);
				for(int i = 0; i < 2 * m; ++i) g_[i] *= g_[i] * f[i];
				atcoder::internal::butterfly_inv(g_);
				T iz = T(-2 * m).inv();
				g_ *= iz;
				g.insert(g.end(), g_.begin() + m / 2, g_.begin() + m);
			}
			F t((*this).begin(), (*this).begin() + m);
			t.deriv_inplace();
			{
				F r{h_drv.begin(), h_drv.begin() + m - 1};
				mult_f(r);
				for(int i = 0; i < m; ++i) t[i] -= r[i] + r[m + i];
			}
			t.insert(t.begin(), t.back());
			t.pop_back();
			t *= g;
			F v((*this).begin() + m, (*this).begin() + std::min(n, 2 * m));
			v.resize(m);
			t.insert(t.begin(), m - 1, 0);
			t.push_back(0);
			t.integral_inplace();
			for(int i = 0; i < m; ++i) v[i] -= t[m + i];
			mult_f(v);
			for(int i = 0; i < std::min(n - m, m); ++i)
				(*this)[m + i] = v[i];
		}
		return *this;
	}
	F exp() const { return F(*this).exp_inplace(); }

	//(NlogN)
	F &pow_inplace(long long k) {
		int n = (*this).size(), l = 0;
		assert(k >= 0);
		if(!k) {
			for(int i = 0; i < n; ++i) (*this)[i] = !i;
			return *this;
		}
		while(l < n and (*this)[l] == 0) ++l;
		if(l > (n - 1) / k or l == n) return *this = F(n);
		T c = (*this)[l];
		(*this).erase((*this).begin(), (*this).begin() + l);
		(*this) /= c;
		(*this).log_inplace();
		(*this).resize(n - l * k);
		(*this) *= k;
		(*this).exp_inplace();
		(*this) *= c.pow(k);
		(*this).insert((*this).begin(), l * k, 0);
		return *this;
	}
	F pow(const long long k) const { return F(*this).pow_inplace(k); }

	//(NlogN)
	F sqrt(int deg = -1) const {
		auto SQRT = [&](T t) {
			int mod = T::mod();
			if(t == 0 or t == 1) return t;
			int v = (mod - 1) / 2;
			if(t.pow(v) != 1) return T(-1);
			int q = mod - 1, m = 0;
			while(~q & 1) q >>= 1, m++;
			std::mt19937 mt;
			T z = mt();
			while(z.pow(v) != mod - 1) z = mt();
			T c = z.pow(q), u = t.pow(q), r = t.pow((q + 1) / 2);
			for(; m > 1; m--) {
				T tmp = u.pow(1 << (m - 2));
				if(tmp != 1) r = r * c, u = u * c * c;
				c = c * c;
			}
			return T(std::min(r.val(), mod - r.val()));
		};
		int n = (*this).size();
		if(deg == -1) deg = n;
		if((*this)[0] == 0) {
			for(int i = 1; i < n; i++) {
				if((*this)[i] != 0) {
					if(i & 1) return F(0);
					if(deg - i / 2 <= 0) break;
					auto ret = (*this);
					ret >>= i;
					ret.resize(n - i);
					ret = ret.sqrt(deg - i / 2);
					if(ret.empty()) return F(0);
					ret <<= (i / 2);
					ret.resize(deg);
					return ret;
				}
			}
			return F(deg);
		}
		auto sqr = SQRT((*this)[0]);
		if(sqr * sqr != (*this)[0]) return F(0);
		F ret{sqr};
		T ti = T(1) / T(2);
		for(int i = 1; i < deg; i <<= 1) {
			auto u = (*this);
			u.resize(i << 1);
			ret = (ret.inv(i << 1) * u + ret) * ti;
		}
		ret.resize(deg);
		return ret;
	}

	void sparse_pow(const int n, const int d, const T c, const int k);
	void sparse_pow_inv(const int n, const int d, const T c, const int k);
	void stirling_first(int n);
	void stirling_second(int n);
	std::vector<T> multipoint_evaluation(const std::vector<T> &p);
};
#pragma endregion

void main_() {
	INT(n, m);
	modint::set_mod(m);
	modint res = 0;
	using fps = FormalPowerSeries<modint, NAIVE>;
	fps f(n + 1);
	f[0] = 1;
	int j = 2;
	int k = 1;
	for(int i = n; i >= divup(n + 1, 2); i--) {
		f.divide(1, -j);
		j += 2;
		f *= k;
		res += f[n - k * 2 + 1];
		k++;
	}
	print(res.val());
}

int main() {
	int t = 1;
	//cin >> t;
	while(t--) main_();
	return 0;
}