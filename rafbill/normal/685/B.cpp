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
#define rall(x) rbegin(x), rend(x)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define PE flush << "\033[2K\r"

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
}

//------------------------------------------------------------------------------


// --- BEGIN SNIPPET TREE ---

struct treechain {
  lli root = -1;
  lli size = 0;
  vi  nodes;

  // using segment = segment_tree; // segment tree / bit / other
  // segment A;

  treechain() { }
  void build(){ }
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

  void read_graph(lli m) {
    FOR(i, m) {
      lli u, v; cin >> u >> v;
      u -= 1; v -= 1;
      G[u].pb(v); G[v].pb(u);
    }
  }

  void read_parent() {
    FOR(i, n-1) {
      lli j; cin >> j; j-=1;
      G[1+i].pb(j); G[j].pb(i+1);
    }
  }

  void dfs(function<void(lli, lli)> const& f){
    function<void(lli, lli)> dfs = [&](lli i, lli p){
      f(i, p);
      for(auto j : G[i]) if(j != p) dfs(j, i);
    };
    dfs(0, -1);
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

  // void calchld() {
  //   if(chains.empty()){
  //     calcsize();
  //     calcdepth();

  //     chain.assign(n, -1);
  //     for(auto i : rorder) {
  //       lli best = -1;
  //       for(auto j : G[i]) if(j != parent[i]) {
  //           if(best == -1 || size[j] > size[best]) best = j;
  //         }
  //       if(best == -1) {
  //         chain[i] = chains.size();
  //         chains.eb();
  //       }else{
  //         chain[i] = chain[best];
  //       }
  //       chains[chain[i]].size += 1;
  //     }

  //     chainIx.assign(n, -1);
  //     for(auto i : order) {
  //       if(parent[i]==-1 || chain[i] != chain[parent[i]]) chains[chain[i]].root = i;
  //       chainIx[i] = chains[chain[i]].nodes.size();
  //       chains[chain[i]].nodes.pb(i);
  //     };

  //     for(auto& c : chains) c.build();
  //   }
  // }

  // lli lca(lli a, lli b) {
  //   calchld();
  //   while(chain[a] != chain[b]) {
  //     if(depth[chains[chain[a]].root]>depth[chains[chain[b]].root]) {
  //       a = parent[chains[chain[a]].root];
  //     }else{
  //       b = parent[chains[chain[b]].root];
  //     }
  //   }
  //   if(depth[a]<depth[b]) return a; else return b;
  // }

  // lli dist(lli a, lli b) {
  //   calchld();
  //   return depth[a]+depth[b]-2*depth[lca(a, b)];
  // }

  // // arguments to f :
  // // segment, segment range, range in path from a to b (a = 0, b = dist(a, b))
  // // the segment range is increasing
  // // the range in path can be decreasing
  // void hld_query(lli a, lli b, function<void(treechain::segment&, lli, lli, lli, lli)> f) {
  //   calchld();
  //   lli from = 0, to = dist(a, b);
  //   while(chain[a] != chain[b]) {
  //     if(depth[chains[chain[a]].root]>depth[chains[chain[b]].root]) {
  //       lli a_ = parent[chains[chain[a]].root];
  //       lli d = depth[a]-depth[a_];
  //       f(chains[chain[a]].A, 0, chainIx[a], from+d, from);
  //       from += d;
  //       a = a_;
  //     }else{
  //       lli b_ = parent[chains[chain[b]].root];
  //       lli d = depth[b]-depth[b_];
  //       f(chains[chain[b]].A, 0, chainIx[b], to-d, to);
  //       to -= d;
  //       b = b_;
  //     }
  //   }
  //   if(depth[a]<depth[b]) {
  //     f(chains[chain[a]].A, chainIx[a]+1, chainIx[b], from, to);
  //   }else{
  //     f(chains[chain[a]].A, chainIx[b]+1, chainIx[a], from, to);
  //   }
  // }
};

// --- END SNIPPET TREE ---

int ans[300000];
int uf[300000];
int find(int i) {
  if(i == -1) return -1;
  return uf[i]==i?i:uf[i]=find(uf[i]);
}

int main(int, char**){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n, q; cin >> n >> q;
  tree t(n); t.read_parent();
  t.calcparent();
  t.calcsize();

  FOR(i, n) uf[i] = i;
  for(int i : t.rorder) {
    if(t.parent[i] == -1) continue;
    int s = t.size[i];
    int ms = 0;
    for(int j : t.G[i]) if(j!=t.parent[i]) ms = max<lli>(ms, t.size[j]);
    // 2*ms <= t <= 2*s+1
    int j = find(i);
    while(j != -1 && 2*ms <= t.size[j] && t.size[j] <= 2*s) {
      ans[j] = i; uf[j] = t.parent[j]; j = find(i);
    }
  }

  FOR(i, q) {
    lli j; cin >> j; cout << 1+ans[j-1] << '\n';
  }
  cout << flush;
  return 0;
}