#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 2e5 + 10;

int n, m, q, u[M], v[M], s[M], t[M], l[M], r[M], o[M], b[N][N], ans[M];

inline int cmp(int x, int y) {
	return r[x] < r[y];
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &u[i], &v[i]);
	for (int i = 1; i <= q; i++)
		scanf("%d%d%d%d", &l[i], &r[i], &s[i], &t[i]);
	for (int i = 1; i <= q; i++) o[i] = i;
	sort (o + 1, o + q + 1, cmp);
	for (int i = 1; i <= n; i++) b[i][i] = M;
	for (int i = 1, k = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == u[i]) b[v[i]][j] = i;
			else b[v[i]][j] = max(b[v[i]][j], b[u[i]][j]);
			if (j == v[i]) b[u[i]][j] = i;
			else b[u[i]][j] = max(b[u[i]][j], b[v[i]][j]);
		}
		for (; k <= q && r[o[k]] == i; k++)
			ans[o[k]] = b[t[o[k]]][s[o[k]]] >= l[o[k]];
	}
	for (int i = 1; i <= q; i++)
		puts(ans[i] ? "Yes" : "No");
	return 0;
}