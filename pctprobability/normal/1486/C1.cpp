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
//#define P pair<ll,ll>
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
void YesNo(bool a){if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}}
void YESNO(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll n;
  cin>>n;
  ll ok=1,ng=n;
  map<pair<ll,ll>,ll> m;
  while(abs(ok-ng)>1){
    ll t=(ok+ng)/2;
    ll p;
    if(m[{ok,ng}]==0){
    cout<<"? "<<ok<<" "<<ng<<endl;
    fflush(stdout);
    cin>>p;
      m[{ok,ng}]=p;
    }
    else{
      p=m[{ok,ng}];
    }
    ll q;
    if(ok<=p&&p<=t){
      
      cout<<"? "<<ok<<" "<<t<<endl;
      fflush(stdout);
      cin>>q;
      if(p==q){
        ng=t;
      }
      else{
        ok=t+1;
      }
    }
    else{
      cout<<"? "<<t<<" "<<ng<<endl;
      fflush(stdout);
      cin>>q;
      if(p==q){
        ok=t;
      }
      else{
        ng=t-1;
      }
    }
 //   cout<<ok<<" "<<ng<<endl;
  }
  if(ok==ng){
    cout<<"! "<<ng<<endl;
    return 0;
  }
  else{
    cout<<"? "<<ok<<" "<<ng<<endl;
    fflush(stdout);
    ll q;
    cin>>q;
    if(q==ok){
      cout<<"! "<<ng<<endl;
      return 0;
    }
    else{
      cout<<"! "<<ok<<endl;
      return 0;
    }
  }
}