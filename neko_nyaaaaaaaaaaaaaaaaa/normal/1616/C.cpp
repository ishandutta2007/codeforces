#include <bits/stdc++.h>
using namespace std;

#define int long long
const double eps = 1e-8;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = n-1;
	// let's fix two elements
	// calculate the rest
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			double d = 1.0*(a[j] - a[i])/(j-i);

			int keep = 0;
			for (int k = 0; k < n; k++) {
				double val = a[i] + d*(k-i);
				if (abs(val - a[k]) < eps) keep++;
			}
			ans = min(ans, n-keep);
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}