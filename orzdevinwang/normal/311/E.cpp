#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define y second
#define x first
using namespace std;
const int N = 2e4 + 7;
const int M = (N << 3);
const int inf = 1e9 + 7;
int n, m, g, a[N], v[N], tot, s, t;
int head[N], edge_id = 1;
struct node {
	int to, next, val;
} e[M << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].val = val, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void add(int u, int v, int val) {
	add_edge(u, v, val), add_edge(v, u, 0);
}
int dis[N];
bool bfs() {
	fill(dis + 1, dis + tot + 1, inf);
	queue<int> q;
	q.push(s), dis[s] = 0;
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
	if(dis[x] >= dis[t]) return 0;
	int now = flow;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(!e[i].val || dis[v] != dis[x] + 1) continue;
		int fl = dfs(v, min(now, e[i].val));
		e[i].val -= fl, e[i ^ 1].val += fl, now -= fl;
		if(!now) break;
	}
	return flow - now;
}
int dinic() {
	int res = 0;
	while(bfs()) res += dfs(s, inf);
	return res;
}
int main() {
	scanf("%d%d%d", &n, &m, &g), tot = n + m, s = ++tot, t = ++tot;
	L(i, 1, n) scanf("%d", &a[i]);
	L(i, 1, n) scanf("%d", &v[i]);
	L(i, 1, n) if(a[i] == 0) add(s, i, v[i]); else add(i, t, v[i]);
	int sum = 0;
	L(i, 1, m) {
		int flag, w, k, mm, tp; scanf("%d%d%d", &flag, &w, &k);
		sum += w;
		while(k--) {
			scanf("%d", &tp);
			if(flag == 0) add(i + n, tp, inf);
			else add(tp, i + n, inf);
		}
		scanf("%d", &mm);
		if(mm == 1) w += g;
		if(flag == 0) add(s, i + n, w);
		else add(i + n, t, w);
	}
	printf("%d\n", sum - dinic());
	return 0;
}