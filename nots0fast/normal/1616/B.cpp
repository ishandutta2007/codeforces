/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
*/

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
#define mt make_tuple
const ll INF = 0x3f3f3f3f;
const ll inf =  1e18;
const ll modulo = pow(10, 9) + 7;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		string a;
		cin>>n>>a;
		string ans = "";
		if(n == 1){
			ans = a + a;
		}
		else{
			if(a[1] < a[0]){
				ll id = 0;
				string cr = "";
				cr += a[0];
				while(id + 1 <  n && a[id+1] <= a[id]){
					++id;
					cr += a[id];
				}
				ans += cr;
				reverse(cr.begin(), cr.end());
				ans += cr;
			}
			else{
				ans += a[0];
				ans += a[0];
			}
		}
		cout<<ans<<'\n';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}