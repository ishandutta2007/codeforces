#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int l, r; cin >> l >> r;
		if (l*2 <= r) {
			cout << l << ' ' << l*2 << '\n';
		} else {
			cout << "-1 -1\n";
		}
	}

	return 0;
}