 #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vecll>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
#define MM " "
#define INF 100000000
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
template< typename G >
struct StronglyConnectedComponents {
  const G &g;
  UnWeightedGraph gg, rg;
  vector< int > comp, order, used;

  StronglyConnectedComponents(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size()) {
    for(int i = 0; i < g.size(); i++) {
      for(auto e : g[i]) {
        gg[i].emplace_back((int) e);
        rg[(int) e].emplace_back(i);
      }
    }
  }

  int operator[](int k) {
    return comp[k];
  }

  void dfs(int idx) {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt) {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(UnWeightedGraph &t) {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      for(auto &to : g[i]) {
        int x = comp[i], y = comp[to];
        if(x == y) continue;
        t[x].push_back(y);
      }
    }
  }
};

UnWeightedGraph g,buff;
main(){
    int n=in() , k=in();
    vec cnt(100010);
    rep(i,n*k){
        cnt[in()]++;
    }
    vec f(100010);
    rep(i,n)f[in()]++;
    vec h={0};
    rep(i,k)h.pb(in());
    int ans=0;
    rep(i,100010){
        if(!f[i])continue;
        int card = cnt[i];
        int num = f[i];
        card =min(card , k *num);
        auto dp = vector<vec>(num+1,vec(card+1));
        rep(i,num){
            rep(j,card+1){
                rep(ii,k+1){
                    if(j+ii<=card){
                        chmax(dp[i+1][j+ii],dp[i][j] + h[ii]);
                    }
                }
            }
        }
        ans+=dp[num][card];
    }
    cout<<ans<<endl;

                
}