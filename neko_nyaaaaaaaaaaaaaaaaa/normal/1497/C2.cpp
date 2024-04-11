#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		while (k > 3) {
			k--; n--; cout << "1 ";
		}

		if (n % 2) {
			cout << "1 " << (n-1)/2 << ' ' << (n-1)/2 << '\n';
		} else if (n % 4) {
			cout << "2 " << (n-2)/2 << ' ' << (n-2)/2 << '\n';
		} else {
			cout << n/4 << ' ' << n/2 << ' ' << n/4 << '\n';  
		}
	}
	
	return 0;
}