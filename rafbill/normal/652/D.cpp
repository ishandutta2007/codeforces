#pragma GCC optimize ("-O3")
#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define DESTRUCT2(t, x, y)                      \
  auto x = get<0>(t);                           \
  auto y = get<1>(t);

#define DESTRUCT3(t, x, y, z)                   \
  auto x = get<0>(t);                           \
  auto y = get<1>(t);                           \
  auto z = get<2>(t);

#define DESTRUCT4(t, x, y, z, w)                \
  auto x = get<0>(t);                           \
  auto y = get<1>(t);                           \
  auto z = get<2>(t);                           \
  auto w = get<3>(t);

#define SQ(x) ((x)*(x))

#define all(x) begin(x), end(x)
#define mp make_pair
#define mt make_tuple
#define pb push_back

#define PE flush << "\033[2K\r"

#ifdef DEBUG
#define DB(x) x
#else
#define DB(x)
#endif

using namespace std;
using lli   = long long int;
using llu   = long long unsigned;

using pii   = tuple<lli, lli>;
using piii  = tuple<lli, lli, lli>;
using piiii = tuple<lli, lli, lli, lli>;
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

template<int... I>
struct my_index_sequence {
  using type = my_index_sequence;
  static constexpr array<int, sizeof...(I)> value = { I... };
};

namespace my_index_sequence_detail {
  template<typename I, typename J> struct concat;
  template<int... I, int... J>
  struct concat<my_index_sequence<I...>, my_index_sequence<J...> > :
    my_index_sequence<I..., (sizeof...(I)+J)...> { };
  template<int N> struct make_index_sequence :
    concat<typename make_index_sequence<N/2>::type, typename make_index_sequence<N-N/2>::type>::type { };
  template <> struct make_index_sequence<0> : my_index_sequence<>{};
  template <> struct make_index_sequence<1> : my_index_sequence<0>{};
}

template<class... A>
using my_index_sequence_for = typename my_index_sequence_detail::make_index_sequence<sizeof...(A)>::type;

template<class T, int... I>
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
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

template<class T, int I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
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
}

int readint(FILE* file = stdin) {
  register int c = 0;
  while((c<'0' || c>'9') && c != '-') c = fgetc(file);
  int x = 0;
  bool neg = 0;
  if(c == '-') {
    neg = true;
    c = fgetc(file);
  }
  for(; c >= '0' && c <= '9'; c = fgetc(file)) {
    x = (x << 1) + (x << 3) + c - '0';
  }
  if(neg) x = -x;
  return x;
}

int readposint(FILE* file = stdin) {
  register int c = 0;
  while(c<'0' || c>'9') c = fgetc(file);
  int x = 0;
  for(; c >= '0' && c <= '9'; c = fgetc(file)) {
    x = (x << 1) + (x << 3) + c - '0';
  }
  return x;
}

#define X get<0>
#define Y get<1>

struct treap {
  treap(lli x_) : l(0), r(0), x(x_), size(1), y(rand()){ }
  treap *l, *r;
  lli x;
  lli size;
  lli y;
};

lli get_size(treap* a){ return a?a->size:0; }

void update(treap* a){
  if(a){
    a->size = 1;
    if(a->l) a->size += a->l->size;
    if(a->r) a->size += a->r->size;
  }
}

void push(treap*){ }

treap* merge(treap* a, treap* b){
  if(a == 0) return b;
  if(b == 0) return a;
  push(a); push(b);
  if(a->y < b->y){
    a->r = merge(a->r, b);
    update(a);
    return a;
  }else{
    b->l = merge(a, b->l);
    update(b);
    return b;
  }
}

tuple<treap*, treap*> split(treap* a, lli x){
  if(a == 0) return mt(nullptr, nullptr);
  push(a);
  if(x <= a->x){
    auto p = split(a->l, x);
    a->l = Y(p);
    update(a);
    return mt(X(p), a);
  }else{
    auto p = split(a->r, x);
    a->r = X(p);
    update(a);
    return mt(a, Y(p));
  }
}

treap* insert(treap* a, lli x){
  auto p = split(a, x);
  return merge(merge(X(p), new treap(x)), Y(p));
}

//------------------------------------------------------------------------------


int main(int, char**){
  ios::sync_with_stdio(0);
  lli n; cin >> n;
  vi l(n), r(n);
  FOR(i, n) cin >> l[i] >> r[i];
  vi I(n); iota(all(I), 0); sort(all(I), [&](lli a, lli b) {return r[a] < r[b]; });
  vi A(n);
  treap* t = nullptr;
  for(auto i : I){
    auto p = split(t, l[i]);
    DESTRUCT2(p, p1, p2);
    A[i] = get_size(p2);
    t = merge(p1, p2);
    t = insert(t, l[i]);
  }
  FOR(i, n) cout << A[i] << "\n";
  cout << flush;
  return 0;
}