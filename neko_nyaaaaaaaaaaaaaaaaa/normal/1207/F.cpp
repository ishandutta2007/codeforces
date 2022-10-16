#include <bits/stdc++.h>
using namespace std;

int a[500001];
int p[801][801];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, y; cin >> x >> y;
			a[x] += y;

			for (int i = 1; i <= 650; i++) {
				p[i][x % i] += y;
			}
		} else if (t == 2) {
			int x, y; cin >> x >> y;

			if (x > 650) {
				int ans = 0;
				for (int i = y; i < 500001; i += x) {
					ans += a[i];
				}
				cout << ans << '\n';
			} else {
				cout << p[x][y] << '\n';
			}
		}
	}

	return 0;
}