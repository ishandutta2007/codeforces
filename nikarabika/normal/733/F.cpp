//sobskdrbhvk
//remember the flying, the bird dies ):(
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
#define cos Cos

const int maxn = 300 * 1000 + 85 - 69,
	  maxl = 20;
int frm[maxn],
	too[maxn],
	par[maxn][maxl],
	dpar[maxn],
	h[maxn],
	ord[maxn],
	n, m;
LL cos[maxn],
   wei[maxn],
   pool;
pll mxw[maxn][maxl];
vector<int> adj[maxn],
	vecans;

int root(int u){ return dpar[u] < 0 ? u : dpar[u] = root(dpar[u]);}

bool merge(int u, int v){
	if((u = root(u)) == (v = root(v)))
		return false;
	if(dpar[u] > dpar[v])
		swap(u, v);
	dpar[u] += dpar[v];
	dpar[v] = u;
	return true;
}

void dfs(int u, int pe = -1){
	for(int i = 1; i < maxl and ~par[u][i - 1]; i++){
		par[u][i] = par[par[u][i - 1]][i - 1];
		mxw[u][i] = max(mxw[u][i - 1], mxw[par[u][i - 1]][i - 1]);
	}
	for(auto e : adj[u]){
		if(e != pe){
			int v = frm[e]^too[e]^u;
			par[v][0] = u;
			mxw[v][0] = MP(wei[e], e);
			h[v] = h[u] + 1;
			dfs(v, e);
		}
	}
	return;
}

int lca(int u, int v){
	if(h[u] < h[v]) swap(u, v);
	for(int i = 0; i < maxl and (h[u] - h[v]); i++)
		if(((h[u] - h[v]) >> i) & 1)
			u = par[u][i];
	if(u == v) return u;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

pll get(int u, int d){
	pll ret(-1, -1);
	for(int i = 0; i < maxl and d; i++)
		if((d >> i) & 1)
			smax(ret, mxw[u][i]), u = par[u][i], d ^= 1<<i;
	return ret;
}

bool cmp(int i, int j){
	return wei[i] < wei[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dpar, -1, sizeof dpar);
	memset(par, -1, sizeof par);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> wei[i];
	for(int i = 0; i < m; i++)
		cin >> cos[i];
	for(int i = 0; i < m; i++)
		cin >> frm[i] >> too[i], frm[i]--, too[i]--;
	cin >> pool;
	iota(ord, ord + m, 0);
	sort(ord, ord + m, cmp);
	LL sum = 0;
	for(int i = 0; i < m; i++){
		int id = ord[i];
		if(merge(frm[id], too[id])){
			sum += wei[id], adj[frm[id]].PB(id), adj[too[id]].PB(id);
			vecans.PB(id);
		}
	}
	dfs(0);
	LL ans = sum;
	int ansid = vecans[0];
	int del = vecans[0];
	for(int i = 0; i < m; i++){
		int p = lca(frm[i], too[i]);
		pll w = max(get(frm[i], h[frm[i]] - h[p]), get(too[i], h[too[i]] - h[p]));
		LL val = sum - w.L + wei[i] - pool / cos[i];
		if(val < ans){
			ans = val;
			ansid = i;
			del = w.R;
		}
	}
	cout << ans << '\n';
	for(auto e : vecans)
		if(e != del)
			cout << e + 1 << ' ' << wei[e] << '\n';
	cout << ansid + 1 << ' ' << wei[ansid] - (pool / cos[ansid]) << '\n';
	return 0;
}