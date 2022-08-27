#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, m, s[N], fa[N], p[N], k[N], siz[N], Ans[N], hv[N];
int L[N], R[N], idtot, mp[N];
vector< int > e[N], ask[N];
void dfs1(int x) {
	siz[x] = 1, L[x] = ++idtot, mp[idtot] = x;
	for(int v : e[x]) if(v ^ fa[x]) {
		fa[v] = x, dfs1(v), siz[x] += siz[v];
		if(siz[v] > siz[hv[x]]) hv[x] = v;
	}
	R[x] = idtot;
}
bool vis[N];
int cnt[N], fcnt[N];
void del(int x) { fcnt[cnt[s[x]]] --, cnt[s[x]] --; }
void add(int x) { cnt[s[x]] ++, fcnt[cnt[s[x]]] ++; }
void dfs2(int x, bool flag) {
	for(int v : e[x]) if(v ^ fa[x] && v ^ hv[x]) dfs2(v, 0);
	if(hv[x]) dfs2(hv[x], 1);
	add(x);
	for(int v : e[x]) if(v ^ fa[x] && v ^ hv[x]) L(i, L[v], R[v]) add(mp[i]);
	if(!vis[x]) for(int t : ask[x]) Ans[t] = fcnt[k[t]];
	vis[x] = 1;
	if(!flag) L(i, L[x], R[x]) del(mp[i]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> s[i];
	L(i, 1, n - 1) {
		int u, v; cin >> u >> v; 
		e[u].push_back(v), e[v].push_back(u);
	}
	L(i, 1, m) cin >> p[i] >> k[i], ask[p[i]].push_back(i);
	dfs1(1), dfs2(1, 1);
	L(i, 1, m) cout << Ans[i] << endl;
	return 0;
}