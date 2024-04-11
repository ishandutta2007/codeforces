#include <cstdio>
#include <vector>

const int N = 100000;

std::vector <int> edge[N];

bool vis[N];
int dfs (int x, int par) {
	vis[x] = 1;
	
	int ret = 1;
	for (int i=0; i<edge[x].size(); i++) {
		int v = edge[x][i];
		if (v == par) continue;
		
		if (vis[v]) ret = 0;
		else ret &= dfs (v, x);
	}
	
	return ret;
}

int n, m;

int main () {
	scanf ("%d %d", &n, &m);
	
	int u, v;
	for (int i=0; i<m; i++) {
		scanf ("%d %d", &u, &v);
		u--, v--;
		
		edge[u].push_back (v);
		edge[v].push_back (u);
	}
	
	int ans = 0;
	for (int i=0; i<n; i++) {
		if (vis[i]) continue;
		ans += dfs(i, i);
	}
	
	printf ("%d\n", ans);
	return 0;
}