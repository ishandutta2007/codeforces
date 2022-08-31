#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7;
int n, m, k, pk, pr[N];	
int ehd[N], ev[N], enx[N], eid;
void eadd(int u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
}
int dep[N], fa[N], tp; 
vi all[N];
bool vis[N];
void dfs(int x) {
	vis[x] = true;
	dep[x] = dep[fa[x]] + 1;
	if(dep[x] == pk) { // dx
		cout << "PATH\n" << pk << "\n";
		for(; x; x = fa[x]) cout << x <<' '; 
		exit(0);
	}
	bool leaf = true;
	for(int i = ehd[x]; i; i = enx[i]) if(!vis[ev[i]]) fa[ev[i]] = x, dfs(ev[i]), leaf = false;
	if(leaf) {
		++tp;
		int a = 0, b = 0;
		for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa[x]) {
			if(!a) a = ev[i];
			else if(!b) b = ev[i];
		}
		if(dep[a] < dep[b]) swap(a, b);
		if((dep[x] - dep[a] + 1) % 3) {
			for(int u = x; u != fa[a]; u = fa[u]) all[tp].push_back(u);
		}
		else if((dep[x] - dep[b] + 1) % 3) {
			for(int u = x; u != fa[b]; u = fa[u]) all[tp].push_back(u);
		}
		else {
			for(int u = x; u != fa[b]; u = fa[u]) if(dep[u] <= dep[a] || u == x) all[tp].push_back(u);
		}
	}
	if(tp == k) {
		cout << "CYCLES\n";
		L(i, 1, k) {
			cout << sz(all[i]) << "\n";
			for(const int &x : all[i]) cout << x << ' ';
			cout << "\n";
		}
		exit(0);
	} 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k, pk = (n + k - 1) / k;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		eadd(u, v), eadd(v, u);
	} 
	dfs(1);
	
	assert(0);
	return 0;
}