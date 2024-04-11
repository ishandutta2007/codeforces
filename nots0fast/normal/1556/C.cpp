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
#define ld long double
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10, 18);
ll modulo = pow(10,9) + 7;


void deal(){
	ll n;
	cin>>n;
	vector<ll> arr(n);
	fori(n){
		cin>>arr[i];
	}
	ll tot = 0;
	fori(n){
		if(i%2 == 1){
			continue;
		}
		ll mx = 0;
		ll s = 0;
		for(ll j = i+1; j<n; j++){
			if(j%2 == 1){
				ll cur;
				ll curs = s + mx;
				if(curs >= 0){
					cur = min(arr[i] - mx, arr[j] - curs);
				}
				else{
					cur = min(arr[i]-max(-curs, mx), arr[j]);
				}
				
				if(j!=i+1){
					++cur;
				}
				cur = max(cur, (ll)0);
				
				tot += cur;
			}
			
			
			if(j%2 == 1){
				s-=arr[j];
			}
			else{
				s+=arr[j];
			}
			mx = max(mx, -s);
		}
	}
	cout<<tot;
}
 
 
int main(){
 	cin.tie(0);
 	ios_base::sync_with_stdio(0);
	deal();
}