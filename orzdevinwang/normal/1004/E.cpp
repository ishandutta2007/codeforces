#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7, inf = 1e9 + 7;
int n, s, fa[N], vis[N], len[N], dep[N], ans = inf, l = 1, r = 1;
int ehd[N], enx[N], ev[N], ew[N], eid;
void eadd(int u, int v, int w) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid;
}
void dfs(int x) {
	for(int i = ehd[x]; i; i = enx[i]) if(!vis[ev[i]] && fa[x] ^ ev[i]) {
		fa[ev[i]] = x;
		len[ev[i]] = len[x] + 1, dep[ev[i]] = dep[x] + ew[i];
		dfs(ev[i]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> s, --s;
	L(i, 1, n - 1) {
		int u, v, val;
		cin >> u >> v >> val;
		eadd(u, v, val);
		eadd(v, u, val);
	}
	dfs(1);
	L(i, 1, n) if(dep[i] > dep[l]) l = i;
	memset(fa, 0, sizeof(fa));
	dep[l] = len[l] = 0, dfs(l);
	L(i, 1, n) if(dep[i] > dep[r]) r = i;
	int t = r;
	for(int i = r; i; i = fa[i]) {
		while(fa[t] && len[i] - len[fa[t]] <= s) t = fa[t];
		ans = min(ans, max(dep[t], dep[r] - dep[i]));
	}
	for(int i = r; i; i = fa[i]) vis[i] = 1;
	for(int i = r; i; i = fa[i]) dep[i] = 0, dfs(i);
	L(i, 1, n) if(!vis[i]) ans = max(ans, dep[i]);
	cout << ans << "\n";
	return 0;
}