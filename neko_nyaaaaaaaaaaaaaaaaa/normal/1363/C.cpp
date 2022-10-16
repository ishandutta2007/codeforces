#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x; cin >> n >> x;
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		cnt += (u == x);
		cnt += (v == x);
	}

	if (cnt <= 1) {
		cout << "Ayush\n";
	} else {
		cout << (n % 2 ? "Ashish\n" : "Ayush\n");
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