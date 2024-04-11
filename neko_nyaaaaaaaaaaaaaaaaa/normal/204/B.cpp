#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	map<int, int> fr, ba;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		fr[x]++;
		if (x != y) ba[y]++;
	}

	int m = (n+1)/2;
	int ans = 100000000;
	for (auto [col, cnt]: fr) {
		if (cnt >= m) {
			cout << 0; exit(0);
		}

		if (cnt + ba[col] >= m) {
			ans = min(ans, m - cnt);
		}
	}

	for (auto [col, cnt]: ba) {
		if (cnt >= m) {
			ans = min(ans, m);
		}
	}

	if (ans == 100000000) {
		cout << -1;
	} else {
		cout << ans;
	}

	return 0;
}