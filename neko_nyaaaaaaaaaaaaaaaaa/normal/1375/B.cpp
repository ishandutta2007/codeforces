#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ff = 4;
			if (j == 0 || j == m-1) ff--;
			if (i == 0 || i == n-1) ff--;
			if (a[i][j] > ff) {
				cout << "NO\n"; return;
			}
		}
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ff = 4;
			if (j == 0 || j == m-1) ff--;
			if (i == 0 || i == n-1) ff--;
			cout << ff << ' ';
		}
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}