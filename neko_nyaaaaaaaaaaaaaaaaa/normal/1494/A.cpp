#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	for (int i = 0; i < (1 << 3); i++) {
		string t;
		for (char c: s) {
			int k = c - 'A';
			if (i & (1 << k)) t.push_back('(');
			else t.push_back(')');
		}

		bool ok = 1; int sum = 0;
		for (char c: t) {
			if (c == '(') sum++;
			else sum--;

			if (sum < 0) {
				ok = 0; break;
			}
		}
		if (sum != 0) {
			ok = 0;
		}

		if (ok) {
			cout << "YES\n";
			return;
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