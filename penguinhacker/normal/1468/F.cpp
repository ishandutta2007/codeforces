#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		map<pair<int, int>, int> mp;
		while(n--) {
			int x, y, a, b; cin >> x >> y >> a >> b;
			x -= a, y -= b;
			assert(x != 0 || y != 0);
			if (x == 0) y = y > 0 ? 1 : -1;
			else if (y == 0) x = x > 0 ? 1 : -1;
			else {
				int g = __gcd(abs(x), abs(y));
				x /= g, y /= g;
			}
			++mp[{x, y}];
		}
		ll ans = 0;
		for (auto& x : mp) {
			pair<int, int> p = x.first;
			p.first *= -1, p.second *= -1;
			if (mp.find(p) != mp.end()) {
				int a = x.second;
				int b = mp[p];
				ans += (ll)a * b;
			}
		}
		assert(ans % 2 == 0);
		ans /= 2;
		cout << ans << "\n";
	}
	return 0;
}