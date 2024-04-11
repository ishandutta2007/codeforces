#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
using ull = long long;
#define all(s) (s).begin(),(s).end()
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
//#define P pair<ll,ll>
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
template<class T>void vcout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
void YesNo(bool a){if(a){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}}
void YESNO(bool a){if(a){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}}
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

void gbjsmzmfuuvdf(){
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(20);
}
ll t[100];
void solve(vector<ll> ans,ll k){
  if(ans.size()==0){
    return;
  }
  if(ans.size()==1){
    cout<<ans[0]<<endl;
    return;
  }
  if(t[ans.size()-1]>=k){
    cout<<ans[0]<<" ";
    vector<ll> tmp;
    for(int i=1;i<ans.size();i++){
      tmp.push_back(ans[i]);
    }
    solve(tmp,k);
  }
  else{
    k-=t[ans.size()-1];
    cout<<ans[1]<<" "<<ans[0]<<" ";
    vector<ll> tmp;
    for(int i=2;i<ans.size();i++){
      tmp.push_back(ans[i]);
    }
    solve(tmp,k);
  }
  return;
}
int main() {
  gbjsmzmfuuvdf();
  ll n,k;
  cin>>n>>k;
  vector<ll> ans(n);
  for(int i=0;i<n;i++){
    ans[i]=i+1;
  }
  ll sum=0;
  ll COM[60][60];
  for(int i=0;i<60;i++){
    COM[i][0]=COM[i][i]=1;
  }
  for(int i=1;i<60;i++){
    for(int j=1;j<i;j++){
      COM[i][j]=COM[i-1][j-1]+COM[i-1][j];
    }
  }
  for(int i=0;i<60;i++){
    for(int j=0;j<=i/2;j++){
      t[i]+=COM[i-j][j];
    }
  }
  solve(ans,k);
}