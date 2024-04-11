#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	string s; cin >> s;
	// must end with B lol
	if (s.back() != 'B') {
		cout << "NO\n";
		return;
	}

	int sum = 0;
	for (char c: s) {
		if (c == 'B') sum--;
		else sum++;

		if (sum < 0) {
			cout << "NO\n";
			return;
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