#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = int;
using ld = long double;
using ull = unsigned long long;
#define endl "\n"
typedef pair<int, int> Pii;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define PB push_back
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
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 41000000;
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
#define INF INT_MAX/2
#define def INF
using V = int;
V comp(V& l, V& r) { return min(l,r); };
struct SegTree { //[l,r)
    int NV;
    vector<V> val;
    void init(int n) {
        NV = 1;
        while (NV < n) NV *= 2;
        val = vector<V>(NV * 2, def);
    }
    V get(int x, int y, int l, int r, int k) {
        if (r <= x || y <= l) return def; if (x <= l&&r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2); auto b = get(x, y, (l + r) / 2, r, k * 2 + 1); return comp(a, b);
    }
    V get(int x, int y) { return get(x, y, 0, NV, 1); }
    void update(int i, V v) { i += NV; val[i] = v; while (i>1)i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]); }
    void compupdate(int i, V v) { update(i, comp(v, val[i + NV])); }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
};
 
struct StaticHealthy2DSegTree {
    int NV;
    vector<SegTree> st;
    vector<vector<int>> index;
    
    void init(vector<vector<pair<int,V>>> &v) {
        int n = v.size();
        NV = 1; while (NV < n) NV *= 2;
        int nn = 2 * NV;
        index.resize(nn);
        rep(i, 0, n) fore(p, v[i]) index[i + NV].push_back(p.first);
        rrep(i, nn - 1, 1) {
            sort(index[i].begin(), index[i].end());
            index[i].erase(unique(index[i].begin(), index[i].end()), index[i].end());
            int jj = i / 2;
            fore(j, index[i]) index[jj].push_back(j);
        }
        st.resize(nn);
        rep(i, 1, nn) st[i].init(index[i].size());
        
        rep(i, 0, n) {
            int ii = i + NV;
            fore(p, v[i]) {
                int j = lower_bound(index[ii].begin(), index[ii].end(), p.first) - index[ii].begin();
                st[ii].update(j, p.second);
            }
        }
 
        rrep(i, nn - 1, 2) {
            int jj = i / 2;
            rep(j, 0, index[i].size()) {
                V v = st[i][j];
                
                int k = lower_bound(index[jj].begin(), index[jj].end(), index[i][j]) - index[jj].begin();
                st[jj].compupdate(k, v);
            }
        }
    }
    V get(int sx, int tx, int sy, int ty, int k, int l, int r) {
        //assert(k < NV * 2);
        //assert(l < r);
        if (r <= sx or tx <= l) return def;
        if (sx <= l and r <= tx) {
            int syy = lower_bound(index[k].begin(), index[k].end(), sy) - index[k].begin();
            int tyy = lower_bound(index[k].begin(), index[k].end(), ty) - index[k].begin();
            return st[k].get(syy, tyy);
        }
        int md = (l + r) / 2;
        V le = get(sx, tx, sy, ty, k * 2, l, md);
        V ri = get(sx, tx, sy, ty, k * 2 + 1, md, r);
        return comp(le, ri);
    }
    V get(int sx, int tx, int sy, int ty) {
        return get(sx, tx, sy, ty, 1, 0, NV);
    }
};
void solve(){
  ll h,w;
  cin>>h>>w;
  vector<vector<ll>> a(h,vector<ll>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        cin>>a[i][j];
    }
  }
  vector<pair<vector<ll>,ll>> x(h);
  for(int i=0;i<h;i++) x[i]={a[i],i};
  sor(x);
  //[0,a),[0,b)  max
  //[a,h),[0,b)  min
  //[0,a),[b,w)  min
  //[a,h),[b,w)  max
  vector<vector<int>> D1(h+1,vector<int>(w+1)),D2,D3,D4;
  D2=D1;
  D3=D2;
  D4=D3;
  for(int i=0;i<=h;i++){
      for(int j=0;j<=w;j++){
          D1[i][j]=-10000;
          if(i) chmax(D1[i][j],D1[i-1][j]);
          if(j) chmax(D1[i][j],D1[i][j-1]);
          if(i&&j) chmax(D1[i][j],x[i-1].fi[j-1]);
      }
  }
  for(int i=h-1;i>=0;i--){
      for(int j=0;j<=w;j++){
          D2[i][j]=1000000000;
          if(i!=h-1) chmin(D2[i][j],D2[i+1][j]);
          if(j) chmin(D2[i][j],D2[i][j-1]);
          if(j) chmin(D2[i][j],x[i].fi[j-1]);
      }
  }
  for(int i=0;i<h;i++){
      for(int j=w-1;j>=0;j--){
          D3[i][j]=1000000000;
          if(i) chmin(D3[i][j],D3[i-1][j]);
          if(j!=w-1) chmin(D3[i][j],D3[i][j+1]);
          if(i) chmin(D3[i][j],x[i-1].fi[j]);
      }
  }
  for(int i=h-1;i>=0;i--){
      for(int j=w-1;j>=0;j--){
          D4[i][j]=-10000;
          if(i!=h-1) chmax(D4[i][j],D4[i+1][j]);
          if(j!=w-1) chmax(D4[i][j],D4[i][j+1]);
          chmax(D4[i][j],x[i].fi[j]);
      }
  }
  for(int i=0;i<h-1;i++){
    if(x[i].fi[0]==x[i+1].fi[0]) continue;
    ll ok=0,ng=w;
    while(abs(ok-ng)>1){
      ll t=(ok+ng)/2;
      if(D1[i+1][t]<D2[i+1][t]){
        ok=t;
      }
      else{
        ng=t;
      }
    }
    chmax(ok,1);
    chmin(ok,w-1);
   // cout<<i<<" "<<ok<<" "<<h<<" "<<D1[i+1][ok]<<" "<<D2[i+1][ok]<<" "<<D3[i+1][ok]<<" "<<D4[i+1][ok]<<endl;
    if(D1[i+1][ok]<D2[i+1][ok]&&D3[i+1][ok]>D4[i+1][ok]){
      cout<<"YES"<<endl;
      vector<char> ans(h);
      for(int j=0;j<h;j++){
        if(i>=j) ans[x[j].se]='B';
        else ans[x[j].se]='R';
      }
      for(auto e:ans) cout<<e;
      cout<<" "<<ok<<endl;
      return;
    }
  }
  cout<<"NO"<<endl;
}

int main() {
  cincout();
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}