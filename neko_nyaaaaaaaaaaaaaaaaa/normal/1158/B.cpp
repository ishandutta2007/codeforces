#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k; cin >> n >> k;
	if (n == k) {
		while (n--) {
			cout << 1;
		}
		exit(0);
	}
	if (k == 1) {
		cout << 0;
		while (--n) {
			cout << 1;
		}
		exit(0);
	}

	int f;
	for (f = 2; f < n; f++) {
		// length f
		// concat twice

		int len = f*2;

		if (len + (k - 2) <= n && len + (k - 1) > n) {
			for (int i = 0; i < n; i++) {
				if (i % f == 0) cout << 1;
				else cout << 0;
			}
			exit(0);
		}
	}

	return 0;
}