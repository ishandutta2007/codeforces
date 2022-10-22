#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;
vector<int> adj[2000], todo;

int dfs(int u) {
	int maxDep=1;
	for (int v:adj[u])
		maxDep=max(maxDep, dfs(v)+1);
	return maxDep;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, u; i<n; ++i) {
		cin >> u, u--;
		if (u>=0)
			adj[u].push_back(i);
		else
			todo.push_back(i);
	}

	int ans = 1;
	for (int i:todo)
		ans=max(ans, dfs(i));
	cout << ans;
	return 0;
}