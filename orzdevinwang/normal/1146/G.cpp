#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
const int inf = 1e9 + 7;
const int mx = 1e5;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
	return x * f;
}
int n, m, h, s, t, tot;
int head[N], edge_id = 1;
struct edge {
	int to, next, val;
} e[N << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], e[edge_id].val = val, head[u] = edge_id;
}
void add(int u, int v, int val) {
	// cout << u << " " << v << " " << val << endl;
	add_edge(u, v, val), add_edge(v, u, 0);
}
int dis[N], cur[N];
bool bfs() {
	queue<int> q;
	fill(dis + 1, dis + tot + 1, inf);
	copy(head + 1, head + edge_id + 1, cur + 1);
	q.push(s), dis[s] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = e[i].next) if(e[i].val) {
			int v = e[i].to;
			if(dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, q.push(v);
		}
	}
	return dis[t] < inf;
}
int dfs(int x, int flow) {
	if(x == t) return flow;
	int fl = flow;
	for(int i = cur[x]; i; i = e[i].next) {
		cur[x] = i;
		int v = e[i].to;
		if(dis[v] != dis[x] + 1 || !e[i].val) continue;
		int now = dfs(v, min(fl, e[i].val));
		fl -= now, e[i].val -= now, e[i ^ 1].val += now;
		if(!fl) break;
	}
	return flow - fl;
}
int dinic() {
	int res = 0;
	while(bfs()) /* cout << "?\n", */ res += dfs(s, inf);
	// cout << res << endl;
	return res;
}
#define P(i, j) (((i) - 1) * (h + 2) + (j) + 1)
int main() {
	n = read(), h = read(), m = read(), tot = n * (h + 2), s = ++tot, t = ++tot;
	L(i, 1, n) {
		add(s, P(i, 0), mx + h * h);
		add(P(i, h), t, mx * 2);
		L(j, 1, h) add(P(i, j - 1), P(i, j), mx + h * h - j * j);
	}
	L(i, 1, m) {
		int l = read(), r = read(), x = read(), val = read(), now = ++tot;
		add(now, t, val);
		L(j, l, r) add(P(j, x), now, inf);
	}
	printf("%d\n", n * (mx + h * h) - dinic());
	return 0;
}