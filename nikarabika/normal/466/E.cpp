#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#undef endl
#define endl '\n'

const int maxn = 1e5 + 85 - 69, maxl = 20;
vector<int> adj[maxn];
int par[maxl][maxn], dsu_par[maxn];
int h[maxn], ans[maxn];
vector<piii> quer;
vector<pii> ask[maxn];
int n, m, lettercnt;

int root(int v){ return (dsu_par[v] < 0) ? v : dsu_par[v] = root(dsu_par[v]);}

void merge(int v, int u){
	if((v = root(v)) == (u = root(u)))
		return;
	if(dsu_par[v] > dsu_par[u])
		swap(v, u);
	dsu_par[v] += dsu_par[u];
	dsu_par[u] = v;
	return;
}

int ithpar(int v, int k){
	for(int i = 0; i < maxl and k; i++)
		if((k >> i) & 1)
			v = par[i][v], k ^= (1 << i);
	return v;
}

void dfs(int v){
	for(int i = 1; i < maxl and par[i - 1][v] != -1; i++)
		par[i][v] = par[i - 1][par[i - 1][v]];
	for(auto u : adj[v]){
		par[0][u] = v;
		h[u] = h[v] + 1;
		dfs(u);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	memset(dsu_par, -1, sizeof dsu_par);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		par[0][i] = 0;
	for(int i = 0; i < m; i++){
		int ty, fi, se;
		cin >> ty;
		if(ty == 1){
			cin >> fi >> se;
			par[0][fi] = se;
			quer.PB({1, {fi, se}});
		}
		else if(ty == 2){
			cin >> fi;
			quer.PB({2, {fi, fi}});
		}
		else{
			cin >> fi >> se;
			quer.PB({3, {fi, se}});
			ask[se].PB({fi, i});
		}
	}
	for(int i = 1; i <= n; i++)
		adj[par[0][i]].PB(i);
	dfs(0);
	for(int i = 0; i < m; i++){
		if(quer[i].L == 1)
			merge(quer[i].R.L, quer[i].R.R);
		else if(quer[i].L == 2){
			lettercnt++;
			int v = quer[i].R.R;
			for(auto u : ask[lettercnt])
				if(root(v) == root(u.L) and h[u.L] <= h[v] and ithpar(v, h[v] - h[u.L]) == u.L)
					ans[u.R] = true;
		}
		else
			cout << (ans[i] ? "YES" : "NO") << endl;
	}
	return 0;
}