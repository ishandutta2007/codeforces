#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template<typename T>
struct matrix {
	int n, m;
	vector<vector<T>> mat;

	matrix() : n(), m() {}
	matrix(int n, int m, const T val = T()) : n(n), m(m), mat(n, vector<T>(m, val)) {}
	matrix(initializer_list<vector<T>> list): mat(list) {
		n = mat.size();
		m = mat.front().size();
	}

	matrix operator+(const matrix &rhs) {
		matrix res(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = mat[i][j] + rhs[i][j];
		return res;
	}

	matrix operator-(const matrix &rhs) {
		matrix res(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i][j] = mat[i][j] - rhs[i][j];
		return res;
	}

	matrix operator*(const matrix &rhs) {
		matrix res(n, rhs.m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < rhs.m; j++)
				for (int k = 0; k < m; k++) res[i][j] += mat[i][k] * rhs[k][j];
		return res;
	}

	matrix operator+=(const matrix &rhs) { return *this = *this + rhs; }
	matrix operator-=(const matrix &rhs) { return *this = *this - rhs; }
	matrix operator*=(const matrix &rhs) { return *this = *this * rhs; }

	vector<T> &operator[](int idx) { return mat[idx]; }
	const vector<T> &operator[](int idx) const { return mat[idx]; }
};

namespace modular {
#define MODULAR

	template <typename>
	struct is_modular : std::false_type { };

	template <typename>
	struct modulus : std::integral_constant<int, 0> { };

	template<int M>
	struct static_mint {
		static_assert(0 < M, "Module M must be positive");

		int val;
		static_mint(): val() {}
		static_mint(long long x) : val(x % M) { if (val < 0) { val += M; } }
		static_mint pow(long long n) const { static_mint ans = 1, x = val; while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		static_mint inv() const { return pow(M - 2); }

		static_mint operator+() const { static_mint m; m.val = val; return m; }
		static_mint operator-() const { static_mint m; m.val = M - val; return m; }
		static_mint &operator+=(const static_mint &m) { val += m.val; if (val >= M) val -= M; return *this; }
		static_mint &operator-=(const static_mint &m) { val -= m.val; if (val < 0) val += M; return *this; }
		static_mint &operator*=(const static_mint &m) { val = (long long) val * m.val % M; return *this; }
		static_mint &operator/=(const static_mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		template <typename T> friend static_mint operator+ (T lhs, const static_mint &m) { return static_mint(lhs) += m; }
		template <typename T> friend static_mint operator- (T lhs, const static_mint &m) { return static_mint(lhs) -= m; }
		template <typename T> friend static_mint operator* (T lhs, const static_mint &m) { return static_mint(lhs) *= m; }
		template <typename T> friend static_mint operator/ (T lhs, const static_mint &m) { return static_mint(lhs) /= m; }
		template <typename T> friend static_mint operator==(T lhs, const static_mint &m) { return static_mint(lhs).val == m.val; }
		template <typename T> friend static_mint operator!=(T lhs, const static_mint &m) { return static_mint(lhs).val != m.val; }

		static_mint &operator++() { return *this += 1; }
		static_mint &operator--() { return *this -= 1; }
		static_mint operator++(int) { static_mint result(*this); *this += 1; return result; }
		static_mint operator--(int) { static_mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const {
			return T(val);
		}

		friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
			os << m.val;
			return os;
		}

		friend std::istream &operator>>(std::istream &is, static_mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	template <int M>
	struct is_modular<static_mint<M>> : std::true_type { };

	template <int M>
	struct modulus<static_mint<M>> : std::integral_constant<int, M> { };

	struct dynamic_mint {
		static int M;
		static void set_mod(int m) { assert(0 < m); M = m; }

		int val;
		dynamic_mint(): val() {}
		dynamic_mint(long long x) : val(x % M) { if (val < 0) { val += M; } }
		dynamic_mint pow(long long n) const { dynamic_mint ans = 1, x = val; while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		dynamic_mint inv() const { return pow(M - 2); }

		dynamic_mint operator+() const { dynamic_mint m; m.val = val; return m; }
		dynamic_mint operator-() const { dynamic_mint m; m.val = M - val; return m; }
		dynamic_mint &operator+=(const dynamic_mint &m) { val += m.val; if (val >= M) val -= M; return *this; }
		dynamic_mint &operator-=(const dynamic_mint &m) { val -= m.val; if (val < 0) val += M; return *this; }
		dynamic_mint &operator*=(const dynamic_mint &m) { val = (long long) val * m.val % M; return *this; }
		dynamic_mint &operator/=(const dynamic_mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		template <typename T> friend dynamic_mint operator+ (T lhs, const dynamic_mint &m) { return dynamic_mint(lhs) += m; }
		template <typename T> friend dynamic_mint operator- (T lhs, const dynamic_mint &m) { return dynamic_mint(lhs) -= m; }
		template <typename T> friend dynamic_mint operator* (T lhs, const dynamic_mint &m) { return dynamic_mint(lhs) *= m; }
		template <typename T> friend dynamic_mint operator/ (T lhs, const dynamic_mint &m) { return dynamic_mint(lhs) /= m; }
		template <typename T> friend dynamic_mint operator==(T lhs, const dynamic_mint &m) { return dynamic_mint(lhs).val == m.val; }
		template <typename T> friend dynamic_mint operator!=(T lhs, const dynamic_mint &m) { return dynamic_mint(lhs).val != m.val; }

		dynamic_mint &operator++() { return *this += 1; }
		dynamic_mint &operator--() { return *this -= 1; }
		dynamic_mint operator++(int) { dynamic_mint result(*this); *this += 1; return result; }
		dynamic_mint operator--(int) { dynamic_mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const { return T(val); }

		friend std::ostream &operator<<(std::ostream &os, const dynamic_mint &m) {
			os << m.val;
			return os;
		}

		friend std::istream &operator>>(std::istream &is, dynamic_mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	int dynamic_mint::M;

	template <>
	struct is_modular<dynamic_mint> : std::true_type { };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = modular::dynamic_mint;

	int m; ll l, r, k;
	cin >> m >> l >> r >> k;
	mint::set_mod(m);

	auto f = [&](ll x) {
		return r / x - (l - 1) / x;
	};

	auto fib = [&](ll n) {
		--n;
		matrix<mint> m = {{1, 1}, {1, 0}}, res = {{1, 0}, {0, 1}};
		while (n) {
			if (n & 1) res *= m;
			m *= m;
			n /= 2;
		}
		return res[0][0];
	};

	ll ans = 1;

	for (ll i = r; i > 1;) {
		if (f(i) >= k) {
			ans = max(ans, i);
		}
		ll lo = 1, hi = i;
		while (lo < hi) {
			ll mid = lo + (hi - lo + 1) / 2;
			if (r / mid > r / i)
				lo = mid;
			else hi = mid - 1;
		}
		i = lo;
	}

	cout << fib(ans) << '\n';
	return 0;
}