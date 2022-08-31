#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<string> grid(n);
		for (auto &row : grid) cin >> row;

		int lx = -1, ly = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'L') {
					lx = i, ly = j;
				}
			}
		}

		const vector<int> dx = {1, -1, 0, 0};
		const vector<int> dy = {0, 0, 1, -1};

		auto check_cell = [&](int x, int y) -> bool {
			int c = 0;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] == '.') {
					c += 1;
				}
			}
			return c <= 1;
		};

		queue<pair<int, int>> q;
		q.emplace(lx, ly);

		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] == '.' && check_cell(nx, ny)) {
					grid[nx][ny] = '+';
					q.emplace(nx, ny);
				}
			}
		}

		for (auto &row : grid) {
			cout << row << '\n';
		}
	}
	return 0;
}