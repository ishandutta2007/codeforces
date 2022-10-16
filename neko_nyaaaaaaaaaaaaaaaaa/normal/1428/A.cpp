#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int ans = abs(a-c) + abs(b-d);

		if (a != c && b != d) ans += 2;
		cout << ans << '\n';
	}

	return 0;
}