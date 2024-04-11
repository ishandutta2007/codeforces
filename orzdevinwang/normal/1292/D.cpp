#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e4 + 5;
const int mx = 5000;
const db pi = acos(-1);
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
	return x * f;
}
struct fenwt {
	int sz[N];
	void add(int x, int v) {
		for(; x <= mx; x += (x & -x)) sz[x] += v;
	}
	int qry(int x) {
		int res = 0;
		for(; x; x -= (x & -x)) res += sz[x];
		return res;
	}
} s;
int head[N], edge_id;
struct edge {
	int to, next;
} e[N];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], head[u] = edge_id;
}
int n, stk[N], tot, dep[N], all, pid;
vector<int> fac[N];
bool Prime[N];
int ptot, p[N];
void xxs(int mx) {
	L(i, 2, mx) {
		if(!Prime[i]) ++ptot, p[ptot] = i;
		for(int j = 1; p[j] * i <= mx && j <= ptot; j ++) {
			Prime[p[j] * i] = 1;
			if(i % p[j] == 0) break;
		}
	}
	L(i, 1, ptot) {
		L(j, 1, mx / p[i]) {
			int now = p[i] * j, t = 0;
			while(now % p[i] == 0) ++t, now /= p[i], fac[p[i] * j].push_back(p[i]);
		}
	} 
}
void init(int mx) {
	xxs(mx);
	++tot, stk[tot] = 1, pid = mx;
	L(i, 2, mx) {
		int sav = s.qry(fac[i].back() - 1), sum = sav * 2 + fac[i].size(), nowdep = all - sav;
		if(nowdep ^ dep[i - 1]) {
			while(tot > 1 && nowdep < dep[stk[tot - 1]]) add_edge(stk[tot - 1], stk[tot]), --tot;
			if(nowdep == dep[stk[tot - 1]]) add_edge(stk[tot - 1], stk[tot]), --tot;
			else ++pid, dep[pid] = nowdep, add_edge(pid, stk[tot]), stk[tot] = pid;
		}
		all += fac[i].size(), dep[i] = all, ++tot, stk[tot] = i;
		for(int v : fac[i]) s.add(v, 1);
	}
	while(tot > 1) add_edge(stk[tot - 1], stk[tot]), --tot;
}
int siz[N], cnt[N];
ll sum[N], ans = 1e15;
void dfs1(int x) {
	siz[x] = cnt[x];
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		dfs1(v);
		sum[x] += sum[v], siz[x] += siz[v], sum[x] += (ll) (dep[v] - dep[x]) * siz[v];
	}
}
void dfs2(int x) {
	ans = min(ans, sum[x]);
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		sum[v] = sum[x] - (ll) (dep[v] - dep[x]) * (siz[v] * 2 - n);
		dfs2(v);
	}
}
int main() {
	init(5000);
	n = read();
	L(i, 1, n) {
		int v = read();
		if(!v) v = 1;
		cnt[v] ++;
	}
	dfs1(1), dfs2(1);
	L(i, 1, pid) {

	}
	printf("%lld\n", ans);
	return 0;
}