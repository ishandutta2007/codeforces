#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<string> grid(n);
		for (auto &row : grid) cin >> row;

		vector<vector<bool>> mark(n, vector<bool>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int h;
				for (h = 0;; h++) {
					if (h == n) {
						h -= 1;
						break;
					}
					if (i - h < 0 || j - h < 0 || grid[i - h][j - h] == '.') {
						h -= 1;
						break;
					}
					if (j + h >= m || grid[i - h][j + h] == '.') {
						h -= 1;
						break;
					}
				}
				if (h >= k) {
					for (; h >= 0; h--) {
						mark[i - h][j - h] = true;
						mark[i - h][j + h] = true;
					}
				}
			}
		}

		bool possible = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				possible &= grid[i][j] == '.' || mark[i][j];
			}
		}

		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}