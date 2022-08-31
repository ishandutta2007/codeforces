#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define db double
using namespace std;
struct cf { int c, f; };
const int N = 3005;
const int M = 2e5;
const int inf = 1e9 + 7;
int n, m, tot, s, t;
int head[N], edge_id = 1;
struct ndoe {
	int to, next, val, w;
} e[M << 1];
void add_edge(int u, int v, int val, int w) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].w = w, e[edge_id].to = v, e[edge_id].val = val, head[u] = edge_id;
}
void add(int u, int v, int val, int w) {
	add_edge(u, v, val, w), add_edge(v, u, 0, -w);
}
int dis[N], cur[N]; bool vis[N];
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
			if(e[i].val && dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w;
				if(!vis[v]) q.push(v), vis[v] = 1;
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
		if(!e[i].val || dis[v] != dis[x] + e[i].w || vis[v]) continue;
		int fl = dfs(v, min(now, e[i].val));
		now -= fl, e[i].val -= fl, e[i ^ 1].val += fl;
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
int L[N], R[N];
int main() {
	scanf("%d%d", &n, &m), tot = n, s = ++tot, t = ++tot;
	L(i, 1, n) L(j, 1, n) ++tot, add(tot, i, 1, 2 * j - 1), add(s, tot, 1, 0);
	L(i, 1, n) L[i] = 1, R[i] = n;
	L(i, 1, m) {
		int l, r, opt, x;
		scanf("%d%d%d%d", &opt, &l, &r, &x);
		if(opt == 1) L(j, l, r) L[j] = max(L[j], x);
		if(opt == 2) L(j, l, r) R[j] = min(R[j], x);
	}
	L(i, 1, n) {
		if(L[i] > R[i]) return puts("-1"), 0;
		++tot;
		add(tot, t, 1, 0);
		L(j, L[i], R[i]) add(j, tot, 1, 0);
	}
	printf("%d\n", dinic().c);
	return 0;
}