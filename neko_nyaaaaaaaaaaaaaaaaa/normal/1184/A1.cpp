#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	long long r; cin >> r;
	for (long long x = 1;; x++) {
		long long c = r - (x*x + x + 1);
		if (c > 0 && c % (2*x) == 0) {
			cout << x << ' ' << c/(2*x) << '\n';
			exit(0);
		} else if (c <= 0) break;
	}
	cout << "NO\n";

	return 0;
}