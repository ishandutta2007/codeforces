#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 3e5 + 7;
vi e[N], se[N];
int n, m, upt[N], ufa[N], fa[N], w[N];
char s[N], no[N];
int ch[N][2];
int dep[N], down[N]; 
int Dep = -1;
bool ok = true;
void DFS(int x) {
	if(!sz(e[x])) {
		if(Dep == -1) Dep = dep[x];
		else if(Dep != dep[x]) ok = false;
		upt[x] = down[x] = x;
		if(upt[fa[x]]) 
			ufa[x] = upt[fa[x]];
		return ;
	}
	if(sz(e[x]) == 2) {
		upt[x] = down[x] = x;
		if(upt[fa[x]]) 
			ufa[x] = upt[fa[x]];
	}
	for(const int &v : e[x]) {
		dep[v] = dep[x] + 1, upt[v] = upt[x], DFS(v);
		if(down[x] != x) down[x] = down[v];
		else se[x].push_back(down[v]);
	}
}
int rcnt, all[N], f[N][26], g[N][26]; 
int Getv (int x, int w) {
	int ret = 0;
	for (const int &v : se[x]) ret = max(ret, f[v][w] + g[v][w]);
	return ret;
}
void modi (int x, int w, int val) {
	int z = down[x];
	for (int u = ufa[z]; u; u = ufa[u]) 
		rcnt -= all[u] > Dep - dep[u], all[u] -= f[u][w];
	g[z][w] += val;
	for (int u = ufa[z]; u; u = ufa[u]) 
		f[u][w] = Getv (u, w), all[u] += f[u][w], rcnt += all[u] > Dep - dep[u];
//	cout << "rcnt = " << rcnt << '\n';
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 2, n) cin >> fa[i] >> (no + 1), s[i] = no[1], e[fa[i]].push_back(i);
	upt[1] = down[1] = 1, DFS(1); 
	if(!ok) {
		L(i, 1, m) cout << "Fou\n";
		return 0;
	}
	L(i, 2, n) if(s[i] != '?') modi (i, s[i] - 'a', 1);
	while (m--) {
		int x;
		cin >> x >> (no + 1);
		if(s[x] != '?') modi (x, s[x] - 'a', -1);
		s[x] = no[1];
		if(s[x] != '?') modi (x, s[x] - 'a', 1);
		if(rcnt) 
			cout << "Fou\n";
		else {
			cout << "Shi ";
			int ns = 0;
			L(i, 0, 25) ns += (i + 1) * (Dep - all[1] + f[1][i]);
			cout << ns << '\n';	
		} 
	} 
	return 0;
}