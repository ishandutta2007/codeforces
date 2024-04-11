#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 200005;

int n, m, s, vis[MAXN], par[MAXN], fr[MAXN];
vector<int> adj[MAXN];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	
	queue<pair<int, int>> q;
	vis[s] = 1;
	for (int u: adj[s]) {
		fr[u] = u; par[u] = s;
		q.push({u, u});
		vis[u] = 1;
	}

	while (q.size()) {
		auto [now, fi] = q.front(); q.pop();
		for (int u: adj[now]) {
			if (u == s) continue;
			if (vis[u]) {
				if (fr[u] == fi) continue;

				vector<int> path1, path2;
				int cur = u;
				while (cur != 0) {
					path1.push_back(cur);
					cur = par[cur];
				}
				path2.push_back(u);
				cur = now;
				while (cur != 0) {
					path2.push_back(cur);
					cur = par[cur];
				}
				reverse(path1.begin(), path1.end());
				reverse(path2.begin(), path2.end());

				cout << "Possible\n";
				cout << path1.size() << '\n';
				for (int i: path1) cout << i << ' ';
					cout << '\n';
				cout << path2.size() << '\n';
				for (int i: path2) cout << i << ' ';
					cout << '\n';
				exit(0);
			} else {
				q.push({u, fi}); vis[u] = 1;
				par[u] = now; fr[u] = fi;
			}
		}
	}
	cout << "Impossible\n";

	return 0;
}