#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <limits.h>
#include <iostream>
#include <iomanip>
#include <complex>
#include <string.h>
#include <string>

#define mp make_pair
#define mtp make_tuple
#define ni(x) scanf("%d", &(x))
#define nii(x, y) scanf("%d%d", &(x), &(y))
#define mul(x,y) (ll)(x)*(y)%mod

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int Mn = 60020;
const int inf_dist = 1000000000;
const int inf_flow = 1000000000;

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
		for (; it[u]<adj[u].size(); it[u]++) {
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
}dn;

void bad_end() {
	puts("unfair");
	exit(0);
}

int numrem(int s, int rem) {
	return s / 5 + (s % 5 >= rem);
}

int numrem(int s, int e, int rem) {
	return numrem(e, rem) - numrem(s - 1, rem);
}
vector<pii> qs;
vector<pair<pii, int> > intervals;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, b, q;
	nii(n, b); ni(q);
	for (int i = 0; i < q; i++) {
		int uto, qu;
		nii(uto, qu);
		qs.push_back(mp(uto, qu));
	}
	sort(qs.begin(), qs.end());
	int cur = 0; int curamt = 0;
	for (auto &x : qs) {
		if (x.first == cur) {
			if (curamt != x.second) bad_end();
			else continue;
		}
		intervals.push_back(mp(mp(cur + 1, x.first), x.second - curamt));
		cur = x.first;
		curamt = x.second;
	}
	if (cur != b) {
		intervals.push_back(mp(mp(cur + 1, b), n - curamt));
	}
	for (auto &x : intervals) {
		if (x.second < 0) bad_end();
	}
	int sz = intervals.size();

	dn.init(5 + sz, 6 + sz, 7 + sz);

	for (int i = 0; i < sz; i++) {
		dn.addEdge(5 + sz, i, intervals[i].second);
		for (int j = 0; j < 5; j++) {
			int nr = numrem(intervals[i].first.first, intervals[i].first.second, j);
			dn.addEdge(i, sz + j, nr);
		}
	}
	for (int j = 0; j < 5; j++) dn.addEdge(sz + j, 6 + sz, n / 5);

	
	if (dn.maxflow() == n) puts("fair");
	else puts("unfair");

	return 0;
}