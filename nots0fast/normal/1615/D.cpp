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
ll modulo = pow(10,9) + 7;

#define N 400'100
#define MAX 400'100

namespace n10{

      int low[N],vis[N],scomp[N],scompNum,I;
      vector<int> adj[N]; stack<int> verts;
      void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
      for (int v : adj[u]) {
      if (!vis[v]) scc(v);
      if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
      if (vis[u] <= low[u]) { int v;
      do { v=verts.top(); verts.pop(); scomp[v]=scompNum; }while (v != u);
      ++scompNum; }}
      void get_scc(int n) {
            for(int i  = 0; i<n; i++){
                  vis[i] = 0;
                  scomp[i] = -1;
            }
      scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }

      bool truth[N/2]; // N must be at least 2 times the number of variables
      // the clause a || b becomes !a => b and !b => a in implication graph
      // 2*a = variable true
      // 2*a + 1 = variable false
      void add_clause(int a, int b) {
      adj[a^1].push_back(b); adj[b^1].push_back(a); }
      bool two_sat(int n) { get_scc(n);
      for (int i = 0; i < n; i += 2) { if (scomp[i] == scomp[i^1]) return 0;
      truth[i/2] = (scomp[i] < scomp[i^1]); } return 1; }
};

vector<pair<ll , ll> > g[MAX];
ll xrval[MAX];
ll edgval[MAX];
ll par[MAX];
bool gg[MAX];

void dfs(ll hd, ll pr){
      for(auto& el : g[hd]){
            ll hr = el.ff, vl = el.ss;
            if(hr == pr){
                  continue;
            }
            par[hr] = hd;
       //     cout<<"vl at "<<hd+1<<" "<<hr+1<<" is "<<vl<<endl;
            if(vl == -1){
                  vl = 0;
                  gg[hr] = 1;
            }
            edgval[hr] = vl;
            xrval[hr] = (xrval[hd] ^ vl);
            dfs(hr, hd);
      }
}

void add1(ll a, ll b){
      // v_a == v_b
      n10::adj[2*a].pb(2*b);
      n10::adj[2*b].pb(2*a);
      n10::adj[2*a+1].pb(2*b+1);
      n10::adj[2*b+1].pb(2*a+1);
}

void add2(ll a, ll b){
      // v_a != v_b
      // if a -> !b
      // if !a -> b
      // if b -> !a
      // if !b -> a
      n10::adj[2*a].pb(2*b+1);
      n10::adj[2*a + 1].pb(2*b);
      n10::adj[2*b].pb(2*a+1);
      n10::adj[2*b+1].pb(2*a);
}

void deal(){
      ll t;
      cin>>t;
      forl(t){
            ll n, m;
            cin>>n>>m;
            fori(n-1){
                  ll xi, yi, vl;
                  cin>>xi>>yi>>vl;
                  --xi, --yi;
                  g[xi].pb(mp(yi, vl));
                  g[yi].pb(mp(xi, vl));
            }
            gg[0] = 1;
            dfs(0, -1);
            
            fori(n){
                  if(!gg[i]){
                        // vi = vpari
                        ll v1 = i, v2 = par[i];
                        add1(v1, v2);
               //         cout<<"we demand it "<<i+1<<endl;
                  }
            }
            
            fori(m){
                  ll a, b, vl;
                  cin>>a>>b>>vl;
                  --a, --b;
                  ll xr = xrval[a] ^ xrval[b];
            //      cout<<"xor is "<<xr<<endl;
                  if(vl == (__builtin_popcount(xr) % 2)){
                        // va == vb
                        add1(a, b);
                  }
                  else{
                        // va != vb
              //          cout<<"oh nvm "<<endl;
                        add2(a, b);
                  }
            }
            
            if(n10::two_sat(2*n)){
                  cout<<"YES\n";
                  for(ll i = 1; i<n; i++){
                        ll pr = par[i];
                        if(n10::truth[i]!=n10::truth[pr]){
                  //            cout<<"truth is different at  "<<i+1<<endl;
                              cout<<i+1<<" "<<pr+1<<" "<<1<<'\n';
                        }
                        else{
                 //             cout<<"edgval at "<<i<<" is "<<edgval[i]<<endl;
                              cout<<i+1<<" "<<pr+1<<" "<<edgval[i]<<'\n';
                        }
                  }
            }
            else{
                  cout<<"NO\n";
            }
            
            fori(2*n+10){
                  n10::adj[i].clear();
                  xrval[i] = 0;
                  gg[i]  =0;
                  g[i].clear();
            }
      }
}
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}