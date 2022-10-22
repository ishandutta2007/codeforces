#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m, val[1000], cost[1000];
vector<pair<int, int>> part;
vector<int> adj[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(cost, 0, sizeof(cost));
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> val[i];
		part.push_back({val[i],i});
	}
	sort(part.rbegin(), part.rend());
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i) {
		for (int j:adj[i])
			cost[i]+=val[j];
	}

	int ans = 0;
	for (int i=0; i<n; ++i) {
		int x=part[i].second;
		ans+=cost[x];
		for (int j:adj[x])
			cost[j]-=val[x];
	}
	cout << ans;
	return 0;
}