#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
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
#define MAX (int)(3*pow(10,2) + 100)
#define pb(a) push_back(a)
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = pow(10,9) + 7;
double eps = 1e-10;
ifstream in;
ofstream out;

ll dp[MAX][MAX];
vector<ll> g[MAX];
ll par[MAX][MAX];
ll dep[MAX][MAX];
ll sz[MAX][MAX];


ll pow_mod(ll a, ll b){
	a = a%modulo;
	if(!a){
		return 0;
	}
	ll has = 1%modulo;
	for(ll i = 62; i>-1; i--){
		has*=has;
		has%=modulo;
		if(((ll)1<<i)&b)
			has*=a, has%=modulo;
	}
	return has;
}


void dfs(ll hd, ll pr, ll root){
	par[root][hd] = pr;
	sz[root][hd] = 1;
	for(auto& hr : g[hd]){
		if(hr == pr){
			continue;
		}
		dep[root][hr] = dep[root][hd] + 1;
		dfs(hr, hd, root);
		sz[root][hd]  += sz[root][hr];
	}
}

bool J(pair<ll,ll>& a, pair<ll,ll>& b){
	return dep[a.ff][a.ss] < dep[b.ff][b.ss];
}

void deal(){
	ll n;
	cin>>n;
	fori(n-1){
		ll xi, yi;
		cin>>xi>>yi;
		--xi, --yi;
		g[xi].pb(yi);
		g[yi].pb(xi);
	}
	fori(n){
		dfs(i, -1, i);
	}
	vector<pair<ll,ll> > all;
	fori(n){
		for(ll j = i+1; j<n; j++){
			all.pb(mp(i, j));
		}
	}
	sort(all.begin(), all.end(), J);
	ll ans = 0;
	fori((ll)all.size()){
		ll ai = all[i].ff, bi = all[i].ss;
		if(dep[ai][bi] == 1){
			dp[ai][bi] = sz[bi][ai] * pow_mod(n, modulo-2) % modulo;
			dp[bi][ai] = sz[ai][bi] * pow_mod(n, modulo-2) % modulo;
		}
		else{
			ll pr1 = par[ai][bi];
			ll pr2 = par[bi][ai];
			ll prob = ((1 - dp[ai][pr1] - dp[bi][pr2]) % modulo + modulo) * pow_mod(2, modulo-2) % modulo;
			dp[ai][bi] = (dp[ai][pr1] + prob) % modulo;
			dp[bi][ai] = (dp[bi][pr2] + prob) % modulo;
		}
		if(ai > bi){
			ans+=dp[ai][bi];
		}
		else{
			ans+=dp[bi][ai];
		}
		ans%=modulo;
	}
	cout<<ans;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();  
}