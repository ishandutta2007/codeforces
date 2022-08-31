#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
#define sz(x) ((int) x.size())
#define be(x) x.begin()
#define en(x) x.end()
using namespace std;
const int N = 1e5 + 7;
const int M = N * 20;
const ll inf = 1e18;
int n, m;
struct line {
	ll k, b;
	line (ll kk = 0, ll bb = 0) {
		k = kk, b = bb;
	}
	ll get(ll x) {
		return x * k + b;
	}
};
db inter(line aa, line bb) { // 
	return (db)(bb.b - aa.b) / (aa.k - bb.k);
}
int tot = 0, hd[N], ch[M][2];
line seg[M];
void add(int &id, int L, int R, line now) {
	if(!id) return id = ++tot, seg[id] = now, void();
	int mid = (L + R) >> 1;
	ll La = seg[id].get(L), Ra = seg[id].get(R), Lb = now.get(L), Rb = now.get(R);
	if(La <= Lb && Ra <= Rb) return;
	if(La >= Lb && Ra >= Rb) return seg[id] = now, void();
	db it = inter(seg[id], now);
	if(La <= Lb) { 
		if(it <= (db) mid) add(ch[id][0], L, mid, seg[id]), seg[id] = now;
		else add(ch[id][1], mid + 1, R, now);
	}
	else {
		if(it <= (db) mid) add(ch[id][0], L, mid, now);
		else add(ch[id][1], mid + 1, R, seg[id]), seg[id] = now;
	}
}
ll qry(int id, int L, int R, int wz) {
	if(!id) return inf;
	int mid = (L + R) >> 1;
	if(wz <= mid) return min(seg[id].get(wz), qry(ch[id][0], L, mid, wz));
	else return min(seg[id].get(wz), qry(ch[id][1], mid + 1, R, wz));	
}
int merge(int x, int y, int L = -1e5, int R = 1e5) {
	if(!x || !y) return x | y;
	int mid = (L + R) >> 1;
	ch[x][0] = merge(ch[x][0], ch[y][0], L, mid);
	ch[x][1] = merge(ch[x][1], ch[y][1], mid + 1, R);
	add(x, L, R, seg[y]);
	return x;
}
int edge_id, head[N];
struct edge {
	int to, next; 
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], head[u] = edge_id;
}
ll dp[N], a[N], b[N];
void dfs(int x, int fa = 0) {
	if(e[head[x]].to == fa && !e[head[x]].next) {
		dp[x] = 0, add(hd[x], -1e5, 1e5, line(b[x], dp[x]));
		return;
	}
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v, x), hd[x] = merge(hd[x], hd[v]);
	}
	dp[x] = qry(hd[x], -1e5, 1e5, a[x]), add(hd[x], -1e5, 1e5, line(b[x], dp[x]));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) cin >> b[i];
	L(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		add_edge(u, v), add_edge(v, u);
	}
	dfs(1);
	L(i, 1, n) cout << dp[i] << " ";
	cout << endl;
	return 0;
}