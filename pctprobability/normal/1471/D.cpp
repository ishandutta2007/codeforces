#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(s) (s).begin(),(s).end()
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
const ll mod = 998244353;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
template<typename T>
vector<T> smallest_prime_factors(T n) {
 
    vector<T> spf(n + 1);
    for (int i = 0; i <= n; i++) spf[i] = i;
 
 
    for (T i = 2; i * i <= n; i++) {
 
        // 
        if (spf[i] == i) {
 
            for (T j = i * i; j <= n; j += i) {
 
                // i
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
 
    return spf;
}
 
template<typename T>
vector<T> factolization(T x, vector<T> &spf) {
    vector<T> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x /= spf[x];
    }
    sort(ret.begin(), ret.end());
    return ret;
}
vector<int> spf;
ll m[1000100];
void solve(){
  ll a;
  cin>>a;
  vector<int> n(a);
  vcin(n);
  vector<ll> s={1};
  for(int i=0;i<a;i++){
    if(n[i]==1){
      m[n[i]]++;
      continue;
    }
    auto u=factolization(n[i],spf);
    ll tmp=1;
    sor(u);
    ll z=1;
    ll f=u[0];
    for(int j=1;j<int(u.size());j++){
      if(f==u[j]){
        z++;
      }
      else{
        if(z%2){
          tmp*=f;
        }
        f=u[j];
        z=1;
      }
    }
    if(z%2){
      tmp*=f;
    } 
    if(m[tmp]==0){
      s.push_back(tmp);
    }
    m[tmp]++;
  }
  ll q;
  cin>>q;
  ll ans=0;
  for(int i=0;i<int(s.size());i++){
    chmax(ans,m[s[i]]);
  }
  ll ans1=0;
  for(int i=0;i<int(s.size());i++){
    if(s[i]!=1){
    if(m[s[i]]%2==0){
      m[1]+=m[s[i]];
      m[s[i]]=0;
    }
    }
  }
  for(int i=0;i<int(s.size());i++){
    chmax(ans1,m[s[i]]);
  }
  for(int i=0;i<q;i++){
    ll g;
    cin>>g;
    if(g==0){
      cout<<ans<<endl;
    }
    else{
      cout<<ans1<<endl;
    }
  }
  for(int i=0;i<int(s.size());i++){
    m[s[i]]=0;
  }
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  const int MAX=1000100;
  spf = smallest_prime_factors(MAX);
  for(int i=0;i<1000100;i++){
    m[i]=0;
  }
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}