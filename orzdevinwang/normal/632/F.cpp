#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2507;
const int M = N * N;
int n, m, f[N][N], fa[N], tot;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
struct node {
	int fr, to, val;
} ee[M];
bool cmp(node aa, node bb) {
	return aa.val < bb.val;
}
int head[N], edge_id;
struct edge {
	int to, next, val;
} e[N << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].to = v, e[edge_id].val = val, e[edge_id].next = head[u], head[u] = edge_id;
}
int dep[N], jp[15][N], jpval[15][N];
void DFS(int x, int fa) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		jp[0][v] = x, jpval[0][v] = e[i].val;
		dep[v] = dep[x] + 1, DFS(v, x);
	}
} 
int get(int x, int y) {
	int Ans = 0;
	if(dep[x] < dep[y]) swap(x, y);
	R(i, 13, 0) if(dep[x] - dep[y] >= (1 << i)) Ans = max(Ans, jpval[i][x]), x = jp[i][x];
	if(x == y) return Ans;
	R(i, 13, 0) if(jp[i][x] != jp[i][y]) Ans = max(Ans, max(jpval[i][x], jpval[i][y])), x = jp[i][x], y = jp[i][y];
	return max(Ans, max(jpval[0][x], jpval[0][y]));
}
int main() {
	scanf("%d", &n);
	L(i, 1, n) fa[i] = i;
	L(i, 1, n) L(j, 1, n) scanf("%d", &f[i][j]);
	L(i, 1, n) if(f[i][i]) return puts("NOT MAGIC"), 0;
	L(i, 1, n) L(j, i + 1, n) if(f[i][j] != f[j][i]) return puts("NOT MAGIC"), 0;
	// cout << "UAKWOBAOLING\n";
	L(i, 1, n) L(j, i + 1, n) ++tot, ee[tot].fr = i, ee[tot].to = j, ee[tot].val = f[i][j];
	sort(ee + 1, ee + tot + 1, cmp);
	// cout<< "George1123AKIOI\n";
	L(i, 1, tot) {
		int u = ee[i].fr, v = ee[i].to;
		if(find(u) != find(v)) /* cout << u << " " << v << " " << ee[i].val << endl,  */
			add_edge(u, v, ee[i].val), add_edge(v, u, ee[i].val), fa[find(u)] = find(v);
	}
	DFS(1, -1);
	L(i, 1, 13) L(j, 1, n) jp[i][j] = jp[i - 1][jp[i - 1][j]], jpval[i][j] = max(jpval[i - 1][j], jpval[i - 1][jp[i - 1][j]]);
	// cout << "qwq\n";
	L(i, 1, n) L(j, i + 1, n) if(f[i][j] > get(i, j)) 
		return /* cout << i << " " << j << " : " << get(i, j) << endl,  */puts("NOT MAGIC"), 0;
	L(i, 1, n) L(j, i + 1, n) if(f[i][j] < get(i, j)) assert(0);
	puts("MAGIC");
	return 0;
}