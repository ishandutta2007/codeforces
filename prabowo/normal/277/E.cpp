#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <cmath>

const int N = 800 + 2;
const double INF = 1e9;

struct MinCostFlow {
	struct Edge {
		int to, cap, flow, rev;
		double cost;
	};
	
	int source, sink;
	std :: vector < Edge > edge[N];
	double pot[N];
	
	void addEdge (int u, int v, double c, int f) {
		Edge edge1 = {v, f, 0, edge[v].size(), c};
		Edge edge2 = {u, 0, 0, edge[u].size(), -c};
		edge[u].push_back (edge1);
		edge[v].push_back (edge2);
	}
	
	std :: pair <int, double> dijkstra () {
		std :: priority_queue < std :: pair <double, int> > pq;
		pq.push ( std :: make_pair (0, source) );
		
		bool vis[N] = {};
		double dist[N];		
		for (int i=0; i<N; i++) dist[i] = INF;
		std :: pair <int, int> prev[N];
		
		dist[source] = 0;
		
		while (pq.size()) {
			std :: pair <double, int> now = pq.top();
			int u = now.second;
			pq.pop();
			
			// printf ("Edge[%d]\n", u);
			
			if (vis[u]) continue;
			vis[u] = 1;
			
			for (int i=0; i<edge[u].size(); i++) {
				Edge e = edge[u][i];
				int v = e.to;
				// printf ("%d %d %d\n", v, e.cap, e.flow);
				
				if (e.cap - e.flow == 0) continue;
				
				double d = dist[u] + e.cost + pot[u] - pot[v];
				if (d < dist[v]) {
					dist[v] = d;
					pq.push (std :: make_pair (-d, v));
					prev[v] = std :: make_pair (u, i);
				}
			}
		}
		
		for (int i=0; i<N; i++) pot[i] += dist[i];
		
		if (dist[sink] == INF) return std :: make_pair (0, 0);
		// printf ("%.5lf\n", dist[sink]);
		
		int f = INF;
		double sum = 0;
		int now = sink;
		
		while (now ^ source) {
			int u = prev[now].first;
			int i = prev[now].second;
			f = std :: min(f, edge[u][i].cap - edge[u][i].flow);
			sum += edge[u][i].cost;
			now = u;
		}
		
		now = sink;
		while (now ^ source) {
			int u = prev[now].first;
			int i = prev[now].second;
			edge[u][i].flow += f;
			edge[now][edge[u][i].rev].flow -= f;
			now = u;
		}
		
		return std :: make_pair (f, sum * f);
	};
	
	std :: pair <int, double> minCostMaxFlow () {
		std :: pair <int, double> tmp = dijkstra();
		std :: pair <int, double> ret = std :: make_pair (0, 0);
		while (tmp.first) {
			ret.first += tmp.first;
			ret.second += tmp.second;
			tmp = dijkstra();
		}
		
		return ret;
	}
	
} mcf;

int n;
std :: pair <int, int> point[444];

int main () {
	scanf ("%d", &n);
	
	for (int i=0; i<n; i++) {
		scanf ("%d %d", &point[i].first, &point[i].second);
	}
	
	mcf.source = 0;
	mcf.sink = 2 * n + 1;
	
	for (int i=0; i<n; i++) {
		bool root = 1;
		for (int j=0; j<n; j++) {
			if (point[i].second < point[j].second) {
				mcf.addEdge (i + 1, j + n + 1, hypot (point[i].first - point[j].first, point[i].second - point[j].second), 1);
				root = 0;
			}
		}
		if (!root) mcf.addEdge (0, i + 1, 0, 1);
		mcf.addEdge (i + n + 1, 2 * n + 1, 0, 2);
	}
	
	std :: pair <int, double> ans = mcf.minCostMaxFlow();	
	if (ans.first ^ n - 1) return 0 * printf ("-1\n");
	
	printf ("%.15lf\n", ans.second);
	
	return 0;
}