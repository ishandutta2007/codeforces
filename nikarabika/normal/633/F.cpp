//sobskdrbhvk
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
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100 * 1000;
bool mark[maxn];
LL a[maxn],
   route[maxn],
   twoans[maxn],
   par[maxn],
   dpup[maxn],
   ans, n;
vector<int> adj[maxn],
	vec[maxn];

bool cmp(int i, int j){
	return route[i] > route[j];
}

LL getymax(int v, int u){
	if(v == -1)
		return 0;
	for(int i = 0; i < sz(vec[v]); i++)
		if(vec[v][i] != u)
			return route[vec[v][i]];
	return 0;
}

LL getomax(int v, int u = -1){
	int cnt = 0;
	LL ret = 0;
	for(int i = 0; i < sz(vec[v]) and cnt < 2; i++)
		if(vec[v][i] != u)
			ret += route[vec[v][i]], cnt++;
	return ret;
}

void dfs(int v, int p = -1){
	par[v] = p;
	route[v] = a[v];
	LL Max1 = 0, Max2 = 0;
	for(auto u : adj[v])
		if(u != p){
			dfs(u, v);
			smax(route[v], a[v] + route[u]);
			smax(twoans[v], twoans[u]);
			if(twoans[u] > Max2)
				Max2 = twoans[u];
			if(Max2 > Max1)
				swap(Max1, Max2);
			vec[v].PB(u);
		}
	sort(all(vec[v]), cmp);
	smax(twoans[v], a[v] + getomax(v));
	smax(ans, twoans[v]);
	smax(ans, Max1 + Max2);
	return;
}

LL dfs_up(int v){
	if(v == -1)
		return 0;
	if(mark[v])
		return dpup[v] + a[v];
	mark[v] = true;
	LL val = dfs_up(par[v]);
	smax(dpup[v], val);
	smax(dpup[v], getymax(par[v], v) + (~par[v] ? a[par[v]] : 0));
	return dpup[v] + a[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(0);
	for(int v = 0; v < n; v++){
		dfs_up(v);
		for(auto u : adj[v])
			if(u != par[v]){
				smax(ans, a[v] + getomax(v, u) + twoans[u]);
				smax(ans, a[v] + getymax(v, u) + dpup[v] + twoans[u]);
			}
	}
	cout << ans << endl;
	return 0;
}