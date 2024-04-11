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
const int N = 55;
const int M = N * N * 2;
const int inf = 1e9;
struct cf { int c, f; };
int n, m, k, c, d, s, t, pre[N];
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
	fill(dis + 1, dis + n + 1, inf);
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
int main() {
	scanf("%d%d", &n, &k), s = 1, t = n;
	L(i, 1, n) L(j, 1, n) {
		int tp; scanf("%d", &tp);
		if(tp) add(i, j, tp, 0);
	}
	cf res = mcmf();
	while(1) {
		for(int i = 2; i <= edge_id; i += 2) if(e[i].val == 0) e[i].val = 1, e[i].w = 1;
		if(!SPFA()) break;
		int flow = inf;
		for(int x = t; x != s; x = e[pre[x] ^ 1].to) flow = min(flow, e[pre[x]].val);
		for(int x = t; x != s; x = e[pre[x] ^ 1].to) e[pre[x]].val -= flow, e[pre[x] ^ 1].val += flow;
		if(flow * dis[t] + res.c > k) {
			int ks = (k - res.c) / dis[t]; 
			res.c += ks * dis[t], res.f += ks;
			break;
		}
		res.c += flow * dis[t], res.f += flow;
	}
	printf("%d\n", res.f);
	return 0;
}