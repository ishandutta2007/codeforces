#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, x, y, d;
	cin >> t;
	while (t--) {
		cin >> n >> x >> y >> d;
		int r = 1e9;
		if (abs(y - x) % d == 0) r = abs(y - x) / d;
		if ((y - 1) % d == 0) r = min(r, x / d + !!(x % d) + (y - 1) / d);
		if ((n - y) % d == 0) r = min(r, (n - x) / d + !!((n - x) % d) + (n - y) / d);
		cout << (r == 1e9 ? -1 : r) << '\n';
	}
}