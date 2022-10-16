#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, m; cin >> n >> m;
	if (m < n) {
		cout << "No\n";
		return;
	} else if (n % 2) {
		cout << "Yes\n";
		for (int i = 0; i < n; i++) {
			if (i == n-1) {
				cout << m << '\n';
			} else {
				cout << "1 ";
				m--;
			}
		}
	} else {
		if (m % 2) {
			cout << "No\n";
			return;
		}

		cout << "Yes\n";
		for (int i = 0; i < n; i++) {
			if (i+2 >= n) {
				cout << m/2 << ' ';
			} else {
				cout << "1 ";
				m--;
			}
		}
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}