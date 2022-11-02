#include <algorithm>
#include <stdio.h>
#include <string.h>
struct Edge {
	int u, t;
	Edge *back;
} e[5001], *head[5001];
int n, m, T, dp[5001][5001];
short from[5001][5001];
bool vis[5001] = {};
void dfs(int x) {
	if(vis[x]) return;
	vis[x] = 1;
	register int i;
	register Edge *j;
	if(x == 1) dp[x][1] = 0;
	for(j = head[x]; j; j = j->back) {
		dfs(j->u);
		for(i = 2; i <= n; ++i) {
			if(~dp[j->u][i - 1] && (dp[x][i] == -1 || dp[j->u][i - 1] + j->t < dp[x][i])) {
				dp[x][i] = dp[j->u][i - 1] + j->t;
				if(dp[x][i] > T) dp[x][i] = -1;
				from[x][i] = j->u;
			}
		}
	}
}
void solve(int x, int y) {
	if(x != 1) solve(from[x][y], y - 1);
	printf("%d ", x);
}
int main() {
	int i, v;
	scanf("%d%d%d", &n, &m, &T);
	for(i = 0; i < m; ++i) {
		scanf("%d%d%d", &e[i].u, &v, &e[i].t);
		e[i].back = head[v];
		head[v] = e + i;
	}
	memset(dp, -1, sizeof dp);
	dfs(n);
	for(i = n; i >= 1; --i) if(~dp[n][i]) break;
	printf("%d\n", i);
	solve(n, i);
	return 0;
}