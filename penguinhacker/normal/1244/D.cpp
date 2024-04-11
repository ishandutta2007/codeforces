#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, cost[100000][3];
vector<int> adj[100000];

ll dfs(int u, int p, int l1, int l2) {
	int color;
	if (l1!=0&&l2!=0)
		color = 0;
	else if (l1!=1&&l2!=1)
		color = 1;
	else
		color = 2;
	ll sum = cost[u][color];
	for (int v:adj[u])
		if (v!=p)
			return sum+dfs(v, u, color, l1);
	return sum;
}

int coloring[100000];
void getAns(int u, int p, int l1, int l2) {
	int color;
	if (l1!=0&&l2!=0)
		color = 0;
	else if (l1!=1&&l2!=1)
		color = 1;
	else
		color = 2;
	coloring[u] = color+1;
	for (int v:adj[u])
		if (v!=p)
			getAns(v, u, color, l1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<3; ++i)
		for (int j=0; j<n; ++j)
			cin >> cost[j][i];
	for (int i=0, u, v; i<n-1; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i) {
		if (adj[i].size()>2) {
			cout << -1;
			return 0;
		}
	}
	int start;
	for (int i=0; i<n; ++i) {
		if (adj[i].size()==1) {
			start = i;
			break;
		}
	}
	
	pi p;
	ll ans = INT64_MAX;
	for (int i=0; i<3; ++i) {
		for (int j=0; j<3; ++j) {
			if (i!=j) {
				ll curr = dfs(start, -1, i, j);
				if (curr<ans) {
					ans = curr;
					p = {i, j};
				}
			}
		}
	}
	cout << ans << '\n';
	getAns(start, -1, p.first, p.second);
	for (int i=0; i<n; ++i)
		cout << coloring[i] << ' ';
	return 0;
}