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
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
void vcin(vector<ll> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
void vcout(vector<ll> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
void YesNo(bool a){if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}}
void YESNO(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

vector<ll> smallest_prime_factors(ll n) {

    vector<ll> spf(n + 1);
    for (int i = 0; i <= n; i++) spf[i] = i;


    for (ll i = 2; i * i <= n; i++) {

        // 
        if (spf[i] == i) {

            for (ll j = i * i; j <= n; j += i) {

                // i
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}

vector<ll> factolization(ll x, vector<ll> &spf) {
    vector<ll> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x /= spf[x];
    }
    sort(ret.begin(), ret.end());
    return ret;
}
template<class T>
vector<pair<T,ll>> ml(vector<T> fact){
  vector<pair<T,ll>> f;
  if(int(fact.size())==0){
    return f;
  }
  sor(fact);
  ll x=fact[0];
  ll y=1;
  for(int i=1;i<int(fact.size());i++){
    if(x==fact[i]){
      y++;
    }
    else{
      pair<T,ll> z;
      z.fi=x;
      z.se=y;
      f.push_back(z);
      x=fact[i];
      y=1;
    }
  }
  pair<T,ll> z;
  z.fi=x;
  z.se=y;
  f.push_back(z);
  return f;
}
ll v[20010000];
bool p[20010000];
ll b[60];
void solve(){
  ll c,d,x;
  cin>>c>>d>>x;
  ll ans=0;
  vector<ll> p;
  for(ll i=1;i*i<=x;i++){
    if(x%i==0){
      p.push_back(i);
      if(i*i!=x){
        p.push_back(x/i);
      }
    }
  }
  for(int i=0;i<int(p.size());i++){
    if((((x/p[i])+d))%c==0){
   //   cout<<((x/p[i])+d)/c<<" "<<v[((x/p[i])+d)/c]<<" "<<b[v[((x/p[i])+d)/c]]<<endl;
      ans+=b[v[((x/p[i])+d)/c]];
    }
  }
  cout<<ans<<endl;
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  
  for(int i=2;i<=20000006;i++){
    if(p[i]==true) continue;
    for(int j=i;j<=20000006;j+=i){
      v[j]++;
      p[j]=true;
    }
  }
  b[0]=1;
  for(int i=1;i<60;i++){
    b[i]=b[i-1]*2;
  }
  ll t;
  cin>>t;
  //t=10000;
  while(t--){
    solve();
  }
}