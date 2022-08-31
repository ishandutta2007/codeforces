#include<bits/stdc++.h>
#define N 500010
using namespace std;
int n, m, a[N], cn[N], ans;
int head[N], edge_id;
struct node {
	int to, next;
} e[N];
bool vis[N];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
vector<int> q;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
	}
	q.push_back(a[n]);
	for(int i = n - 1; i >= 1; i--) {
		for(int j = head[a[i]]; j; j = e[j].next) vis[e[j].to] = 1;
		bool flag = 1;
		for(auto x : q) 
			if(!vis[x]) {
				flag = 0;
				break;
			}
		for(int j = head[a[i]]; j; j = e[j].next) vis[e[j].to] = 0;
		ans += flag, cn[i] = flag;
		if(!flag) q.push_back(a[i]);
	}
	printf("%d\n", ans);
	return 0;
}