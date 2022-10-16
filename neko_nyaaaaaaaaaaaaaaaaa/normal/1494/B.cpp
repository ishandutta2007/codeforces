#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, a[4], b[4];
	cin >> n >> a[0] >> a[1] >> a[2] >> a[3];

	for (int i = 0; i < (1 << 4); i++) {
		for (int j = 0; j < 4; j++) {
			b[j] = a[j];
		}

		for (int j = 0; j < 4; j++) {
			if (i & (1 << j)) {
				b[j]--; b[(j+1) % 4]--;
			}
		}

		bool ok = 1;
		for (int j = 0; j < 4; j++) {
			if (b[j] >= 0 && b[j] <= n-2) {

			} else {
				ok = 0;
			}
		}
		if (ok) {
			cout << "YES\n"; 
			return;
		}
	}
	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}