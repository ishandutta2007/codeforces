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

template <typename>
struct is_mint : public std::false_type { };

template <int M>
struct is_mint<static_mint<M>> : public std::true_type { };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<998244353>;

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<vector<int>> lvl(n, vector<int>(n, -1));
	for (int s = 0; s < n; s++) {
		queue<int> q;
		q.push(s), lvl[s][s] = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i : g[x]) {
				if (lvl[s][i] == -1) {
					lvl[s][i] = lvl[s][x] + 1;
					q.push(i);
				}
			}
		}
	}

	vector<bool> sub_i(n), sub_j(n), other(n);
	vector<int> cnt(n);

	vector<vector<int>> sav(n, vector<int>(n, -1));
	vector<vector<bool>> e(n, vector<bool>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sav[j][i] != -1)
				continue;
			sub_i[i] = true, sub_j[j] = true;
			other[i] = other[j] = true;

			for (int u = 0; u < n; u++) {
				if (u == i || u == j)
					continue;
				if (lvl[u][i] + lvl[i][j] == lvl[u][j]) {
					for (int v : g[u]) {
						if (sub_i[v] && lvl[i][v] + 1 == lvl[i][u]) {
							cnt[u] += 1;
						} else if (sub_i[v] && lvl[i][v] == lvl[i][u] + 1) {
							cnt[v] += 1;
						}
					}
					sub_i[u] = true;
				} else if (lvl[u][j] + lvl[j][i] == lvl[j][i]) {
					for (int v : g[u]) {
						if (sub_j[v] && lvl[j][v] + 1 == lvl[j][u]) {
							cnt[u] += 1;
						} else if (sub_j[v] && lvl[j][v] == lvl[j][u] + 1) {
							cnt[v] += 1;
						}
					}
					sub_j[u] = true;
				} else {
					other[u] = true;
				}
			}

			mint ans = 1;
			for (int u = 0; u < n; u++) {
				if (u == i || u == j)
					continue;
				if (other[u]) {
					int c0 = 0, c1 = 0, c2 = 0;
					for (int v : g[u]) {
						if (!other[v])
							continue;
						if (lvl[i][v] + 1 == lvl[i][u] && lvl[j][v] + 1 == lvl[j][u]) {
							c0 += 1;
						} else if (lvl[i][v] + 1 == lvl[i][u] && lvl[j][v] == lvl[j][u] + 1) {
							c1 += 1;
						} else if (lvl[i][v] == lvl[i][u] + 1 && lvl[j][v] + 1 == lvl[j][u]) {
							c2 += 1;
						}
					}
					if (lvl[i][u] + lvl[u][j] == lvl[i][j]) {
						if (!e[lvl[i][u]][lvl[u][j]])
							ans *= c1 * c2, e[lvl[i][u]][lvl[u][j]] = true;
						else ans = 0;
					} else {
						ans *= c0;
					}
				} else {
					ans *= cnt[u];
				}
			}

			for (int u = 0; u < n; u++) {
				if (u != i && u != j && other[u])
					e[lvl[u][i]][lvl[u][j]] = false;
				cnt[u] = 0, sub_i[u] = sub_j[u] = other[u] = false;
			}
			sav[i][j] = ans.val;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (sav[i][j] != -1 ? sav[i][j] : sav[j][i]) << ' ';
		}
		cout << '\n';
	}
	return 0;
}