#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 1e5 + 85 - 69, maxl = 20, maxsq = 320;
vector<int> adj[maxn], red;
int bfs_h[maxn], dis[maxn], h[maxn], par[maxn][maxl];
bool mark[maxn];
int n, m;
queue<int> Q;

void add_edge(int v, int u){
	adj[v].PB(u);
	adj[u].PB(v);
	return;
}

void dfs(int x, int p = -1){
	par[x][0] = p;
	for(int i = 1; i < maxl; i++)
		if(par[x][i - 1] != -1)
			par[x][i] = par[par[x][i - 1]][i - 1];
	for(auto y : adj[x])
		if(y != p){
			h[y] = h[x] + 1;
			dfs(y, x);
		}
	return;
}

int lca(int v, int u){
	if(h[v] < h[u])
		swap(v, u);
	int d = h[v] - h[u];
	for(int i = 0; i < maxl; i++)
		if((d >> i) & 1)
			v = par[v][i];
	//cout << v << ' ' << u << endl
	//	<< h[v] << ' ' << h[u] << endl;;
	if(v == u)
		return v;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

void bfs(){
	memset(mark, false, sizeof mark);
	for(auto v : red)
		mark[v] = true, bfs_h[v] = 0, Q.push(v);
	while(Q.size()){
		int v = Q.front();
		dis[v] = min(dis[v], bfs_h[v]);
		Q.pop();
		for(auto u : adj[v])
			if(!mark[u])
				mark[u] = true, bfs_h[u] = bfs_h[v] + 1, Q.push(u);
	}
	red.clear();
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	memset(dis, 63, sizeof dis);
	red.reserve(maxsq + 10);
	cin >> n >> m;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		add_edge(fi, se);
	}
	dfs(1);
	//int fi, se;
	//while(cin >> fi >> se){
	//	cout << lca(fi, se) << endl;
	//	cout << h[fi] + h[se] - 2 * h[lca(fi, se)] << endl;
	//}
	red.PB(1);
	bfs();
	for(int i = 0; i < m; i++){
		int ty, fi;
		cin >> ty >> fi;
		if(ty == 1){
			red.PB(fi);
			if(sz(red) % maxsq == 0)
				bfs();
		}
		else{
			int ans = dis[fi];
			for(auto x : red)
				ans = min(ans, h[x] + h[fi] - 2 * h[lca(fi, x)]);
			cout << ans << '\n';
		}
		//cerr << "NEGAR" << endl;
	}
	return 0;
}