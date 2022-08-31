#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 2e6 + 7;
int n, m;
int ehd[N], ev[N], enx[N], eid;
void eadd (int u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
}
int fa[N], deg[N]; 
bool vis[N];
void dfs (int x) {
	vis[x] = true;
	for(int i = ehd[x]; i; i = enx[i]) if(!vis[ev[i]]) fa[ev[i]] = x, deg[x] += 1, dfs (ev[i]);
}
int A[N], B[N], tp;
void Main () {
	cin >> n >> m;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		eadd (u, v);
		eadd (v, u);
	}
	dfs (1);
	queue < int > q;
	L(i, 1, n) if(!deg[i]) q.push(i);
	while (q.size() > 1) {
		int a, b;
		a = q.front(), q.pop();
		b = q.front(), q.pop();
		++tp, A[tp] = a, B[tp] = b;
		deg[fa[a]] -= 1;
		if(deg[fa[a]] == 0) q.push(fa[a]);
		deg[fa[b]] -= 1;
		if(deg[fa[b]] == 0) q.push(fa[b]); 
	}
	if(tp * 2 >= (n + 1) / 2) {
		cout <<  "PAIRING\n" << tp << "\n";
		L(i, 1, tp) cout << A[i] << " " << B[i] << "\n";
	}
	else {
		tp = 0;
		for(int u = q.front(); u; u = fa[u]) A[++tp] = u;
		cout << "PATH\n" << tp << "\n";
		L(i, 1, tp) cout << A[i] << " ";
		cout << "\n";
	}
	L(i, 1, n) ehd[i] = 0, vis[i] = 0, fa[i] = 0, deg[i] = 0;
	while (!q.empty()) q.pop();
	tp = 0, eid = 0;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}