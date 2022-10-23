#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int a[N], f[N][N][N], g[N][N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	memset(f, 0xcf, sizeof f);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int v = a[j];
			for (int k = 0; k <= i; ++k) {
				if (k > 0)
					f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + v);
				int t = j - i;
				if (t >= 0 && t <= k) 
					f[i][j][k] = max(f[i][j][k], g[k - t][j - 1] + v);
			}
		}
		for (int j = 1; j <= n; ++j)
			for (int k = 0; k <= i; ++k)
				g[k][j] = max(g[k][j], f[i][j][k]);
		for (int j = 0; j <= i; ++j)
			for (int k = 1; k <= n; ++k) {
				ans = max(g[j][k] = max(g[j][k], g[j][k - 1]), ans);
			}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}