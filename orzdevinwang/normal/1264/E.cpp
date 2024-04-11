#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int P = 105;
const int N = P * P * 2;
const int M = N * 5;
const int inf = 1e9 + 7;
struct cf { int c, f; } ;
int n, m, s, t, G[P][P], tot, d[P][P];
int head[N], edge_id = 1;
struct node {
	int to, val, w, next;
} e[M << 1];
void add_edge(int u, int v, int val, int w) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].val = val, e[edge_id].w = w, e[edge_id].to = v, head[u] = edge_id;
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
				if(!vis[v]) q.push(v);
			}
		}
	}
	return dis[t] < inf;
}
int dinic(int x, int flow) {
	if(x == t) return flow;
	vis[x] = 1;
	int now = flow;
	for(int i = cur[x]; i; i = e[i].next) {
		int v = e[i].to;
		cur[x] = i;
		if(vis[v] || !e[i].val || dis[v] != dis[x] + e[i].w) continue;
		int fl = dinic(v, min(now, e[i].val));
		now -= fl, e[i].val -= fl, e[i ^ 1].val += fl;
		if(!now) break;
	}
	vis[x] = 0;
	return flow - now;
}
cf mcmf() {
	cf res = {};
	while(SPFA()) {
		int now = dinic(s, inf);
		res.c += now * dis[t], res.f += now;
	}
	return res;
}
int main() { 
	scanf("%d%d", &n, &m);
	tot = n, s = ++tot, t = ++tot;
	L(i, 1, n) L(j, 1, n) ++tot, add(i, tot, 1, 0), add(tot, t, 1, j - 1);
	L(i, 1, n) L(j, i + 1, n) G[i][j] = G[j][i] = 2;
	L(i, 1, m) {
		int u, v; scanf("%d%d", &u, &v);
		G[u][v] = 1, G[v][u] = 0, add(s, u, 1, 0);
	}
	L(i, 1, n) L(j, i + 1, n) if(G[i][j] == 2 && i < j) ++tot, add(s, tot, 1, 0), add(tot, i, 1, 0), d[i][j] = edge_id, add(tot, j, 1, 0);
	mcmf();
	L(i, 1, n) L(j, i + 1, n) if(G[i][j] == 2) G[i][j] = e[d[i][j]].val, G[j][i] = (G[i][j] ^ 1);
	L(i, 1, n) L(j, 1, n) printf("%d%s", G[i][j], j == n ? "\n" : "");
	return 0;
}