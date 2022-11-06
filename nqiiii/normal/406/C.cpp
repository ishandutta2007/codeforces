#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int n, m, dfn[maxn + 10], dfscnt, res[maxn + 10][3], cnt;
vector<int> g[maxn + 10];

bool dfs(int p, int fa) {
	dfn[p] = ++dfscnt; vector<int> now;
	for (int i = 0; i < g[p].size(); ++i) {
		int e = g[p][i];
		if (!dfn[e]) {
			if (dfs(e, p)) now.push_back(e);
		} else if (e != fa && dfn[e] < dfn[p]) now.push_back(e);
	}
	if (fa) now.push_back(fa);
	for (int i = 0; i + 1 < now.size(); i += 2) {
		res[++cnt][0] = now[i];
		res[cnt][1] = p; res[cnt][2] = now[i + 1];
	}
	return now.size() & 1;
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i] && dfs(i, 0)) {
			printf("No solution"); return 0;
		}
	for (int i = 1; i <= cnt; ++i)
		printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
}