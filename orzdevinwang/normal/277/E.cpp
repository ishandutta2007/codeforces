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
const int N = 844;
const int M = N * N;
const int inf = 1e9;
struct cf { db c; int f; };
int n, m, s, t, tot, pre[N];
int head[N], edge_id = 1;
struct node {
	int to, next, val; db w;
} e[M << 1];
void add_edge(int u, int v, int val, db w) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].w = w, e[edge_id].to = v, e[edge_id].val = val, head[u] = edge_id;
}
void add(int u, int v, int val, db w) {
//	cout << u << " " << v << " " << val << "(" << w << ")\n";
	add_edge(u, v, val, w), add_edge(v, u, 0, -w);
}
db dis[N]; bool vis[N];
bool SPFA() {
	fill(dis + 1, dis + tot + 1, (db)(inf + 1));
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
db X[N], Y[N];
struct Point { db x, y; } P[N];
bool cmp(Point aa, Point bb) { return aa.y > bb.y; }
db len(int x, int y) { return sqrt((P[x].x - P[y].x) * (P[x].x - P[y].x) + (P[x].y - P[y].y) * (P[x].y - P[y].y)); }
cf mcmf() {
	cf res = {};
	while(SPFA()) {
		int flow = inf;
//		cout << "QwQ\n";
		for(int x = t; x != s; x = e[pre[x] ^ 1].to) /*cout << x << " <- ", */flow = min(flow, e[pre[x]].val);
//		cout << s << endl;
		for(int x = t; x != s; x = e[pre[x] ^ 1].to) e[pre[x]].val -= flow, e[pre[x] ^ 1].val += flow;
//		cout << dis[t] << endl;

		res.f += flow, res.c += dis[t] * flow;
	}
	return res;
}
int main() {
	scanf("%d", &n);
	tot = n * 2, s = ++tot, t = ++tot;
//	cout << s << " to " << t << endl;
	L(i, 1, n) scanf("%lf%lf", &P[i].x, &P[i].y);
	L(i, 1, n) add(s, i * 2 - 1, 2, 0), add(i * 2, t, 1, 0);
	L(i, 1, n) L(j, 1, n) if(P[i].y > P[j].y) add(i * 2 - 1, j * 2, 1, len(i, j));
	cf res = mcmf();
	if(res.f == n - 1) printf("%.10lf\n", res.c);
	else puts("-1");
	return 0;
}