#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, int> pli;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smax(x, y) (x) = max((x), (y))

const int maxn = 210;
vector<int> adj[maxn];
bool orgmark[maxn], mark[maxn];
int n;
LL ans;

pli find_farest(int v, bool an, int p = -1){
	if(an) mark[v] = true;
	pli ret = {0, v};
	for(auto u : adj[v])
		if(!orgmark[u] and u != p){
			pli x = find_farest(u, an, v);
			smax(ret, MP(x.L + 1, x.R));
		}
	return ret;
}

LL find_ans(void){
	memset(mark, false, sizeof mark);
	LL ret = 0;
	for(int i = 1; i <= n; i++)
		if(!orgmark[i] and !mark[i]){
			int v = find_farest(i, 0).R;
			smax(ret, find_farest(v, 1).L);
		}
	return ret;
}

void dfs(int v, int p = -1, LL len = 0){
	orgmark[v] = true;
	smax(ans, find_ans() * len);
	for(auto u : adj[v])
		if(u != p)
			dfs(u, v, len + 1);
	orgmark[v] = false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 1; i <= n; i++)
		dfs(i);
	cout << ans << endl;
	return 0;
}