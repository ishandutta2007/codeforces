#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, toLeaf[100];
vector<int> adj[100];

void dfs(int u=0, int p=-1) { //find distance to farthest leaf
	int maxDist = 0;
	for (int v:adj[u]) {
		if (v!=p) {
			dfs(v,u);
			maxDist = max(maxDist, toLeaf[v]+1);
		}
	}
	toLeaf[u] = maxDist;
}

int solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=0, u, v; i<n-1; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	int diameter = 1;
	for (int i=0; i<n; ++i) {
		multiset<int, greater<>> childDist; //bc im to lazy to code largest 2 children
		childDist.insert(0);
		childDist.insert(0);
		for (int u:adj[i])
			if (toLeaf[u]<toLeaf[i])
				childDist.insert(toLeaf[u]+1);
		auto it = childDist.begin();
		int curr = *it; it++;
		curr += *it;
		diameter = max(diameter, curr);
	}
	return diameter;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t, length = 0;
	cin >> t;
	while(t--)
		length += solve();
	cout << length;
	return 0;
}