#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mkp make_pair
#define fi first
#define se second
const int maxn = 2e5;
int n, m;
int fa[maxn + 10], dep[maxn + 10];
bool vis[maxn + 10], mk[maxn + 10];
vector<int> g[maxn + 10];
set<pii> a[maxn + 10], del[maxn + 10];
vector<int> z[maxn + 10];
vector<int> b;

void mergeto(set<pii> &x, set<pii> &y) {
	if (x.size() < y.size()) x.swap(y);
	for (auto i: y) x.insert(i);
}

void adde(int x, int y) {
	z[x].push_back(y); z[y].push_back(x);
}	

void mark(int x, int y) {
	adde(x, y);
	while (x != y) {
		if (!mk[x]) {
			mk[x] = 1;
			adde(x, fa[x]);
		}
		x = fa[x];
	}
}

void dfs2(int p, int fa) {
	if (fa && z[p].size() == 3) {
		printf("%d ", (int)b.size() + 1);
		for (auto i: b) printf("%d ", i);
		printf("%d\n", p); return;
	}
	b.push_back(p);
	for (auto i: z[p])
		if (i != fa) dfs2(i, p);
	b.pop_back();
}

void solve(pii x, pii y) {
	mark(x.fi, x.se);
	mark(y.fi, y.se);
	for (int i = 1; i <= n; ++i)
		if (z[i].size() == 3) {
			dfs2(i, 0);
			exit(0);
		}
}

void dfs(int p) {
	dep[p] = dep[fa[p]] + 1; vis[p] = 1;
	for (auto i: g[p])
		if (i != fa[p]) {
			if (vis[i]) {
				if (dep[i] < dep[p]) {
					a[p].insert(mkp(p, i));
					del[i].insert(mkp(p, i));
				}
			} else {
				fa[i] = p; dfs(i);
				mergeto(a[p], a[i]);
			}
		}
	for (auto i: del[p]) a[p].erase(i);
	if (a[p].size() >= 2) {
		printf("YES\n");
		solve(*a[p].begin(), *a[p].rbegin());
		assert(0);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) dfs(i);
	printf("NO\n");
}