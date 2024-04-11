#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, m;
int vl, vr, l[maxn + 10], r[maxn + 10];
vector<int> g[maxn + 10];
vector<int> nd[maxn + 10][2];
int wl[maxn + 10][2], wr[maxn + 10][2], co[maxn + 10];
int ndcnt, ans[maxn + 10];

void ext() {
	printf("IMPOSSIBLE"); exit(0);
}

void dfs(int p) {
	wl[ndcnt][co[p] - 1] = max(wl[ndcnt][co[p] - 1], l[p]);
	wr[ndcnt][co[p] - 1] = min(wr[ndcnt][co[p] - 1], r[p]);
	nd[ndcnt][co[p] - 1].push_back(p);
	for (int i = 0; i < (int)g[p].size(); ++i) {
		int e = g[p][i];
		if (co[e]) {
			if (co[p] == co[e]) ext();
		} else {
			co[e] = 3 - co[p];
			dfs(e);
		}
	}
}

int main() {
	scanf("%d%d", &vl, &vr);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &l[i], &r[i]);
	for (int i = 1; i <= m; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);
	}
	memset(wr, 0x3f, sizeof wr);
	for (int i = 1; i <= n; ++i)
		if (!co[i]) {
			++ndcnt;
			co[i] = 1; dfs(i);
		}
	int v1 = 0, v2 = 2e9;
	for (int i = 1; i <= n; ++i) {
		v1 = max(v1, l[i]); v2 = min(v2, r[i]);
	}
	if (v1 + v2 < vl) v1 = vl - v2;
	if (v1 + v2 > vr) v2 = vr - v1;
	if (v1 < 0 || v2 < 0) ext();
	for (int i = 1; i <= ndcnt; ++i) {
		int d = 0;
		if (!(v1 >= wl[i][d] && v1 <= wr[i][d] && v2 >= wl[i][d ^ 1] && v2 <= wr[i][d ^ 1])) 
			d ^= 1;
		if (!(v1 >= wl[i][d] && v1 <= wr[i][d] && v2 >= wl[i][d ^ 1] && v2 <= wr[i][d ^ 1])) 
			ext();
		for (int j = 0; j < (int)nd[i][d].size(); ++j)
			ans[nd[i][d][j]] = 1;
		for (int j = 0; j < (int)nd[i][d ^ 1].size(); ++j)
			ans[nd[i][d ^ 1][j]] = 2;
		
	}
	printf("POSSIBLE\n");
	printf("%d %d\n", v1, v2);
	for (int i = 1; i <= n; ++i) printf("%d", ans[i]);
}