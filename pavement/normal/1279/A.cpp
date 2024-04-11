#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, a[3];
	cin >> t;
	while (t--) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3, greater<int>());
		a[0] -= a[2];
		a[1] -= a[2];
		a[0] -= a[1];
		if (a[0] <= a[2] + 1) cout << "Yes\n";
		else cout << "No\n";
	}
}