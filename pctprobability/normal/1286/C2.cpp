#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
using ull = long long;
#define endl "\n"
typedef pair<int, int> Pii;
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define all(s) (s).begin(),(s).end()
//#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
//#define rep(i, n) rep2(i, 0, n)
#define PB push_back 
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
//#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
#define NP next_permutation
//const ll mod = 1000000009;
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 9100000000000000000ll;
const ld eps = ld(0.0000000000001);
static const long double pi = 3.141592653589793;
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
template<class T,class K>void vcin(vector<T> &n,vector<K> &m){for(int i=0;i<int(n.size());i++) cin>>n[i]>>m[i];}
template<class T>void vcout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
template<class T>void vcin(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cin>>n[i][j];}}}
template<class T>void vcout(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cout<<n[i][j]<<" ";}cout<<endl;}cout<<endl;}
void yes(bool a){cout<<(a?"yes":"no")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void possible(bool a){ cout<<(a?"possible":"impossible")<<endl; }
void Possible(bool a){ cout<<(a?"Possible":"Impossible")<<endl; }
void POSSIBLE(bool a){ cout<<(a?"POSSIBLE":"IMPOSSIBLE")<<endl; }
template<class T>auto min(const T& a){ return *min_element(all(a)); }
template<class T>auto max(const T& a){ return *max_element(all(a)); }
template<class T,class F>void print(pair<T,F> a){cout<<a.fi<<" "<<a.se<<endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll a){ll res=0;while(a){res+=a%2;a/=2;}return res;}
template<class T>
struct Sum{
  vector<T> data;
  Sum(const vector<T>& v):data(v.size()+1){
    for(ll i=0;i<v.size();i++) data[i+1]=data[i]+v[i];
  }
  T get(ll l,ll r) const {
    return data[r]-data[l];
  }
};
template<class T>
struct Sum2{
  vector<vector<T>> data;
  Sum2(const vector<vector<T>> &v):data(v.size()+1,vector<T>(v[0].size()+1)){
    for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) data[i+1][j+1]=data[i][j+1]+v[i][j];
    for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) data[i+1][j+1]+=data[i+1][j];
  }
  T get(ll x1,ll y1,ll x2,ll y2) const {
    return data[x2][y2]+data[x1][y1]-data[x1][y2]-data[x2][y1];
  }
};
 
void cincout(){
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
}

int main() {
 // cincout();
  ll n;
  cin>>n;
  if(n<=3){
    string ans;
    for(int i=0;i<n;i++){
      cout<<"? "<<i+1<<" "<<i+1<<endl;
      fflush(stdout);
      char u;
      cin>>u;
      ans.pb(u);
    }
    cout<<"!"<<" "<<ans<<endl;
    return 0;
  }
  else{
    vector<map<string,ll>> m(n+10),m2(n+10),m3(n+10);
    cout<<"? "<<1<<" "<<n<<endl;
    fflush(stdout);
    for(int i=0;i<(n*(n+1))/2;i++){
      string s;
      cin>>s;
      sor(s);
      m[s.size()][s]++;
    }
    cout<<"? "<<1<<" "<<(n+1)/2<<endl;
    fflush(stdout);
    for(int i=0;i<(((n+1)/2)*((n+1)/2+1))/2;i++){
      string s;
      cin>>s;
      sor(s);
      m2[s.size()][s]++;
    }
    cout<<"? "<<2<<" "<<(n+1)/2<<endl;
    fflush(stdout);
    for(int i=0;i<((n+1)/2-1)*((n+1)/2)/2;i++){
      string s;
      cin>>s;
      sor(s);
      m3[s.size()][s]++;
    }
    string ans;
    for(int i=1;i<=(n+1)/2;i++){
      for(auto e:m2[i]){
        bool ok=true;
        for(auto e2:m3[i]){
          if(e.fi==e2.fi){
            if(e.se==e2.se) ok=false;
          }
        }
       // cout<<e.fi<<" "<<int(ok)<<endl;
        if(ok){
          string p=ans,q=e.fi;
          sor(p);
          sor(q);
          map<char,ll> x,y;
          for(auto e3:p) x[e3]++;
          for(auto e3:q) y[e3]++;
          for(auto e3:y){
            if(e3.se!=x[e3.fi]) ans.pb(e3.fi);
          }
        }
      }
    }
    vector<char> solve(n);
    for(int i=0;i<ans.size();i++) solve[i]=ans[i];
    vector<map<char,ll>> x(n+10);
    for(int i=1;i<=n;i++){
      for(auto k:m[i]){
        for(auto y:k.fi){
          x[i][y]+=k.se;
         // cout<<i<<" "<<k.se<<" "<<y<<endl;
         // if(i==3) cout<<"K"<<" "<<y<<endl;
        }
      }
    }
    for(int i=1;i<=n;i++){
      for(auto k:m2[i]){
        for(auto y:k.fi){
          x[i][y]-=k.se;
         // if(i==3) cout<<y<<endl;
        }
      }
    }
    for(int i=2;i<=n/2+1;i++){
      ll y=i-1;
      for(int j=0;j<=i-2;j++){
       // cout<<"I"<<" "<<i<<" "<<j<<endl;
        x[i][ans[ans.size()-1-j]]-=y;
        y--;
      }
    }
    for(int i=2;i<=n/2+1;i++){
      ll u=n-i+1;
      ll ke=1;
      for(int j=n-1;j>=u+1;j--){
        x[i][solve[j]]-=ke;
        ke++;
      }
      for(int j=0;j<26;j++){
        if(x[i][char(int('a')+j)]%i) solve[u]=char(int('a')+j);
     //   if(i==3) cout<<x[i][char(int('a')+j)]<<endl;
      }
     // cout<<u<<" "<<solve[u]<<endl;
    }
    string S;
    for(auto e:solve) S.pb(e);
    cout<<"! "<<S<<endl;
    return 0;
  }
}