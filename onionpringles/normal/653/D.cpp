#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <tuple>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int inf_flow = inf;
const int inf_dist = inf;
const int Mn = 50;

class Bad_Dinic {
	class Edge {
	public:
		int u, v, rev, f, c;
		Edge(int _u, int _v, int _rev, int _c) :u(_u), v(_v), rev(_rev), c(_c) { f = 0; }
	};
public:
	int s, t, vn;
	vector<Edge> adj[Mn];
	int dist[Mn];
	int vis[Mn];
	int it[Mn];
	void print() {
		for (int i = 0; i < vn; i++) {
			printf("%d: ", i);
			for (auto &x : adj[i]) printf("%d ", x.v);
			printf("\n");
		}
	}
	void init(int _s, int _t, int _vn) {
		for (int i = 0; i<_vn; i++) adj[i].clear();
		s = _s; t = _t; vn = _vn;
	}
	void addEdge(int u, int v, int c) {
		int usz = adj[u].size();
		int vsz = adj[v].size();

		adj[u].push_back(Edge(u, v, vsz, c));
		adj[v].push_back(Edge(v, u, usz, 0));
	}

	int bfs() {
		memset(vis, 0, vn*sizeof(*vis));
		for (int i = 0; i<vn; i++) dist[i] = inf_dist;
		queue<int> quu;
		quu.push(s);
		vis[s] = 1;
		dist[s] = 0;
		while (!quu.empty()) {
			int x = quu.front(); quu.pop();
			for (auto &e : adj[x]) {
				if (vis[e.v]) continue;
				if (e.f == e.c) continue;
				vis[e.v] = 1;
				dist[e.v] = dist[x] + 1;
				quu.push(e.v);
			}
		}
		return dist[t]<inf_dist;
	}
	int dfs(int u, int fl) {
		if (u == t) return fl;
		int cur_flow = 0;
		for (; it[u]<(int)adj[u].size(); it[u]++) {
			int i = it[u];
			int v = adj[u][i].v;
			if (dist[v] != dist[u] + 1) continue;
			if (adj[u][i].f == adj[u][i].c) continue;
			int av_flow = dfs(v, min(fl - cur_flow, adj[u][i].c - adj[u][i].f));
			adj[u][i].f += av_flow;
			adj[v][adj[u][i].rev].f -= av_flow;
			cur_flow += av_flow;
			if (fl == cur_flow) break;
		}
		return cur_flow;
	}
	int maxflow() {
		int cur_flow = 0;
		while (bfs()) {
			memset(it, 0, vn*sizeof(*it));
			int f = dfs(s, inf_flow);
			if (!f)break;
			cur_flow += f;
		}
		return cur_flow;
	}
	void print_antichain() {
		int n = (vn - 2) / 2;
		for (int i = 0; i < n; i++) {
			if (dist[i] < inf_dist && dist[n + i] == inf_dist) {
				printf("%d ", i + 1);
			}
		}
	}
} dn;

vector<pair<int, int> > adj[50];

const double eps = 1e-9;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, x;
	nii(n, m); ni(x);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		nii(a, b); ni(c);
		a--; b--;
		adj[a].push_back(mp(b, c));
	}
	double low = 0; double high = 1000000000;
	for (int i = 0; i < 150; i++) {
		double mid = (low + high) / 2;
		
		dn.init(0, n - 1, n);
		for (int j = 0; j < n; j++) {
			for (auto &y : adj[j]) {
				if (mid*x < y.second + eps) {
					dn.addEdge(j, y.first, x);
				}
				else {
					int m = (int)(y.second / mid);
					dn.addEdge(j, y.first, m);
				}
			}
		}

		if (dn.maxflow() >= x) {
			low = mid;
		}
		else high = mid;
	}
	printf("%.15f", x * (low + high) / 2);
	return 0;
}