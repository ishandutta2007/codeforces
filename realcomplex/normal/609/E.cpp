#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<ll, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define int ll

const int N = (int)2e5 + 9;
const int LG = 20;

struct Edge{
	int from;
	int to;
	int wei;
	int idx;
	bool operator< (Edge to){
		return wei < to.wei;
	}
};

vector<pii> T[N];

int sz[N];
int pi[N];

int fin(int a){
	if(a == pi[a])
		return a;
	return pi[a] = fin(pi[a]);
}

bool merge(int a, int b){
	a = fin(a);
	b = fin(b);
	if(a == b){
		return false;
	}
	if(sz[a] > sz[b])
		swap(a, b);
	pi[a] = b;
	sz[b] += sz[a];
	return true;
}

int up[N][LG];
int mx[N][LG];

int tin[N];
int tout[N];
int cnt;
int dep[N];

void dfs(int u, int pr, int cmax){
	tin[u] = cnt ++ ;
	up[u][0] = pr;
	mx[u][0] = cmax;
	for(int j = 1; j < LG; j ++ ){
		up[u][j] = up[up[u][j - 1]][j - 1];
		mx[u][j] = max(mx[u][j - 1], mx[up[u][j - 1]][j - 1]);
	}
	for(auto x : T[u]){
		if(x.fi != pr){
			dep[x.fi] = dep[u] + 1;
			dfs(x.fi, u, x.se);
		}
	}
	tout[u] = cnt - 1;
}

bool is_ancestor(int a, int b){
	return (tin[a] <= tin[b] && tout[a] >= tin[b]);
}

int query(int a, int b){
	if(is_ancestor(b, a))
		swap(b, a);
	if(is_ancestor(a, b)){
		int amx = 0;
		for(int j = LG - 1; j >= 0 ; j -- ){
			if(!is_ancestor(up[b][j], a)){
				amx = max(amx, mx[b][j]);
				b = up[b][j];
			}
		}
		amx = max(amx, mx[b][0]);
		return amx;
	}
	int amx = 0;
	for(int j = LG - 1; j >= 0 ; j -- ){
		if(!is_ancestor(up[a][j], b)){
			amx = max(amx, mx[a][j]);
			a = up[a][j];
		}
	}
	for(int j = LG - 1; j >= 0 ; j -- ){
		if(!is_ancestor(up[b][j], a)){
			amx = max(amx, mx[b][j]);
			b = up[b][j];
		}
	}
	amx = max(amx, mx[a][0]);
	amx = max(amx, mx[b][0]);
	return amx;
}

signed main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ){
		sz[i] = 1;
		pi[i] = i;
	}
	Edge E[m];
	ll ans[m];
	int v[m], u[m], ws[m];
	for(int i = 0 ;i <  m ; i ++ ){
		cin >> E[i].from >> E[i].to >> E[i].wei;
		v[i] = E[i].from;
		u[i] = E[i].to;
		ws[i] = E[i].wei;
		E[i].idx = i;
		ans[i] = -1;
	}
	sort(E, E + m);
	ll answ = 0;
	for(int i =0 ; i < m ;i ++ ){
		if(merge(E[i].from, E[i].to)){
			T[E[i].from].push_back(mp(E[i].to, E[i].wei));
			T[E[i].to].push_back(mp(E[i].from, E[i].wei));
			answ += E[i].wei;
			ans[E[i].idx] = 0;
		}
	}
	for(int i = 0 ; i < m ; i ++ ){
		if(ans[i] == 0)
			ans[i] = answ;
	}
	dfs(1, 1, 0);
	ll curr;
	for(int i = 0 ; i < m ; i ++ ){
		if(ans[i] == -1){
			curr = answ;
			curr += ws[i];
			curr -= query(v[i], u[i]);
			ans[i] = curr;
		}
		cout << ans[i] << "\n";
	}
	return 0;
}