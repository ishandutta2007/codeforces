#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	vector<int> p(2*n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int d = i+j;
			a[i][j] = p[d];
			p[d] ^= (1LL << d);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

	int q; cin >> q;
	while (q--) {
		int k; cin >> k;
		int x = 0, y = 0;

		while (x != n-1 || y != n-1) {
			cout << x+1 << ' ' << y+1 << endl;
			if (x == n-1) {
				y++;
			} else if (y == n-1) {
				x++;
			} else {
				int d = x+y+1;
				int f1 = k & (1LL << d);
				int f2 = a[x+1][y] & (1LL << d);
				if (f1 == f2) x++;
				else y++;
			}
		}
		cout << x+1 << ' ' << y+1 << endl;
	}

	return 0;
}