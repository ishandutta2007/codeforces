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

	using mint = static_mint<1000000007>;

	int n, k;
	cin >> n >> k;

	vector<mint> fact(2 * k + 1); fact[0] = 1;
	for (int i = 1; i <= 2 * k; i++) {
		fact[i] = i * fact[i - 1];
	}

	auto choose = [&](int n, int k) -> mint {
		mint ans = 1;
		for (int i = n; i > n - k; i--) {
			ans *= i;
		}
		ans /= fact[k];
		return ans;
	};

	vector<vector<mint>> C(2 * k, vector<mint>(2 * k));
	for (int i = 0; i < 2 * k; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	vector<vector<mint>> dp(2 * k + 1, vector<mint>(2 * k + 1));

	dp[0][0] = 1;
	for (int i = 1; i <= 2 * k; i++) {
		for (int j = 1; j <= i / 2; j++) {
			for (int len = 2; len <= i; len++) {
				dp[i][j] += C[i - 1][len - 1] * fact[len - 1] * dp[i - len][j - 1];
			}
		}
	}

	array<mint, 2> sum;
	sum[0] += 1;

	for (int s = 1; s <= k; s++) {
		if (s < n) {
			mint add = 0;
			for (int i = s + 1; i <= 2 * k; i++) {
				add += choose(n, i) * dp[i][i - s];
			}
			sum[s % 2] += add;
		}
		cout << sum[s % 2] << ' ';
	}
	cout << '\n';
	return 0;
}