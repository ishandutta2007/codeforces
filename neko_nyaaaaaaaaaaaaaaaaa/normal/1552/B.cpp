#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<vector<int>> r(n, vector<int>(5));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> r[i][j];
		}
	}

	int best = 0;
	for (int i = 1; i < n; i++) {
		int win = 0;
		for (int j = 0; j < 5; j++) {
			if (r[i][j] < r[best][j]) win++;
		}
		if (win >= 3) {
			best = i;
		}
	}

	// is this best
	for (int i = 0; i < n; i++) {
		if (i == best) continue;

		int win = 0;
		for (int j = 0; j < 5; j++) {
			if (r[i][j] < r[best][j]) win++;
		}

		if (win >= 3) {
			cout << "-1\n"; return;
		}
	}

	cout << best+1 << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}