#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, z; cin >> n >> z;
	int ans = 0;
	while (n--) {
		int x; cin >> x;
		ans = max(ans, x | z);
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