#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define endl "\n"
typedef pair<int, int> Pii;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(s) (s).begin(),(s).end()
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
#define PQminll priority_queue<ll, vector<ll>, greater<ll>>
#define PQmaxll priority_queue<ll,vector<ll>,less<ll>>
#define PQminP priority_queue<P, vector<P>, greater<P>>
#define PQmaxP priority_queue<P,vector<P>,less<P>>
#define NP next_permutation
typedef string::const_iterator State;
class ParseError {};
//const ll mod = 1000000009;
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 4100000000000000000ll;
const ld eps = ld(0.00000000001);
//static const long double pi = 3.141592653589793;
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
ll fastgcd(ll u,ll v){ll shl=0;while(u&&v&&u!=v){bool eu=!(u&1);bool ev=!(v&1);if(eu&&ev){++shl;u>>=1;v>>=1;}else if(eu&&!ev){u>>=1;}else if(!eu&&ev){v>>=1;}else if(u>=v){u=(u-v)>>1;}else{ll tmp=u;u=(v-u)>>1;v=tmp;}}return !u?v<<shl:u<<shl;}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll x){return __builtin_popcountll(x);}
ll poplong(ll x){ll y=-1;while(x){x/=2;y++;}return y;}
P hyou(P a){ll x=fastgcd(abs(a.fi),abs(a.se));a.fi/=x;a.se/=x;if(a.se<0){a.fi*=-1;a.se*=-1;}return a;}
P Pplus(P a,P b){ return hyou({a.fi*b.se+b.fi*a.se,a.se*b.se});}
P Ptimes(P a,ll b){ return hyou({a.fi*b,a.se});}
P Ptimes(P a,P b){ return hyou({a.fi*b.fi,a.se*b.se});}
P Pminus(P a,P b){ return hyou({a.fi*b.se-b.fi*a.se,a.se*b.se});}
P Pgyaku(P a){ return hyou({a.se,a.fi});}

void cincout(){
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(15);
}
int main() {
  cincout();
  ll n,q;
  cin>>n>>q;
  if(q==0){
    cout<<(modPow(2,modPow(2,n,mod-1)-2,mod)*modPow(2,modPow(2,n,mod-1)-1,mod)%mod*3%mod)<<endl;
    return 0;
  }
  map<ll,vector<P>> m;
  map<string,ll> c;
  c["white"]=0;
  c["yellow"]=0;
  c["green"]=1;
  c["blue"]=1;
  c["red"]=2;
  c["orange"]=2;
  for(int i=0;i<q;i++){
    ll x;
    cin>>x;
    string s;
    cin>>s;
    ll y=c[s];
    m[poplong(x)].pb({x,y});
  }
  for(auto &e:m) sor(e.se);
  vector<ll> now;
  map<ll,vector<ll>> x;
  ll G=1;
  for(int i=n-1;i>=0;i--){
    map<ll,vector<ll>> y;
    auto z=x;
    map<ll,ll> seen;
    for(auto e:m[i]){
      if(i==n-1){
        y[e.fi]={1,1,1};
        for(int ii=0;ii<3;ii++){
          if(e.se!=ii) y[e.fi][ii]=0;
        }
      }
      else{
        auto A=now,B=now;
        if(z[e.fi*2].size()==3){
          seen[e.fi*2]=1;
          A=z[e.fi*2];
        }
        if(z[e.fi*2+1].size()==3){
          B=z[e.fi*2+1];
          seen[e.fi*2+1]=1;
        }
        vector<ll> res(3);
        for(int X=0;X<3;X++){
          for(int Y=0;Y<3;Y++){
            for(int Z=0;Z<3;Z++){
              if(X!=Z&&Y!=Z) (res[Z]+=A[X]*B[Y])%=mod;
            }
          }
        }
        for(int ii=0;ii<3;ii++){
          if(e.se!=ii) res[ii]=0;
        }
        y[e.fi]=res;
      }
    }
    for(auto e:x){
      if(seen[e.fi]) continue;
      if(e.fi%2==0){
        if(z[e.fi+1].size()==3){
          seen[e.fi+1]=1;
          auto A=e.se,B=x[e.fi+1];
          vector<ll> res(3);
          for(int X=0;X<3;X++){
            for(int Y=0;Y<3;Y++){
              for(int Z=0;Z<3;Z++){
                if(X!=Z&&Y!=Z) (res[Z]+=A[X]*B[Y])%=mod;
              }
            }
          }
          y[e.fi/2]=res;
        }
        else{
          auto A=e.se,B=now;
          vector<ll> res(3);
          for(int X=0;X<3;X++){
            for(int Y=0;Y<3;Y++){
              for(int Z=0;Z<3;Z++){
                if(X!=Z&&Y!=Z) (res[Z]+=A[X]*B[Y])%=mod;
              }
            }
          }
          y[e.fi/2]=res;
        }
      }
      else{
        if(z[e.fi-1].size()==3){
          seen[e.fi-1]=1;
          auto A=e.se,B=x[e.fi-1];
          vector<ll> res(3);
          for(int X=0;X<3;X++){
            for(int Y=0;Y<3;Y++){
              for(int Z=0;Z<3;Z++){
                if(X!=Z&&Y!=Z) (res[Z]+=A[X]*B[Y])%=mod;
              }
            }
          }
          y[e.fi/2]=res;
        }
        else{
          auto A=e.se,B=now;
          vector<ll> res(3);
          for(int X=0;X<3;X++){
            for(int Y=0;Y<3;Y++){
              for(int Z=0;Z<3;Z++){
                if(X!=Z&&Y!=Z) (res[Z]+=A[X]*B[Y])%=mod;
              }
            }
          }
          y[e.fi/2]=res;
        }
      }
    }
    if(i==n-1){
      now={1,1,1};
    }
    else{
      now[0]=modPow(2,modPow(2,G,mod-1)-2,mod);
      now[1]=modPow(2,modPow(2,G,mod-1)-2,mod);
      now[2]=modPow(2,modPow(2,G,mod-1)-2,mod);
      now[0]%=mod;
      now[1]%=mod;
      now[2]%=mod;
    }
    x=y;
    G++;
  }
  //cout<<x[1].size()<<endl;
  ll sum=(x[1][0]+x[1][1]+x[1][2]);
  sum%=mod;
  cout<<(sum*modPow(2,(mod-1)*2+modPow(2,n,mod-1)-1-q,mod)%mod)<<endl;
}