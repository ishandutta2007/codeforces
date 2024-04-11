//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
bool mark[maxn],
	 istree;
int n, m;
vector<int> adj[maxn];

void dfs(int v, int p = -1){
	if(mark[v]){
		istree = false;
		return;
	}
	mark[v] = true;
	for(auto u : adj[v])
		if(u != p)
			dfs(u, v);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) if(!mark[i]){
		istree = true;
		dfs(i);
		if(istree)
			ans++;
	}
	cout << ans << endl;
	return 0;
}