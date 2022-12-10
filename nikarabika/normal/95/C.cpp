#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pll;

#define MP make_pair
#define L first
#define R second
#define PB push_back

const int maxn = 1010;
const LL INF = 1e18;
LL dis[maxn][maxn], t[maxn], c[maxn];
vector<pll> adj[2][maxn];
set<pll> s;
int n, m;

void add_edge(int ty, int fi, int se, LL th){
	adj[ty][fi].PB(MP(se, th));
	if(ty == 0)
		adj[ty][se].PB(MP(fi, th));
	return;
}

void Dij(int ty, int so){
	LL *d = dis[so];
	for(int i = 0; i <= n; i++)
		dis[so][i] = INF;
	d[so] = 0;
	s.insert(MP(d[so], so));
	while(s.size()){
		int v = s.begin()->R;
		s.erase(s.begin());
		for(auto u : adj[ty][v]){
			if(d[v] + u.R < d[u.L]){
				s.erase(MP(d[u.L], u.L));
				d[u.L] = d[v] + u.R;
				s.insert(MP(d[u.L], u.L));
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int source, sink;
	cin >> n >> m
		>> source >> sink;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		add_edge(0, fi, se, th);
	}
	for(int i = 1; i <= n; i++)
		cin >> t[i] >> c[i];
	for(int i = 1; i <= n; i++)
		Dij(0, i);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(dis[i][j] <= t[i])
				add_edge(1, i, j, c[i]);
	Dij(1, source);
	cout << ((dis[source][sink] == dis[1][0]) ? -1 : dis[source][sink]) << endl;
	return 0;
}