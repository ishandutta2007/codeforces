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
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
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
const ll mod = 998244353;
//const ll mod = 1000000007;
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
#define def2 0
using V = ll;
V comp2(V& l, V& r) { return max(l,r); };
struct SegTree2 { //[l,r)
    int NV;
    vector<V> val;
    void init(int n) {
        NV = 1;
        while (NV < n) NV *= 2;
        val = vector<V>(NV * 2, def2);
    }
    V get(int x, int y, int l, int r, int k) {
        if (r <= x || y <= l) return def2;
      if (x <= l&&r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2); auto b = get(x, y, (l + r) / 2, r, k * 2 + 1); return comp2(a, b);
    }
    V get(int x, int y) { return get(x, y, 0, NV, 1); }
    void update(int i, V v) { i += NV; val[i] = v; while (i>1)i >>= 1, val[i] = comp2(val[i * 2], val[i * 2 + 1]); }
    void add(int i, V v) { update(i, val[i + NV] + v); }
    V operator[](int x) { return get(x, x + 1); }
};
 
struct Healthy2DSegTree {
    int NV;
    vector<SegTree2> st;
    vector<vector<int>> index;
 
    void init(vector<vector<int>> &v) {
        int n = v.size();
        NV = 1; while (NV < n) NV *= 2;
        index.resize(2 * NV);
        rep(i, 0, n) fore(j, v[i]) index[i + NV].push_back(j);
        rrep(i, NV * 2 - 1, 1) {
            sort(index[i].begin(), index[i].end());
            index[i].erase(unique(index[i].begin(), index[i].end()), index[i].end());
            fore(j, index[i]) index[i / 2].push_back(j);
        }
        st.resize(2 * NV);
        rep(i, 1, NV * 2) st[i].init(index[i].size());
    }
    void update(int x, int y, V v) {
        assert(x < NV);
        x += NV;
        while (x) {
            int yy = lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
            assert(yy != index[x].size());
            assert(y == index[x][yy]);
            st[x].update(yy, v);
            x >>= 1;
        }
    }
    void add(int x, int y, V v) {
        assert(x < NV);
        x += NV;
        while (x) {
            int yy = lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
            assert(yy != index[x].size());
            assert(y == index[x][yy]);
            st[x].add(yy, v);
            x >>= 1;
        }
    }
    V get(int sx, int tx, int sy, int ty, int k, int l, int r) {
        assert(k < NV * 2);
        assert(l < r);
        if (r <= sx or tx <= l) return def2;
        if (sx <= l and r <= tx) {
            int syy = lower_bound(index[k].begin(), index[k].end(), sy) - index[k].begin();
            int tyy = lower_bound(index[k].begin(), index[k].end(), ty) - index[k].begin();
            return st[k].get(syy, tyy);
        }
        int md = (l + r) / 2;
        V le = get(sx, tx, sy, ty, k * 2, l, md);
        V ri = get(sx, tx, sy, ty, k * 2 + 1, md, r);
        return comp2(le, ri);
    }
    V get(int sx, int tx, int sy, int ty) {
        return get(sx, tx, sy, ty, 1, 0, NV);
    }
};
int main() {
  cincout();
  Healthy2DSegTree stmax;
  ll n;
  cin>>n;
  vector<ll> a(n);
  vcin(a);
  for(auto &e:a) e--;
  vector<ll> b(n);
  for(int i=0;i<n;i++) b[i]=i-a[i];
  vector<vector<int>> u(n+10);
  for(int i=0;i<n;i++){
    if(a[i]>=0&&b[i]>=0) u[a[i]].pb(b[i]);
  }
  stmax.init(u);
  for(int i=0;i<n;i++){
    if(a[i]>=0&&b[i]>=0){
      ll q=stmax.get(0,a[i],0,b[i]+1);
      stmax.update(a[i],b[i],q+1);
    }
  }
  cout<<stmax.get(0,n+5,0,n+5)<<endl;
}