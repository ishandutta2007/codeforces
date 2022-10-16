#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n; 
	int lc = 1;

	int ans = n % 1000000007;
	for (int i = 2; lc <= n; i++) {
		ans = (ans + n/lc) % 1000000007;
		lc = lcm(i, lc);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}