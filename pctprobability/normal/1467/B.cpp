#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(s) (s).begin(),(s).end()
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
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
ll check(ll a,ll b,ll c){
  if((b-a)*(b-c)>0){
    return 1;
  }
  else{
    return 0;
  }
}
void solve(){
  ll a;
  cin>>a;
  ll tmp=0;
  ll ans=0;
  vector<ll> n(a);
  vcin(n);
  vector<ll> s(a,0);
  for(int i=1;i<a-1;i++){
    if((n[i]-n[i-1])*(n[i]-n[i+1])>0){
      s[i]=1;
      ans++;
    }
  }
  for(int i=1;i<a-1;i++){
    vector<ll> k={n[i-1]-1,n[i-1]+1,n[i-1],n[i+1]-1,n[i+1]+1,n[i+1]};
    for(int j=0;j<6;j++){
      ll si=s[i-1]+s[i]+s[i+1];
      ll ki=0;
    if(i!=1){
       ki+=check(n[i-2],n[i-1],k[j]);
    }
    if(i!=a-2){
       ki+=check(k[j],n[i+1],n[i+2]);
    }
      ki+=check(n[i-1],k[j],n[i+1]);
      chmax(tmp,si-ki);
    }
  }
  cout<<ans-tmp<<endl;
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