#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int x1, x2, y1, y2; 
		cin >> x1 >> y1 >> x2 >> y2;
		cout << 1LL*(x2 - x1)*(y2 - y1) + 1 << '\n';
	}

	return 0;
}