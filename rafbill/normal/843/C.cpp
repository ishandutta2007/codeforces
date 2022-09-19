#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
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

void test(lli n, vii ES, vector<tpl<lli,lli,lli>> ans) {
  vector<set<lli>> G(n);
  for(auto const &p :ES) {
    lli u,v; tie(u,v) = p;
    G[u].insert(v);
    G[v].insert(u);
  }
  for(auto const& p : ans) {
    lli x,y,z; tie(x,y,z) = p;
    assert(G[x].count(y));
    assert(G[y].count(x));
    function<lli(lli,lli)> dfs = [&](lli i, lli p) {
      lli sz=1;
      for(lli j : G[i]) if(j!=p) {
          sz+=dfs(j,i);
        }
      return sz;
    };
    lli szx = dfs(x,y);
    lli szy = dfs(y,x);
    assert(szx>szy);
    G[x].erase(y); G[y].erase(x);
    assert(!G[z].count(x));
    assert(!G[x].count(z));
    G[x].insert(z); G[z].insert(x);
  }
  // lli r=0;
  // function<void(lli,lli,lli,lli)> dfs = [&](lli i0, lli i, lli p, lli d) {
  //   r += d*d;
  //   for(lli j : G[i]) if(j!=p) {
  //       dfs(i0,j,i,d+1);
  //     }
  // };
  // FOR(i,n) dfs(i,i,-1,0);
  // cerr << r << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n; cin>>n;
  vvi G(n);
  vii ES;
  FOR(i,n-1) {
    lli u,v;
    cin>>u>>v;
    --u; --v;
    // u = i+1; v = i;
    ES.pb(mt(u,v));
    G[u].pb(v);
    G[v].pb(u);
  }

  vi  A(n,0);
  vi  CP(n,-1);
  vi  DP(n,-1);
  lli root;
  vi pairWith(n,-1);
  FOR(l,100){
    vi E = A;
    vi P(n);
    vi S(n,1);
    function<void(vi&, lli,lli)> dfs0 = [&](vi& C, lli i,lli p){
      E[i]=1; P[i]=p; C.pb(i);
      for(lli j : G[i]) if(!A[j] && j!=p) {
          dfs0(C,j,i);
          S[i]+=S[j];
        }
    };
    vi C;
    FOR(i,n) if(!E[i]) {
      C.clear();
      dfs0(C, i, -1);
      auto f = [&](lli j){
        lli r=0;
        for(auto k : G[j]) if(!A[k] && k!=P[j]) r=max<lli>(r,S[k]);
        r=max<lli>(r,S[i]-S[j]);
        return r;
      };
      vi centroids; lli best=1<<30;
      for(lli j : C) {
        lli v=f(j);
        if(v<best) { centroids.clear(); best=v; }
        if(v==best) centroids.pb(j);
      }
      assert(centroids.size()>=1);
      assert(centroids.size()<=2);
      for(lli j:centroids) A[j]=1;
      if(centroids.size() == 2) {
        pairWith[centroids[0]]=centroids[1];
        pairWith[centroids[1]]=centroids[0];
        CP[centroids[1]]=-1;
      }
      if(CP[centroids[0]]==-1) root=centroids[0];
      function<void(lli,lli,lli,lli)> dfs1 = [&](lli k, lli kk, lli i, lli p){
        if(i!=k) {CP[i]=k;DP[i]=kk;}
        for(lli j : G[i]) if(!A[j] && j!=p) {
            dfs1(k,(kk==-1?j:kk),j,i);
          }
      };
      if(centroids.size() == 1) dfs1(centroids[0],-1,centroids[0],-1);
      else {
        dfs1(centroids[0],-1,centroids[0],centroids[1]);
        dfs1(centroids[1],-1,centroids[1],centroids[0]);
      }
    }
    FOR(i,n) if(!A[i]) goto l_beg;
    break;
  l_beg:;
  }

  vvi H(n); FOR(i,n) if(CP[i]!=-1) H[CP[i]].pb(i);
  vector<tuple<int,int,int>> ans;

  function<void(int,int)> solve = [&](int i, int rt) {
    int to=i;
    function<void(int,int)> dfs = [&](int j, int p) {
      for(int k : G[j]) if(k!=p) {
          dfs(k,j);
        }
      if(p!=rt && p!=i) {
        ans.pb(mt(rt,to,j));
        ans.pb(mt(j,p,i));
        to=j;
      }
    };
    dfs(i,rt);
    if(to!=i) ans.pb(mt(rt,to,i));
  };

  for(int i:G[root]) if(i!=pairWith[root]) solve(i,root);
  if(pairWith[root]==-1) {
  }else{
    for(int i:G[pairWith[root]]) if(i!=root) solve(i,pairWith[root]);
  }
  cout << ans.size() << endl;
  for(auto const& p:ans) {
    int x,y,z; tie(x,y,z) = p;
    cout << x+1 << " " << y+1 << " " << z+1 << '\n';
  }
  cout << flush;

  return 0;
}