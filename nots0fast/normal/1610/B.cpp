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

bool tr(vector<ll>& arr, ll x){
      ll n = arr.size();
      ll pt1 = 0, pt2 = n-1;
      while(pt1 <= pt2){
            if(arr[pt1] != arr[pt2]){
                  if(arr[pt1] == x ){
                        ++pt1;
                  }
                  else if(arr[pt2] == x){
                        --pt2;
                  }
                  else{
                        return 0;
                  }
            }
            else{
                  ++pt1, --pt2;
            }
      }
      return 1;
}

void deal(){
      ll t;
      cin>>t;
      forl(t){
            ll n;
            cin>>n;
            vector<ll> arr(n);
            fori(n){
                  cin>>arr[i];
            }
            ll x = -1, y = -1;
            fori(n){
                  if(arr[i] != arr[n-1-i]){
                        x = arr[i], y = arr[n-1-i];
                  }
            }
            if(tr(arr, x) || tr(arr, y)){
                  cout<<"YES\n";
            }
            else{
                  cout<<"NO\n";
            }
      }
}
 
int main(){
      cin.tie(0);
      ios_base::sync_with_stdio(0);
      deal();
}