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
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
int Fa[N], Maxid[N], ans = 1e9;
void dfs(int x) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == Fa[x]) continue;
		Fa[v] = x, Maxid[v] = min(Maxid[x], v), dfs(v);
	}
}
int n, m, lastans;
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n - 1) {
		int u, v; scanf("%d%d", &u, &v);
		add_edge(u, v), add_edge(v, u);
	}
	int opt, x; scanf("%d%d", &opt, &x), x = (x + lastans) % n + 1, --m;
	Maxid[x] = x, dfs(x);
	while(m--) {
		scanf("%d%d", &opt, &x), x = (x + lastans) % n + 1;
		if(opt == 1) ans = min(ans, Maxid[x]);
		if(opt == 2) printf("%d\n", lastans = min(ans, Maxid[x]));
	}
	return 0;
}