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

		vector<string> a(n);
		for (auto &s : a) cin >> s;

		if (n == 1) {
			cout << string(m, 'X') << '\n';
			continue;
		} else if (m == 1) {
			for (int i = 0; i < n; i++) cout << 'X' << '\n';
			continue;
		}

		for (int i = 0; i < n; i += 3) {
			for (auto &ch : a[i]) {
				ch = 'X';
			}
		}

		for (int i = 1, j = 0; i < n; i += 3, j ^= 1) {
			if (j == 0) {
				a[i][m - 1] = 'X';
				if (i + 1 < n) {
					a[i + 1][m - 1] = 'X';
				}
			} else {
				a[i][0] = 'X';
				if (i + 1 < n) {
					a[i + 1][0] = 'X';
				}
			}
		}

		for (int j = 0; j < m; j++) {
			if (a[n - 1][j] == '.')
				continue;
			bool there = false;
			for (int k = 0; k < 8; k++) {
				int new_i = n - 1 + dx[k], new_j = j + dy[k];
				if (new_i < 0 || n <= new_i || new_j < 0 || m <= new_j)
					continue;
				there |= a[new_i][new_j] == 'X';
			}

			if (!there) {
				a[n - 2][j] = 'X';
			}
		}

		for (int i = 1, j = 0; i < n; i += 3, j ^= 1) {
			if (i + 1 < n) {
				if (j == 0) {
					if (a[i][m - 2] == 'X' || a[i + 1][m - 2] == 'X') {
						a[i][m - 2] = a[i + 1][m - 2] = 'X';
						a[i][m - 1] = a[i + 1][m - 1] = '.';
					}
				} else {
					if (a[i][1] == 'X' || a[i + 1][1] == 'X') {
						a[i][1] = a[i + 1][1] = 'X';
						a[i][0] = a[i + 1][0] = '.';
					}
				}
			} else {
				if (j == 0) {
					if (a[i][m - 2] == 'X') {
						a[i][m - 1] = '.';
					}
				} else {
					if (a[i][1] == 'X') {
						a[i][0] = '.';
					}
				}
			}
		}

		for (auto &s : a) {
			cout << s << '\n';
		}
	}
	return 0;
}