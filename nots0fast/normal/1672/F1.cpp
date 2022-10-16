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
      ll t;
      cin>>t;
      forl(t){
            ll n;
            cin>>n;
            vector<ll> arr(n);
            fori(n){
                  cin>>arr[i];
            }
            vector<stack<ll> > id(n+10); 
            fori(n){
                  id[arr[i]].push(i);
            }
            
            vector<ll> a2 = arr;
            set<ll> good;
            fori(n+10){
                  if(!id[i].empty()){
                        good.insert(i);
                  }
            }
            
            while((ll)good.size() > 1){
                  vector<ll> ids;
                  vector<ll> val;
                  
                  vector<ll> sil;
                  for(auto& el : good){
                        val.pb(el);
                        ids.pb(id[el].top());
                        id[el].pop();
                        if(id[el].empty()){
                              sil.pb(el);
                        }
                  }
                  
                  ll sz = ids.size();
                  fori(sz){
                        ll nx = (i+1)%sz;
                        a2[ids[nx]] = val[i];
                  }
                  
                  for(auto& el : sil){
                        good.erase(el);
                  }
            }
            
            fori(n){
                  cout<<a2[i]<<' ';
            }
            cout<<'\n';
      }
}

int main(){
      cin.tie(0);
      ios_base::sync_with_stdio(0);
      deal();
}