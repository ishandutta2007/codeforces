#include <stdio.h>
#include <vector>

#define N 6010

using namespace std;

vector<int> adj[N];

int LCA[N][N];
int r[N], H[N], P[N];
int n, ans;

int dp_dec[N], dp_inc[N];

void dfs_H(int u, int p, int h) {
	H[u] = h;
	P[u] = p;
	for(int i = 0;i < adj[u].size();i++) {
		int v = adj[u][i];
		if(v == p) {
			continue;
		}
		dfs_H(v, u, h+1);
	}
}
int dfs_LCA(int u, int v) {
	if(LCA[u][v]) {
		return LCA[u][v];
	}
	if(u == v) {
		return LCA[u][v] = u;
	}
	if(H[u] >= H[v]) {
		return LCA[u][v] = dfs_LCA(P[u], v);
	}else {
		return LCA[u][v] = dfs_LCA(u, P[v]);
	}
}
void dfs_dp(int u, int p) {
	for(int i = 0;i < adj[u].size();i++) {
		int v = adj[u][i];
		if(v == p) {
			continue;
		}
		dfs_dp(v, u);
	}
	dp_dec[u] = dp_inc[u] = 1;
	for(int i = 1;i <= n;i++) {
		if(i == u) {
			continue;
		}
		if(LCA[i][u] == u) {
			if(r[i] > r[u]) {
				dp_inc[u] = max(dp_inc[u], dp_inc[i] + 1);
			}
			if(r[i] < r[u]) {
				dp_dec[u] = max(dp_dec[u], dp_dec[i] + 1);
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &r[i]);
	}
	for(int i = 0;i < n-1;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs_H(1, -1, 1);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			LCA[i][j] = dfs_LCA(i, j);
		}
	}
	dfs_dp(1, -1);
	
	ans = 0;
	for(int i = 1;i <= n;i++) {
		ans = max(ans, dp_dec[i]);
		ans = max(ans, dp_inc[i]);
		for(int j = 1;j <= n;j++) {
			if(i == j || LCA[i][j] == i || LCA[i][j] == j) {
				continue;
			}
			int lca = LCA[i][j];
			if(r[i] > r[j]) {
				ans = max(ans, dp_inc[i] + dp_dec[j] + (r[j] < r[lca] && r[lca] < r[i]));
			}
			if(r[i] < r[j]) {
				ans = max(ans, dp_dec[i] + dp_inc[j] + (r[i] < r[lca] && r[lca] < r[j]));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}