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
const int N = 6005;
const int M = (N << 1);
const int inf = 1e9 + 7;
const ll linf = 1e16;
int n, m, a[N], tot, s, t;
int head[N], edge_id = 1;
struct node {
	int to, next; ll val;
} e[M << 1];
void add_edge(int u, int v, ll val) {
	++edge_id, e[edge_id].val = val, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void add(int u, int v, ll val) {
	// cout << "add : " << u << " " << v << " : " << val << endl;
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
ll dfs(int x, ll flow) {
	if(x == t) return flow;
	if(dis[x] >= dis[t]) return 0;
	ll now = flow;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(!e[i].val || dis[v] != dis[x] + 1) continue;
		int fl = dfs(v, min(now, e[i].val));
		e[i].val -= fl, e[i ^ 1].val += fl, now -= fl;
		if(!now) break;
	}
	return flow - now;
}
ll dinic() {
	ll res = 0;
	while(bfs()) res += dfs(s, linf);
	return res;
}
int main() {
	scanf("%d%d", &n, &m), tot = n + m, s = ++tot, t = ++tot;
	L(i, 1, n) scanf("%d", &a[i]), add(s, i, a[i]);
	ll sum = 0;
	L(i, 1, m) {
		int u, v, val; scanf("%d%d%d", &u, &v, &val), sum += val;
		add(u, i + n, linf), add(v, i + n, linf), add(i + n, t, val);
	}
	printf("%lld\n", sum - dinic());
	return 0;
}