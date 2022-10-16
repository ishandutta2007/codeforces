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
#define ll int
#define double long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,7) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9);
ll modulo = pow(10,9)+7;
 
 
 
void deal(){
	ll t = 1;
//	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<pair<ll,ll> > arr(n);
		set<pair<ll,ll> > all;
		fori(n){
			cin>>arr[i].ff>>arr[i].ss;
		}
		for(ll i = 1; i<=n; i++){
			all.insert(mp(arr[i%n].ff-arr[i-1].ff, arr[i%n].ss - arr[i-1].ss));
			all.insert(mp(-(arr[i%n].ff-arr[i-1].ff), -(arr[i%n].ss - arr[i-1].ss)));
			
		}
		if(all.size() == n){
			cout<<"yes";
		}
		else{
			cout<<"no";
		}
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}