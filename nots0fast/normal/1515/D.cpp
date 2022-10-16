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

void figure(ll& cost, ll& tot, ll& mx){
	if(mx*2 >= tot){
		cost+=tot/2;
	}
	else{
		cost += mx + (tot-2*mx);
	}
}

void deal(){
	ll t;
	cin>>t;
	forx(t){
		ll n, l , r;
		cin>>n>>l>>r;
		
		vector<ll > ls(n), rs(n);
		
		set<ll> lbig, rbig;
		
		fori(n){
			ll ci;
			cin>>ci;
			--ci;
			if(i < l){
				ls[ci]++;
			}
			else{
				rs[ci]++;
			}
		}
		
		
		fori(n){
			ll mn = min(ls[i], rs[i]);
			ls[i] -= mn;
			rs[i] -= mn;
		}
		
		
		ll cost = 0;
		
		ll ltot = 0, rtot = 0;
		ll mxl = 0, mxr = 0;
		
		fori(n){
			ltot += ls[i];
			rtot += rs[i];
			if(ls[i] > 1){
				lbig.insert(i);
			}
			if(rs[i] > 1){
				rbig.insert(i);
			}
			mxl += ls[i]/2;
			mxr += rs[i]/2;
		}
		
		ll mn = min(ltot, rtot);
		ltot-=mn, rtot-=mn;
		cost += mn;
		
		figure(cost, ltot, mxl);
		figure(cost, rtot, mxr);
		
		cout<<cost<<'\n';
		
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}