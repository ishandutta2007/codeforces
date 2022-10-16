#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n, x, y; cin >> n >> x >> y;
		int yes = 0;
		while (x--) {
			int k; cin >> k;
			if (k == n) yes = 1;
		}
		while (y--) {
			int k; cin >> k;
		}

		if (yes) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}