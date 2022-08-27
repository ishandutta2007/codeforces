#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int T, n, a, b, da, db, fa[N], jp[20][N], dep[N], maxa[N], maxb[N], maxn;
int edge_id, head[N];
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	edge_id++, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void dfs(int x) {
	maxa[x] = maxb[x] = 0;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa[x]) continue;
		fa[v] = jp[0][v] = x, dep[v] = dep[x] + 1, dfs(v);
		if(maxa[v] + 1 > maxa[x]) maxb[x] = maxa[x], maxa[x] = maxa[v] + 1;
		else maxb[x] = max(maxb[x], maxa[v] + 1);
	}
	maxn = max(maxn, maxa[x] + maxb[x]);
}
void build() {
	for(int i = 1; i <= 18; i++) 
		for(int j = 1; j <= n; j++) 
			jp[i][j] = jp[i - 1][jp[i - 1][j]];
}
int get(int u, int v) {
	int sum = 0;
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 18; i >= 0; i--) if(dep[u] - dep[v] >= (1 << i)) u = jp[i][u], sum += (1 << i);
	if(u == v) return sum;
	for(int i = 18; i >= 0; i--) if(jp[i][u] != jp[i][v]) u = jp[i][u], v = jp[i][v], sum += (1 << (i + 1));
	return sum + 2;
}
int main() {
	scanf("%d", &T);
	while(T--) {
		maxn = 0;
		scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
		for(int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v), add_edge(v, u);
		}
		dep[1] = 1, dfs(1), build();
		if(get(a, b) <= da || da * 2 >= db || da * 2 >= maxn) printf("Alice\n");
		else printf("Bob\n");
		for(int i = 1; i <= n; i++) fa[i] = head[i] = 0;
		for(int i = 1; i <= edge_id; i++) e[i].to = e[i].next = 0;
		edge_id = 0;
	}
	return 0;
}