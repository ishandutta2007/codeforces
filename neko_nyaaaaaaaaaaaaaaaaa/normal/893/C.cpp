#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, ans, sum, x, y;
vector<ll> cost(100001, 0);
vector<bool> visited(100001, false);
vector<vector<ll>> adjlist(100001, vector<ll>(1, 0));

void dfs(ll a) {
	if (ans > cost[a]) ans = cost[a];
	for (ll i = 1; i < adjlist[a].size(); i++) {
		if (visited[adjlist[a][i]]) continue;
		visited[adjlist[a][i]] = true;
		dfs(adjlist[a][i]);
	}
}

int main() {
	
	sum = 0;
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (ll i = 1; i <= m; i++) {
		cin >> x >> y;
		adjlist[x].push_back(y);
		adjlist[y].push_back(x);
	}
	for (ll i = 1; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		ans = 1000000000000;
		dfs(i);
		sum += ans;
	}
	cout << sum;
	
	return 0;
}