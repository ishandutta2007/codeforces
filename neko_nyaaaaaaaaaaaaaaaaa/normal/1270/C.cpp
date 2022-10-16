#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		long long sum = 0, xr = 0;
		for (int i = 0; i < n; i++) {
			long long x; cin >> x;
			sum += x; xr ^= x;
		}

		long long gx = (1LL << 58);
		if (sum % 2) gx++;

		sum += gx; xr ^= gx;
		xr *= 2;

		long long gg = xr - sum;

		cout << "3\n";
		cout << gx << ' ' << gg/2 << ' ' << gg/2 << '\n';
	}

	return 0;
}