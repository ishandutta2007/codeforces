#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(s) (s).begin(),(s).end()
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define P pair<ll,ll>
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
void vcin(vector<ll> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
void vcout(vector<ll> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
void YesNo(bool a){if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}}
void YESNO(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
ll dp[1100][1100][2];
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  string a,b;
  cin>>a>>b;
  ll ans=0;
  ll x=int(a.size());
  ll y=int(b.size());
  vector<ll> dpx(x+10),dpy(y+10);
  for(int i=x-1;i>=0;i--){
    ll ans=1;
    for(int j=i;j>=1;j--){
      if(a[j]==a[j-1]){
        break;
      }
      ans++;
    }
    dpx[i]=ans;
  }
  for(int i=y-1;i>=0;i--){
    ll ans=1;
    for(int j=i;j>=1;j--){
      if(b[j]==b[j-1]){
        break;
      }
      ans++;
    }
    dpy[i]=ans;
  }
  dp[0][0][0]=(a[0]!=b[0]);
  dp[0][0][1]=(a[0]!=b[0]);
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
      if(i==0&&j==0) continue;
      dp[i][j][0]=(a[i]!=b[j])*dpy[j];
      dp[i][j][1]=(a[i]!=b[j])*dpx[i];
      dp[i][j][0]%=mod;
      dp[i][j][1]%=mod;
      if(i!=0){
        if(a[i-1]!=a[i]){
          dp[i][j][0]+=dp[i-1][j][0];
          dp[i][j][0]%=mod;
        }
        if(a[i]!=b[j]){
          dp[i][j][0]+=dp[i-1][j][1];
          dp[i][j][0]%=mod;
        }
      }
      if(j!=0){
        if(b[j-1]!=b[j]){
          dp[i][j][1]+=dp[i][j-1][1];
          dp[i][j][1]%=mod;
        }
        if(b[j]!=a[i]){
          dp[i][j][1]+=dp[i][j-1][0];
          dp[i][j][1]%=mod;
        }
      }
    }
  }
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
  //    cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
      ans+=dp[i][j][0]+dp[i][j][1];
      ans%=mod;
    }
  }
  cout<<ans<<endl;
}