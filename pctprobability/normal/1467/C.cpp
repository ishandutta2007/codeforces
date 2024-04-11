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
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll a,b,c;
  cin>>a>>b>>c;
  vector<ll> x(a);
  vcin(x);
  vector<ll> y(b);
  vcin(y);
  vector<ll> z(c);
  vcin(z);
  ll k=inf;
  ll sum=0;
  ll g=0;
  for(int i=0;i<a;i++){
    sum+=x[i];
    g+=x[i];
  }
  chmin(k,g);
  g=0;
  for(int i=0;i<b;i++){
    sum+=y[i];
    g+=y[i];
  }
  chmin(k,g);
  g=0;
  for(int i=0;i<c;i++){
    sum+=z[i];
    g+=z[i];
  }
  chmin(k,g);
  sor(x);
  sor(y);
  sor(z);
  chmin(k,x[0]+y[0]);
  chmin(k,x[0]+z[0]);
  chmin(k,z[0]+y[0]);
  cout<<sum-2*k<<endl;
}