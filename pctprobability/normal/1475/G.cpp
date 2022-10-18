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
vector<ll> g[201000];
ll ans[201000];
ll dp[201000];
ll seen[201000];
ll dfs(ll a){
  if(seen[a]==1){
    return dp[a];
  }
  seen[a]=1;
  if(ans[a]==0&&a!=1){
    return 0;
  }
  ll an=0;
  for(int i=0;i<int(g[a].size());i++){
    chmax(an,dfs(g[a][i]));
  }
  an+=ans[a];
  return dp[a]=an;
}
void solve(){
  ll a;
  cin>>a;
  vector<ll> n(a);
  vcin(n);
  for(int i=0;i<201000;i++){
    ans[i]=0;
    dp[i]=0;
    seen[i]=0;
  }
  for(int i=0;i<a;i++){
    ans[n[i]]++;
  }
  for(int i=200999;i>=1;i--){
    dfs(i);
  }
  cout<<a-dp[1]<<endl;
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll t;
  cin>>t;
  for(int i=1;i<=200000;i++){
    for(int j=2*i;j<=200000;j+=i){
      g[i].push_back(j);
    }
  }
  while(t--){
    solve();
  }
}