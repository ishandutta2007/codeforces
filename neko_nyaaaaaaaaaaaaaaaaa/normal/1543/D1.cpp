#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, k; cin >> n >> k;
	int xr = 0;
	for (int i = 0; i < n; i++) {
		cout << (i^xr) << endl;
		int rs; cin >> rs;
		if (rs == 0) {
			xr = i;
		} else {
			return;
		}
	}
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve(); 
	}

	return 0;
}