#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << "-1\n";
	} else {
		for (int i = 1; i < n; i++) {
			cout << 5;
		}
		cout << "8\n";
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