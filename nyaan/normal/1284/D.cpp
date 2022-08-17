#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i,N) for(long long i = 0; i < (long long)(N); i++)
#define repr(i,N) for(long long i = (long long)(N) - 1; i >= 0; i--)
#define rep1(i,N) for(long long i = 1; i <= (long long)(N) ; i++)
#define repr1(i,N) for(long long i = (N) ; (long long)(i) > 0 ; i--)
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
using namespace std; void solve();
using ll = long long; template<class T = ll> using V = vector<T>;
using vi = V<int>; using vl = V<>; using vvi = V< V<int> >;
constexpr int inf = 1001001001; constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(7);} } iosetupnya;
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename T, typename U> ostream& operator <<(ostream& os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
template<typename T, typename U> istream& operator >>(istream& is, pair<T, U> &p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator <<(ostream& os, const vector<T> &v) { int s = (int)v.size(); rep(i,s) os << (i ? " " : "") << v[i]; return os; }
template<typename T> istream& operator >>(istream& is, vector<T> &v) { for(auto &x : v) is >> x; return is; }
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template<typename T>void die(T x){out(x); exit(0);}
#ifdef NyaanDebug
  #include "NyaanDebug.h"
  #define trc(...) do { cerr << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define trca(v,N) do { cerr << #v << " = "; array_out(v , N);cout << endl;} while(0)
#else
  #define trc(...)
  #define trca(...)
  int main(){solve();}
#endif
 
using P = pair<ll,ll>; using vp = V<P>;
constexpr int MOD = /**/ 1000000007; //*/ 998244353;
//////////
 
template<class T>
struct compress{
  vector<T> xs;
  compress(const vector<T>& v){
    xs.reserve(v.size());
    for(T x : v) xs.push_back(x);
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()) , xs.end());
  }

  int get(const T& x){
    return lower_bound(xs.begin(),xs.end(),x) - xs.begin();
  }
  int size(){
    return xs.size();
  }
  T& operator[](int i){
    return xs[i];
  }
};

// 
template <typename T,typename E,typename F,typename G,typename H>
struct LST{
  int n,height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  LST(int n, F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){
      init(n);
  }
  LST(const vector<T> &v, F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){
      init( (int)v.size() );
      build(v);
  }
  
  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  inline T reflect(int k){
    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
  }
  inline void eval(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }
  inline void thrust(int k){
    for(int i=height;i;i--) eval(k>>i);
  }
  inline void recalc(int k){    
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
  }
  void update(int a,int b,E x){
    thrust(a+=n);
    thrust(b+=n-1);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a,T x){
    thrust(a+=n);
    dat[a]=x;laz[a]=ei;
    recalc(a);
  }
  T query(int a,int b){
    thrust(a+=n);
    thrust(b+=n-1);
    T vl=ti,vr=ti;
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }
};

void solve(){
  ini(N);
  vi a(N) , b(N) , c(N) , d(N);
  rep(i , N)
    in(a[i] , b[i] , c[i] , d[i]);

  vi ord(N); iota(all(ord) , 0);
  sort(all(ord) , [&](int x,int y){
    return a[x]==a[y] ? b[x] < b[y] : a[x] < a[y];
  });

  vi unzip; unzip.pb(-1); unzip.pb(inf);
  rep(i , N){
    unzip.pb(c[i] - 1);
    unzip.pb(c[i]);
    unzip.pb(d[i]);
    unzip.pb(d[i] + 1);
  }
  compress<int> zip(unzip);

  // a
  auto f = [](P a,P b){
    return P( a.fi+b.fi, a.se+b.se );
  };
  auto gg = [](P a,ll b){
    return P( a.fi+b*a.se, a.se);
  };
  auto h = [](ll a,ll b){
    return a+b;
  };
  vector<P> v(zip.size() + 10 , P(0,1));
  LST<P,ll,decltype(f),decltype(gg),decltype(h)>
    lst (v,f,gg,h,P(0,0),0);  



  priority_queue<P , vp , greater<P> > Q;
  
  // 
  multiset<int> lmax , rmin;

  each(i , ord){
    
    // 
    while(!Q.empty() && Q.top().first < a[i]){
      auto p = Q.top(); Q.pop();
      lst.update(zip.get(c[p.second]) , zip.get(d[p.second]) , 1);
      lmax.erase(c[p.second]);
      rmin.erase(d[p.second]);
    }
    
    // pushc[i] d[i]
    int nya = lst.query(zip.get(c[i]) , zip.get(d[i]) + 1).first;
    if(nya != 0) die("NO");
  
    // a,b
    if(!lmax.empty() && *(lmax.rbegin()) > d[i]) die("NO");
    if(!rmin.empty() &&  *(rmin.begin()) < c[i]) die("NO");

    // 
    Q.emplace(b[i] , i);
    lmax.emplace(c[i]);
    rmin.emplace(d[i]);
  }
  
  out("YES");
}