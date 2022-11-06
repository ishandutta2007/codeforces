#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= 2 * n; i++) cin >> a[i];
		sort(a + 1, a + 1 + 2 * n);
		cout << a[n + 1] - a[n] << '\n';
	}
}