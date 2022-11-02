#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <long long, int> pli;

long long a[300010];
int n, m, W;
vector <pii> from[300010];
vector <pii> G[300010];
int vis[300010];
set <pii> adj[300010];
int fa[300010];
priority_queue <pli> q;

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

void GetTree(int x) {
	vis[x] = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, id = from[x][i].se;
		if (vis[v]) continue;
		G[x].push_back(mp(v, id)), G[v].push_back(mp(x, id));
		adj[x].insert(mp(v, id)), adj[v].insert(mp(x, id));
		GetTree(v);
	}
}

void Merge(int x, int y) {
	if (adj[x].size() < adj[y].size()) swap(x, y);
	a[x] += a[y] - W, fa[y] = x;
	for (auto it : adj[y]) {
		int v = it.fi, id = it.se;
		if (find(v) != x) adj[x].insert(mp(find(v), id));
	}
	adj[y].clear(), q.push(mp(a[x], x));
}

int main() {
	scanf("%d%d%d", &n, &m, &W);
	for (int i = 1; i <= n; i++) fa[i] = i;
	long long sum = 0;
	for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]), sum += a[i];
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(mp(y, i + 1));
		from[y].push_back(mp(x, i + 1));
	}
	if (sum < 1ll * (n - 1) * W) {
		printf("NO\n");
		return 0;
	}
	GetTree(1);
	printf("YES\n");
	for (int i = 1; i <= n; i++) q.push(mp((long long)a[i], i));
	for (int T = 1; T < n; T++) {
		pli t = q.top(); q.pop(); int x = t.se;
		while (fa[x] != x || t.fi != a[x]) t = q.top(), q.pop(), x = t.se;
		for (set <pii> :: iterator it = adj[x].begin(); it != adj[x].end(); ) {
			int v = find(it->fi), id = it->se;
			if (v == x) {
				it = adj[x].erase(it);
				continue;
			}
			if (a[x] + a[v] >= W) {
				Merge(x, v), printf("%d\n", id);
				goto END;
			}
			it++;
		}
		assert(0);
		END:;
	}
	return 0;
}