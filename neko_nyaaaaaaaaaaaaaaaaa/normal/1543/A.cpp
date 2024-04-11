#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		long long a, b; cin >> a >> b;
		if (a == b) cout << "0 0\n";
		else {
			int g = abs(a-b);
			cout << g << ' ' << min(a % g, g - (a % g)) << '\n';
		}
	}

	return 0;
}