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
const int M = 8e6 + 7;
const int inf = 1e9 + 7; 
const ll Mx = 1e12;

struct line {
	ll k, b;
	line (ll kk = 0, ll bb = 0) {
		k = kk, b = bb;
	}
	ll get(ll x) {
		return x * k + b;
	}
} ;
db inter(line aa, line bb) { 
	return (db)(bb.b - aa.b) / (aa.k - bb.k);
}
int tot = 0, hd1, hd2, ch[M][2];
line seg[M];
void add(int &id, ll L, ll R, line now) {
	if(!id) return id = ++tot, seg[id] = now, void();
	ll mid = (L + R) >> 1, La = seg[id].get(L), Ra = seg[id].get(R), Lb = now.get(L), Rb = now.get(R);
	if(La >= Lb && Ra >= Rb) return;
	if(La <= Lb && Ra <= Rb) return seg[id] = now, void();
	db it = inter(seg[id], now);
	if(La >= Lb) { 
		if(it <= (db) mid) add(ch[id][0], L, mid, seg[id]), seg[id] = now;
		else add(ch[id][1], mid + 1, R, now);
	}
	else {
		if(it <= (db) mid) add(ch[id][0], L, mid, now);
		else add(ch[id][1], mid + 1, R, seg[id]), seg[id] = now;
	}
}
ll qry(int id, ll L, ll R, ll wz) {
	if(!id) return 0;
	ll mid = (L + R) >> 1;
	if(wz <= mid) return max(seg[id].get(wz), qry(ch[id][0], L, mid, wz));
	else return max(seg[id].get(wz), qry(ch[id][1], mid + 1, R, wz));	
}

ll ans;
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
} 
int n, a[N], FN, siz[N], dep[N], rt, rtmx;
ll len[N], sum1[N], sum2[N];
bool vis[N];
void findrt(int x, int fa) {
	int maxn = 0; siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to; if(v == fa || vis[v]) continue;
		findrt(v, x), siz[x] += siz[v], maxn = max(maxn, siz[v]);
	} 
	maxn = max(maxn, FN - siz[x]);
	if(maxn < rtmx) rt = x, rtmx = maxn;
}
void work1(int x, int fa) {
	siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to; if(v == fa || vis[v]) continue;
		dep[v] = dep[x] + 1, len[v] = len[x] + a[v], sum1[v] = sum1[x] + len[v], sum2[v] = sum2[x] + (ll) dep[v] * a[v];
		work1(v, x), siz[x] += siz[v];
	}
	ans = max(ans, qry(hd1, 0, Mx, len[x]) + sum2[x]);
	ans = max(ans, qry(hd2, 0, n, dep[x]) + sum1[x]);
}
void work2(int x, int fa) {
	dep[x] = dep[fa] + 1, len[x] = len[fa] + a[x], sum1[x] = sum1[fa] + len[x], sum2[x] = sum2[fa] + (ll) dep[x] * a[x];
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to; if(v == fa || vis[v]) continue;
		work2(v, x);
	}
	add(hd1, 0, Mx, line(dep[x], sum1[x]));
	add(hd2, 0, n, line(len[x], sum2[x]));
}
void divide(int x) {
	if(FN == 1) return;
	L(i, 1, tot) ch[i][0] = ch[i][1] = 0;
	tot = hd1 = hd2 = 0;
	rtmx = inf, findrt(x, -1), vis[rt] = 1, dep[rt] = 1, len[rt] = sum1[rt] = sum2[rt] = a[rt];
//	cout << "rt = " << rt << "\n";
	add(hd1, 0, Mx, line(dep[rt], sum1[rt]));
	add(hd2, 0, n, line(len[rt], sum2[rt]));
	for(int i = head[rt]; i; i = e[i].next) {
		int v = e[i].to; if(vis[v]) continue;
		dep[v] = 1, sum1[v] = sum2[v] = len[v] = a[v], work1(v, rt), work2(v, rt);
	}
	for(int i = head[rt]; i; i = e[i].next) {
		int v = e[i].to;
		if(!vis[v]) FN = siz[v], divide(v);
	}
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		add_edge(u, v), add_edge(v, u);
	}
	L(i, 1, n) cin >> a[i];
	FN = n, divide(1);
	cout << ans << "\n";
	return 0;
}