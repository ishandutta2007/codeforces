//sobskdrbhvk
//remember the flight, the bird dies ):(
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
bool mark[maxn],
	 mark2[maxn];
int col[maxn],
	cnt[maxn],
	n, m, k;
vector<int> adj[maxn];
set<pii> s;

void dfs1(int u){
	mark[u] = true;
	s.erase(MP(cnt[col[u]], u));
	cnt[col[u]]++;
	s.insert(MP(cnt[col[u]], u));
	for(auto v : adj[u])
		if(!mark[v])
			dfs1(v);
	return;
}

void dfs2(int u){
	mark2[u] = true;
	cnt[col[u]] = 0;
	for(auto v : adj[u])
		if(!mark2[v])
			dfs2(v);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> col[i], col[i]--;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	int ans = n;
	for(int i = 0; i < n; i++)
		if(!mark[i]){
			s.clear();
			dfs1(i);
			ans -= s.rbegin()->L;
			dfs2(i);
		}
	cout << ans << '\n';
	return 0;
}