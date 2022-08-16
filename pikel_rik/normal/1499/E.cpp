#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	int val;
	static_mint(): val() {}
	static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
	static_mint pow(long long n) const { static_mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
	static_mint inv() const { return pow(M - 2); }

	friend static_mint pow(const static_mint &m, long long n) { return m.pow(n); }
	friend static_mint inv(const static_mint &m) { return m.inv(); }

	static_mint operator+() const { static_mint m; m.val = val; return m; }
	static_mint operator-() const { static_mint m; m.val = M - val; return m; }
	static_mint &operator+=(const static_mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
	static_mint &operator-=(const static_mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
	static_mint &operator*=(const static_mint &m) { val = (long long) val * m.val % M; return *this; }
	static_mint &operator/=(const static_mint &m) { val = (long long) val * m.inv().val % M; return *this; }

	friend static_mint operator+ (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) += rhs; }
	friend static_mint operator- (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) -= rhs; }
	friend static_mint operator* (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) *= rhs; }
	friend static_mint operator/ (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) /= rhs; }
	friend bool operator==(const static_mint &lhs, const static_mint &rhs) { return lhs.val == rhs.val; }
	friend bool operator!=(const static_mint &lhs, const static_mint &rhs) { return lhs.val != rhs.val; }

	static_mint &operator++() { return *this += 1; }
	static_mint &operator--() { return *this -= 1; }
	static_mint operator++(int) { static_mint result(*this); *this += 1; return result; }
	static_mint operator--(int) { static_mint result(*this); *this -= 1; return result; }

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<998244353>;

	string x, y;
	cin >> x >> y;

	int n = x.length(), m = y.length();
	x = '$' + x, y = '$' + y;

	vector<vector<array<mint, 2>>> dp(n + 1, vector<array<mint, 2>>(m + 1));

	for (int i = 1; i <= n; i++) {
		dp[i][0][0] = 1;
		if (x[i - 1] != x[i]) {
			dp[i][0][0] += dp[i - 1][0][0];
		}
	}

	for (int j = 1; j <= m; j++) {
		dp[0][j][1] = 1;
		if (y[j - 1] != y[j]) {
			dp[0][j][1] += dp[0][j - 1][1];
	 	}
	}

	mint final = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j][0] += (x[i - 1] != x[i]) * dp[i - 1][j][0];
			dp[i][j][0] += (y[j] != x[i]) * dp[i - 1][j][1];
			dp[i][j][1] += (x[i] != y[j]) * dp[i][j - 1][0];
			dp[i][j][1] += (y[j - 1] != y[j]) * dp[i][j - 1][1];
			if (i != 1)
				dp[i][j][0] += (x[i] != y[j]) * dp[0][j][1];
			if (j != 1)
				dp[i][j][1] += (x[i] != y[j]) * dp[i][0][0];
			final += dp[i][j][0] + dp[i][j][1];
		}
	}
	cout << final << '\n';
	return 0;
}