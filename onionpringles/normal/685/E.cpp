#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000;
const int M = 200000;

int dist[N][N];

class Query {
public:
	int l, r, s, t;
	int id;
	Query() {}
	Query(int ll, int rr, int ss, int tt) :l(ll), r(rr), s(ss), t(tt) {}
	bool operator<(const Query& x) const {
		return l > x.l;
	}
} qs[M];

class Edge {
public:
	int u, v;
	Edge() {}
	Edge(int uu, int vv) :u(uu), v(vv) {}
} e[M];

int ans[M];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, q; scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		e[i] = Edge(u, v);
	}
	for (int i = 0; i < q; i++) {
		int l, r, s, t;
		scanf("%d%d%d%d", &l, &r, &s, &t);
		l--; r--; s--; t--;
		qs[i] = Query(l, r, s, t);
		qs[i].id = i;
	}
	sort(qs, qs + q);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = m;
			if (i == j) dist[i][j] = 0;
		}
	}
	int curp = 0;
	for (int cur = m - 1; cur >= 0; cur--) {
		int u = e[cur].u;
		int v = e[cur].v;
		for (int i = 0; i < n; i++) {
			if (i == u) {
				dist[v][i] = cur;
			}
			else if (i == v) {
				dist[u][i] = cur;
			}
			else
			dist[u][i] = dist[v][i] = min(dist[u][i], dist[v][i]);
		}
		while (curp < q && qs[curp].l == cur) {
			int s = qs[curp].s;
			int t = qs[curp].t; int j = qs[curp].id;
			if (dist[s][t] <= qs[curp].r) {
				ans[j] = 1;
			}
			else ans[j] = 0;
			curp++;
		}
	}
	for (int i = 0; i < q; i++) {
		if (ans[i]) puts("Yes");
		else puts("No");
	}
	return 0;
}