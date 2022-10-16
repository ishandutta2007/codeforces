#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, q; cin >> n >> q;

	long long pl = 0, mn = -1e18;
	while (n--) {
		int x; cin >> x;
		mn = max(mn, pl + x);
		pl = max(pl, mn - x);
	}
	cout << max(pl, mn) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}