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
#define MAX (int)(2*pow(10,3) + 100)
ll INF = 0x3f3f3f3f;
ll inf = pow(10,9);
ll modulo = 998244353;
ld eps = 1e-6;


void deal(){
	ll n;
	cin>>n;
	map<ll,ll> all;
	fori(n){
		ll ed;
		cin>>ed;
		all[ed-i]+=ed;
	}
	ll mx = 0;
	for(auto& el : all){
		mx = max(mx, el.ss);
	}
	cout<<mx;
}
  
  
  
  
  
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}