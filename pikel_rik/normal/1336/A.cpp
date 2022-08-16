#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 5;

int n, k;
vector<int> adj[N];

int d[N], sz[N];
//d = depth of vertex, sz = subtree size of subtree rooted at vertex

void dfs(int x, int p) {
	sz[x] = 1;
	for (int v : adj[x]) {
		//there are going to be "visited" vertices
		//there are going to be unvisited vertices
		if (v != p) {
			d[v] = 1 + d[x];
			dfs(v, x);
			sz[x] += sz[v];
		}
	}
}

bool comp(int u, int v) {
	return d[u] - sz[u] + 1 > d[v] - sz[v] + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	//1 = root, capital kingdom

	vector<int> vertices(n);
	for (int i = 0; i < n; i++) {
		vertices[i] = i + 1;
	}

	sort(vertices.begin(), vertices.end(), comp);

	long long sum = 0;
	for (int i = 0; i < k; i++) {
		int v = vertices[i];
		sum += d[v] - sz[v] + 1;
	}
	cout << sum << '\n';
	return 0;
}