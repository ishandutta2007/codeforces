#include <bits/stdc++.h>
using namespace std;

namespace modular {
	template <typename>
	struct is_modular : std::false_type { };

	template<int M>
	struct static_mint {
		static_assert(0 < M, "Module must be positive");

		using mint = static_mint;
		constexpr static int get_mod() { return M; }

		int val;
		static_mint(): val() {}
		static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
		mint pow(long long n) const { mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		mint inv() const { return pow(M - 2); }

		friend mint pow(const mint &m, long long n) { return m.pow(n); }
		friend mint inv(const mint &m) { return m.inv(); }

		mint operator+() const { mint m; m.val = val; return m; }
		mint operator-() const { mint m; m.val = M - val; return m; }
		mint &operator+=(const mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
		mint &operator-=(const mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
		mint &operator*=(const mint &m) { val = (long long) val * m.val % M; return *this; }
		mint &operator/=(const mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend mint operator+ (const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
		friend mint operator- (const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
		friend mint operator* (const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
		friend mint operator/ (const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
		friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.val == rhs.val; }
		friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.val != rhs.val; }

		mint &operator++() { return *this += 1; }
		mint &operator--() { return *this -= 1; }
		mint operator++(int) { mint result(*this); *this += 1; return result; }
		mint operator--(int) { mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const { return T(val); }

		friend std::ostream &operator<<(std::ostream &os, const mint &m) {
			return os << m.val;
		}

		friend std::istream &operator>>(std::istream &is, mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	template <int M>
	struct is_modular<static_mint<M>> : std::true_type { };

	struct dynamic_mint {
		static int M;
		static void set_mod(int m) { assert(0 < m); M = m; }
		static int get_mod() { return M; }

		using mint = dynamic_mint;

		int val;
		dynamic_mint(): val() {}
		dynamic_mint(long long x) : val(x % M) { if (val < 0) { val += M; } }
		mint pow(long long n) const { mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		mint inv() const { return pow(M - 2); }

		friend mint pow(const mint &m, long long n) { return m.pow(n); }
		friend mint inv(const mint &m) { return m.inv(); }

		mint operator+() const { mint m; m.val = val; return m; }
		mint operator-() const { mint m; m.val = M - val; return m; }
		mint &operator+=(const mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
		mint &operator-=(const mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
		mint &operator*=(const mint &m) { val = (long long) val * m.val % M; return *this; }
		mint &operator/=(const mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend mint operator+ (const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
		friend mint operator- (const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
		friend mint operator* (const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
		friend mint operator/ (const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
		friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.val == rhs.val; }
		friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.val != rhs.val; }

		mint &operator++() { return *this += 1; }
		mint &operator--() { return *this -= 1; }
		mint operator++(int) { mint result(*this); *this += 1; return result; }
		mint operator--(int) { mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const { return T(val); }

		friend std::ostream &operator<<(std::ostream &os, const mint &m) {
			return os << m.val;
		}

		friend std::istream &operator>>(std::istream &is, mint &m) {
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

	using mint = modular::static_mint<1000000007>;

	int n, k, q;
	cin >> n >> k >> q;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<vector<mint>> dp(n, vector<mint>(k + 1));
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) dp[j][i] += dp[j + 1][i - 1];
			if (j > 0) dp[j][i] += dp[j - 1][i - 1];
		}
	}

	vector<mint> w(n);
	for (int j = 0; j < n; j++) {
		for (int i = 0; i <= k; i++) {
			w[j] += dp[j][i] * dp[j][k - i];
		}
	}

	mint ans = 0;
	for (int i = 0; i < n; i++) {
		ans += w[i] * a[i];
	}

	for (int i, x; q > 0; q--) {
		cin >> i >> x, --i;
		ans -= w[i] * a[i];
		a[i] = x;
		ans += w[i] * a[i];
		cout << ans << '\n';
	}
	return 0;
}