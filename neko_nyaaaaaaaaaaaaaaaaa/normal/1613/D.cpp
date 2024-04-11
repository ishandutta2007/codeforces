#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> dp0, dp1, dp2; int ans = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;

			int d0 = (x == 0), d1 = (x == 1), d2 = 0;
			d0 = (d0 + dp0[x] + dp0[x-1]) % M;
			d1 = (d1 + dp0[x-2] + dp1[x] + dp2[x-2]) % M;
			d2 = (d2 + dp1[x+2] + dp2[x]) % M;

			dp0[x] = (dp0[x] + d0) % M;
			dp1[x] = (dp1[x] + d1) % M;
			dp2[x] = (dp2[x] + d2) % M;

			ans = (ans + d0 + d1 + d2) % M;
		}
		cout << ans << '\n';
	}

	return 0;
}