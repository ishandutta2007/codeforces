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
bool noe[maxn];
bool mark[maxn];
int sw[maxn][2];
vector<pair<int, bool> > adj[maxn];
int ty[maxn];
int n, m;

void dfs(int u){
	mark[u] = true;
	for(auto e : adj[u])
		if(!mark[e.L]){
			noe[e.L] = noe[u] ^ e.R;
			dfs(e.L);
		}
		else if(noe[e.L] ^ noe[u] ^ e.R){
			cout << "NO";
			exit(0);
		}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(sw, -1, sizeof sw);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> ty[i], ty[i] ^= 1;
	for(int i = 0; i < m; i++){
		int cnt;
		cin >> cnt;
		while(cnt--){
			int x;
			cin >> x;
			x--;
			if(sw[x][0] == -1) sw[x][0] = i;
			else sw[x][1] = i;
		}
	}
	for(int i = 0; i < n; i++){
		adj[sw[i][0]].PB(MP(sw[i][1], ty[i]));
		adj[sw[i][1]].PB(MP(sw[i][0], ty[i]));
	}
	for(int i = 0; i < m; i++){
		if(!mark[i])
			dfs(i);
	}
	cout << "YES";
	return 0;
}