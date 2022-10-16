#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		int no = 1;
		for (int i = 1; i < n; i++) {
			if (a[i-1] <= a[i]) no = 0;
		}
		if (no) cout << "NO\n"; else cout << "YES\n";
	}

	return 0;
}