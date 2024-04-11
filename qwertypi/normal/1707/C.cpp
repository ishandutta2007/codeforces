#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int u, v, w;
};

const int N = 1e5 + 13;
vector<Edge> E, MSTE;
vector<int> G[N], MST[N];

int p[N], dp[N], dp2[N], dep[N], lp[20][N];
int g[N];
struct DSU{
	vector<int> par, sz;
	void copy(const DSU& d){
		this->par = d.par;
		this->sz = d.sz;
	}
	void init(int n){
		par.resize(n), sz.resize(n);
		for(int i = 0; i < n; i++){
			par[i] = i;
			sz[i] = 1;
		}
	}
	int root(int x){
		if(par[x] == x) return x;
		return par[x] = root(par[x]);
	}
	bool join(int x, int y, int w){
		int u = x, v = y;
		x = root(x), y = root(y);
		if(x == y) return false;
		if(sz[x] < sz[y]) swap(x, y);
		par[y] = x;
		sz[x] += sz[y];
		MSTE.push_back({u, v, w});
		return true;
	}
} dsu;

void dfs_1(int v, int par = -1){
	for(auto i : MST[v]){
		if(i != par){
			p[i] = v;
			dep[i] = dep[v] + 1;
			dfs_1(i, v);
		}
	}
}

void dfs_2(int v, int par = -1){
	for(auto i : MST[v]){
		if(i != par){
			dp[i] += dp[v];
			dfs_2(i, v);
		}
	}
}

int lca(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	for(int j = 19; j >= 0; j--){
		if(dep[u] >= dep[v] + (1 << j)){
			u = lp[j][u];
		}
	}
	if(u == v) return u; return -1;
}

int lcap(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	for(int j = 19; j >= 0; j--){
		if(dep[u] >= dep[v] + (1 << j) + 1){
			u = lp[j][u];
		}
	}
	return u;
}

int main(){
	int n, m;
	cin >> n >> m;
	dsu.init(n + 1);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		E.push_back({u, v, i + 1});
		dsu.join(u, v, i + 1);
	}
	for(auto i : MSTE){
		MST[i.u].push_back(i.v);
		MST[i.v].push_back(i.u);
	}
	dfs_1(1);
	for(int i = 1; i <= n; i++) lp[0][i] = p[i];
	for(int j = 1; j < 20; j++){
		for(int i = 1; i <= n; i++){
			lp[j][i] = lp[j - 1][lp[j - 1][i]];
		}
	}
	for(auto i : E){
		if(dep[i.u] < dep[i.v]) swap(i.u, i.v);
		if(p[i.u] != i.v && p[i.v] != i.u){
			if(lca(i.u, i.v) == i.v){
				dp[lcap(i.u, i.v)]++;
				dp[i.u]--;
			}else{
				dp[1]++;
				dp[i.u]--;
				dp[i.v]--;
			}
		}
	}
	dfs_2(1);
	for(int i = 1; i <= n; i++){
		cout << (char) ('0' + (dp[i] == 0));
	}
	cout << '\n';
}