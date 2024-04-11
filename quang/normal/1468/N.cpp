#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int c1, c2, c3, a1, a2, a3, a4, a5;
		cin >> c1 >> c2 >> c3 >> a1 >> a2 >> a3 >> a4 >> a5;
		c1 -= a1;
		c2 -= a2;
		c3 -= a3;

		bool ok = (c1 >= 0) && (c2 >= 0) && (c3 >= 0);
		ok &= (c1 + c3 >= a4) && (c2 + c3 >= a5) && (c1 + c2 + c3 >= a4 + a5);

		cout << (ok ? "YES\n" : "NO\n");

	}

	return 0;
}