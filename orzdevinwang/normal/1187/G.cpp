#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define se second
#define fi first
using namespace std;
const int N = 5005;
const int M = 4 * N * sqrt(N);
const int inf = 1e9;
struct cf { int c, f; };
int n, m, k, c, d, s, t, tot, pre[N];
int head[N], edge_id = 1;
struct node {
	int to, next, val, w;
} e[M << 1];
void add_edge(int u, int v, int val, int w) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].w = w, e[edge_id].to = v, e[edge_id].val = val, head[u] = edge_id;
}
void add(int u, int v, int val, int w) {
	add_edge(u, v, val, w), add_edge(v, u, 0, -w);
}
int dis[N]; bool vis[N];
bool SPFA() {
	fill(dis + 1, dis + tot + 1, inf);
	queue<int> q;
	q.push(s), dis[s] = 0;
	while(!q.empty()) {
		int u = q.front();
		vis[u] = 0;
		q.pop();
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(e[i].val && dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w, pre[v] = i;
				if(!vis[v]) vis[v] = 1, q.push(v);
			}
		}
	}
	return dis[t] < inf;
}
cf mcmf() {
	cf res = {};
	while(SPFA()) {
		int flow = inf;
		for(int x = t; x != s; x = e[pre[x] ^ 1].to) flow = min(flow, e[pre[x]].val);
		for(int x = t; x != s; x = e[pre[x] ^ 1].to) e[pre[x]].val -= flow, e[pre[x] ^ 1].val += flow;
		res.f += flow, res.c += dis[t] * flow;
	}
	return res;
}
#define P(i, j) ((i) * n + (j))
int E[N][2];
int main() {
	scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
	int cs = 2 * k; tot = cs * n; 
	s = ++tot, t = ++tot;
	int tp; L(i, 1, k) scanf("%d", &tp), add(s, P(0, tp), 1, 0);
	L(i, 1, m) scanf("%d%d", &E[i][0], &E[i][1]);
	L(i, 1, cs - 1) {
		add(P(i, 1), t, k, c * i);
		L(j, 1, n) add(P(i - 1, j), P(i, j), k, 0);
		L(j, 1, m) L(t, 1, k) 
			add(P(i - 1, E[j][0]), P(i, E[j][1]), 1, (2 * t - 1) * d), 
			add(P(i - 1, E[j][1]), P(i, E[j][0]), 1, (2 * t - 1) * d);
	} 
	printf("%d\n", mcmf().c);
	return 0;
}