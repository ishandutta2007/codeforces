#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7, mod = 998244353;
int n, m, dp[N], f[N], deg[N], ns = mod; 
vi e[N];
int sl[N], sr[N];
bool vis[N];
void dfs (int x, int fa) {
	if(sz(e[x]) == 1 && fa) return dp[x] = 1, f[x] = 1, vis[x] = true, void ();
	dp[x] = 0;
	int et = mod, cnt = 0;
	for(int v : e[x]) if(v != fa) dfs(v, x), dp[x] += dp[v], et = min(et, f[v] - dp[v]), cnt += vis[v];
	f[x] = dp[x] + et;
	if(!cnt) vis[x] = true, dp[x] += 1;
	else vis[x] = false, dp[x] -= 1;
}
void Main () {
	cin >> n;
	L(t, 1, n - 1)  {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs (1, 0);
	cout << f[1] << '\n';
	L(i, 1, n) e[i].clear ();
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}