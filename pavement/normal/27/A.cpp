#include <bits/stdc++.h>
using namespace std;

int n, a[3005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1, c = 1; i <= n; i++, c++)
		if (c != a[i]) {
			cout << c << '\n';
			return 0;
		}
	cout << n + 1 << '\n';
}