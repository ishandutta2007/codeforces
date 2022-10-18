#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
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
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
void vcin(vector<int> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
void vcout(vector<ll> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
void YesNo(bool a){if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}}
void YESNO(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
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
int m[10000010];
vector<int> v;
void solve(){
  ll n;
  cin>>n;
  ll k;
  cin>>k;
  vector<int> a(n);
  vcin(a);
  vector<ll> b(n);
  for(int i=0;i<n;i++){
      vector<ll> p;
      auto result = factolization(a[i],v);
    sor(result);
      ll ans=1;
      for(int j=0;j<int(result.size());j++){
          if(ans%result[j]==0){
            ans/=result[j];
          }
        else{
          ans*=result[j];
        }
      }
      b[i]=ans;
  }
  ll ans=0;
  vector<ll> f;
  vector<ll> e;
  for(int i=0;i<n;i++){
      if(m[b[i]]!=0){
          ans++;
        for(int j=0;j<int(f.size());j++){
          m[f[j]]=0;
        }
        f=e;
        m[b[i]]++;
        f.push_back(b[i]);
      }
      else{
          m[b[i]]++;
        f.push_back(b[i]);
      }
  }
  if(f.size()){
      ans++;
  }
  for(int i=0;i<n;i++){
    m[b[i]]=0;
  }
  cout<<ans<<endl;
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  v = smallest_prime_factors(10001000);
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}