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

struct segment_tree {

  struct segment_node {
    lli value=-1; // maximum from point of view of the bottom
    bool dirty=false;
    lli base;
  };

  void pushall(lli i, lli a, lli b){
    if(i<n){
      push(i,a,b);
      lli c = (a+b)/2;
      pushall(2*i,a,c);
      pushall(2*i+1,c+1,b);
    }
  }

  void print(){
    FOR(i,2*n) cerr << A[i].value << " "; cerr << endl;
    pushall(1,0,n-1);
    FOR(i,2*n) cerr << A[i].value << " "; cerr << endl;
    FOR(i,2*n) cerr << A[i].base << " "; cerr << endl;
    FOR(i,2*n) cerr << A[i].dirty << " "; cerr << endl;
  }

  lli n;
  vector<segment_node> A;
  segment_tree(){}
  segment_tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n) {
  }

  void update(lli i, lli a, lli b) {
    if(i < n) {
      A[i].value=-1;
      lli c = (a+b)/2;
      A[i].value = max(A[2*i].value + (b-c), A[2*i+1].value);
    }
  }

  void push(lli i, lli a, lli b){
    if(i < n){
      if(A[i].dirty){
        lli c = (a+b)/2;
        set__(2*i,   a,   c, A[i].base);
        set__(2*i+1, c+1, b, A[i].base + (c-a+1));
        A[i].dirty=0;
      }
      // add__(2*i  , a,   c, A[i].delta);
      // add__(2*i+1, c+1, b, A[i].delta);
    }
  }

  void set__(lli i, lli a, lli b, lli v){
    A[i].value=v+(b-a);
    A[i].base=v;
    A[i].dirty=1;
  }

  void set_(lli i, lli a, lli b, lli l, lli r, lli v) {
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      set__(i, a, b, v);
      return;
    }
    push(i,a,b);
    lli c = (a+b)/2;
    set_(2*i  , a  , c, l, r, v);
    set_(2*i+1, c+1, b, l, r, v + (c+1-a));
    update(i,a,b);
  }

  void set(lli l, lli r, lli v){
    set_(1, 0, n-1, l, r, v - l);
  }
#define C_YELLOW  "\033[33m"
#define C_BYELLOW  "\033[33;1m"
#define C_RESET   "\033[0m"  // Reset the terminal state

  // largest larger/or equal to v
  pii query_(lli i, lli a, lli b, lli l, lli r, lli v) {
    //cerr << C_YELLOW << i << " " << a << " "  << b<< " "  << l << " " << r << " " << v << " " << A[i].value << C_RESET << endl;
    if(l > b) return mt(-1,-1);
    if(r < a) return mt(-1,-1);
    push(i,a,b);
    lli c = (a+b)/2;
    if(l <= a && b <= r){
      if(A[i].value <= v) return mt(-1,-1);
      if(i>=n) return mt(a,A[i].value);
      pii r0 = query_(2*i+1, c+1, b, l, r, v);
      if(r0==mt(-1,-1)) return query_(2*i, a, c, l, r, v+(b-c));
      else return r0;
    }else{
      pii ans=max(query_(2*i+1, c+1, b, l, r, v),
                  query_(2*i, a, c, l, r, v+(b-c)));
      return ans;
    }
  }

  pii query(lli l, lli r, lli v){
    return query_(1, 0, n-1, l, r, v+r-(n-1));
  }
};

// --- END SNIPPET SET SEGMENT TREE ---


// --- BEGIN SNIPPET TREE ---

#define WITH_HLD 1

struct treechain {
  lli root = -1;
  lli size = 0;
  vi  nodes;

  treechain() { }

#ifdef WITH_HLD
  using segment = segment_tree; // segment tree / bit / other
  segment A;
  void build(){ A = segment(size); /* make segment tree */ }
#else
  void build(){ }
#endif
};

struct tree {
  lli n;
  vvi G;

  vi parent;
  vi depth;
  vi size;
  vi order, rorder;
  vii eorder;

  vector<treechain> chains;
  vector<lli>       chain;
  vector<lli>       chainIx;

  tree(lli n_) : n(n_), G(n) { }

  void read_parent() {
    FOR(i, n-1) {
      int u; scanf("%d", &u);
      G[1+i].pb(u); G[u].pb(1+i);
    }
  }

