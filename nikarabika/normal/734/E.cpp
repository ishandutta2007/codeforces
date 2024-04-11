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
int mn[maxn][2][2],
	dow[maxn],
	ans[maxn],
	n;
bool col[maxn];
vector<int> adj[maxn];

void dfs1(int u, int p = -1){
	dow[u] = 0;
	for(auto v : adj[u]) if(v^p){
		dfs1(v, u);
		int x = col[u]^col[v];
		int tmp = dow[v] + x;
		smax(dow[u], tmp);
		for(int i = 0; i < 2; i++)
			if(mn[u][x][i] < tmp)
				swap(mn[u][x][i], tmp);
	}
}

int get0(int u, int v){
	if(col[u]^col[v]) return mn[u][0][0];
	if(mn[u][0][0] == dow[v]) return mn[u][0][1];
	return mn[u][0][0];
}

int get1(int u, int v){
	if(col[u]^col[v]^1) return mn[u][1][0];
	if(mn[u][1][0] == dow[v] + 1) return mn[u][1][1];
	return mn[u][1][0];
}

void dfs2(int u, int p = -1, int up = 0){
	ans[u] = max(dow[u], up);
	for(auto v : adj[u]) if(v^p){
		int x = col[u] ^ col[v];
		int nup = up + x;
		dfs2(v, u, max(nup, max(get0(u, v), get1(u, v)) + x));
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> col[i];
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs1(0);
	dfs2(0);
	cout << *min_element(ans, ans + n) << endl;
	return 0;
}