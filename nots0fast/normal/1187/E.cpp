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
#define pb(a) push_back(a)
#define PI 2*acos(0)
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll inf =  pow(10,9);
ll modulo = 163577857;
#define MAX 200100
#define MAX2 30

vector<ll> g[MAX];
ll dp[MAX];
ll sz[MAX];


void dfs1(ll hd, ll pr){
	sz[hd]++;
	for(auto hr : g[hd]){
		if(hr == pr)
			continue;
		dfs1(hr, hd);
		dp[hd] += dp[hr] + sz[hr];
		sz[hd] += sz[hr];
	}
}

void dfs2(ll hd, ll pr, ll n){
	for(auto hr : g[hd]){
		if(hr == pr)
			continue;
		dp[hr] = dp[hr] + (dp[hd] - (dp[hr] + sz[hr]) + (n-sz[hr])); 
		dfs2(hr, hd, n);
	}
}


void deal(){
	ll n;
	cin>>n;
	fori(n-1){
		ll a, b;
		cin>>a>>b;
		--a, --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs1(0, -1);
	dfs2(0, -1, n);
	ll mx = 0;
	fori(n)
		mx = max(mx, dp[i]);
	cout<<mx+n;
}	


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}