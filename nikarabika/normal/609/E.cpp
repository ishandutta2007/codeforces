#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pii;
typedef pair<pii, LL> piii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) (x) = max((x), (y))
#define endl '\n'

const int maxn = 2e5 + 85 - 69, maxl = 20;
bool mark[maxn];
vector<pii> adj[maxn];
vector<piii> edge;
int par[maxn][maxl], h[maxn];
LL dis[maxn][maxl];
set<pii> s;
int n, m;
LL sum;

LL get_wei(int v, int k){
	LL ret = -1;
	for(int i = 0; i < 20 and k; i++)
		if((k >> i) & 1)
			smax(ret, dis[v][i]), v = par[v][i], k ^= (1 << i);
	return ret;
}

int get_par(int v, int k){
	for(int i = 0; i < 20 and k; i++)
		if((k >> i) & 1)
			v = par[v][i], k ^= (1 << i);
	return v;
}

int lca(int v, int u){
	if(h[v] < h[u])
		swap(v, u);
	v = get_par(v, h[v] - h[u]);
	if(v == u) return v;
	for(int i = 20 - 1; i >= 0; i--)
		if(par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		adj[fi].PB({se, th});
		adj[se].PB({fi, th});
		edge.PB({{fi, se}, th});
	}
	memset(par, -1, sizeof par);
	memset(dis, -1, sizeof dis);
	for(int i = 1; i <= n; i++)
		dis[i][0] = 1000000000 + 10;
	s.insert(MP(0, 1));
	dis[1][0] = 0;
	for(int i = 1; i <= n; i++){
		int v = s.begin()->R;
		s.erase(s.begin());
		mark[v] = true;
		sum += dis[v][0];
		for(int lev = 1; lev < maxl and par[v][lev - 1] != -1; lev++){
			par[v][lev] = par[par[v][lev - 1]][lev - 1];
			dis[v][lev] = max(dis[v][lev - 1], dis[par[v][lev - 1]][lev - 1]);
		}
		for(auto u : adj[v]){
			if(!mark[u.L] and u.R < dis[u.L][0]){
				s.erase(MP(dis[u.L][0], u.L));
				dis[u.L][0] = u.R;
				par[u.L][0] = v;
				h[u.L] = h[v] + 1;
				s.insert(MP(dis[u.L][0], u.L));
			}
		}
	}
	for(int i = 0; i < m; i++){
		int v = edge[i].L.L,
			u = edge[i].L.R;
		int p = lca(v, u);
		LL wei = max(get_wei(v, h[v] - h[p]), get_wei(u, h[u] - h[p]));
		cout << sum - wei + edge[i].R << endl;
	}
	return 0;
}