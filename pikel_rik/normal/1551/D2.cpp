#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const vector<int> di = {1, -1, 0, 0};
	const vector<int> dj = {0, 0, 1, -1};

	constexpr int alpha = 10;

	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		int total = n * m / 2;

		bool swapped = false;
		if (n % 2 != 0) {
			swap(n, m);
			k = total - k;
			swapped = true;
		}

		vector<string> grid(n, string(m, 0));

		auto check = [&](int i, int j) -> vector<bool> {
			vector<bool> mark(alpha);
			for (int k = 0; k < 4; k++) {
				int ni = i + di[k], nj = j + dj[k];
				if (0 <= ni && ni < n && 0 <= nj && nj < m && grid[ni][nj]) {
					mark[grid[ni][nj] - 'a'] = true;
				}
			}
			return mark;
		};

		auto check_horizontal = [&](int i, int j) -> char {
			auto mark1 = check(i, j);
			auto mark2 = check(i, j + 1);

			for (int c = 0; c < alpha; c++) {
				if (!mark1[c] && !mark2[c]) {
					return 'a' + c;
				}
			}
			return 0;
		};

		auto check_vertical = [&](int i, int j) -> char {
			auto mark1 = check(i, j);
			auto mark2 = check(i + 1, j);

			for (int c = 0; c < alpha; c++) {
				if (!mark1[c] && !mark2[c]) {
					return 'a' + c;
				}
			}
			return 0;
		};

		if (k % 2 != 0) {
			cout << "NO\n";
			continue;
		}

		if (m % 2 != 0) {
			for (int i = 0; i < n; i += 2) {
				auto c = check_vertical(i, m - 1);
				grid[i][m - 1] = grid[i + 1][m - 1] = c;
			}
		}

		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j + 1 < m; j += 2) {
				if (k > 0) {
					auto c = check_horizontal(i, j);
					grid[i][j] = grid[i][j + 1] = c;
					c = check_horizontal(i + 1, j);
					grid[i + 1][j] = grid[i + 1][j + 1] = c;
					k -= 2;
				} else {
					auto c = check_vertical(i, j);
					grid[i][j] = grid[i + 1][j] = c;
					c = check_vertical(i, j + 1);
					grid[i][j + 1] = grid[i + 1][j + 1] = c;
				}
			}
		}

		if (k > 0) {
			cout << "NO\n";
			continue;
		}

		if (swapped) {
			swap(n, m);
			vector<string> actual_grid(n, string(m, 0));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					actual_grid[i][j] = grid[j][i];
				}
			}
			grid.swap(actual_grid);
		}

		cout << "YES\n";
		for (auto &row : grid) {
			cout << row << '\n';
		}
	}
	return 0;
}