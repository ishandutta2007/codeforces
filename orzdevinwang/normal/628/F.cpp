#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int M = 5e5 + 7;
const int inf = 1e9;
int tot, s, t;
int head[N], edge_id = 1;
struct node {
	int to, next, val;
} e[M << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].to = v, e[edge_id].val = val, e[edge_id].next = head[u], head[u] = edge_id;
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
		cur[x] = i;
		int v = e[i].to;
		if(!e[i].val || dis[v] != dis[x] + 1) continue;
		int fl = dfs(v, min(now, e[i].val));
		now -= fl, e[i].val -= fl, e[i ^ 1].val += fl;
		if(!now) break;
	}
	return flow - now;
}
int dinic() {
	int res = 0;
	while(bfs()) res += dfs(s, inf);
	return res;
}
int n, m, q;
struct sot { int u, t; } f[N];
bool cmp(sot aa, sot bb) { return aa.u < bb.u; }
int main() {
	scanf("%d%d%d", &n, &m, &q), tot = m, s = ++tot, t = ++tot;
	L(i, 1, q) scanf("%d%d", &f[i].u, &f[i].t);
	f[q + 1].u = m, f[q + 1].t = n;
	sort(f + 1, f + q + 1, cmp);
	L(i, 1, q + 1) {
		++tot, add(s, tot, f[i].t - f[i - 1].t);
		if(f[i].t < f[i - 1].t) return puts("unfair"), 0;
		L(o, f[i - 1].u + 1, f[i].u) add(tot, o, 1);
	}
	L(i, 1, m) add(i, i % 5 + tot + 1, 1);
	L(i, 1, 5) ++tot, add(tot, t, n / 5);
	if(dinic() == n) printf("fair\n");
	else printf("unfair\n");
	return 0;
}