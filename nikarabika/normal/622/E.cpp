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

const int maxn = 5e5 + 85 - 69;
int leacnt[maxn * 2], lea, n;
vector<int> adj[maxn];

int dfs(int v, int h = 0, int p = -1){
	if(sz(adj[v]) == 1)
		lea++, leacnt[h]++;
	int ret = -1;
	for(auto u : adj[v])
		if(u != p)
			smax(ret, dfs(u, h + 1, v));
	return max(ret, h);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	int ans = -1;
	for(auto v : adj[0]){
		int maxh = dfs(v, 0, 0);
		int cnt = 0;
		int i;
		for(i = 0; lea; i++){
			if(leacnt[i] == 0 and cnt)
				cnt--, lea--;
			if(leacnt[i])
				cnt += leacnt[i] - 1, lea--;
		}
		smax(ans, i);
		for(int i = 0; i <= maxh; i++)
			leacnt[i] = 0;
		lea = 0;
	}
	cout << ans << endl;
	return 0;
}