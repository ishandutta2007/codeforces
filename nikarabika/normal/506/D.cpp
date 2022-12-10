//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())

const int maxn = 1e5 + 10, maxsq = 320;
vector<int> vert[maxn];
vector<pii> edge[maxn], quer[maxn];
int par[maxn], ans[maxn];
int n, m, q;

int root(int v){return (par[v] < 0) ? v : par[v] = root(par[v]);}

void merge(int v, int u){
	if((v = root(v)) == (u = root(u)))
		return;
	if(par[v] > par[u])
		swap(v, u);
	par[v] += par[u];
	par[u] = v;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		th--;
		edge[th].PB({fi, se});
		vert[th].PB(fi);
		vert[th].PB(se);
	}
	for(int i = 0; i < maxn; i++){
		sort(vert[i].begin(), vert[i].end());
		vert[i].resize(unique(vert[i].begin(), vert[i].end()) - vert[i].begin());
	}
	cin >> q;
	for(int i = 0; i < q; i++){
		int fi, se;
		cin >> fi >> se;
		if(fi > se)
			swap(fi, se);
		quer[fi].PB({se, i});
	}
	for(int i = 1; i <= n; i++)
		sort(quer[i].begin(), quer[i].end());
	for(int col = 0; col < maxn; col++){
		for(auto v : vert[col])
			par[v] = -1;
		for(auto e : edge[col])
			merge(e.L, e.R);
		if(sz(vert[col]) >= maxsq){
			for(auto v : vert[col]){
				for(auto gar : quer[v]){
					int u = gar.L;
					int id = lower_bound(vert[col].begin(), vert[col].end(), u) - vert[col].begin();
					if(id != sz(vert[col]) and vert[col][id] == u and root(v) == root(u))
						ans[gar.R]++;
				}
			}
		}
		else{
			for(int i = 0; i < sz(vert[col]); i++){
				int v = vert[col][i];
				for(int j = i + 1; j < sz(vert[col]); j++){
					int u = vert[col][j];
					if(root(v) == root(u)){
						int id = lower_bound(quer[v].begin(), quer[v].end(), MP(u, -1)) - quer[v].begin();
						while(id < sz(quer[v]) and quer[v][id].L == u){
							ans[quer[v][id].R]++;
							id++;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	return 0;
}