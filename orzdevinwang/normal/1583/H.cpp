#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, inf = 1.1e9; 
int n, q;
struct Data {
	int mx, lc;
	Data (int V = 0, int Lc = 0) { 
		mx = V, lc = Lc;
	}
};
struct edge {
	int a, b, c, d;
} we[N];
int up1[20][N], w2[N], W[N], up2[20][N], ch[N][2], dep[N];
void dfs1 (int x) {
	L(i, 0, 1) if(ch[x][i]) dep[ch[x][i]] = dep[x] + 1, dfs1 (ch[x][i]);
}
int lca (int x, int y) {
	if(dep[x] < dep[y]) swap (x, y);
	R(i, 19, 0) if(dep[x] - dep[y] >= (1 << i)) x = up2[i][x];
	if(x == y) return x;
	R(i, 19, 0) if(up2[i][x] != up2[i][y]) x = up2[i][x], y = up2[i][y]; 
	return up2[0][x];
}
Data em[N];
Data merge (Data a, Data b) {
	if(a.mx < b.mx) swap (a, b);
	if(a.mx != b.mx) return a;
	return Data (a.mx, lca(a.lc, b.lc));
}
int f[N];
int find (int x) { 
	return f[x] == x ? x : f[x] = find (f[x]); 
}
int jump (int x, int v) {
	R(i, 19, 0) if(up1[i][x] && W[up1[i][x]] >= v) x = up1[i][x];
	return x;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> q;
	L(i, 1, n) cin >> em[i].mx;
	L(i, 1, n - 1) cin >> we[i].a >> we[i].b >> we[i].c >> we[i].d;
	
	sort(we + 1, we + n, [&] (edge a, edge b) {
		return a.d < b.d;
	});
	L(i, 1, n * 2 - 1) f[i] = i;
	L(i, 1, n - 1) {
		int su = find(we[i].a), sv = find (we[i].b);
		f[su] = f[sv] = up2[0][su] = up2[0][sv] = i + n, ch[i + n][0] = su, ch[i + n][1] = sv, w2[i + n] = we[i].d;
	}
	L(i, 1, 19) L(j, 1, n * 2 - 1) up2[i][j] = up2[i - 1][up2[i - 1][j]];
	dep[2 * n - 1] = 1, dfs1 (2 * n - 1);
	L(i, 1, n) em[i].lc = i;
	sort(we + 1, we + n, [&] (edge a, edge b) {
		return a.c > b.c;
	});
	L(i, 1, n * 2 - 1) f[i] = i;
	L(i, 1, n - 1) {
		int su = find(we[i].a), sv = find (we[i].b);
		W[i + n] = we[i].c, f[su] = f[sv] = up1[0][su] = up1[0][sv] = i + n, ch[i + n][1] = sv, em[i + n] = merge (em[su], em[sv]);
	}
	L(i, 1, 19) L(j, 1, n * 2 - 1) up1[i][j] = up1[i - 1][up1[i - 1][j]];
	while (q--) {
		int v, x;
		cin >> v >> x;
		int z = jump (x, v);
		cout << em[z].mx << ' ' << w2[lca(em[z].lc, x)] << '\n';
	}
	return 0;
}