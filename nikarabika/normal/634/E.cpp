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
vector<int> adj[maxn];
int a[maxn],
	dp[maxn],
	pd[maxn],
	sz[maxn],
	mx[maxn],
	mx2[maxn],
	par[maxn],
	sum[maxn],
	n, k;
bool can[maxn];

void calc(int u = 0, int p = -1){
	par[u] = p;
	sz[u] = 1;
	for(auto v : adj[u])
		if(v != p)
			calc(v, u), sz[u] += sz[v];
	return;
}

int func(int u){
	return u == -1 ? 0 : dp[u];
}

void dfs1(int u = 0, int p = -1){
	mx[u] = mx2[u] = -1;
	dp[u] = sum[u] = 0;
	for(auto v : adj[u])
		if(v != p){
			dfs1(v, u);
			if(dp[v] == sz[v])
				sum[u] += dp[v];
			else{
				if(func(v) >= func(mx[u]))
					mx2[u] = mx[u], mx[u] = v;
				else if(func(v) >= func(mx2[u]))
					mx2[u] = v;
			}
		}
	if(can[u]) dp[u] = sum[u] + func(mx[u]) + 1;
	else dp[u] = 0;
	return;
}

void dfs2(int u = 0, int p = -1){
	if(p != -1){
		pd[u] = sum[p] - (dp[u] == sz[u]) * dp[u];
		if(pd[p] == n - sz[p]) pd[u] += pd[p] + (mx[p] == u ? func(mx2[p]) : func(mx[p]));
		else pd[u] += max((mx[p] == u ? func(mx2[p]) : func(mx[p])), pd[p]);
		if(!can[p]) pd[u] = 0;
		else pd[u]++;
	}
	for(auto v : adj[u])
		if(v != p)
			dfs2(v, u);
	return;
}

bool check(void){
	dfs1();
	dfs2();
	for(int u = 0; u < n; u++) if(can[u]){
		int su = 0,
			mix = 0;
		for(auto v : adj[u]){
			int siz = (v == par[u] ? n - sz[u] : sz[v]);
			if(v == par[u]){
				if(pd[u] == siz)
					su += pd[u];
				else
					smax(mix, pd[u]);
			}
			else if(dp[v] == siz)
				su += dp[v];
			else
				smax(mix, dp[v]);
		}
		if(su + mix + 1 >= k) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	calc();
	int lo = 1, hi = 2000 * 1000 + 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		for(int i = 0; i < n; i++)
			can[i] = a[i] >= mid;
		if(check())
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << '\n';
	return 0;
}