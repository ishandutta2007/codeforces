// sto George1123 orz
// George1123's  : https://www.cnblogs.com/George1123/p/12813027.html /qq /qq /qq
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e3 + 7;
const int M = 1e6 + 7;
const int inf = 1e9 + 7;
int tot, s, t;
int head[N], edge_id = 1; 
struct node {
	int to, val, next;
} e[M << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, e[edge_id].val = val, head[u] = edge_id;
}
void add(int u, int v, int val) {
	add_edge(u, v, val), add_edge(v, u, 0); 
}
int dis[N], cur[N]; 
bool bfs() {
	fill(dis + 1, dis + tot + 1, inf);
	copy(head + 1, head + tot + 1, cur + 1);
	queue<int> q; q.push(s), dis[s] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(e[i].val && dis[v] >= inf) dis[v] = dis[u] + 1, q.push(v);
		}
	}
	return dis[t] < inf;
}
int dfs(int x, int flow) {
	if(x == t) return flow;
	int now = flow;
	for(int i = cur[x]; i; i = e[i].next) {
		int v = e[i].to;
		cur[x] = i;
		if(!e[i].val || dis[v] != dis[x] + 1) continue;
		int fl = dfs(v, min(now, e[i].val));
		now -= fl, e[i].val -= fl, e[i ^ 1].val += fl;
		if(!now) break;
	}
	return flow - now;
}
ll dinic() {
	ll res = 0;
	while(bfs()) res += dfs(s, inf);
	return res;
} 
int n;
int main() {
	scanf("%d", &n), tot = n * 2, s = ++tot, t = ++tot; 
	const int mx = 4e8; // 
	ll sum = 0;
	L(i, 1, n) add(i + n, t, mx);
	L(g, 1, n) {
		int k; scanf("%d", &k);
		while(k--) {
			int x; scanf("%d", &x);
			add(g, x + n, inf);
		}
	} 
	int val; L(i, 1, n) scanf("%d", &val), add(s, i, mx - val), sum += mx - val; // V = mx - val
	sum -= dinic();
	printf("%lld\n", -sum);
	return 0;
}