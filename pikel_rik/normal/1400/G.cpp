#include <bits/stdc++.h>
using namespace std;

namespace modular {
	template <typename>
	struct is_modular : std::false_type { };

	template<int M>
	struct static_mint {
		static_assert(0 < M, "Module must be positive");

		using mint = static_mint;
		constexpr static int get_mod() { return M; }

		int val;
		static_mint(): val() {}
		static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
		mint pow(long long n) const { mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		mint inv() const { return pow(M - 2); }

		friend mint pow(const mint &m, long long n) { return m.pow(n); }
		friend mint inv(const mint &m) { return m.inv(); }

		mint operator+() const { mint m; m.val = val; return m; }
		mint operator-() const { mint m; m.val = M - val; return m; }
		mint &operator+=(const mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
		mint &operator-=(const mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
		mint &operator*=(const mint &m) { val = (long long) val * m.val % M; return *this; }
		mint &operator/=(const mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend mint operator+ (const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
		friend mint operator- (const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
		friend mint operator* (const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
		friend mint operator/ (const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
		friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.val == rhs.val; }
		friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.val != rhs.val; }

		mint &operator++() { return *this += 1; }
		mint &operator--() { return *this -= 1; }
		mint operator++(int) { mint result(*this); *this += 1; return result; }
		mint operator--(int) { mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const { return T(val); }

		friend std::ostream &operator<<(std::ostream &os, const mint &m) {
			return os << m.val;
		}

		friend std::istream &operator>>(std::istream &is, mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	template <int M>
	struct is_modular<static_mint<M>> : std::true_type { };

	struct dynamic_mint {
		static int M;
		static void set_mod(int m) { assert(0 < m); M = m; }
		static int get_mod() { return M; }

		using mint = dynamic_mint;

		int val;
		dynamic_mint(): val() {}
		dynamic_mint(long long x) : val(x % M) { if (val < 0) { val += M; } }
		mint pow(long long n) const { mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		mint inv() const { return pow(M - 2); }

		friend mint pow(const mint &m, long long n) { return m.pow(n); }
		friend mint inv(const mint &m) { return m.inv(); }

		mint operator+() const { mint m; m.val = val; return m; }
		mint operator-() const { mint m; m.val = M - val; return m; }
		mint &operator+=(const mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
		mint &operator-=(const mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
		mint &operator*=(const mint &m) { val = (long long) val * m.val % M; return *this; }
		mint &operator/=(const mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend mint operator+ (const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
		friend mint operator- (const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
		friend mint operator* (const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
		friend mint operator/ (const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
		friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.val == rhs.val; }
		friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.val != rhs.val; }

		mint &operator++() { return *this += 1; }
		mint &operator--() { return *this -= 1; }
		mint operator++(int) { mint result(*this); *this += 1; return result; }
		mint operator--(int) { mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const { return T(val); }

		friend std::ostream &operator<<(std::ostream &os, const mint &m) {
			return os << m.val;
		}

		friend std::istream &operator>>(std::istream &is, mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	int dynamic_mint::M;

	template <>
	struct is_modular<dynamic_mint> : std::true_type { };
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int N = 300000;
	using mint = modular::static_mint<998244353>;

	vector<mint> fact(N + 1), inv(N + 1);
	fact[0] = 1, inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = i * fact[i - 1];
		inv[i] = fact[i].inv();
	}

	auto choose = [&](int n, int k) -> mint {
		if (0 <= n && 0 <= k && k <= n) {
			return fact[n] * inv[k] * inv[n - k];
		}
		return 0;
	};

	auto zeta_transform = [&](int n, vector<mint> &f) -> void {
		for (int i = 0; i < n; i++) {
			for (int mask = 0; mask < (1 << n); mask++) {
				if (mask & (1 << i)) {
					f[mask] += f[mask ^ (1 << i)];
				}
			}
		}
	};

	int n, m;
	cin >> n >> m;

	vector<array<int, 2>> ranges(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ranges[i][0] >> ranges[i][1];
	}

	vector<vector<int>> g(n + 1);
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<bool> visited(n + 1);
	vector<int> pos(n + 1), r, leaders;
	vector<vector<int>> v;
	vector<vector<vector<mint>>> f;
	leaders.reserve(m), r.reserve(m), f.reserve(m);

	for (int i = 1; i <= n; i++) {
		if (!g[i].empty() && !visited[i]) {
			int li = (int)leaders.size();
			leaders.push_back(i), r.emplace_back();
			v.emplace_back();
			auto dfs = [&](int x, const auto &self) -> void {
				pos[x] = r.back()++;
				v.back().push_back(x);
				visited[x] = true;
				for (int j : g[x]) {
					if (!visited[j]) {
						self(j, self);
					}
				}
			};

			dfs(i, dfs);
			int sz = r.back();

			vector<bool> ok(1 << sz, true);
			f.emplace_back();
			f[li].assign(sz, vector<mint>(1 << sz));
			for (int mask = 0; mask < (1 << sz); mask++) {
				int pop = 0;
				for (int j = 0; j < sz; j++) {
					if (mask & (1 << j)) {
						for (int x : g[v.back()[j]]) {
							if (mask & (1 << pos[x])) {
								ok[mask] = false;
							}
						}
						pop += 1;
					}
				}
				if (ok[mask]) {
					f[li][pop][mask] = 1;
				}
			}

			for (int j = 1; j < sz; j++) {
				zeta_transform(sz, f[li][j]);
			}
		}
	}

	vector<int> add(n + 1);

	for (int i = 1; i <= n; i++) {
		if (g[i].empty()) {
			add[ranges[i][0]] += 1;
			if (ranges[i][1] != n) {
				add[ranges[i][1] + 1] -= 1;
			}
		}
	}

	int ones = 0;
	mint ans = 0;

	for (int i = 1; i <= n; i++) {
		ones += add[i];
		vector<mint> dp(m + 1);
		dp[0] = 1;
		for (int li = 0; li < leaders.size(); li++) {
			int cur_mask = 0;
			for (int j = 0; j < r[li]; j++) {
				if (ranges[v[li][j]][0] <= i && i <= ranges[v[li][j]][1]) {
					cur_mask |= 1 << j;
				}
			}
			for (int w = m; w >= 0; w--) {
				for (int j = 1; j < r[li] && w + j <= m; j++) {
					dp[w + j] += dp[w] * f[li][j][cur_mask];
				}
			}
		}
		for (int j = 0; j <= m; j++) {
			ans += choose(ones, i - j) * dp[j];
		}
	}
	cout << ans << '\n';
	return 0;
}