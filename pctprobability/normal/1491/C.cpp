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
  vector<ll> n(a);
  vector<ll> m(a+10);
  vcin(n);
  ll ans=0;
  for(int i=0;i<a;i++){
 //   cout<<n[i]<<" "<<m[i]<<endl;
    ll c=n[i];
    n[i]-=m[i];
    n[i]=max(n[i],1ll);
    ans+=n[i]-1;
  //  cout<<"ANS"<<" "<<n[i]-1<<endl;
 //   cout<<m[i]<<" "<<c<<endl;
    if(m[i]>=c){
      m[i+1]+=m[i]-c+1;
    }
    for(int j=i+2;j<min(a,i+c+1);j++){
      m[j]++;
  //    cout<<"+"<<" "<<i<<" "<<j<<endl;
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
//  t=1;
  while(t--){
    solve();
  }
}