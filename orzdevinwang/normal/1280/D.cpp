#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 3007, mod = 1e9 + 7 ;
int n, m, siz[N], w[N];
vi e[N];
#define dt pair < int, ll >
dt dp[N][N], sav[N];
dt operator + (dt a, dt b) {
	return {a.first + b.first, a.second + b.second};
}
void dfs (int x, int fa) {
	siz[x] = 0;
	dp[x][0] = make_pair (0, w[x]);
	for (const int &v : e[x]) if(v != fa) {
		dfs (v, x);
		L(i, 0, siz[x] + siz[v]) sav[i] = make_pair(0, -1e15);
		L(i, 0, siz[x]) 
			L(j, 0, siz[v]) 
				sav[i + j] = max(sav[i + j], dp[x][i] + dp[v][j]);
		siz[x] += siz[v];
		L(i, 0, siz[x]) dp[x][i] = sav[i];
	}
	dp[x][siz[x] + 1] = {0, -1e15};
	R(i, siz[x], 0) 
		dp[x][i + 1] = max(dp[x][i + 1], make_pair(dp[x][i].first + (dp[x][i].second > 0), 0LL));
	siz[x] += 1;
}
void Main () {
	cin >> n >> m;
	L(i, 1, n) cin >> w[i], w[i] = - w[i];
	L(i, 1, n) {
		int x;
		cin >> x;
		w[i] += x;
	}
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs (1, 0);
	cout << dp[1][m - 1].first + (dp[1][m - 1].second > 0) << '\n';
	L(i, 1, n) e[i].clear ();
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}