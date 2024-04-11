#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, k, r, c; cin >> n >> k >> r >> c; r--, c--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i+j) % k == (r+c) % k) cout << 'X';
			else cout << '.';
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