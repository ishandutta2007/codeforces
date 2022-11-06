#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int n, co[maxn + 10], fa[maxn + 10];
int dfn[maxn + 10], ed[maxn + 10], dcnt;
int val[maxn + 10], sum[maxn + 10];
vector<int> g[maxn + 10];

void dfs(int p) {
	dfn[p] = ++dcnt; val[dcnt] = co[p];
	for (int i = 0; i < g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fa[p]) {
			fa[e] = p; dfs(e);
		}
	}
	ed[p] = dcnt;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);
	}
	for (int i = 1; i <= n; ++i) scanf("%d", &co[i]);
	dfs(1);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + (val[i] != val[i - 1]);
	for (int i = 1; i <= n; ++i) {
		bool fd = 1;
		for (int j = 0; j < g[i].size(); ++j) {
			int e = g[i][j];
			if (e != fa[i])
				if (sum[ed[e]] - sum[dfn[e]]) {
					fd = 0; break;
				}
		}
		if ((dfn[i] > 1 && sum[dfn[i] - 1] - sum[1]) || (ed[i] < n && sum[n] - sum[ed[i] + 1]) || (dfn[i] > 1 && ed[i] < n && val[1] != val[n])) fd = 0;
		if (fd) {
			printf("YES\n%d", i); return 0;
		}
	}
	printf("NO");
}