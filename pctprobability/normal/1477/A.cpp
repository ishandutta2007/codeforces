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
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
void solve(){
  ll a,k;
  cin>>a>>k;
  vector<ll> n(a);
  ll r;
  bool t=false;
  for(int i=0;i<a;i++){
    cin>>n[i];
    if(i==0){
      r=n[i];
    }
    else{
      r=gcd(r,n[i]);
    }
    if(k==n[i]){
      cout<<"YES"<<endl;
      t=true;
    }
  }
  if(t){
    return;
  }
  sor(n);
  ll q=n[1]-n[0];
  for(int i=1;i<a-1;i++){
    q=gcd(q,n[i+1]-n[i]);
  }
  if((k%q+q)%q!=(n[0]%q+q)%q){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
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