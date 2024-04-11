#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define db double
using namespace std;
const int N = 114 * 2;
const int M = 514 * 2;
const int inf = 1e9 + 7;
struct cf { int c, f; };
int tot, s, t;
int head[N], edge_id = 1;
struct node {
	int to, val, w, next;
} e[M << 1];
void add_edge(int u, int v, int val, int w) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].w = w, e[edge_id].val = val, e[edge_id].to = v, head[u] = edge_id;
}
void add(int u, int v, int val, int w) {
	add_edge(u, v, val, w), add_edge(v, u, 0, -w);
}
int dis[N], cur[N]; bool vis[N];
bool SPFA() {
	fill(dis + 1, dis + tot + 1, inf);
	copy(head + 1, head + tot + 1, cur + 1);
	queue<int> q;
	q.push(s), dis[s] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(e[i].val && dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w;
				if(!vis[v]) vis[v] = 1, q.push(v); 
			}
		}
	}
	return dis[t] < inf;
}
int dfs(int x, int flow) {
	if(x == t) return flow;
	vis[x] = 1;
	int now = flow;
	for(int i = cur[x]; i; i = e[i].next) {
		int v = e[i].to;
		cur[x] = i;
		if(vis[v] || dis[v] != dis[x] + e[i].w || !e[i].val) continue;
		int fl = dfs(v, min(now, e[i].val));
		now -= fl, e[i].val -= fl, e[i ^ 1].val += fl;
		if(!now) break;
	}
	vis[x] = 0;
	return flow - now;
}
cf dinic() {
	cf res = {};
	while(SPFA()) {
		int flow = dfs(s, inf);
		res.c += flow * dis[t], res.f += flow;
	}
	return res;
}
int n, m, pre[N], a[N], v[N];
#define P(i, j) ((i) * 2 + (j) - 1)
int main() {
	scanf("%d%d", &n, &m), tot = 2 * n, s = ++tot, t = ++tot;
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 1, n) scanf("%d", &v[i]);
	L(i, 1, n) {
		add(s, P(i, 0), 1, v[a[i]]);
		add(P(i, 1), t, 1, 0);
		add(P(i, 0), P(i, 1), 1, 0);
		if(i < n) add(P(i, 0), P(i + 1, 0), m - 1, 0);
		if(pre[a[i]]) add(P(i - 1, 0), P(pre[a[i]], 1), 1, -v[a[i]]);
		pre[a[i]] = i;
	}
	printf("%d\n", dinic().c);
	return 0;
}