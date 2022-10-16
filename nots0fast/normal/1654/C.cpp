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
#define ll long long
#define ld long double
#define pb push_back
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = 998244353 ;
double eps = 1e-6;
ifstream in;
ofstream out;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		multiset<ll> need, have;
		ll s = 0;
		fori(n){
			ll ed;
			cin>>ed;
			need.insert(ed);
			s+=ed;
		}
		have.insert(s);
		while(!need.empty()){
			auto it1 = have.end();
			auto it2 = need.end();
			--it1, --it2;
			if((*it1) > (*it2)){
				have.insert((*it1)/2);
				have.insert((*it1 + 1)/2);
				have.erase(it1);
			}
			else if((*it1) == (*it2)){
				have.erase(it1);
				need.erase(it2);
			}	
			else{
				break;
			}
		}
		if(need.empty()){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}