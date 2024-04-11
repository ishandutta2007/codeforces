#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
#define all(s) (s).begin(),(s).end()
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

void s(vector<ll> a,map<ll,ll> &m){
  if(int(a.size())==0){
    return;
  }
  if(int(a.size())<=1){
    m[a[0]]++;
    return;
  }
  vector<ll> x;
  vector<ll> y;
  ll sumx=0,sumy=0;
  ll k=(a[0]+a[int(a.size())-1])/2;
  for(int i=0;i<int(a.size());i++){
    if(a[i]<=k){
      x.push_back(a[i]);
      sumx+=a[i];
    }
    else{
      y.push_back(a[i]);
      sumy+=a[i];
    }
  }
  m[sumy]++;
  m[sumx]++;
 // cout<<sumx<<" "<<sumy<<endl;
  if(int(x.size())!=0&&a!=x){
  s(x,m);
  }
  if(int(y.size())!=0&&a!=y){
  s(y,m);
  }
}
void solve(){
  ll a,b;
  cin>>a>>b;
  vector<ll> n(a);
  map<ll,ll> m;
  vcin(n);
  sor(n);
  s(n,m);
  ll sum=0;
  for(int i=0;i<a;i++){
    sum+=n[i];
  }
  m[sum]++;
  while(b--){
    ll x;
    cin>>x;
    if(m[x]){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}