#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = int;
using ld = long double;
using ull = long long;
#define endl "\n"
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define all(s) (s).begin(),(s).end()
//#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
//#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
const ll mod = 998244353;
//const ll mod = 1000000007;
//const ll inf = 4500000000000000000ll;
static const long double pi = 3.141592653589793;
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
template<class T>auto min(const T& a){ return *min_element(all(a)); }
template<class T>auto max(const T& a){ return *max_element(all(a)); }
template<class T,class F>void print(pair<T,F> a){cout<<a.fi<<" "<<a.se<<endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
template<class T>
struct Sum{
  vector<T> data;
  Sum(const vector<T>& v):data(v.size()+1){
    for(ll i=0;i<v.size();i++) data[i+1]=data[i]+v[i];
  }
  T get(ll l,ll r) const {
    return data[r]-data[l];
  }
};
template<class T>
struct Sum2{
  vector<vector<T>> data;
  Sum2(const vector<vector<T>> &v):data(v.size()+1,vector<T>(v[0].size()+1)){
    for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) data[i+1][j+1]=data[i][j+1]+v[i][j];
    for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) data[i+1][j+1]+=data[i+1][j];
  }
  T get(ll x1,ll y1,ll x2,ll y2) const {
    return data[x2][y2]+data[x1][y1]-data[x1][y2]-data[x2][y1];
  }
};

void cincout(){
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(20);
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
  vector<vector<ll>> w;
  graph(ll n){
    init(n);
  }
  void init(ll n){
    v=n;
    g.resize(n);
    d.resize(n);
    w.resize(n);
    for(int i=0;i<n;i++){
      w[i].resize(n);
    }
    negative.resize(n);
    diameter.resize(n);
    bipartite.resize(n);
    for(int i=0;i<v;i++){
      d[i]=10000000;
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
      d[i]=10000000;
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
      d[i]=10000000;
      negative[i]=false;
    }
    d[s]=0;
    for(int i=0;i<v;i++){
      for(int V=0;V<v;V++){
        if(d[V]==10000000){
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
  void waa(){
    for(int i=0;i<v;i++){
      for(int j=0;j<v;j++){
        if(i==j) w[i][j]=0;
        else w[i][j]=10000000;
      }
    }
    for(int i=0;i<v;i++){
      for(auto e:g[i]){
        w[e.to][i]=1;
      }
    }
    for(int k=0;k<v;k++){
      for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
          chmin(w[i][j],(w[i][k]+w[k][j]));
        }
      }
    }
  }
};
int main() {
  cincout();
  ll a;
  cin>>a;
  vector<long long> t(a);
  vcin(t);
  vector<long long> n;
  for(auto e:t){
    if(e!=0) n.pb(e);
  }
  a=n.size();
  if(a>=200){
    cout<<3<<endl;
    return 0;
  }
  vector<vector<ll>> d(a);
  for(int i=0;i<a;i++){
    for(int j=0;j<a;j++){
      if((n[i]&n[j])){
     d[i].pb(j);
      }
    }
  }
  ll ans=1000000;
  for(int F=0;F<a;F++){
    graph g(a);
    for(int i=0;i<a;i++){
        if(i==F) continue;
        for(auto f:d[i]){
            if(f==F) continue;
            g.addedge(i,f,1);
        }
    }
    g.waa();
  for(int i=0;i<a;i++){
    if(i==F) continue;
    for(int j=0;j<a;j++){
      if(i==j) continue;
      if(j==F) continue;
      if(((n[F])&(n[i]))!=0&&((n[F])&(n[j]))!=0){
        chmin(ans,2+g.w[i][j]);
      }
    }
  }
  }
  if(ans>=1000000/2){
    cout<<-1<<endl;
    return 0;
  }
  cout<<ans<<endl;
}