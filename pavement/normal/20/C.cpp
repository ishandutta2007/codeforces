#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int n, e, u, v, w;
	scanf("%d%d", &n, &e);
	vector<pii> adj[n + 1];
	while (e--) {
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	int dist[n + 1], prev[n + 1];
	bool f[n + 1] = {};
	fill(dist, dist + n + 1, INT_MAX);
	fill(prev, prev + n + 1, -1);
	dist[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		int a = pq.top().second;
		if (a == n) break;
		pq.pop();
		for (auto u : adj[a]) {
			if (!f[u.first] && dist[a] + u.second < dist[u.first]) {
				dist[u.first] = dist[a] + u.second;
				prev[u.first] = a;
				pq.push({dist[u.first], u.first});
			}
		}
		f[a] = true;
	}
	if (dist[n] == INT_MAX) printf("-1");
	else {
		vector<int> path;
        for(int v = n; v != -1; v = prev[v]) path.push_back(v);
        for(int i = path.size() - 1; i > 0; i--) printf("%d ", path[i]);
        printf("%d\n", path[0]);
	}
}