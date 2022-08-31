#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	int val;

	static_mint() : val() {}

	static_mint(long long x) : val(x % M) { if (val < 0) val += M; }

	static_mint pow(long long n) const {
		static_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}

	static_mint inv() const {
		return pow(M - 2);
	}

	static_mint operator+() const {
		static_mint m;
		m.val = val;
		return m;
	}

	static_mint operator-() const {
		static_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}

	static_mint &operator+=(const static_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}

	static_mint &operator-=(const static_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}

	static_mint &operator*=(const static_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}

	static_mint &operator/=(const static_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}

	friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) += rhs;
	}

	friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) -= rhs;
	}

	friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) *= rhs;
	}

	friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) /= rhs;
	}

	friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val == rhs.val;
	}

	friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val != rhs.val;
	}

	static_mint &operator++() {
		return *this += 1;
	}

	static_mint &operator--() {
		return *this -= 1;
	}

	static_mint operator++(int) {
		static_mint result(*this);
		*this += 1;
		return result;
	}

	static_mint operator--(int) {
		static_mint result(*this);
		*this -= 1;
		return result;
	}

	template<typename T>
	explicit operator T() const {
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

	constexpr int N = 100;

	vector<vector<mint>> C(N + 1, vector<mint>(N + 1));
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				C[i][j] = 1;
			} else {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<vector<int>> g(n);
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		if (k == 2) {
			cout << n * (n - 1) / 2 << '\n';
			continue;
		}

		mint ans = 0;
		for (int root = 0; root < n; root++) {
			vector<int> cnt(n);
			auto dfs = [&](int u, int p, int d, const auto &self) -> void {
				cnt[d] += 1;
				for (int v : g[u]) {
					if (v != p) {
						self(v, u, d + 1, self);
					}
				}
			};

			vector<vector<int>> cnts;
			cnts.reserve(g[root].size());
			for (int u : g[root]) {
				dfs(u, root, 0, dfs);
				cnts.push_back(cnt);
				fill(cnt.begin(), cnt.end(), 0);
			}

			for (int lvl = 0; lvl < n; lvl++) {
				vector<mint> dp(k + 1);
				dp[0] = 1;
				for (int i = 0; i < (int) g[root].size(); i++) {
					vector<mint> new_dp = dp;
					for (int j = 0; j < k; j++) {
						new_dp[j + 1] += cnts[i][lvl] * dp[j];
					}
					dp.swap(new_dp);
				}
				ans += dp[k];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}