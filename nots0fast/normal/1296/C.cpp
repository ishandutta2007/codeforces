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
#define MAX  (int)(3*pow(10,6) + 10)
#define ld long double
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,9);
ll modulo = pow(10,9)+7;


ll dx[4] = {-1, 0 , 1, 0};
ll dy[4] = {0, -1, 0 , 1};
string dir = "LURD";

void deal(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string a;
		cin>>a;
		map<ll,map<ll, vector<ll> > > all;
		ll x =0 , y = 0;
		all[x][y].pb(0);
		for(ll i = 1; i<=a.length(); i++){
			ll wh = dir.find(a[i-1]);
			x+=dx[wh];
			y+=dy[wh];
			all[x][y].pb(i);
		}
		ll mn = inf, lz1 = -1, lz2 = -1;
		for(auto& el1 : all){
			for(auto& el2 : el1.ss){
				for(ll i = 1; i<el2.ss.size(); i++){
					if(el2.ss[i] - el2.ss[i-1] < mn){
						lz2 = el2.ss[i];
						lz1 = el2.ss[i-1]+1;
						mn = lz2 - lz1;
					}
				}
			}
		}
		if(mn == inf){
			cout<<-1<<'\n';
		}
		else{
			cout<<lz1<<' '<<lz2<<'\n';
		}
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}