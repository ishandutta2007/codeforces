#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
vector<int> adj[200000];

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int cnt = 1;
	vector<int> parity(n);
	vector<bool> visited(n, 0);
	visited[0] = 1;
	parity[0] = 1;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v:adj[u]) {
			if (!visited[v]) {
				visited[v] = 1;
				parity[v] = parity[u]^1;
				q.push(v);
				if (parity[v])
					cnt++;
			}
		}
	}
	if (cnt<=n/2) {
		cout << cnt << '\n';
		for (int i=0; i<n; ++i)
			if (parity[i])
				cout << i+1 << ' ';
	}
	else {
		cout << n-cnt << '\n';
		for (int i=0; i<n; ++i)
			if (parity[i]==0)
				cout << i+1 << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}