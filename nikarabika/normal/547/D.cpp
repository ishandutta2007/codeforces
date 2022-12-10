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

const int maxx = 2e5 + 85 - 69,
	  maxn = maxx * 2 + 85 - 69;
int col[maxn],
	x[maxn],
	y[maxn],
	n, m;
vector<int> adj[maxn];

void add_edge(int xx, int yy){
	x[m] = xx;
	y[m] = yy + maxx;
	adj[xx].PB(m);
	adj[maxx + yy].PB(m);
	m++;
}

void dfs(int u, int e = -1){
	while(sz(adj[u])){
		int ne = adj[u].back();
		adj[u].pop_back();
		if(col[ne]) continue;
		col[ne] = 1;
		dfs(x[ne]^y[ne]^u, ne);
	}
	if(~e){
		if(u == x[e])
			col[e] = 1;
		else
			col[e] = 2;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		add_edge(x[i], y[i]);
	}
	for(int i = 1; i < maxx; i++)
		if(sz(adj[i]) & 1)
			add_edge(i, maxx);
	for(int i = maxx + 1; i <= maxx * 2; i++)
		if(sz(adj[i]) & 1)
			add_edge(maxx, i - maxx);
	for(int i = 0; i < maxn; i++)
		dfs(i);
	for(int i = 0; i < n; i++)
		cout << (col[i]^1?'b':'r');
	cout << '\n';
	return 0;
}