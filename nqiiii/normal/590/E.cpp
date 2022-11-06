#include <bits/stdc++.h>
using namespace std;
const int maxn = 750, maxc = 1e7;
int n;
char s[maxc + 10];
bool a[maxn + 10][maxn + 10], vis[maxn + 10], is[maxn + 10];
bool visl[maxn + 10], visr[maxn + 10];
int lk[maxn + 10], cnt;

namespace acm {
	int ch[maxc + 10][2], idcnt, ndcnt;
	int ed[maxc + 10], fa[maxc + 10];
	int ne[maxc + 10], nxt[maxc + 10];

	void ins(char *s) {
		int l = strlen(s + 1), p = 0;
		for (int i = 1; i <= l; ++i) {
			int t = s[i] - 'a';
			if (!ch[p][t]) {
				ch[p][t] = ++ndcnt; fa[ndcnt] = p;
			}
			p = ch[p][t];
		}
		if (!ed[p]) ed[p] = ++idcnt;
	}

	void build() {
		static queue<int> q;
		for (int i = 0; i < 2; ++i)
			if (ch[0][i]) q.push(ch[0][i]);
		while (!q.empty()) {
			int p = q.front(); q.pop();
			ne[p] = ed[p] ? ed[p] : ne[nxt[p]];
			for (int i = 0; i < 2; ++i)
				if (ch[p][i]) {
					nxt[ch[p][i]] = ch[nxt[p]][i];
					q.push(ch[p][i]);
				} else ch[p][i] = ch[nxt[p]][i];
		}
		for (int i = 1; i <= ndcnt; ++i)
			if (ed[i])
				for (int j = i; j; j = fa[j]) {
					int to;
					if (j == i) to = ne[nxt[j]];
					else to = ne[j];
					if (to) a[ed[i]][to] = 1;
				}
	}
}

bool dfs(int p) {
	for (int i = 1; i <= n; ++i)
		if (a[p][i] && !vis[i]) {
			vis[i] = 1;
			if (!lk[i] || dfs(lk[i])) {
				lk[i] = p; return 1;
			}
		}
	return 0;
}

void dfs2(int p) {
	visl[p] = 1;
	for (int i = 1; i <= n; ++i)
		if (a[p][i] && !visr[i] && lk[i]) {
			visr[i] = 1; dfs2(lk[i]);
		}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		acm::ins(s);
	}
	acm::build();
	n = acm::idcnt;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				a[i][j] |= a[i][k] && a[k][j];
	for (int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof vis);
		dfs(i);
	}
	for (int i = 1; i <= n; ++i)
		if (lk[i]) is[lk[i]] = 1;
	for (int i = 1; i <= n; ++i)
		if (!is[i]) dfs2(i);
	for (int i = 1; i <= n; ++i)
		if (visl[i] && !visr[i]) ++cnt;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; ++i)
		if (visl[i] && !visr[i]) printf("%d ", i);
}