#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) + rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

using namespace std;

const int maxn = 2e5 + 10;

int n, m, k, u[maxn], v[maxn], ans[maxn];
bool ban[maxn];
set<int> g[maxn];
set<pair<int, int> > all;

void work() {
	while(all.size() && all.begin()->first < k) {
		int u = all.begin()->second; all.erase(all.begin());
		ban[u] = 1;
		for (int v: g[u]) {
			all.erase(make_pair(g[v].size(), v));
			g[v].erase(u);
			all.insert(make_pair(g[v].size(), v));
		}
	}
	return;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) scanf("%d%d", u + i, v + i), g[u[i]].insert(v[i]), g[v[i]].insert(u[i]);
	for (int u = 1; u <= n; ++u) all.insert(make_pair(g[u].size(), u));
	work();
	ans[m] = all.size();
	for (int i = m - 1; i; --i) {
		int x = u[i + 1], y = v[i + 1];
		if(!ban[x] && !ban[y]) {
			all.erase(make_pair(g[x].size(), x)); all.erase(make_pair(g[y].size(), y));
			g[x].erase(y); g[y].erase(x);
			all.insert(make_pair(g[x].size(), x)); all.insert(make_pair(g[y].size(), y));
			work();
		}
		ans[i] = all.size();
	}
	for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
	return 0;
}