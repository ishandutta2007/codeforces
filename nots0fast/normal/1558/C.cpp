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
ll modulo = 998244353;
ld eps = 1e-13;


void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<ll> arr(n);
		fori(n){
			cin>>arr[i];
		}
		bool bad = 0;
		fori(n){
			if( (arr[i] % 2) == (i%2)){
				bad = 1;
			}
		}
		if(bad){
			cout<<-1<<'\n';
			continue;
		}
		vector<ll> op;
		for(ll i = 1; i<n; i+=2){
			ll lz;
			forj(n){
				if(arr[j] == i){
					lz = j;
				}
			}
			op.pb(lz+1);
			reverse(arr.begin(), arr.begin() + lz + 1);
			forj(n){
				if(arr[j] == i+1){
					lz = j;
				}
			}
			op.pb(lz);
			reverse(arr.begin(), arr.begin() + lz);
			op.pb(lz+2);
			reverse(arr.begin(), arr.begin() + lz + 2);
			op.pb(3);
			reverse(arr.begin(), arr.begin() + 3);
			op.pb(n-i+1);
			reverse(arr.begin(), arr.begin() + n - i + 1);
		}
		op.pb(n);
		reverse(arr.begin(), arr.end());
		cout<<op.size()<<'\n';
		for(auto& el : op){
			cout<<el<<' ';
		}
		cout<<'\n';
	}
}
 
 
int main(){
 	cin.tie(0);
 	ios_base::sync_with_stdio(0);
	deal();
}