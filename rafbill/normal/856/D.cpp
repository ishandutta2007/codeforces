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

#define FOR(i, n)     for(int i = 0; i < (int)(n); ++i)
#define FORU(i, j, k) for(int i = (j); i <= (int)(k); ++i)
#define FORD(i, j, k) for(int i = (j); i >= (int)(k); --i)

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
  tpl(){}
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

using pii   = tpl<int, int>;
using piii  = tpl<int, int, int>;
using piiii = tpl<int, int, int, int>;
using vi    = vector<int>;
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

// --- BEGIN SNIPPET LINK CUT TREE ---

namespace link_cut {

  // change min to change augmentation
  // create edge-node to augment edges

  struct node {
    node(){ }

    node(int value0_, int value1_) : value0(value0_), mvalue0(value0_), value1(value1_), mvalue1(value1_){
    }
    int value0,mvalue0;
    int value1,mvalue1;

    node *p = 0, *cs[2] = {0, 0};
    bool isroot() const { return !p||(this!=p->cs[0]&&this!=p->cs[1]); }
    int  dir() const { return this==p->cs[1]; }

    bool flip = 0;
  };

  void push(node* n){
    if(n->flip){
      swap(n->cs[0], n->cs[1]);
      FOR(i, 2) if(n->cs[i]) n->cs[i]->flip ^= 1;
      n->flip = 0;
    }
  }

  void update(node* n){
    if(n){
      n->mvalue0 = n->value0;
      FOR(i, 2) if(n->cs[i]) n->mvalue0 += n->cs[i]->mvalue0;
      n->mvalue1 = n->value1;
      FOR(i, 2) if(n->cs[i]) n->mvalue1 += n->cs[i]->mvalue1;
    }
  }

  void rotate(node* n){
    int d = n->dir();
    node *p = n->p, *b = n->cs[1-d];
    if(!p->isroot()) p->p->cs[p->dir()] = n;
    n->p = p->p;
    n->cs[1-d] = p; p->p = n;
    p->cs[d] = b; if(b) b->p = p;
    update(n); update(p); update(n->p);
  }

  void splay(node* n){
    push(n);
    while(!n->isroot()){
      if(n->p->p) push(n->p->p);
      push(n->p); push(n);
      if(n->p->isroot()) {
        rotate(n);
      } else if(n->dir() == n->p->dir()) {
        rotate(n->p); rotate(n);
      }else{
        rotate(n); rotate(n);
      }
    }
  }

  node* leftmost(node* n){
    while(n->cs[0]) n = n->cs[0];
    return n;
  }

  void splice(node* x){
    push(x->p);
    x->p->cs[1] = x;
    update(x->p);
  }

  void expose(node* x){
    { node* y = x; while(y) { splay(y); y = y->p; } }
    { node* y = x; while(y->p) { splice(y); y = y->p; }}
    splay(x);
  }

  void evert(node* n){
    expose(n);
    if(n->cs[0]){
      n->cs[0]->flip ^= 1;
      n->cs[0] = 0;
      update(n);
    }
  }

  void link(node* x, node* y){
    evert(y); y->p = x;
  }

  void cut(node* x, node* y){
    evert(x); expose(y);
    y->cs[0] = 0; x->p = 0;
    update(y);
  }

  int path0(node* x, node* y){
    if(x == y) {
      return x->value0;
    }
    evert(x);
    expose(y);
    return y->cs[0]->mvalue0 + y->value0;
  }

  int path1(node* x, node* y){
    if(x == y) {
      return x->value1;
    }
    evert(x);
    expose(y);
    return y->cs[0]->mvalue1 + y->value1;
  }
}

// --- END SNIPPET LINK CUT TREE ---
int read_positive(){
  char c; int x=0;
  do { c = getchar(); } while(c<'0' || c>'9');
  while(c>='0'&&c<='9') {
    x=10*x+(c-'0');
    c = getchar();
  }
  return x;
}


const int N = 300000;
const int LN = 20;

int parent[LN][N];
int depth[N];

link_cut::node LA[N];

int main(){
  int n,m; n=read_positive(); m=read_positive();
  vvi G(n);
  FOR(i,n-1) {
    int u; u=read_positive()-1;
    int v = 1+i;
    G[u].pb(v); G[v].pb(u);
  }
  vector<tpl<int,int,int>> Q(m);
  FOR(i,m) {
    int u,v,c; u=read_positive()-1; v=read_positive()-1; c=read_positive();
    Q[i] = mt(u,v,c);
  }
  function<void(int, int, int)> dfs = [&](int i, int p, int d) {
    parent[0][i] = p;
    depth[i] = d;
    for(int j : G[i]) if(j!=p) {
        dfs(j,i,d+1);
      }
  };
  dfs(0,-1,0);
  FOR(j,LN-1) {
    FOR(i,n) {
      if(parent[j][i] != -1) {
        parent[j+1][i] = parent[j][parent[j][i]];
      }
    }
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

  function<int(int,int)> next0 = [&](int i, int lca) {
    FORD(k,LN-1,0) if(depth[i]-(1<<k) > depth[lca]) {
      i = parent[k][i];
    }
    return i;
  };


  vector<vector<tpl<int,int,int>>> QS(n);
  FOR(i,m) {
    int u,v,c; tie(u,v,c) = Q[i];
    QS[lca(u,v)].pb(Q[i]);
  }

  vector<int> V(n);
  vector<int> SV(n);
  function<void(int, int)> dfs2 = [&](int i, int p) {
    V[i] = 0; SV[i] = 0;
    for(int j : G[i]) if(j!=p) {
        dfs2(j,i);
        SV[i] += V[j];
      }
    V[i] = SV[i];
    for(auto const& q : QS[i]) {
      int u,v,c; tie(u,v,c) = q;
      int curv = c;
      curv += SV[i];
      if(u != i) {
        int u_ = next0(u,i);
        curv += link_cut::path0(&LA[u_],&LA[u]);
        curv -= link_cut::path1(&LA[u_],&LA[u]);
      }
      if(v != i) {
        int v_ = next0(v,i);
        curv += link_cut::path0(&LA[v_],&LA[v]);
        curv -= link_cut::path1(&LA[v_],&LA[v]);
      }
      V[i] = max(V[i], curv);
    }
    LA[i] = link_cut::node(SV[i],V[i]);
    for(int j : G[i]) if(j != p) {
        link_cut::link(&LA[i],&LA[j]);
      }
  };
  dfs2(0,-1);
  cout << V[0] << endl;
  exit(0);
  return 0;
}