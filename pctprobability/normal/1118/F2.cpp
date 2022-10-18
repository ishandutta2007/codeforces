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
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 4100000000000000000ll;
const ld eps = ld(0.000000000001);
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
ll poplong(ll x){ll y=-1;while(x){x/=2;y++;}return y;}

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
vector<vector<ll>> G;
ll dp[400000],dp2[400000];
void dpdfs(ll a,ll b){
  if(G[a].size()==1) return;
  for(auto e:G[a]){
    if(e==b) continue;
    dpdfs(e,a);
  }
  ll dp2p=1;
  for(auto e:G[a]){
    if(e==b) continue;
    (dp2p*=dp2[e])%=mod;
  }
  for(auto e:G[a]){
    if(e==b) continue;
    dp[a]+=dp2p*modPow(dp2[e],mod-2,mod)%mod*dp[e]%mod;
    dp[a]%=mod;
  }
  dp2[a]+=dp[a];
  dp2[a]+=dp2p;
  dp2[a]%=mod;
}
ll Solve(){
  ll n=G.size();
  if(n<=2) return 1;
  ll root=-1;
  for(int i=0;i<n;i++){
    if(G[i].size()>=2) root=i;
  }
  for(int i=0;i<n;i++) dp[i]=dp2[i]=0;
  for(int i=0;i<n;i++) if(G[i].size()==1) dp[i]=dp2[i]=1;
  dpdfs(root,-1);
  return dp[root];
}
ll x[400000];//
ll a[400000];//
map<ll,ll> mid[400000];
vector<ll> g[400000];
ll use[400000];
vector<P> newg[400000];
// mid[i] <- i  x[j]  {j, j }
void dfs(ll p,ll q){
  for(auto e:g[p]){
    if(e==q) continue;
    dfs(e,p);
    for(auto f:mid[e]) mid[p][f.fi]+=f.se;
  }
  if(mid[p].size()>=2){
    cout<<0<<endl;
    exit(0);
  }
  if(a[p]){
    mid[p][a[p]]++;
    for(auto e:mid[p]){
      if(e.fi!=a[p]){
        cout<<0<<endl;
        exit(0);
      }
    }
  }
  else if(mid[p].size()){
    for(auto e:mid[p]) a[p]=e.fi;
  }
  vector<int> era;
  for(auto e:mid[p]){
    if(x[e.fi]==e.se){
      era.pb(e.fi);
    }
  }
  for(auto e:era) mid[p].erase(e);
}
ll dfs2(ll p,ll q){
  ll x=0;
  if(a[p]) x++;
  for(auto e:g[p]){
    if(e==q) continue;
    x+=dfs2(e,p);
  }
  if(x) use[p]=1;
  return x;
}
void solve(){
  ll n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]) x[a[i]]++;
  }
  for(int i=0;i<n-1;i++){
    ll p,q;
    cin>>p>>q;
    p--;
    q--;
    g[p].pb(q);
    g[q].pb(p);
  }
  dfs(0,-1);
  ll root=-1;
  for(int i=0;i<n;i++){
    if(a[i]) root=i;
  }
  dfs2(root,-1);
  UnionFind uf(n);
  for(int i=0;i<n;i++){
    for(auto e:g[i]){
      if(a[i]||a[e]) continue;
      if(use[i]==0||use[e]==0) continue;
      uf.merge(i,e);
    }
  }
  for(int i=0;i<n;i++){
    for(auto e:g[i]){
      if(a[i]||a[e]) continue;
      if(use[i]==0||use[e]==0) continue;
      newg[uf.root(i)].pb({i,e});
    }
  }
  ll ans=1;
  for(int i=0;i<n;i++){
    if(uf.root(i)==i&&a[i]==0){
      map<ll,ll> m;
      m[i]++;
      for(auto e:newg[i]){
        m[e.fi]++;
        m[e.se]++;
      }
      ll now=0;
      for(auto &e:m){
        e.se=now;
        now++;
      }
      G.clear();
      G.resize(now);
      for(auto e:newg[i]){
        G[m[e.fi]].pb(m[e.se]);
      }
      for(auto e:m){
        ll x=e.fi;
        ll y=0;
        for(auto f:g[x]){
          if(a[f]) y++;
        }
        for(int j=0;j<y;j++){
          G[m[e.fi]].pb(now);
          vector<ll> v={m[e.fi]};
          G.pb(v);
          now++;
        }
      }
      ans*=Solve();
      ans%=mod;
    }
  }
  cout<<ans<<endl;
}
int main(){
  cincout();
  ll t;
 // cin>>t;
  t=1;
  while(t--){
    solve();
  }
}