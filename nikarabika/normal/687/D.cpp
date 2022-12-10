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

const int maxn = 1000,
	  maxm = 1000 * 1000;
pair<pii, pii> e[maxm];
int par[maxn],
	col[maxn],
	sz[maxn];
int n, m, q;
vector<int> adj[maxn];

/*int root(int v){
	if(par[v] < 0)
		return v;
	root(par[v]);
	wei[v] ^= wei[par[v]];
	return par[v] = root(par[v]);
	//return root(par[v]);
}

int woot(int v){root(v); return wei[v];}
//int woot(int v){ return par[v] < 0 ? 0 : wei[v] ^ woot(par[v]);}

bool merge(int v, int u){
	int x = woot(v) ^ woot(u);
	if((v = root(v)) == (u = root(u)))
		return x;
	if(par[v] > par[u]) swap(v, u);
	par[v] += par[u];
	par[u] = v;
	wei[u] = !x;
	return true;
}*/

void dfs(int v, int rt, int cl){
	par[v] = rt;
	col[v] ^= cl;
	sz[par[rt]]++;
	for(auto u : adj[v])
		dfs(u, rt, cl);
	return;
}

bool merge(int v, int u){
	int x = col[v] ^ col[u];
	if((v = par[v]) == (u = par[u]))
		return x;
	if(sz[par[v]] < sz[par[u]])
		swap(v, u);
	adj[v].PB(u);
	dfs(u, v, !x);
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th, fi--, se--;
		e[i] = MP(MP(th, i), MP(fi, se));
	}
	sort(e, e + m);
	for(int i = 0; i < q; i++){
		for(int i = 0; i < n; i++){
			par[i] = i;
			sz[i] = 1;
			adj[i].clear();
		}
		memset(col, 0, sizeof col);
		int fi, se;
		cin >> fi >> se, fi--, se--;
		for(int j = m - 1; j >= -1; j--){
			if(j == -1){
				cout << -1 << '\n';
				break;
			}
			if(e[j].L.R >= fi and e[j].L.R <= se)
				if(!merge(e[j].R.L, e[j].R.R)){
					cout << e[j].L.L << '\n';
					break;
				}
		}
	}
	return 0;
}