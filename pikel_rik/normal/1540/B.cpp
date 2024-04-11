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

	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i + 1 < n; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<vector<mint>> dp_outer(n, vector<mint>(n));

	mint inv2 = mint(2).inv(), invn = mint(n).inv();

	for (int m = 1; m <= n; m++) {
		vector<vector<mint>> dp_inner(n, vector<mint>(n));
		for (int l = m - 1; l > 0; l--) {
			for (int i = 0; i + l <= m; i++) {
				int j = i + l - 1;
				if (i == 0) {
					dp_inner[i][j] = 1;
				} else if (j + 1 == m) {
					dp_inner[i][j] = 0;
				} else {
					dp_inner[i][j] += inv2 * dp_inner[i - 1][j];
					dp_inner[i][j] += inv2 * dp_inner[i][j + 1];
				}
			}
		}
		for (int j = 0; j < m; j++) {
			dp_outer[m - 1][j] = dp_inner[j][j];
		}
	}

	mint ans = 0;
	for (int s = 0; s < n; s++) {
		vector<int> sz(n), d(n);
		auto dfs = [&](int u, int p, const auto &self) -> void {
			sz[u] = 1;
			for (int v : g[u]) {
				if (v != p) {
					d[v] = 1 + d[u];
					self(v, u, self);
					sz[u] += sz[v];
				}
			}
		};

		dfs(s, -1, dfs);

		vector<int> lvl(n);
		auto reroot = [&](int u, int p, const auto &self) -> void {
			lvl[d[u]] += sz[u];
			if (u > s) {
				for (int i = 0; i <= d[u]; i++) {
					ans += lvl[i] * invn * dp_outer[d[u]][d[u] - i];
				}
			}
			for (int v : g[u]) {
				if (v != p) {
					lvl[d[u]] -= sz[v];
					self(v, u, self);
					lvl[d[u]] += sz[v];
				}
			}
			lvl[d[u]] -= sz[u];
		};

		reroot(s, -1, reroot);
	}
	cout << ans << '\n';
	return 0;
}