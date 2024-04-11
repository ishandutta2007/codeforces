#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	int val;
	constexpr static_mint(): val() {}
	constexpr static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
	constexpr static_mint pow(long long n) const { static_mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
	constexpr static_mint inv() const { return pow(M - 2); }

	constexpr friend static_mint pow(const static_mint &m, long long n) { return m.pow(n); }
	constexpr friend static_mint inv(const static_mint &m) { return m.inv(); }

	constexpr static_mint operator+() const { static_mint m; m.val = val; return m; }
	constexpr static_mint operator-() const { static_mint m; m.val = M - val; return m; }
	constexpr static_mint &operator+=(const static_mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
	constexpr static_mint &operator-=(const static_mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
	constexpr static_mint &operator*=(const static_mint &m) { val = (long long) val * m.val % M; return *this; }
	constexpr static_mint &operator/=(const static_mint &m) { val = (long long) val * m.inv().val % M; return *this; }

	constexpr friend static_mint operator+ (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) += rhs; }
	constexpr friend static_mint operator- (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) -= rhs; }
	constexpr friend static_mint operator* (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) *= rhs; }
	constexpr friend static_mint operator/ (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) /= rhs; }
	constexpr friend bool operator==(const static_mint &lhs, const static_mint &rhs) { return lhs.val == rhs.val; }
	constexpr friend bool operator!=(const static_mint &lhs, const static_mint &rhs) { return lhs.val != rhs.val; }

	constexpr static_mint &operator++() { return *this += 1; }
	constexpr static_mint &operator--() { return *this -= 1; }
	constexpr static_mint operator++(int) { static_mint result(*this); *this += 1; return result; }
	constexpr static_mint operator--(int) { static_mint result(*this); *this -= 1; return result; }

	template <typename T> explicit operator T() const { return T(val); }

	friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
		return os << m.val;
	}

	friend std::istream &operator>>(std::istream &is, static_mint &m) {
		long long x; is >> x; m = x;
		return is;
	}
};

template <typename>
struct is_mint : public std::false_type { };

template <int M>
struct is_mint<static_mint<M>> : public std::true_type { };

namespace ntt {
	template <int P>
	struct prime_info {
		constexpr static int root = 0, root_pw = 0;
	};

	template <> struct prime_info<7340033>   { constexpr static int root = 5, root_pw = 1 << 20; };
	template <> struct prime_info<998244353> { constexpr static int root = 15311432, root_pw = 1 << 23; };
	template <> struct prime_info<754974721> { constexpr static int root = 739831874, root_pw = 1 << 24; };
	template <> struct prime_info<167772161> { constexpr static int root = 243, root_pw = 1 << 25; };
	template <> struct prime_info<469762049> { constexpr static int root = 2187, root_pw = 1 << 26; };

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

	template <int M>
	std::vector<static_mint<M>> root = {0, 1};

	template <int M>
	void compute_roots(int lg) {
		static int computed = 1;
		if (lg <= computed) return;
		root<M>.resize(1 << lg);
		for (int k = computed; k < lg; k++) {
			static_mint<M> z(prime_info<M>::root);
			for (int i = (1 << (k + 1)); i < prime_info<M>::root_pw; i <<= 1) {
				z *= z;
			}
			for (int i = (1 << (k - 1)); i < (1 << k); i++) {
				root<M>[i << 1] = root<M>[i];
				root<M>[i << 1 | 1] = root<M>[i] * z;
			}
		}
	}

