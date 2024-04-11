#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())

const int maxn = 1e5 + 85 - 69;
vector<int> adj[maxn];
int leafcnt[maxn], minleaf[maxn], maxleaf[maxn], pos[maxn];
int n;

bool isleaf(int v){return v != 1 and sz(adj[v]) == 1;}

bool cmp(int v, int u){return minleaf[v] < minleaf[u];}

void dfs1(int v, int p = -1){
	if(isleaf(v)){
		leafcnt[v] = 1;
		minleaf[v] = maxleaf[v] = pos[v];
		return;
	}
	minleaf[v] = 1000000;
	maxleaf[v] = -1;
	for(auto u : adj[v]) if(u != p){
		dfs1(u, v);
		leafcnt[v] += leafcnt[u];
		smin(minleaf[v], minleaf[u]);
		smax(maxleaf[v], maxleaf[u]);
	}
	if(maxleaf[v] - minleaf[v] + 1 != leafcnt[v]){
		cout << -1 << endl;
		exit(0);
	}
	return;
}

void dfs2(int v, int p = -1){
	sort(adj[v].begin(), adj[v].end(), cmp);
	cout << v << ' ';
	for(auto u : adj[v])
		if(u != p){
			dfs2(u, v);
			cout << v << ' ';
		}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	int lcnt = 0;
	for(int i = 1; i <= n; i++)
		lcnt += isleaf(i);
	for(int i = 0; i < lcnt; i++){
		int x;
		cin >> x;
		pos[x] = i;
	}
	dfs1(1);
	dfs2(1);
	cout << endl;
	return 0;
}