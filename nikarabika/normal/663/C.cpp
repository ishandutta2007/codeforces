//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
int col[maxn];
vector<int> vec[2],
	ans;
vector<pii> E[2], adj[maxn];
bool found, bipa;
int n, m;

void dfs(int v, int cl = 0){
	col[v] = cl;
	vec[cl].PB(v);
	for(auto e : adj[v]){
		int u = e.L;
		if(col[u] == -1)
			dfs(u, (cl + e.R) & 1);
		else if(col[u] != ((cl + e.R) & 1))
			bipa = false;
	}
	return;
}

void solve(int id){
	for(auto e : E[id])
		adj[e.L].PB(MP(e.R, 0)),
			adj[e.R].PB(MP(e.L, 0));
	for(auto e : E[1 - id])
		adj[e.L].PB(MP(e.R, 1)),
			adj[e.R].PB(MP(e.L, 1));
	vector<int> thisans;
	bipa = true;
	memset(col, -1, sizeof col);
	for(int i = 0; i < n; i++)
		if(col[i] == -1){
			vec[0].clear();
			vec[1].clear();
			dfs(i);
			if(sz(vec[0]) > sz(vec[1]))
				swap(vec[0], vec[1]);
			for(auto val : vec[0])
				thisans.PB(val);
		}
	if(bipa){
		if(!found)
			ans = thisans;
		else if(sz(thisans) < sz(ans))
			ans = thisans;
		found = true;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		char th;
		cin >> fi >> se >> th;
		fi--, se--;
		E[th == 'B'].PB(MP(fi, se));
	}
	solve(0);
	for(int i = 0; i < n; i++)
		adj[i].clear();
	solve(1);
	if(found){
		cout << sz(ans) << '\n';
		for(auto val : ans)
			cout << val + 1 << ' ';
	}
	else
		cout << -1;
	return 0;
}