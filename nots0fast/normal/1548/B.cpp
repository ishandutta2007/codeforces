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
ll inf = 1e18;
ll INF = pow(10,9);
ll modulo = 998244353;
double eps = 1e-10;



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
            vector<vector<ll> > b(n-1, vector<ll>(20, 1));
            for(ll i = 1; i<n; i++){
                  b[i-1][0] = (abs(arr[i] - arr[i-1]));
            }
            
            
            for(ll j = 1; j<20; j++){
                  fori((ll)b.size()){
                        if(i + (1<<j) > (ll)b.size()){
                              b[i][j] = 1;
                              continue;
                        }
                        b[i][j] = __gcd(b[i][j-1], b[i+(1<<(j-1))][j-1]);
                  }
            }
            
            ll mx = 1;
            
            fori((ll)b.size()){
                  ll cr = i;
                  ll len  =0;
                  ll gcd = 0;
                  for(ll j = 19; j>-1; j--){
                        if(cr == (ll)b.size()){
                              break;
                        }
                        ll val = __gcd(gcd , b[cr][j]);
                        if(val!=1){
                             len += (1<<j);
                             cr += (1<<j); 
                             gcd = val;
                        }
                  }
                  mx = max(mx, len + 1);
            }
            
            cout<<mx<<'\n';
            
      }
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	deal();
}