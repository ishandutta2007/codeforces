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

#define MAX 200'100

vector<ll> g[MAX];
ll fkt[MAX];

void pre(){
      fkt[0] = 1;
      for(ll i = 1; i<MAX; i++){
            fkt[i] = fkt[i-1] * i % modulo;
      }
}

void dfs(ll hd, ll pr, ll& ans){
      ll sz = g[hd].size();
      ans *= fkt[sz];
      ans %= modulo;
      for(auto& hr : g[hd]){
            if(hr == pr){
                  continue;
            }
            dfs(hr, hd, ans);
      }
}

void deal(){
      pre();
      ll n;
      cin>>n;
      fori(n-1){
            ll u,v;
            cin>>u>>v;
            --u, --v;
            g[u].pb(v);
            g[v].pb(u);
      }
      ll ans = 1;
      for(auto& el : g[0]){
            dfs(el, 0, ans);
      }
      {
            ans *= n;
            ans %= modulo;
            ll sz = g[0].size();
            ans *= fkt[sz];
            ans %= modulo;
      }
      cout<<ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}