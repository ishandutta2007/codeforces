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
            vector<ll> a1(n+1, -1), a2(n+1, -1);
            for(ll i = 1; i<=n; i++){
                  cin>>a1[i];
            }
            for(ll i = 1; i<=n; i++){
                  cin>>a2[i];
            }
            multiset<ll> todel;
            a2[0] = -inf;
            ll pv = inf;
            ll p1 = n, p2  =n;
            
            bool gg = 1;
            while(p1 || p2){
            //      cout<<p1<<" "<<p2<<endl;
                  if(a1[p1] == a2[p2]){
                        pv = a1[p1];
                        --p1, --p2;
                  }
                  else{
                        if(pv == a2[p2]){
                              todel.insert(a2[p2]);
                              --p2;
                        }
                        else{
                              auto it = todel.find(a1[p1]);
                              if(it != todel.end()){
                                    todel.erase(it);
                                    --p1;
                              }
                              else{
                                    gg = 0;
                                    break;
                              }
                        }
                  }
            }
            
            if(gg){
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