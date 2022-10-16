#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	int ans = n, op = 0;
	char prv = '?';
	for (char c: s) {
		if (c == '(') {
			op++;
			if (prv == ')') ans--;
		} else {
			op--;
		}
		prv = c;
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