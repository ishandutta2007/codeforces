#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
template < int N, int Ne >  struct flow { 
	using F = int; // flow type
	F inf = 1e9;
	int n, s, t; // Remember to assign n, s and t !
	int ehd[N], cur[N], ev[Ne << 1], enx[Ne << 1], eid = 1;
	void clear() {
		eid = 1, memset(ehd, 0, sizeof(ehd));
	}
	F ew[Ne << 1], dis[N];
	void Eadd(int u, int v, F w) {
		++eid, enx[eid] = ehd[u], ew[eid] = w, ev[eid] = v, ehd[u] = eid;
	}
	void add(int u, int v, F w, bool op = 0) {
		Eadd(u, v, w), Eadd(v, u, op * w);
	}
	void cle() {
		memset(vis, 0, sizeof(vis));
	}
	bool vis[N];
	bool push0(int x) {
		if(x == t) return true;
		vis[x] = true;
		for(int i = ehd[x]; i; i = enx[i]) if((!ew[i] || ev[i] == t) && !vis[ev[i]] && push0(ev[i])) return ++ew[i], --ew[i ^ 1], true;
		return false;
	}
	bool del(int x) {
		return cle(), push0(x);
	}
	
	bool push1(int x) {
		if(x == s) return true;
		vis[x] = true;
		for(int i = ehd[x]; i; i = enx[i]) if(ew[i ^ 1] && !vis[ev[i]] && push1(ev[i])) return
			++ew[i], --ew[i ^ 1], true;
		return false;
	}
	bool ins(int x) {
		return cle(), push1(x);
	}
} ; 
const int N = 207, inf = 1e9;
flow < N * N, 4 * N * N > s;
int n, a[N][N], tot;
ll ns, res = 0;
#define P(x, y) (((x) - 1) * n + (y))
struct pr {
	int xid, v, d;
} q[N * 4];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n, s.s = P(n, n) + 1, s.t = P(n, n) + 2, s.n = P(n, n) + 2;
	L(i, 1, n) L(j, 1, n) cin >> a[i][j];
//	L(i, 1, n) L(j, 1, n) a[i][j] = (i == 1 || i == n || j == 1 || j == n ? 114514 : 0);
	L(i, 1, n) L(j, 1, n - 1) if(a[i][j] != -1 && a[i][j + 1] != -1) s.add(P(i, j), P(i, j + 1), 1, 1);
	L(i, 1, n - 1) L(j, 1, n) if(a[i][j] != -1 && a[i + 1][j] != -1) s.add(P(i, j), P(i + 1, j), 1, 1);
	L(i, 1, n) L(j, 1, n) if(a[i][j] > 0) 
		++tot, q[tot].xid = P(i, j), q[tot].v = a[i][j], s.add(s.s, P(i, j), inf), q[tot].d = (s.eid ^ 1);
	sort(q + 1, q + tot + 1, [&] (pr a, pr b) { return a.v > b.v; });
	L(i, 1, tot) {
		while(s.del(q[i].xid)) -- res;
		s.ew[q[i].d] = s.ew[q[i].d ^ 1] = 0;
//		cout << "res' = " << res << "\n";
		
//		cout << "????????\n";
//		while(s.ins(s.t)) ++res, s.cle(), cout << "\n"; //, ++cnt;
//		cout << "v : " << q[i].xid << "\n";
//		int cnt = 0;
		
		s.add(q[i].xid, s.t, inf);
		while(s.ins(s.t)) ++res, s.cle(); //, cout << "\n"; //, ++cnt;
//		if(cnt > n * 4) cout << "qaq : " << cnt << "\n";
//		cout << "res = " << q[i].v  << "\n";
		ns += (ll) res * (q[i].v - q[i + 1].v);
//		cout << "---------------------\n";
	}
	cout << ns << "\n";
	return 0;
}