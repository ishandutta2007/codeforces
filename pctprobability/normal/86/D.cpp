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
map<pair<ll,ll>,ll> m;
ll cnt[1001000];
ll sum=0;
ll a[201000];
ll n,q;
void erase(int i){
  ll tmp=a[i];
 // cout<<"E"<<" "<<tmp<<" "<<cnt[tmp]<<endl;
  sum-=(cnt[tmp]*2-1)*tmp;
  cnt[tmp]--;
}
void insert(int i){
  ll tmp=a[i];
 // cout<<"I"<<" "<<tmp<<" "<<cnt[tmp]<<endl;
  sum+=(cnt[tmp]*2+1)*tmp;
  cnt[tmp]++;
}
void Mo(vector<ll> l,vector<ll> r){
  vector<pair<ll,ll>> s;
  for(int i=0;i<int(l.size());i++){
    s.push_back({l[i],r[i]});
  }
  sort(s.begin(),s.end(),[&](pair<ll,ll> a,pair<ll,ll> b){
    if(a.fi/448!=b.fi/448){
      return a.fi<b.fi;
    }
    return a.se<b.se;
  });
  ll p=0,q=-1;
  for(int i=0;i<int(s.size());i++){
   // cout<<s[i].fi<<" "<<s[i].se<<endl;
    while(s[i].se>q){
      insert(q+1);
      q++;
    }
    while(s[i].se<q){
      erase(q);
      q--;
    }
    while(s[i].fi>p){
      erase(p);
      p++;
    }
    while(s[i].fi<p){
      p--;
      insert(p);
    }
  //  cout<<p<<" "<<q<<" "<<sum<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
    m[{s[i].fi,s[i].se}]=sum;
  }
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  cin>>n>>q;
  for(int i=0;i<n;i++){
    cin>>a[i];
    cnt[i]=0;
  }
  for(int i=n;i<200100;i++){
    a[i]=0;
    cnt[i]=0;
  }
  vector<ll> l(q),r(q);
  for(int i=0;i<q;i++){
    cin>>l[i]>>r[i];
    l[i]--;
    r[i]--;
  }
  Mo(l,r);
  for(int i=0;i<q;i++){
    cout<<m[{l[i],r[i]}]<<endl;
  }
}