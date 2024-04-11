#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
ll ans, dp[1 << 19][19];
bool e[19][19];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v, --u, --v;
		e[u][v] = e[v][u] = 1;
	}
	for (int i = 0; i < n; ++i)
		dp[1 << i][i] = 1;
	for (int i = 1; i < (1 << n); ++i) {
		int small = __builtin_ctz(i);
		for (int j = small; j < n; ++j)
			if (i & (1 << j)) {
				if (dp[i][j] == 0)
					continue;
				if (__builtin_popcount(i) >= 3 && e[j][small])
					ans += dp[i][j];
				for (int k = small + 1; k < n; ++k)
					if (!(i & (1 << k)) && e[j][k])
						dp[i | (1 << k)][k] += dp[i][j];
			}
	}
	cout << ans / 2;
	return 0;
}