#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define db double
using namespace std;
const int N = 9999;
const int M = 99999;
const int inf = 1e9 + 7;
struct cf { int c, f; };
int tot, s, t;
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
				if(!vis[v]) vis[v] = 1, q.push(v); 
			}
		}
	}
	return dis[t] < inf;
}
int dfs(int x, int flow) {
	if(x == t) return flow;
	vis[x] = 1;
	int now = flow;
	for(int i = cur[x]; i; i = e[i].next) {
		int v = e[i].to;
		cur[x] = i;
		if(vis[v] || dis[v] != dis[x] + e[i].w || !e[i].val) continue;
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
		int flow = dfs(s, inf);
		res.c += flow * dis[t], res.f += flow;
	}
	return res;
}
int n, a[N], b[N];
struct Node { int a, b, id; ll p; } f[N];
bool cmp(Node aa, Node bb) { return aa.b == bb.b ? aa.a > bb.a : aa.b < bb.b; }
bool cmpid(Node aa, Node bb) { return aa.id < bb.id; }
bool cmpp(Node aa, Node bb) { return aa.p < bb.p; }
ll p[N], q[N];
bool check(int x) {
	L(i, 1, n) p[i] = 1ll * a[i + n] * x + b[i + n];
	sort(p + 1, p + n + 1);
	ll now = 0; int cnt = 0;
	L(i, 1, 2 * n) {
		now = max(now, 1ll * f[i].a * x + f[i].b);
		if(f[i].id <= n) {
			cnt ++;
			if(now < p[cnt]) return 0;
		}
	}
	return 1;
}
int main() {
	scanf("%d", &n);
	L(i, 1, 2 * n) scanf("%d%d", &a[i], &b[i]), f[i].a = a[i], f[i].b = b[i], f[i].id = i;
	sort(f + 1, f + 2 * n + 1, cmp);
	int l = 0, r = inf, ans = inf + 1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	if(ans > inf) puts("-1");
	else {
		tot = n * 4, s = ++tot, t = ++tot;
		ll now = 0;
		L(i, 1, 2 * n) now = max(now, 1ll * f[i].a * ans + f[i].b), q[f[i].id] = now;
		sort(f + 1, f + n * 2 + 1, cmpid);
		L(i, 1, n * 2) p[i] = f[i].p = 1ll * a[i] * ans + b[i];
		L(i, 1, n) add(s, i, 1, 0), add(i + n, t, 1, 0);

		sort(f + n + 1, f + n * 2 + 1, cmp);
		L(i, n + 1, n * 2) add(i + n, i, 1, 0);
		L(i, n + 2, n * 2) add(f[i].id + n, f[i - 1].id + n, i - n, 0); // n * 2 + 1 ~ n + 3
		L(i, 1, n) R(j, 2 * n, n + 1) if(b[i] >= f[j].b) { add(i, f[j].id + n, 1, 1); break; } 

		sort(f + n + 1, f + 2 * n + 1, cmpp);
		L(i, n + 1, n * 2) add(i + n * 2, i, 1, 0);
		L(i, n + 2, n * 2) add(f[i].id + n * 2, f[i - 1].id + n * 2, i - n, 0); // n * 3 + 1  n * 4
		L(i, 1, n) R(j, 2 * n, n + 1) if(p[i] >= f[j].p) { add(i, f[j].id + n * 2, 1, 1); break; } 
		L(i, 1, n) R(j, 2 * n, n + 1) if(q[i] >= f[j].p) { add(i, f[j].id + n * 2, 1, 2); break; } 
		// L(i, 1, n) L(j, n + 1, 2 * n) {
		// 	if(p[i] >= p[j] || b[i] >= b[j]) add(i, j, 1, 1);
		// 	else if(q[i] >= p[j]) add(i, j, 1, 2);
		// }
		printf("%d %d\n", ans, dinic().c);
	}
	return 0;
}