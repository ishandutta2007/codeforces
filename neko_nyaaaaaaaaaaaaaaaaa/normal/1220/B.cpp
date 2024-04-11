#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ans[n];
	ans[0] = (a[0][1] * a[0][2]) / a[1][2];
	ans[0] = sqrtl(ans[0]);

	cout << ans[0] << ' ';
	for (int i = 1; i < n; i++) {
		ans[i] = a[0][i]/ans[0];
		cout << ans[i] << ' ';
	}

	return 0;
}