#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int n, m, x;
vector<int> v[111];
vector<int> p[111];

#define ll long long
#define Z long long

/// Edmonds-Karp algorithm for computing max flow in a graph. Edges are given
/// with addEdge(source, destination, capacity), and maxFlow computes the
/// maximum flow, populating the flow fields of the edges.
struct EdmondsKarp {
	struct Edge {
		int dest;
		Z cap;  // Remaining capacity in the edge.
		Z flow; // Flow through the edge. >= 0 in normal edges, <= 0 in
		           // backwards edges.
		int back;  // Corresponding backwards edge.
	};
	
	EdmondsKarp(int n) : G(n) { }
	
	void addEdge(int src, int dest, Z cap) {
		if(src == dest) return;
		Edge e1 = {dest, cap, 0, (int)G[dest].size()};
		Edge e2 = {src, 0, 0, (int)G[src].size()};
		G[src].push_back(e1);
		G[dest].push_back(e2);
	}
	
	Z maxFlow(int s, int t) {
		Z ret = 0;
		
		typedef pair<int, int> P;
		vector<P> parent;
		while(true) {
			parent.clear();
			parent.resize(G.size(), P(-1, -1));
			
			queue<int> Q;
			Q.push(s);
			parent[s] = P(s, -1);
			
			while(!Q.empty()) {
				int v = Q.front();
				Q.pop();
				
				if(v == t) break;
				
				for(int i = 0; i < G[v].size(); ++i) {
					if(G[v][i].flow == G[v][i].cap) continue;
					int x = G[v][i].dest;
					if(parent[x].first != -1) continue;
					parent[x] = P(v, i);
					Q.push(x);
				}
			}
			
			if(parent[t].first == -1) break;
			
			Z a = -1;
			int v = t;
			while(v != s) {
				P p = parent[v];
				Z rem = G[p.first][p.second].cap - G[p.first][p.second].flow;
				if(a < 0 || rem < a) a = rem;
				v = p.first;
			}
			ret += a;
			v = t;
			while(v != s) {
				P p = parent[v];
				G[p.first][p.second].flow += a;
				G[v][G[p.first][p.second].back].flow -= a;
				v = p.first;
			}
		}
		
		return ret;
	}
	
	vector<vector<Edge> > G;
};

bool ok(double z) {
    EdmondsKarp e(n+2);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            e.addEdge(i,v[i][j],(ll)(p[i][j]/z));
        }
    }
    return e.maxFlow(1,n) >= x;
}


int main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(b);
        //v[b].push_back(a);
        p[a].push_back(c);
        //p[b].push_back(c);
    }
    double t = 0;
    double b = 1000000;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 4 && ok(t+b); j++) {
            t += b;
        }
        b /= 2;
    }
    printf("%.9lf\n", t*x);
}