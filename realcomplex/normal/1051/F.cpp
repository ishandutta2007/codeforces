#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 123;
const int LOG = 18;
const int NOT = 42;

vector<pii> T[N];
bool vis[N];
int climb[LOG][N];
ll dist[N];

vector<int> check[N];
vector<int> ver;

int ts[N];
int subt[N];
int tt;

void dfs(int u, int par, ll dep){
	vis[u] = true;
	dist[u] = dep;
	climb[0][u] = par;
	subt[u] = 1;
	ts[u] = tt ++ ;
	for(int i = 1;i < LOG; i ++ )
		climb[i][u] = climb[i - 1][climb[i - 1][u]];
	for(auto x : T[u]){
		if(x.fi == par)
			continue;
		if(!vis[x.fi]){
			dfs(x.fi, u, dep + x.se);
			subt[u] += subt[x.fi];
		}
		else{
			ver.push_back(u);
			ver.push_back(x.fi);
		}	
	}
}

ll dtt[NOT][N];
bool visit[N];

bool is_ancestor(int u, int v){
	return ts[v] >= ts[u] and ts[u] + subt[u] - 1 >= ts[v];
}

int lca(int u, int v){
	if(u == v)
		return u;
	if(is_ancestor(u, v))
		return u;
	if(is_ancestor(v, u))
		return v;
	for(int i = LOG - 1; i >= 0; i -- ){
		if(!is_ancestor(climb[i][u], v))
			u = climb[i][u];
	}
	return climb[0][u];
}

void Query(){
	int a, b;
	scanf("%d %d", &a, &b);
	ll answer = dist[a] + dist[b] - 2 * dist[lca(a, b)];
	
	for(int i = 0;i < ver.size(); i ++ )
		answer = min(answer, dtt[i][a] + dtt[i][b]);
	printf("%lli\n",  answer);
}


int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int v, u, d;
	for(int i = 0;i < m; i ++ ){
		cin >> v >> u >> d;
		T[v].push_back(mp(u, d));
		T[u].push_back(mp(v, d));
	}
	dfs(1, 1, 0);
	sort(ver.begin(), ver.end());
	ver.resize(unique(ver.begin(), ver.end()) - ver.begin());
	int node;
	ll ddis;
	for(int vert = 0; vert < ver.size(); vert ++ ){
		for(int j = 1;j <= n;j ++ )
			dtt[vert][j] = (ll)1e18, visit[j] = false;
		node = ver[vert];
		priority_queue<pii, vector<pii>, greater<pii>> nx;
		nx.push(mp(0, node));
		dtt[vert][node] = 0;
		while(!nx.empty()){
			node = nx.top().se;
			ddis = nx.top().fi;
			nx.pop();
			if(visit[node])
				continue;
			visit[node] = true;
			for(auto x : T[node]){
				if(ddis + x.se < dtt[vert][x.fi]){
					dtt[vert][x.fi] = ddis + x.se;
					nx.push(mp(ddis + x.se, x.fi));
				}
			}
		}
	}
	int q;
	scanf("%d", &q);
	for(int tes = 0; tes < q; tes ++ )
		Query();
	return 0;
}