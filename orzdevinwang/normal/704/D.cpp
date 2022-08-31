// sto George1123 orz
// George1123's  : https://www.cnblogs.com/George1123/p/12813027.html /qq /qq /qq
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 3e5 + 7;
const int M = 5e5 + 7;
const int inf = 1e9;
int n, m, r, b, tot, deg[N], E[N];
int head[N], edge_id = 1;
struct node {
	int to, next, val;
} e[M << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, e[edge_id].val = val, head[u] = edge_id;
}
void add(int u, int v, int val) {
	add_edge(u, v, val), add_edge(v, u, 0);
}
int dis[N], cur[N];
int bfs(int s, int t) {
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
int dfs(int x, int t, int flow) {
	if(x == t) return flow;
	int now = flow;
	for(int i = cur[x]; i; i = e[i].next) {
		cur[x] = i;
		int v = e[i].to;
		if(!e[i].val || dis[v] != dis[x] + 1) continue;
		int fl = dfs(v, t, min(now, e[i].val));
		now -= fl, e[i].val -= fl, e[i ^ 1].val += fl;
		if(!now) break;
	}
	return flow - now;
}
int dinic(int s, int t) {
	int res = 0;
	while(bfs(s, t)) res += dfs(s, t, inf);
	return res;
}
int arra[N], arrb[N], tota, totb, x[N], y[N], szx[N], szy[N], px[N], py[N];
int s, t, S, T; bool flag;
int main() {
	scanf("%d%d%d%d", &n, &m, &r, &b);
	L(i, 1, n) scanf("%d%d", &x[i], &y[i]), arra[++tota] = x[i], arrb[++totb] = y[i];
	sort(arra + 1, arra + tota + 1);
	tota = unique(arra + 1, arra + tota + 1) - arra - 1;
	sort(arrb + 1, arrb + totb + 1);
	totb = unique(arrb + 1, arrb + totb + 1) - arrb - 1;
	tot = tota + totb;
	s = ++tot, t = ++tot, S = ++tot, T = ++tot;
	L(i, 1, n) {
		x[i] = lower_bound(arra + 1, arra + tota + 1, x[i]) - arra;
		y[i] = lower_bound(arrb + 1, arrb + totb + 1, y[i]) - arrb;
		szx[x[i]] ++, szy[y[i]] ++;
	}
	L(i, 1, tota) px[i] = szx[i];
	L(i, 1, totb) py[i] = szy[i];
	L(i, 1, m) {
		int t, l, d; scanf("%d%d%d", &t, &l, &d);
		if(t == 1) {
			int pp = lower_bound(arra + 1, arra + tota + 1, l) - arra;
			if(arra[pp] != l) continue;
			px[pp] = min(px[pp], d);
		}
		else {
			int pp = lower_bound(arrb + 1, arrb + totb + 1, l) - arrb;
			if(arrb[pp] != l) continue;
			py[pp] = min(py[pp], d);
		}
	}
	if(r < b) swap(r, b), flag = 1;
	L(i, 1, tota) {
		int L = (szx[i] - px[i] + 1) / 2, R = (szx[i] + px[i]) / 2;
		if(L > R) return puts("-1"), 0;
		add(s, i, R - L), deg[s] += L, deg[i] -= L;
	} 
	L(i, 1, totb) {
		int L = (szy[i] - py[i] + 1) / 2, R = (szy[i] + py[i]) / 2;
		if(L > R) return puts("-1"), 0;
		add(i + tota, t, R - L), deg[i + tota] += L, deg[t] -= L;
	} 
	L(i, 1, n) add(x[i], y[i] + tota, 1), E[i] = edge_id;
	int sum = 0;
	L(i, 1, t) {
		if(deg[i] > 0) add(i, T, deg[i]), sum += deg[i];
		if(deg[i] < 0) add(S, i, -deg[i]); 
	}
	add(t, s, inf);
	if(dinic(S, T) != sum) return puts("-1"), 0;
	sum = e[edge_id].val, e[edge_id].val = e[edge_id ^ 1].val = 0;
	sum -= dinic(t, s);
	printf("%lld\n", 1ll * r * sum + 1ll * b * (n - sum));
	L(i, 1, n) {
		if(flag ^ e[E[i]].val) printf("r");
		else printf("b");
	}
	puts("");
	return 0;
}