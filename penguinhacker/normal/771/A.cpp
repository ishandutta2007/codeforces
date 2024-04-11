#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
bool vis[150000];
vector<int> adj[150000];

void dfs(int u, int &cnt, int &pairs) {
	vis[u]=1, ++cnt;
	for (int v: adj[u]) {
		++pairs;
		if (!vis[v])
			dfs(v, cnt, pairs);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i=0; i<n; ++i) {
		if (vis[i]) continue;
		int cnt=0, pairs=0;
		dfs(i, cnt, pairs);
		if (1ll*cnt*(cnt-1)!=pairs) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/