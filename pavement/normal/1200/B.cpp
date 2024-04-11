#include <bits/stdc++.h>
using namespace std;
#define int long long

int h[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		bool c = 0;
		for (int i = 1; i <= n; i++) cin >> h[i];
		for (int i = 1; i < n; i++) {
			if (abs(h[i + 1] - h[i]) <= k || h[i] > h[i + 1] + k) m += h[i] - max(0ll, h[i + 1] - k);
			else if (m >= h[i + 1] - k - h[i]) m -= h[i + 1] - k - h[i];
			else c = 1;
		}
		if (c) cout << "NO\n";
		else cout << "YES\n";
	}
}