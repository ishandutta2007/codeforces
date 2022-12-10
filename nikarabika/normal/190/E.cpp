#include <bits/stdc++.h>

using namespace std;

#undef next
#define next Next
#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 5e5 + 85 - 69;
vector<int> adj[maxn], vert[maxn];
int next[maxn], comp;
int n, m;

int root(int v){return (next[v] == v) ? v : next[v] = root(next[v]);}

void dfs(int v){
	vert[comp].PB(v);
	next[v] = v + 1;
	int p = 0;
	for(int u = root(1); u <= n; u = root(u + 1)){
		while(p < sz(adj[v]) and adj[v][p] < u) p++;
		if(p != sz(adj[v]) and adj[v][p] == u)
			continue;
		dfs(u);
	}
	return;
}

int main(){
	for(int i = 0; i < maxn; i++)
		next[i] = i;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		int fi, se;
		scanf("%d%d", &fi, &se);
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	for(int i = 1; i <= n; i++)
		if(next[i] == i)
			dfs(i), comp++;
	printf("%d\n", comp);
	for(int i = 0; i < comp; i++){
		printf("%d ", sz(vert[i]));
		for(auto v : vert[i])
			printf("%d ", v);
		printf("\n");
	}
	return 0;
}