#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if ((n % 2) == 1) {
		n--; a.pop_back();
	}

	int ans = 0;
	for (int i = 0; i < n; i += 2) {
		int pf = 0, ng = 0;
		for (int j = i+1; j < n; j += 2) {
			if (ng == 0) {
				ans += min(a[i], a[j]); 
			} else {
				// left: spend ng to equalize
				// right: spend at least pf to equalize
				
				int l = a[i] - ng;
				int r = a[j] - pf;

				if (l >= 0 && r >= 0) ans += min(l, r) + 1; 
			}

			pf -= a[j];
			if (pf < 0) {
				ng -= pf;
				pf = 0;
			}
			if (j+1 < n) pf += a[j+1];
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}