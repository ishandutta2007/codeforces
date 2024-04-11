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
const int N = 505;
const int M = 1505;
const int inf = 1e9 + 7;
int ans;
int n, m;
int edge_id = 1, head[N], reset[M << 1];
struct node {
	int to, val, next;
} e[M << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, reset[edge_id] = e[edge_id].val = val, head[u] = edge_id;
}
int hd[N], edgeid = 1;
struct edge {
	int to, next, val;
} G[N << 1];
void Eadd(int u, int v, int val) {
	++edgeid, G[edgeid].next = hd[u], G[edgeid].to = v, G[edgeid].val = val, hd[u] = edgeid;
}
int res, rid;
void findmax(int x, int fa) {
	for(int i = hd[x]; i; i = G[i].next) {
		if(G[i].val == -1) continue;
		int v = G[i].to;
		if(v == fa) continue;
		if(G[i].val < res) res = G[i].val, rid = i;
		findmax(v, x);
	}
}
void DFS(int x) {
	res = inf, findmax(x, -1);
	if(res == inf) return printf("%d ", x), void();
	int pp = rid;
	G[rid].val = G[rid ^ 1].val = -1;
	DFS(G[pp].to), DFS(G[pp ^ 1].to);
}
int dis[N];
bool bfs(int s, int t) {
	fill(dis + 1, dis + n + 1, inf);
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
int dfs(int x, int t, int flow) {
	if(x == t) return flow;
	if(dis[x] >= dis[t]) return 0;
	int now = flow;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(!e[i].val || dis[v] != dis[x] + 1) continue;
		int fl = dfs(v, t, min(now, e[i].val));
		now -= fl, e[i].val -= fl, e[i ^ 1].val += fl;
		if(!now) break;
	}
	if(flow == now) dis[x] = inf;
	return flow - now;
}
int a[N];
bool cmp(int aa, int bb) { return dis[aa] < dis[bb]; }
void solve(int l, int r) {
	if(l == r) return;
	int res = 0;
	while(bfs(a[l], a[r])) res += dfs(a[l], a[r], inf);//, cout << res << " ";
//	cout << a[l] << " " << a[r] << " " << res << endl;
	Eadd(a[l], a[r], res), Eadd(a[r], a[l], res), ans += res;
	sort(a + l, a + r + 1, cmp);
	int cut;
	L(i, l, r) if(dis[a[i]] >= inf) {
		cut = i; 
		break;
	} 
	L(i, 2, edge_id) e[i].val = reset[i];
	solve(l, cut - 1), solve(cut, r);
}
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, m) {
		int u, v, val; scanf("%d%d%d", &u, &v, &val);
		add_edge(u, v, val), add_edge(v, u, val);
	}
	L(i, 1, n) a[i] = i;
	solve(1, n);
	printf("%d\n", ans);
	DFS(1);
	return 0;
}