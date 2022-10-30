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
int par[N];
vector <int> adj[N];
int dfs(int v){
	visited[v] = 1;
	int  h =0;
	for (int u : adj[v]){
		if (!visited[u]){
			h = max(h,dfs(u));
		}
	}
	return h+1;
}
int main(){
	ll n;
	cin >> n;
	rep(i,1,n+1){
		cin >> par[i];
		if (par[i] != -1){
			adj[par[i]].pb(i);
			adj[i].pb(par[i]);
		}
	}
	int h = 0;
	rep(i,1,n+1){
		if (!visited[i] && par[i] == -1){
			h = max(h,dfs(i));
		}
	}
	cout << h;
}