#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5;
int n, f[maxn + 10], k;
vector<int> g[maxn + 10], a;
bool in[maxn + 10], inin[maxn + 10];
int fa[maxn + 10], sz[maxn + 10];

void dfs(int p) {
	sz[p] = 1;
	for (auto i: g[p])
		if (in[i] && i != fa[p]) {
			fa[i] = p; dfs(i);
			sz[p] += sz[i];
		}
}

void dfsit(int p, vector<int> &x) {
	x.push_back(p); inin[p] = 1;
	for (auto i: g[p])
		if (in[i] && i != fa[p]) dfsit(i, x);
}

void solve(vector<int> a, int k) {
	if (k <= 1) return;
	for (auto i: a) in[i] = 1;
	fa[a[0]] = 0;
	dfs(a[0]);
	int pos = -1;
	for (auto i: a)
		if (sz[i] == f[k - 1] || sz[i] == f[k - 2]) {
			pos = i;
		}
	if (pos == -1) {
		printf("NO\n"); exit(0);
	}
	vector<int> l, r;
	dfsit(pos, l);
	for (auto i: a)
		if (!inin[i]) r.push_back(i);
	for (auto i: a)
		in[i] = inin[i] = 0;
	if (l.size() < r.size()) {
		solve(l, k - 2); solve(r, k - 1);
	} else {
		solve(l, k - 1); solve(r, k - 2);
	}
}


int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("YES"); return 0;
	}
	for (int i = 1; i < n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);
	}
	f[0] = f[1] = 1;
	for (k = 2; ; ++k) {
		f[k] = f[k - 1] + f[k - 2];
		if (f[k] >= n) break;
	}
	if (f[k] != n) {
		printf("NO"); return 0;
	}
	for (int i = 1; i <= n; ++i)
		a.push_back(i);
	solve(a, k);
	printf("YES");
}