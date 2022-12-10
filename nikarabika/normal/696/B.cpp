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

const int maxn = 1e5 + 85 - 69;
LD ans[maxn];
int par[maxn],
	siz[maxn],
	n;
vector<int> adj[maxn];

void dfs1(int v){
	siz[v] = 1;
	for(auto u : adj[v]){
		dfs1(u);
		siz[v] += siz[u];
	}
	return;
}

void dfs2(int v, LD ex = 0){
	ans[v] = ex + 1;
	for(auto u : adj[v])
		dfs2(u, ex + 1 + (siz[v] - 1 - siz[u]) / 2.);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++)
		cin >> par[i], adj[--par[i]].PB(i);
	dfs1(0);
	dfs2(0);
	cout.precision(10);
	for(int i = 0; i < n; i++)
		cout << fixed << ans[i] << ' ';
	cout << '\n';
	return 0;
}