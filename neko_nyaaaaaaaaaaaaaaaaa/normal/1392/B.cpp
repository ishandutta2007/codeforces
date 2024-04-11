#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int d = *max_element(a.begin(), a.end());
		k--;

		for (int i = 0; i < n; i++) {
			a[i] = d - a[i];
		}

		if (k % 2) {
			d = *max_element(a.begin(), a.end());
			for (int i = 0; i < n; i++) {
				a[i] = d - a[i];
			}
		}
		for (int i: a) cout << i << ' ';
		cout << '\n';
	}

	return 0;
}