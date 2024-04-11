#include <bits/stdc++.h>
using namespace std;

namespace math {
	constexpr int mod_exp(long long x, long long n, int m) {
		assert(0 <= n && 0 < m);
		if ((x %= m) < 0) {
			x += m;
		}
		long long ans = 1;
		for (; n; n /= 2) {
			if (n & 1) {
				ans = ans * x % m;
			}
			x = x * x % m;
		}
		return ans;
	}

	template <typename T>
	constexpr T primitive_root(T n) {
		assert(1 < n);

		T factors[20] = {};
		int no_factors = 0;

		T x = n - 1;
		for (int i = 2; (T) i * i <= x; i++) {
			if (x % i == 0) {
				factors[no_factors++] = i;
				while (x % i == 0) {
					x /= i;
				}
			}
		}
		if (x > 1) {
			factors[no_factors++] = x;
		}

		for (int i = 1; i < n; i++) {
			bool is_primitive_root = true;
			for (int j = 0; j < no_factors; j++) {
				is_primitive_root &= mod_exp(i, (n - 1) / factors[j], n) != 1;
			}
			if (is_primitive_root) {
				return i;
			}
		}
		return -1;
	}
}

template <typename mint>
struct is_static_mint_helper : std::false_type { };

template <typename mint>
struct is_static_mint : is_static_mint_helper<typename std::decay<mint>::type> { };

template <typename mint>
struct is_dynamic_mint_helper : std::false_type { };

template <typename mint>
struct is_dynamic_mint : is_dynamic_mint_helper<typename std::decay<mint>::type> { };

template <typename mint>
struct is_mint : std::integral_constant<bool, is_static_mint<mint>::value || is_dynamic_mint<mint>::value> { };

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	constexpr static auto get_m() {
		return M;
	}

	int val;

	constexpr auto get_val() {
		return val;
	}

	constexpr static_mint() : val() {}

	constexpr static_mint(long long x) : val(x % M) { if (val < 0) val += M; }

	constexpr static_mint pow(long long n) const {
		static_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}

	constexpr static_mint inv() const {
		return pow(M - 2);
	}

	constexpr static_mint operator+() const {
		static_mint m;
		m.val = val;
		return m;
	}

	constexpr static_mint operator-() const {
		static_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}

	constexpr static_mint &operator+=(const static_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}

	constexpr static_mint &operator-=(const static_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}

	constexpr static_mint &operator*=(const static_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}

	constexpr static_mint &operator/=(const static_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}

	constexpr friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) += rhs;
	}

	constexpr friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) -= rhs;
	}

	constexpr friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) *= rhs;
	}

	constexpr friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) /= rhs;
	}

	constexpr friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val == rhs.val;
	}

	constexpr friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val != rhs.val;
	}

	constexpr static_mint &operator++() {
		return *this += 1;
	}

	constexpr static_mint &operator--() {
		return *this -= 1;
	}

	constexpr static_mint operator++(int) {
		static_mint result(*this);
		*this += 1;
		return result;
	}

	constexpr static_mint operator--(int) {
		static_mint result(*this);
		*this -= 1;
		return result;
	}

	template<typename T>
	constexpr explicit operator T() const {
		return T(val);
	}

	friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
		return os << m.val;
	}

	friend std::istream &operator>>(std::istream &is, static_mint &m) {
		long long x;
		return is >> x, m = x, is;
	}
};

template <int M>
struct is_static_mint_helper<static_mint<M>> : std::true_type { };

namespace ntt {
	template <typename T>
	constexpr T ntt_root(T n) {
		auto root = math::primitive_root(n);
		return math::mod_exp(root, (n - 1) >> __builtin_ctz(n - 1), n);
	}

	template <typename T>
	constexpr T order_of_ntt_root(T n) {
		return 1 << __builtin_ctz(n - 1);
	}

	template <typename mint>
	struct ntt_info {
		static_assert(is_static_mint<mint>::value, "Mod must be a constant");

		static constexpr auto m = mint::get_m();
		static constexpr auto root = ntt_root(m);
		static constexpr auto root_order = order_of_ntt_root(m);

		static std::vector<mint> roots;

