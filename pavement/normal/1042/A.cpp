#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mt make_tuple
#define mp make_pair

int a[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, tmax = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], tmax = max(tmax, a[i]);
	for (int i = 1; i <= m; i++) {
		int cur = 1e9, pos = -1;
		for (int i = 1; i <= n; i++)
			if (cur > a[i]) {
				cur = a[i];
				pos = i;
			}
		a[pos]++;
	}
	cout << *max_element(a + 1, a + 1 + n) << ' ' << tmax + m << '\n';
}