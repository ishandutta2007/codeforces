#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	int prv; cin >> prv;
	int ans = 0;
	while (--n) {
		int x; cin >> x;
		if (x < prv) {
			int diff = prv - x;	

			int sec = 0;
			while (diff > 0) {
				sec++; diff /= 2;
			}
			ans = max(ans, sec);
		} 
		prv = max(prv, x);
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