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

const int maxn = 1e5 + 10;
char ans[maxn];
bool fnd[maxn];
int siz[maxn],
	n, cent;
vector<int> adj[maxn];

void dfs(int u, int p, int sz){
	siz[u] = 1;
	for(auto v : adj[u])
		if((v^p) and !fnd[v]){
			dfs(v, u, sz);
			siz[u] += siz[v];
		}
	if((cent >> 31) and siz[u] >= (sz + 1) / 2)
		cent = u;
}

void go(int u, int sz = n, char c = 'A'){
	cent = -1;
	dfs(u, -1, sz);
	u = cent;
	fnd[u] = true;
	ans[u] = c++;
	for(auto v : adj[u])
		if(!fnd[v]){
			if(siz[v] > siz[u])
				go(v, sz - siz[u], c);
			else
				go(v, siz[v], c);
		}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1, fi, se; i < n; i++){
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	go(0);
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}