#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<string> a(n);
		for (auto &s : a) cin >> s;

		int mn_i = n - 1, mx_i = 0, mn_j = n - 1, mx_j = 0;

		vector<pair<int, int>> points;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == '*') {
					mn_i = min(mn_i, i);
					mx_i = max(mx_i, i);
					mn_j = min(mn_j, j);
					mx_j = max(mx_j, j);
					points.emplace_back(i, j);
				}
			}
		}

		if (mn_i != mx_i && mn_j != mx_j) {
			for (auto x : {mn_i, mx_i}) {
				for (auto y : {mn_j, mx_j}) {
					a[x][y] = '*';
				}
			}
		} else if (mn_i == mx_i) {
			if (mn_i == 0) {
				a[1][mn_j] = a[1][mx_j] = '*';
			} else {
				a[0][mn_j] = a[0][mx_j] = '*';
			}
		} else {
			if (mn_j == 0) {
				a[mn_i][1] = a[mx_i][1] = '*';
			} else {
				a[mn_i][0] = a[mx_i][0] = '*';
			}
		}

		for (auto &s : a) cout << s << '\n';
	}
	return 0;
}