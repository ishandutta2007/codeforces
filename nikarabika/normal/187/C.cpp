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

const int maxn = 1e5 + 85 - 69;
vector<int> adj[maxn],
	vec;
vector<pair<int, pii> > merq;
int par[maxn],
	dis[maxn];
bool mark[maxn];
int q[maxn], pos[maxn], sz;
int n, m, k;

int root(int u){ return par[u] < 0 ? u : par[u] = root(par[u]);}

void merge(int u, int v){
	if((u = root(u)) == (v = root(v))) return;
	if(par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	memset(dis, 63, sizeof dis);
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		int x;
		cin >> x, x--;
		vec.PB(x);
	}
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	int st, en;
	cin >> st >> en, st--, en--;
	vec.PB(en);
	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	memset(pos, -1, sizeof pos);
	pos[0] = 0;
	for(auto u : vec)
		q[sz++] = u, mark[u] = true, dis[u] = 0;
	for(int i = 0; i == 0 or pos[i] > pos[i - 1]; i++){
		pos[i + 1] = sz;
		for(int j = pos[i]; j < pos[i + 1]; j++){
			int u = q[j];
			for(auto v : adj[u]){
				if(!mark[v]){
					mark[v] = true;
					q[sz++] = v;
					dis[v] = dis[u] + 1;
					par[v] = u;
				}
				else if(dis[v] == dis[u])
					merge(u, v);
			}
		}
		if(root(st) == root(en)){
			cout << (i<<1|1) << endl;
			return 0;
		}
		for(int j = pos[i]; j < pos[i + 1]; j++){
			int u = q[j];
			for(auto v : adj[u])
				if(dis[v] == dis[u] + 1)
					merge(u, v);
		}
		if(root(st) == root(en)){
			cout << ((i+1)<<1) << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}