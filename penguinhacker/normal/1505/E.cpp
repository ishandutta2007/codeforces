#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, d[5][5];
string g[5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> g[i];
	memset(d, 0x3f, sizeof(d));
	for (int i = n - 1; ~i; --i)
		for (int j = m - 1; ~j; --j) {
			if (g[i][j] == '*') {
				d[i][j] = 0;
				continue;
			}
			if (i < n - 1) d[i][j] = min(d[i + 1][j] + 1, d[i][j]);
			if (j < m - 1) d[i][j] = min(d[i][j], d[i][j + 1] + 1);
		}
	int i = 0, j = 0, ans = 0;
	while(1) {
		ans += g[i][j] == '*';
		if (i == n - 1 && j == m - 1)
			break;
		if (i == n - 1)
			++j;
		else if (j == m - 1)
			++i;
		else if (d[i][j + 1] <= d[i + 1][j])
			++j;
		else
			++i;
	}
	cout << ans;
	return 0;
}