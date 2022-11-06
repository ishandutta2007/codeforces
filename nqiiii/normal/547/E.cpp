#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int n, q, pos[maxn + 10], ans[maxn * 3 + 10];
char s[maxn + 10];

struct que {
	int l, r, id;
};

namespace seg {
	const int maxc = maxn * 20;
	int lc[maxc + 10], rc[maxc + 10], val[maxc + 10];
	int ndcnt;

	void modify(int &p, int k, int ls, int rs) {
		if (!p) p = ++ndcnt;
		++val[p];
		if (ls != rs) {
			int mid = (ls + rs) >> 1;
			if (k <= mid) modify(lc[p], k, ls, mid);
			else modify(rc[p], k, mid + 1, rs);
		}
	}

	int merge(int x, int y) {
		if (!x || !y) return x + y;
		val[x] += val[y]; 
		lc[x] = merge(lc[x], lc[y]); rc[x] = merge(rc[x], rc[y]);
		return x;
	}

	int query(int p, int l, int r, int ls, int rs) {
		if (ls == l && rs == r) return val[p];
		else {
			int mid = (ls + rs) >> 1;
			if (r <= mid) return query(lc[p], l, r, ls, mid);
			else if (l > mid) return query(rc[p], l, r, mid + 1, rs);
			else return query(lc[p], l, mid, ls, mid) + query(rc[p], mid + 1, r, mid + 1, rs);
		}
	}
}

namespace acm {
	int ch[maxn + 10][26], ndcnt;
	int nxt[maxn + 10], rt[maxn + 10];
	vector<int> a[maxn + 10], g[maxn + 10];
	vector<que> c[maxn + 10];

	int ins(char *s, int id) {
		int l = strlen(s + 1), p = 0;
		for (int i = 1; i <= l; ++i) {
			int d = s[i] - 'a';
			if (!ch[p][d]) ch[p][d] = ++ndcnt;
			p = ch[p][d]; a[p].push_back(id);
		}
		return p;
	}

	void dfs(int p) {
		for (int i = 0; i < (int)a[p].size(); ++i)
			seg::modify(rt[p], a[p][i], 1, n);
		for (int i = 0; i < (int)g[p].size(); ++i) {
			int e = g[p][i]; dfs(e);
			rt[p] = seg::merge(rt[p], rt[e]);
		}
		for (int i = 0; i < (int)c[p].size(); ++i) {
			que e = c[p][i];
			ans[e.id] = seg::query(rt[p], e.l, e.r, 1, n);
		}
	}

	void build() {
		static queue<int> q;
		for (int i = 0; i < 26; ++i)
			if (ch[0][i]) q.push(ch[0][i]);
		while (!q.empty()) {
			int p = q.front(); q.pop();
			g[nxt[p]].push_back(p);
			for (int i = 0; i < 26; ++i)
				if (ch[p][i]) {
					nxt[ch[p][i]] = ch[nxt[p]][i];
					q.push(ch[p][i]);
				} else ch[p][i] = ch[nxt[p]][i];
		}
		dfs(0);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		pos[i] = acm::ins(s, i);
	}
	for (int i = 1; i <= q; ++i) {
		int l, r, p; scanf("%d%d%d", &l, &r, &p);
		acm::c[pos[p]].push_back((que){l, r, i});
	}
	acm::build();
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
}