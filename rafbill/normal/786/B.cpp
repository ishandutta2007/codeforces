#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
#endif
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

lli read_positive(){
  char c; lli x=0;
  do { c = getchar(); } while(c<'0' || c>'9');
  while(c>='0'&&c<='9') {
    x=10*x+(c-'0');
    c = getchar();
  }
  return x;
}

//------------------------------------------------------------------------------

// --- BEGIN SNIPPET SEGMENT TREE ---

struct set_segment_tree {

  struct node {
    node(){allSet=0;}
    bool allSet=0;

    void combine(node &a, node& b) {
      allSet = a.allSet&&b.allSet;
    }
  };

  lli n;
  vector<node> A;
  set_segment_tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n) { }

  void update(lli i) {
    if(i < n) {
      A[i].combine(A[2*i],A[2*i+1]);
    }
  }

  void set__(lli i){
    A[i].allSet = 1;
  }

  void set_(lli i, lli a, lli b, lli l, lli r) {
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      set__(i);
      return;
    }
    lli c = (a+b)/2;
    set_(2*i  , a  , c, l, r);
    set_(2*i+1, c+1, b, l, r);
    update(i);
  }

  void set(lli l, lli r){
    set_(1, 0, n-1, l, r);
  }

  bool get_(lli i, lli a, lli b, lli l, lli r) {
    if(l > b) return true;
    if(r < a) return true;
    if(l <= a && b <= r){
      return A[i].allSet;
    }
    lli c = (a+b)/2;
    bool ar = get_(2*i  , a  , c, l, r);
    bool br = get_(2*i+1, c+1, b, l, r);
    return ar&&br;
  }

  bool get(lli l, lli r){
    return get_(1, 0, n-1, l, r);
  }
};

struct tt_segment_tree {

  struct node {
    node(){}
    vi LIST;
  };

  lli n;
  vector<node> A;
  tt_segment_tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n) { }

  void add__(lli i, lli v){
    A[i].LIST.pb(v);
  }

  void add_(lli i, lli a, lli b, lli l, lli r, lli v) {
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      add__(i, v);
      return;
    }
    lli c = (a+b)/2;
    add_(2*i  , a  , c, l, r, v);
    add_(2*i+1, c+1, b, l, r, v);
  }

  void add(lli l, lli r, lli v){
    add_(1, 0, n-1, l, r, v);
  }

  void get_(lli i, lli a, lli b, lli l, vi& rr) {
    if(l > b) return;
    if(l < a) return;
    for(auto j : A[i].LIST) rr.pb(j);
    A[i].LIST.clear();
    if(a==b){
      return;
    }
    lli c = (a+b)/2;
    get_(2*i  , a  , c, l, rr);
    get_(2*i+1, c+1, b, l, rr);
  }

  vi get(lli l){
    vi rr;
    get_(1, 0, n-1, l, rr);
    return rr;
  }
};




// --- END SNIPPET SEGMENT TREE ---

lli ans[200000];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n,q,s; cin>>n>>q>>s; --s;
  FOR(i,n) ans[i]=-1;
  vvii G0(n);
  vector<vector<tpl<lli,lli,lli> > > G1(n);
  tt_segment_tree tree2(n+2);

  lli nq0=0;
  vector<tpl<lli,lli>> Q0;
  FOR(j_,q) {
    lli t; cin>>t;
    if(t==1) {
      lli u,v,w; cin>>u>>v>>w;
      --u; --v;
      G0[u].pb(mt(v,w));
    }else if(t==2) {
      lli u,l,r,w; cin>>u>>l>>r>>w;
      --u; --l; --r;
      G1[u].pb(mt(l,r,w));
    }else{
      lli u,l,r,w; cin>>u>>l>>r>>w;
      --u; --l; --r;
      tree2.add(l,r,nq0);
      Q0.pb(mt(u,w)); nq0++;
    }
  }

  set_segment_tree tree1(n+2);
  min_queue<tpl<lli,lli,lli>> Q;
  Q.push(mt(0,s,s));

  function<void(lli,lli)> add = [&](lli i, lli d) {
    assert(ans[i]==-1);
    tree1.set(i,i); ans[i]=d;
    for(auto q : G0[i]) {
      Q.push(mt(d+q.y(),q.x(),q.x()));
    }
    for(auto q : G1[i]) {
      Q.push(mt(d+q.z(),q.x(),q.y()));
    }
    auto rr = tree2.get(i);
    for(auto j : rr) {
      auto q = Q0[j];
      Q.push(mt(d+q.y(),q.x(),q.x()));
    }
  };

  while(!Q.empty()) {
    auto p = Q.top(); Q.pop();
    lli d = p.x();
    lli l = p.y();
    lli r = p.z();

    function<void(lli,lli)> test = [&](lli l, lli r){
      if(r<l) return;
      if(tree1.get(l,r)) return;
      if(l == r) {
        add(l,d);
      }else{
        lli m = (l+r)/2;
        test(l,m);
        test(m+1,r);
      }
    };
    test(l,r);
  }
  FOR(i,n) cout << ans[i] << ' '; cout << endl;
  return 0;
}