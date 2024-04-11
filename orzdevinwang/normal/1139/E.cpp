#include<bits/stdc++.h>
#define N 5010
using namespace std;
int n, m, d, p[N], c[N], k[N], pp[N], Ans[N], ans = 1;
bool used[N], vis[N];
int edge_id, head[N];
struct node {
	int to, next;
} e[N];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
bool dfs(int x) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(vis[v]) continue;
		vis[v] = 1;
		if(!pp[v] || dfs(pp[v])) return pp[v] = x, 1;
	}
	return 0;
}
bool could(int x) {
	memset(vis, 0, sizeof(vis));
	return dfs(x);
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &p[i]), ++p[i];
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	scanf("%d", &d);
	for(int i = 1; i <= d; i++) scanf("%d", &k[i]), used[k[i]] = true;
	reverse(k + 1, k + d + 1);
	for(int i = 1; i <= n; i++) if(!used[i]) add_edge(p[i], c[i]);
	for(int i = 1; i <= d; i++) {
		while(could(ans)) ++ans;
		Ans[i] = ans;
		add_edge(p[k[i]], c[k[i]]);
	}
	reverse(Ans + 1, Ans + d + 1);
	for(int i = 1; i <= d; i++) printf("%d\n", Ans[i] - 1);
	return 0;
}

// 8 1
// 1 6 3 4 2 0 5 9
// 8 4 2 4 6 4 1 8
// 1
// 8