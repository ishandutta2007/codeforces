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

const int maxn = 200 + 10,
	  maxm = maxn * 100;
bool mark[maxm],
	 dir[maxm];
vector<int> adj[maxn];
int frm[maxm],
	too[maxm],
	n, m;

void dfs(int u, int e = -1){
	while(sz(adj[u])){
		int eid = adj[u].back();
		adj[u].pop_back();
		if(mark[eid]) continue;
		mark[eid] = true;
		int v = frm[eid]^too[eid]^u;
		dfs(v, eid);
	}
	if(~e) dir[e] = frm[e] == u;
}

void solve(void){
	memset(mark, false, sizeof mark);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		adj[i].clear();
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se, fi--, se--;
		adj[fi].PB(i);
		adj[se].PB(i);
		frm[i] = fi;
		too[i] = se;
	}
	int mm = m, lst = -1, nn = n;
	for(int i = 0; i < n; i++)
		if(sz(adj[i]) & 1){
			nn--;
			if(lst == -1)
				lst = i;
			else{
				frm[mm] = lst;
				too[mm] = i;
				adj[lst].PB(mm);
				adj[i].PB(mm);
				mm++;
				lst = -1;
			}
		}
	for(int i = 0; i < n; i++)
		if(sz(adj[i]))
			dfs(i);
	cout << nn << '\n';
	for(int i = 0; i < m; i++){
		if(dir[i]) swap(too[i], frm[i]);
		cout << 1+too[i] << ' ' << 1+frm[i] << '\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}