#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int P = 10009;
const int N = 5e5 + 7;
const int M = 5e6 + 7;
const int inf = 1e9;
int tot, s, t;
int head[N], edge_id = 1;
struct node {
	int to, next, val;
} e[M << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, e[edge_id].val = val, head[u] = edge_id;
}
void add(int u, int v, int val) {
	// cout << u << " " << v << " " << val << endl;
	add_edge(u, v, val), add_edge(v, u, 0);
}
int dis[N], cur[N];
bool bfs() {
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
int dfs(int x, int flow) {
	if(x == t) return flow;
	int now = flow;
	for(int i = cur[x]; i; i = e[i].next) {
		int v = e[i].to;
		cur[x] = i;
		if(!e[i].val || dis[v] != dis[x] + 1) continue;
		int fl = dfs(v, min(now, e[i].val));
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
int n, m, now;
int p[N], hd[N], ch[N][2], Val[N];
vector<pii> vea[P];
vector<pii> veb[P];
void build(int id, int L, int R) {
	Val[id] = inf;
	if(L == R) return add(id, L, 1), void();
	int mid = (L + R) / 2;
	ch[id][0] = ++tot, add(id, ch[id][0], inf), build(ch[id][0], L, mid);
	ch[id][1] = ++tot, add(id, ch[id][1], inf), build(ch[id][1], mid + 1, R);
}
void Add(int &id, int fid, int las, int L, int R, int l, int r, int val) {
	id = ++tot;
	int mid = (L + R) / 2;
	if(l <= L && R <= r) {
		// cout << L << " " << R << " : " << val << endl;
		if(l == 1 && r == n) {
			Add(ch[id][0], ch[fid][0], id, L, mid, l, mid, val);
			Add(ch[id][1], ch[fid][1], id, mid + 1, R, mid + 1, r, val);
			return;
		}
		if(las) add(las, id, Val[id] = val);
		if(L ^ R) {
			ch[id][0] = ch[fid][0], add(id, ch[id][0], Val[ch[id][0]]);
			ch[id][1] = ch[fid][1], add(id, ch[id][1], Val[ch[id][1]]);
		}
		else add(id, L, 1);
		return;
	}
	if(las) add(las, id, Val[id] = Val[fid]);
	if(l <= mid) Add(ch[id][0], ch[fid][0], id, L, mid, l, r, val);
	else ch[id][0] = ch[fid][0], add(id, ch[id][0], Val[ch[id][0]]);
	if(r > mid) Add(ch[id][1], ch[fid][1], id, mid + 1, R, l, r, val);
	else ch[id][1] = ch[fid][1], add(id, ch[id][1], Val[ch[id][1]]);
}
int main() {
	scanf("%d%d", &n, &m), tot = n * 2, s = ++tot, t = ++tot;
	if(n == 1) return printf("%d\n", 1 - m), 0;
	L(i, 1, m) {
		int l1, l2, r1, r2; scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		vea[l1].push_back(mkp(r1, r2));
		veb[l2].push_back(mkp(r1, r2));
	}
	hd[0] = ++tot, build(hd[0], 1, n);
	L(i, 1, n) add(s, i + n, 1);
	L(i, 1, n) add(i, t, 1);
	// Add(hd[now + 1], hd[now], 0, 1, n, 1, n, 0), ++now;
	// Add(hd[now + 1], hd[now], 0, 1, n, 1, n, inf), ++now;
	L(i, 1, n) {
		for(pii x : vea[i]) Add(hd[now + 1], hd[now], 0, 1, n, x.first, x.second, 0), ++now;
		add(i + n, hd[now], 1);
		for(pii x : veb[i]) Add(hd[now + 1], hd[now], 0, 1, n, x.first, x.second, inf), ++now;
	}
	printf("%d\n", dinic());
	return 0;
}