#include<bits/stdc++.h>
#define N 200100
using namespace std;
int T, n, fa[N], siz[N], minn, qwq[N], tot;
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1]; 
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void dfs(int x) {
	int amax = 0;
	siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa[x]) continue;
		fa[v] = x, dfs(v), siz[x] += siz[v], amax = max(amax, siz[v]);
	} 
	amax = max(amax, n - siz[x]);
	if(amax < minn) 
		minn = amax, qwq[tot = 1] = x;
	else if(amax == minn) 
		qwq[++tot] = x;
}
int main() {
	scanf("%d", &T);
	while(T--) {
		minn = 1e9;
		scanf("%d", &n);
		for(int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v), add_edge(v, u); 
		}
		dfs(1);
		int sa = qwq[1], sb = qwq[2];
		if(tot == 1) {
			int v = e[head[sa]].to;
			printf("%d %d\n", sa, v);
			printf("%d %d\n", sa, v);
		}
		else {
			int v;
			for(int i = head[sa]; i; i = e[i].next) {
				v = e[i].to;
				if(v != sb) break;
			}
			printf("%d %d\n", sa, v);
			printf("%d %d\n", sb, v);
		}
		for(int i = 1; i <= edge_id; i++) e[i].to = e[i].next = 0;
		for(int i = 1; i <= n; i++) fa[i] = head[i] = 0;
		tot = edge_id = 0;
	}
	return 0;
}