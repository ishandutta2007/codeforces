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
const int N = 3e5 + 7;
const int inf = 1e9 + 7;
int n, m, g, a[N], b[N], tot, s, t;
int head[N], edge_id = 1, cur[N];
struct node {
	int to, next, val;
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
	copy(head + 1, head + edge_id + 1, cur + 1);
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
	for(int i = cur[x]; i; i = e[i].next) {
		int v = e[i].to;
		cur[x] = i;
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
int las[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n, tot = n, s = ++tot, t = ++tot;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) cin >> b[i];
	int sum = 0;
	L(i, 1, n) {
		L(j, 1, a[i]) if(a[i] % j == 0 && las[j]) add(i, las[j], inf);
		las[a[i]] = i;
		if(b[i] > 0) add(s, i, b[i]), sum += b[i];
		if(b[i] < 0) add(i, t, - b[i]);
	}
	cout << sum - dinic() << endl;
	return 0;
}