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

	using mint = static_mint<1000000007>;

	struct edge { int u, v, w; };

	int n, m;
	cin >> n >> m;

	vector<edge> e(m);
	vector<vector<int>> g(n);

	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		g[--e[i].u].push_back(i);
		g[--e[i].v].push_back(i);
		if (e[i].v == 0) {
			swap(e[i].u, e[i].v);
		}
	}

	vector<bool> is_back_edge(m), visited(n);
	vector<int> xor_d(n), d(n), p(n, -1);

	auto dfs = [&](int u, const auto &self) -> void {
		visited[u] = true;
		for (int i : g[u]) {
			int v = e[i].u ^ e[i].v ^ u;
			if (v != p[u]) {
				if (visited[v]) {
					is_back_edge[i] = true;
				} else {
					d[v] = 1 + d[u], p[v] = u;
					xor_d[v] = e[i].w ^ xor_d[u];
					self(v, self);
				}
			}
		}
	};

	dfs(0, dfs);

	auto find = [&](int x) -> int {
		auto recurse = [&](int y, const auto &self) -> int {
			return p[y] == 0 ? y : p[y] = self(p[y], self);
		};
		return recurse(x, recurse);
	};

	vector<vector<int>> back_edge(n);
	for (int i = 0; i < m; i++) {
		if (!is_back_edge[i]) {
			continue;
		}
		int l = find(e[i].v);
		back_edge[l].push_back(i);
	}

	auto weight_of = [&](int i) -> int {
		return e[i].w ^ xor_d[e[i].u] ^ xor_d[e[i].v];
	};

	map<uint32_t, uint32_t> subspace_of;
	map<uint32_t, uint32_t> basis_of;

	vector<uint32_t> subspaces = {0};
	for (int pop = 1; pop < 6; pop++) {
		array<bool, 32> bits = {};
		fill(bits.rbegin(), bits.rbegin() + pop, 1);
		do {
			uint32_t basis = 0;
			for (int i = 0; i < 32; i++) {
				if (bits[i]) {
					basis |= 1u << i;
				}
			}
			uint32_t &subspace = subspace_of[basis], xor_sum = 0;
			for (int i = 0; i < 32; i++) {
				if (bits[i]) {
					xor_sum ^= i;
					subspace |= subspace_of[basis ^ (1u << i)];
				}
			}
			subspace |= 1u << xor_sum;
			if (basis_of.find(subspace) == basis_of.end()) {
				basis_of[subspace] = basis;
				subspaces.push_back(subspace);
			}
		} while (next_permutation(bits.begin(), bits.end()));
	}

	subspaces.erase(remove_if(subspaces.begin(), subspaces.end(), [&](uint32_t subspace) {
		return subspace & 1;
	}), subspaces.end());

	int sz = subspaces.size();
	vector<vector<uint32_t>> inter(sz, vector<uint32_t>(sz, -1));
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			uint32_t a = subspaces[i], b = subspaces[j];
			if (a & b) {
				continue;
			}
			uint32_t &best = inter[i][j], best_pop = -1;
			for (int k = 0; k < sz; k++) {
				uint32_t c = subspaces[k];
				if ((c & a) == a && (c & b) == b && __builtin_popcount(c) < best_pop) {
					best = k;
					best_pop = __builtin_popcount(c);
				}
			}
		}
	}

	vector<mint> dp(sz);
	dp[0] = 1;

	for (int l = 1; l < n; l++) {
		if (p[l] == 0) {
			bool linearly_dependent = false;
			uint32_t basis = 0;

			auto add_back_edge = [&](int i) -> void {
				int w = weight_of(i);
				linearly_dependent |= (basis >> w & 1);
				basis |= 1u << w;
				linearly_dependent |= __builtin_popcount(basis) > 5;
			};

			vector<mint> new_dp(sz);
			auto update_dp = [&](mint mul) -> void {
				if (linearly_dependent) {
					return;
				}
				uint32_t subspace = subspace_of[basis];
				if (subspace & 1) {
					return;
				}
				int j = std::find(subspaces.begin(), subspaces.end(), subspace) - subspaces.begin();
				for (int i = 0; i < sz; i++) {
					if (!(subspaces[i] & 1) && !(subspaces[i] & subspace)) {
						new_dp[inter[i][j]] += mul * dp[i];
					}
				}
			};

			int j = -1;
			for (int i : back_edge[l]) {
				if (e[i].u == 0) {
					j = i;
				} else {
					add_back_edge(i);
				}
			}
			if (j == -1) {
				update_dp(1);
			} else {
				update_dp(2);
				add_back_edge(j);
				update_dp(1);
			}

			for (int i = 0; i < sz; i++) {
				dp[i] += new_dp[i];
			}
		}
	}

	mint ans = 0;
	for (int i = 0; i < sz; i++) {
		if (!(subspaces[i] & 1)) {
			ans += dp[i];
		}
	}
	cout << ans << '\n';
	return 0;
}