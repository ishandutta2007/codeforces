#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a;
		for (int i = 1; i <= n; i++) {
			a.push_back(i);
		}
		reverse(a.begin(), a.end());

		int dx = 5;
		if (n <= 24) dx = 4;
		if (n <= 6) dx = 3;

		for (int i = 1; i <= n; i++) {
			for (int j: a) cout << j << ' ';
				cout << '\n';
			prev_permutation(a.begin(), a.begin() + dx);
		}
	}

	return 0;
}