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
#define MAX (int)(pow(10,5) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

set<ll> taken;
vector<ll> ans;


void deal(){
	ll n, x;
	cin>>n>>x;
	taken.insert(0);
	taken.insert(x);
	ll last = 0;
	fori(1<<n){
		ll xr = i;
		auto it = taken.find(xr);
		auto it1 = taken.find(xr^x);
		if(it != taken.end() || it1 != taken.end())
			continue;
		ll cur = i^last;
		ans.pb(cur);
		taken.insert(xr);
		taken.insert(xr^x);
		last = i;
	}
	cout<<ans.size()<<'\n';
	fori(ans.size())
		cout<<ans[i]<<' ';
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