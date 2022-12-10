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
vector<int> adj[maxn];
int col[maxn];
bool mark[maxn];
int n, m;
vector<int> vec[2];

bool dfs(int v){
	vec[col[v]].PB(v);
	mark[v] = true;
	for(auto u : adj[v]){
		if(!mark[u]){
			col[u] = 1-col[v];
			if(!dfs(u))
				return false;
		}
		else if(col[u] != 1-col[v])
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 0; i < n; i++)
		if(!mark[i])
			if(!dfs(i)){
				cout << -1 << endl;
				return 0;
			}
	for(int i = 0; i < 2; i++){
		cout << sz(vec[i]) << '\n';
		for(auto val : vec[i])
			cout << val+1 << ' ';
		cout << '\n';
	}
	return 0;
}