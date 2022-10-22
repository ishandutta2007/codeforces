#include <bits/stdc++.h>
using namespace std;

#define INF 1e9+25

int n, m, ans_min=0, ans_max=0;
int dist[200000];
vector<int> adj[200000], nextNode[200000];

void bfs(int start) {
	memset(dist, 0x3f, sizeof(dist));
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int u : adj[x]) {
			if (dist[x]+1 < dist[u]) {
				dist[u] = dist[x]+1;
				nextNode[u].push_back(x);
				q.push(u);
			}
			else if (dist[x]+1 == dist[u]) {
				nextNode[u].push_back(x);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[v].push_back(u);
	}

	int l; cin >> l; //length
	vector<int> path;
	for (int i=0, u; i<l; ++i) {
		cin >> u, u--;
		path.push_back(u);
	}
	bfs(*path.rbegin());
	
	for (int i=0; i<l-1; ++i) {
		if (find(nextNode[path[i]].begin(), nextNode[path[i]].end(), path[i+1]) == nextNode[path[i]].end()) {
			ans_min++;
			ans_max++;
		}
		else if (nextNode[path[i]].size()>1)
			ans_max++;
	}
	cout << ans_min << ' ' << ans_max;
	return 0;
}