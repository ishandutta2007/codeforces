#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define endl "\n"
typedef pair<int,int> Pii;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define PB push_back
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(s) (s).begin(),(s).end()
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
#define PQminll priority_queue<ll, vector<ll>, greater<ll>>
#define PQmaxll priority_queue<ll,vector<ll>,less<ll>>
#define PQminP priority_queue<P, vector<P>, greater<P>>
#define PQmaxP priority_queue<P,vector<P>,less<P>>
#define NP next_permutation
typedef string::const_iterator State;
class ParseError {};
//const ll mod = 1000000009;
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 4100000000000000000ll;
const ld eps = ld(0.00000000000001);
//static const long double pi = 3.141592653589793;
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
template<class T,class K>void vcin(vector<T> &n,vector<K> &m){for(int i=0;i<int(n.size());i++) cin>>n[i]>>m[i];}
template<class T>void vcout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
template<class T>void vcin(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cin>>n[i][j];}}}
template<class T>void vcout(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cout<<n[i][j]<<" ";}cout<<endl;}cout<<endl;}
void yes(bool a){cout<<(a?"yes":"no")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void possible(bool a){ cout<<(a?"possible":"impossible")<<endl; }
void Possible(bool a){ cout<<(a?"Possible":"Impossible")<<endl; }
void POSSIBLE(bool a){ cout<<(a?"POSSIBLE":"IMPOSSIBLE")<<endl; }
template<class T>void print(T a){cout<<a<<endl;}
template<class T>auto min(const T& a){ return *min_element(all(a)); }
template<class T>auto max(const T& a){ return *max_element(all(a)); }
template<class T,class F>void print(pair<T,F> a){cout<<a.fi<<" "<<a.se<<endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
ll fastgcd(ll u,ll v){ll shl=0;while(u&&v&&u!=v){bool eu=!(u&1);bool ev=!(v&1);if(eu&&ev){++shl;u>>=1;v>>=1;}else if(eu&&!ev){u>>=1;}else if(!eu&&ev){v>>=1;}else if(u>=v){u=(u-v)>>1;}else{ll tmp=u;u=(v-u)>>1;v=tmp;}}return !u?v<<shl:u<<shl;}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll x){return __builtin_popcountll(x);}
ll poplong(ll x){ll y=-1;while(x){x/=2;y++;}return y;}
P hyou(P a){ll x=fastgcd(abs(a.fi),abs(a.se));a.fi/=x;a.se/=x;if(a.se<0){a.fi*=-1;a.se*=-1;}return a;}
P Pplus(P a,P b){ return hyou({a.fi*b.se+b.fi*a.se,a.se*b.se});}
P Ptimes(P a,ll b){ return hyou({a.fi*b,a.se});}
P Ptimes(P a,P b){ return hyou({a.fi*b.fi,a.se*b.se});}
P Pminus(P a,P b){ return hyou({a.fi*b.se-b.fi*a.se,a.se*b.se});}
P Pgyaku(P a){ return hyou({a.se,a.fi});}

void cincout() {
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
}
class UnionFind{
public:
  vector<ll> par;
  vector<ll> siz;
  UnionFind(ll sz_):par(sz_),siz(sz_,1ll){
    for(int i=0;i<sz_;i++) par[i]=i;
  }
  void init(ll sz_){
    par.resize(sz_);
    siz.assign(sz_,1ll);
    for(int i=0;i<sz_;i++) par[i]=i;
  }
  ll root(ll x){
    while(par[x]!=x){
      x=par[x]=par[par[x]];
    }
    return x;
  }
  bool merge(ll x,ll y){
    x=root(x);
    y=root(y);
    if(x==y) return false;
    if(siz[x]<siz[y]) swap(x,y);
    siz[x]+=siz[y];
    par[y]=x;
    return true;
  }
  bool issame(ll x,ll y){
    return root(x)==root(y);
  }
  ll size(ll x){
    return siz[root(x)];
  }
};
struct graph{
  struct edge{
    ll to,cost;
  };
  ll v;
  vector<vector<edge>> g;
  vector<ll> d;
  vector<bool> negative;
  vector<bool> diameter;
  vector<ll> topological_sort;
  ll diametercost;
  bool bipartitecheck;
  vector<ll> bipartite;
  graph(ll n){
    init(n);
  }
  void init(ll n){
    v=n;
    g.resize(n);
    d.resize(n);
    negative.resize(n);
    diameter.resize(n);
    bipartite.resize(n);
    for(int i=0;i<v;i++){
      d[i]=inf;
      bipartite[i]=-1;
      negative[i]=false;
      diameter[i]=false;
    }
  }
  void addedge(ll s,ll t,ll cost){
    edge e;
    e.to=t;
    e.cost=cost;
    g[s].push_back(e);
  }
  void dijkstra(ll s){
    for(int i=0;i<v;i++){
      d[i]=inf;
    }
    d[s]=0;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(P(0,s));
    while(!que.empty()){
      P p=que.top();
      que.pop();
      ll V=p.second;
      if(d[V]<p.first) continue;
      for(auto e:g[V]){
        if(d[e.to]>d[V]+e.cost){
          d[e.to]=d[V]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
  void BellmanFord(ll s){
    for(int i=0;i<v;i++){
      d[i]=inf;
      negative[i]=false;
    }
    d[s]=0;
    for(int i=0;i<v;i++){
      for(int V=0;V<v;V++){
        if(d[V]==inf){
          continue;
        }
        for(auto e:g[V]){
          if(d[e.to]>d[V]+e.cost){
            d[e.to]=d[V]+e.cost;
            if(i==v-1){
              negative[e.to]=true;
              negative[V]=true;
            }
          }
        }
      }
    }
  }
  void dfs(ll s){
    for(int i=0;i<v;i++){
      d[i]=inf;
    }
    d[s]=0;
    dfs2(s,-1);
  }
  void dfs2(ll s,ll v){
    for(auto e:g[s]){
      if(e.to==v) continue;
      if(d[e.to]>d[s]+e.cost){
        d[e.to]=d[s]+e.cost;
        dfs2(e.to,s);
      }
    }
  }
  void treediameter(){
    dfs(0);
    ll p=0;
    ll q=0;
    for(int i=0;i<v;i++){
      if(q<d[i]){
        q=d[i];
        p=i;
      }
    }
    diameter[p]=true;
    dfs(p);
    ll p2=0;
    ll q2=0;
    for(int i=0;i<v;i++){
      if(q2<d[i]){
        q2=d[i];
        p2=i;
      }
    }
    diameter[p2]=true;
    diametercost=d[p2];
  }
  void Bipartite(){
    for(int i=0;i<v;i++){
      if(bipartite[i]==-1){
        Bipartitedfs(i);
      }
    }
  }
  void Bipartitedfs(ll s,ll cur=0){
    bipartite[s]=cur;
    for(auto e:g[s]){
      if(bipartite[e.to]!=-1){
        if((bipartite[e.to]==bipartite[s])^(!e.cost%2)){
          bipartitecheck=false;
        }
      }
      else{
        if(e.cost%2){
          Bipartitedfs(e.to,1-cur);
        }
        else{
          Bipartitedfs(e.to,cur);
        }
      }
    }
  }
  void topologicalsort(){
    for(int i=0;i<v;i++){
      d[i]=0;
    }
    for(int i=0;i<v;i++){
      if(d[i]) continue;
      topologicaldfs(i);
    }
    rever(topological_sort);
  }
  void topologicaldfs(ll a){
    d[a]=1;
    for(auto e:g[a]){
      if(d[e.to]) continue;
      topologicaldfs(e.to);
    }
    topological_sort.push_back(a);
  }
};
vector<ll> s;
map<P,ll> h;
vector<ll> G[200000];
void dfs(ll a,ll b){
 // cout<<a<<" "<<b<<endl;
  for(auto e:G[a]){
    if(e==b) continue;
   // cout<<a<<" "<<e<<" "<<s[a]<<" "<<s[e]<<endl;
    if(s[a]%2!=s[e]%2){
      h[{min(a,e),max(a,e)}]=1;
    }
    dfs(e,a);
  }
}
void solve(){
  //A_i,B_i 
  //A_i,B_i
  ll n,m;
  cin>>n>>m;
  UnionFind t(n);
  graph g(n);
  vector<ll> x(n-1),y(n-1),z(n-1);
  for(int i=0;i<n-1;i++){
    cin>>x[i]>>y[i]>>z[i];
    x[i]--;
    y[i]--;
    if(z[i]>=0){
      g.addedge(x[i],y[i],pop(z[i])%2);
      g.addedge(y[i],x[i],pop(z[i])%2);
      t.merge(x[i],y[i]);
    }
  }
  vector<ll> p,q,r;
  for(int i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    a--;
    b--;
    ll c;
    cin>>c;
    p.pb(a);
    q.pb(b);
    r.pb(c);
    g.addedge(a,b,c);
    g.addedge(b,a,c);
    t.merge(a,b);
  }
  for(int i=1;i<n;i++){
    if(t.merge(0,i)){
      g.addedge(0,i,0);
      g.addedge(i,0,0);
    }
  }
  g.dijkstra(0);
  vector<ll> ans=g.d;
  bool ok=true;
  for(int i=0;i<n-1;i++){
    if(z[i]>=0){
      if((ans[x[i]]+ans[y[i]]+pop(z[i]))%2==1) ok=false;
    }
  }
  for(int i=0;i<m;i++){
    if((ans[p[i]]+ans[q[i]]+r[i])%2==1) ok=false;
  }
  if(ok){
    cout<<"YES"<<endl;
    s=ans;
    h.clear();
    for(int i=0;i<n;i++) G[i].clear();
    for(int i=0;i<n-1;i++){
      G[x[i]].pb(y[i]);
      G[y[i]].pb(x[i]);
    }
    dfs(0,-1);
    for(int i=0;i<n-1;i++){
      if(z[i]==-1){
        cout<<x[i]+1<<" "<<y[i]+1<<" "<<h[{min(x[i],y[i]),max(x[i],y[i])}]<<endl;
      }
      else{
        cout<<x[i]+1<<" "<<y[i]+1<<" "<<z[i]<<endl;
      }
    }
  }
  else{
    cout<<"NO"<<endl;
  }
}
int main() {
  cincout();
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}