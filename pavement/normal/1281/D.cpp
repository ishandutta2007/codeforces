#include <bits/stdc++.h>
using namespace std;

char f[65][65];
int pr[65][65];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, r, c;
	cin >> t;
	while (t--) {
		memset(pr, 0, sizeof pr);
		cin >> r >> c;
		bool h = 0, nh = 0;
		int ans = 4;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				cin >> f[i][j], h = max(h, f[i][j] == 'A'), nh = max(nh, f[i][j] == 'P'), pr[i][j] = (f[i][j] == 'A') + pr[i - 1][j] + pr[i][j - 1] - pr[i - 1][j - 1];
		if (!h) {
			cout << "MORTAL\n";
			continue;
		}
		if (!nh) {
			cout << "0\n";
			continue;
		}
		if (pr[1][c] == c) ans = min(ans, 1);
		else if (f[1][1] == 'A' || f[1][c] == 'A') ans = min(ans, 2);
		else if (pr[1][c] > 0) ans = min(ans, 3);
		if (pr[r][1] == r) ans = min(ans, 1);
		else if (f[1][1] == 'A' || f[r][1] == 'A') ans = min(ans, 2);
		else if (pr[r][1] > 0) ans = min(ans, 3);
		if (pr[r][c] - pr[r][c - 1] == r) ans = min(ans, 1);
		else if (f[1][c] == 'A' || f[r][c] == 'A') ans = min(ans, 2);
		else if (pr[r][c] - pr[r][c - 1] > 0) ans = min(ans, 3);
		if (pr[r][c] - pr[r - 1][c] == c) ans = min(ans, 1);
		else if (f[r][1] == 'A' || f[r][c] == 'A') ans = min(ans, 2);
		else if (pr[r][c] - pr[r - 1][c] > 0) ans = min(ans, 3);
		for (int i = 1; i <= r; i++)
			if (pr[i][c] - pr[i - 1][c] == c) ans = min(ans, 2);
		for (int i = 1; i <= c; i++)
			if (pr[r][i] - pr[r][i - 1] == r) ans = min(ans, 2);
		cout << ans << '\n';
	}
}