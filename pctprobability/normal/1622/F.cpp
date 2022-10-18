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
const ll mod = 1000000000000000000ll;
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
ll can(ll n){
  vector<vector<ll>> fac(n+1);
  vector<bool> prime(n+1,true);
  for(int i=2;i<=n;i++){
    for(int j=2*i;j<=n;j+=i) prime[j]=false;
  }
  for(int i=2;i<=n;i++){
    if(prime[i]){
      for(int j=i;j<=n;j+=i){
        ll now=0;
        ll x=j;
        while(x%i==0){
          now++;
          x/=i;
        }
        if(now%2) fac[j].pb(i);
      }
    }
  }
  vector<ll> c(n+1);
  for(int i=n;i>=1;i-=2){
    for(auto e:fac[i]) (c[e]+=1)%=2;
  }
  ll x=0;
  for(auto e:c) if(e) x++;
  if(x==0) return 1;
  for(int i=2;i<=n;i++){
    for(auto e:fac[i]){
      if(c[e]) x--;
      else x++;
      c[e]++;
      c[e]%=2;
    }
    if(x==0) return i;
  }
  return -1;
}
P can3(ll n){
  vector<vector<ll>> fac(n+1);
  vector<bool> prime(n+1,true);
  for(int i=2;i<=n;i++){
    for(int j=2*i;j<=n;j+=i) prime[j]=false;
  }
  for(int i=2;i<=n;i++){
    if(prime[i]){
      for(int j=i;j<=n;j+=i){
        ll now=0;
        ll x=j;
        while(x%i==0){
          now++;
          x/=i;
        }
        if(now%2) fac[j].pb(i);
      }
    }
  }
  vector<ll> h(n+1);
  std::random_device seed;
  std::default_random_engine engine(seed());
  std::uniform_int_distribution<long long> r(1,999999999999999999ll);
  for(int i=0;i<=n;i++) h[i]=r(engine);
   vector<ll> c(n+1);
  for(int i=n;i>=1;i-=2){
    for(auto e:fac[i]) (c[e]+=1)%=2;
  }
  ll v=0;
  for(int i=0;i<=n;i++) if(c[i]) (v+=h[i])%=mod;
  ll me=0;
  vector<ll> d(n+1);
  unordered_map<ll,vector<ll>> m;
  for(int i=1;i<=n;i++){
    for(auto e:fac[i]){
      if(d[e]) me-=h[e];
      else me+=h[e];
      d[e]++;
      d[e]%=2;
      me%=mod;
      me+=mod;
      me%=mod;
    }
    for(auto e:fac[i]){
      if(c[e]) v-=h[e];
      else v+=h[e];
      c[e]++;
      c[e]%=2;
      v%=mod;
      v+=mod;
      v%=mod;
    }
    m[me].pb(i);
    if(m[v].size()) return {i,m[v][0]};
  }
  return {-1,-1};
}
void solve(ll n){
  if(n<=3){
    cout<<1<<endl;
    cout<<1<<endl;
    return;
  }
  if(n%2){
    ll d=can(n);
    if(d!=-1){
      cout<<n-1<<endl;
      for(int i=1;i<=n;i++){
        if(i!=d) cout<<i<<" ";
      }
      cout<<endl;
      return;
    }
    P d2=can3(n);
    if(d2.fi!=-1){
      cout<<n-2<<endl;
      for(int i=1;i<=n;i++){
        if(i!=d2.fi&&i!=d2.se) cout<<i<<" ";
      }
      cout<<endl;
      return;
    }
    solve(n-1);
    return;
  }
  ll d=n/2;
  ll d2=can(n);
  if(d2!=-1){
    cout<<n-1<<endl;
    for(int i=1;i<=n;i++){
      if(i!=d2) cout<<i<<" ";
    }
    cout<<endl;
    return;
  }
  else{
    cout<<n-2<<endl;
    for(int i=1;i<=n;i++){
      if(i!=2&&i!=d) cout<<i<<" ";
    }
    cout<<endl;
    return;
  }
}
int main() {
  cincout();
  ll n;
  cin>>n;
  solve(n);
}