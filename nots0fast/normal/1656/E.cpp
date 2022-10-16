#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define ll long long
#define double long double
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10, 18);
ll modulo = inf;
double eps = 1e-10;
ifstream in;
ofstream out;

void dfs(ll hd, ll pr, vector<vector<ll> >& g, vector<ll>& dep, vector<ll>& dp, vector<ll>& val){
	ll s = 0;
	for(auto& hr : g[hd]){
		if(hr == pr){
			continue;
		}
		dep[hr] = dep[hd] + 1;
		dfs(hr, hd, g, dep, dp, val);
		s += dp[hr];
	}
	
	if(dep[hd] == 0){
		val[hd] = -s;
		dp[hd] = 0;
	}
	else if(dep[hd] % 2 == 0){
		val[hd] = -s + 1;
		dp[hd] = 1;
	}
	else{
		val[hd] = -s - 1;
		dp[hd] = -1;
	}
}


void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<vector<ll> > g(n);
		vector<ll> dp(n);
		vector<ll> dep(n, 0);
		vector<ll> val(n);
		fori(n-1){
			ll ai, bi;
			cin>>ai>>bi;
			--ai, --bi;
			g[ai].pb(bi);
			g[bi].pb(ai);
		}
		dfs(0, -1, g, dep, dp, val);
		fori(n){
			cout<<val[i]<<' ';
		}
		cout<<'\n';
	}
}
	

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}