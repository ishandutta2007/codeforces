#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define ll long long
#define ld long double
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10, 18);
ll modulo = pow(10,9) + 7;
ifstream in;
ofstream out;


void deal(){
      ll n;
      cin>>n;
      vector<ll> arr(n);
      fori(n){
            cin>>arr[i];
      }
      ll ans = inf;
      fori(n){
            // zero is i
            ll pv = 0;
            ll cur = 0;
            for(ll j = i-1; j>=0; j--){
                  ll tm = pv / arr[j];
                  if(tm * arr[j] <= pv){
                        ++tm;
                  }
                  cur += tm;
                  pv = tm * arr[j];
            }
            
            pv = 0;
            for(ll j = i+1; j<n; j++){
                  ll tm = pv/arr[j];
                  if(tm * arr[j] <= pv){
                        ++tm;
                  }
                  cur += tm;
                  pv = tm * arr[j];
            }
            
            ans = min(ans, cur);
      }
      cout<<ans;
}

int main(){
      cin.tie(0);
      ios_base::sync_with_stdio(0);
      deal();
}