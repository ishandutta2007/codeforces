#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
 

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
#define MAX (int)(pow(10,6) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;

ll sqt(ll n){
	ll lo = 0, hi = 1e9;
		while(lo < hi){
			ll mid = (lo+hi)/2;
			if(mid * mid < n){
				lo = mid+1;
			}
			else{
				hi = mid;
			}
		}
	return lo;
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, m , x;
		cin>>n>>m>>x;
		
		vector<pair<ll,ll> > arr(n);
		
		fori(n){
			ll ed;
			cin>>ed;
			arr[i] = mp(ed, i);
		}		
		
		sort(arr.rbegin(), arr.rend());
		
		multimap<ll,ll> all;
		
		fori(m){
			all.insert(mp(0, i));
		}	
		
		vector<ll> where(n);
		
		fori(n){
			auto it = all.begin();
			ll s = (*it).ff, wh = (*it).ss;
			all.erase(it);
			all.insert(mp(s+arr[i].ff, wh));
			where[arr[i].ss] = wh;
		}
		
		auto itn = all.end();
		--itn;
		auto itb = all.begin();
		if((*itn).ff - (*itb).ff > x){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
			fori(n){
				cout<<where[i] + 1<<' ';
			}
			cout<<'\n';
		}

	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}