#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 1;
vector<pii> T[N];

ll f(ll t){
	return (t * (t - 1)) / 2;
}

ll prec[N];

ll calc(ll x){
	ll l = 0ll, r = (ll)1e5;
	ll md;
	ll value;
	while(r - l > 1){
		md = (l + r) / 2;
		value = f(md);
		if(value <= x){
			l = md;
		}
		else{
			r = md;
		}
	}
	return (x * l) - prec[l];
}

bool ok[N];
vector<int> ord;

void dfs1(int u){
	if(ok[u])
		return;
	ok[u] = true;
	for(auto x : T[u]){
		dfs1(x.fi);
	}
	ord.push_back(u);
}

vector<pii> R[N];

int bel[N];
int cnt = 0;

void dfs2(int u){
	if(bel[u] != 0)
		return;
	bel[u] = cnt;
	for(auto x : R[u]){
		dfs2(x.fi);
	}
}

vector<pii> G[N];
int deg[N];

ll nval[N];
ll dp[N];

int main(){
	fastIO;
	for(int i = 1; i < N ; i ++ ){
		prec[i] = prec[i - 1] + f(i);
	}
	
	int n, m;
	cin >> n >> m;
	int u, v, w;
	for(int i = 0 ; i < m ; i ++ ){
		cin >> u >> v >> w;
		T[u].push_back(mp(v, w));
		R[v].push_back(mp(u, w));
	}
	int start;
	cin >> start;
	dfs1(start);
	int las_node;
	while(!ord.empty()){
		las_node = ord.back();
		ord.pop_back();
		if(bel[las_node] != 0)
			continue;
		++ cnt;
		dfs2(las_node);
	}
	for(int i = 1; i <= n; i ++ ){
		if(!ok[i])
			continue;
		for(auto x : T[i]){
			if(bel[i] == bel[x.fi]){
				nval[bel[i]] += calc(x.se);
			}
			else{
				G[bel[i]].push_back(mp(bel[x.fi], x.se));
				deg[bel[x.fi]] ++ ;
			}
		}
	}
	queue<int> vv;
	vv.push(bel[start]);
	dp[bel[start]] = nval[bel[start]];
	int node;
	while(!vv.empty()){
		node = vv.front();
		vv.pop();
		for(auto x : G[node]){
			dp[x.fi] = max(dp[x.fi], dp[node] + nval[x.fi] + x.se);
			deg[x.fi] -- ;
			if(deg[x.fi] == 0){
				vv.push(x.fi);
			}
		}
	}
	ll ret = 0;
	for(int i = 1; i <= n; i ++ ){
		ret = max(ret, dp[i]);
	}
	cout << ret << "\n";
	return 0;
}