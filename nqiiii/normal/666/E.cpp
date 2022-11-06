#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5;
int n, m, q;
int pos[maxn + 10], len[maxn + 10];
char s[maxn + 10], t[maxn + 10];

struct data {
	int v, id;
	data(int _v = 0, int _id = 1e9) {
		v = _v; id = _id;
	}
};

data operator + (const data &a, const data &b) {
	if (a.v != b.v) return a.v > b.v ? a : b;
	return a.id < b.id ? a : b;
}

namespace seg {
	const int maxw = 1e7;

	int lc[maxw + 10], rc[maxw + 10], ndcnt;
	data v[maxw + 10];

	void modify(int &p, int k, int ls, int rs) {
		if (ls == rs) {
			if (!p) {
				p = ++ndcnt; v[p] = data(1, ls);
			} else ++v[p].v;
		} else {
			if (!p) p = ++ndcnt;
			int mid = (ls + rs) >> 1;
			if (k <= mid) modify(lc[p], k, ls, mid);
			else modify(rc[p], k, mid + 1, rs);
			v[p] = v[lc[p]] + v[rc[p]];
		}
	}

	int merge(int x, int y, int ls, int rs) {
		if (!x || !y) return x + y;
		int p = ++ndcnt;
		if (ls == rs) v[p] = data(v[x].v + v[y].v, ls);
		else {
			int mid = (ls + rs) >> 1;
			lc[p] = merge(lc[x], lc[y], ls, mid);
			rc[p] = merge(rc[x], rc[y], mid + 1, rs);
			v[p] = v[lc[p]] + v[rc[p]];
		}
		return p;
	}

	data query(int p, int l, int r, int ls, int rs) {
		if (ls == l && rs == r) return v[p];
		int mid = (ls + rs) >> 1;
		if (r <= mid) return query(lc[p], l, r, ls, mid);
		else if (l > mid) return query(rc[p], l, r, mid + 1, rs);
		else return query(lc[p], l, mid, ls, mid) + query(rc[p], mid + 1, r, mid + 1, rs);
	}
}

namespace sam {
	const int maxc = 1e5, lgn = 17;
	int maxl[maxc + 10], ch[maxc + 10][26], np = 1, ndcnt = 1;
	int fa[maxc + 10], f[maxc + 10][lgn + 1], rt[maxc + 10];
	vector<int> a[maxc + 10];
	vector<int> g[maxc + 10];

	void add(int c) {
		int p = np; np = ++ndcnt;
		maxl[np] = maxl[p] + 1;
		for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
		if (p) {
			int q = ch[p][c];
			if (maxl[p] + 1 == maxl[q]) fa[np] = q;
			else {
				int nq = ++ndcnt; fa[nq] = fa[q];
				maxl[nq] = maxl[p] + 1;
				fa[q] = fa[np] = nq;
				for (int i = 0; i < 26; ++i) ch[nq][i] = ch[q][i];
				for (; ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
			}
		} else fa[np] = 1;
	}

	void addin(char *s, int id) {
		int n = strlen(s + 1); np = 1;
		for (int i = 1; i <= n; ++i) {
			add(s[i] - 'a');
			a[np].push_back(id);
		}
	}

	void dfs(int p) {
		for (int i = 1; i <= lgn; ++i) f[p][i] = f[f[p][i - 1]][i - 1];
		for (int i = 0; i < (int)a[p].size(); ++i)
			seg::modify(rt[p], a[p][i], 1, m);
		for (int i = 0; i < (int)g[p].size(); ++i) {
			int e = g[p][i]; f[e][0] = p;
			dfs(e); rt[p] = seg::merge(rt[p], rt[e], 1, m);
		}
	}

	void build() {
		for (int i = 2; i <= ndcnt; ++i)
			g[fa[i]].push_back(i);
		dfs(1);
	}

	int jump(int p, int len) {
		for (int i = lgn; i >= 0; --i)
			if (maxl[f[p][i]] >= len) p = f[p][i];
		return p;
	}

}

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%s", t + 1);
		sam::addin(t, i);
	}
	sam::build();
	for (int i = 1, p = 1, l = 0; i <= n; ++i) {
		int c = s[i] - 'a';
		while (p != 1 && !sam::ch[p][c]) {
			p = sam::fa[p]; l = sam::maxl[p];
		}
		if (sam::ch[p][c]) {
			++l; p = sam::ch[p][c];
		} else l = 0;
		pos[i] = p; len[i] = l;
	}
	scanf("%d", &q);
	while (q--) {
		int l, r, pl, pr; scanf("%d%d%d%d", &l, &r, &pl, &pr);
		int w = pr - pl + 1;
		if (w > len[pr]) {
			printf("%d %d\n", l, 0); continue;
		}
		int p = sam::jump(pos[pr], w);
		data v = seg::query(sam::rt[p], l, r, 1, m);
		if (v.v) printf("%d %d\n", v.id, v.v);
		else printf("%d %d\n", l, 0);
	}
}