#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using ld = long double;
#define all(s) (s).begin(),(s).end()
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define SIZE(n) int(n.size())
#define P pair<ll,ll>
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll modulo) { ll ret = 1; ll p = a % modulo; while (n) { if (n & 1) ret = ret * p % modulo; p = p * p % modulo; n >>= 1; } return ret; }
void solve(){
  ll a,b;
  cin>>a>>b;
  vector<ll> n(a);
  vcin(n);
  ll ans=0;
  ll ok=n[0],ng=1000000000000000ll;
  while(abs(ok-ng)>1){
    ll t=(ok+ng)/2;
    vector<ll> s=n;
    s[0]=t;
    bool d=true;
    ll sum=s[0];
    for(int i=1;i<a;i++){
      if(100*s[i]>sum*b){
        d=false;
        break;
      }
      sum+=s[i];
  //   cout<<sum<<endl;
    }
    if(d){
      ng=t;
    }
    else{
      ok=t;
    }
   // cout<<ok<<" "<<ng<<endl;
  }
  for(ll i=max(1ll,max(n[0],ok-5));i<=ok+5;i++){
    vector<ll> s=n;
    s[0]=i;
    bool d=true;
    ll sum=s[0];
    for(int j=1;j<a;j++){
      if(100*s[j]>sum*b){
        d=false;
        break;
      }
      sum+=s[j];
    }
    if(d){
      cout<<i-n[0]<<endl;
      return;
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