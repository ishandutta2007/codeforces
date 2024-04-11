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
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;


ll ind[MAX];
ll arr[MAX];
vector<pair<ll,ll> > all;
void upd(ll index){
	ind[arr[index]] = index;
}

void swapp( ll a, ll b){
	all.pb(mp(a,b));
	swap(arr[a], arr[b]);
}



void deal(){
	ll n;
	cin>>n;
	fori(n){
		ll ed;
		cin>>ed;
		arr[i+1] =ed;
		upd(i+1);
	}
	for(int i = 1; i<=n/2; i++){
		if(arr[i] == i)
			continue;
		ll lz = ind[i];
		if( lz >= i+n/2 ){
			swapp(i, lz);
			upd(i);
			upd(lz);
		}
		else{
			if( lz <= n/2){
				swapp(lz, n);
				swapp(n, i);
				upd(n);
				upd(lz);
				upd(i);
			}
			else{
				swapp(1 , lz);
				swapp(1,  n);
				swapp(n,  i);
				swapp(1,  lz);
				upd(1);
				upd(n);
				upd(lz);
				upd(i);
			}
		}
	}
	for(int i=n/2+1; i<=n; i++){
		if(arr[i] == i)
			continue;
		ll lz  =ind[i];
		swapp(1 ,lz);
		swapp(1, i);
		swapp(lz, 1);
		upd(1);
		upd(lz);
		upd(i);
	}
	cout<<all.size()<<'\n';
	fori(all.size())
		cout<<all[i].ff<<" "<<all[i].ss<<'\n';
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1