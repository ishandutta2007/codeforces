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
#define double long double
#define MAX (int)(pow(10,6) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, w;
		cin>>n>>w;
		vector<ll> arr(n);
		fori(n){
			cin>>arr[i];
		}
		sort(arr.begin(), arr.end());
		ll s = 0;
		fori(n){
			s+=arr[i];
			if(s == w){
			
				if(i == n-1){
					break;
				}
			
				s = (s-arr[0] + arr[n-1]);
				
				ll one = arr[0];
				ll lst = arr[n-1];
				
				arr.erase(arr.begin());
				arr.insert(arr.begin() + i, lst);
				arr[n-1] = one;
				
				if(s == w){
					break;
				}
			}
			
		}
		
		if(s == w){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
			fori(n){
				cout<<arr[i]<<' ';
			}
			cout<<'\n';
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}