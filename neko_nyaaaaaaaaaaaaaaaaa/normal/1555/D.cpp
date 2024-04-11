#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	string s; cin >> s;

	int pref[n+1][3], pref2[n+1][3];
	memset(pref, 0, sizeof(pref));
	memset(pref, 0, sizeof(pref));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int ds = s[i] - (i % 3);
			if (ds < 'a') ds += 3;

			pref[i+1][j] = pref[i][j];
			if (j == (ds - 'a')) pref[i+1][j]++;
		}

		for (int j = 0; j < 3; j++) {
			int ds = s[i] + (i % 3);
			if (ds > 'c') ds -= 3;

			pref2[i+1][j] = pref2[i][j];
			if (j == (ds - 'a')) pref2[i+1][j]++;
		}
	}

	while (m--) {
		int l, r; cin >> l >> r;

		int ans = 0;
		for (int i = 0; i < 3; i++) {
			ans = max(ans, pref[r][i] - pref[l-1][i]);
			ans = max(ans, pref2[r][i] - pref2[l-1][i]);
		}
		cout << (r-l+1) - ans << '\n';
	}

	return 0;
}