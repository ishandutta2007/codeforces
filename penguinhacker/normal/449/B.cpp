#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define INF 1e18

int n, m, k, ans=0;
ll d[100000], deg[100000];
bool vis[100000];
vector<pair<int, int>> adj[100000];
pair<int, int> train[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0, u, v, w; i<m; ++i) {
		cin >> u >> v >> w, u--, v--;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	for (int i=0, u, w; i<k; ++i) {
		cin >> u >> w, --u;
		train[i]={u, w};
	}

	for (int i=1; i<n; ++i)
		d[i]=INF;

	priority_queue<pair<ll, int>> q;
	q.push({0, 0});
	while (!q.empty()) {
		int u=q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u]=1;
		for (auto x : adj[u]) {
			int v=x.first, w=x.second;
			if (d[u]+w<d[v]) {
				d[v]=d[u]+w;
				q.push({-d[v], v});
			}
		}
		if (u==0) {
			for (int i=0; i<k; ++i) {
				if (train[i].second<d[train[i].first]) {
					d[train[i].first]=train[i].second;
					q.push({-train[i].second, train[i].first});
				}
			}
		}
	}
	for (int i=0; i<n; ++i) {
		for (auto x : adj[i]) {
			if (d[i]+x.second==d[x.first])
				deg[x.first]++;
		}
	}
	for (int i=0; i<k; ++i) {
		int v=train[i].first, w=train[i].second;
		if (w>d[v])
			++ans;
		else {
			if (deg[v]>0)
				++ans;
			else
				++deg[v];
		}
	}
	cout << ans;
	return 0;
}