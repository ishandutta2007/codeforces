#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e5 + 7;
const int mod = 998244353;
const int B = 19;
const int M = N * (B + 1);
int n, m, Pow2[N];
struct PII {
	int x, y;
	PII (int xx = 0, int yy = 0) {
		x = xx, y = yy;
	} 
};
bool operator < (PII aa, PII bb) {
	return aa.x == bb.x ? aa.y < bb.y : aa.x < bb.x;
}
PII operator + (PII aa, PII bb) {
	return PII(aa.x + bb.x, aa.y + bb.y);
}
PII dis[N];
// case 1
int head[N], edge_id;
struct edge {
	int to, next; 
	PII val;
} e[N << 2];
void add_edge(int u, int v, PII val) {
	++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], e[edge_id].val = val, head[u] = edge_id;
}
bool flag[N];
void dijkstra() {
	priority_queue< pair<PII, int> > q;
	L(i, 1, n * 2) dis[i] = PII(1e9, 0);
	dis[1] = PII(0, 0), q.push(mkp(PII(0, 0), 1));
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(flag[u]) continue;
		flag[u] = 1;
		for(int i = head[u]; i; i = e[i].next) {
			int v = e[i].to;
			if(dis[u] + e[i].val < dis[v]) {
				dis[v] = dis[u] + e[i].val;
				q.push(mkp(PII(- dis[v].x, - dis[v].y), v));
			}
		}
	}
}
// case 2
int Dis[M], hd[M], edgeid;
struct Edge {
	int to, next;
} E[M << 2];
void addedge(int u, int v) {
	++edgeid, E[edgeid].to = v, E[edgeid].next = hd[u], hd[u] = edgeid;
}
void bfs() {
	memset(Dis, 0x3f, sizeof(Dis));
	queue<int> q;
	q.push(1), Dis[1] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = hd[u]; i; i = E[i].next) {
			int v = E[i].to;
			if(Dis[v] > Dis[u] + 1) Dis[v] = Dis[u] + 1, q.push(v);
		}
	}
}
int ans = 1e9;
#define P(x, y) ((x) * n * 2 + y)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	Pow2[0] = 1;
	L(i, 1, max(n, B)) Pow2[i] = (ll) Pow2[i - 1] * 2 % mod;
	L(i, 1, n) add_edge(i, i + n, PII(1, 0)), add_edge(i + n, i, PII(1, 0));
	L(i, 1, m) {
		int u, v; cin >> u >> v;
		add_edge(u, v, PII(0, 1));
		add_edge(v + n, u + n, PII(0, 1));
		L(j, 0, B) addedge(P(j, u), P(j, v)), addedge(P(j, v + n), P(j, u + n));
		L(j, 0, B - 1) addedge(P(j, u + n), P(j + 1, v)), addedge(P(j, v), P(j + 1, u + n));
	}
	bfs();
	L(j, 0, B) if(Dis[P(j, n)] <= 1e8) ans = min(ans, Dis[P(j, n)] + Pow2[j] - 1);
	L(j, 0, B) if(Dis[P(j, n * 2)] <= 1e8) ans = min(ans, Dis[P(j, n * 2)] + Pow2[j] - 1);
	if(ans < 1e9) return cout << ans << endl, 0;
	dijkstra();
	cout << (Pow2[min(dis[n].x, dis[n * 2].x)] - 1 + dis[n].y) % mod << endl;
	return 0;
}