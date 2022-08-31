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
const int N = 1e4 + 7;
const int inf = 1e9;
int n, m, s, t, f[N], tot;
int head[N], edge_id = 1;
struct node { 
	int to, val, next;
} e[N << 1];
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
			if(e[i].val && dis[v] >= inf) q.push(v), dis[v] = dis[u] + 1;
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
		int fl = dfs(v, min(e[i].val, now));
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
int E[N][2];
int work(int x) {
	L(i, 1, 2 * n + 2) head[i] = 0;
	edge_id = 1, tot = n * 2;
	int cnt = 0;
	s = ++tot, t = ++tot;
	L(i, 1, n) add(s, i * 2 - 1, 1), add(i * 2, t, 1);
	L(i, 1, m) {
		if(E[i][0] == x || E[i][1] == x) cnt++;
		else add(E[i][0] * 2 - 1, E[i][1] * 2, 1);
	}
	int res = dinic();
	return (n * 2 - 1 - cnt) + (n - 1 - res) + (m - res - cnt);
}
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, m) scanf("%d%d", &E[i][0], &E[i][1]);
	int Ans = inf;
	L(i, 1, n) Ans = min(Ans, work(i));
	printf("%d\n", Ans);
	return 0;
}