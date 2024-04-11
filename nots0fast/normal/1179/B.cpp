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
const ll inf =  2*pow(10,9);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,6)+10)


void handle(ll fr, ll sc, ll m){ // first row, second row
	ll arr[2] = {fr, sc};
	if(fr == sc){
		ll ct = 1;
		for(ll i = 1; i!=(m+2)/2; ){
			cout<<fr<<" "<<i<<'\n';
			if(ct&1)
				i = m+1-i;
			else
				i = m+2-i;
			ct^=1;
		}
		cout<<fr<<" "<<(m+2)/2<<'\n';
	}
	else{
		ll kd = 0;
		ll ct = 1;
		for(ll i = 1; i!=(m+2)/2; ){
			cout<<arr[kd]<<" "<<i<<'\n';
			if(ct&1)
				i = m+1-i;
			else
				i = m+2-i;
			kd^=1;
			ct^=1;
		}
		cout<<arr[kd]<<" "<<(m+2)/2<<'\n';
		kd^=1;
		cout<<arr[kd]<<" "<<(m+2)/2<<'\n';
		if(m==1)
			return;
		kd^=1;
		ll add = -1;
		if(m&1)
			add = 1;
		for(ll i = (m+2)/2+add; i!=1; i+=add){
			cout<<arr[kd]<<' '<<i<<'\n';
			kd^=1;
			ll yen_add = fabs(add)+1;
			if(add>0)
				yen_add = -yen_add;
			add = yen_add;
		}
		cout<<arr[kd]<<" "<<1<<'\n';
	}
}

void deal(){
	ll t = 1;
	forl(t){
	ll n , m;
	cin>>n>>m;
		for(ll i = 1; i<=n/2; i++)
			handle(i, n+1-i, m);
		if(n&1)
			handle((n+1)/2, (n+1)/2, m);
	}
}





int main()  
{
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	deal();
}