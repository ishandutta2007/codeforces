#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

const int MAXN = 1e5+5;
pair<pair<int, int>, pair<int, int>> edges[MAXN]; // {{node, node}, {wt, idx}}
vector<pair<int, int>> spanTree[MAXN]; // {node, edgeidx}
int n, m, timer;
int root[MAXN];
int ans[MAXN];
int tin[MAXN], low[MAXN];

// DSU (expected O(n))


inline int findroot(int node) {
	return root[node]==node?node:root[node]=findroot(root[node]);
}



// DFS for detecting bridges using Tarjan's algo (expected O(m))

void dfs(int node, int p) {
	low[node] = tin[node] = ++timer;
	for(auto u: spanTree[node]) {
		if(u.S==p) continue;
		if(tin[u.F]==-1) {
			dfs(u.F, u.S);
			if(low[u.F]>tin[node]) ans[u.S] = 1;
			low[node] = min(low[node], low[u.F]);
		} else {
			low[node] = min(low[node], tin[u.F]);
		}
	}
}


// solving for edges with indices from l to r (all of them have same wt)

void solve(int l, int r) {
	// init
	for(int i=l;i<=r;i++) {
		int u = findroot(edges[i].F.F);
		int v = findroot(edges[i].F.S);
		spanTree[u].clear();
		spanTree[v].clear();
		tin[u] = tin[v] = -1;
	}
		
	// connect edges to graph
	for(int i=l;i<=r;i++) {
		int u = findroot(edges[i].F.F);
		int v = findroot(edges[i].F.S);
		if(u==v) {
			ans[edges[i].S.S] = 0;
		} else {
			ans[edges[i].S.S] = 2;
			spanTree[u].emplace_back(make_pair(v, edges[i].S.S));
			spanTree[v].emplace_back(make_pair(u, edges[i].S.S));
		}
	}

	// check for bridges
	for(int i=l;i<=r;i++) {
		int u = findroot(edges[i].F.F);
		int v = findroot(edges[i].F.S);
		if(tin[u]==-1) dfs(u, -1);
	}

	// unite components
	for(int i=l;i<=r;i++) root[findroot(edges[i].F.F)] = findroot(edges[i].F.S);

}	



int main() {
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++) {
		scanf("%d%d%d", &edges[i].F.F, &edges[i].F.S, &edges[i].S.F);
		--edges[i].F.F; --edges[i].F.S;
		edges[i].S.S = i;
	}
	
	// sorting (expected O(m log m))
	{
		sort(edges, edges+m, [&](pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y) {
			return x.S.F<y.S.F;
		});
	}
	for(int i=0;i<n;i++) {
		root[i] = i;
	}

	for(int i=0;i<m;i++) {
		int j = i;
		while(edges[j].S.F==edges[i].S.F) ++j;
		--j;
		solve(i, j); // solve for all edges of same weight simultaneously
		i = j;
	}

	for(int i=0;i<m;i++) {
		if(ans[i]==0) puts("none");
		else if(ans[i]==1) puts("any");
		else puts("at least one");
	}

}