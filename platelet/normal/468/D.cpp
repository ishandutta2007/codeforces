#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define fi first
#define se second
#define mp make_pair
#define in insert
#define er erase

using namespace std;
const int N = 1e5 + 5;
int n, sz[N], mi, root; long long ans;
vector <pair <int, int> > G[N];
int cnt, rt[N]; set <pair <int, int> > id; set <int> tr[N], s;
void find(int u, int fa) {
	sz[u] = 1; int ma = 0;
	for(auto v : G[u]) if(v.fi ^ fa) {
		find(v.fi, u), sz[u] += sz[v.fi], ma = max(ma, sz[v.fi]);
		ans += 2LL * v.se * min(sz[v.fi], n - sz[v.fi]);
	}
	if((ma = max(ma, n - sz[u])) < mi) root = u, mi = ma;
}
void dfs(int u, int fa) {
	tr[rt[u] = cnt].in(u); for(auto v : G[u]) if(v.fi ^ fa) dfs(v.fi, u);
}
int main() {
	cin >> n;
	int u, v, w;
	rep(i, 2, n) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back(mp(v, w)), G[v].push_back(mp(u, w));
	}
	mi = 1e9, find(1, 0);
	cout << ans << endl;
	if(n == 1) return puts("1"), 0;
	for(auto v : G[root]) {
		cnt++, dfs(v.fi, root), s.in(*tr[cnt].begin());
		sz[cnt] = tr[cnt].size() * 2, id.in(mp(sz[cnt], cnt));
	}
	tr[rt[root] = ++cnt].in(root), s.in(root);
	rep(i, 1, n) {
		int x, msz = id.rbegin() -> fi, mid = id.rbegin() -> se;
		if(msz == n - i + 1 && mid ^ rt[i]) x = *tr[mid].begin();
		else if(rt[*s.begin()] ^ rt[i] || i == root) x = *s.begin();
		else x = *++s.begin();
		tr[rt[x]].er(x), s.er(x);
		if(!tr[rt[x]].empty()) s.in(*tr[rt[x]].begin());
		if(i ^ root) id.er(mp(sz[rt[i]], rt[i])), id.in(mp(--sz[rt[i]], rt[i]));
		if(x ^ root) id.er(mp(sz[rt[x]], rt[x])), id.in(mp(--sz[rt[x]], rt[x]));
		printf("%d ", x);
	}
}