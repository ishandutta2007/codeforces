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
  ll k,l,r,t,x,y;
  cin>>k>>l>>r>>t>>x>>y;
  if(t<=5){
    while(t--){
   //   cout<<k<<endl;
      if((k-x<l&&k+y<=r)||(x>=y&&k+y<=r)){
        k+=y;
      }
      if(k<l||k>r){
        cout<<"No"<<endl;
        return;
      }
      k-=x;
      if(k<l||k>r){
        cout<<"No"<<endl;
        return;
      }
    }
    cout<<"Yes"<<endl;
    return;
  }
  if(x>=y){
    if(k+y<=r){
      if(x-y<(l+k+t-1)/t){
        cout<<"Yes"<<endl;
      }
      else{
        cout<<"No"<<endl;
      }
    }
    else{
 //     cout<<x-y<<" "<<(l+k-x+t-2)/(t-1)<<endl;
      if(x-y<(l+k-x+t-2)/(t-1)){
        cout<<"Yes"<<endl;
      }
      else{
        cout<<"No"<<endl;
      }
    }
    return;
  }
  if(x+l<=r-y){
    cout<<"Yes"<<endl;
    return;
  }
  vector<bool> check(x+10,false);
  for(int i=0;i<=10000000;i++){
    ll tmp=(k-l)/x,tmp2=(r-x-k)/(y-x);
    t-=tmp;
    k-=tmp*x;
    if(t<=0){
      cout<<"Yes"<<endl;
      return;
    }
    if(check[k-l]){
      cout<<"Yes"<<endl;
      return;
    }
    if(tmp2>0){
      t-=tmp2;
      k+=(y-x)*tmp2;
    }
  }
  cout<<"No"<<endl;
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll t;
//  cin>>t;
  t=1;
  while(t--){
    solve();
  }
}