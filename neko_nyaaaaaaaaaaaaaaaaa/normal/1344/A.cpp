#include <bits/stdc++.h>
using namespace std; 

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> taken(n);
	for (int i = 0; i < n; i++) {
		int k = i;
		int nxt = k + (a[i] % n);
		nxt %= n;
		if (nxt < 0) nxt += n;

		taken[nxt] = 1;
	}

	for (int i: taken) {
		if (i == 0) {
			cout << "NO\n"; return;
		}
	}
	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}