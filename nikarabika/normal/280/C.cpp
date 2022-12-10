#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

#define PB push_back

const int maxn = 1e5 + 85 - 69;
vector<int> adj[maxn];
int n;
LD ans;

void dfs(int u, int p = -1, int h = 1){
	ans += 1. / h;
	for(auto v : adj[u])
		if(v^p)
			dfs(v, u, h + 1);
	return;
}

int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(0);
	cout.precision(15);
	cout << fixed << ans << '\n';
	return 0;
}