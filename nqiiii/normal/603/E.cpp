#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;

struct edge {
	int l, r, w, id;
	bool operator < (const edge &t) const {
		return w < t.w;
	}
}a[maxn + 10];
int n, m, pos = 0, ans[maxn + 10];
vector<int> b[maxn * 4 + 10];

namespace dsu {

	int fa[maxn + 10];
	pair<int, int> bk[maxn * 5 + 10];
	int bcnt, cnt;

	void init() {
		cnt = n;
		for (int i = 1; i <= n; ++i) fa[i] = -1;
	}

	int getf(int p) {
		while (fa[p] > 0) p = fa[p];
		return p;
	}

	void merge(int x, int y) {
		x = getf(x); y = getf(y);
		if (x != y) {
			if ((fa[x] & 1) && (fa[y] & 1)) cnt -= 2;
			bk[++bcnt] = make_pair(x, fa[x]);
			bk[++bcnt] = make_pair(y, fa[y]);
			if (fa[x] < fa[y]) swap(x, y);
			fa[y] += fa[x]; fa[x] = y;
		}
	}

	void trace(int p) {
		while (bcnt > p) {
			fa[bk[bcnt].first] = bk[bcnt].second;
			--bcnt;
		}
	}

}

void addin(int p, int l, int r, int ls, int rs, int v) {
	if (l > r) return;
	if (ls == l && rs == r) b[p].push_back(v);
	else {
		int mid = (ls + rs) >> 1;
		if (r <= mid) addin(p << 1, l, r, ls, mid, v);
		else if (l > mid) addin(p << 1 | 1, l, r, mid + 1, rs, v);
		else {
			addin(p << 1, l, mid, ls, mid, v);
			addin(p << 1 | 1, mid + 1, r, mid + 1, rs, v);
		}
	}
}

void dfs(int p, int ls, int rs) {
	int lst = dsu::cnt, bk = dsu::bcnt;
	for (int i = 0; i < (int)b[p].size(); ++i) {
		int e = b[p][i];
		dsu::merge(a[e].l, a[e].r);
	}
	if (ls == rs) {
		while (pos <= m && dsu::cnt) {
			if (++pos == m + 1) break;
			if (a[pos].id <= ls) {
				dsu::merge(a[pos].l, a[pos].r);
				addin(1, a[pos].id, ls - 1, 1, m, pos);
			}
		}
		ans[ls] = pos == m + 1 ? -1 : a[pos].w;
	} else {
		int mid = (ls + rs) >> 1;
		dfs(p << 1 | 1, mid + 1, rs);
		dfs(p << 1, ls, mid);
	}
	dsu::cnt = lst; dsu::trace(bk);
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].w);
		a[i].id = i;
	}
	sort(a + 1, a + m + 1);
	dsu::init(); dfs(1, 1, m);
	for (int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
}