#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

const int INF = 1000000;
const int N = 100;	

struct Dinic {
	struct Edge {
		int to, cap, flow, rev;
	};
	
	int source, sink;
	std :: vector <Edge> edge[2 * N + 2];
	int level[2 * N + 2];
	
	void addEdge (int u, int v, int f) {
		Edge edge1 = {v, f, 0, edge[v].size()};
		Edge edge2 = {u, f, f, edge[u].size()};
		edge[u].push_back(edge1);
		edge[v].push_back(edge2);
		return;
	}
	
	int maxFlow () {
		int flow, ret = 0;
		while (bfs()) 
			while (flow = dfs (source, INF))
				ret += flow;
		return ret;
	}
	
	private:
	
	bool bfs () {
		memset (level, -1, sizeof level);
		std :: queue <int> q;
		
		q.push (source);
		level[source] = 0;
		
		while (q.size()) {
			int u = q.front();
			q.pop();
			
			for (int i=0; i<edge[u].size(); i++) {
				Edge e = edge[u][i];
				
				if (level[e.to] >= 0 || e.cap == e.flow) continue;
				level[e.to] = level[u] + 1;
				
				q.push (e.to);
			}	
		}
		
		return ~level[sink];
	}
	
	int dfs (int u, int bottleNeck) {
		if (u == sink) return bottleNeck;
		if (!bottleNeck) return 0;
		
		int ret = 0;
		for (int i=0; i<edge[u].size() && ret < bottleNeck; i++) {
			Edge &e = edge[u][i];
			
			if (level[e.to] != level[u] + 1) continue;
			
			int flow = dfs (e.to, std :: min(bottleNeck - ret, e.cap - e.flow));
			
			ret += flow;
			e.flow += flow; 
			edge[e.to][e.rev].flow -= flow;
		}
		
		return ret;
	}
	
	
} dinic;

int main () {
	int n, m;
	scanf ("%d %d", &n, &m);
	
	dinic.source = 0;
	dinic.sink = 2 * n + 1;
	
	int u, v, w;
	
	int sumA, sumB = sumA = 0;
	
	for (int i=0; i<n; i++) {
		scanf ("%d", &w);
		dinic.addEdge (dinic.source, i + 1, w);
		sumA += w;
	}
	
	for (int i=0; i<n; i++) {
		scanf ("%d", &w);
		dinic.addEdge (n + i + 1, dinic.sink, w);
		sumB += w;
	}
	
	if (sumA ^ sumB) return 0 * printf ("NO\n");
	
	for (int i=0; i<n; i++) 
		dinic.addEdge (i + 1, n + i + 1, INF);
	
	for (int i=0; i<m; i++) {
		scanf ("%d %d", &u, &v);
		dinic.addEdge (u, v + n, INF);
		dinic.addEdge (v, u + n, INF);
	}
	
	if (dinic.maxFlow() ^ sumA) return 0 * printf ("NO\n");
	
	int adj[N][N] = {};
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<dinic.edge[i + 1].size(); j++) {	
			if (dinic.edge[i + 1][j].to)
				adj[i][dinic.edge[i + 1][j].to - n - 1] = dinic.edge[i + 1][j].flow;
		}
	}
	
	printf ("YES\n");
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) printf ("%d ", adj[i][j]);
		printf ("\n");
	}
	
	return 0;
}