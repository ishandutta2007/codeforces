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
struct cf { int c, f; };
const int N = 307;
const int M = N * 60;
const int inf = 1e9 + 7;
int n, m, s, t, tot, deg[N];
int head[N], edge_id = 1;
struct node {
	int to, val, w, next;
} e[M << 1];
void add_edge(int u, int v, int val, int w) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, e[edge_id].val = val, e[edge_id].w = w, head[u] = edge_id;
}
void add(int u, int v, int val, int w) {
	add_edge(u, v, val, w), add_edge(v, u, 0, -w);
}
int dis[N], cur[N]; bool vis[N];
bool bfs() {
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
	int now = flow;
	vis[x] = 1;
	for(int i = cur[x]; i; i = e[i].next) {
		cur[x] = i;
		int v = e[i].to;
		if(vis[v] || !e[i].val || dis[v] != dis[x] + e[i].w) continue;
		int fl = dfs(v, min(now, e[i].val));
		now -= fl, e[i].val -= fl, e[i ^ 1].val += fl;
		if(!now) break;
	}
	vis[x] = 0;
	return flow - now;
}
cf dinic() {
	cf res = {};
	while(bfs()) {
		int flow = dfs(s, inf);
		res.f += flow, res.c += flow * dis[t];
	}
	return res;
}
int main() {
	int ans = 0;
	scanf("%d%d", &n, &m), tot = n, s = ++tot, t = ++tot;
	L(i, 1, m) {
		int u, v, vala, valb; scanf("%d%d%d%d", &u, &v, &vala, &valb);
		if(valb <= vala) {
			deg[u] += valb, deg[v] -= valb;
			add(u, v, vala - valb, 1), add(u, v, inf - vala, 2), add(v, u, valb, 1);
		}
		else {
			deg[u] += vala, deg[v] -= vala, ans += valb - vala;
			add(u, v, valb - vala, 0), add(u, v, inf - valb, 2), add(v, u, vala, 1);
		}
	}
	L(i, 1, n) {
		if(deg[i] > 0) add(i, t, deg[i], 0);
		if(deg[i] < 0) add(s, i, -deg[i], 0);
	}
	add(n, 1, inf, 0);
	printf("%d\n", dinic().c + ans);
	return 0;
}