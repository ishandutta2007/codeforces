#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6)+10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18)+10;
ll modulo = 998244353;

/*
ll Mn[MAX][22][2][2]; // i - node , j - (1<<j), k - which graph, l - with/without switch
ll LCA[MAX][23];
ll dep[MAX];
vector<ll> g[2][MAX];
void dfs(ll hd, ll kd){
	fori(g[hd][kd].size()){	
		ll hr = g[hd][kd][i];
		if(hr == LCA[hd][0])
			continue;
		LCA[hr][0] = hd;
		dep[hr]    = dep[hd]+1;
		dfs(hr);
	}
}
void pre(ll n){
		for(ll j=1; j<23; j++)
			fori(n)
				LCA[i][j] = LCA[LCA[i][j-1]][j-1];
}
ll lca(ll a,ll b){
	if(dep[b] > dep[a])											swap(a,b);
	for(ll j=22; j>-1; j--)	if(dep[LCA[a][j]] >= dep[b])	a = LCA[a][j];
	for(ll j=22; j>-1; j--)	if(LCA[a][j]!=LCA[b][j])		a = LCA[a][j], b = LCA[b][j];
	return (a==b) ? a : LCA[a][0];
}

*/
ll arr[MAX];
ll dp[MAX][2]; // limited by 0 - same dudes, 1- different dudes , our "-1" seq is of length i
ll has = 1;
void pre(ll k){
	dp[1][0] = k-1;
	dp[1][1] = k-2;
	for(ll i=2; i<MAX; i++){
		dp[i][0] = (k-1)*dp[i-1][1];
		dp[i][1] = dp[i-1][0] + (k-2)*dp[i-1][1];
		forj(2)
			dp[i][j]%=modulo;
	}
}
void handle(ll st, ll n, ll k){
	while(st<n){
		ll sy = 0;
		ll pv = st;
		while(st<n && arr[st] == -1)
			++sy, st+=2;
		if(pv<=1){
			if(st >= n){
				has*=k, has%=modulo;
				fori(sy-1)
					has*=(k-1), has%=modulo;
			}
			else{
				fori(sy)
					has*=(k-1), has%=modulo;
			}
		}
		else if(st>=n){
			fori(sy)
				has*=(k-1), has%=modulo;
		}
		else
			has*=dp[sy][arr[pv-2] != arr[st]], has%=modulo;
		while(st<n && arr[st] != -1){
			if(arr[st] == arr[st+2])
				has=0;
			st+=2;
		}
	}
}
void deal(){
	ll n, k;
	cin>>n>>k;
	fori(n)
		cin>>arr[i];
	pre(k);
	handle(0, n, k);
	handle(1, n, k);
	cout<<has;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1