	template<int M>
	void ntt(std::vector<static_mint<M>> &a) {
		int n = int(a.size()), lg = 32 - __builtin_clz(n) - 1;
		compute_bit_reverse(lg);
		compute_roots<M>(lg);
		int shift = 31 - lg;
		for (int i = 0; i < n; i++) {
			if (i < (rev[i] >> shift)) {
				std::swap(a[i], a[rev[i] >> shift]);
			}
		}
		for (int k = 1; k < n; k <<= 1) {
			static_mint<M> wl = prime_info<M>::root;
			for (int i = 2 * k; i < prime_info<M>::root_pw; i <<= 1) {
				wl *= wl;
			}
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; j++) {
					static_mint<M> z = root<M>[j + k] * a[i + j + k];
					a[i + j + k] = a[i + j] - z;
					a[i + j] = a[i + j] + z;
				}
			}
		}
	}

	template <int M>
	std::enable_if_t<prime_info<M>::root != 0, std::vector<static_mint<M>>>
	convolution(std::vector<static_mint<M>> a, std::vector<static_mint<M>> b) {
		int n = 1;
		while (n < a.size() + b.size()) {
			n <<= 1;
		}
		a.resize(n);
		b.resize(n);
		ntt(a), ntt(b);
		static_mint<M> n_inv = static_mint<M>(n).inv();
		for (int i = 0; i < n; i++) {
			a[i] *= b[i] * n_inv;
		}
		reverse(a.begin() + 1, a.end());
		ntt(a);
		return a;
	}

	template <int M>
	static_mint<M> garner(int a1, int a2, int a3) {
		constexpr static int M1 = 754974721, M2 = 167772161, M3 = 469762049;
		constexpr static int R12 = static_mint<M2>(M1).inv().val;
		constexpr static int R13 = static_mint<M3>(M1).inv().val;
		constexpr static int R23 = static_mint<M3>(M2).inv().val;
		int x1 = a1;
		int x2 = (long long)(a2 - x1) * R12 % M2; if (x2 < 0) x2 += M2;
		int x3 = ((long long)(a3 - x1) * R13 % M3 - x2) * R23 % M3; if (x3 < 0) x3 += M3;
		return static_mint<M>(x1) + static_mint<M>(x2) * M1 + static_mint<M>(x3) * M1 * M2;
	}

	template <int M>
	std::enable_if_t<prime_info<M>::root == 0, std::vector<static_mint<M>>>
	convolution(std::vector<static_mint<M>> a, const std::vector<static_mint<M>> &b) {
		constexpr static int M1 = 754974721, M2 = 167772161, M3 = 469762049;
		auto c1 = convolution(vector<static_mint<M1>>(a.begin(), a.end()), vector<static_mint<M1>>(b.begin(), b.end()));
		auto c2 = convolution(vector<static_mint<M2>>(a.begin(), a.end()), vector<static_mint<M2>>(b.begin(), b.end()));
		auto c3 = convolution(vector<static_mint<M3>>(a.begin(), a.end()), vector<static_mint<M3>>(b.begin(), b.end()));
		int n = int(c1.size());
		a.resize(n);
		for (int i = 0; i < n; i++) {
			a[i] = garner<M>(c1[i].val, c2[i].val, c3[i].val);
		}
		return a;
	}

	template <int M, typename T>
	std::enable_if_t<!is_mint<T>::value, std::vector<T>>
	convolution(const std::vector<T> &a, const std::vector<T> &b) {
		auto f = convolution(std::vector<static_mint<M>>(a.begin(), a.end()), std::vector<static_mint<M>>(b.begin(), b.end()));
		return vector<T>(f.begin(), f.end());
	}

	template <typename T>
	void normalize(const std::vector<T> &a) {
		for (int i = int(a.size()) - 1; i >= 0; i--) {
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

	auto is_lucky = [&](int x) -> bool {
		bool f = true;
		for (; x; x /= 10) {
			f &= x % 10 == 4 || x % 10 == 7;
		}
		return f;
	};

	using mint = static_mint<1000000007>;

	int n, k;
	cin >> n >> k;

	vector<mint> fact(n + 1), inv(n + 1);
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = i * fact[i - 1];
		inv[i] = fact[i].inv();
	}

	auto choose = [&](int n, int k) -> mint {
		if (0 <= n && 0 <= k && k <= n)
			return fact[n] * inv[n - k] * inv[k];
		return 0;
	};

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<vector<mint>> poly;

	map<int, int> cnt;
	int not_lucky = 0;

	for (auto &x : a) {
		if (is_lucky(x)) {
			cnt[x]++;
		} else not_lucky += 1;
	}

	for (auto &[x, c] : cnt) {
		poly.push_back({1, c});
	}

	for (int sz = int(poly.size()); sz > 1; sz /= 2) {
		for (int i = 0; i < sz / 2; i++) {
			poly[i] = ntt::convolution(poly[2 * i], poly[2 * i + 1]);
		}
		if (sz % 2 != 0) {
			poly[sz / 2].swap(poly[sz - 1]);
			sz += 1;
		}
	}

	if (poly.empty()) {
		cout << choose(n, k) << '\n';
		return 0;
	}

	mint ans = 0;
	for (int i = 0; i < int(poly[0].size()); i++) {
		ans += choose(not_lucky, k - i) * poly[0][i];
	}
	cout << ans << '\n';
	return 0;
}