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

const int maxn = 100 * 1000 + 85 - 69, maxl = 20;
vector<int> adj[maxn],
	vec[maxn],
	roots;
int h[maxn],
	par[maxn][maxl],
	sttime[maxn],
	fitime[maxn],
	n, q, ti;

void dfs(int v){
	sttime[v] = ti++;
	vec[h[v]].PB(sttime[v]);
	for(int j = 1; j < maxl and ~par[v][j - 1]; j++)
		par[v][j] = par[par[v][j - 1]][j - 1];
	for(auto u : adj[v])
		h[u] = h[v] + 1, dfs(u);
	fitime[v] = ti;
	return;
}

int kthpar(int v, int k){
	if(k > h[v])
		return -1;
	for(int i = 0; k; i++)
		if((k >> i) & 1)
			v = par[v][i], k ^= (1 << i);
	return v;
}

int childismatistic(int v, int dis){
	dis += h[v];
	return lower_bound(all(vec[dis]), fitime[v]) - lower_bound(all(vec[dis]), sttime[v]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> par[i][0], par[i][0]--;
		if(~par[i][0])
			adj[par[i][0]].PB(i);
		else
			roots.PB(i);
	}
	for(auto v : roots)
		dfs(v);
	cin >> q;
	while(q--){
		int fi, se;
		cin >> fi >> se;
		fi--;
		int p = kthpar(fi, se);
		if(p == -1){
			cout << "0 ";
			continue;
		}
		cout << childismatistic(p, se) - 1 << ' ';
	}
	return 0;
}