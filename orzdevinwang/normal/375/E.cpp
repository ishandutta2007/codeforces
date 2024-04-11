#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int N = 507;
int n, m, col[N], cnt, siz[N], L[N], R[N], mp[N], idtot;
short dp[N][N][N], mn[N][N], sv[N][N];
int head[N], edge_id;
struct edge {
	int to, next, val;
} e[N << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].val = val, e[edge_id].to = v, head[u] = edge_id;
}
void init(int rt, int x, int fa, int dep) {
	if(rt == 1) L[x] = ++idtot, mp[idtot] = x;
	if(dep > m) dep = m + 1;
	if(x ^ rt && dep <= m) dp[rt][0][x] = 0;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to; if(v == fa) continue;
		init(rt, v, x, dep + e[i].val);
	}
	if(rt == 1) R[x] = idtot; 
}
void Min(short &aa, short bb) { if(aa > bb) aa = bb; }
void dfs(int x, int fa) {
	siz[x] = 1;
	for(int t = head[x]; t; t = e[t].next) {
		int v = e[t].to; if(v == fa) continue;
		dfs(v, x);
		memset(sv, 0x3f, sizeof(sv));
		L(i, 1, n) L(j, 0, siz[x]) L(k, 0, siz[v]) Min(sv[j + k][i], dp[x][j][i] + dp[v][k][i]);
		L(i, 1, n) if(i < L[v] || i > R[v]) L(j, 0, siz[x]) L(k, 0, siz[v]) Min(sv[j + k][mp[i]], dp[x][j][mp[i]] + mn[v][k]);
		siz[x] += siz[v];
		L(i, 0, siz[x]) L(j, 1, n) dp[x][i][j] = sv[i][j];	
	}
	L(i, 0, siz[x]) L(j, L[x], R[x]) Min(mn[x][i], dp[x][i][mp[j]]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(dp, 0x3f, sizeof(dp));
	memset(mn, 0x3f, sizeof(mn));
	cin >> n >> m;
	L(i, 1, n) cin >> col[i], dp[i][1][i] = 1 - col[i], cnt += col[i];
	L(i, 1, n - 1) {
		int u, v, val; cin >> u >> v >> val;
		add_edge(u, v, val), add_edge(v, u, val);
	}
	L(i, 1, n) init(i, i, -1, 0);
	dfs(1, -1);
	short ans = 1e4;
	L(i, 0, cnt) L(j, 1, n) Min(ans, dp[1][i][j]);
	if(ans == 10000) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}