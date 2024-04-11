#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define mid ((l + r) / 2)
#define lch l, mid, ls[o]
#define rch mid + 1, r, rs[o]

using namespace std;
const int N = 100025, M = 100020, P = 999999937;

int n, m, s, t, bas[N], dis[N], pre[N];
int as, path[N], tp;
vector <pair <int, int>> G[N];
int rt0, rt1, idx;
int sz[N * 80], ls[N * 80], rs[N * 80], c[N * 80];
void pu(int o) {
	c[o] = (c[ls[o]] + c[rs[o]]) % P, sz[o] = sz[ls[o]] + sz[rs[o]];
}
void bld0(int l, int r, int& o) {
	sz[o = ++idx] = r - l + 1;
	if(l < r) bld0(lch), bld0(rch);
}
void bld1(int l, int r, int& o) {
	o = ++idx;
	if(l == r) c[o] = l < M ? bas[l] : 0;
	else bld1(lch), bld1(rch), pu(o);
}
void upd1(int p, int l, int r, int& o, int O) {
	ls[o = ++idx] = ls[O], rs[o] = rs[O];
	if(l == r) c[o] = bas[p];
	else p <= mid ? upd1(p, lch, ls[O]) : upd1(p, rch, rs[O]), pu(o);
}
void upd0(int L, int R, int l, int r, int& o, int O, int oo) {
	if(L <= l && r <= R) { o = oo; return; } 
	ls[o = ++idx] = ls[O], rs[o] = rs[O];
	if(L <= mid) upd0(L, R, lch, ls[O], ls[oo]);
	if(R > mid) upd0(L, R, rch, rs[O], rs[oo]); 
	pu(o);
}
int find(int p, int l, int r, int o) {
	if(!sz[o]) return -1;
	if(l == r) return l;
	int re = p <= mid ? find(p, lch) : -1;
	return ~re ? re : find(p, rch);
}
int cmp(int l, int r, int o, int oo) {
	return l < r ? c[rs[o]] ^ c[rs[oo]] ? cmp(rch, rs[oo]) : cmp(lch, ls[oo]) : c[o] < c[oo];
}
int Cmp(int a, int b) { return c[a] ^ c[b] && cmp(0, M, a, b); }
void calc(int l, int r, int o) {
	if(l == r) as = (as * 2 + (c[o] > 0)) % 1000000007;
	else calc(rch), calc(lch);
}
struct node {
	int u, d;
	bool operator <(const node& b)const { return Cmp(b.d, d); }
};
priority_queue <node> q;
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	bas[0] = 1;
	rep(i, 1, M) bas[i] = bas[i - 1] * 131ll % P;
	cin >> n >> m;
	bld0(0, M, rt0), bld1(0, M, rt1);
	int u, v, w;
	while(m--) scanf("%d%d%d", &u, &v, &w), G[u].eb(v, w), G[v].eb(u, w);
	rep(i, 1, n) dis[i] = rt1;
	cin >> s >> t;
	dis[s] = rt0;
	q.push({s, dis[s]});
	while(!q.empty()) {
		auto [u, d] = q.top(); q.pop();
		if(dis[u] ^ d) continue;
		for(auto [v, w] : G[u]) {
			int t = d, p = find(w, 0, M, t);
			if(w < p) upd0(w, p - 1, 0, M, t, t, rt0);
			upd1(p, 0, M, t, t);
			if(Cmp(t, dis[v])) dis[v] = t, pre[v] = u, q.push({v, t});
		}
	}
	if(dis[t] == rt1) puts("-1");
	else {
		calc(0, M, dis[t]);
		for(int u = t; u ^ s; u = pre[u]) path[++tp] = u;
		path[++tp] = s;
		printf("%d\n%d\n", as, tp);
		while(tp) printf("%d ", path[tp--]);
	}
	return 0;
}