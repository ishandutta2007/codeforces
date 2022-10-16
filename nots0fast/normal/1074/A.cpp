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
#define PI 2*acos(0)
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 2*pow(10,9)+10;
const ll inf =  pow(10,18);
ll modulo = 163577857;


void deal(){
	ll n , m;
	cin>>n>>m;
	vector<ll> vrt;
	fori(n){
		ll x;
		cin>>x;
		vrt.pb(x);
	}
	vrt.pb(pow(10,9));
	sort(vrt.begin(), vrt.end());
	vector<ll> hrt;
	fori(m){
		ll x1, x2, y;
		cin>>x1>>x2>>y;
		if(x1 == 1)
			hrt.pb(x2);
	}
	sort(hrt.begin(), hrt.end());
	ll st = 0;
	ll mn = n + m + 10;
	for(ll i = 0; i<vrt.size(); i++){
		while(st<hrt.size() && hrt[st] < vrt[i])
			++st;
		mn = min(mn, i + (ll)(hrt.size() - st));
	}
	cout<<mn;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}