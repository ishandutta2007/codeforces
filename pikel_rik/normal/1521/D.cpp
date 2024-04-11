#include <bits/stdc++.h>
using namespace std;

struct union_find {
	int n, c;
	std::vector<int> p;
	std::vector<std::vector<int>> v;

	union_find(): n(), c() {}
	union_find(int n): n(n), c(n), p(n), v(n) {
		for (int i = 0; i < n; i++) p[i] = i, v[i] = {i};
	}

	int count() const noexcept {
		return c;
	}

	int find(int x) {
		return p[x];
	}

	bool merge(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if (s1 == s2)
			return false;
		if (v[s2].size() > v[s1].size())
			std::swap(s1, s2);
		for (int i : v[s2]) {
			v[s1].push_back(i);
			p[i] = s1;
		}
		v[s2].clear();
		c -= 1;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<pair<int, int>> edges;
		vector<vector<int>> g(n);
		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v, --u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
			edges.emplace_back(u, v);
		}

		vector<array<int, 2>> dp(n);
		vector<array<array<int, 2>, 2>> back_track(n);

		auto dfs = [&](int x, int p, const auto &self) -> void {
			dp[x][0] = 1, dp[x][1] = n + 1;
			int sum = 0;
			vector<int> diffs;

			back_track[x][0][0] = back_track[x][0][1] = -1;

			for (int i : g[x]) {
				if (i != p) {
					self(i, x, self);
					sum += min(dp[i][0], dp[i][1]);
					diffs.push_back(i);
				}
			}

			dp[x][0] += sum;
			sort(diffs.begin(), diffs.end(), [&](int i, int j) {
				return dp[i][0] - min(dp[i][0], dp[i][1]) < dp[j][0] - min(dp[j][0], dp[j][1]);
			});

			if (diffs.size() >= 1) {
				int i = diffs[0], diff_i = dp[i][0] - min(dp[i][0], dp[i][1]);
				if (diff_i + sum < dp[x][0]) {
					dp[x][0] = diff_i + sum;
					back_track[x][0][0] = i;
				}
				if (diffs.size() >= 2) {
					int j = diffs[1], diff_j = dp[j][0] - min(dp[j][0], dp[j][1]);
					dp[x][1] = diff_i + diff_j + sum - 1;
					back_track[x][1][0] = i, back_track[x][1][1] = j;
				}
			}
		};

		dfs(0, -1, dfs);

		union_find uf(n);
		auto get_sol = [&](int x, int f, int p, const auto &self) -> void {
			for (int i : g[x]) {
				if (i == p) {
					continue;
				}
				if (f == 0 && i == back_track[x][0][0]) {
					uf.merge(x, i);
					self(i, 0, x, self);
				} else if (f == 1 && (i == back_track[x][1][0] || i == back_track[x][1][1])) {
					uf.merge(x, i);
					self(i, 0, x, self);
				} else if (dp[i][0] <= dp[i][1]) {
					self(i, 0, x, self);
				} else {
					self(i, 1, x, self);
				}
			}
		};

		if (dp[0][0] <= dp[0][1]) {
			get_sol(0, 0, -1, get_sol);
		} else {
			get_sol(0, 1, -1, get_sol);
		}

		vector<bool> in_path(n);
		vector<pair<int, int>> path_ends;

		for (int i = 0; i < n; i++) {
			if (i != uf.p[i]) {
				continue;
			}
			for (int x : uf.v[i]) {
				in_path[x] = true;
			}
			for (int x : uf.v[i]) {
				int neighbors = 0;
				for (int y : g[x]) {
					neighbors += in_path[y];
				}
				if (neighbors == 0) {
					path_ends.emplace_back(x, x);
				} else if (neighbors == 1) {
					if (!path_ends.empty() && path_ends.back().second == -1) {
						path_ends.back().second = x;
					} else {
						path_ends.emplace_back(x, -1);
					}
				}
			}
			for (int x : uf.v[i]) {
				in_path[x] = false;
			}
		}

//		for (int i = 0; i < n; i++) {
//			cout << i << ' ';
//			cout << dp[i][0] << ' ' << dp[i][1] << '\n';
//		}

		cout << (int)path_ends.size() - 1 << '\n';
		for (int i = 1, j = 0; i < path_ends.size(); i++) {
			while (uf.p[edges[j].first] == uf.p[edges[j].second]) {
				j += 1;
			}
			cout << edges[j].first + 1 << ' ' << edges[j].second + 1 << ' ', j++;
			cout << path_ends[i - 1].second + 1 << ' ' << path_ends[i].first + 1 << '\n';
		}
	}
	return 0;
}