		static void compute_roots(int lg) {
			static constexpr auto M = mint::get_m();
			static int computed = 1;
			if (lg <= computed) return;
			roots.resize(1 << lg);
			for (int k = computed; k < lg; k++) {
				mint z(ntt_info<mint>::root);
				for (int i = (1 << (k + 1)); i < root_order; i <<= 1) {
					z *= z;
				}
				for (int i = (1 << (k - 1)); i < (1 << k); i++) {
					roots[i << 1] = roots[i];
					roots[i << 1 | 1] = roots[i] * z;
				}
			}
			computed = lg;
		};
	};

	template <typename mint>
	std::vector<mint> ntt_info<mint>::roots = {0, 1};

	std::vector<int> rev = {0};

	void compute_bit_reverse(int lg) {
		static int computed = 0;
		if (lg <= computed) return;
		rev.resize(1 << lg);
		for (int i = (1 << computed); i < (1 << lg); i++) {
			rev[i] = (rev[i >> 1] >> 1) ^ ((i & 1) << 30);
		}
		computed = lg;
	}

	template<typename mint>
	void ntt(std::vector<mint> &a) {
		int n = int(a.size()), lg = 32 - __builtin_clz(n) - 1;
		compute_bit_reverse(lg);
		ntt_info<mint>::compute_roots(lg);
		int shift = 31 - lg;
		for (int i = 0; i < n; i++) {
			if (i < (rev[i] >> shift)) {
				std::swap(a[i], a[rev[i] >> shift]);
			}
		}
		for (int k = 1; k < n; k <<= 1) {
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; j++) {
					auto z = ntt_info<mint>::roots[j + k] * a[i + j + k];
					a[i + j + k] = a[i + j] - z;
					a[i + j] = a[i + j] + z;
				}
			}
		}
	}

	template<typename mint>
	std::vector<mint> convolution(std::vector<mint> a, std::vector<mint> b) {
		int n = 1;
		while (n < a.size() + b.size()) {
			n <<= 1;
		}
		a.resize(n), b.resize(n);
		ntt(a), ntt(b);
		mint n_inv = mint(n).inv();
		for (int i = 0; i < n; i++) {
			a[i] *= b[i] * n_inv;
		}
		std::reverse(a.begin() + 1, a.end());
		return ntt(a), a;
	}

	template <typename mint>
	std::vector<mint>& inplace_convolution(std::vector<mint> &a, std::vector<mint> b) {
		int n = 1;
		while (n < a.size() + b.size()) {
			n <<= 1;
		}
		a.resize(n), b.resize(n);
		ntt(a), ntt(b);
		mint n_inv = mint(n).inv();
		for (int i = 0; i < n; i++) {
			a[i] *= b[i] * n_inv;
		}
		std::reverse(a.begin() + 1, a.end());
		return ntt(a), a;
	}

	template <typename mint, template <int...> typename ntt_mint>
	mint garner(int a1, int a2, int a3) {
		static constexpr auto M1 = 167772161, M2 = 469762049, M3 = 754974721;
		static constexpr auto R12 = ntt_mint<M2>(M1).inv().get_val();
		static constexpr auto R13 = ntt_mint<M3>(M1).inv().get_val();
		static constexpr auto R23 = ntt_mint<M3>(M2).inv().get_val();
		int x1 = a1;
		int x2 = (long long) (a2 >= x1 ? a2 - x1 : M2 + a2 - x1) * R12 % M2;
		int temp = (long long) (a3 >= x1 ? a3 - x1 : M3 + a3 - x1) * R13 % M3;
		int x3 = (long long) (temp >= x2 ? temp - x2 : M3 + temp - x2) * R23 % M3;
		return mint(x1) + mint(x2) * M1 + mint(x3) * M1 * M2;
	}

	template <typename mint, template <unsigned...> typename ntt_mint>
	mint garner(unsigned a1, unsigned a2, unsigned a3) {
		static constexpr auto M1 = 167772161u, M2 = 469762049u, M3 = 754974721u;
		static constexpr auto R12 = ntt_mint<M2>(M1).inv().get_val();
		static constexpr auto R13 = ntt_mint<M3>(M1).inv().get_val();
		static constexpr auto R23 = ntt_mint<M3>(M2).inv().get_val();
		unsigned x1 = a1;
		unsigned x2 = (unsigned long long) (a2 >= x1 ? a2 - x1 : M2 + a2 - x1) * R12 % M2;
		unsigned temp = (unsigned long long) (a3 >= x1 ? a3 - x1 : M3 + a3 - x1) * R13 % M3;
		unsigned x3 = (unsigned long long) (temp >= x2 ? temp - x2 : M3 + temp - x2) * R23 % M3;
		return mint(x1) + mint(x2) * M1 + mint(x3) * M1 * M2;
	}

	template <typename mint, template <auto...> typename ntt_mint>
	std::vector<mint> arbitrary_mod_convolution(std::vector<mint> a, const std::vector<mint> &b) {
		static constexpr decltype(ntt_mint<167772161>::get_m()) M1 = 167772161, M2 = 469762049, M3 = 754974721;
		auto c1 = convolution(std::vector<ntt_mint<M1>>(a.begin(), a.end()),
							  std::vector<ntt_mint<M1>>(b.begin(), b.end()));
		auto c2 = convolution(std::vector<ntt_mint<M2>>(a.begin(), a.end()),
							  std::vector<ntt_mint<M2>>(b.begin(), b.end()));
		auto c3 = convolution(std::vector<ntt_mint<M3>>(a.begin(), a.end()),
							  std::vector<ntt_mint<M3>>(b.begin(), b.end()));
		int n = (int) c1.size();
		a.resize(n);
		for (int i = 0; i < n; i++) {
			a[i] = garner<mint, ntt_mint>(c1[i].get_val(), c2[i].get_val(), c3[i].get_val());
		}
		return a;
	}

	template <typename mint, template <auto...> typename ntt_mint>
	std::vector<mint>& arbitrary_mod_inplace_convolution(std::vector<mint> &a, const std::vector<mint> &b) {
		static constexpr decltype(ntt_mint<167772161>::get_m()) M1 = 167772161, M2 = 469762049, M3 = 754974721;
		auto c1 = convolution(std::vector<ntt_mint<M1>>(a.begin(), a.end()),
							  std::vector<ntt_mint<M1>>(b.begin(), b.end()));
		auto c2 = convolution(std::vector<ntt_mint<M2>>(a.begin(), a.end()),
							  std::vector<ntt_mint<M2>>(b.begin(), b.end()));
		auto c3 = convolution(std::vector<ntt_mint<M3>>(a.begin(), a.end()),
							  std::vector<ntt_mint<M3>>(b.begin(), b.end()));
		int n = (int) c1.size();
		a.resize(n);
		for (int i = 0; i < n; i++) {
			a[i] = garner<mint, ntt_mint>(c1[i].get_val(), c2[i].get_val(), c3[i].get_val());
		}
		return a;
	}

	template<typename T>
	void normalize(std::vector<T> &a) {
		for (int i = (int) a.size() - 1; i >= 0; i--) {
			if (a[i]) {
				a.resize(i + 1);
				return;
			}
		}
		a.clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<998244353>;
	using ntt::inplace_convolution;

	int n;
	cin >> n;

	vector<int> deg(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		deg[--u] += 1;
		deg[--v] += 1;
	}

	struct comp {
		bool operator()(const vector<mint> &a, const vector<mint> &b) const {
			return a.size() > b.size();
		}
	};

	priority_queue<vector<mint>, vector<vector<mint>>, comp> pq;
	for (int u = 0; u < n; u++) {
		pq.push({1, deg[u] - !!u});
	}

	while (pq.size() > 1) {
		auto x = pq.top(); pq.pop();
		auto y = pq.top(); pq.pop();
		inplace_convolution(x, y);
		ntt::normalize(x);
		pq.push(x);
	}

	vector<mint> fact(n + 1); fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = i * fact[i - 1];
	}

	mint ans = 0;
	for (int k = 0; k < (int) pq.top().size(); k++) {
		if (k % 2 == 0) {
			ans += fact[n - k] * pq.top()[k];
		} else {
			ans -= fact[n - k] * pq.top()[k];
		}
	}
	cout << ans << '\n';
	return 0;
}