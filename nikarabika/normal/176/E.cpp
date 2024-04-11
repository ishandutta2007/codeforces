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

const int maxn = 100 * 1000 + 85 - 69,
	  maxl = 20;
set<int> s;
vector<pll> adj[maxn];
LL wei[maxn],
   ans;
int par[maxn][maxl],
	sttime[maxn],
	fitime[maxn],
	dfs_order[maxn],
	h[maxn],
	n, ti;

void dfs(int v){
	dfs_order[ti] = v;
	sttime[v] = ti++;
	for(int j = 1; par[v][j - 1] != -1; j++)
		par[v][j] = par[par[v][j - 1]][j - 1];
	for(auto u : adj[v])
		if(u.L != par[v][0]){
			par[u.L][0] = v;
			h[u.L] = h[v] + 1;
			wei[u.L] = wei[v] + u.R;
			dfs(u.L);
		}
	fitime[v] = ti;
	return;
}

bool ischild(int v, int u){
	return sttime[v] <= sttime[u] and sttime[u] < fitime[v];
}

int kthpar(int v, int k){
	for(int i = 0; k; i++)
		if((k >> i) & 1)
			v = par[v][i], k ^= 1 << i;
	return v;
}

int lca(int v, int u){
	if(h[v] < h[u])
		swap(v, u);
	v = kthpar(v, h[v] - h[u]);
	if(v == u)
		return v;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

int getpos(int p, int v, int u){
	int lo = -1, hi = h[v] - h[p];
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		int pp = kthpar(v, mid);
		if(ischild(pp, u))
			hi = mid;
		else
			lo = mid;
	}
	return kthpar(v, hi);
}

LL getval(int v){
	if(sz(s) == 0) return 0;
	int lst, nxt;
	bool an = false;
	{
		auto it = s.lower_bound(sttime[v]);
		if(it == s.end()) nxt = dfs_order[*s.begin()], an = true;
		else nxt = dfs_order[*it];
		if(it == s.begin()) lst = dfs_order[*(it = s.end(), --it)], an = true;
		else it--, lst = dfs_order[*it];
	}
	int p = lca(lst, nxt);
	if(!ischild(p, v)){
		int pp = lca(p, v);
		return wei[p] + wei[v] - 2 * wei[pp];
	}
	if(ischild(v, lst) or ischild(v, nxt))
		return 0;
	int p1 = getpos(p, lst, v),
		p2 = getpos(p, nxt, v);
	if(h[p1] > h[p2])
		return wei[v] - wei[p1];
	return wei[v] - wei[p2];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].PB(MP(se, th));
		adj[se].PB(MP(fi, th));
	}
	dfs(0);
	int q;
	cin >> q;
	while(q--){
		char ty;
		cin >> ty;
		if(ty == '?')
			cout << ans << '\n';
		else{
			int v;
			cin >> v, v--;
			if(ty == '+'){
				ans += getval(v);
				s.insert(sttime[v]);
			}
			else{
				s.erase(sttime[v]);
				ans -= getval(v);
			}
		}
	}
	return 0;
}