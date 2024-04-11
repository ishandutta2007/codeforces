#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()

using namespace std;
const int N = 1e5 + 5;
int n, m, co[N], id[N], idx = 2;
vector <int> G[N], f[2];
int dfs(int u) {
	f[co[u] - 1].push_back(u);
	for(int v : G[u]) if(co[u] == co[v] || (!co[v] && !dfs((co[v] = 3 - co[u], v)))) return 0;
	return 1;
}
int find() {
	static int lst;
	for(int u : f[0]) if(u ^ lst) {
		if(f[1].size() < G[u].size() + 2) continue;
		vector <int> tmp;
		sort(all(G[u]));
		for(int v : f[1]) if(!binary_search(all(G[u]), v)) tmp.push_back(v);
		id[u] = ++idx, id[tmp[0]] = ++idx, id[tmp[1]] = ++idx;
		return lst = u, 1;
	}
	return 0;
}
int main() {
	cin >> n >> m;
	for(int u, v; m--; scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u));
	rep(i, 1, n) if(!co[i]) co[i] = 1, dfs(i);
	if(f[0].size() % 3 == 0) {
		rep(i, 0, 1) for(int x : f[i]) id[x] = ++idx;
		puts("YES");
		rep(i, 1, n) printf("%d ", id[i] / 3);
		exit(0);
	}
	if(f[1].size() % 3 == 1) swap(f[0], f[1]);
	if(!find() && (swap(f[0], f[1]), !find() || !find())) puts("NO"), exit(0);
	rep(i, 0, 1) for(int x : f[i]) if(!id[x]) id[x] = ++idx;
	puts("YES");
	rep(i, 1, n) printf("%d ", id[i] / 3);
}