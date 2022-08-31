#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, k, fa[N], w[N], dp[N], up[20][N], mnd[N], upt[N];
inline int gk (int x, int k) { L(i, 0, 19) if(k >> i & 1) x = up[i][x]; return x; }
vi e[N];
void dfs (int x) {
	if(!sz(e[x])) return mnd[x] = 0, void ();
	for (const int &v : e[x]) dfs(v), mnd[x] = min(mnd[x], mnd[v] + 1);
}
void DFS (int x) {
	upt[x] = x;
	if(mnd[x] < k) upt[x] = upt[gk(x, k - mnd[x])];
	if(!sz(e[x])) return w[upt[gk(x, k)]] += 1, void ();
	for (const int &v : e[x]) DFS(v), dp[x] = max(dp[x], dp[v]);
	dp[x] += w[x];
}
int main () {
	memset (mnd, 0x3f, sizeof(mnd));
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	L(i, 2, n) cin >> fa[i], up[0][i] = fa[i], e[fa[i]].push_back(i);
	L(i, 1, 19) L(j, 1, n) up[i][j] = up[i - 1][up[i - 1][j]];
	dfs(1), upt[0] = 1, DFS(1);
	cout << dp[1] << '\n';
	return 0;
}