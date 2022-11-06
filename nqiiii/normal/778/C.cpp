#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000, maxc = 2000000;
int n, dep[maxn + 10], ans[maxn + 10], id;
int ch[maxc + 10][26], ndcnt;

struct edge {
	int to; char c;
};
vector<edge> g[maxn + 10];

int merge(int x, int y, int d) {
	if (!x || !y) return x + y;
	++ans[d]; int p = ++ndcnt;
	for (int i = 0; i < 26; ++i) 
		ch[p][i] = merge(ch[x][i], ch[y][i], d);
	return p;
}

void dfs(int p, int fa) {
	dep[p] = dep[fa] + 1;
	for (int i = 0; i < g[p].size(); ++i) {
		edge e = g[p][i];
		if (e.to != fa) {
			ch[p][e.c - 'a'] = e.to; dfs(e.to, p);
		}
	}
	int rt = 0; ndcnt = n;
	for (int i = 0; i < g[p].size(); ++i) {
		edge e = g[p][i];
		if (e.to != fa) rt = merge(rt, e.to, dep[p]);
	}
	ans[dep[p]] += bool(rt);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int l, r; char c[5];
		scanf("%d%d%s", &l, &r, c);
		g[l].push_back((edge){r, c[0]});
		g[r].push_back((edge){l, c[0]});
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i)
		if (ans[i] > ans[id]) id = i;
	printf("%d\n%d", n - ans[id], id);
}