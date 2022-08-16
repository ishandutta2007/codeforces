#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
	const vector<int> dy = {0, 0, 1, -1, 1, 1, -1, -1};

	int n, m;
	cin >> n >> m;

	vector<string> a(n);
	for (auto &s : a) cin >> s;

	vector<vector<bool>> visited(n, vector<bool>(m));

	auto check = [&](int i, int j) -> bool {
		if (a[i][j] == '.')
			return false;
		if (i > 0 && j > 0 && a[i - 1][j] == '.' && a[i][j - 1] == '.' && a[i - 1][j - 1] == '.')
			return true;
		if (i > 0 && j + 1 < m && a[i - 1][j] == '.' && a[i][j + 1] == '.' && a[i - 1][j + 1] == '.')
			return true;
		if (i + 1 < n && j > 0 && a[i + 1][j] == '.' && a[i][j - 1] == '.' && a[i + 1][j - 1] == '.')
			return true;
		if (i + 1 < n && j + 1 < m && a[i + 1][j] == '.' && a[i][j + 1] == '.' && a[i + 1][j + 1] == '.')
			return true;
		return false;
	};

	auto bfs = [&](int sx, int sy) -> void {
		queue<pair<int, int>> q;
		a[sx][sy] = '.', q.emplace(sx, sy);

		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();

			for (int i = 0; i < 8; i++) {
				int new_x = x + dx[i], new_y = y + dy[i];
				if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m && check(new_x, new_y)) {
					a[new_x][new_y] = '.';
					q.emplace(new_x, new_y);
				}
			}
		}
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check(i, j)) {
				bfs(i, j);
			}
		}
	}

	for (auto &s : a) cout << s << '\n';
	return 0;
}