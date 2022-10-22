#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N, K;
long long dp[105][42]; // node, dis to black, dis to uncovered white
vector<int> c[105], v[105];

void dfs(int x, int p) {
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) dfs(v[x][i], x);
	if (v[x].size() == 0) dp[x][K + 1] = dp[x][0] = 1;
	else {
		long long dp2[v[x].size()][42][42]; // n, min, max
		memset(dp2, 0, sizeof(dp2));
		for (int j = 0; j <= 2 * K; j++) dp2[0][j][j] = dp[v[x][0]][j];
		for (int i = 1; i < v[x].size(); i++) {
			for (int j = 0; j <= 2 * K; j++) {
				for (int k = 0; k <= 2 * K; k++) {
					for (int l = k; l <= 2 * K; l++) {
						int newmn = min(k, j), newmx = max(l, j);
						dp2[i][newmn][newmx] += (dp2[i - 1][k][l] * dp[v[x][i]][j]) % MOD;
						dp2[i][newmn][newmx] %= MOD;
					}
				}
			}
		}
		for (int k = 0; k <= 2 * K; k++) {
			for (int l = k; l <= 2 * K; l++) {
				int newval;
				if (k + l >= 2 * K) {
					// they don't cover each other
					newval = max(k, l) + 1;
				} else newval = min(k, l) + 1;
				dp[x][0] += dp2[v[x].size() - 1][k][l];
				dp[x][0] %= MOD;
				if (newval <= 2 * K) {
					dp[x][newval] += dp2[v[x].size() - 1][k][l];
					dp[x][newval] %= MOD;
				}
			}
		}
	}
	//for (int k = 0; k <= 2 * K; k++) printf("%d %d = %lld\n", x, k, dp[x][k]);
}

void dfs2(int x, int p) {
	for (int i = 0; i < c[x].size(); i++) {
		if (c[x][i] == p) continue;
		else {
			//printf("%d to %d\n", x, c[x][i]);
			v[x].push_back(c[x][i]);
			dfs2(c[x][i], x);
		}
	}
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		c[a].push_back(b);
		c[b].push_back(a);
	}
	dfs2(0, -1);
	dfs(0, -1);
	long long ans = 0;
	for (int i = 0; i <= K; i++) {
		ans += dp[0][i];
		ans %= MOD;
	}
	printf("%lld\n", ans);
}