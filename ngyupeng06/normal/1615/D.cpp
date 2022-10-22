#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, a, b, c, p[200005], pp[200005];
vector<ll> v[200005][2];
vector<pll> adj[200005];
ll val[200005];
bool gd = true;

int findSet(int id) { 
	return (p[id] == id) ? id : (p[id] = findSet(p[id])); 
} 


void dfs(int x, int par){
	p[x] = par;
	if (val[x] == -1) val[x] = 0;
	for (int i=0; i<2; i++){
		for (auto it : v[x][i]){
			if (val[it] == -1){
				val[it] = (val[x]+i)%2;
				dfs(it, par);
			}
			else if (val[it] != (val[x]+i)%2) gd = false;
		}
	}
}

void dfs1(int x, int par){
	for (auto it : adj[x]){
		if (it.first == par) continue;
		if (it.second != -1){
			cout << x << " " << it.first << " " << it.second << "\n";
			dfs1(it.first, x);
		}
		else {
			cout << x << " " << it.first << " " << (val[x]+val[it.first])%2 << "\n";	
			dfs1(it.first, x);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		for (int i=1; i<=n; i++){
			v[i][0].clear();
			v[i][1].clear();
			adj[i].clear();
			val[i] = -1;
			p[i] = i;
			pp[i] = -1;
		}
		gd = true;
		for (int i=0; i<n-1; i++){
			cin >> a >> b >> c;
			if (c!=-1){		
				ll x = c, cnt = 0;
				while(x>0){
					if (x%2) cnt++;
					x/=2;
				}
				cnt%=2;
				v[a][cnt].pb(b);
				v[b][cnt].pb(a);
			}
			adj[a].pb(mp(b,c));
			adj[b].pb(mp(a,c));
		}
		for (int i=0; i<m; i++){
			cin >> a >> b >> c;
			v[a][c].pb(b);
			v[b][c].pb(a);
		}
		for (int i=1; i<=n; i++){
			if (val[i]==-1){
				dfs(i,i);
			}
		}
		if (!gd){
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			dfs1(1,-1);
		}
	}
}