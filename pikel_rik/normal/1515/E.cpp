#include <bits/stdc++.h>
using namespace std;

struct dynamic_mint {
	static int M;
	static void set_mod(int m) { assert(0 < m); M = m; }

	int val;
	dynamic_mint(): val() {}
	dynamic_mint(long long x) : val(x % M) { if (val < 0) { val += M; } }
	dynamic_mint pow(long long n) const { dynamic_mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
	dynamic_mint inv() const { return pow(M - 2); }

	friend dynamic_mint pow(const dynamic_mint &m, long long n) { return m.pow(n); }
	friend dynamic_mint inv(const dynamic_mint &m) { return m.inv(); }

	dynamic_mint operator+() const { dynamic_mint m; m.val = val; return m; }
	dynamic_mint operator-() const { dynamic_mint m; m.val = M - val; return m; }
	dynamic_mint &operator+=(const dynamic_mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
	dynamic_mint &operator-=(const dynamic_mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
	dynamic_mint &operator*=(const dynamic_mint &m) { val = (long long) val * m.val % M; return *this; }
	dynamic_mint &operator/=(const dynamic_mint &m) { val = (long long) val * m.inv().val % M; return *this; }

	friend dynamic_mint operator+ (const dynamic_mint &lhs, const dynamic_mint &rhs) { return dynamic_mint(lhs) += rhs; }
	friend dynamic_mint operator- (const dynamic_mint &lhs, const dynamic_mint &rhs) { return dynamic_mint(lhs) -= rhs; }
	friend dynamic_mint operator* (const dynamic_mint &lhs, const dynamic_mint &rhs) { return dynamic_mint(lhs) *= rhs; }
	friend dynamic_mint operator/ (const dynamic_mint &lhs, const dynamic_mint &rhs) { return dynamic_mint(lhs) /= rhs; }
	friend bool operator==(const dynamic_mint &lhs, const dynamic_mint &rhs) { return lhs.val == rhs.val; }
	friend bool operator!=(const dynamic_mint &lhs, const dynamic_mint &rhs) { return lhs.val != rhs.val; }

	dynamic_mint &operator++() { return *this += 1; }
	dynamic_mint &operator--() { return *this -= 1; }
	dynamic_mint operator++(int) { dynamic_mint result(*this); *this += 1; return result; }
	dynamic_mint operator--(int) { dynamic_mint result(*this); *this -= 1; return result; }

	template <typename T> explicit operator T() const { return T(val); }

	friend std::ostream &operator<<(std::ostream &os, const dynamic_mint &m) {
		return os << m.val;
	}

	friend std::istream &operator>>(std::istream &is, dynamic_mint &m) {
		long long x; is >> x; m = x;
		return is;
	}
};

int dynamic_mint::M;

template <typename>
struct is_mint : public std::false_type { };

template <>
struct is_mint<dynamic_mint> : public std::true_type { };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = dynamic_mint;

	int n, M;
	cin >> n >> M;

	mint::set_mod(M);

	vector<mint> fact(n + 1); fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = i * fact[i - 1];
	}

	vector<vector<mint>> dp(n + 1, vector<mint>(n + 1));
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] += j * dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	mint ans = mint(2).pow(n - 1);
	for (int holes = 1; n - 2 * holes - 1 >= 0; holes++) {
		ans += mint(2).pow(n - 2 * holes - 1) * fact[holes + 1] * dp[n - holes][holes + 1];
	}
	cout << ans << '\n';
	return 0;
}