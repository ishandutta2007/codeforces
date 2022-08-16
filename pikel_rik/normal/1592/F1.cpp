#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> grid(n);
	for (auto &row : grid) cin >> row;

	vector<vector<int>> parity(n, vector<int>(m));

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			parity[i][j] = (grid[i][j] == 'B');
			if (i + 1 < n) {
				parity[i][j] ^= (grid[i + 1][j] == 'B');
			}
			if (j + 1 < m) {
				parity[i][j] ^= (grid[i][j + 1] == 'B');
			}
			if (i + 1 < n && j + 1 < m) {
				parity[i][j] ^= (grid[i + 1][j + 1] == 'B');
			}
			sum += parity[i][j];
		}
	}

	int ans = sum;
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			int now_sum = parity[i][j] + parity[n - 1][j] + parity[i][m - 1] + parity[n - 1][m - 1];
			ans = min(ans, sum + 7 - 2 * now_sum);
		}
	}

	cout << ans << '\n';
	return 0;
}