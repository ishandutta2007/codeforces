#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5e5 + 7;
int n, m, dis[N];
int head[N], edge_id, fa[N], dep[N], hv[N], siz[N], id[N], mp[N], idtot;
int mx[1 << 22];
struct edge {
	int to, val, next;
} e[N];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], e[edge_id].val = val, head[u] = edge_id;
}
void dfs1(int x) {
	id[x] = ++idtot, mp[idtot] = x, siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		dis[v] = (dis[x] ^ (1 << e[i].val)), dep[v] = dep[x] + 1, dfs1(v), siz[x] += siz[v];
		if(siz[v] > siz[hv[x]]) hv[x] = v;
	}
}
int ans[N];
void dfs2(int x, bool flag) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to; 
		if(v == hv[x]) continue;
		dfs2(v, 0), ans[x] = max(ans[x], ans[v]);
	}
	if(hv[x]) dfs2(hv[x], 1), ans[x] = max(ans[x], ans[hv[x]]);
	
	L(i, 0, 21) ans[x] = max(ans[x], mx[dis[x] ^ (1 << i)] - dep[x]);
	ans[x] = max(ans[x], mx[dis[x]] - dep[x]), mx[dis[x]] = max(mx[dis[x]], dep[x]);
	
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == hv[x]) continue;
		L(t, id[v], id[v] + siz[v] - 1) {
			int val = dis[mp[t]], Dep = dep[mp[t]];
			L(j, 0, 21) ans[x] = max(ans[x], mx[val ^ (1 << j)] + Dep - dep[x] * 2);
			ans[x] = max(ans[x], mx[val] + Dep - dep[x] * 2);
		}
		L(t, id[v], id[v] + siz[v] - 1) mx[dis[mp[t]]] = max(mx[dis[mp[t]]], dep[mp[t]]);
	}
	if(!flag) L(t, id[x], id[x] + siz[x] - 1) mx[dis[mp[t]]] = -1e9;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 2, n) {
		char ch[6]; 
		cin >> fa[i] >> ch, add_edge(fa[i], i, ch[0] - 'a');
	}
	L(i, 0, (1 << 22) - 1) mx[i] = -1e9;
	dfs1(1), dfs2(1, 1);
	L(i, 1, n) cout << ans[i] << " ";
	cout << "\n"; 
	return 0;
}