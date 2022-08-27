// You AK, wo bao ling. wo men de qian tu ... dou guang ming ! 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define uint unsigned int
using namespace std;
const int N = 1e5 + 7;
int n, m, Q, head[N], edge_id;
ll dis[N];
struct node {
	int to, next, val;
} e[N];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].val = val, e[edge_id].to = v, head[u] = edge_id;
} 
bool vis[N];
void dijkstra() {
	fill(dis + 1, dis + n + 1, 1e16);
	priority_queue<pair<ll, int>> q;
	dis[1] = 0, q.push(mkp(0, 1));
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].val) {
				dis[v] = dis[u] + e[i].val;
				q.push(mkp(-dis[v], v));
			}
		}
	}
}
queue<int> q[N];
int d[N];
void bfs(int maxn) {
	L(i, 0, maxn) while(!q[i].empty()) {
		int u = q[i].front();
		q[i].pop();
		if(d[u] < i) continue;
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to; ll qwq = dis[u] + e[i].val + d[u] - dis[v];
			if(qwq > maxn) continue;
			if(d[v] > qwq) d[v] = qwq, q[qwq].push(v);
			// dis[v] = min(dis[u] + e[i].val + d[i] - dis[v])
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &Q);
	L(i, 1, m) {
		int u, v, val; scanf("%d%d%d", &u, &v, &val);
		add_edge(u, v, val);
	}
	dijkstra();
	while(Q--) {
		int opt, x; scanf("%d%d", &opt, &x);
		if(opt == 1) {
			if(dis[x] > 1e15) printf("-1\n");
			else printf("%lld\n", dis[x]);
			continue;
		}
		L(i, 1, x) {
			int t; scanf("%d", &t);
			e[t].val ++;
		}
		fill(d + 1, d + n + 1, 1e9);
		q[0].push(1), d[1] = 0;
		bfs(x);
		L(i, 1, n) dis[i] += d[i];
	}
	return 0;
}