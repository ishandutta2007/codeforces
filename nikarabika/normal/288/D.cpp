//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long int ULL;
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

const int maxn = 80 * 1000 + 85 - 69;
ULL sum[maxn],
	sz[maxn],
	ans;
int n;
vector<int> adj[maxn];

void dfs(int u, int p = -1){
	sz[u] = 1;
	for(auto v : adj[u])
		if(v != p){
			dfs(v, u);
			sum[u] += sz[u] * sz[v];
			sz[u] += sz[v];
		}
	sum[u] += sz[u] * (n - sz[u]);
	ans += sum[u] * sum[u];
	if(~p){
		ULL tmp = sz[u] * (n - sz[u]);
		ans -= tmp * tmp;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(0);
	ULL val = ULL(n) * ULL(n - 1) / 2;
	cout << val * val - ans << endl;
	return 0;
}