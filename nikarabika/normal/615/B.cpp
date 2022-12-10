#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 1e5 + 85 - 69;
LL dp[maxn];
LL deg[maxn];
vector<int> adj[maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[max(fi, se)].PB(min(fi, se));
		deg[fi]++, deg[se]++;
	}
	for(int v = 0; v < n; v++)
		for(auto u : adj[v])
			smax(dp[v], dp[u] + 1);
	LL ans = 0;
	for(int i = 0; i < n; i++)
		smax(ans, (dp[i] + 1) * deg[i]);
	cout << ans << endl;
	return 0;
}