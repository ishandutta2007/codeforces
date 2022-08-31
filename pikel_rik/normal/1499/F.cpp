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

	int n, k;
	cin >> n >> k;

	vector<vector<int>> g(n);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> mx_d(n);
	auto dfs = [&](int u, int p, const auto &self) -> vector<array<mint, 2>> {
		vector<array<mint, 2>> dp(n);
		dp[0][0] = 1, mx_d[u] = 0;
		for (int v : g[u]) {
			if (v != p) {
				auto dpv = self(v, u, self);
				vector<array<mint, 2>> new_dp(n);
				for (int i = 0; i <= mx_d[u]; i++) {
					for (int j = 0; j <= mx_d[v]; j++) {
						//im using the edge
						if (i + j + 1 > k) {
							new_dp[max(i, j + 1)][1] += (dp[i][0] + dp[i][1]) * (dpv[j][0] + dpv[j][1]);
						} else {
							new_dp[max(i, j + 1)][1] += (dp[i][0] + dp[i][1]) * (dpv[j][0] + dpv[j][1]) - dp[i][0] * dpv[j][0];
							new_dp[max(i, j + 1)][0] += dp[i][0] * dpv[j][0];
						}
						//im not using the edge
						new_dp[i][1] += (dp[i][0] + dp[i][1]) * (dpv[j][0] + dpv[j][1]) - dp[i][0] * dpv[j][0];
						new_dp[i][0] += dp[i][0] * dpv[j][0];
					}
				}
				mx_d[u] = max(mx_d[u], 1 + mx_d[v]);
				dp.swap(new_dp);
			}
		}
		return dp;
	};

	auto dp = dfs(0, -1, dfs);

	mint ans = mint(2).pow(n - 1);
	for (int i = 0; i < n; i++) {
		ans -= dp[i][1];
	}
	cout << ans << '\n';
	return 0;
}