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
#define MAX (int)(2*pow(10,7) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9) + 7;


void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<ll> wh(n);
		vector<ll> a1(n), a2(n);
		fori(n){
			cin>>a1[i];
			--a1[i];
		}
		fori(n){
			cin>>a2[i];
			--a2[i];
		}
		fori(n){
			wh[a1[i]] = a2[i];
		}
		vector<bool> seen(n, 0);
		ll tot = 1;
		fori(n){
			if(wh[i] == i){
				tot = 0;
			}
			if(!seen[i]){
				ll cr = i;
				while(!seen[cr]){
					seen[cr] = 1;
					cr = wh[cr];
				}
				tot *= 2;
				tot %= modulo;
			}
		}
		cout<<tot<<'\n';
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}