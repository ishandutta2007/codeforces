#ifndef __clang__
#pragma GCC optimize ("-O3")
#endif
#ifdef ONLINE_JUDGE
#define NDEBUG 1
#endif
#define _GLIBCXX_USE_CXX11_ABI 0
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
  static constexpr array<size_t, sizeof...(I)> value = { {I}... };
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

int read_positive(){
  char c; int x=0;
  do { c = getchar(); } while(c<'0' || c>'9');
  while(c>='0'&&c<='9') {
    x=10*x+(c-'0');
    c = getchar();
  }
  return x;
}

//------------------------------------------------------------------------------

// --- BEGIN SNIPPET MIN SEGMENT TREE ---

const lli MOD = 1e9+7;

using M = array<array<lli, 2>, 2>;

M mult(M const& a, M const& b){
  M c;
  FOR(i, 2) FOR(j, 2) { c[i][j]=0; FOR(k, 2) (c[i][j] += a[i][k]*b[k][j])%=MOD; }
  return c;
}

M ident(){
  M a; FOR(i, 2) FOR(j, 2) a[i][j]=i==j;
  return a;
}

// --- BEGIN SNIPPET MODULAR ---

M addM(M const& a, M const& b) {
  M c; FOR(i, 2) FOR(j, 2) c[i][j] =(a[i][j]+b[i][j])%MOD;
  return c;
}

inline M fexpM(M a, lli b) {
  M r = ident();
  while(b){
    if(b&1) r = mult(r, a);
    a = mult(a, a);
    b /= 2;
  }
  return r;
}

// --- END SNIPPET MODULAR ---

M fib = {{{{0,1}},{{1,1}}}};

struct segment_tree {

  struct segment_node {
    segment_node() {
      value = ident();
      wdelta=0;
      delta = ident();
    }
    M value;
    bool wdelta=0;
    M delta;
  };

  lli n;
  vector<segment_node> A;
  segment_tree(lli n_) : n((lli)1<<(lli)(log2(n_)+2)), A(2*n) { }

  void update(lli i) {
    if(i < n) {
      A[i].value = addM(A[2*i].value, A[2*i+1].value);
    }
  }

  void push(lli i){
    if(i < n){
      if(A[i].wdelta){
        add__(2*i  , A[i].delta);
        add__(2*i+1, A[i].delta);
        A[i].wdelta = 0;
        A[i].delta = ident();
      }
    }
  }

  void build(){
    FORD(i, n-1, 1) {
      update(i);
    }
  }

  void add__(lli i, M const& v){
    A[i].value  =  mult(A[i].value, v);
    A[i].wdelta = 1;
    A[i].delta  =  mult(A[i].delta, v);
  }

  void add_(lli i, lli a, lli b, lli l, lli r, M const& v) {
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      add__(i, v);
      return;
    }
    push(i);
    lli c = (a+b)/2;
    add_(2*i  , a  , c, l, r, v);
    add_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void add(lli l, lli r, lli const& v){
    add_(1, 0, n-1, l, r, fexpM(fib,v));
  }

  lli get_(lli i, lli a, lli b, lli l, lli r){
    if(l > b) return 0;
    if(r < a) return 0;
    if(l <= a && b <= r){
      return A[i].value[1][0];
    }
    push(i);
    lli c = (a+b)/2;
    return (get_(2*i  , a  , c, l, r)+
            get_(2*i+1, c+1, b, l, r))%MOD;
  }

  lli get(lli x, lli y){
    return get_(1, 0, n-1, x, y);
  }
};

// --- END SNIPPET SET SEGMENT TREE ---


int main(int, char**){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n, m; cin >> n >> m;
  segment_tree T(n);
  FOR(i, n) {
    lli x; cin >> x;
    T.add(i, i, x);
  }
  T.build();
  FOR(i, m) {
    lli t, l, r; cin >> t >> l >> r; l -= 1; r -= 1;
    if(t == 1) {
      lli v; cin >> v;
      T.add(l, r, v);
    }else{
      cout << T.get(l, r) << '\n';
    }
  }
  cout << flush;
  return 0;
}