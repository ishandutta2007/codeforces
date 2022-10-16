#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// if all 0 --> 0
	bool all_z = 1;
	for (int i: a) {
		if (i > 0) all_z = 0;
	}
	if (all_z) {
		cout << "0\n";
		return;
	}

	// if non-0 form subarray --> 1
	int l = -1, r = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			if (l == -1) l = i;
			r = i;
		}
	}
	bool one = 1;
	for (int i = l; i <= r; i++) {
		if (a[i] == 0) one = 0;
	}
	if (one) {
		cout << "1\n";
		return;
	}

	// else, 2
	cout << "2\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}