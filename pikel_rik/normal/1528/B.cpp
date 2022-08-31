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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<998244353>;

	int n;
	cin >> n;

	vector<mint> dp(n + 1, 1), pref(n + 1, 1);

	for (int i = 2; i <= n; i++) {
		dp[i] += 1 + pref[i - 1];
		for (int j = i + i; j <= n; j += i) {
			dp[j] += 1;
		}
		pref[i] = dp[i] + pref[i - 1];
	}
	cout << dp[n] << '\n';
	return 0;
}