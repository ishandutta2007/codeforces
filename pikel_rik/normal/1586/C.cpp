#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> grid(n);
	for (auto &row : grid) cin >> row;

	vector<int> prefix(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 < n && j > 0 && grid[i][j] == 'X' && grid[i + 1][j - 1] == 'X') {
				prefix[j] += 1;
			}
		}
	}

	partial_sum(prefix.begin(), prefix.end(), prefix.begin());

	int q;
	cin >> q;

	while (q--) {
		int x1, x2;
		cin >> x1 >> x2, --x1, --x2;

		cout << (prefix[x2] - prefix[x1] ? "NO" : "YES") << '\n';
	}
	return 0;
}