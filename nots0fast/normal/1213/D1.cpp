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
#define MAX (int)(pow(10,6)+10)
#define pb(a) push_back(a)
#define ld long double
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;

void deal(){
	ll n,k;
	cin>>n>>k;
	map<ll, vector<ll> > dist;
	fori(n){
		ll ed;
		cin>>ed;
		ll cnt = 0;
		dist[ed].pb(0);
		while(ed){
			ed/=2;
			++cnt;
			dist[ed].pb(cnt);
		}
	}
	ll mn = inf;
	for(auto& el : dist){
		auto dt = el.ss;
		if(dt.size() >= k){
			ll s = 0;
			sort(dt.begin(),dt.end());
			forj(k)
				s+=dt[j];
			mn =min(mn,s);
		}
	}
	cout<<mn;
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}