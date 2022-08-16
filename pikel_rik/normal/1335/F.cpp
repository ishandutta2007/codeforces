#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<string> c(n), s(n);
		for (int i = 0; i < n; i++) cin >> c[i];
		for (int i = 0; i < n; i++) cin >> s[i];

		int cur_id = 0;
		vector<vector<pair<int, int>>> cycles;
		vector<vector<int>> id(n, vector<int>(m, -1)), pos(n, vector<int>(m)), dist(n, vector<int>(m, 0));
		vector<vector<bool>> in_cycle(n, vector<bool>(m));

		auto next = [&](int x, int y) -> pair<int, int> {
			if (s[x][y] == 'U')
				return make_pair(x - 1, y);
			if (s[x][y] == 'D')
				return make_pair(x + 1, y);
			if (s[x][y] == 'R')
				return make_pair(x, y + 1);
			return make_pair(x, y - 1);
		};

		vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
		vector<vector<bool>> v(n, vector<bool>(m));

		auto dfs = [&](int x, int y, const auto &dfs) -> void {
			v[x][y] = true;
			auto [nx, ny] = next(x, y);
			if (v[nx][ny]) {
				cycles.emplace_back();
				vector<pair<int, int>> &cycle = cycles.back();
				for (int i = x, j = y; make_pair(i, j) != p[nx][ny]; tie(i, j) = p[i][j]) {
					id[i][j] = cur_id;
					in_cycle[i][j] = true;
					cycle.emplace_back(i, j);
				}
				reverse(cycle.begin(), cycle.end());
				for (int i = 0; i < cycle.size(); i++) {
					pos[cycle[i].first][cycle[i].second] = i;
				}
				cur_id++;
			} else if (p[nx][ny] == make_pair(-1, -1)) {
				p[nx][ny] = make_pair(x, y);
				dfs(nx, ny, dfs);
			}
			v[x][y] = false;
		};

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (p[i][j] == make_pair(-1, -1)) {
					p[i][j].first = -2;
					dfs(i, j, dfs);
				}
			}
		}

		vector<vector<pair<int, int>>> final_p(n, vector<pair<int, int>>(m));
		auto recurse = [&](int x, int y, const auto &recurse) -> void {
			if (v[x][y]) {
				return;
			}
			if (in_cycle[x][y]) {
				dist[x][y] = 0;
				final_p[x][y] = make_pair(x, y);
			} else {
				auto[nx, ny] = next(x, y);
				recurse(nx, ny, recurse);
				dist[x][y] = 1 + dist[nx][ny];
				final_p[x][y] = final_p[nx][ny];
			}
			v[x][y] = true;
		};

		vector<vector<array<bool, 2>>> f(cycles.size());
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				recurse(i, j, recurse);
				auto [pi, pj] = final_p[i][j];
				int k = id[pi][pj];
				if (f[k].empty()) {
					f[k].resize(cycles[k].size());
				}
				int final_pos = (int(1e7) - dist[i][j] + pos[pi][pj]) % cycles[k].size();
				f[k][final_pos][c[i][j] - '0'] = true;
			}
		}

		int total = 0, black = 0;
		for (int i = 0; i < cycles.size(); i++) {
			for (int j = 0; j < cycles[i].size(); j++) {
				if (f[i][j][0]) {
					total++;
					black++;
				} else if (f[i][j][1]) {
					total++;
				}
			}
		}
		cout << total << ' ' << black << '\n';
	}
	return 0;
}