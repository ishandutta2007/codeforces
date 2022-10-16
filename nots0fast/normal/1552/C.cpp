#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision
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
#define mt make_tuple
#define MAX (int)(4*pow(10,5) + 5)
// #define cout out
// #define cin in
ll inf = pow(10, 18) + 100;
ll INF = pow(10, 9);
ll modulo = 998244353;
double eps = 1e-10;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, k;
		cin>>n>>k;
		vector<pair<ll,ll> > all;
		vector<bool> taken(2*n, 0);
		fori(k){
			ll ai, bi;
			cin>>ai>>bi;
			--ai, --bi;
			if(ai > bi){
				swap(ai, bi);
			}
			all.pb(mp(ai, bi));
			taken[ai] = 1;
			taken[bi] = 1;
		}
		vector<ll> arr;
		fori(2*n){
			if(!taken[i]){
				arr.pb(i);
			}
		}
		ll sz = arr.size();
		fori(sz/2){
			all.pb(mp(arr[i], arr[i+sz/2]));
		}
		ll add = 0;
		fori((ll)all.size()){
			forj(i){
				pair<ll,ll> a = all[j], b = all[i];
				if(a > b){
					swap(a, b);
				}
				if(a.ff < b.ff && b.ff < a.ss && a.ss < b.ss){
					++add;
				}
			}
		}
		cout<<add<<'\n';
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	deal();
}