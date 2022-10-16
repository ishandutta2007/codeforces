#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int ans[11][101][101];
	memset(ans, 0, sizeof(ans));

	int n, q, c; cin >> n >> q >> c;
	while (n--) {
		int x, y, s; cin >> x >> y >> s;
		for (int i = 0; i <= c; i++) {
			ans[i][x][y] += (s+i) % (c+1);
		}
	}

	for (int i = 0; i <= c; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int k = 1; k <= 100; k++) {
				ans[i][j][k] += ans[i][j-1][k] + ans[i][j][k-1] - ans[i][j-1][k-1];
			}
		}
	}

	while (q--) {
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;

		t %= (c+1);

		cout << ans[t][x2][y2] - ans[t][x1-1][y2] - ans[t][x2][y1-1] + ans[t][x1-1][y1-1] << '\n';
	}

	return 0;
}