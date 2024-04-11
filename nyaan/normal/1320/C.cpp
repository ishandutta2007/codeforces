#include <bits/stdc++.h>  // clang-format off
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)

#ifdef ONLINE_JUDGE
  #define rep(i,N) for(int i = 0; i < (int)(N); i++)
  #define repr(i,N) for(int i = (int)(N) - 1; i >= 0; i--)
  #define rep1(i,N) for(int i = 1; i <= (int)(N) ; i++)
  #define repr1(i,N) for(int i = (N) ; (int)(i) > 0 ; i--)
#else
  #define rep(i,N) for(long long i = 0; i < (long long)(N); i++)
  #define repr(i,N) for(long long i = (long long)(N) - 1; i >= 0; i--)
  #define rep1(i,N) for(long long i = 1; i <= (long long)(N) ; i++)
  #define repr1(i,N) for(long long i = (N) ; (long long)(i) > 0 ; i--)
#endif

using namespace std; void solve();
using ll = long long; template<class T = ll> using V = vector<T>;
using vi = V<int>; using vl = V<>; using vvi = V< V<int> >;
constexpr int inf = 1001001001; constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(7);} } iosetupnya;
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename T, typename U> ostream& operator <<(ostream& os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
template<typename T, typename U> istream& operator >>(istream& is, pair<T, U> &p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator <<(ostream& os, const vector<T> &v) { int s = (int)v.size(); for(int i=0;i<s;i++) os << (i ? " " : "") << v[i]; return os; }
template<typename T> istream& operator >>(istream& is, vector<T> &v) { for(auto &x : v) is >> x; return is; }
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template<typename T>void die(T x){out(x); exit(0);}

#ifdef NyaanDebug
  #include "NyaanDebug.h"
  #define trc(...) do { cerr << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define trca(v,N) do { cerr << #v << " = "; array_out(v , N);} while(0)
  #define trcc(v) do { cerr << "name : " << #v << "\n"; int cnt = 0; each(x , v){cerr << (cnt++) << " : "; trc(x); } } while(0)
#else
  #define trc(...)
  #define trca(...)
  #define trcc(...)
  int main(){solve();}
#endif

#define inc(...) char __VA_ARGS__; in(__VA_ARGS__)
#define in2(s,t)     rep(i,sz(s)){in(s[i] , t[i]);}
#define in3(s,t,u)   rep(i,sz(s)){in(s[i] , t[i] , u[i]);}
#define in4(s,t,u,v) rep(i,sz(s)){in(s[i] , t[i] , u[i] , v[i]);}
using vd = V<double>; using vs = V<string>; using vvl = V< V<> >;
template<typename T,typename U>ll ceil(T a,U b){return (a + b - 1) / b;}

using P = pair<int,int>; using vp = V<P>;
constexpr int MOD = /**/ 1000000007; //*/ 998244353;
// clang-format on
///////////////////////////////////////////////////////////

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
  ini(N , M , K);

  vp a(N) , b(M); in(a , b);

  vi x(K) , y(K) , z(K);
  in3(x , y , z);
  auto mkord = [&](int n , auto f) -> vector<int>{
    vector<int> ord(n);
    iota(begin(ord) , end(ord) , 0);
    sort(begin(ord) , end(ord) , f);
    return ord;
  };
  vector<int> ord = mkord(K, [&](int s,int t){
    return y[s] < y[t];
  });
  

  sort(all(a) , [&](P x,P y){
    return x.fi==y.fi ? x.se < y.se : x.fi > y.fi;
  });
  sort(all(b) , [&](P x,P y){
    return x.fi==y.fi ? x.se < y.se : x.fi > y.fi;
  });

  auto verify = [](vp a)->vp{
    vp ret;
    int mi = inf;
    each(p , a){
      if(mi > p.second){
        mi = p.second;
        ret.emplace_back(p);
      }
    }
    reverse(all(ret));
    return ret;
  };
  a = verify(a);
  b = verify(b);
  N = sz(a) , M = sz(b);
  trc(a);
  trc(b);

  // a
  using T = pair<ll, int>;
  using E = ll;
  constexpr T T_UNIT = T(-infLL, 0);
  constexpr E E_UNIT = 0;
  auto f = [](T a, T b){
    return T( max(a.fi, b.fi) , a.se + b.se);
  };
  auto gg = [](T a, E b){
    return T(a.fi + b, a.se);
  };
  auto h = [](E a, E b){
    return a + b;
  };

  vector<T> v(N + 1 , T(-infLL,1));
  rep(i , N) v[i].first = -a[i].second;
  LST<T, E, decltype(f), decltype(gg), decltype(h)>
    lst(v,f,gg,h,T_UNIT,E_UNIT);

  auto it = ord.begin();

  ll ans = -infLL;

  // y0 ~ M - 1
  rep(j , M){
    trc(j , b[j]);
    // 
    lst.update(0 , N , -b[j].second);
    // y
    
    //trc(x[*it] , y[*it] , z[*it]);
    while(it != end(ord) && y[*it] < b[j].first){
      trc(x[*it] , y[*it] , z[*it]);
      auto nya = lower_bound(all(a) , P(x[*it] , inf));
      int nyaa = nya - a.begin();
      trc(nyaa);
      // [nyaa , N)
      if(nyaa != N) lst.update(nyaa , N , z[*it]);
      it++;
    }
    rep(i , N){trc(lst.query(i , i + 1));}
    // 
    amax(ans , lst.query(0 , N).first);
    
    // 
    lst.update(0 , N , b[j].second);
  }

  out(ans);

  
}