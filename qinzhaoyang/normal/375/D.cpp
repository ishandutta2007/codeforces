#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, S = 320;

struct Query {
	int l, r, k, id;
	inline friend int operator < (Query &A, Query &B) {
		return A.l / S != B.l / S ? A.l < B.l : A.r < B.r;
	}
}	q[N];

int n, m, c[N], L[N], R[N], dfn[N], cnt, Ans[N], ct[N], A[N];
vector <int> G[N];

void add(int x) {
	ct[c[dfn[x]]]++;
	if (ct[c[dfn[x]]]) A[ct[c[dfn[x]]]]++;
}

void sub(int x) {
	if (ct[c[dfn[x]]]) A[ct[c[dfn[x]]]]--;
	ct[c[dfn[x]]]--;
}

void dfs(int x, int fa) {
	L[x] = ++cnt, dfn[cnt] = x;
	for (int i : G[x]) if (i != fa)
		dfs(i, x);
	R[x] = cnt;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= m; i++) {
		int u, k; scanf("%d%d", &u, &k);
		q[i] = (Query){L[u], R[u], k, i};
	}
	sort (q + 1, q + m + 1);
	int l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		int tl = q[i].l, tr = q[i].r;
		while (l < tl) sub(l++); while (l > tl) add(--l);
		while (r < tr) add(++r); while (r > tr) sub(r--);
		Ans[q[i].id] = A[q[i].k];
	}
	for (int i = 1; i <= m; i++)
		printf("%d\n", Ans[i]);
	return 0;
}