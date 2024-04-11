#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e6 + 7;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
int n, m;
int fa[N];
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
int tot, maxn[N], ch[N][2];
int minn[N], hd[N];
void upd(int x) {
	minn[x] = 1e9;
	if(ch[x][0]) minn[x] = min(minn[x], minn[ch[x][0]]);
	if(ch[x][1]) minn[x] = min(minn[x], minn[ch[x][1]]);
}
int merge(int x, int y) {
	if(!x || !y) return x | y;
	int nw = ++tot;
	minn[nw] = min(minn[x], minn[y]);
	ch[nw][0] = merge(ch[x][0], ch[y][0]);
	ch[nw][1] = merge(ch[x][1], ch[y][1]);
	return nw;
}
void ins(int &id, int L, int R, int wz, int val) {
	id = ++tot;
	if(L == R) return minn[id] = val, void();
	int mid = (L +R) >> 1;
	if(wz <= mid) ins(ch[id][0], L, mid, wz, val);
	else ins(ch[id][1], mid + 1, R, wz, val);
	upd(id);
}
int query(int id, int L, int R, int l, int r) {
	if(!id) return 1e9;
	if(l <= L && R <= r) return minn[id];
	int mid = (L + R) >> 1, res = 1e9;
	if(l <= mid) res = min(res, query(ch[id][0], L, mid, l, r));
	if(r > mid) res = min(res, query(ch[id][1], mid + 1, R, l, r));
	return res; 
}
int rt, dep[N], a[N];
void dfs(int x) {
	ins(hd[x], 1, n, dep[x], a[x]);
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa[x]) continue;
		fa[v] = x, dep[v] = dep[x] + 1, dfs(v);
		hd[x] = merge(hd[x], hd[v]);
	}
}
int lastans;
int main() {
	n = read(), rt = read();
	L(i, 1, n) a[i] = read();
	L(i, 1, n - 1) {
		int u = read(), v = read();
		add_edge(u, v), add_edge(v, u);
	}
	dep[rt] = 1, dfs(rt);
	m = read();
	while(m--) {
		int x, k; 
		x = read(), k = read();
		x = (x + lastans) % n + 1;
		k = (k + lastans) % n;
		printf("%d\n", lastans = query(hd[x], 1, n, dep[x], min(dep[x] + k, n)));
	}
	return 0;
}