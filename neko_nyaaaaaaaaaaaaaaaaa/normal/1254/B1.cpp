#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> p;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x) p.push_back(i);
	}
	if (p.size() == 1) {
		cout << -1; exit(0);
	}
	
	n = p.size();
	int ans = 1e18;
	for (int k = 2; k <= n; k++) {
		if (n % k == 0) {
			int tmp = 0;
			// partition into k parts
			for (int i = 0, j = k-1; i < n; i += k, j += k) {
				// take the median
				int m = p[j - k/2];

				for (int f = i; f <= j; f++) {
					tmp += abs(p[f] - m);
				}
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans << '\n';
 
	return 0;
}