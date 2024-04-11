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
#define P pair<ll,ll>
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
void YesNo(bool a){if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}}
void YESNO(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
void solve(){
  ll a;
  cin>>a;
 // a=5000;
  vector<ll> n(a);
  vcin(n);
  ll ans=0;
  for(int i=0;i<a;i++){
    ans+=n[i]-1;
    n[i]=min(n[i],a+3);
    while(n[i]>1){
      ll t=i;
      while(t<a){
        ll s=t+n[t];
        n[t]=max(n[t]-1,1ll);
        t=s;
        cout<<s<<" ";
      }
      cout<<endl;
    }
  }
  cout<<ans<<endl;
}
ll pop(ll a){
  ll ans=0;
  while(a>0){
    ans+=a%2;
    a/=2;
  }
  return ans;
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll t;
  cin>>t;
//  t=1;
  while(t--){
    ll a,b;
    cin>>a>>b;
    if(a>b){
      cout<<"NO"<<endl;
      continue;
    }
    ll f=0,g=0;
    ll z=1;
    while(a>0||b>0){
      f+=a%2;
      g+=b%2;
      if(f<g){
        cout<<"NO"<<endl;
        z=0;
        break;
      }
      a/=2;
      b/=2;
    }
    if(z){
      cout<<"YES"<<endl;
    }
  }
}