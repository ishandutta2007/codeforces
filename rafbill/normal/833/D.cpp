// #ifndef __clang__
// #pragma GCC optimize "-O3"
// #pragma GCC target "tune=native"
// #endif
#ifdef ONLINE_JUDGE
#define NDEBUG 1
#endif
#include <stdio.h>
#include <bits/stdc++.h>

#define DESTRUCT2(p, a, b)                      \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);

#define DESTRUCT3(p, a, b, c)                   \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);                           \
  auto c = get<2>(p);

#define DESTRUCT4(p, a, b, c, d)                \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);                           \
  auto c = get<2>(p);                           \
  auto d = get<3>(p);

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define SQ(x) ((x)*(x))

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

using namespace std;

template<typename... As>
struct tpl : public std::tuple<As...> {
  using std::tuple<As...>::tuple;
  tpl(std::tuple<As...> const& b) { std::tuple<As...>::operator=(b); }

  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type const&
  x() const { return get<0>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type&
  x() { return get<0>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type const&
  y() const { return get<1>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type&
  y() { return get<1>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type const&
  z() const { return get<2>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type&
  z() { return get<2>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type const&
  w() const { return get<3>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type&
  w() { return get<3>(*this); }
};

using lli   = long long int;
using llu   = long long unsigned;

using pii   = tpl<lli, lli>;
using piii  = tpl<lli, lli, lli>;
using piiii = tpl<lli, lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

template<size_t... I>
struct my_index_sequence {
  using type = my_index_sequence;
  static constexpr array<size_t, sizeof...(I)> value = { {I...} };
};

namespace my_index_sequence_detail {
  template<typename I, typename J> struct concat;
  template<size_t... I, size_t... J>
  struct concat<my_index_sequence<I...>, my_index_sequence<J...> > :
    my_index_sequence<I..., (sizeof...(I)+J)...> { };
  template<size_t N> struct make_index_sequence :
    concat<typename make_index_sequence<N/2>::type, typename make_index_sequence<N-N/2>::type>::type { };
  template <> struct make_index_sequence<0> : my_index_sequence<>{};
  template <> struct make_index_sequence<1> : my_index_sequence<0>{};
}

template<class... A>
using my_index_sequence_for = typename my_index_sequence_detail::make_index_sequence<sizeof...(A)>::type;

template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, my_index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tpl<A...> const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class... A>
ostream& operator<<(ostream& s, tpl<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

namespace std {
  namespace {
    template <class T>
    inline void hash_combine(size_t& seed, T const& v) {
      seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
    template <class Tuple, size_t Index = tuple_size<Tuple>::value - 1>
    struct HashValueImpl {
      static void apply(size_t& seed, Tuple const& tuple) {
        HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
        hash_combine(seed, get<Index>(tuple));
      }
    };
    template <class Tuple>
    struct HashValueImpl<Tuple, 0> {
      static void apply(size_t& seed, Tuple const& tuple) {
        hash_combine(seed, get<0>(tuple));
      }
    };
  }
  template <typename ... TT>
  struct hash<tuple<TT...>> {
    size_t operator()(tuple<TT...> const& tt) const {
      size_t seed = 0;
      HashValueImpl<tuple<TT...> >::apply(seed, tt);
      return seed;
    }
  };
  template <typename ... TT>
  struct hash<tpl<TT...>> {
    size_t operator()(tpl<TT...> const& tt) const {
      size_t seed = 0;
      HashValueImpl<tuple<TT...> >::apply(seed, tt);
      return seed;
    }
  };
}

//------------------------------------------------------------------------------

// --- BEGIN SNIPPET MODULAR ---

const lli MOD = 1e9+7;

inline lli fexp(lli a, int b) {
  lli r = 1;
  while(b){
    if(b&1) r = (r*a)%MOD;
    a = (a*a)%MOD;
    b /= 2;
  }
  return r;
}

inline lli invmod(lli a) {
  return fexp(a, MOD-2);
}

// --- END SNIPPET MODULAR ---

// --- BEGIN SNIPPET 2D SEGMENT TREE ---

tpl<lli,int> mapp(tpl<lli,int> const& a, tpl<lli,int> const& b) {
  return mt((a.x()*b.x())%MOD,a.y()+b.y());
}

struct s1d {
  struct node {
    node(){}
    lli value=1;
    int count=0;
    int from=1e9, to=1e9;
  };
  int n; vector<node> A;
  s1d(){}
  s1d(set<int> data) : n(1ll<<((int)(1+log2(data.size()+1)))) {
    while(n&&(n/2)>=(int)data.size()) n/=2;
    A.resize(2*n);
    int cur=0;
    for(auto const& p:data){
      A[n+cur].value = 1;
      A[n+cur].count = 0;
      A[n+cur].from = A[n+cur].to = p;
      cur++;
    }
    build();
  }
  void build(){
    FORD(i,n-1,1) update(i);
  }
  void update(int i){
    A[i].value=(A[2*i].value*A[2*i+1].value)%MOD;
    A[i].count=(A[2*i].count+A[2*i+1].count);
    A[i].from=A[2*i].from;
    A[i].to=A[2*i+1].to;
  }

  void add0(int i, int x, lli v) {
    if(A[i].from>x) return;
    if(A[i].to<x) return;
    A[i].value = (A[i].value*v)%MOD;
    A[i].count += 1;
    if(i<n){
      add0(2*i,x,v);
      add0(2*i+1,x,v);
    }
  }
  void add(int x,lli v){
    add0(1,x,v);
  }
  tpl<lli,int> query0(int i, int x0, int x1) {
    if(A[i].from>x1) return mt(1,0);
    if(A[i].to<x0) return mt(1,0);
    if(x0<=A[i].from && A[i].to <=x1) return mt(A[i].value,A[i].count);
    return mapp(query0(2*i,x0,x1),query0(2*i+1,x0,x1));
  }
  tpl<lli,int> query(int x0, int x1) {
    return query0(1,x0,x1);
  }


};

struct s2d {
  struct node {
    node(){}
    set<int> data;
    s1d value;
    int from=1e9, to=1e9;
  };
  int n; vector<node> A;
  s2d(map<int,set<int> > &&data) : n(1ll<<((int)(1+log2(data.size()+1)))), A(2*n) {
    int cur=0;
    for(auto const& p:data){
      A[n+cur].data = p.second;
      A[n+cur].value = s1d(p.second);
      A[n+cur].from = A[n+cur].to = p.first;
      cur++;
    }
    build();
  }
  void build(){
    FORD(i,n-1,1) {
      update(i);
    }
  }
  void update(int i){
    A[i].data=A[2*i].data;
    for(auto p : A[2*i+1].data) { A[i].data.insert(p); }
    A[2*i].data.clear();
    A[2*i+1].data.clear();
    A[i].value = s1d(A[i].data);
    A[i].from=A[2*i].from;
    A[i].to=A[2*i+1].to;
  }
  void add0(int i, int x, int y, lli v) {
    if(A[i].from>x) return;
    if(A[i].to<x) return;
    A[i].value.add(y,v);
    if(i<n){
      add0(2*i,x,y,v);
      add0(2*i+1,x,y,v);
    }
  }
  void add(int x, int y, lli v){
    add0(1,x,y,v);
  }
  tpl<lli,int> query0(int i, int x0, int x1, int y0, int y1) {
    if(A[i].from>x1) return mt(1,0);
    if(A[i].to<x0) return mt(1,0);
    if(x0<=A[i].from && A[i].to <=x1) {
      return A[i].value.query(y0,y1);
    }
    return mapp(query0(2*i,x0,x1,y0,y1),query0(2*i+1,x0,x1,y0,y1));
  }
  tpl<lli,int> query(int x0, int x1, int y0, int y1) {
    return query0(1,x0,x1,y0,y1);
  }
};

// --- END SNIPPET 2D SEGMENT TREE ---


const int N=120016;
const int LN=19;
int parent[LN][N];
int depth[N];
int d0[N], d1[N];
lli val[N];
lli ival[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
  // n=100000;
  vvi G(n);
  vvi GC(n);
  vvi GV(n);
  FOR(i,n-1) {
    int u,v,c; lli va;
    cin>>u>>v>>va>>c; --u; --v;

    // u=rand()%(i+1);
    // v=i+1;
    // c=rand()%2;
    // va = 1+rand()%MOD;

    G[u].pb(v);
    G[v].pb(u);
    GV[u].pb(va);
    GV[v].pb(va);
    GC[u].pb(c);
    GC[v].pb(c);
  }
  function<void(int,int,int,int,lli)> dfs0 = [&](int i, int p, int n0, int n1, lli V) {
    parent[0][i]=p;
    d0[i] = n0;
    d1[i] = n1;
    depth[i]=d0[i]+d1[i];
    val[i]=V;
    ival[i]=invmod(V);
    FOR(j,G[i].size()) if(G[i][j]!=p) dfs0(G[i][j],i,n0+(GC[i][j]==0),n1+(GC[i][j]==1),(V*GV[i][j])%MOD);
  };
  dfs0(0,-1,0,0,1);
  FOR(i,LN-1) FOR(j,n) {
    if(parent[i][j] != -1) {
      parent[i+1][j] = parent[i][parent[i][j]];
    }
    else parent[i+1][j] = -1;
  }
  function<int(int,int)> lca = [&](int i, int j) {
    if(depth[i]<depth[j]) swap(i,j);
    FORD(k,LN-1,0) if(depth[i]-(1<<k) >= depth[j]) {
      i = parent[k][i];
    }
    if(i==j) return i;
    FORD(k,LN-1,0) if(depth[i]>=(1<<k)) {
      if(parent[k][i] != parent[k][j]) {
        i=parent[k][i];
        j=parent[k][j];
      }
    }
    return parent[0][i];
  };
  function<tpl<int,int,lli>(int,int)> d01 = [&](int i, int j) {
    tpl<int,int,lli> r(0,0,1);
    int l=lca(i,j);
    r.x() += d0[i] + d0[j] - 2*d0[l];
    r.y() += d1[i] + d1[j] - 2*d1[l];
    r.z() *= val[i]; r.z() %= MOD;
    r.z() *= val[j]; r.z() %= MOD;
    r.z() *= ival[l]; r.z() %= MOD;
    r.z() *= ival[l]; r.z() %= MOD;
    return r;
  };

  // {
  //   lli bans=1;
  //   FOR(i,n) FOR(j,n) if(i<j) {
  //     lli a,b; lli v; tie(a,b,v) = d01(i,j);
  //     if(2*a-b>=0&&2*b-a>=0) {
  //       bans = (bans*v)%MOD;
  //     }
  //   }
  //   cout << "..." << bans << endl;
  // }

  lli ans=1;

  vi  A(n,0);
  vi  CP(n,-1);
  int root=-1;
  FOR(l,100){
    vi E = A;
    vi P(n);
    vi S(n,1);
    function<void(vi&, int,int)> dfs0 = [&](vi& C, int i,int p){
      E[i]=1; P[i]=p; C.pb(i);
      for(int j : G[i]) if(!A[j] && j!=p) {
          dfs0(C,j,i);
          S[i]+=S[j];
        }
    };
    vi C;
    FOR(i,n) if(!E[i]) {
      C.clear();
      dfs0(C, i, -1);
      auto f = [&](int j){
        int r=0;
        for(auto k : G[j]) if(!A[k] && k!=P[j]) r=max<int>(r,S[k]);
        r=max<int>(r,S[i]-S[j]);
        return r;
      };
      int centroid=i; int best=f(i);
      for(int j : C) {
        int v=f(j); if(v<best) { centroid=j; best=v; }
      }
      A[centroid]=1;
      if(CP[centroid]==-1) root=centroid;
      for(int j : C) if(j!=centroid) CP[j]=centroid;

      map<int,set<int>> data;
      vector<vector<tpl<int,int,lli>>> V; V.emplace_back();
      function<void(int,int)> dfs1 = [&](int i, int p) {
        int d0,d1; lli v; tie(d0,d1,v) = d01(centroid,i);
        data[2*d0-d1].insert(2*d1-d0);
        V.back().pb(mt(2*d0-d1,2*d1-d0,v));
        for(int j:G[i]) if(CP[j]==centroid && j!=p) {
            if(i==centroid) V.emplace_back();
            dfs1(j,i);
          }
      };
      dfs1(centroid,-1);

      // cerr << V << endl;

      s2d tr(move(data));

      for(auto const& v : V) {
        for(auto const& p : v) {
          int a,b; lli u; tie(a,b,u) = p;
          lli w; int cnt; tie(w,cnt) = tr.query(-a,1<<25,-b,1<<25);
          if(cnt) {
            ans *= w; ans %= MOD;
            ans *= fexp(u,cnt); ans %= MOD;
          }
        }
        for(auto const& p : v) {
          int a,b; lli u; tie(a,b,u) = p;
          tr.add(a,b,u);
        }
      }

      // function<void(int)> addself = [&](int i) {
      //   int d0,d1; lli v; tie(d0,d1,v) = d01(centroid,i);
      //   tr.add(2*d0-d1,2*d1-d0,v);
      // };
      // function<void(int,int)> dfs3 = [&](int i, int p) {
      //   addself(i);
      //   for(int j:G[i]) if(CP[j]==centroid && j!=p) {
      //       dfs3(j,i);
      //     }
      // };
      // function<void(int,int)> dfs2 = [&](int i, int p) {
      //   int d0,d1; lli v; tie(d0,d1,v) = d01(centroid,i);
      //   lli u; int cnt; tie(u,cnt) = tr.query(-(2*d0-d1),1<<20,-(2*d1-d0),1<<20);
      //   ans *= u; ans %= MOD;
      //   ans *= fexp(v,cnt); ans %= MOD;
      //   if(i == centroid) {
      //     addself(i);
      //   }
      //   // d0 + d0' >= 0
      //   // d1 + d1' >= 0
      //   // tr.get(-d0,infty,-d1,infty);
      //   for(int j:G[i]) if(CP[j]==centroid && j!=p) {
      //       dfs2(j,i);
      //       if(i==centroid) dfs3(j,i);
      //     }
      // };
      // dfs2(centroid,-1);

      //

    }
    FOR(i,n) if(!A[i]) goto l_beg;
    break;
  l_beg:;
  }

  cout << ans << endl;

  // vvi H(n); FOR(i,n) if(CP[i]!=-1) H[CP[i]].pb(i);
  // cout << root << " " << H << endl;
  // lli res=1;
  // function<void(lli)> dfs1 = [&](lli i) {
  //   for(lli j:H[i]) {
  //     dfs1(j);
  //     lli a,b; lli v; tie(a,b,v) = d01(i,j);
  //     ANS[i] *= fexp(invmod(v),2*CNT[j]);
  //     ANS[i] %= MOD;
  //   }
  //   res *= ANS[i];
  //   res %= MOD;
  // };
  // dfs1(root);
  // cout << res << endl;
  // // the tree (root,H) is now a centroid decomposition

  return 0;
}