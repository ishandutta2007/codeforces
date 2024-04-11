#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 405;
const int M = (N << 2);
const int inf = 1e6;
struct cf { int c, f; } ;
int na, nb, m, s, t, deg[N], r, b, tot, bha[N], bhb[N];
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
		int v = e[i].to;
		cur[x] = i;
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
	while(SPFA()) {
		if(dis[t] >= 0) break;
		int flow = dfs(s, inf);
		res.c += flow * dis[t], res.f += flow;
	}
	return res;
}
char aa[N], bb[N];
int main() { 
	scanf("%d%d%d%d%d", &na, &nb, &m, &r, &b);
	tot = na + nb, s = ++tot, t = ++tot;
	scanf("%s%s", aa + 1, bb + 1);
	int cnt = 0;
	L(i, 1, na) {
		if(aa[i] == 'R') add(s, i, 1, -inf), add(s, i, inf, 0), ++cnt; 
		else if(aa[i] == 'B') add(i, t, 1, -inf), add(i, t, inf, 0), ++cnt;
		else add(s, i, inf, 0), add(i, t, inf, 0);
	}
	L(i, 1, nb) {
		if(bb[i] == 'B') add(s, i + na, 1, -inf), add(s, i + na, inf, 0), ++cnt; 
		else if(bb[i] == 'R') add(i + na, t, 1, -inf), add(i + na, t, inf, 0), ++cnt;	
		else add(s, i + na, inf, 0), add(i + na, t, inf, 0);
	}
	L(i, 1, m) {
		int u, v; scanf("%d%d", &u, &v), v += na;
		add(u, v, 1, r), bha[i] = edge_id, add(v, u, 1, b), bhb[i] = edge_id;
	}
	int res = dinic().c + cnt * inf;
	if(res > inf) return printf("-1\n"), 0;
	printf("%d\n", res);
	L(i, 1, m) {
		if(e[bha[i]].val) printf("R");
		else if(e[bhb[i]].val) printf("B");
		else printf("U");
	}
	puts("");
	return 0;
}