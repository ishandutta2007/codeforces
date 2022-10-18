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
vector<ll> G[200000];
ll d[200000];
bool use[200000];
ll to=0;
vector<ll> v;
void dfs(ll a,ll b){
  d[a]++;
  for(auto e:G[a]){
    if(e==b) continue;
    d[e]=d[a];
    dfs(e,a);
  }
}
void dfs2(ll a,ll b){
 // cout<<"D"<<" "<<a<<" "<<b<<endl;
  if(a==to) use[a]=true;
  for(auto e:G[a]){
    if(e==b) continue;
   // cout<<"V"<<" "<<e<<endl;
    dfs2(e,a);
    use[a]|=use[e];
  }
  if(use[a]) v.pb(a);
}
ll net[200000];
ll nenow=0;
vector<ll> X,Y;
void dfs3(ll a,ll b){
  net[a]=nenow;
  nenow++;
  for(auto e:G[a]){
    if(use[e]) continue;
    if(e==b) continue;
    dfs3(e,a);
    X.pb(net[a]);
    Y.pb(net[e]);
  }
}
vector<ll> solve(vector<vector<ll>> g){
  ll n=g.size();
  if(n==1){
    return {1};
  }
  if(n==0){
    return {};
  }
  if(n==2){
    return {2,0};
  }
  for(int i=0;i<n;i++) G[i].clear();
  for(int i=0;i<n;i++){
    use[i]=false;
    d[i]=0;
    for(auto e:g[i]){
      G[e].pb(i);
    }
  }
  dfs(0,-1);
  ll ma=-1,in=0;
  for(int i=0;i<n;i++){
    if(chmax(ma,d[i])) in=i;
  }
  to=in;
  v={};
  dfs2(0,-1);
  vector<ll> ans;
  ans.pb(ma);
  vector<vector<vector<ll>>> q2;
  for(int i=0;i<v.size()-1;i++) ans.pb(0);
  for(int i=0;i<v.size();i++){
    ll x=v[i];
    for(auto e:g[x]){
      if(use[e]) continue;
      vector<vector<ll>> q;
      X={};
      Y={};
      nenow=0;
      dfs3(e,-1);
      q.resize(nenow);
      for(int j=0;j<X.size();j++){
        q[X[j]].pb(Y[j]);
        q[Y[j]].pb(X[j]);
      }
      q2.pb(q);
    }
  }
  for(auto e:q2){
    auto ans2=solve(e);
    for(auto E:ans2) ans.pb(E);
  }
  return ans;
}
int main() {
  cincout();
  ll n,k;
  cin>>n>>k;
  vector<vector<ll>> g(n);
  for(int i=0;i<n-1;i++){
    ll a,b;
    cin>>a>>b;
    a--;
    b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  auto ans=solve(g);
 // cout<<ans.size()<<endl;
  sor(ans);
  rever(ans);
  ll sum=0;
  ll Ans=-inf;
  for(int i=0;i<=k;i++){
    ll q=min(n/2,n-i);
    chmin(q,n-sum);
    chmax(Ans,(n-i-q)*(i-q));
    if(i<ans.size()) sum+=ans[i];
  }
  cout<<Ans<<endl;
}