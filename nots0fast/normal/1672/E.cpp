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
#define lll __int128
#define ld long double
#define pb push_back
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10, 18);
ll modulo = pow(10,9) + 7;
double eps = 1e-10;
ifstream in;
ofstream out;

void deal(){
      ll n;
      cin>>n;
      ll lo = n, hi = n*2000;
      while(lo < hi){
            ll mid = (lo+hi)/2;
            cout<<"? "<<mid<<endl;
            ll ans;
            cin>>ans;
            if(ans == 1){
                  hi = mid;
            }
            else{
                  lo = mid+1;
            }
      }
      // s + n - 1 = lo
      ll s  = lo - n + 1;
      ll mn = lo;
      for(ll i = 2; i<=n; i++){
            // is splitting in i ways possible ?
            ll wopt = lo/i;
            if(wopt*i == lo){
                  --wopt;
            } 
            if(wopt <= 0){
                  wopt = 1;
            }
            cout<<"? "<<wopt<<endl;
            ll ans;
            cin>>ans;
            if(ans != 0){
                  mn = min(mn, ans * wopt);
            }
      }
      
      
      cout<<"! "<<mn<<endl;
      
}

int main(){
      cin.tie(0);
      ios_base::sync_with_stdio(0);
      deal();
}