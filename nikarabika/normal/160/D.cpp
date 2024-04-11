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

const int maxn = 1e5 + 85 - 69,
	  maxw = 1e6 + 85 - 69;
vector<int> vec[maxw],
	adj[maxn];
bool none[maxn],
	 mark[maxn],
	 cut[maxn];
int frm[maxn],
	too[maxn],
	par[maxn],
	h[maxn],
	n, m;

int dfs(int u, int pe = -1){
	mark[u] = true;
	int up = h[u];
	for(auto e : adj[u]) if(e^pe){
		int v = frm[e]^too[e]^u;
		if(!mark[v]){
			h[v] = h[u] + 1;
			smin(up, dfs(v, e));
		}
		else if(v == u)
			none[e] = true;
		else
			smin(up, h[v]);
	}
	if(~pe) cut[pe] = up == h[u];
	return up;
}

int root(int u){return (par[u]>>31) ? u : par[u] = root(par[u]);}

void merge(int u, int v){
	if((u = root(u)) == (v = root(v)))
		return;
	if(par[u] > par[v])
		swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int fi, se, th;
		scanf("%d%d%d", &fi, &se, &th);
		fi--, se--;
		frm[i] = fi, too[i] = se;
		vec[th].PB(i);
	}
	memset(par, -1, sizeof par);
	for(int i = 0; i < maxw; i++)
	{
		for(auto e : vec[i])
		{
			int u = frm[e] = root(frm[e]);
			int v = too[e] = root(too[e]);
			mark[u] = mark[v] = h[u] = h[v] = 0;
			adj[u].clear();
			adj[v].clear();
		}
		for(auto e : vec[i])
		{
			int u = frm[e],
				v = too[e];
			adj[u].PB(e);
			adj[v].PB(e);
		}
		for(auto e : vec[i])
		{
			int u = frm[e],
				v = too[e];
			if(!mark[u])
				dfs(u);
			merge(u, v);
		}
	}
	for(int i = 0; i < m; i++)
		printf(none[i] ? "none\n" : cut[i] ? "any\n" : "at least one\n");
	return 0;
}