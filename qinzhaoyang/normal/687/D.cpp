#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, q, l[N], r[N], per[N * N];

struct Edge {
	int u, v, w;
}	e[N * N];
inline int cmp(int A, int B) {
	return e[A].w > e[B].w;
}

struct BCJ {
	int fa[N << 1], ans = -1;
	inline int find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	inline void con(int x, int y) {
		if (find(x) != find(y))
			fa[fa[x]] = fa[y];
	}
	inline void init() {
		ans = -1;
		for (int i = 1; i <= n * 2; i++) fa[i] = i;
	}
	inline void Mdf(Edge e) {
		if (ans != -1) return;
		int u = e.u, v = e.v;
		if (find(u) == find(v)) ans = e.w;
		con(u, v + n), con(v, u + n);
	}
}	b;

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	for (int i = 1; i <= q; i++)
		scanf("%d%d", &l[i], &r[i]);
	for (int i = 1; i <= m; i++) per[i] = i;
	sort (per + 1, per + m + 1, cmp);
	for (int j = 1; j <= q; j++) {
		b.init();
		for (int i = 1; i <= m; i++)
			if (l[j] <= per[i] && per[i] <= r[j]) {
				b.Mdf(e[per[i]]);
				if (b.ans != -1) break;
			}
		printf("%d\n", b.ans);
	}
	return 0;
}