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
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 10)
const ll inf = pow(10, 9);
ll INF = 1e9;
ll modulo = 998244353;
ld eps = 1e-9;


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
		vector<ll > cur;
		fori(n){
			if(arr[i] == 1){
				cur.pb(1);
			}
			else{
				while(cur[(ll)cur.size()-1] != arr[i] - 1){
					cur.erase(cur.end()-1);
				}
				cur.erase(cur.end()-1);
				cur.pb(arr[i]);
			}
			string ans = "";
			ll sz = cur.size();
			forj(sz){
				ans+=to_string(cur[j]);
				if(j!=sz-1){
					ans+='.';
				}
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