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

	struct edge { int u, v; long long w; };

	int n, m;
	cin >> n >> m;

	vector<edge> e(m);
	vector<vector<int>> g(n);

	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		g[--e[i].u].push_back(i);
		g[--e[i].v].push_back(i);
	}

	vector<int> visited(n, -1);
	vector<long long> d(n);

	mint ans = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] != -1) {
			continue;
		}

		int sz = 0;
		mint subspace_size = 1;
		vector<int> cnt(60);
		vector<long long> basis(60);
		vector<mint> dist(60);

		auto dfs = [&](int u, const auto &self) -> void {
			sz += 1, visited[u] = 0;
			for (int j = 0; j < 60; j++) {
				cnt[j] += (d[u] >> j & 1);
			}
			for (int i : g[u]) {
				int v = e[i].u ^ e[i].v ^ u;
				if (visited[v] == -1) {
					d[v] = d[u] ^ e[i].w;
					self(v, self);
				} else {
					long long w = d[v] ^ d[u] ^ e[i].w;
					for (int j = 0; j < 60; j++) {
						if (w >> j & 1) {
							if (basis[j]) {
								w ^= basis[j];
							} else {
								basis[j] = w;
								break;
							}
						}
					}
					if (w > 0) {
						for (int j = 0; j < 60; j++) {
							if (w >> j & 1) {
								dist[j] += subspace_size - dist[j];
							} else {
								dist[j] += dist[j];
							}
						}
						subspace_size += subspace_size;
					}
				}
			}
		};

		dfs(i, dfs);

		auto reroot = [&](int u, const auto &self) -> void {
			visited[u] = 1;
			mint cur_ans = 0;
			for (int j = 59; j >= 0; j--) {
				cur_ans += cur_ans;
				if (d[u] >> j & 1) {
					cur_ans += (cnt[j] - 1) * dist[j];
					cur_ans += (sz - cnt[j]) * (subspace_size - dist[j]);
				} else {
					cur_ans += cnt[j] * (subspace_size - dist[j]);
					cur_ans += (sz - cnt[j] - 1) * dist[j];
				}
			}
			ans += cur_ans;
			for (int i : g[u]) {
				int v = e[i].u ^ e[i].v ^ u;
				if (!visited[v]) {
					self(v, self);
				}
			}
		};

		reroot(i, reroot);
	}
	ans /= 2;
	cout << ans << '\n';
	return 0;
}