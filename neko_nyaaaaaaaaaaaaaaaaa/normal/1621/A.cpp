#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	int nd = k*2 - 1;
	if (n < nd) {
		cout << "-1\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j && k > 0 && i % 2 == 0) {
				cout << "R"; k--;
			} else {
				cout << ".";
			}
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