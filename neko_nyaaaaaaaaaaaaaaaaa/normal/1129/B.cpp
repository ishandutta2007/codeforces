#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int k; cin >> k;

	cout << "2000\n";
	cout << "-1 2";

	int need = k+2000-2;

	for (int i = 2; i < 2000; i++) {
		if (need > 1000000) {
			cout << " 1000000";
			need -= 1000000;
		} else {
			cout << ' ' << need;
			need -= need;
		}
	}

	return 0;
}