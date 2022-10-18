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
using ll = long long;
using ld = long double;
using ull = long long;
#define endl "\n"
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define all(s) (s).begin(),(s).end()
//#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
//#define rep(i, n) rep2(i, 0, n)
#define PB push_back 
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 4500000000000000000ll;
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
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
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
constexpr ll MAX = 300000;
ll fac[MAX],finv[MAX],inv[MAX];
void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<MAX;i++){
    fac[i]=fac[i-1]*i%mod;
    inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    finv[i]=finv[i-1]*inv[i]%mod;
  }
}
ll COM(ll n,ll k){
  if(n<k) return 0;
  if(n<0||k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}
ll HOM(ll n,ll k){
  if(n+k-1>=n-1&&n-1>=0){
  return COM(n+k-1,n-1);
  }
  else{
    return 0;
  }
}
void solve(){
  ll a;
  cin>>a;
  vector<ll> f(a),g(a,inf);
  for(int i=0;i<a;i++){
    char q;
    cin>>q;
    if(q=='-') f[i]=0;
    else{
      f[i]=1;
      ll x;
      cin>>x;
      g[i]=x;
    }
  }
  ll ans=0;
  for(int i=0;i<a;i++){
    if(f[i]==0) continue;
    vector<vector<ll>> dp2(a+1,vector<ll>(a+1));
    dp2[0][0]=1;
    for(int j=0;j<a;j++){
      if(j==i){
        dp2[j+1]=dp2[j];
        continue;
      }
      for(int k=0;k<=a;k++){
        if(f[j]==0){
          if(k){
            dp2[j+1][k-1]+=dp2[j][k];
            dp2[j+1][k-1]%=mod;
          }
          else if(j<i){
            dp2[j+1][k]+=dp2[j][k];
            dp2[j+1][k]%=mod;
          }
          dp2[j+1][k]+=dp2[j][k];
          dp2[j+1][k]%=mod;
        }
        else if(g[j]<g[i]+int(i<j)){
          if(k!=a){
            dp2[j+1][k+1]+=dp2[j][k];
            dp2[j+1][k+1]%=mod;
          }
          dp2[j+1][k]+=dp2[j][k];
          dp2[j+1][k]%=mod;
        }
        else{
          dp2[j+1][k]+=dp2[j][k]*2;
          dp2[j+1][k]%=mod;
        }
      }
    }
    ll sum=0;
    for(int j=0;j<=a;j++){
      sum+=dp2[a][j]%mod;
      sum%=mod;
    }
    sum%=mod;
    ans+=sum*g[i];
    /*cout<<i<<" "<<sum<<endl;
    for(int j=0;j<=a;j++){
      for(int k=0;k<=a;k++){
        cout<<dp2[j][k]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;*/

    ans%=mod;
  }
  cout<<ans<<endl;
}
int main() {
  cincout();
  COMinit();
  ll t;
 // cin>>t;
  t=1;
  while(t--){
    solve();
  }
}