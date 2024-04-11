#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

namespace modular {
#define MODULAR

	template<int M>
	struct static_mint {
		static_assert(0 < M, "Module M must be positive");

		int val;
		static_mint(): val() {}
		static_mint(long long x) : val(x % M) { if (val < 0) { val += M; } }
		static_mint pow(long long n) const { static_mint ans = 1, x = val; while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		static_mint inv() const { return pow(M - 2); }

		static_mint operator+ () const { static_mint m; m.val = val; return m; };
		static_mint operator- () const { static_mint m; m.val = M - val; return m; }
		static_mint operator+ (static_mint m) const { m.val += val; if (m.val >= M) m.val -= M; return m; }
		static_mint operator- (static_mint m) const { m.val = val - m.val; if (m.val < 0) m.val += M; return m; }
		static_mint operator* (static_mint m) const { m.val = m.val * (long long) val % M; return m; }
		static_mint operator/ (static_mint m) const { return *this * m.inv(); }
		static_mint &operator+=(const static_mint &m) { val += m.val; if (val >= M) val -= M; return *this; }
		static_mint &operator-=(const static_mint &m) { val -= m.val; if (val < 0) val += M; return *this; }
		static_mint &operator*=(const static_mint &m) { val = (long long) val * m.val % M; return *this; }
		static_mint &operator/=(const static_mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend static_mint operator+(int lhs, const static_mint &m) { return static_mint(lhs) + m; }
		friend static_mint operator-(int lhs, const static_mint &m) { return static_mint(lhs) - m; }
		friend static_mint operator*(int lhs, const static_mint &m) { return static_mint(lhs) * m; }
		friend static_mint operator/(int lhs, const static_mint &m) { return static_mint(lhs) / m; }
		friend static_mint operator+(long long lhs, const static_mint &m) { return static_mint(lhs) + m; }
		friend static_mint operator-(long long lhs, const static_mint &m) { return static_mint(lhs) - m; }
		friend static_mint operator*(long long lhs, const static_mint &m) { return static_mint(lhs) * m; }
		friend static_mint operator/(long long lhs, const static_mint &m) { return static_mint(lhs) / m; }

		bool operator==(const static_mint &m) const { return val == m.val; }
		bool operator!=(const static_mint &m) const { return val != m.val; }
		template <typename T> explicit operator T() const { return val; }

		friend ostream &operator<<(ostream &os, const static_mint &m) {
			os << m.val;
			return os;
		}
		friend istream &operator>>(istream &is, static_mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	struct dynamic_mint {
		static int M;
		static void set_mod(int m) { assert(0 < m); M = m; }

		int val;
		dynamic_mint(): val() {}
		dynamic_mint(long long x) : val(x % M) { if (val < 0) { val += M; } }
		dynamic_mint pow(long long n) const { dynamic_mint ans = 1, x = val; while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		dynamic_mint inv() const { return pow(M - 2); }

		dynamic_mint operator+ () const { dynamic_mint m; m.val = val; return m; };
		dynamic_mint operator- () const { dynamic_mint m; m.val = M - val; return m; }
		dynamic_mint operator+ (dynamic_mint m) const { m.val += val; if (m.val >= M) m.val -= M; return m; }
		dynamic_mint operator- (dynamic_mint m) const { m.val = val - m.val; if (m.val < 0) m.val += M; return m; }
		dynamic_mint operator* (dynamic_mint m) const { m.val = m.val * (long long) val % M; return m; }
		dynamic_mint operator/ (dynamic_mint m) const { return *this * m.inv(); }
		dynamic_mint &operator+=(const dynamic_mint &m) { val += m.val; if (val >= M) val -= M; return *this; }
		dynamic_mint &operator-=(const dynamic_mint &m) { val -= m.val; if (val < 0) val += M; return *this; }
		dynamic_mint &operator*=(const dynamic_mint &m) { val = (long long) val * m.val % M; return *this; }
		dynamic_mint &operator/=(const dynamic_mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend dynamic_mint operator+(int lhs, const dynamic_mint &m) { return dynamic_mint(lhs) + m; }
		friend dynamic_mint operator-(int lhs, const dynamic_mint &m) { return dynamic_mint(lhs) - m; }
		friend dynamic_mint operator*(int lhs, const dynamic_mint &m) { return dynamic_mint(lhs) * m; }
		friend dynamic_mint operator/(int lhs, const dynamic_mint &m) { return dynamic_mint(lhs) / m; }
		friend dynamic_mint operator+(long long lhs, const dynamic_mint &m) { return dynamic_mint(lhs) + m; }
		friend dynamic_mint operator-(long long lhs, const dynamic_mint &m) { return dynamic_mint(lhs) - m; }
		friend dynamic_mint operator*(long long lhs, const dynamic_mint &m) { return dynamic_mint(lhs) * m; }
		friend dynamic_mint operator/(long long lhs, const dynamic_mint &m) { return dynamic_mint(lhs) / m; }

		bool operator==(const dynamic_mint &m) const { return val == m.val; }
		bool operator!=(const dynamic_mint &m) const { return val != m.val; }
		template <typename T> explicit operator T() const { return val; }

		friend ostream &operator<<(ostream &os, const dynamic_mint &m) {
			os << m.val;
			return os;
		}
		friend istream &operator>>(istream &is, dynamic_mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	template <typename>
	struct is_modular : public false_type { };

	template <int M>
	struct is_modular<static_mint<M>> : public true_type { };

	template <>
	struct is_modular<dynamic_mint> : public true_type { };
}

using mint = modular::static_mint<mod>;

int n;
mint dp[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	//(1/2) ((1/1)dp[n - 1] + (1/4)dp[n - 3] + (1/16)dp[n - 5] + ... +

	dp[0] = 1;
	dp[1] = mint(2).inv();

	mint pref[2];
	pref[0] = dp[0], pref[1] = dp[1];

	mint inv_2 = mint(2).inv(), inv_4 = inv_2 * inv_2;

	for (int i = 2; i <= n; i++) {
		dp[i] = inv_2 * pref[1 - i % 2];
		pref[i & 1] = dp[i] + inv_4 * pref[i % 2];
	}
	cout << dp[n] << '\n';
	return 0;
}