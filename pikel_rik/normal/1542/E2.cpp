#include <bits/stdc++.h>
using namespace std;

struct dynamic_mint {
	static int M;

	static void set_mod(int m) {
		assert(0 < m);
		M = m;
	}

	int val;

	dynamic_mint() : val() {}

	dynamic_mint(long long x) : val(x % M) { if (val < 0) { val += M; }}

	dynamic_mint pow(long long n) const {
		dynamic_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}

	dynamic_mint inv() const { return pow(M - 2); }

	dynamic_mint operator+() const {
		dynamic_mint m;
		m.val = val;
		return m;
	}

	dynamic_mint operator-() const {
		dynamic_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}

	dynamic_mint &operator+=(const dynamic_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}

	dynamic_mint &operator-=(const dynamic_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}

	dynamic_mint &operator*=(const dynamic_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}

	dynamic_mint &operator/=(const dynamic_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}

	friend dynamic_mint operator+(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return dynamic_mint(lhs) += rhs;
	}

	friend dynamic_mint operator-(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return dynamic_mint(lhs) -= rhs;
	}

	friend dynamic_mint operator*(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return dynamic_mint(lhs) *= rhs;
	}

	friend dynamic_mint operator/(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return dynamic_mint(lhs) /= rhs;
	}

	friend bool operator==(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return lhs.val == rhs.val;
	}

	friend bool operator!=(const dynamic_mint &lhs, const dynamic_mint &rhs) {
		return lhs.val != rhs.val;
	}

	dynamic_mint &operator++() {
		return *this += 1;
	}

	dynamic_mint &operator--() {
		return *this -= 1;
	}

	dynamic_mint operator++(int) {
		dynamic_mint result(*this);
		*this += 1;
		return result;
	}

	dynamic_mint operator--(int) {
		dynamic_mint result(*this);
		*this -= 1;
		return result;
	}

	template<typename T>
	explicit operator T() const {
		return T(val);
	}

	friend std::ostream &operator<<(std::ostream &os, const dynamic_mint &m) {
		return os << m.val;
	}

	friend std::istream &operator>>(std::istream &is, dynamic_mint &m) {
		long long x;
		return is >> x, m = x, is;
	}
};

int dynamic_mint::M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = dynamic_mint;

	auto f = [&](int x) -> int {
		return (x * x - x) / 2;
	};

	int n, mod;
	cin >> n >> mod;

	mint::set_mod(mod);

	vector<mint> fact(n + 1); fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = i * fact[i - 1];
	}

	vector<vector<mint>> C(n + 1, vector<mint>(n + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				C[i][j] = 1;
			} else {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
	}

	mint ans = 0;

	vector<mint> dp(1, 1);
	for (int iter = n - 3; iter >= 0; iter--) {
		int m = n - iter - 1;

		vector<mint> new_dp(f(m) + 1);
		mint running_sum = dp[0];
		for (int i = 0; i <= f(m); i++) {
			new_dp[i] = running_sum;
			if (i + 1 <= f(m - 1)) {
				running_sum += dp[i + 1];
			}
			if (i - m + 1 >= 0 && i - m + 1 <= f(m - 1)) {
				running_sum -= dp[i - m + 1];
			}
		}
		dp.swap(new_dp);

		vector<mint> pref(f(m) + 1);
		partial_sum(dp.begin(), dp.end(), pref.begin());

		vector<mint> pref_pref(f(m) + 1);
		partial_sum(pref.begin(), pref.end(), pref_pref.begin());

		mint add = 0, sum = 0;
		for (int i = 0; i <= f(m); i++) {
			if (i >= 2) {
				sum += (m + 1) * pref[i - 2];
				sum -= pref_pref[i - 2];
				if (i - 1 - m - 1 > 0) {
					sum += pref_pref[i - 1 - m - 2];
				}
			}
			add += dp[i] * sum;
//			for (int j = i - 2; j >= 0 && i - j - 1 <= m; j--) {
//				add += (m + 1 - (i - j - 1)) * dp[i] * pref[j]; //i - j - 1 = m, j = i - 1 - m = j
//			}
		}
		ans += C[n][m + 1] * fact[n - m - 1] * add;
	}
	cout << ans << '\n';
	return 0;
}