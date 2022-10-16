#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		long long n; cin >> n;
		n = (n+1)/2;
		cout << max(15LL, n*5) << '\n';
	}

	return 0;
}