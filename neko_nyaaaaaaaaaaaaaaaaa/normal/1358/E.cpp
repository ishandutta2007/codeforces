#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	int m = (n+1)/2;
	vector<long long> a(m);
	for (long long &i: a) cin >> i;
	int x; cin >> x;

	reverse(a.begin(), a.end());
	vector<long long> pref(m);
	for (int i = 0; i < m; i++) {
		if (i == 0) {
			pref[i] = 1LL*x*(n - m) + a[i];
		} else {
			pref[i] = pref[i-1] + a[i];
		}
	}

	long long mn = 1e18;
	for (int i = m-1, k = n; i >= 0; i--, k--) {
		mn -= x;
		mn = min(mn, pref[i]);
		if (mn > 0) {
			cout << k << '\n';
			exit(0);
		}
	}
	cout << "-1\n";

	return 0;
}