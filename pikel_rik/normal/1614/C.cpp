#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	constexpr static auto get_m() {
		return M;
	}

	int val;

	constexpr static_mint() : val() {}

	constexpr static_mint(long long x) : val(x % M) { if (val < 0) val += M; }

	constexpr static_mint pow(long long n) const {
		static_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}

	constexpr static_mint inv() const {
		return pow(M - 2);
	}

	constexpr static_mint operator+() const {
		static_mint m;
		m.val = val;
		return m;
	}

	constexpr static_mint operator-() const {
		static_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}

	constexpr static_mint &operator+=(const static_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}

	constexpr static_mint &operator-=(const static_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}

	constexpr static_mint &operator*=(const static_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}

	constexpr static_mint &operator/=(const static_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}

	constexpr friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) += rhs;
	}

	constexpr friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) -= rhs;
	}

	constexpr friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) *= rhs;
	}

	constexpr friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) /= rhs;
	}

	constexpr friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val == rhs.val;
	}

	constexpr friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val != rhs.val;
	}

	constexpr static_mint &operator++() {
		return *this += 1;
	}

	constexpr static_mint &operator--() {
		return *this -= 1;
	}

	constexpr static_mint operator++(int) {
		static_mint result(*this);
		*this += 1;
		return result;
	}

	constexpr static_mint operator--(int) {
		static_mint result(*this);
		*this -= 1;
		return result;
	}

	template<typename T>
	constexpr explicit operator T() const {
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<1000000007>;

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> prefix(30, vector<int>(n));

		while (m--) {
			int l, r, x;
			cin >> l >> r >> x, --l, --r;
			for (int j = 0; j < 30; j++) {
				if (!(x >> j & 1)) {
					prefix[j][l] += 1;
					if (r + 1 < n) {
						prefix[j][r + 1] -= 1;
					}
				}
			}
		}

		mint ans = 0;
		for (int j = 0; j < 30; j++) {
			partial_sum(prefix[j].begin(), prefix[j].end(), prefix[j].begin());
			array<mint, 2> dp = {1, 0};
			for (int i = 0; i < n; i++) {
				array<mint, 2> new_dp = {0, 0};
				if (prefix[j][i] == 0) {
					new_dp[0] = dp[0] + dp[1];
					new_dp[1] = dp[0] + dp[1];
				} else {
					new_dp[0] = 2 * dp[0];
					new_dp[1] = 2 * dp[1];
				}
				dp.swap(new_dp);
			}
			ans += mint(1 << j) * dp[1];
		}

		cout << ans << '\n';
	}
	return 0;
}