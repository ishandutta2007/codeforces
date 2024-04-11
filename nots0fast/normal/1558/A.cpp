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
		ll a, b;
		cin>>a>>b;
		ll gm = a+b;
		set<ll> pos;
		for(ll i = 0; i<=a; i++){
			// Bob broke it i times is it possible ?
			for(ll j = 0; j<2; j++){
				ll bob = gm/2;
				ll alice = gm - bob;
				if(j){
					swap(bob, alice);
				}
				if(i <= alice && a-i<=bob){
					ll other = bob - (a-i);
					pos.insert(other+i);
				}
			}
		}
		cout<<pos.size()<<'\n';
		for(auto& el : pos){
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