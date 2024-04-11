#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;

	long long ft = 1;
	for (int i = 1; i < n/2; i++) {
		ft *= i;
	}

	long long ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		if (__builtin_popcount(i) == n/2) {
			ans += ft*ft;
		}
	}
	cout << ans/2 << '\n';

	return 0;
}