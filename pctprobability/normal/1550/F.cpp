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
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define fi first
#define se second
#define pb push_back
#define P pair<ll,ll>
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 4500000000000000000ll;
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
  cout<< fixed << setprecision(20);
}
struct PartiallyPersistentUnionFind {
  vector< int > data;
  vector< int > last;
  vector< vector< pair< int, int > > > add;

  PartiallyPersistentUnionFind() {}

  PartiallyPersistentUnionFind(int sz) : data(sz, -1), last(sz, 1e9), add(sz) {
    for(auto &vs : add) vs.emplace_back(-1, -1);
  }

  bool unite(int t, int x, int y) {
    x = find(t, x);
    y = find(t, y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    add[x].emplace_back(t, data[x]);
    data[y] = x;
    last[y] = t;
    return true;
  }

  int find(int t, int x) {
    if(t < last[x]) return x;
    return find(t, data[x]);
  }

  int size(int t, int x) {
    x = find(t, x);
    return -prev(lower_bound(begin(add[x]), end(add[x]), make_pair(t, 0)))->second;
  }
};
int main() {
  cincout();
  ll n,Q,s,d;
  cin>>n>>Q>>s>>d;
  s--;
  vector<ll> a(n);
  vcin(a);
  priority_queue<pair<ll,P>, vector<pair<ll,P>>, greater<pair<ll,P>>> pq;
  map<ll,ll> z;
  for(int i=0;i<n;i++) z[a[i]]=i;
  z[inf]=z[-inf]=-1;
  for(int i=0;i<=0;i++){
    auto p=z.lower_bound(a[i]-d);
    auto q=*p;
    pq.push({abs(q.fi-(a[i]-d)),{i,q.se}});
    p--;
    auto q2=*p;
    pq.push({abs(q2.fi-(a[i]-d)),{i,q2.se}});
  }
  for(int i=0;i<=0;i++){
    auto p=z.lower_bound(a[i]+d);
    auto q=*p;
    pq.push({abs(q.fi-(a[i]+d)),{i,q.se}});
    p--;
    auto q2=*p;
    pq.push({abs(q2.fi-(a[i]+d)),{i,q2.se}});
  }
  ll now=1;
  vector<ll> edge;
  PartiallyPersistentUnionFind t(n);
  vector<pair<ll,P>> e;
  while(!pq.empty()){
    auto u=pq.top();
    pq.pop();
    ll from=u.se.fi;
    ll to=u.se.se;
    if(to==-1) continue;
    if(z.count(a[to])==0) continue;
   // edge.pb(abs(d-abs(a[from]-a[to])));
    //t.unite(now,from,to);
    e.pb({abs(d-abs(a[from]-a[to])),{from,to}});
   // cout<<now<<" "<<abs(d-abs(a[from]-a[to]))<<" "<<to<<" "<<from<<endl;
  //  now++;
    z.erase(a[to]);
    ll ne=a[from]-d;
    {
    auto p=z.lower_bound(ne);
    auto q=*p;
    pq.push({abs(q.fi-ne),{from,q.se}});
    p--;
    auto q2=*p;
    pq.push({abs(q2.fi-ne),{from,q2.se}});
    }
    {
    ne=a[from]+d;
    auto p=z.lower_bound(ne);
    auto q=*p;
    pq.push({abs(q.fi-ne),{from,q.se}});
    p--;
    auto q2=*p;
    pq.push({abs(q2.fi-ne),{from,q2.se}});
    }
    {
    ne=a[to]-d;
    auto p=z.lower_bound(ne);
    auto q=*p;
    pq.push({abs(q.fi-ne),{to,q.se}});
    p--;
    auto q2=*p;
    pq.push({abs(q2.fi-ne),{to,q2.se}});
    }
    {
    ne=a[to]+d;
    auto p=z.lower_bound(ne);
    auto q=*p;
    pq.push({abs(q.fi-ne),{to,q.se}});
    p--;
    auto q2=*p;
    pq.push({abs(q2.fi-ne),{to,q2.se}});
    }
  }
  sor(e);
  for(int i=0;i<e.size();i++){
  //  cout<<e[i].fi<<" "<<e[i].se.fi<<" "<<e[i].se.se<<endl;
    t.unite(i+1,e[i].se.fi,e[i].se.se);
    edge.pb(e[i].fi);
  }
  edge.pb(inf);
  while(Q--){
    ll x,y;
    cin>>x>>y;
    x--;
    ll p=upper_bound(all(edge),y)-edge.begin();
   // cout<<p<<" "<<y<<endl;
   // p--;
    chmax(p,0ll);
  //  cout<<p<<" "<<x<<" "<<s<<endl;
    Yes(t.find(p,x)==t.find(p,s));
  }
}