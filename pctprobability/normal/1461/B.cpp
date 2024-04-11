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
void solve(){
  ll a,b;
  cin>>a>>b;
  vector<string> n(a);
  vcin(n);
  vector<vector<ll>> dp(a,vector<ll>(b));
  ll ans=0;
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      dp[i][j]=(n[i][j]=='*');
      ans+=dp[i][j];
    }
  }
//  cout<<ans<<endl;
  for(int k=0;k<max(a,b)+2;k++){
    vector<vector<ll>> dp2(a,vector<ll>(b));
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      if(j-1>=0&&j+1<b&&i-1>=0){
   //     cout<<i<<" "<<j<<" "<<" "<<k<<" "<<dp[i][j-1]<<" "<<dp[i][j+1]<<" "<<dp[i-1][j]<<endl;
        if(n[i][j]=='*'&&dp[i][j-1]==k+1&&dp[i][j+1]==k+1&&dp[i-1][j]==k+1){
          dp2[i][j]=k+2;
          ans++;
        }
      }
    }
  }
    dp=dp2;
//    cout<<"K"<<" "<<k<<" "<<ans<<endl;
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