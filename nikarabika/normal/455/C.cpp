//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smax(x, y) (x) = max((x), (y))
#define smin(x, y) (x) = min((x), (y))

const int maxn = 3e5 + 85 - 69;
int par[maxn], ans[maxn], comp[maxn];
bool mark[maxn];
vector<int> adj[maxn];
int n, m, q, compcnt;

int root(int v){return (par[v] < 0) ? v : par[v] = root(par[v]);}

void merge(int v, int u){
	if((v = root(v)) == (u = root(u)))
		return;
	if(par[v] > par[u])
		swap(v, u);
	par[v] += par[u];
	par[u] = v;
	ans[v] = max(max(ans[v], ans[u]), (ans[v] + 1) / 2 + (ans[u] + 1) / 2 + 1);
	return;
}

pii inc(pii an){
	return {an.L + 1, an.R};
}

pii find_farest(int v, int compcnt, int root, bool mval){
	mark[v] = true;
	comp[v] = compcnt;	//component index
	par[v] = (v != root) * root;	//dsu
	par[root]--;
	pii ret(0, v);		//return value
	for(auto u : adj[v])
		if(!mark[u])
			smax(ret, inc(find_farest(u, compcnt, root, mval)));
	mark[v] = mval;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 1; i <= n; i++) if(!mark[i]){
		int v = find_farest(i, compcnt, i, false).R;
		ans[i] = find_farest(v, compcnt, i, true).L;
		//cerr << "LOG: " << i << ' ' << ans[i] << '\n';
		compcnt++;
	}
	while(q--){
		int ty, fi, se;
		cin >> ty;
		if(ty == 1){
			cin >> fi;
			cout << ans[root(fi)] << '\n';
		}
		else{
			cin >> fi >> se;
			merge(fi, se);
		}
	}
	return 0;
}