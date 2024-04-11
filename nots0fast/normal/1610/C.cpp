/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
*/

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
#define lll __int128
#define pb(a) push_back(a)
#define ld long double
#define mt make_tuple
const ll INF = 0x3f3f3f3f;
ll inf = 1e18;
ll modulo = 998244353;

void deal(){
      ll t;
      cin>>t;
      forl(t){
            ll n;
            cin>>n;
            vector<pair<ll,ll> > arr(n);
            fori(n){
                  cin>>arr[i].ff>>arr[i].ss;
            }
            ll lo = 0, hi = n;
            while(lo < hi){
                  ll mid = (lo + hi)/2 + 1;
                  ll took = 0;
                  fori(n){
                        if(arr[i].ss >= took && arr[i].ff >= mid-1-took){
                              ++took;
                        }
                  }
                  if(took >= mid){
                        lo = mid;
                  }
                  else{
                        hi = mid-1;
                  }
            }
            cout<<lo<<'\n';
      }
}
 
int main(){
      cin.tie(0);
      ios_base::sync_with_stdio(0);
      deal();
}