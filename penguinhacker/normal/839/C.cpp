#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>

int n;
vector<int> adj[100000];

double dfs(int u=0, int p=-1) {
	if ((adj[u].size()==1&&u)||adj[u].size()==0)
		return 0;
	double curr = 0;
	for (int v:adj[u])
		if (v!=p)
			curr += 1+dfs(v, u);
	int child = adj[u].size();
	if (u)
		child--;
	return curr/child;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(numeric_limits<double>::max_digits10);

	cin >> n;
	for (int i=0, u, v; i<n-1; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << dfs();
	return 0;
}