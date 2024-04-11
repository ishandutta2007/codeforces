#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
#define i128 __int128
using namespace std;
const int N = 1e6 + 7; 
int f[N]; 
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
struct tarjan {
	int stk[N], stot, vis[N], dfn[N], low[N], tot, cnt;
	int ehd[N], enx[N], ev[N], eid;
	void add(int u, int v) {
		++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
	}
	void dfs(int x) {
		vis[x] = true, stk[++stot] = x, dfn[x] = low[x] = ++tot;
		for(int i = ehd[x]; i; i = enx[i]) {
			if(!dfn[ev[i]]) dfs(ev[i]), low[x] = min(low[x], low[ev[i]]);
			if(vis[ev[i]]) low[x] = min(low[x], dfn[ev[i]]);
		}
		if(low[x] == dfn[x]) for(int u = 0; u != x; --stot) 
			u = stk[stot], stk[stot] = vis[u] = 0, f[u] = x;
	}
} G;
const ll inf = 1e18;
int n, m, q, su[N], sv[N], sw[N];
int ehd[N], ev[N], enx[N], ew[N], eid;
void eadd(int u, int v, int w) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid;
} 
vector < int > vc[N];
ll vis[N], d[N], D, sD;
bool op;
void dfs1(int x) {
	for(int i = ehd[x]; i; i = enx[i]) {
		if(vis[ev[i]] >= inf) 
			vis[ev[i]] = vis[x] + ew[i], dfs1(ev[i]); 
		else if(vis[ev[i]] != vis[x] + ew[i]) 
			D = __gcd(D, abs(vis[ev[i]] - (vis[x] + ew[i])));
	}
}
ll ns[N];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) f[i] = i;
	L(i, 1, m) cin >> su[i] >> sv[i] >> sw[i], G.add(su[i], sv[i]);
	L(i, 1, n) if(!G.dfn[i]) G.dfs(i);
	L(i, 1, m) if(find(su[i]) == find(sv[i])) eadd(su[i], sv[i], sw[i]), eadd(sv[i], su[i], -sw[i]);
	
	L(i, 1, n) vc[find(i)].push_back(i);
	L(u, 1, n) if(f[u] == u) {
		op = false, D = 0;
		for(const int &x : vc[u]) vis[x] = inf * 2;
		vis[u] = 0, dfs1(u), ns[u] = D;
	}
	int q;
	cin >> q;
	while(q--) {
		int x;
		ll s, t;
		cin >> x >> s >> t, x = find(x);
		if(s == 0) {
			cout << "YES\n";
			continue;
		}
		if(!ns[x]) {
			cout << "NO\n";
			continue;
		}
		ll row = __gcd(t, ns[x]);
		if(s % row == 0) cout << "YES\n";
		else cout << "NO\n"; 
	} 
	return 0;
}