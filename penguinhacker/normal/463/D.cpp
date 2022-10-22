#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, pos[1000][5];
vector<int> adj[1000];

void make_edge(int i, int j) { // i --> j
	bool b=1;
	for (int p=0; p<k; ++p)
		if (pos[i][p]>=pos[j][p]) {
			b=0;
			break;
		}
	if (b) adj[j].push_back(i);
}

int ans=0, d[1000];
bool vis[1000];
void dfs(int u) {
	d[u]=1, vis[u]=1;
	for (int v: adj[u]) {
		if (!vis[v]) dfs(v);
		d[u]=max(d[u], d[v]+1);
	}
	ans=max(ans, d[u]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int j=0; j<k; ++j) {
		for (int i=0; i<n; ++i) {
			int a; cin >> a, --a;
			pos[a][j]=i;
		}
	}
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			make_edge(i, j);
	for (int i=0; i<n; ++i) if (!vis[i])
		dfs(i);
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/