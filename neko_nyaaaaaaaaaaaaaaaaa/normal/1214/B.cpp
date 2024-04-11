#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int b, g, n; cin >> b >> g >> n;
	int ans = 0;
	for (int boy = 0; boy <= min(n, b); boy++) {
		int girl = n - boy;
		if (girl > g) continue;

		ans++;
	}
	cout << ans;

	return 0;
}