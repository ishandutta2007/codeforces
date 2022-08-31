#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int inf = 100000000;

	constexpr int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

	int n, m;
	cin >> n >> m;

	vector<string> a(n);
	for (auto &s : a) cin >> s;

	vector<vector<int>> lvl(n, vector<int>(m));
	vector<vector<vector<int>>> mn_lvl(n, vector<vector<int>>(m, vector<int>(3, inf)));

	for (int col = 0; col < 3; col++) {
		deque<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			std::fill(lvl[i].begin(), lvl[i].end(), inf);
			for (int j = 0; j < m; j++) {
				if (isdigit(a[i][j]) && a[i][j] - '1' == col) {
					q.emplace_back(i, j);
					lvl[i][j] = 0;
				}
			}
		}

		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop_front();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != '#' && lvl[nx][ny] == inf) {
					if (a[nx][ny] == '.') {
						lvl[nx][ny] = 1 + lvl[x][y];
						q.emplace_back(nx, ny);
					} else {
						lvl[nx][ny] = lvl[x][y];
						q.emplace_front(nx, ny);
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mn_lvl[i][j][col] = lvl[i][j];
			}
		}
	}

	int ans = inf;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') {
				ans = min(ans, mn_lvl[i][j][0] + mn_lvl[i][j][1] + mn_lvl[i][j][2] - 2);
			} else {
				ans = min(ans, mn_lvl[i][j][0] + mn_lvl[i][j][1] + mn_lvl[i][j][2]);
			}
		}
	}
	cout << (ans == inf ? -1 : ans) << '\n';
	return 0;
}