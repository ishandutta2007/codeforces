#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 11100, M = 80010;
const int inf = 0x3f3f3f3f;

namespace MaxFlowMinCost {
	int first[N], cur = 1, S, T;
	struct Edge {int nxt, to, fl, w;} e[M];
	void Con(int x, int y, int z, int w) {
		e[++cur] = (Edge){first[x], y, z, w};
		first[x] = cur;
	}
	void con(int x, int y, int z, int w) {
		Con(x, y, z, w), Con(y, x, 0, -w);
	}
	int q[N], l, r, inq[N], d[N], lst[N];
	int Spfa() {
		for (int i = 1; i <= T; i++) d[i] = inf;
		q[l = 1] = S, inq[S] = 1, d[S] = 0, r = 2;
		while (l != r) {
			int u = q[l++]; inq[u] = 0; if (l == T + 2) l = 1;
			for (int i = first[u], v; i; i = e[i].nxt)
				if (e[i].fl && d[v = e[i].to] > d[u] + e[i].w) {
					d[v] = d[u] + e[i].w, lst[v] = i;
					if (!inq[v]) {
						q[r] = v, inq[v] = 1;
						r = r == T + 1 ? 1 : r + 1;
					}
				}
		}
		return d[T] != inf;
	}
	int EK() {
		int ret = 0;
		while (Spfa()) {
			int mn = inf, tmp = 0;
			for (int i = T; i != S; i = e[lst[i] ^ 1].to)
				mn = min(mn, e[lst[i]].fl), tmp += e[lst[i]].w;
			ret += mn * tmp;
			for (int i = T; i != S; i = e[lst[i] ^ 1].to)
				e[lst[i]].fl -= mn, e[lst[i] ^ 1].fl += mn;
		}
		return ret;
	}
}; // need N, M, inf
using namespace MaxFlowMinCost;

int n, m, b[110][110];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			b[i][j] = 2;
	for (int i = 1; i <= n; i++)
		b[i][i] = 0;
	for (int i = 1, x, y; i <= m; i++)
		scanf("%d%d", &x, &y), b[x][y] = 1, b[y][x] = 0;
	S = n * (n - 1) / 2 + n + 1, T = S + 1;
	int c = 0, t = n * (n - 1) / 2;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++) {
			con(S, ++c, 1, 0);
			if (b[i][j] != 1) con(c, t + i, 1, 0);
			if (b[i][j] != 0) con(c, t + j, 1, 0);
		}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < n; j++)
			con(t + i, T, 1, j);
	EK(), c = 0;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++) {
			++c;
			if (b[i][j] == 2) {
				for (int k = first[c]; k; k = e[k].nxt)
					if (t < e[k].to && e[k].fl == 0) {
						if (e[k].to - t == i) b[i][j] = 0, b[j][i] = 1;
						else b[i][j] = 1, b[j][i] = 0;
						break;
					}
			}
		}
	for (int i = 1; i <= n; i++, puts(""))
		for (int j = 1; j <= n; j++)
			printf("%d", b[i][j]);
	return 0;
}