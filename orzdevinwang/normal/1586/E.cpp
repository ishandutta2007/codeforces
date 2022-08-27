#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7; 
int n, m, cnt[N], x[N], y[N];
int f[N];
int find (int x) {
	return f[x] == x ? x : f[x] = find (f[x]); 
}
int dep[N], fa[N];
vi e[N];
void dfs (int x) {
	for (const int &v : e[x]) if(v != fa[x])
		dep[v] = dep[x] + 1, fa[v] = x, dfs (v);
} 
vi get (int u, int v) {
	vi A, B;
	A.push_back(u);
	B.push_back(v);
	while (u != v) {
		if(dep[u] > dep[v]) u = fa[u], A.push_back(u);
		else v = fa[v], B.push_back(v);
	}
	R(i, sz(B) - 2, 0) 
		A.push_back(B[i]);
	return A;
}
vi s[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	L(i, 1, n) f[i] = i;
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		if(find(u) != find (v)) 
			f[find(u)] = v, e[u].push_back(v), e[v].push_back(u); 
	} 
	dfs (1);
	int q;
	cin >> q;
	L(i, 1, q) {
		int u, v;
		cin >> u >> v;
		s[i] = get(u, v);
		cnt[u] ^= 1, cnt[v] ^= 1;
	}
	int ret = 0;
	L(i, 1, n) ret += cnt[i];
	if(ret) {
		cout << "NO\n" << ret / 2 << '\n';
	}
	else {
		cout << "YES\n";
		L(i, 1, q) {
			cout << sz(s[i]) << '\n';
			for (const int &t : s[i]) 
				cout << t << ' ';
			cout << '\n';
		}
	}
	return 0;
}