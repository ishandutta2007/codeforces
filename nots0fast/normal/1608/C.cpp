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

vector<ll> arr;
bool J (ll& a, ll& b){
      return arr[a] < arr[b];
}

void deal(){
      ll t;
      cin>>t;
      forl(t){
            ll n;
            cin>>n;
            vector<ll> a1(n), a2(n);
            fori(n){
                  cin>>a1[i];
            }
            fori(n){
                  cin>>a2[i];
            }
            vector<ll> as(n), bs(n);
            fori(n){
                  as[i] = i, bs[i] = i;
            }
            arr = a1;
            sort(as.begin(), as.end(), J);
            arr = a2;
            sort(bs.begin(), bs.end(), J);
            ll p1 = n-1, p2 = n-1;
            ll mina = a1[bs.back()], minb = a2[as.back()];
            while(1){
                  ll move = 0;
                  while(p1 >= 1){
                        ll id = as[p1-1];
                        if(a1[id] >= mina){
                              --p1;
                              move = 1;
                              minb = min(minb, a2[id]);
                        }
                        else{
                              break;
                        }
                  }
                  while(p2 >= 1){
                        ll id = bs[p2 - 1];
                        if(a2[id] >= minb){
                              --p2;
                              move = 1;
                              mina = min(mina, a1[id]);
                        }
                        else{
                              break;
                        }
                  }
                  if(!move){
                        break;
                  }
            }
            vector<bool> win(n, 0);
            for(ll i = p1; i<n; i++){
                  ll cr = as[i];
                  win[cr] = 1;
            }
            for(ll i = p2; i<n; i++){
                  ll cr = bs[i];
                  win[cr] = 1;
            }
            fori(n){
                  cout<<win[i];
            }
            cout<<'\n';
      }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}