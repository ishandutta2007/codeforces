#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
bool vis[10000];
vector<int> adj[10000];

void dfs(int u) {
	vis[u]=1;
	for (int v: adj[u])
		if (!vis[v])
			dfs(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		int x; cin >> x, --x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	int ans=0;
	for (int i=0; i<n; ++i) {
		if (vis[i]) continue;
		++ans;
		dfs(i);
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/