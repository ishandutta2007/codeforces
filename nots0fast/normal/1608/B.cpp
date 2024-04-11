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
#define pb(a) push_back(a)
#define mt make_tuple
const ll INF = 0x3f3f3f3f;
const ll inf =  1e9;
const ll modulo = 998244353;

void deal(){
      ll t;
      cin>>t;
      forl(t){
            ll n, a, b;
            cin>>n>>a>>b;
            bool sw = 0;
            if( a < b){
                  sw = 1;
                  swap(a, b);
            }
            vector<ll> arr(2*a+1, -1);
            
            ll pt = 1;
            if(b < a){
                  pt = n + 1 - (2*a + 1);
            }
            for(ll i = 0; i<2*a+1; i+=2){
                  arr[i] = pt;
                  ++pt;
            }
            for(ll i = 1; i<2 * a+ 1; i+=2){
                  arr[i] = pt;
                  ++pt;
            }
            /*
            fori(2*a+1){
                  cout<<arr[i]<<' ';
            }
            cout<<endl;
            */
            
            if(b < a){
                  ll mx = (n+1) - (2*a + 1) - 1;
                  while((ll)arr.size() < n ){
                        arr.pb(mx);
                        --mx;     
                  }
            }
            else{
                  while(pt <= n){
                        arr.pb(pt);
                        ++pt;
                  }
            }
            
            if((ll)arr.size() > n || (a == b && 2 * a + 1 == n) || abs(a-b) > 1){
                  cout<<-1<<'\n';
            }
            else{
                  if(sw){
                        fori(n){
                              arr[i] = n+1-arr[i];
                        }
                  }
                  
                  fori(n){
                        cout<<arr[i]<<' ';
                  }
                  cout<<'\n';
            }
      }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}