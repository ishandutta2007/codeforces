#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int x, y; cin >> x >> y;
		ll ans = 0;
		for (int b = 2; b <= min(32000, y); ++b) {
			ans += min(b - 1, x / (b + 1));
		}
		for (int l = min(32000, y) + 1; l <= y;) {
			int d = x / (l + 1);
			if (d == 0) break;
			int r = min(y, x / d - 1);
			assert(l <= r);
			ans += (ll)(r - l + 1) * d;
			l = r + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}