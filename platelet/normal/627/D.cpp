#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)


using namespace std;
const int N = 2e5 + 5;
int n, K, mid, a[N], sz[N], si[N], f[N], g[N], g1[N];
vector <int> G[N];
void dfs(int u, int fa) {
	sz[u] = 1, si[u] = a[u] < mid, f[u] = !si[u];
	for(int v : G[u]) if(v ^ fa) {
		dfs(v, u), sz[u] += sz[v], si[u] += si[v];
		if(a[u] >= mid) {
			if(si[v]) {
				if(f[v] + g[v] > g[u]) g[u] = f[v] + g[v];
				else g1[u] = max(g1[u], f[v] + g[v]);
			} else f[u] += f[v];
		}
	}
}
int Dfs(int u, int fa) {
	if(f[u] + g[u] >= K) return 1;
	for(int v : G[u]) if(v ^ fa) {
		if(a[u] >= mid) {
			int gu = g[u], gv = g[v];
			if(si[v]) {
				if(f[v] + g[v] == g[u]) g[u] = g1[u];
			} else f[u] -= f[v];
			sz[u] -= sz[v], sz[v] += sz[u];
			si[u] -= si[v], si[v] += si[u];
			if(si[u]) g[v] = max(g[v], f[u] + g[u]);
			else f[v] += f[u];
			if(Dfs(v, u)) return 1;
			if(!si[u]) f[v] -= f[u];
			sz[v] -= sz[u], sz[u] += sz[v];
			si[v] -= si[u], si[u] += si[v];
			if(!si[v]) f[u] += f[v];
			g[u] = gu, g[v] = gv;
		} else {
			sz[u] -= sz[v], sz[v] += sz[u];
			si[u] -= si[v], si[v] += si[u];
			if(Dfs(v, u)) return 1;
			sz[v] -= sz[u], sz[u] += sz[v];
			si[v] -= si[u], si[u] += si[v];
		}
	}
	return 0;
}

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> K;
	rep(i, 1, n) scanf("%d", &a[i]);
	int u, v;
	rep(i, 2, n) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	int l = 1, r = 1e6;
	while(l <= r) {
		mid = (l + r) / 2;
		mem(f, 0), mem(g, 0), mem(g1, 0), dfs(1, 0);
		if(Dfs(1, 0)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r;
	return 0; 
}