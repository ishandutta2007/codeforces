#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1000 * 100 + 85 - 69;
vector<pie> adj[maxn], limita;
int col[maxn];
bool mark[maxn];
int n, m;

void add_edge(int v, int u){
	adj[v].PB(MP(u, +1));
	adj[u].PB(MP(v, -1));
}

void dfs(int v){
	mark[v] = true;
	for(auto u : adj[v]){
		if(!mark[u.L]){
			col[u.L] = col[v] + u.R;
			dfs(u.L);
		}
		else
			limita.PB(MP(col[v] + u.R, col[u.L]));
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		add_edge(fi, se);
	}
	for(int i = 1; i <= n; i++)
		if(!mark[i])
			dfs(i);
	int ans = 0;
	for(auto lim : limita){
		int dif = max(lim.L, lim.R) - min(lim.L, lim.R);
		ans = __gcd(ans, dif);
	}
	if(ans == 0)
		cout << n << endl;
	else
		cout << ans << endl;
	return 0;
}