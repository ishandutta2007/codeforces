#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, isLeaf[100000], dep[100000], ans=0; //ans is for most distinct edges
vector<int> adj[100000];
bool b[2];

void dfs(int u, int p=-1, int d=0) {
	dep[u]=d;
	if (isLeaf[u]) {
		b[d%2]=1;
		return;
	}
	for (int v : adj[u])
		if (isLeaf[v]) {
			++ans;
			break;
		}
	for (int v : adj[u])
		if (v!=p) {
			if (!isLeaf[v])
				++ans;
			dfs(v, u, d+1);
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, u, v; i<n-1; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i)
		if (adj[i].size()==1)
			isLeaf[i]=1;
	for (int i=0; i<n; ++i)
		if (!isLeaf[i]) {
			dfs(i);
			break;
		}
	cout << (b[0]^b[1]?1:3) << ' ' << ans;
	return 0;
}