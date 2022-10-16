#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	string s; cin >> s;
	// zero forms one segment
	int l = -1, r = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			if (l == -1) l = i;
			r = i;
		}
	}

	if (l == -1) {
		cout << "0\n";
		return;
	}

	for (int i = l; i <= r; i++) {
		if (s[i] == '1') {
			cout << "2\n";
			return;
		}
	}

	cout << "1\n";
	return;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}