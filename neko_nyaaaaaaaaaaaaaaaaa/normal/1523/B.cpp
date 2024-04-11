#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << 6*(n/2) << '\n';
	for (int i = 1; i <= n; i += 2) {
		cout << "2 " << i << ' ' << i+1 << '\n'; a[i+1] -= a[i];
		cout << "1 " << i << ' ' << i+1 << '\n'; a[i] += a[i+1];
		cout << "2 " << i << ' ' << i+1 << '\n'; a[i+1] -= a[i];
		cout << "1 " << i << ' ' << i+1 << '\n'; a[i] += a[i+1];
		cout << "2 " << i << ' ' << i+1 << '\n'; a[i+1] -= a[i];
		cout << "1 " << i << ' ' << i+1 << '\n'; a[i] += a[i+1];
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}