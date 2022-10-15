#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "exp.inp"
#define FILE_OUT "exp.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(111539768))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
 
typedef long long ll;
typedef pair <int, int> pii;
 
const int N = 3e5 + 5, inf = 1e9;
 
int n, m, q, par[N], sz[N], dp[N], dist[N], mx;
bool mark[N];
vector <int> adj[N];
 
int root(int v) {
	if(v == par[v])
		return v;
	return par[v] = root(par[v]);
}
 
int bfs(int v) {
//	mx = 0;
	vector <int> vec;
	queue <int> q;
	q.push(v);
	dist[v] = 0;
	while(!q.empty()) {
		v = q.front();
		q.pop();
		mark[v] = true;
		vec.push_back(v);
		for (auto u : adj[v]) {
			if(dist[u] > dist[v] + 1) {
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	int idx = -1;
	for (auto u : vec) {
		if(mx < dist[u])
			mx = dist[u], idx = u;
		dist[u] = inf;
	}
	return idx;
}
 
void dsu(int v, int u) {
	v = root(v), u = root(u);
	if(v == u)
		return;
	if(sz[v] > sz[u])
		swap(v, u);
	sz[u] += sz[v];
	par[v] = u;
}
 
void merge(int v, int u) {
	v = root(v), u = root(u);
	if(v == u)
		return;
	if(sz[v] > sz[u])
		swap(v, u);
	sz[u] += sz[v];
	par[v] = u;
	dp[u] = max(max(dp[u], dp[v]), (dp[u] + 1) / 2 + (dp[v] + 1) / 2 + 1);
}
 
int main() {
    fio;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		sz[i] = 1, par[i] = i, dist[i] = 1e9;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		dsu(v, u);
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 0; i < n; i++) {
		if(!mark[i]) {
			mx = 0;
			int v = bfs(i);
			bfs(v);
			dp[root(i)] = mx;
		}
	}
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if(type == 1) {
			int x;
			cin >> x;
			x--;
			x = root(x);
			cout << dp[x] << endl;;
		}
		else {
			int v, u;
			cin >> v >> u;
			v--, u--;
			merge(v, u);
		}
	}
}