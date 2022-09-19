#pragma GCC optimize ("-Ofast")
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
using lli   = int;

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

//


struct node {
  node(){ }
  node(lli cost_, lli edge_) : cost(mt(cost_, edge_)){
    mcost = cost;
  }
  pii cost;
  pii mcost;

  node *parent = 0, *children[2] = {0, 0};
  bool isroot() const { return !parent||(this!=parent->children[0]&&this!=parent->children[1]); }
  lli  direction() const { return this==parent->children[1]; }

  bool flip = 0;
};

void push(node* n){
  if(n->flip){
    swap(n->children[0], n->children[1]);
    FOR(i, 2) if(n->children[i]) n->children[i]->flip ^= 1;
    n->flip = 0;
  }
}

void update(node* n){
  if(n){
    n->mcost = n->cost;
    FOR(i, 2) if(n->children[i]) n->mcost = min(n->mcost, n->children[i]->mcost);
  }
}

void rotate(node* n){
  lli d = n->direction();
  node *p = n->parent, *b = n->children[1-d];
  if(!p->isroot()) p->parent->children[p->direction()] = n;
  if(p->parent) { n->parent = p->parent; }
  else { n->parent = 0; }
  n->children[1-d] = p; p->parent = n;
  if(b) { p->children[d] = b; if(b) b->parent = p; }
  else { p->children[d] = 0; }
  update(n); update(p); update(n->parent);
}

void splay(node* n){
  push(n);
  while(!n->isroot()){
    if(n->parent->parent) push(n->parent->parent);
    push(n->parent); push(n);
    if(n->parent->isroot()) {
      rotate(n);
    } else if(n->direction() == n->parent->direction()) {
      rotate(n->parent); rotate(n);
    }else{
      rotate(n); rotate(n);
    }
  }
}

node* leftmost(node* n){
  while(n->children[0]) n = n->children[0];
  return n;
}

void splice(node* x){
  push(x->parent);
  x->parent->children[1] = x;
  update(x->parent);
}

void expose(node* x){
  { node* y = x; while(y) { splay(y); y = y->parent; } }
  { node* y = x; while(y->parent) { splice(y); y = y->parent; }}
  splay(x);
}

void evert(node* n){
  expose(n);
  if(n->children[0]){
    n->children[0]->flip ^= 1;
    n->children[0] = 0;
    update(n);
  }
}

void link(node* x, node* y){
  evert(y); y->parent = x;
}

void cut(node* x, node* y){
  evert(x); expose(y);
  y->children[0] = 0; x->parent = 0;
  update(y);
}

pii path(node* x, node* y){
  evert(x);
  expose(y);
  return min(y->children[0]->mcost, y->cost);
}

//------------------------------------------------------------------------------

int readint() {
  register int c = 0;
  while(c<'0' || c>'9') c = getchar();
  int x = 0;
  for(; c >= '0' && c <= '9'; c = getchar()) {
    x = (x << 1) + (x << 3) + c - '0';
  }
  return x;
}

node E[500000];
node A[500000];

int main(int, char**){
  lli n = readint();
  unordered_set<pii> initial_edges;
  vii C; FOR(i, n-1) {
    int x, y; x = readint(); y = readint();
    x-=1; y-=1;
    if(x>y) swap(x, y);
    initial_edges.insert(mt(x, y));
    C.pb(mt(x, y));
  }
  unordered_set<pii> valid_edges;
  vii D; FOR(i, n-1) {
    int x, y; x = readint(); y = readint();
    x-=1; y-=1;
    if(x>y) swap(x, y);
    valid_edges.insert(mt(x, y));
    D.pb(mt(x, y));
  }
  FOR(i, n-1) E[i] = node(valid_edges.count(C[i]), i);
  FOR(i, n) A[i] = node(1e9, -1);
  FOR(i, n-1) {
    DESTRUCT2(C[i], x, y);
    link(&A[x], &E[i]);
    link(&A[y], &E[i]);
  }

  vector<tuple<pii, pii>> R;

  FOR(i, n-1) if(initial_edges.count(D[i]) == 0) {
    DESTRUCT2(D[i], x, y);
    auto p = path(&A[x], &A[y]);
    DESTRUCT2(p, cost, j);
    DESTRUCT2(C[j], x_, y_);
    cut(&E[j], &A[x_]);
    cut(&E[j], &A[y_]);
    E[j] = node(1, j);
    link(&E[j], &A[x]);
    link(&E[j], &A[y]);
    R.pb(mt(mt(x_, y_), mt(x, y)));
  }

  printf("%d\n", (int)R.size());
  for(auto p : R) {
    DESTRUCT2(p, a, b);
    DESTRUCT2(a, x, y);
    DESTRUCT2(b, x_, y_);
    printf("%d %d %d %d\n", x+1, y+1, x_+1, y_+1);
  }

  return 0;
}