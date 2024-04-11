#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define sz(a) ((int) (a).size())
#define x first
#define y second
using namespace std;
const int N = 3e5 + 7, M = N * 30;
const ll inf = 1e15;
int n, m, ch[M][2], tot;
ll mn[M], tag[M];
void add(int &id, int L, int R, int pos, ll w) {
	if(!id) id = ++tot, mn[id] = inf, tag[id] = 0;
	mn[id] = min(mn[id], w);
	if(L == R) return;
	int mid = (L + R) >> 1;
	if(pos <= mid) add(ch[id][0], L, mid, pos, w);
	else add(ch[id][1], mid + 1, R, pos, w);
}
void ad(int x, ll y) {
	if(x) mn[x] += y, mn[x] = min(mn[x], inf), tag[x] += y, tag[x] = min(tag[x], inf);
}
void pushdown(int x) {
	ad(ch[x][0], tag[x]), ad(ch[x][1], tag[x]), tag[x] = 0;
}
void cover(int id, int L, int R, int pos) {
	if(!id) return;
	if(L == R) return mn[id] = inf, void();
	int mid = (L + R) >> 1;
	pushdown(id);
	if(pos <= mid) cover(ch[id][0], L, mid, pos);
	else cover(ch[id][1], mid + 1, R, pos);
	mn[id] = min(mn[ch[id][0]], mn[ch[id][1]]);
}
int merge(int x, int y, int L, int R, ll xr, ll yr) {  
	if(!x || !y) {
		if(!x && !y) return 0;
		if(!x) return ad(y, xr), y;
		if(!y) return ad(x, yr), x;
	}
	if(L == R) return mn[x] = min(min(mn[x] + yr, mn[y] + xr), min(mn[x] + mn[y], inf)), x;
	pushdown(x), pushdown(y); 
	int mid = (L + R) >> 1; 
	ch[x][0] = merge(ch[x][0], ch[y][0], L, mid, min(xr, mn[ch[x][1]]), min(yr, mn[ch[y][1]]));
	ch[x][1] = merge(ch[x][1], ch[y][1], mid + 1, R, xr, yr);
	mn[x] = min(mn[ch[x][0]], mn[ch[x][1]]);
	return x;
}
int ehd[N], dep[N], enx[N << 1], ev[N << 1], eid, hd[N];
void eadd(int u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
}
void dfs(int x, int fa) {
	for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa) dep[ev[i]] = dep[x] + 1, dfs(ev[i], x);
}
void Dfs(int x, int fa) {
	if(enx[ehd[x]] || x == 1) {
		int cnt = 0, v = 0; 
		for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa) cnt ++, v = ev[i];
		if(cnt == 1) Dfs(v, x), hd[x] = merge(hd[x], hd[v], 1, n, 0ll, inf);
		else {
			add(hd[x], 1, n, dep[x], 0);
			for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa) Dfs(ev[i], x), hd[x] = merge(hd[x], hd[ev[i]], 1, n, inf, inf);
		}
	}
	if(x > 1) cover(hd[x], 1, n, dep[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m, mn[0] = inf;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		eadd(u, v), eadd(v, u);
	}
	dep[1] = 1, dfs(1, 0);
	L(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		add(hd[u], 1, n, dep[v], w);
	}
	Dfs(1, 0);
	if(mn[hd[1]] >= inf) cout << "-1\n";
	else cout << mn[hd[1]] << "\n";  
	return 0;
}