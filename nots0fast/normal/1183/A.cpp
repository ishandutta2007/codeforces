

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
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10,18);
ll modulo = 163577857;
#define MAX (int)(3*pow(10,5) + 10)


ll s(ll a){
	ll sum = 0;
	while(a){
		sum+=a%10;
		a/=10;
	}
	return sum;
}


void deal(){
	ll a;
	cin>>a;
	for(ll i = a; ; i++){
		ll sum = s(i);
		if(sum%4==0){
			cout<<i;
			return;
		}
	}
}





int main(){

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}