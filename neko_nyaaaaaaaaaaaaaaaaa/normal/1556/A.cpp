#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int c, d; cin >> c >> d;
	if (c == 0 && d == 0) {
		cout << "0\n";
		return;
	}

	if (c == d) {
		cout << "1\n";
		return;
	}

	if ((c % 2) != (d % 2)) {
		cout << "-1\n";
		return;
	}

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