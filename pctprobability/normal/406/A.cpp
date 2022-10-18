#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
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

int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll a;
  cin>>a;
  vector<vector<ll>> n(a,vector<ll>(a));
  for(int i=0;i<a;i++){
    for(int j=0;j<a;j++){
      cin>>n[i][j];
    }
  }
  ll ans=0;
  for(int i=0;i<a;i++){
    ans+=n[i][i];
  }
  ll q;
  cin>>q;
  ans%=2;
  for(int i=0;i<q;i++){
    ll x,y;
    cin>>x;
    if(x==1||x==2){
      cin>>y;
      ans=1-ans;
    }
    else{
      printf("%d",ans);
    }
  }
}