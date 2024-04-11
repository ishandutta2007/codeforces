#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ld long double
#define i128 __int128 
using namespace std;
const int N = 1e6 + 7;
int n, m, tot, nsa[N], nsb[N], deg[N];
vi G[N], e[N];
int f[N];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
} 
void mer(int x, int y) {
	if(find(x) != find(y)) 
		f[find(x)] = find(y), e[x].emplace_back(y), e[y].emplace_back(x), 
			deg[x] += 1, deg[y] += 1;
} 
bool vis[N];
void init() {
	int mxd = 1;
	L(i, 1, n) if(sz(e[i]) > sz(e[mxd])) mxd = i;
	for(const int &v : G[mxd]) vis[v] = true;
	L(i, 1, n) if(!vis[i]) mer(i, mxd);
	for(const int &v : G[mxd]) vis[v] = false;
	for(const int &x : G[mxd]) {
		for(const int &v : G[x]) vis[v] = true;
		L(i, 1, n) if(!vis[i]) mer(x, i);
		for(const int &v : G[x]) vis[v] = false;
	}
}
void del(int x) {
	vis[x] = true, deg[x] = 0;
	for(const int &v : e[x]) 
		deg[v] -= 1;
}
bool can[N];
void dfs(int x) {
	if(!deg[x]) return nsa[x] = nsb[x] = ++tot, del(x), void ();
	vi qwq;
	can[x] = true;
	for(const int &v : e[x]) if(!vis[v] && deg[v] == 1) qwq.emplace_back(v);
	if(!sz(qwq)) {
		for(const int &v : e[x]) if(!vis[v] && can[v]) {
			nsa[x] = nsb[v] = ++tot, nsb[x] = nsa[v] = ++tot, del(x), del(v);
			for(const int &cv : e[x]) if(!vis[cv]) dfs(cv);
			for(const int &cv : e[v]) if(!vis[cv]) dfs(cv);
			return ;
		} 
		for(const int &v : e[x]) if(!vis[v]) 
			return dfs(v), void ();
		assert(false);
	} 
	del(x), nsa[x] = ++tot;
	for(const int &v : qwq) del(v), nsb[v] = tot, nsa[v] = ++tot;
	nsb[x] = tot;
	for(const int &v : e[x]) if(!vis[v]) dfs(v);
}
void Main () {
	cin >> n >> m;
	L(i, 1, n) f[i] = i;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	init();
	tot = 0;
	L(i, 1, n) if(!vis[i]) dfs(i);
	L(i, 1, n) cout << nsa[i] << ' ';
	cout << '\n';
	L(i, 1, n) cout << nsb[i] << ' ';
	cout << '\n';
	L(i, 1, n) G[i].clear(), e[i].clear(), vis[i] = false, deg[i] = 0, can[i] = 0;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main ();
	return 0;
}