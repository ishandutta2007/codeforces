#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=2e3+30,inf = 1e18;
bool visited[N];
vector <int> adj[N];
pair <int,int> co[N];
void dfs(int v){
	visited[v] = 1;
	for (int u : adj[v]){
		if (!visited[u]){
			dfs(u);
		}
	}
	return;
}
int main(){
	ll n;
	cin >> n;
	rep(i,0,n){
		cin >> co[i].X >> co[i].Y;
		rep(j,0,i){
			if (co[i].X == co[j].X || co[i].Y == co[j].Y){
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	int ans = 0;
	rep(i,0,n){
		if (!visited[i]){
			dfs(i);
			ans++;
		}
	}
	cout << ans-1;
}