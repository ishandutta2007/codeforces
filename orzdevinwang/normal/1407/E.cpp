#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, dp[N], ans[N];
struct node {
	int to, next, val;
} e[N << 1];
int head[N], edge_id;
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], e[edge_id].val = val, head[u] = edge_id;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v, col;
		scanf("%d%d%d", &u, &v, &col);
		add_edge(v, u, col);
	}
	memset(ans, -1, sizeof(ans));
	memset(dp, -1, sizeof(dp));
	queue<int> q;
	q.push(n), dp[n] = 0; 
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(dp[v] != -1) continue;
			if(ans[v] == -1 || ans[v] == (1 ^ e[i].val)) ans[v] = (1 ^ e[i].val);
			else dp[v] = dp[u] + 1, q.push(v);
		}
	}
	printf("%d\n", dp[1]);
	for(int i = 1; i <= n; i++) printf("%d", ans[i] == -1 ? 0 : ans[i]);
	puts("");
	return 0;
}