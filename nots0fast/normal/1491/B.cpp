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
#define double long double
#define MAX (int)(pow(10,5) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;




void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, u,v;
		cin>>n>>u>>v;
		vector<ll> arr(n);
		fori(n){
			cin>>arr[i];
		}
		bool diffBiggerThanOne = 0;
		fori(n-1){
			if(fabs(arr[i] - arr[i+1]) > 1 ){
				diffBiggerThanOne = 1;
			}
		}
		if(diffBiggerThanOne){
			cout<<0<<'\n';
		}
		else{
			bool allEq = 1;
			fori(n-1){
				if(arr[i] != arr[i+1]){
					allEq = 0;
				}
			}
			ll ans;
			if(allEq){
				ans = min(2*v, u+v);
			}
			else{
				ans = min(u,v);
			}
			cout<<ans<<'\n';
		}
	}
}




int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}