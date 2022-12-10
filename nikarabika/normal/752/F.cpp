//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 2e5 + 85 - 69;
int cent = -1,
	n, k;
int dn[maxn];
vector<int> adj[maxn],
	vec[maxn];
set<pii> s;
bool mark[maxn];

void dfs0(int u, int p = -1){
	for(auto v : adj[u])
		if(v ^ p){
			dfs0(v, u);
			dn[u] += dn[v];
		}
	if(!~cent and dn[u] >= k)
		cent = u;
	return;
}

void dfs1(int u, int p, int rt){
	for(auto v : adj[u])
		if(v ^ p)
			dfs1(v, u, rt);
	if(mark[u])
		vec[rt].PB(u);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 0; i < k+k; i++){
		int fi;
		cin >> fi, fi--;
		dn[fi] = mark[fi] = 1;
	}
	dfs0(0);
	for(auto v : adj[cent])
		dfs1(v, cent, v);
	adj[cent].PB(cent);
	if(mark[cent]) vec[cent].PB(cent);
	for(auto v : adj[cent])
		s.insert(MP(sz(vec[v]), v));
	cout << 1 << '\n'
		<< cent+1 << '\n';
	while(sz(s) and s.begin()->L == 0) s.erase(s.begin());
	while(sz(s)){
		int u = s.rbegin()->R;
		s.erase(MP(sz(vec[u]), u));
		int v = s.rbegin()->R;
		s.erase(MP(sz(vec[v]), v));
		cout << vec[u].back() + 1 << ' ' << vec[v].back() + 1 << ' ' << cent + 1 << '\n';
		vec[u].pop_back();
		vec[v].pop_back();
		if(sz(vec[u])) s.insert(MP(sz(vec[u]), u));
		if(sz(vec[v])) s.insert(MP(sz(vec[v]), v));
	}
	return 0;
}