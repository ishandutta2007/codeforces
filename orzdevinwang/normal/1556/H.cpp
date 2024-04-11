#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
using namespace std;
const int N = 55, M = N * N, sM = N * N * N, inf = 1e9;
int n, k, e[N][N], ns = inf;
bool vis[M];
int idt, su[M], sv[M], W[M];
struct M1 {
	int f[N];
	void init (int x) { L(i, 1, x) f[i] = i; }
	int find (int x) { return f[x] == x ? x : f[x] = find(f[x]); }
	inline void merge (int i) { f[find(su[i])] = find (sv[i]); }
	inline bool check (int i) { return find (su[i]) != find (sv[i]); }
} it1, S1;
struct M2 {
	int deg[N];
	inline void merge (int i) { deg[su[i]] -= 1, deg[sv[i]] -= 1; }
	inline bool check (int i) { return deg[su[i]] > 0 && deg[sv[i]] > 0; }
} it2, S2;
int ehd[M], ev[sM], enx[sM], cnt[M], eid;
inline void eadd (int u, int v) { ++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid; }
inline int getv (int x) { return vis[x] ? - W[x] : W[x]; } 
int dis[M], pre[M];
bool inq[M];
int Work () {
	eid = 0;
	L(i, 1, idt) ehd[i] = 0;
	L(i, 1, idt) if(vis[i]) {
		S1 = it1, S2 = it2;
		L(j, 1, idt) if(vis[j] && j != i) S1.merge(j), S2.merge(j);
		L(j, 1, idt) if(!vis[j] && S1.check(j)) eadd (i, j);
		L(j, 1, idt) if(!vis[j] && S2.check(j)) eadd (j, i);
	}
	S1 = it1, S2 = it2;
	L(i, 1, idt) if(vis[i]) S1.merge(i), S2.merge(i);
	L(i, 1, idt) if(!vis[i] && S2.check(i)) eadd (i, idt + 1);
	queue < int > q;
	L(i, 1, idt + 1) dis[i] = cnt[i] = inf, pre[i] = 0;
	L(i, 1, idt) if(!vis[i] && S1.check(i)) dis[i] = W[i], cnt[i] = 0, q.push(i); 
	while (!q.empty()) {
		int u = q.front();
		q.pop(); 
		inq[u] = false;
		for(int i = ehd[u]; i; i = enx[i]) {
			int ds = dis[u] + getv(ev[i]);
			if(dis[ev[i]] > ds || (dis[ev[i]] == ds && cnt[u] + 1 < cnt[ev[i]])) { 
				dis[ev[i]] = ds, cnt[ev[i]] = cnt[u] + 1, pre[ev[i]] = u;
				if(!inq[ev[i]]) q.push(ev[i]), inq[ev[i]] = true;
			} 
		}
	}
	if(dis[idt + 1] == inf) return inf;
	for(int u = pre[idt + 1]; u; u = pre[u]) vis[u] ^= 1;
	return dis[idt + 1];
}
int Solve (int upt) {
	memset(vis, 0, sizeof(bool) * (idt + 3));
	int res = 0;
	while (upt--) {
		int ret = Work ();
		if(ret == inf) return inf;
		res += ret;
	}
	return res;
}
M1 x1[11][11];
M2 x2[11][11];
void dfs (int u, int v, int ret, int upt) {
	if(u == k) return ns = min(ns, Solve (upt) + ret), void();
	if(v == k + 1) return dfs (u + 1, u + 2, ret, upt), void ();
	dfs (u, v + 1, ret, upt);
	if(it1.find (u) != it1.find (v) && it2.deg[u] > 0 && it2.deg[v] > 0) {
		x1[u][v] = it1, x2[u][v] = it2; 
		it1.f[it1.find(u)] = v, it2.deg[u] -= 1, it2.deg[v] -= 1;
		dfs (u, v + 1, ret + e[u][v], upt - 1);
		it1 = x1[u][v], it2 = x2[u][v];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> k, it1.init(n);
	L(i, 1, k) cin >> it2.deg[i];
	L(i, k + 1, n) it2.deg[i] = inf;
	L(i, 1, n) L(j, i + 1, n) cin >> e[i][j], e[j][i] = e[i][j];
	L(i, 1, n) L(j, max(i, k) + 1, n) ++idt, su[idt] = i, sv[idt] = j, W[idt] = e[i][j];
	dfs (1, 2, 0, n - 1);
	cout << ns << "\n";
	return 0;
}