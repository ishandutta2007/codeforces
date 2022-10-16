#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

int n, m, a, b, fa, fb, cc;
vector<int> adj[MAXN];
vector<int> vis(MAXN);

void dfs(int now) {
	if (now == a) {
		fa = 1; return;
	}
	if (now == b) {
		fb = 1; return;
	}

	cc++; vis[now] = 1;
	for (int u: adj[now]) {
		if (!vis[u]) dfs(u);
	}
}

void solve() {
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		vis[i] = 0;
	}

	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ca = 0, cb = 0;
	for (int i = 1; i <= n; i++) {
		if (i != a && i != b && vis[i] == 0) {
			fa = 0, fb = 0, cc = 0;
			dfs(i);

			if (fa && !fb) {
				ca += cc;
			} else if (!fa && fb) {
				cb += cc;
			}
		}
	}
	cout << 1LL*ca*cb << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}
 
	return 0;
}