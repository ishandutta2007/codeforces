#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m;
vector<ar<int, 2>> adj[mxN];
ll d[mxN][4];
bool vis[mxN][4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	memset(d, 0x3f, sizeof(d));
	d[0][0]=0;
	priority_queue<ar<ll, 3>, vector<ar<ll, 3>>, greater<ar<ll, 3>>> pq;
	pq.push({0, 0, 0});
	auto Ck=[&](int u, int t, ll x) {
		if (x<d[u][t]) {
			assert(!vis[u][t]);
			pq.push({d[u][t]=x, u, t});
		}
	};
	while(!pq.empty()) {
		int u=pq.top()[1], t=pq.top()[2];
		pq.pop();
		if (vis[u][t])
			continue;
		vis[u][t]=1;
		if (t==0) {
			for (auto [v, w] : adj[u]) {
				Ck(v, 0, d[u][t]+w);
				Ck(v, 1, d[u][t]+2*w);
				Ck(v, 2, d[u][t]);
				Ck(v, 3, d[u][t]+w);
			}
		} else if (t==1) {
			for (auto [v, w] : adj[u]) {
				Ck(v, 1, d[u][t]+w);
				Ck(v, 3, d[u][t]);
			}
		} else if (t==2) {
			for (auto [v, w] : adj[u]) {
				Ck(v, 2, d[u][t]+w);
				Ck(v, 3, d[u][t]+2*w);
			}
		} else {
			for (auto [v, w] : adj[u])
				Ck(v, 3, d[u][t]+w);
		}
	}
	for (int i=1; i<n; ++i) {
		ll ans=d[i][3];
		assert(ans<1e18);
		cout << ans << " ";
	}
	return 0;
}