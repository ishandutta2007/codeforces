#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, x, y;
ll ans, sub;
vector<int> adj[300000];

int dfs(int u, int s, int p, int c) {
	int res=u==c?-1e9:1;
	for (int v: adj[u]) if (v!=p)
		res+=u==s?max(0, dfs(v, s, u, c)):dfs(v, s, u, c);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x >> y, --x, --y;
	for (int i=1; i<n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	sub=dfs(x, x, -1, y);
	sub*=dfs(y, y, -1, x);
	ans=1ll*n*(n-1)-sub;
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/