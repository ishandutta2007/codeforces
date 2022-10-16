#include <bits/stdc++.h>
using namespace std;

bool check(int n, string s) {
	bool x = 0, y = 0;
	for (char c: s) {
		if (c == '<') x = 1;
		if (c == '>') y = 1;
	}
	if (x && y) return 0;
	return 1;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	if (check(n, s)) {
		cout << n << '\n'; return;
	}

	s.push_back(s[0]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '-' || s[i-1] == '-') ans++;
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