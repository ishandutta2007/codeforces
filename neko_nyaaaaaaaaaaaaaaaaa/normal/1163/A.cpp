#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;
	if (m == 0) {
		cout << 1;
		return 0;
	}
	if (m == n) {
		cout << 0;
		return 0;
	}

	cout << min(n - m, m);

	return 0;
}