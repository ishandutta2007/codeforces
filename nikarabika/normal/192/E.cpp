#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 10, maxl = 20;
vector<int> adj[maxn];
pair<int, int> E[maxn];
int n, q, h[maxn], dp[maxn], ans[maxn];
int par[maxn][maxl];

void dfs(int v, int p){
	par[v][0] = p;
	for(int i = 1; i < maxl and par[v][i - 1] != -1; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];
	for(int i = 0; i < adj[v].size(); i++)
		if(adj[v][i] != p){
			h[adj[v][i]] = h[v] + 1;
			dfs(adj[v][i], v);
		}
}

int dfs2(int v, int p){
	ans[v] = dp[v]; //!
	for(int i = 0; i < adj[v].size(); i++)
		if(adj[v][i] != p)
			ans[v] += dfs2(adj[v][i], v);
	return ans[v];
}

int lca(int fi, int se){
	if(h[fi] > h[se])
		swap(fi, se);
	int dh = h[se] - h[fi];
	for(int i = 0; i < maxl; i++)
		if(dh & (1 << i))
			se = par[se][i];
	if(fi == se)
		return fi;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[fi][i] != -1 and par[fi][i] != par[se][i])
			fi = par[fi][i], se = par[se][i];
	return par[fi][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(par, -1, sizeof par);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
		E[i] = MP(fi, se);
	}
	dfs(1, -1);
	cin >> q;
	for(int i = 0; i < q; i++){
		int fi, se;
		int p;
		cin >> fi >> se;
		p = lca(fi, se);
		dp[fi]++;
		dp[se]++;
		dp[p] -= 2;
	}
	dfs2(1, -1);
	for(int i = 1; i < n; i++){
		if(h[E[i].L] > h[E[i].R])
			cout << ans[E[i].L] << ' ';
		else
			cout << ans[E[i].R] << ' ';
	}
	cout << endl;
	return 0;
}