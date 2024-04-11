#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
typedef pair<int, int> Pii;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
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
//const ll mod = 1000000009;
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 4100000000000000000ll;
const ld eps = ld(0.00000000001);
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
  cout<< fixed << setprecision(15);
}
class LCA{
  private:
  int root;
  int k; // n<=2^kk
  vector<vector<int>> dp; // dp[i][j]:=j2^i
  vector<int> depth;  // depth[i]:=rooti
  
  public:
  LCA(){
  }
  LCA(const vector<vector<int>>& _G, const int _root=0){
    int n=_G.size();
    root=_root;
    k=1;
    int nibeki=2;
    while(nibeki<n){
      nibeki<<=1;
      k++;
    }
    // i
    dp = vector<vector<int>>(k+1, vector<int>(n, -1));
    depth.resize(n);
    function<void(int, int)> _dfs=[&](int v, int p){
      dp[0][v]=p;
      for(auto nv: _G[v]){
        if(nv==p) continue;
        depth[nv]=depth[v]+1;
        _dfs(nv, v); 
      }
    };
    _dfs(root, -1);
    // 
    for(int i=0; i<k; i++){
      for(int j=0; j<n; j++){
        if(dp[i][j]==-1) continue;
        dp[i+1][j]=dp[i][dp[i][j]];
      }
    }
  }
  
  /// get LCA
  int get(int u, int v){
    if(depth[u]<depth[v]) swap(u,v); // u
    if(depth[u]!=depth[v]){
      long long d=depth[u]-depth[v];
      for(int i=0; i<k; i++) if((d>>i)&1) u=dp[i][u];
    }
    if(u==v) return u;
    
    for(int i=k; i>=0; i--){
      if(dp[i][u]!=dp[i][v]){
        u=dp[i][u], v=dp[i][v];
      }
    }
    return dp[0][u];
  }
  
  int get_distance(const int u, const int v){
    int lca=get(u,v);
    return depth[u]+depth[v]-2*depth[lca];
  }
};
LCA G;
vector<int> g[200000];
int a[200000];
int W[200000];
vector<int> B,C;
void dfs(int p,int q){
  for(auto e:g[p]){
    if(e!=q){
      W[e]=W[p]+1;
      dfs(e,p);
    }
  }
}
int n;
ll solve(vector<int> f){
  int m=f.size();
  if(f.size()>=200){
    for(int i=0;i<n;i++) a[i]=0;
    for(auto e:f) a[e]++;
    for(int i=0;i<B.size();i++) a[B[i]]+=a[C[i]];
    ll sum=0;
    for(int i=1;i<n;i++){
      sum+=a[i]*(f.size()-a[i]);
    }
    sum%=mod;
    sum*=(m-2);
    sum%=mod;
    sum*=modPow(2,mod-2,mod);
    sum%=mod;
    return sum;
  }
  ll sum=0;
  for(int i=0;i<f.size();i++){
    for(int j=i+1;j<f.size();j++){
      sum+=G.get_distance(f[i],f[j]);
    }
  }
  return sum*(m-2)%mod*modPow(2,mod-2,mod)%mod;
}
int main() {
  cincout();
  cin>>n;
  vector<vector<int>> Q(n);
  vector<int> p(200001,true);
  for(int i=2;i<=200000;i++){
    for(int j=2*i;j<=200000;j+=i) p[j]=false;
  }
  vector<int> spf(200001,100000000);
  for(int i=2;i<=200000;i++){
    for(int j=i;j<=200000;j+=i) chmin(spf[j],i);
  }
  vector<int> a(n,1);
  vcin(a);
  B.resize(n-1);
  C.resize(n-1);
  for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    u--;
    v--;
    B[i]=u;
    C[i]=v;
    g[u].pb(v);
    g[v].pb(u);
    Q[u].pb(v);
    Q[v].pb(u);
  }
  dfs(0,-1);
  vector<vector<int>> D;
  for(int i=0;i<n-1;i++){
    if(W[B[i]]>W[C[i]]){
      swap(B[i],C[i]);
    }
    D.pb({W[B[i]],B[i],C[i]});
  }
  sor(D);
  rever(D);
  for(int i=0;i<n-1;i++){
    B[i]=D[i][1];
    C[i]=D[i][2];
  }
  LCA G2(Q);
  G=G2;
  ll ans=0;
  vector<vector<int>> f(200001);
  for(int i=0;i<n;i++){
    map<int,int> m;
    int x=a[i];
    while(x>1){
      m[spf[x]]++;
      x/=spf[x];
    }
    for(auto e:m) f[e.fi].pb(i);
  }
  for(int i=2;i<=200000;i++){
    if(f[i].size()>=3){
      ans+=solve(f[i]);
    }
  }
  cout<<ans%mod<<endl;
}