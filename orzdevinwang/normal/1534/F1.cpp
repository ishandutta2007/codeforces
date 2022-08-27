#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
#define News(x) L(i, 0, n + 1) { x[i] = new int [m + 2], memset (x[i], 0, sizeof(int) * (m + 2)); }
using namespace std;
const int N = 2e6 + 7;
struct tarjan {
	int stk[N], stot, vis[N], dfn[N], low[N], kind[N], tot, cnt;
	int ehd[N], enx[N], ev[N], eid, DEG[N], U[N];
	int lese[N];
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
			u = stk[stot], stk[stot] = vis[u] = 0, kind[u] = x;	
	}
	void work (int n) {
		L(i, 1, n) if(!dfn[i]) dfs(i);
	}
} G;
int n, m, a[N], could[N], q[N]; 
string s[N];
int * nxp[N], * lsp[N], * lef[N], * rig[N];
int dp[N], que[N], l, r, mx[N];
#define P(i, j) (((i) - 1) * m + (j))

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);  
	cin >> n >> m;
	R(i, n, 1) cin >> s[i], s[i] = " " + s[i];
	L(i, 1, m) cin >> a[i], q[i] = i;
	News(nxp)News(lsp)News(lef)News(rig)
	L(j, 1, m) {
		L(i, 1, n) nxp[i][j] = s[i][j] == '#' ? i : nxp[i - 1][j];
		lsp[n + 1][m] = n + 1;
		R(i, n, 1) lsp[i][j] = s[i][j] == '#' ? i : lsp[i + 1][j];
	}
	L(i, 1, n) L(j, 1, m) if(s[i][j] == '#') G.lese[P(i, j)] = true;
	L(j, 1, m) L(i, 2, n) if(s[i][j] == '#' && nxp[i - 1][j]) G.add(P(i, j), P(nxp[i - 1][j], j)); 
	L(j, 2, m) L(i, 1, n) if(s[i][j] == '#' && nxp[i][j - 1]) G.add(P(i, j), P(nxp[i][j - 1], j - 1));
	L(j, 1, m - 1) L(i, 1, n) if(s[i][j] == '#' && nxp[i][j + 1]) G.add(P(i, j), P(nxp[i][j + 1], j + 1));
	L(j, 1, m) L(i, 1, n - 1) if(s[i][j] == '#' && s[i + 1][j] == '#') G.add(P(i, j), P(i + 1, j));
////	L(i, 1, n) L(j, 1, m) cout << i << " " << j << " : " << G.kind[P(i, j)] << "\n";
	G.work(n * m);
	L(j, 1, m) {
		int z = nxp[n][j], tmp = (j == 1 ? 1 : lef[z][j - 1]);
		L(i, 1, n) 
			if(z && G.kind[P(i, j)] == G.kind[P(z, j)]) lef[i][j] = tmp;
			else lef[i][j] = j + 1;
		L(i, 2, n) lef[i][j] = min(lef[i][j], lef[i - 1][j]);
	} 
//	L(i, 1, n) L(j, 1, m) cout << i << " " << j << " : " << lef[i][j] << "\n";  
	R(j, m, 1) {
		int z = nxp[n][j], tmp = (j == m ? m : rig[z][j + 1]);
		L(i, 1, n) 
			if(z && G.kind[P(i, j)] == G.kind[P(z, j)]) rig[i][j] = tmp;
			else rig[i][j] = j - 1;
		L(i, 2, n) rig[i][j] = max(rig[i][j], rig[i - 1][j]);
	} 
	L(i, 1, m) {
		int z = nxp[n][i], L, R;
		if(z) L = lef[z][i], R = rig[z][i], q[R] = min(q[R], L);
	}
	R(i, m - 1, 1) q[i] = min(q[i], q[i + 1]);
	l = 0, r = 0, que[0] = 0;
	L(i, 1, m) {
		if(!a[i]) dp[i] = dp[i - 1];
		else dp[i] = 1e9;
		while(l <= r && que[l] < q[i] - 1) ++l;
		if(l <= r) dp[i] = min(dp[i], dp[que[l]] + 1);
		while(l <= r && dp[que[r]] > dp[i]) --r;
		que[++r] = i;
	}
	cout << dp[m] << "\n";
	return 0;
}