#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define endl "\n"
typedef pair<int, int> Pii;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
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
#define PQminll priority_queue<ll, vector<ll>, greater<ll>>
#define PQmaxll priority_queue<ll,vector<ll>,less<ll>>
#define PQminP priority_queue<P, vector<P>, greater<P>>
#define PQmaxP priority_queue<P,vector<P>,less<P>>
#define NP next_permutation
//const ll mod = 1000000009;
//const ll mod = 998244353;
const ll Mod = 1000000007;
const ll inf = 4100000000000000000ll;
const ld eps = ld(0.00000000001);
const long double pi = 3.141592653589793;
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
ll fastgcd(ll u,ll v){ll shl=0;while(u&&v&&u!=v){bool eu=!(u&1);bool ev=!(v&1);if(eu&&ev){++shl;u>>=1;v>>=1;}else if(eu&&!ev){u>>=1;}else if(!eu&&ev){v>>=1;}else if(u>=v){u=(u-v)>>1;}else{ll tmp=u;u=(v-u)>>1;v=tmp;}}return !u?v<<shl:u<<shl;}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll x){return __builtin_popcountll(x);}
ll poplong(ll x){ll y=-1;while(x){x/=2;y++;}return y;}
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

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
  cout<< fixed << setprecision(15);
}

int main() {
  cincout();
  ll n,k;
  cin>>n>>k;
  vector<ld> a(n),b(n);
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
  }
  ld ok=200000,ng=0;
  ll ka=40;
  while(ka--){
    ld t=(ok+ng)/2.0;
    bool check=false;
    ll now=0;
    vector<pair<ld,pair<int,int>>> ivent;
    for(int i=0;i<n;i++){
      if(sqrt(a[i]*a[i]+b[i]*b[i])>2*t){
       // if(t<=5) cout<<i<<endl;
        continue;
      }
      if((a[i]-(t))*(a[i]-(t))+b[i]*b[i]<=t*t){
       // cout<<i<<endl;
        now++;
      }
      if(a[i]==0&&b[i]==0) continue;
      vector<ld> s;
      if(a[i]==0){
        ld x=sqrt(4*t*t-b[i]*b[i])/2.0,y=b[i]/2.0;
        s.pb(atan2(y,x));
        x*=-1;
        s.pb(atan2(y,x));
      }
      if(b[i]==0){
        ld x=a[i]/2.0,y=sqrt(4*t*t-a[i]*a[i])/2.0;
        s.pb(atan2(y,x));
        y*=-1;
        s.pb(atan2(y,x));
      }
      if(a[i]!=0&&b[i]!=0){
        ld x=(a[i]*a[i]*a[i]-sqrt(-b[i]*b[i]*(a[i]*a[i]+b[i]*b[i])*(a[i]*a[i]+b[i]*b[i]-4*t*t))+a[i]*b[i]*b[i])/((a[i]*a[i]+b[i]*b[i])*2.0);
        ld y=(a[i]*sqrt(-b[i]*b[i]*(a[i]*a[i]+b[i]*b[i])*(a[i]*a[i]+b[i]*b[i]-4*t*t))+a[i]*a[i]*b[i]*b[i]+b[i]*b[i]*b[i]*b[i])/(2.0*a[i]*a[i]*b[i]+2.0*b[i]*b[i]*b[i]);
        s.pb(atan2(y,x));
       // if(t<=5) cout<<x<<" "<<y<<endl;
        y=(-a[i]*sqrt(-b[i]*b[i]*(a[i]*a[i]+b[i]*b[i])*(a[i]*a[i]+b[i]*b[i]-4*t*t))+a[i]*a[i]*b[i]*b[i]+b[i]*b[i]*b[i]*b[i])/(2.0*a[i]*a[i]*b[i]+2.0*b[i]*b[i]*b[i]);
        x=(a[i]*a[i]*a[i]+sqrt(-b[i]*b[i]*(a[i]*a[i]+b[i]*b[i])*(a[i]*a[i]+b[i]*b[i]-4*t*t))+a[i]*b[i]*b[i])/((a[i]*a[i]+b[i]*b[i])*2.0);
        s.pb(atan2(y,x));
       // if(t<=5) cout<<x<<" "<<y<<endl;
      }
      for(auto &e:s){
        while(e<0) e+=pi*2;
      }
      sor(s);
     /* if(i==2){
        cout<<s[0]<<" "<<s[1]<<" "<<t<<" "<<t*t-((a[i]-(t))*(a[i]-(t))+b[i]*b[i])<<endl;
      }*/
   //   if(t<=5) for(auto e:s) cout<<e<<" ";
    //  if(t<=5) cout<<endl;
      if((a[i]-(t))*(a[i]-(t))+b[i]*b[i]<=t*t){
        ivent.pb({s[0],{-1,i}});
        ivent.pb({s[1],{1,i}});
      }
      else{
        ivent.pb({s[0],{1,i}});
        ivent.pb({s[1],{-1,i}});
      }
    }
    sor(ivent);
   // cout<<t<<" "<<now<<endl;
    if(now>=k) check=true;
    for(auto e:ivent){
      now+=e.se.fi;
      //if(t<=5) cout<<e.fi<<" "<<e.se.fi<<" "<<e.se.se<<" "<<now<<endl;
      if(now>=k) check=true;
    }
    if(check){
      ok=t;
    }
    else{
      ng=t;
    }
  }
  cout<<ok<<endl;
}