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
 
ll fen[MAX];

void upd(ll ind, ll vl){
	while(ind){
		fen[ind] = max(fen[ind], vl);
		ind-=ind&-ind;
	}
}

ll que(ll ind){
	ll mx = 0;
	while(ind<MAX){
		mx= max(mx, fen[ind]);
		ind+=ind&-ind;
	}
	return mx;
}


void deal(){
	ll t = 1;
//	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<pair<char, ll> > all;
		fori(n){
			char f;
			cin>>f;
			all.pb(mp(f, i));
		}
		vector<ll> arr(n);
		sort(all.begin(), all.end());
		ll mx = 0;
		fori(all.size()){
			ll idx = all[i].ss;
			arr[idx] = que(idx+1) + 1;
			mx = max(mx, arr[idx]);
			upd(idx, arr[idx]);
		}
		cout<<mx<<'\n';
		fori(n){
			cout<<arr[i]<<' ';
		}
		cout<<'\n';
	}
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}