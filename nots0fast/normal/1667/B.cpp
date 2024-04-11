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
      ll t;
      cin>>t;
      forl(t){
            ll n;
            cin>>n;
            map<ll, ll> bigs, smalls, eql;
            bigs[-inf] = -inf, smalls[inf] =  -inf;
            bigs[0] = 0, smalls[0] = 0, eql[0] = 0;
            
            ll pf = 0;
            ll ans;
            for(ll i = 1; i<=n ;i++){
                  ll val;
                  cin>>val;
                  pf += val;
                  
                  ans = -inf;
                  auto it = bigs.lower_bound(pf);
                  if(it != bigs.begin()){
                        --it;
                        ans = max(ans, (*it).ss + i);
                  }
                  
                  it = smalls.upper_bound(pf);
                  if(it != smalls.end()){
                        ans = max(ans, (*it).ss  - i);
                  }
                  
                  it = eql.find(pf);
                  if(it != eql.end()){
                        ans = max(ans, (*it).ss);
                  }
                  
                  {
                        // for bigs
                        it = bigs.upper_bound(pf);
                        --it;
                        if((*it).ss < ans - i){
                              bigs[pf] = ans - i;
                              it = bigs.find(pf);
                              ++it;
                              while(it != bigs.end() && (*it).ss < ans - i){
                                    auto itn = it;
                                    ++itn;
                                    bigs.erase(it);
                                    it = itn;
                              }
                        }
                  }
                  
                  {
                        // for smalls
                        auto it = smalls.lower_bound(pf);
                        
                        if((*it).ss < ans + i){
                              smalls[pf] = ans + i ;
                              it = smalls.find(pf);
                              while(it != smalls.begin() ){
                                    --it;
                                    if((*it).ss < ans + i){
                                          auto itn = it;
                                          ++itn;
                                          smalls.erase(it);
                                          it = itn;
                                    }
                              }
                        }
                  }
                  
                  {
                        eql[pf] = ans;
                  }
            //      cout<<"at index "<<i<<" we have "<<pf<<" and ans "<<ans<<endl;
            }
            
            cout<<ans<<'\n';
      }
}

int main(){
      cin.tie(0);
      ios_base::sync_with_stdio(0);
      deal();
}