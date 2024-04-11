#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000, maxc = 4000000;
char s[maxn + 10];
int n, q, m;

namespace di_sword {
	int lc[maxc + 10], rc[maxc + 10], ndcnt;

	void add(int &p, int k, int ls, int rs) {
		if (!p) p = ++ndcnt;
		if (ls != rs) {
			int mid = ls + rs >> 1;
			if (k <= mid) add(lc[p], k, ls, mid);
			else add(rc[p], k, mid + 1, rs);
		}
	}

	int merge(int x, int y) {
		if (!x || !y) return x + y;
		int p = ++ndcnt;
		lc[p] = merge(lc[x], lc[y]);
		rc[p] = merge(rc[x], rc[y]);
		return p;
	}

	bool query(int p, int l, int r, int ls, int rs) {
		if (!p || l > r) return 0;
		if (l == ls && r == rs) return 1;
		int mid = ls + rs >> 1;
		if (r <= mid) return query(lc[p], l, r, ls, mid);
		else if (l > mid) return query(rc[p], l, r, mid + 1, rs);
		else return query(lc[p], l, mid, ls, mid) || query(rc[p], mid + 1, r, mid + 1, rs);
	}

}

namespace real_boot {
	int ch[maxn * 2 + 10][26], fa[maxn * 2 + 10], maxl[maxn * 2 + 10], rt[maxn * 2 + 10];
	int np = 1, ndcnt = 1; bool islv[maxn * 2 + 10];
	vector<int> g[maxn * 2 + 10];

	void add(int c) {
		int p = np; np = ++ndcnt;
		maxl[np] = maxl[p] + 1; islv[np] = 1;
		while (p && !ch[p][c]) {
			ch[p][c] = np; p = fa[p];
		}
		if (p) {
			int q = ch[p][c];
			if (maxl[p] + 1 == maxl[q]) fa[np] = q;
			else {
				int nq = ++ndcnt; fa[nq] = fa[q];
				fa[q] = fa[np] = nq; maxl[nq] = maxl[p] + 1;
				for (int i = 0; i < 26; ++i) ch[nq][i] = ch[q][i];
				while (ch[p][c] == q) {
					ch[p][c] = nq; p = fa[p];
				}
			}
		} else fa[np] = 1;
	}

	void dfs(int p) {
		if (islv[p]) di_sword::add(rt[p], maxl[p], 1, n);
		for (int i = 0; i < g[p].size(); ++i) {
			int e = g[p][i];
			dfs(e); rt[p] = di_sword::merge(rt[p], rt[e]);
		}
	}

	void build() {
		for (int i = 2; i <= ndcnt; ++i)
			g[fa[i]].push_back(i);
		dfs(1);
	}

	bool query(int p, int l, int r, int len) {
		return di_sword::query(rt[p], l + len - 1, r, 1, n);
	}	
}

char update(int p, int c, int l, int r, int len) {
	while (c < 26) {
		if (real_boot::ch[p][c] && real_boot::query(real_boot::ch[p][c], l, r, len)) return c;
		++c;
	}
	return -1;
}

int main() {
	scanf("%s%d", s + 1, &q); n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) real_boot::add(s[i] - 'a');
	real_boot::build();
	while (q--) {
		int l, r, p = 1, pos = 0; scanf("%d%d%s", &l, &r, s + 1);
		m = strlen(s + 1);
		int c = update(p, s[1] - 'a' + 1, l, r, 1);
		for (int i = 1; i <= m; ++i) {
			p = real_boot::ch[p][s[i] - 'a'];
			if (!p || !real_boot::query(p, l, r, i)) break;
			char t = update(p, i == m ? 0 : s[i + 1] - 'a' + 1, l, r, i + 1);
			if (t != -1) {
				pos = i; c = t;
			}
		}
		if (c != -1) {
			for (int i = 1; i <= pos; ++i) printf("%c", s[i]);
			printf("%c\n", c + 'a'); 
		} else printf("-1\n");
	}
}