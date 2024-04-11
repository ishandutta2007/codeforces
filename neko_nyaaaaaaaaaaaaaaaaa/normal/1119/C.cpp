#include <bits/stdc++.h>
using namespace std;

int r[508], c[508];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			r[i] += x;
			c[j] += x; 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			r[i] -= x;
			c[j] -= x; 
		}
	}

	for (int i = 0; i < n; i++) {
		if (r[i] % 2 != 0) {cout << "No"; return 0;} 
	}
	for (int i = 0; i < m; i++) {
		if (c[i] % 2 != 0) {cout << "No"; return 0;} 
	}
	cout << "Yes";

	return 0;
}