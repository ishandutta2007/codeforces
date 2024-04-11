#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n, s; cin >> n >> s;
		if (n % 2) {
			n -= n/2;
		} else {
			n -= (n/2) - 1;
		}
		cout << s/n << '\n';
	}

	return 0;
}