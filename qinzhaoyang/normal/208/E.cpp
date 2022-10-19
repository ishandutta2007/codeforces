#include <stdio.h>
#include <bits/stdc++.h>
#define mid ((l + r) >> 1)

using namespace std;

const int N = 1e5 + 10;

struct Node {int lch, rch, v;} o[N * 40];
int rt[N], cnt;

int Mdf(int lst, int l, int r, int x) {
	int p = ++cnt; o[p] = o[lst];
	if (l == r) return o[p].v++, p;
	if (x <= mid) o[p].lch = Mdf(o[lst].lch, l, mid, x);
	else o[p].rch = Mdf(o[lst].rch, mid + 1, r, x);
	return p;
}

int Qry(int A, int B, int l, int r, int x) {
	if (l == r) return o[A].v - o[B].v;
	if (x <= mid) return Qry(o[A].lch, o[B].lch, l, mid, x);
	else return Qry(o[A].rch, o[B].rch, mid + 1, r, x);
}

int n, m, f[N][21], dep[N], L[N], R[N], dfn[N], cur;
vector <int> G[N];

void dfs(int x) {
	dep[x] = dep[f[x][0]] + 1;
	L[x] = ++cur, dfn[cur] = x;
	for (int i : G[x]) dfs(i);
	R[x] = cur;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i][0]); if (!f[i][0]) f[i][0] = n + 1;
		G[f[i][0]].push_back(i);
	}
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= n; i++)
			f[i][j] = f[f[i][j - 1]][j - 1];
	dfs(n + 1), scanf("%d", &m);
	for (int i = 1; i <= n + 1; i++)
		rt[i] = Mdf(rt[i - 1], 1, n + 1, dep[dfn[i]]);
	while (m--) {
		int x, k, t; scanf("%d%d", &x, &k), t = dep[x];
		for (int i = 20; i >= 0; i--)
			if (k >> i & 1) x = f[x][i];
		if (x == n + 1 || !x) printf("0\n");
		else printf("%d\n", Qry(rt[R[x]], rt[L[x] - 1], 1, n + 1, t) - 1);
	}
	return 0;
}