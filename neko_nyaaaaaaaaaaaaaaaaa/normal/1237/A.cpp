#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	int delta = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x % 2 == 0) {
			cout << x/2 << '\n';
		} else {
			if (delta) {
				if (x > 0) {
					cout << x/2 << '\n';
				} else {
					cout << (x/2) - 1 << '\n';
				}
				delta = 0;
			} else {
				if (x > 0) {
					cout << (x/2) + 1 << '\n';
				} else {
					cout << x/2 << '\n';
				}
				delta = 1;
			}
		} 
	}



	return 0;
}