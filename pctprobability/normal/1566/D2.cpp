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
using ull = unsigned long long;
#define endl "\n"
typedef pair<int, int> Pii;
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
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
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
ll fastgcd(ll u,ll v){ll shl=0;while(u&&v&&u!=v){bool eu=!(u&1);bool ev=!(v&1);if(eu&&ev){++shl;u>>=1;v>>=1;}else if(eu&&!ev){u>>=1;}else if(!eu&&ev){v>>=1;}else if(u>=v){u=(u-v)>>1;}else{ll tmp=u;u=(v-u)>>1;v=tmp;}}return !u?v<<shl:u<<shl;}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll x){return __builtin_popcountll(x);}
ll poplong(ll x){ll y=-1;while(x){x/=2;y++;}return y;}
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
class SegmentTree {
  static const ll inf = 1e18;
  struct Node {
    Node *left, *right;
    ll max_v, smax_v, max_c;
    ll min_v, smin_v, min_c;
    ll sum;
    ll len, ladd, lval;
 
    Node() : left(0), right(0), ladd(0), lval(inf) {}
 
    void init(ll x) {
      max_v = min_v = sum = x;
      smax_v = -inf; smin_v = inf;
      max_c = min_c = 1;
    }
 
    void init_empty() {
      max_v = smax_v = -inf;
      min_v = smin_v = inf;
      max_c = min_c = 0;
    }
 
    void update_max(ll x) {
      sum += (x - max_v) * max_c;
 
      if(max_v == min_v) {
        max_v = min_v = x;
      } else if(max_v == smin_v) {
        max_v = smin_v = x;
      } else {
        max_v = x;
      }
 
      if(lval != inf && x < lval) {
        lval = x;
      }
    }
 
    void update_min(ll x) {
      sum += (x - min_v) * min_c;
 
      if(max_v == min_v) {
        max_v = min_v = x;
      } else if(max_v == smin_v) {
        min_v = smax_v = x;
      } else {
        min_v = x;
      }
 
      if(lval != inf && lval < x) {
        lval = x;
      }
    }
 
    void addall(ll x) {
      max_v += x;
      if(smax_v != -inf) smax_v += x;
      min_v += x;
      if(smin_v != inf) smin_v += x;
 
      sum += len * x;
      if(lval != inf) {
        lval += x;
      } else {
        ladd += x;
      }
    }
 
    void updateall(ll x) {
      max_v = min_v = x;
      smax_v = -inf; smin_v = inf;
      max_c = min_c = len;
 
      sum = len * x;
      lval = x; ladd = 0;
    }
 
    void push() {
 
      if(lval != inf) {
        left->updateall(lval);
        right->updateall(lval);
        lval = inf;
        return;
      }
 
      if(ladd != 0) {
        left->addall(ladd);
        right->addall(ladd);
        ladd = 0;
      }
 
      if(max_v < left->max_v) {
        left->update_max(max_v);
      }
      if(left->min_v < min_v) {
        left->update_min(min_v);
      }
 
      if(max_v < right->max_v) {
        right->update_max(max_v);
      }
      if(right->min_v < min_v) {
        right->update_min(min_v);
      }
    }
 
    void update() {
      sum = left->sum + right->sum;
 
      if(left->max_v < right->max_v) {
        max_v = right->max_v;
        max_c = right->max_c;
        smax_v = max(left->max_v, right->smax_v);
      } else if(left->max_v > right->max_v) {
        max_v = left->max_v;
        max_c = left->max_c;
        smax_v = max(left->smax_v, right->max_v);
      } else {
        max_v = left->max_v;
        max_c = left->max_c + right->max_c;
        smax_v = max(left->smax_v, right->smax_v);
      }
 
      if(left->min_v < right->min_v) {
        min_v = left->min_v;
        min_c = left->min_c;
        smin_v = min(left->smin_v, right->min_v);
      } else if(left->min_v > right->min_v) {
        min_v = right->min_v;
        min_c = right->min_c;
        smin_v = min(left->min_v, right->smin_v);
      } else {
        min_v = left->min_v;
        min_c = left->min_c + right->min_c;
        smin_v = min(left->smin_v, right->smin_v);
      }
    }
  };
 
  int n, n0;
  Node *root;
 
  void _update_min(ll x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a || nd->max_v <= x) {
      return;
    }
    if(a <= l && r <= b && nd->smax_v < x) {
      nd->update_max(x);
      return;
    }
 
    nd->push();
    _update_min(x, a, b, nd->left, l, (l+r)/2);
    _update_min(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }
 
  void _update_max(ll x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a || x <= nd->min_v) {
      return;
    }
    if(a <= l && r <= b && x < nd->smin_v) {
      nd->update_min(x);
      return;
    }
 
    nd->push();
    _update_max(x, a, b, nd->left, l, (l+r)/2);
    _update_max(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }
 
  void _add_val(ll x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return;
    }
    if(a <= l && r <= b) {
      nd->addall(x);
      return;
    }
 
    nd->push();
    _add_val(x, a, b, nd->left, l, (l+r)/2);
    _add_val(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }
 
