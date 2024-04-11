#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, x, y, a, b;
	cin >> t;
	while (t--) {
		cin >> x >> y >> a >> b;
		int lo = 0, hi = 1e9, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (x + a * mid >= y - b * mid) {
				ans = mid;
				hi = mid - 1;
			} else lo = mid + 1;
		}
		if (x + a * ans == y - b * ans) cout << ans << '\n';
		else cout << "-1\n";
	}
}