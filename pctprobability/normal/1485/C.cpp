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
ll solve2(ll a,ll b){
  b=min(a,b);
  ll ans=0;
  ll k=b;
  ll t=0;
  for(ll i=1;i*i<=a;i++){
  //  k--;
    chmax(t,i);
    if(i<=b&&i*i!=a){
     ans+=a/i;
      k--;
    }
  }
  if(t*(t+1)>a&&t*t!=a){
    t--;
  }
  for(ll i=t;i>=1;i--){
    ans+=i*max(0ll,min(k,a/i-a/(i+1)));
    k-=a/i-a/(i+1);
    chmax(k,0ll);
  }
  return ans;
}
void solve(){
  ll a,b;
  cin>>a>>b;
  ll ans=solve2(a,b+1)-a;
  for(int i=1;i*i<=a&&i<=b;i++){
    ans-=a/(i+1);
    if(i<=b){
      ans+=i-1;
    }
  }
  cout<<ans<<endl;
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