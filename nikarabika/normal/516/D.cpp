//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100 * 1000 + 1;
vector<pll> adj[maxn],
	stc;
int par[maxn],
	ans[maxn],
	n;
LL downdis[maxn],
   Max2[maxn],
   updis[maxn],
   dis[maxn],
   parw[maxn],
   len;

void dfs0(int v, int p = -1){
	par[v] = p;
	for(auto e : adj[v])
		if(e.L != p){
			dfs0(e.L, v);
			parw[e.L] = e.R;
			LL val = downdis[e.L] + e.R;
			if(val >= downdis[v])
				Max2[v] = downdis[v], downdis[v] = val;
			else if(val > Max2[v])
				Max2[v] = val;
		}
	return;
}

void dfs1(int v){
	if(par[v] == -1){
		updis[v] = 0;
		dis[v] = downdis[v];
	}
	else{
		LL val = updis[par[v]];
		if(downdis[par[v]] == downdis[v] + parw[v])
			smax(val, Max2[par[v]]);
		else
			smax(val, downdis[par[v]]);
		updis[v] = val + parw[v];
		dis[v] = max(downdis[v], updis[v]);
	}
	for(auto e : adj[v])
		if(e.L != par[v])
			dfs1(e.L);
	return;
}

int dfs2(int v, int p = -1){
	stc.EB(MP(dis[v], v));
	ans[v]++;
	for(auto e : adj[v])
		if(e.L != p)
			ans[v] += dfs2(e.L, v);
	int id = lower_bound(all(stc), MP(dis[v] - len, -1LL)) - stc.begin() - 1;
	ans[stc[id].R]--;
	stc.pop_back();
	return ans[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].EB(MP(se, th));
		adj[se].EB(MP(fi, th));
	}
	dfs0(0);
	dfs1(0);
	int root = min_element(dis, dis + n) - dis;
	stc.EB(MP(-1000LL * 1000 * 1000 * 1000, n));
	int q;
	cin >> q;
	while(q--){
		memset(ans, 0, sizeof ans);
		cin >> len;
		dfs2(root);
		cout << *max_element(ans, ans + n) << '\n';
	}
	return 0;
}