#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
 
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
#define lll __int128
#define pb(a) push_back(a)
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10,9);
const ll modulo = pow(10,9) + 7;

#define MAX 1'000'010

vector<ll> g[MAX];
bool ok[MAX];

void dfs(ll hd, ll pr, ll& tot){
	ok[hd] = 1;
	ll cur = 0;
	for(auto& hr : g[hd]){
		if(hr == pr){
			continue;
		}
		dfs(hr, hd, tot);
		if(ok[hr]){
			++cur;
		}
	}
	if(cur != 0){
		tot += cur-1;
		ok[hd] = 0;
	}
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		fori(n-1){
			ll u, v;
			cin>>u>>v;
			--u, --v;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		ll ans = 0;
		ll ks = 0;
		
		for(auto& el : g[0]){
			dfs(el, 0, ans);
			if(ok[el]){
				++ks;
			}
		}
		
	//	cout<<ans<<" "<<ks<<endl;
		if(ks == 0){
			ans++;
		}
		else{
			ans+=ks;
		}
		
		cout<<ans<<'\n';
		
		fori(n){
			g[i].clear();
		}
	}
}
 
int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}