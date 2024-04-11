#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		int l = -1, r = -1;
		for (int i = 1; i < n; i++) {
			if (max(a[i], a[i-1]) - min(a[i], a[i-1]) >= 2) {
				l = i, r = i+1; break;
			}
		}
		if (l != -1) {
			cout << "YES\n" << l << ' ' << r << '\n';
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}