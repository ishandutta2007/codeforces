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

	using mint = static_mint<998244353>;

	struct edge {
		int u, v;
	};

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<edge> e(m);
		vector<vector<int>> g(n);

		for (int i = 0; i < m; i++) {
			cin >> e[i].u >> e[i].v;
			g[--e[i].u].push_back(i);
			g[--e[i].v].push_back(i);
		}

		vector<int> c(n, -1);

		vector<int> sz(n), partition(n);
		for (int s = 0; s < n; s++) {
			if (c[s] != -1) {
				continue;
			}

			queue<int> q;
			q.push(s);
			c[s] = 0;
			sz[s] = 1;
			partition[s] = 1;

			while (!q.empty()) {
				int u = q.front();
				q.pop();

				for (int i : g[u]) {
					int v = e[i].u ^ e[i].v ^ u;
					if (c[v] == -1) {
						c[v] = 1 ^ c[u];
						q.push(v);
						sz[s] += 1;
						if (c[v] == 0) {
							partition[s] += 1;
						}
					}
				}
			}
		}

		bool bipartite = true;
		for (auto &[u, v] : e) {
			bipartite &= c[u] != c[v];
		}

		if (!bipartite) {
			cout << 0 << '\n';
			continue;
		}

		mint ans = 1;
		for (int s = 0; s < n; s++) {
			if (sz[s] == 0) {
				continue;
			}
			ans *= mint(2).pow(partition[s]) + mint(2).pow(sz[s] - partition[s]);
		}
		cout << ans << '\n';
	}
	return 0;
}