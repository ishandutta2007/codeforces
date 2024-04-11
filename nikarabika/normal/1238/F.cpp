//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 3e5 + 10;
vector<int> adj[maxn];
int dp[maxn],
	ans;

void dfs(int u, int p = -1) {
	int chdp = 0;
	int chdp2 = 0;
	for (auto v : adj[u])
		if (v ^ p) {
			dfs(v, u);
			if (dp[v] > chdp)
				chdp2 = chdp, chdp = dp[v];
			else if (dp[v] > chdp2)
				chdp2 = dp[v];
		}
	dp[u] = sz(adj[u]) > 1 ? chdp + sz(adj[u]) - 1 : 1;
	if (sz(adj[u]) == 1)
		smax(ans, 1 + (p != -1));
	else if (sz(adj[u]) == 2)
		smax(ans, chdp + 1 + (p != -1));
	else
		smax(ans, chdp + chdp2 + sz(adj[u]) - 2 + (p != -1));
}

int solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		adj[i].clear();
	for (int i = 1; i < n; i++) {
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	adj[0].PB(-1);
	ans = 0;
	dfs(0);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}