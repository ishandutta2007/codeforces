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

const int maxn = 100 * 1000;
int par[maxn],
	n;
vector<int> adj[maxn];
vector<pii> E;

int f(int v, int root){
	return v + (root > v);
}

void dfs(int v, int p, int root){
	if(p != root and ~p) E.PB(MP(f(v, root), f(p, root)));
	par[v] = p;
	for(auto u : adj[v])
		if(u != p)
			dfs(u, v, root);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	int root = -1;
	for(int i = 0; i < n; i++)
		if(sz(adj[i]) == 1)
			root = i;
	dfs(root, -1, root);
	cout << n - 1 << '\n';
	for(int i = 0; i < n; i++)
		if(i != root)
			cout << 2 << ' ' << i + 1 << ' ' << par[i] + 1 << '\n';
	for(auto e : E)
		cout << e.L << ' ' << e.R << '\n';
	return 0;
}