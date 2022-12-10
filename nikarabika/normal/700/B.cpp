//sobskdrbhvk
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
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2e5 + 85 - 69;
int uni[maxn];
vector<int> adj[maxn];
LL ans = 0;
int n, k;

void dfs(int v, int p = -1){
	for(auto u : adj[v])
		if(u != p)
			dfs(u, v), uni[v] += uni[u];
	ans += min(uni[v], 2 * k - uni[v]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < k+k; i++){
		int x;
		cin >> x, x--;
		uni[x] = 1;
	}
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(0);
	cout << ans << '\n';
	return 0;
}