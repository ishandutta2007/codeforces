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

const int maxn = 2e5 + 85 - 69;
set<int> vvec, uvec, esht;
vector<int> adj[maxn];
vector<pii> ans,
	vecans[maxn];
bool mark[maxn],
	 molmark[maxn];
int comcnt, n, m, su, sy, dt, ds;
int com[maxn];

void dfs(int u){
	mark[u] = true;
	com[u] = comcnt;
	for(auto v : adj[u])
		if(!mark[v])
			dfs(v), vecans[comcnt].PB(MP(u, v));
	return;
}

void print(pii P){
	cout << P.L + 1 << ' ' << P.R + 1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	cin >> su >> sy >> ds >> dt;
	su--, sy--;
	bool isaj = find(all(adj[su]), sy) != adj[su].end();
	if(isaj){
		adj[su].erase(find(all(adj[su]), sy));
		adj[sy].erase(find(all(adj[sy]), su));
	}
	mark[su] = mark[sy] = true;
	for(int i = 0; i < n; i++)
		if(!mark[i])
			comcnt++, dfs(i);
	for(auto u : adj[su])
		uvec.insert(com[u]);
	for(auto u : adj[sy])
		vvec.insert(com[u]);
	for(auto val : uvec)
		if(vvec.find(val) == vvec.end())
			ds--;
		else
			esht.insert(val);
	for(auto val : vvec)
		if(uvec.find(val) == uvec.end())
			dt--;
	if(ds <= 0 or dt <= 0){
hell:
		cout << "No" << endl;
		return 0;
	}
	for(auto u : adj[su])
		if(!molmark[com[u]] and esht.find(com[u]) == esht.end())
			ans.PB(MP(su, u)), molmark[com[u]] = true;
	for(auto u : adj[sy])
		if(!molmark[com[u]] and esht.find(com[u]) == esht.end())
			ans.PB(MP(sy, u)), molmark[com[u]] = true;
	if(!isaj){
		if(ds + dt <= sz(esht) or sz(esht) == 0)
			goto hell;
bokhor:
		for(auto u : adj[su])
			if(!molmark[com[u]] and ds and esht.find(com[u]) != esht.end()){
				molmark[com[u]] = true;
				ans.PB(MP(su, u));
				ds--;
			}
		for(auto u : adj[sy])
			if(molmark[com[u]] and esht.find(com[u]) != esht.end()){
				ans.PB(MP(sy, u));
				break;
			}
		for(auto u : adj[sy])
			if(!molmark[com[u]] and esht.find(com[u]) != esht.end()){
				molmark[com[u]] = true;
				ans.PB(MP(sy, u));
			}
	}
	else{
		if(ds + dt > sz(esht) and sz(esht))
			goto bokhor;
		if(ds + dt >= sz(esht) + 2){
			ans.PB(MP(su, sy));
			ds--, dt--;
			for(auto u : adj[su])
				if(!molmark[com[u]] and ds and esht.find(com[u]) != esht.end()){
					molmark[com[u]] = true;
					ans.PB(MP(su, u));
					ds--;
				}
			for(auto u : adj[sy])
				if(!molmark[com[u]] and esht.find(com[u]) != esht.end()){
					molmark[com[u]] = true;
					ans.PB(MP(sy, u));
				}
		}
		else
			goto hell;
	}
	cout << "Yes\n";
	for(int i = 1; i <= comcnt; i++)
		for(auto P : vecans[i])
			print(P);
	for(auto P : ans)
		print(P);
	return 0;
}