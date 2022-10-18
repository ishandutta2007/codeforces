#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		long long x; cin >> x;
		if (x < 15) {
			cout << "NO\n";
		} else if ((x % 14) > 0 && (x % 14) <= 6) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}