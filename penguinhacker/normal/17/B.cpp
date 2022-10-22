#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, q[1000];
vector<pair<int, int>> adj[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int inds[1000];
	for (int i=0; i<n; ++i) {
		cin >> q[i];
	}
	iota(inds, inds+n, 0);
	sort(inds, inds+n, [](int a, int b) {return q[a]>q[b]; } );

	cin >> m;
	for (int i=0, a, b, c; i<m; ++i) {
		cin >> a >> b >> c, a--, b--;
		adj[a].push_back({b, c});
	}

	int ans = 0;
	vector<int> cost(n, 1000000000);
	cost[inds[0]] = 0;
	for (int i=0; i<n; ++i) {
		int u = inds[i];
		if (cost[u]==1000000000) {
			cout << -1;
			return 0;
		}
		ans += cost[u];
		for (auto x:adj[u]) {
			cost[x.first] = min(cost[x.first], x.second);
		}
	}

    cout << ans;
	return 0;
}