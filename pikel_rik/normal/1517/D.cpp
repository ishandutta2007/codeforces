#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	if (k % 2 != 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << -1 << ' ';
			}
			cout << '\n';
		}
		return 0;
	}

	vector<vector<int>> right(n, vector<int>(m)), down(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			cin >> right[i][j];
		}
	}

	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> down[i][j];
		}
	}

	const vector<int> dx = {1, -1, 0, 0};
	const vector<int> dy = {0, 0, 1, -1};

	vector<vector<int>> lvl(n, vector<int>(m));

	for (int iter = 0; iter < k / 2; iter++) {
		vector<vector<int>> new_lvl(n, vector<int>(m, INT_MAX));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j + 1 < m; j++) {
				new_lvl[i][j] = min(new_lvl[i][j], right[i][j] + lvl[i][j + 1]);
				new_lvl[i][j + 1] = min(new_lvl[i][j + 1], right[i][j] + lvl[i][j]);
			}
		}

		for (int i = 0; i + 1 < n; i++) {
			for (int j = 0; j < m; j++) {
				new_lvl[i][j] = min(new_lvl[i][j], down[i][j] + lvl[i + 1][j]);
				new_lvl[i + 1][j] = min(new_lvl[i + 1][j], down[i][j] + lvl[i][j]);
			}
		}
		lvl.swap(new_lvl);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << 2 * lvl[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}