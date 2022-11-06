#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int maxn = 3e5;
const ll inf = 1e18;
int n, m, dep[maxn + 10];
vector<int> g[maxn + 10];
vector<pair<int, int> > z[maxn + 10];
ll f[maxn + 10];
priority_queue<pii, vector<pii>, greater<pii> > hp[maxn + 10];
ll dt[maxn + 10], ans;

void dfsdep(int p, int fa) {
	dep[p] = dep[fa] + 1;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fa) dfsdep(e, p);
	}
}

void merge(int x, int y) {
	if (hp[x].size() < hp[y].size()) {
		hp[x].swap(hp[y]); swap(dt[x], dt[y]);
	}
	while (!hp[y].empty()) {
		pii p = hp[y].top(); hp[y].pop();
		p.first += dt[y]; p.first -= dt[x];
		hp[x].push(p);
	}
}

void dfs(int p, int fa) {
	ll sum = 0; int cnt = 0;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fa) {
			dfs(e, p);
			if (f[e] != -1) sum += f[e];
			else ++cnt;
		}
	}
	if (!cnt) {
		for (int i = 0; i < (int)z[p].size(); ++i) {
			pair<int, int> e = z[p][i];
			hp[p].push(make_pair(sum + e.second, e.first));
		}
	}
	for (int i = 0; i < (int)g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fa && cnt - (f[e] == -1) == 0) {
			dt[e] = dt[e] + sum - max(f[e], 0ll);
			merge(p, e);
		}
	}
	while (!hp[p].empty() && hp[p].top().second >= dep[p]) hp[p].pop();
	f[p] = hp[p].empty() ? -1 : dt[p] + hp[p].top().first;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);
	}
	dfsdep(1, 0);
	for (int i = 1; i <= m; ++i) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		z[x].push_back(make_pair(dep[y], w));
	}
	dfs(1, 0);
	for (int i = 0; i < (int)g[1].size(); ++i) {
		int e = g[1][i];
		if (f[e] == -1) {
			printf("-1"); return 0;
		}
		ans += f[e];
	}
	printf("%lld", ans);
}