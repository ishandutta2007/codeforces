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

const int maxn = 2000 * 100;
vector<int> adj[maxn];
LL ans[maxn];
LL n, x, y;

bool dfs(int v, int p = -1){
	if(p != -1 and sz(adj[v]) == 1)
		return ans[v] = 1;
	LL val = 0;
	for(auto u : adj[v]) if(u != p){
		val += dfs(u, v);
		ans[v] += ans[u];
	}
	if(val == 0){
		ans[v]++;
		return true;
	}
	if(val == 1)
		return true;
	ans[v]--;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x >> y;
	swap(x, y);
	int mx = 0;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
		smax(mx, sz(adj[fi]));
		smax(mx, sz(adj[se]));
	}
	if(x == y){
		cout << x * (n - 1) << endl;
		return 0;
	}
	if(x > y){
		dfs(0);
		LL cnt = ans[0];
		cout << (cnt - 1) * x - (cnt - n) * y << '\n';
		return 0;
	}
	if(mx == n - 1)
		cout << x * (n - 2) + y << '\n';
	else
		cout << x * (n - 1) << '\n';
	return 0;
}