  void calcparent() {
    if(parent.empty()) {
      parent.assign(n, -1);
      order.clear();
      vi E(n, 0);
      vector<lli> Q; Q.pb(0);
      while(!Q.empty()) {
        lli i = Q.back(); Q.pop_back();
        order.pb(i);
        E[i] = 1;
        for(auto j : G[i]) if(!E[j]) {
            parent[j] = i;
            Q.pb(j);
          }
      }
      rorder = order;
      reverse(all(rorder));
    }
  }

  template<typename T>
  inline vector<vector<T> > makeEVec(T const& def = T()) {
    vector<vector<T> > v(n); FOR(i, n) v[i].assign(G[i].size(), def);
    return v;
  }

  void calceorder() {
    if(eorder.empty()) {
      vvi E = makeEVec(0ll);
      FOR(i, n) FOR(j_, G[i].size()) if(!E[i][j_]) {
        vii Q; Q.pb(mt(i,j_));
        vii tmp;
        while(!Q.empty()) {
          DESTRUCT2(Q.back(), i, j_); Q.pop_back();
          tmp.pb(mt(i, j_)); E[i][j_] = 1;
          lli j = G[i][j_];
          FOR(k_, G[j].size()) if(G[j][k_] != i && !E[j][k_]) Q.pb(mt(j, k_));
        }
        reverse(all(tmp));
        eorder.insert(end(eorder), all(tmp));
      }
    }
  }

  void calcsize() {
    calcparent();
    if(size.empty()) {
      size.assign(n, 1);
      for(auto i : rorder) if(parent[i]!=-1) size[parent[i]] += size[i];
    }
  }

  void calcdepth() {
    calcparent();
    if(depth.empty()) {
      depth.assign(n, 0);
      for(auto i : order) if(parent[i] != -1) depth[i] = depth[parent[i]] + 1;
    }
  }

  void calchld() {
    if(chains.empty()){
      calcsize();
      calcdepth();

      chain.assign(n, -1);
      for(auto i : rorder) {
        lli best = -1;
        for(auto j : G[i]) if(j != parent[i]) {
            if(best == -1 || size[j] > size[best]) best = j;
          }
        if(best == -1) {
          chain[i] = chains.size();
          chains.eb();
        }else{
          chain[i] = chain[best];
        }
        chains[chain[i]].size += 1;
      }

      chainIx.assign(n, -1);
      for(auto i : order) {
        if(parent[i]==-1 || chain[i] != chain[parent[i]]) chains[chain[i]].root = i;
        chainIx[i] = chains[chain[i]].nodes.size();
        chains[chain[i]].nodes.pb(i);
      };

      for(auto& c : chains) c.build();
    }
  }

  // O(log n) lca
  lli lca(lli a, lli b) {
    calchld();
    while(chain[a] != chain[b]) {
      if(depth[chains[chain[a]].root]>depth[chains[chain[b]].root]) {
        a = parent[chains[chain[a]].root];
      }else{
        b = parent[chains[chain[b]].root];
      }
    }
    if(depth[a]<depth[b]) return a; else return b;
  }

  lli dist(lli a, lli b) {
    calchld();
    return depth[a]+depth[b]-2*depth[lca(a, b)];
  }

#ifdef WITH_HLD
  // arguments to f :
  // segment, segment range, range in path from a to b (a = 0, b = dist(a, b))
  // the segment range is increasing
  // the range in path can be decreasing
  // O (log n)
  void hld_query(lli a, lli b, function<void(treechain::segment&, lli, lli, lli, lli)> f) {
    calchld();
    lli from = 0, to = dist(a, b);
    while(chain[a] != chain[b]) {
      if(depth[chains[chain[a]].root]>depth[chains[chain[b]].root]) {
        lli a_ = parent[chains[chain[a]].root];
        lli d = depth[a]-depth[a_];
        f(chains[chain[a]].A, 0, chainIx[a], from+d, from);
        from += d;
        a = a_;
      }else{
        lli b_ = parent[chains[chain[b]].root];
        lli d = depth[b]-depth[b_];
        f(chains[chain[b]].A, 0, chainIx[b], to-d, to);
        to -= d;
        b = b_;
      }
    }
    if(depth[a]<depth[b]) {
      f(chains[chain[a]].A, chainIx[a]+1, chainIx[b], from, to);
    }else{
      f(chains[chain[a]].A, chainIx[b]+1, chainIx[a], from, to);
    }
  }
#endif
};

