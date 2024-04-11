#include <bits/stdc++.h>
using namespace std;

bool ok(string s, string t) {
	int n = s.size(), m = t.size();
	if ((n % 2) != (m % 2)) return 0;

	int j = 0;
	for (int i = 0; i < n;) {
		if (j < m && s[i] == t[j]) {
			j++; i++;
		} else {
			i += 2;
		}
	}
	return (j == m);
}

void solve() {
	bool yes = 0;
	string s, t; cin >> s >> t;
	if (ok(s, t)) yes = 1;
	s.erase(s.begin());
	if (ok(s, t)) yes = 1;

	if (yes) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}