#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e15;

void solve() {
	int n; cin >> n;
	map<pair<int, int>, int> mp;
	map<int, int> ml, mr;
	int mn = INF, mx = -INF;

	while (n--) {
		int l, r, c; cin >> l >> r >> c;
		mn = min(mn, l); mx = max(mx, r);

		if (mp.find({l, r}) == mp.end()) mp[{l, r}] = c;
		else mp[{l, r}] = min(c, mp[{l, r}]);

		if (ml.find(l) == ml.end()) ml[l] = c;
		else ml[l] = min(ml[l], c);

		if (mr.find(r) == mr.end()) mr[r] = c;
		else mr[r] = min(mr[r], c);

		int ans = INF;
		if (mp.find({mn, mx}) != mp.end()) {
			ans = min(ans, mp[{mn, mx}]);
		}
		ans = min(ans, ml[mn] + mr[mx]);
		cout << ans << '\n';
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