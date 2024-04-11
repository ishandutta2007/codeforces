#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<(ll)v; i++)
#define forj(v) for(ll j=0; j<(ll)v; j++)
#define fork(v) for(ll k=0; k<(ll)v; k++)
#define forl(v) for(ll l=0; l<(ll)v; l++)
#define fort(v) for(ll t=0; t<(ll)v; t++)
#define forz(v) for(ll z=0; z<(ll)v; z++)
#define forx(v) for(ll x=0; x<(ll)v; x++)
#define fory(v) for(ll y=0; y<(ll)v; y++)
#define ll long long
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 10)
ll INF = 0x3f3f3f3f;
ll inf = pow(10,9);
ll modulo = 998244353;
ld eps = 1e-6;


void popit(ll tim, ll upto , multimap<ll,ll>& when, ll& s){
	while(tim != upto && when.size() ){
		auto it = when.end();
		--it;
		s+=(tim - (*it).ss)*(*it).ff;
		when.erase(it);
		++tim;	
	}
	
}


void deal(){
	ll n;
	cin>>n;
	map<ll,vector<ll> > all;
	vector<ll> arr(n);
	ll tim = inf;
	fori(n){
		cin>>arr[i];
		tim  = min(tim, arr[i]);
	}
	fori(n){
		ll ed;
		cin>>ed;
		all[arr[i]].pb(ed);
	}
	ll s = 0;
	multimap<ll, ll> when;
	for(auto& el : all){
		popit(tim, el.ff, when, s);
		tim = el.ff;
		fori(el.ss.size()){
			when.insert(mp(el.ss[i], el.ff));
		}
	}
	popit(tim, (ll)pow(10,10), when, s);
	cout<<s;
}
  
  
  
  
  
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}