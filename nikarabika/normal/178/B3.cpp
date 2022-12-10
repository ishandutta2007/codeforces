//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5, maxl = 20;
int n, m, k;
int h[maxn], par[maxn][maxl], sum[maxn], low[maxn];
bool mark[maxn];
vector<int> adj[maxn], vec;

void addedge(int fi, int se){
	adj[fi].PB(se);
	adj[se].PB(fi);
	return;
}

int dfs(int v){
	vec.PB(v);
	mark[v] = true;
	low[v] = h[v];
	for(int j = 1; j < maxl and par[v][j - 1] != -1; j++)
		par[v][j] = par[par[v][j - 1]][j - 1];
	for(auto u : adj[v])
		if(u != par[v][0]){
			if(!mark[u]){
				par[u][0] = v;
				h[u] = h[v] + 1;
				smin(low[v], dfs(u));
			}
			else
				smin(low[v], h[u]);
		}
	return low[v];
}

int kthpar(int v, int kk){
	int j = 0;
	while(kk){
		if(kk & 1)
			v = par[v][j];
		j++;
		kk >>= 1;
	}
	return v;
}

int lca(int v, int u){
	if(h[v] < h[u])
		swap(v, u);
	v = kthpar(v, h[v] - h[u]);
	if(v == u)
		return v;
	for(int j = maxl - 1; j >= 0; j--)
		if(par[v][j] != par[u][j])
			v = par[v][j], u = par[u][j];
	return par[v][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m;
	while(m--){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		addedge(fi, se);
	}
	dfs(0);
	for(auto v : vec)
		if(v)
			sum[v] = sum[par[v][0]] + (low[v] == h[v]);
	cin >> k;
	while(k--){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		int p = lca(fi, se);
		cout << sum[fi] + sum[se] - 2 * sum[p] << '\n';
	}
	return 0;
}