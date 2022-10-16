#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; char c; string s;
	cin >> n >> c >> s;

	// 0
	if (*min_element(s.begin(), s.end()) == c && *max_element(s.begin(), s.end()) == c) {
		cout << "0\n\n";
		return;
	}

	// 1
	for (int x = 1; x <= n; x++) {
		bool ok = 1;
		for (int i = x; i <= n; i += x) {
			if (s[i-1] != c) {
				ok = 0; break;
			}
		}
		if (ok) {
			cout << "1\n" << x << '\n';
			return;
		}
	}

	// 2
	cout << "2\n" << n-1 << ' ' << n << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve(); 
	}

	return 0;
}