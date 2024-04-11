#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int 
using namespace std;
const int N = 2e5 + 7;
int n, deg[N], a[N];
vi e[N];
int dp[N][3], co[N], ns;
void dfs (int x, int fa) {
	L(i, 0, 2) dp[x][i] = -1e9;
	dp[x][a[x]] = 0;
	for (const int &v : e[x]) if(v != fa) {
		dfs (v, x);
		L(i, 0, 2) 
			L(j, 0, 2) 
				ns = max(ns, dp[x][i] + dp[v][j] + (i + j == 3));
		L(i, 0, 2) 
			dp[x][a[x] ? a[x] : i] = max(dp[x][a[x] ? a[x] : i], dp[v][i] + (i + a[x] == 3));
	}
}
void Main () {
	ns = 0;
	cin >> n;
	L(i, 1, n) cin >> a[i];
	queue < int > q[3];
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		deg[u] += 1;
		deg[v] += 1; 
	}
	dfs (1, 0);
	cout << (ns + 3) / 2 << '\n';
	L(i, 1, n) e[i].clear ();
}
int main () {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}