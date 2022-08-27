#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m, hv[N], mxdep[N];
int *f[N], tmp[N << 1], *id = tmp, ans[N];
int head[N], edge_id;
struct node {
	int to, next; 
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], head[u] = edge_id;
}
void dfs1(int x, int fa) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		dfs1(v, x);
		if(mxdep[v] + 1 > mxdep[x]) mxdep[x] = mxdep[v] + 1, hv[x] = v;		
	}
}
void dfs2(int x, int fa) {
	f[x][0] = 1;
	if(hv[x]) f[hv[x]] = f[x] + 1, dfs2(hv[x], x), ans[x] = ans[hv[x]] + 1, (f[x][ans[x]] == 1) && (ans[x] = 0);
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa || v == hv[x]) continue;
		f[v] = id, id += mxdep[v] + 1, dfs2(v, x);
		L(j, 0, mxdep[v]) {
			f[x][j + 1] += f[v][j];
			if(f[x][j + 1] > f[x][ans[x]] || (f[x][j + 1] == f[x][ans[x]] && j + 1 < ans[x])) ans[x] = j + 1;
		}
	}
}
int main() {
	scanf("%d", &n);
	L(i, 1, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		add_edge(u, v), add_edge(v, u);
	}
	dfs1(1, 0);
	f[1] = id, id += mxdep[1] + 1;
	dfs2(1, 0);
	L(i, 1, n) printf("%d\n", ans[i]);
	return 0;
}