  void _update_val(ll x, int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return;
    }
    if(a <= l && r <= b) {
      nd->updateall(x);
      return;
    }
 
    nd->push();
    _update_val(x, a, b, nd->left, l, (l+r)/2);
    _update_val(x, a, b, nd->right, (l+r)/2, r);
    nd->update();
  }
 
  ll _query_max(int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return -inf;
    }
    if(a <= l && r <= b) {
      return nd->max_v;
    }
    nd->push();
    ll lv = _query_max(a, b, nd->left, l, (l+r)/2);
    ll rv = _query_max(a, b, nd->right, (l+r)/2, r);
    return max(lv, rv);
  }
 
  ll _query_min(int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return inf;
    }
    if(a <= l && r <= b) {
      return nd->min_v;
    }
    nd->push();
    ll lv = _query_min(a, b, nd->left, l, (l+r)/2);
    ll rv = _query_min(a, b, nd->right, (l+r)/2, r);
    return min(lv, rv);
  }
 
  ll _query_sum(int a, int b, Node *nd, int l, int r) {
    if(b <= l || r <= a) {
      return 0;
    }
    if(a <= l && r <= b) {
      return nd->sum;
    }
    nd->push();
    ll lv = _query_sum(a, b, nd->left, l, (l+r)/2);
    ll rv = _query_sum(a, b, nd->right, (l+r)/2, r);
    return lv + rv;
  }
 
public:
  SegmentTree(int n, vector<ll> a) : n(n) {
    n0 = 1;
    while(n0 < n) n0 <<= 1;
 
    Node *nds = new Node[2*n0];
    root = nds;
 
    nds[0].len = n0;
    for(int i=0; i<n0-1; ++i) {
      nds[i].left = &nds[2*i+1];
      nds[i].right = &nds[2*i+2];
      nds[2*i+1].len = nds[2*i+2].len = (nds[i].len >> 1);
    }
 
    for(int i=0; i<n; ++i) nds[n0-1+i].init(a[i]);
    for(int i=n; i<n0; ++i) nds[n0-1+i].init_empty();
    for(int i=n0-2; i>=0; i--) nds[i].update();
  }
 
  void update_min(int a, int b, ll x) {
    _update_min(x, a, b, root, 0, n0);
  }
 
  void update_max(int a, int b, ll x) {
    _update_max(x, a, b, root, 0, n0);
  }
 
  void add_val(int a, int b, ll x) {
    _add_val(x, a, b, root, 0, n0);
  }
 
  void update_val(int a, int b, ll x) {
    _update_val(x, a, b, root, 0, n0);
  }
 
  ll query_max(int a, int b) {
    return _query_max(a, b, root, 0, n0);
  }
 
  ll query_min(int a, int b) {
    return _query_min(a, b, root, 0, n0);
  }
 
  ll query_sum(int a, int b) {
    return _query_sum(a, b, root, 0, n0);
  }
};
vector<ll> compress(vector<ll> arr){
  ll n=arr.size();
  map<ll,ll> m;
  for(int i=0;i<n;i++){
    m[arr[i]]=0;
  }
  ll s=0;
  for(auto& i:m){
    i.second=s++;
  }
  vector<ll> ans;
  for(int i=0;i<n;i++){
    ans.push_back(m[arr[i]]);
  }
  return ans;
}
void solve(){
  ll n,m;
  cin>>n>>m;
  vector<ll> z;
  vector<vector<ll>> now(n*m);
  for(int i=0;i<n*m;i++){
    ll s;
    cin>>s;
    z.pb(s);
  }
  z=compress(z);
  for(int i=0;i<n*m;i++){
    now[z[i]].pb(i);
  }
  for(int i=0;i<n*m;i++){
    sor(now[i]);
  }
  vector<vector<ll>> tmp(n,vector<ll>(m,inf));
  ll ans=0;
  ll p=0,q=0;
  for(int i=0;i<n*m;i++){
  //  cerr<<i<<" "<<p<<" "<<q<<" "<<now[i].size()<<" "<<ans<<endl;
    if(now[i].size()==0) continue;
    int f=now[i].size(),g=0;
    while(m-q<=f){
      for(int j=m-1;j>=0;j--){
        if(tmp[p][j]!=inf) break;
        tmp[p][j]=now[i][g];
        for(int x=0;x<j;x++){
         // cout<<"K"<<" "<<tmp[p][x]<<" "<<now[i][g]<<endl;
          if(tmp[p][x]<now[i][g]) ans++;
        }
        g++;
        f--;
      }
      p++;
      q=0;
    }
    if(f){
     // cout<<"X"<<" "<<i<<endl;
      rever(now[i]);
      for(int j=0;j<f;j++){
        for(int x=0;x<q;x++){
         // cout<<"K"<<" "<<tmp[p][x]<<" "<<now[i][j]<<endl;
          if(tmp[p][x]<now[i][j]) ans++;
        }
        tmp[p][q]=now[i][j];
        q++;
      }
    }
  }
 /* for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<tmp[i][j]<<" ";
    }
    cout<<endl;
  }*/
  cout<<ans<<endl;
}
int main() {
  cincout();
  ll t;
  cin>>t;
  //t=1;
  while(t--){
    solve();
  }
}