// --- END SNIPPET TREE ---

#ifdef LOCAL
int main(int,char**){
  int n,m; scanf("%d%d", &n, &m);
  tree tr(n+1); tr.read_parent();
  tr.calcparent();
  tr.calcdepth();
  tr.calchld();
  vii M; M.reserve(m);
  FOR(i, m) {
    lli x, t; cin >> x >> t; M.pb(mt(x,t));
  }
  min_queue<tpl<int, int, int, int, int, int> > Q;
  FOR(i, m) {
    auto p = M[i];
    Q.push(mt(p.y(), 1, p.x(), p.x(), -1, i));
  }
  vi ANS(m);
  vi W(1+n, -1);
  vi C(1+n, -1);
  while(!Q.empty()) {
    auto p=Q.top(); Q.pop();
    int t=get<0>(p);
    int init=get<2>(p);
    int cur=get<3>(p);
    int ch=get<4>(p);
    int ix=get<5>(p);
    if(ix == W[cur]) {
      if(cur==init) {
        ANS[ix]=t;
        W[cur]=-1; C[cur]=-1;
      }else{
        W[cur]=-1;
        Q.push(mt(t+1,0,init,C[cur],cur,ix));
        C[cur]=-1;
      }
    }else if(cur==0||W[cur]!=-1) {
      if(ch!=-1)
        Q.push(mt(t+1,0,init,ch,cur,ix));
      else {
        ANS[ix]=t;
      }
    }else{
      W[cur]=ix; C[cur]=ch; Q.push(mt(t+1,1,init,tr.parent[cur],cur,ix));
    }
  }

  FOR(i, m){
    printf("%lld ", ANS[i]);
  }
  printf("\n");

  return 0;
}

#else

int main(int, char**){
  int n,m; scanf("%d%d", &n, &m);
  tree tr(n+1); tr.read_parent();
  tr.calcparent();
  tr.calcdepth();
  tr.calchld();
  vii M; M.reserve(m);
  FOR(i, m) {
    lli x, t; cin >> x >> t; M.pb(mt(x,t));
  }
  auto sorter = [&](pii const& a){
    return mt(a.y()+tr.depth[a.x()], a.x());
  };
  vi I(m); iota(all(I), 0);
  vi ANS(m);
  sort(all(I), [&](lli i, lli j){return sorter(M[i])<sorter(M[j]); });

  //
  for(lli i : I) {
    lli x = M[i].x(), t = M[i].y();
    // cerr << i << " " << M[i] << endl;

    // find blocking !
    lli r0=-1; lli t1;
    { lli x0=x;
      lli t0=t;
      while(x0!=-1){
        pii r = tr.chains[tr.chain[x0]].A.query(0, tr.chainIx[x0], t0);
        if(r.x()!=-1){
          //cerr << r << endl;
          r0=tr.chains[tr.chain[x0]].nodes[r.x()];
          break;
        }
        lli nx0 = tr.parent[tr.chains[tr.chain[x0]].root];
        t0 += tr.depth[x0] - tr.depth[nx0];
        x0=nx0;
      }
    }
    if(r0==-1) {
      r0=0;
    }
    t1=t+tr.depth[x]-tr.depth[r0];
    //cerr << i << " " << r0 << " " << t << " " << t1 << endl;
    ANS[i] = t1+(t1-t);
    lli aD = tr.depth[r0];
    lli tgtC = tr.chain[r0];
    while(1) {
      auto& ch = tr.chains[tr.chain[x]];
      lli ix0=0; if(tr.chain[x] == tgtC) { ix0 = tr.chainIx[r0]+1; }
      if(ix0<=tr.chainIx[x]) {
        ch.A.set(ix0, tr.chainIx[x], t1+tr.depth[ch.nodes[ix0]]-aD); // TODO
        //cerr << "upd " << ix0 << " " << tr.chainIx[x] << " " <<  t1+tr.depth[ch.nodes[ix0]]-aD << endl;
      }
      // ch.A.print();
      if(tr.chain[x] == tgtC) break;
      x = tr.parent[tr.chains[tr.chain[x]].root];
    }
  }
  //

  FOR(i, m){
    printf("%lld ", ANS[i]);
  }
  printf("\n");
  return 0;
}
#endif