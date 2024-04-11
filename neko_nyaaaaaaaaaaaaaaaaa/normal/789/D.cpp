#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, x, y, loop, e;
vector<vector<int>> adj(1000001);
vector<int> vis(1000001, 1);
vector<ll> deg(1000001);

void dfs(int u) {
	vis[u] = 1;
	for (int i: adj[u]) {
		if (vis[i]) continue;
		dfs(i);
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (x != y) {
			adj[x].push_back(y);
			adj[y].push_back(x);
			deg[x]++;
			deg[y]++;
			e++;
			vis[x] = vis[y] = 0;
		}
		else {loop++; vis[x] = 0;}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {dfs(i); break;}	
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {cout << "0"; return 0;}
	}
	
	// calculating
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += deg[i]*(deg[i] - 1)/2;
	}
	ans += e*loop;
	ans += loop*(loop - 1)/2;
	
	cout << ans;
}