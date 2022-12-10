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

const int maxn = 3e5 + 85 - 69;
int par[maxn],
	ans[maxn],
	sz[maxn],
	n, q;
vector<int> adj[maxn];

void dfs(int v){
	sz[v] = 1;
	if(!sz(adj[v])){
		ans[v] = v;
		return;
	}
	pii mx = MP(-1, -1);
	for(auto u : adj[v]){
		dfs(u);
		sz[v] += sz[u];
		smax(mx, MP(sz[u], u));
	}
	ans[v] = ans[mx.R];
	while(sz[ans[v]] <= sz[v] / 2)
		ans[v] = par[ans[v]];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i < n; i++){
		cin >> par[i], par[i]--;
		adj[par[i]].PB(i);
	}
	dfs(0);
	while(q--){
		int fi;
		cin >> fi, fi--;
		cout << ans[fi] + 1 << '\n';
	}
	return 0;
}