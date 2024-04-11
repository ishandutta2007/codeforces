#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; string s; cin >> n >> s;

	int petr = 0;
	int c = 0;
	while (petr < n) {
		if (s[petr] == '(') {
			if (petr+1 == n) break;
			petr += 2; c++; continue;
		} else {
			int init = petr;
			petr++;
			while (petr < n) {
				if (s[petr] == ')') break;
				petr++;
			}
			if (petr < n) {
				petr++; c++; continue;
			} else {
				petr = init; break;
			}
		}
	}

	cout << c << ' ' << n-petr << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}