#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, q;
	cin >> n >> m >> q;

	//dp_downward = 1 + dp_rightward[below_cell]
	//dp_rightward = 1 + dp_downward[right_cell]

	vector<vector<bool>> grid(n, vector<bool>(m, true));
	vector<vector<long long>> dp0(n, vector<long long>(m, 1));
	vector<vector<long long>> dp1(n, vector<long long>(m, 1));

	long long sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (i + 1 < n) {
				dp0[i][j] += dp1[i + 1][j];
			}
			if (j + 1 < m) {
				dp1[i][j] += dp0[i][j + 1];
			}
			sum += dp0[i][j] + dp1[i][j] - 1;
		}
	}

	auto recompute = [&](int x, int y) -> void {
		sum -= max(0ll, dp0[x][y] + dp1[x][y] - 1);
		dp0[x][y] = 1, dp1[x][y] = 1;
		if (x + 1 < n) {
			dp0[x][y] += dp1[x + 1][y];
		}
		if (y + 1 < m) {
			dp1[x][y] += dp0[x][y + 1];
		}
		sum += dp0[x][y] + dp1[x][y] - 1;
	};

	while (q--) {
		int x, y;
		cin >> x >> y, --x, --y;

		grid[x][y] = grid[x][y] ^ true;
		if (grid[x][y]) {
			recompute(x, y);
		} else {
			sum -= dp0[x][y] + dp1[x][y] - 1;
			dp0[x][y] = dp1[x][y] = 0;
		}

		int i = x - 1, j = y;
		for (int rep = 0; i >= 0 && j >= 0 && grid[i][j]; rep++) {
			recompute(i, j);
			if (rep % 2 == 0) {
				j -= 1;
			} else {
				i -= 1;
			}
		}

		i = x, j = y - 1;
		for (int rep = 0; i >= 0 && j >= 0 && grid[i][j]; rep++) {
			recompute(i, j);
			if (rep % 2 == 0) {
				i -= 1;
			} else {
				j -= 1;
			}
		}

		cout << sum << '\n';
	}
	return 0;
}