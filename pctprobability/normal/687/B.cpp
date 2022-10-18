//
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
//typedef string::const_iterator State;
//class ParseError {};
//const ll mod = 1000000009;
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 4100000000000000000ll;
const ld eps = ld(0.000000001);
const long double pi = 3.141592653589793;
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
template<class T,class F>void print(pair<T,F> a){cout<<a.fi<<" "<<a.se<<endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
ll fastgcd(ll u,ll v){ll shl=0;while(u&&v&&u!=v){bool eu=!(u&1);bool ev=!(v&1);if(eu&&ev){++shl;u>>=1;v>>=1;}else if(eu&&!ev){u>>=1;}else if(!eu&&ev){v>>=1;}else if(u>=v){u=(u-v)>>1;}else{ll tmp=u;u=(v-u)>>1;v=tmp;}}return !u?v<<shl:u<<shl;}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll x){return __builtin_popcountll(x);}
ll poplong(ll x){ll y=0;while(x){x/=2;y++;}return y;}

void cincout() {
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
}
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
  void bfs(ll s){
    for(int i=0;i<v;i++){
      d[i]=inf;
    }
    d[s]=0;
    queue<ll> q;
    q.push(s);
    while(q.size()){
      ll v=q.front();
      q.pop();
      for(auto e:g[v]){
        assert(e.cost==1);
        if(chmin(d[e.to],d[v]+1)) q.push(e.to);
      }
    }
  }
  void treediameter(){
    bfs(0);
    ll p=0;
    ll q=0;
    for(int i=0;i<v;i++){
      if(q<d[i]){
        q=d[i];
        p=i;
      }
    }
    diameter[p]=true;
    bfs(p);
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
int main(){
  cincout();
  ll n,k;
  cin>>n>>k;
  ll t=1000000;
  vector<ll> sp(t+1,inf);
  for(int i=2;i<=t;i++){
    if(sp[i]==inf){
      for(int j=i;j<=t;j+=i) chmin(sp[j],ll(i));
    }
  }
  map<ll,ll> m;
  for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    map<ll,ll> v;
    while(x>1){
      v[sp[x]]++;
      x/=sp[x];
    }
    for(auto e:v) chmax(m[e.fi],e.se);
  }
  for(auto e:m){
    for(int i=0;i<e.se;i++) k/=gcd(k,e.fi);
  }
  Yes(k==1);
}