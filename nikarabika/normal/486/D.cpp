#include <bits/stdc++.h>

using namespace std;

#define PB push_back

typedef long long int ll;

const int maxn = 2e3 + 10;
vector<int> adj[maxn];
int a[maxn], d, n, working;
const ll D = 1e9 + 7;
ll wa[maxn], ans;
bool mark[maxn];

void dfs(int v, int p){
	wa[v] = 1;
	for(int i = 0; i < adj[v].size(); i++) if(adj[v][i] != p){
		int u = adj[v][i];
		if(a[u] >= working and a[u] <= working + d and (!mark[u] or a[u] != working)){
			dfs(u, v);
			wa[v] *= wa[u] + 1;
			wa[v] %= D;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> d >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 1; i <= n; ++i){
		working = a[i];
		mark[i] = true;
		dfs(i, 0);
		ans += wa[i];
		ans %= D;
	}
	cout << ans << endl;
	return 0;
}