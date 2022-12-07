#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, m; cin >> n >> m;
	int r = 0, w = 0;
	while (m--) {
		int x, y; cin >> x >> y;
		r = max(r, x);
		w = max(w, y);
	}
	if (r+w > n) {
		cout << "IMPOSSIBLE\n";
	} else {
		string s(n, 'W');
		for (int i = 0; i < r; i++) {
			s[i] = 'R';
		}
		cout << s << '\n';
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