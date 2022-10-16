#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, d; cin >> n >> d;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		while (d--) {
			for (int i = 1; i < n; i++) {
				if (a[i]) {
					a[i-1]++;
					a[i]--;
					break;
				}
			}
		}
		cout << a[0] << '\n';
	}

	return 0;
}