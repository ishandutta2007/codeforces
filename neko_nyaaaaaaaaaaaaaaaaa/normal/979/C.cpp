#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x, y, ans, sidex, sidey;
vector<vector<ll>> adj(300001);
vector<ll> vis(300001);

void dfs(int now, int bee, int xx) {
	if (now == x && xx == 1) {bee = 1;}
	if (now == y && xx == 0) {bee = 1;}
	if (xx == 1) {sidex += bee;}
	if (xx == 0) {sidey += bee;}
 	vis[now] = 1;
	
	for (int i = 0; i < adj[now].size(); i++) {
		if (vis[adj[now][i]]) continue;
		dfs(adj[now][i], bee, xx);
	}
} 

int main() {
	ios::sync_with_stdio(0);
	
	cin >> n >> x >> y;
	ans = n*(n-1);
	for (int i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(x, 0, 0);
	for (int i = 1; i <= n; i++) vis[i] = 0;
	dfs(y, 0, 1);
	
	cout << ans - sidex*sidey;
	
	return 0;
}