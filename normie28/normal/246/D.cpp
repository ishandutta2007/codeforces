#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
using namespace std;
typedef long long ll;
const int MAX = 1e6 + 10;
const int MAXI = INT_MAX;
ll n, m, col[MAX], u, v, mn = MAXI;
vector <ll> adj[MAX];
map < pair <ll, ll >, bool> khara;
set <ll> arr[MAX];
bool vis[MAX];
void DFS (ll v) {
	if (vis[v]) return ;
	vis[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		ll u = adj[v][i];
		if (col[v] != col[u]) arr[col[v]].insert(col[u]);
		DFS(u);
	}
}
 
int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> col[i];
		mn = min (mn, col[i]);
	}
	while (m--) {
		cin>>u>>v;
		if (khara[mp(u, v)] || u == v || khara[mp(v, u)]) continue;
		adj[u].pb(v);
		adj[v].pb(u);
		khara[mp(u, v)] = true;
		khara[mp(v, u)] = true;
	}
	for (int i = 1; i <= n; i++) 
		DFS(i);
	pair <ll, ll> ans = mp(0, 0);
	for (int i = 1; i <= n; i++)
		ans.F = max(ans.F, ll(arr[col[i]].size()));
	if (ans.F == 0) cout << mn << endl;
	else {
		ll ret = MAXI;
		for (ll i = 1; i <= n; i++) {
			if (arr[col[i]].size() == ans.F)
				ret = min (ret, col[i]);
		}
		cout << ret << endl;
	}
}