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
#define lll __int128
#define pb(a) push_back(a)
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10,9);
const ll modulo = pow(10,9) + 7;
 
bool check(string& a){
	bool seen = 0;
	char pv = '0';
	for(auto& f: a){
		if(f == '0'){
			if(seen){
				if(pv != f){
					return 0;
				}
			}
			else{
				seen = 1;
			}
		}
		pv = f;
	}
	return 1;
}
 
void deal(){
	ll t;
	cin>>t;
	forl(t){
		string a;
		cin>>a;
		vector<bool> seen(2, 0);
		for(auto& f : a){
			seen[f-'0'] = 1;
		}
		ll ans;
		if(seen[0]){
			if(seen[1]){
				if(check(a)){
					ans = 1;
				}
				else{
					ans = 2;
				}
			}
			else{
				ans = 1;
			}
		}
		else{
			ans = 0;
		}
		cout<<ans<<'\n';
	}
}
 
int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}