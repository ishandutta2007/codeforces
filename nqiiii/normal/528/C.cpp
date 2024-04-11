#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
int n, m, lst;
int l[maxn + 10], r[maxn + 10], deg[maxn + 10], fa[maxn + 10];
vector<int> g[maxn + 10];

int getf(int p) {
	return fa[p] == p ? p : fa[p] = getf(fa[p]);
}

void dfs(int p, int fa) {
	for (int i = 0; i < (int)g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fa) {
			dfs(e, p);
			if (deg[e]) {
				printf("%d %d\n", e, p); deg[e] ^= 1;
			} else {
				printf("%d %d\n", p, e); deg[p] ^= 1;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		deg[l[i]] ^= 1; deg[r[i]] ^= 1;
	}
	for (int i = 1; i <= n; ++i)
		if (deg[i]) {
			if (!lst) lst = i;
			else {
				l[++m] = lst; r[m] = i;
				lst = 0;
			}
		}
	if (m & 1) {
		l[++m] = 1; r[m] = 1;
	}
	printf("%d\n", m);
	memset(deg, 0, sizeof deg);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		int x = getf(l[i]), y = getf(r[i]);
		if (x == y) {
			printf("%d %d\n", l[i], r[i]);
			deg[l[i]] ^= 1;
		} else {
			g[l[i]].push_back(r[i]); g[r[i]].push_back(l[i]);
			fa[x] = y;
		}
	}
	dfs(1, 0);
}