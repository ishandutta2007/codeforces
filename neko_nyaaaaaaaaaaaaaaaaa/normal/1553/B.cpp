#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s, t; cin >> s >> t;
	for (int las = 0; las <= s.size(); las++) {
		string g;
		for (int i = 0; i < las; i++) {
			g.push_back(s[i]);
		}
		for (int i = las-2; i >= 0; i--) {
			g.push_back(s[i]);
		}

		// is t inside s?
		int pos = g.find(t);
		if (pos != -1) {
			cout << "YES\n"; return;
		}
	}
	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}