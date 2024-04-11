#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2607;
const int M = N * 2;
const int inf = 1e9 + 7;
struct cf { int c, f; };
int tot, s, t;
int head[N], edge_id = 1;
struct node {
	int val, w, to, next;
} e[M << 1];
void add_edge(int u, int v, int val, int w) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, e[edge_id].val = val, e[edge_id].w = w, head[u] = edge_id;
}
void add(int u, int v, int val, int w) {
	add_edge(u, v, val, w), add_edge(v, u, 0, -w);
}
int cur[N], dis[N]; bool vis[N];
bool SPFA() {
	fill(dis + 1, dis + tot + 1, inf);
	copy(head + 1, head + tot + 1, cur + 1);
	queue<int> q; q.push(s), dis[s] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].w && e[i].val) {
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
		res.f += flow, res.c += flow * dis[t];
	}
	return res;
}
int n, b[N];
#define P(i, j) ((i) * 26 + (j) + 1 + (n / 2))
char ss[N];
int main() {
	scanf("%d", &n), tot = (n / 2 + 1) * 26 + n / 2, s = ++tot, t = ++tot;
	scanf("%s", ss + 1);
	L(i, 1, n) add(s, P(0, ss[i] - 'a'), 1, 0);
	L(i, 1, n) scanf("%d", &b[i]);
	L(i, 1, n / 2) {
		L(j, 0, 25) {
			add(P(i, j), i, 1, 0);
			if(j == ss[i] - 'a') add(P(0, j), P(i, j), 1, -b[i]);
			if(j == ss[n - i + 1] - 'a') add(P(0, j), P(i, j), 1, -b[n - i + 1]);
			if(j != ss[i] - 'a' && j != ss[n - i + 1] - 'a') add(P(0, j), P(i, j), 1, 0); 
		}
		add(i, t, 2, 0);
	}
	printf("%d\n", -dinic().c);
	return 0;
}