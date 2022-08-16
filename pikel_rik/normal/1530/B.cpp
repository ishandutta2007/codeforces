#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const vector<int> dx = {1, -1, 0, 0, 1, 1, -1, -1};
	const vector<int> dy = {0, 0, 1, -1, 1, -1, 1, -1};

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<string> ans(n, string(m, '0'));

		auto check = [&](int i, int j) -> bool {
			bool ok = true;
			for (int k = 0; k < 8; k++) {
				int ni = i + dx[k], nj = j + dy[k];
				if (0 <= ni && ni < n && 0 <= nj && nj < m && ans[ni][nj] == '1') {
					ok = false;
				}
			}
			return ok;
		};

		for (int j = 0; j < m; j++) {
			if (check(0, j)) {
				ans[0][j] = '1';
			}
		}

		for (int i = 0; i < n; i++) {
			if (check(i, m - 1)) {
				ans[i][m - 1] = '1';
			}
		}

		for (int j = m - 1; j >= 0; j--) {
			if (check(n - 1, j)) {
				ans[n - 1][j] = '1';
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			if (check(i, 0)) {
				ans[i][0] = '1';
			}
		}

		for (auto &row : ans) cout << row << '\n';
	}
	return 0;
}