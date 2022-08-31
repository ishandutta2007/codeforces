#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	int val;

	static_mint() : val() {}

	static_mint(long long x) : val(x % M) { if (val < 0) val += M; }

	static_mint pow(long long n) const {
		static_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}

	static_mint inv() const {
		return pow(M - 2);
	}

	static_mint operator+() const {
		static_mint m;
		m.val = val;
		return m;
	}

	static_mint operator-() const {
		static_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}

	static_mint &operator+=(const static_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}

	static_mint &operator-=(const static_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}

	static_mint &operator*=(const static_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}

	static_mint &operator/=(const static_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}

	friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) += rhs;
	}

	friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) -= rhs;
	}

	friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) *= rhs;
	}

	friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) /= rhs;
	}

	friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val == rhs.val;
	}

	friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val != rhs.val;
	}

	static_mint &operator++() {
		return *this += 1;
	}

	static_mint &operator--() {
		return *this -= 1;
	}

	static_mint operator++(int) {
		static_mint result(*this);
		*this += 1;
		return result;
	}

	static_mint operator--(int) {
		static_mint result(*this);
		*this -= 1;
		return result;
	}

	template<typename T>
	explicit operator T() const {
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

template <typename>
struct is_mint_helper : std::false_type { };

template <int M>
struct is_mint_helper<static_mint<M>> : std::true_type { };

template <typename T>
struct is_mint : is_mint_helper<typename std::decay<T>::type> { };

namespace ntt {
	template<int P>
	struct prime_info {
		constexpr static int root = 0, root_pw = 0;
	};

	template<>
	struct prime_info<7340033> {
		constexpr static int root = 5, root_pw = 1 << 20;
	};

	template<>
	struct prime_info<998244353> {
		constexpr static int root = 15311432, root_pw = 1 << 23;
	};

	template<>
	struct prime_info<754974721> {
		constexpr static int root = 739831874, root_pw = 1 << 24;
	};

	template<>
	struct prime_info<167772161> {
		constexpr static int root = 243, root_pw = 1 << 25;
	};

	template<>
	struct prime_info<469762049> {
		constexpr static int root = 2187, root_pw = 1 << 26;
	};

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

	template<int M>
	std::vector<static_mint<M>> root = {0, 1};

	template<int M>
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

	template<int M>
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

	template<int M>
	static_mint<M> garner(int a1, int a2, int a3) {
		constexpr static int M1 = 754974721, M2 = 167772161, M3 = 469762049;
		const static int R12 = static_mint<M2>(M1).inv().val;
		const static int R13 = static_mint<M3>(M1).inv().val;
		const static int R23 = static_mint<M3>(M2).inv().val;
		int x1 = a1;
		int x2 = (long long) (a2 - x1) * R12 % M2;
		if (x2 < 0) x2 += M2;
		int x3 = ((long long) (a3 - x1) * R13 % M3 - x2) * R23 % M3;
		if (x3 < 0) x3 += M3;
		return static_mint<M>(x1) + static_mint<M>(x2) * M1 + static_mint<M>(x3) * M1 * M2;
	}

	template<int M>
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

	template<int M = 998244353, typename T>
	std::enable_if_t<!is_mint<T>::value, std::vector<T>>
	convolution(const std::vector<T> &a, const std::vector<T> &b) {
		auto f = convolution(std::vector<static_mint<M>>(a.begin(), a.end()),
							 std::vector<static_mint<M>>(b.begin(), b.end()));
		return vector<T>(f.begin(), f.end());
	}

	template<typename T>
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

	using mint = static_mint<998244353>;
	using ntt::convolution;

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int q;
	cin >> q;

	while (q--) {
		int t, x;
		cin >> t;

		vector<mint> b(a.begin(), a.end());
		if (t == 1) {
			int i, d;
			cin >> x >> i >> d, --i;
			b[i] = d;
		} else {
			int l, r, d;
			cin >> x >> l >> r >> d, --l, --r;
			for (int i = l; i <= r; i++) {
				b[i] += d;
			}
		}

		for (auto &y : b) {
			y = x - y;
		}

		vector<vector<mint>> tree(2 * n);
		for (int i = 0; i < n; i++) {
			tree[i + n] = {1, b[i]};
		}

		for (int i = n - 1; i > 0; i--) {
			tree[i].swap(tree[i << 1]);
			tree[i] = convolution(tree[i], tree[i << 1 | 1]);
		}

		cout << tree[1][k] << '\n';
	}
	return 0;
}