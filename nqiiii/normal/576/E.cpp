#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5;
int n, m, K, q;
int l[maxn + 10], r[maxn + 10];
int id[maxn + 10], c[maxn + 10];
int vis[maxn + 10], nxt[maxn + 10], co[maxn + 10];
vector<pair<int, int> > op[maxn * 4 + 10];
pair<int*, int> bk[maxn * 10 + 10];
int bcnt;

struct mydsu {

	int fa[maxn + 10], dfa[maxn + 10];

	void init() {
		for (int i = 1; i <= n; ++i) fa[i] = -1;
	}

	int getf(int &p) {
		int ans = 0;
		while (fa[p] > 0) {
			ans ^= dfa[p]; p = fa[p];
		}
		return ans;
	}

	bool merge(int x, int y) {
		int d = 1;
		d ^= getf(x); d ^= getf(y);
		if (x == y) return d;
		if (fa[x] < fa[y]) swap(x, y);
		bk[++bcnt] = make_pair(&fa[x], fa[x]);
		bk[++bcnt] = make_pair(&fa[y], fa[y]);
		bk[++bcnt] = make_pair(&dfa[x], dfa[x]);
		fa[y] += fa[x]; fa[x] = y;
		dfa[x] = d; return 0;
	}
}dsu[51];

void addin(int p, int l, int r, pair<int, int> v, int ls, int rs) {
	if (l > r) return;
	if (ls == l && rs == r) op[p].push_back(v);
	else {
		int mid = (ls + rs) >> 1;
		if (r <= mid) addin(p << 1, l, r, v, ls, mid);
		else if (l > mid) addin(p << 1 | 1, l, r, v, mid + 1, rs);
		else {
			addin(p << 1, l, mid, v, ls, mid);
			addin(p << 1 | 1, mid + 1, r, v, mid + 1, rs);
		}
	}
}

void dfs(int p, int ls, int rs) {
	int lst = bcnt;
	for (int i = 0; i < (int)op[p].size(); ++i) {
		pair<int, int> e = op[p][i];
		assert(!dsu[e.first].merge(l[e.second], r[e.second]));
	}
	if (ls == rs) {
		if (!dsu[c[ls]].merge(l[id[ls]], r[id[ls]])) {
			puts("YES");
			co[id[ls]] = c[ls];
			addin(1, ls + 1, nxt[ls] - 1, make_pair(c[ls], id[ls]), 1, q);
		} else {
			puts("NO");
			if (co[id[ls]])
				addin(1, ls + 1, nxt[ls] - 1, make_pair(co[id[ls]], id[ls]), 1, q);
		}
	} else {
		int mid = (ls + rs) >> 1;
		dfs(p << 1, ls, mid); dfs(p << 1 | 1, mid + 1, rs);
	}
	while (bcnt > lst) {
		*bk[bcnt].first = bk[bcnt].second;
		--bcnt;
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &K, &q);
	for (int i = 1; i <= m; ++i) scanf("%d%d", &l[i], &r[i]);
	for (int i = 1; i <= q; ++i) scanf("%d%d", &id[i], &c[i]);
	for (int i = q; i >= 1; --i) {
		if (!vis[id[i]]) nxt[i] = q + 1;
		else nxt[i] = vis[id[i]];
		vis[id[i]] = i;
	}
	for (int i = 1; i <= K; ++i) dsu[i].init();
	dfs(1, 1, q);
}