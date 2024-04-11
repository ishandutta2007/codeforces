#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, d, e; cin >> n >> d >> e;
	e *= 5;

	int ans = n;
	for (int dol = 0; dol*d <= n; dol++) {
		int eu = (n - (dol*d))/e;
		ans = min(ans, n - dol*d - eu*e);
	}
	cout << ans;

	return 0;
}