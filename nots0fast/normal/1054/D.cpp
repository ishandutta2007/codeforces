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
#define double long double
#define MAX 1010
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9) + 7;

map<ll,ll> track;

void deal(){
	ll n, k;
	cin>>n>>k;
	track[0] = 1;
	ll xr = 0;
	fori(n){
		ll ed;
		cin>>ed;
		ll inv = (((ll)1<<(k)) - 1)^ed;
		if(track[inv^xr] < track[ed^xr])
			xr^=inv;
		else
			xr^=ed;
		track[xr]++;
	}
	ll s = 0;
	for(auto num : track)
		s+=(num.ss-1)*num.ss/2;
	ll num = n*(n+1)/2;
	cout<<num-s;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





/* 
11 9 10
1 2
2 3
3 4
4 5
5 6
6 7
4 8
8 9
8 10 
8 11

*/