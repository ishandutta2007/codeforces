#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> color(2, 0);
vector<vector<ll>> adjlist(100001, vector<ll>(1, 0));
vector<bool> visited(100001, false);

void dfs(ll node, ll d) {
	visited[node] = true;
	color[d]++;
	for (ll i = 1; i < adjlist[node].size(); i++) {
		if (visited[adjlist[node][i]]) continue;
		dfs(adjlist[node][i], d ^ 1);
	}
}

int main() {
	
	ll n, x, y;
	cin >> n;
	for (ll i = 1; i < n; i++) {
		cin >> x >> y;
		adjlist[x].push_back(y);
		adjlist[y].push_back(x);
	}
	dfs(1LL, 1LL);
	cout << color[0]*color[1] - (n - 1LL);
	
	
	return 0;
}