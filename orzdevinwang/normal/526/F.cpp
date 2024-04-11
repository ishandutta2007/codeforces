#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 6e5 + 7;
const int M = N * 4;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x * f; 
}
struct SegmentTree {
	int mn[M], flag[M];
	void upd(int x) {
		mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
	}
	void ad(int x, int y) {
		mn[x] += y, flag[x] += y;
	}
	void pushdown(int x) {
		ad(x << 1, flag[x]), ad(x << 1 | 1, flag[x]), flag[x] = 0;
	}
	void add(int id, int L, int R, int l, int r, int v) {
		if(l <= L && R <= r) return ad(id, v), void();
		int mid = (L + R) >> 1;
		pushdown(id);
		if(l <= mid) add(id << 1, L, mid, l, r, v);
		if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, v);
		upd(id);
	}
	int get(int id, int L, int R, int wz) {
		if(L == R) return mn[id];
		int mid = (L + R) >> 1;
		pushdown(id);
		if(wz <= mid) return get(id << 1, L, mid, wz);
		else return get(id << 1 | 1, mid + 1, R, wz);
	}
	int qry(int id, int L, int R) {
		if(L == R) return L;
		pushdown(id);
		int mid = (L + R) >> 1;
		if(!mn[id << 1]) return qry(id << 1, L, mid);
		else return qry(id << 1 | 1, mid + 1, R);
	}
} seg;
int n, head[N], edge_id, type[N], fa[N], up[20][N], dep[N], cnt;
int p[N], stk[N], tot, id[N], L[N], R[N], las[N];
int mxstk[N], mxtot, mnstk[N], mntot, deg[N];
struct edge {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	deg[u] ++;
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void dfs(int x) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		fa[v] = up[0][v] = x, dep[v] = dep[x] + 1, dfs(v);
	}
}
bool chk(int wz) {
	return seg.get(1, 1, n, wz) == 0;
}
void Build() {
	L(i, 1, n) {
		while(mxtot && p[mxstk[mxtot]] < p[i]) 
			seg.add(1, 1, n, mxstk[mxtot - 1] + 1, mxstk[mxtot], p[i] - p[mxstk[mxtot]]), -- mxtot;
		mxstk[++mxtot] = i;
		while(mntot && p[mnstk[mntot]] > p[i]) 
			seg.add(1, 1, n, mnstk[mntot - 1] + 1, mnstk[mntot], p[mnstk[mntot]] - p[i]), -- mntot;
		mnstk[++mntot] = i;	
		id[i] = ++cnt, L[cnt] = R[cnt] = i;
		int lef = seg.qry(1, 1, n), now = cnt;
		while(tot && L[stk[tot]] >= lef) {
			if(type[stk[tot]] && chk(las[stk[tot]])) 
				R[stk[tot]] = i, add_edge(stk[tot], now), now = stk[tot --]; 
			else if(chk(L[stk[tot]])) 
				++cnt, type[cnt] = 1, L[cnt] = L[stk[tot]], R[cnt] = i, 
				add_edge(cnt, stk[tot --]), add_edge(cnt, now), las[cnt] = L[now], now = cnt;
			else {
				++cnt, R[cnt] = i, add_edge(cnt, now);
				while(tot && !chk(L[stk[tot]])) add_edge(cnt, stk[tot --]);
				L[cnt] = L[stk[tot]], add_edge(cnt, stk[tot --]);
				now = cnt;
			}
		}
		stk[++tot] = now, seg.add(1, 1, n, 1, i, -1);
	}
}
ll ans = 0;
int main() {
	n = read();
	L(i, 1, n) {
		int x = read(), y = read();
		p[x] = y;
	}
	Build();
	L(i, 1, cnt) {
		if(type[i]) ans += (ll) deg[i] * (deg[i] - 1) / 2;
		else ans ++;
	}
	printf("%lld\n", ans);
	return 0;
}