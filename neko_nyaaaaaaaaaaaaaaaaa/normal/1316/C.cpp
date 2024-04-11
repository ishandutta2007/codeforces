#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, p; cin >> n >> m >> p;
	int pos1 = n, pos2 = m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x % p) pos1 = i;
	}
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (x % p) pos2 = i;
	}
	cout << pos1 + pos2 << endl;

	return 0;
}