#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define db double
using namespace std;
const int N = 55;
const int M = N * N;
const int inf = 1e9 + 7;
struct cf { int c, f; };
int tot, s, t, pre[N];
int head[N], edge_id = 1;
struct node {
	int to, val, w, next;
} e[M << 1];
void add_edge(int u, int v, int val, int w) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].w = w, e[edge_id].val = val, e[edge_id].to = v, head[u] = edge_id;
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
		// cout << u << endl;
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(e[i].val && dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w, pre[v] = i;
				// cout << u << " : " << e[pre[i] ^ 1].to << endl;
				if(!vis[v]) vis[v] = 1, q.push(v); 
			}
		}
	}
	return dis[t] < inf;
}
vector<pii> ve;
cf dinic() {
	cf res = {};
	while(SPFA()) {
		// cout << " qwq\n";
		// cout << dis[t] << endl;
		int flow = inf;
		for(int i = t; i != s; i = e[pre[i] ^ 1].to) flow = min(flow, e[pre[i]].val);
		// cout << flow << endl;
		for(int i = t; i != s; i = e[pre[i] ^ 1].to) e[pre[i]].val -= flow, e[pre[i] ^ 1].val += flow;
		res.c += flow * dis[t], res.f += flow;
		ve.push_back(mkp(res.f, res.c));
	}
	// cout << res.c << endl;
	return res;
}
int n, m;
int main() {
	scanf("%d%d", &n, &m), tot = n;
	s = 1, t = n;
	L(i, 1, m) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		add(u, v, 1, w);
	}
	dinic();
	int q; scanf("%d", &q);
	while(q--) {
		int p; scanf("%d", &p); db ans = inf;
		for(pii x : ve) ans = min(ans, (db)(x.second + p) / x.first);
		printf("%.10lf\n", ans);
	}
	return 0;
}