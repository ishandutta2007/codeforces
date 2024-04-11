#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int MOD=1e9+7;

int n, m, k;
bool vis[2000];
vector<int> adj[2000];

void dfs(int u) {
	vis[u]=1;
	for (int v: adj[u]) if (!vis[v]) dfs(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i+k-1<n; ++i) {
		for (int j=0; j<k/2; ++j) {
			adj[i+j].push_back(i+k-j-1);
			adj[i+k-j-1].push_back(i+j);
		}
	}
	ll ans=1;
	for (int i=0; i<n; ++i) if (!vis[i]) {
		dfs(i);
		ans=ans*m%MOD;
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