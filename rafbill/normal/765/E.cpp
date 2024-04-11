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


// --- BEGIN SNIPPET TREE ---


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

  void read_graph(istream& input = cin) {
    FOR(i, n-1) {
      lli u, v; input >> u >> v;
      u -= 1; v -= 1;
      G[u].pb(v); G[v].pb(u);
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
      eorder.reserve(2*n);
      vi E1(n); vi R(n,0);
      auto E = makeEVec(false);
      FOR(i, n) FOR(j_, G[i].size()) if(!E[i][j_]) {
        vii Q; Q.pb(mt(i,j_));
        vii tmp;
        while(!Q.empty()) {
          DESTRUCT2(Q.back(), i, j_); Q.pop_back();
          tmp.pb(mt(i, j_)); E[i][j_] = 1;
          lli j = G[i][j_];
          if(!E1[j]) {
            E1[j]=1;
            FOR(k_, G[j].size()) {
              if(G[j][k_] == i) R[j]=k_;
              if(G[j][k_] != i && !E[j][k_]) Q.pb(mt(j, k_));
            }
          }else{
            if(G[j][R[j]]!=i && !E[j][R[j]]) Q.pb(mt(j,R[j]));
          }
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

const int N=200010;
unordered_map<int,int> M1[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  tree t(n); t.read_graph();
  t.calceorder();
  map<pii,int> M2;
  for(auto e : t.eorder) {
    int i = e.x(); int j_ = e.y(); int j = t.G[i][j_];
    if(M2.count(mt(j,i))) {
      M1[j][M2[mt(j,i)]]--;
      if(M1[j][M2[mt(j,i)]] == 0) M1[j].erase(M2[mt(j,i)]);
    }
    int res=-1;
    if(M1[j].empty()) {
      res=1;
    }else{
      if(M1[j].size()==1 && 0<=M1[j].begin()->first) {
        res = 1+M1[j].begin()->first;
      }
    }
    M2[mt(i,j)]=res;
    M1[i][res]++;
    //cout << i << " " << j << " " << res << endl;
    if(M2.count(mt(j,i))) {
      M1[j][M2[mt(j,i)]]++;
    }
  }
  bool ok=0;
  int ans=(1<<30);
  FOR(i,n) {
    set<int> S;
    for(auto i : M1[i]) S.insert(i.first);
    if(S.count(-1)) continue;
    if(S.size() <= 2) {
      int cur=0;for(int j:S) cur+=j;
      ans=min(cur,ans); ok=1;
    }
  }
  if(ok) {
    while(ans%2==0) ans/=2;
    cout << ans << endl;
  }else{
    cout << -1 << endl;
  }
  return 0;
}