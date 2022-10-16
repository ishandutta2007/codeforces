#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;

	map<pair<int, int>, int> p;
	int ans = 0;

	while (n--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int x = x2 - x1, y = y2 - y1;
		int g = abs(__gcd(x, y));
		x /= g; y /= g;

		ans += p[{-x, -y}];
		p[{x, y}]++;
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