#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7; 
int n, m;
vi e[N], pe[N];
int dfn[N], en[N], fa[N], idt;
bool vis[N];
void Build (int x) {
	vis[x] = true, dfn[x] = ++idt;
	for (const int &v : e[x]) if(!vis[v]) fa[v] = x, Build (v);
	en[x] = idt;
}
bool check (int x) {
	L(i, 1, n) vis[i] = false, dfn[i] = en[i] = fa[i] = 0;
	idt = 0, Build (x); 
	L(i, 1, n) for (const int &v : e[i]) 
		if(fa[v] != i && !(dfn[v] <= dfn[i] && dfn[i] <= en[v])) return false ;
	return true ;
}
mt19937_64 orz (time (0) ^ clock()); 
bool ok[N];
int dep[N], mn1[N], s1[N], mn2[N];
void dfs2 (int x) {
	mn1[x] = mn2[x] = 1e9, s1[x] = -1;
	for(const int &v : e[x]) if(fa[v] != x) {
		if(dep[v] < mn1[x]) mn2[x] = mn1[x], s1[x] = v, mn1[x] = dep[v];
		else mn2[x] = min(mn2[x], dep[v]);
	}
	for(const int &v : e[x]) 
		if(fa[v] == x) {	
			dep[v] = dep[x] + 1, dfs2 (v);
			if(mn1[v] < mn1[x]) mn2[x] = min(mn1[x], mn2[v]), s1[x] = s1[v], mn1[x] = mn1[v];
			else mn2[x] = min(mn2[x], mn1[v]); 
		}
}
void dfs3 (int x) {
	if(mn1[x] < dep[x] && mn2[x] >= dep[x] && ok[s1[x]]) ok[x] = true;
	for (const int &v : e[x]) if(fa[v] == x) dfs3 (v);
}
void Main () {
	cin >> n >> m;
	L(i, 1, n) e[i].clear (), pe[i].clear (), ok[i] = false;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		pe[v].push_back(u);
	}
	int u = 1, T = 100;
	while (T--) {
		u = orz() % n + 1;
		if (check(u)) {
			dep[u] = 1, ok[u] = true, dfs2 (u), dfs3 (u);
			vi S;
			L(i, 1, n) if(ok[i]) S.push_back(i);
			if(sz(S) * 5 < n) cout << "-1\n";
			else {
				for (const int &w : S) cout << w << ' ';
				cout << '\n';
			}
			return ;
		}
	}
	cout << -1 << '\n';
} 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) Main ();
	return 0;
}