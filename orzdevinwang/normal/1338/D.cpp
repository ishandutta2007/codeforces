#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;
int n, fa[N], deg[N], f[N], g[N], ns; 
vi e[N];
void dfs(int x) {
	for(const int &v : e[x]) if(v != fa[x]) deg[x]++;
	for(const int &v : e[x]) if(v != fa[x]) {
		fa[v] = x, dfs(v);
		ns = max(ns, g[x] + f[v] + (x > 1) + max(0, deg[x] - 2)), ns = max(ns, f[x] + g[v] + 1);
		f[x] = max(f[x], g[v]), g[x] = max(g[x], f[v]);
	}
	f[x]++, g[x] += max(deg[x] - 1, 0), f[x] = max(f[x], g[x]), ns = max(ns, f[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	cin >> n;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
	} 
	dfs(1), cout << ns << '\n';
	return 0;
}