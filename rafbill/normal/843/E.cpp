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

// --- BEGIN SNIPPET MAX FLOW DINIC ---

struct MaxFlow {
  const lli infinity = numeric_limits<lli>::max();

  struct edge {
    edge(lli to_, lli c_) : to(to_), c(c_), f(0){ }
    lli to, c, f;
    edge* rev;
  };

  vector<vector<edge*>> G;

  MaxFlow(lli n = 0) : G(n){ }

  lli addNode() {
    G.eb();
    return G.size()-1;
  }

  edge* addEdge(lli a, lli b, lli c){
    edge* e1 = new edge(b, c);
    edge* e2 = new edge(a, 0);
    e1->rev = e2; e2->rev = e1;
    G[a].pb(e1); G[b].pb(e2);
    return e1;
  }

  vector<edge*> get_minimum_cut(lli S){
    int n=G.size();
    vi E(n);
    function<void(int)> dfs = [&](int i){
      if(E[i]) return;
      E[i]=1;
      for(edge* e : G[i]) if(e->f<e->c) dfs(e->to);
    };
    dfs(S);
    vector<edge*> R;
    FOR(i,n) if(E[i]) for(edge* e : G[i]) if(!E[e->to]) R.pb(e);
    return R;
  }

  lli flow(lli S, lli T){
    lli N = G.size();
    lli f = 0;
    vi D, W;
    while(1){
      // bfs
      D.assign(N, -1);
      queue<lli> Q; Q.push(S); D[S] = 0;
      while(!Q.empty()){
        lli i = Q.front(); Q.pop();
        if(i == T) break;
        for(edge *e : G[i]) if(e->c > e->f && D[e->to] == -1){
            D[e->to] = D[i] + 1;
            Q.push(e->to);
          }
      }
      if(D[T] == -1) return f;
      // dfs
      W.assign(N, 0);
      function<lli(lli, lli)> dfs = [&](lli i, lli f){
        if(i == T) return f;
        lli cf = 0;
        for(; W[i] < (lli)G[i].size(); W[i]++) {
          edge *e = G[i][W[i]];
          if(e->c > e->f && D[e->to] == D[i] + 1){
            lli df = dfs(e->to, min(f, e->c - e->f));
            if(df > 0){
              cf += df;
              f -= df;
              e->f += df;
              e->rev->f -= df;
            }
          }
        }
        return cf;
      };
      while(lli df = dfs(S, infinity)) f += df;
    }
  }
};

// --- END SNIPPET MAX FLOW DINIC ---


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,s,t; cin>>n>>m>>s>>t;
  --s; --t;
  vvii G(n);
  vvi OF(n);
  FOR(i,m) {
    int u,v,g; cin>>u>>v>>g;
    --u; --v;
    G[u].pb(mt(v,g));
    OF[u].pb(i);
  }
  MaxFlow F(n);
  vector<vector<MaxFlow::edge*>> GE(n);
  FOR(i,n) for(auto const& p : G[i]) {
    int j,g; tie(j,g) = p;
    if(g == 1) {
      auto e = F.addEdge(i,j,1);
      F.addEdge(j,i,(1<<25));
      GE[i].pb(e);
    }else{
      auto e = F.addEdge(i,j,(1<<25));
      GE[i].pb(e);
    }
  }
  lli f = F.flow(s,t);
  auto mc = F.get_minimum_cut(s);
  set<MaxFlow::edge*> mcs(all(mc));
  vvii ans(n);
  int nmc=0;
  FOR(i,n) ans[i].assign(G[i].size(),mt(0,0));
  FOR(i,n) FOR(j,G[i].size()) {
    if(mcs.count(GE[i][j])) {
      ans[i][j] = mt(0,1);
      nmc+=1;
    }else{
      ans[i][j] = mt(0,(1<<20));
    }
  }
  FOR(i,n) FOR(j,G[i].size()) if(G[i][j].y() && !ans[i][j].x()) {
    auto test = [&](int i, int j) {
      vi E(n,0);
      function<bool(int)> dfs = [&](int i) -> bool {
        E[i]=1;
        if(i==j) return 1;
        FOR(j,G[i].size()) if(G[i][j].y() && !E[G[i][j].x()] && ans[i][j].x() != ans[i][j].y()) {
            if(dfs(G[i][j].x())) return 1;
          }
        return 0;
      };
      return dfs(i);
    };
    auto push = [&](int i, int j) {
      vi E(n,0);
      function<bool(int)> dfs = [&](int i) -> bool {
        E[i]=1;
        if(i==j) return 1;
        FOR(j,G[i].size()) if(G[i][j].y() && !E[G[i][j].x()] && ans[i][j].x() != ans[i][j].y()) {
          if(dfs(G[i][j].x())) {ans[i][j].x() += 1; return 1;}
        }
        return 0;
      };
      return dfs(i);
    };
    if(test(s,i) && test(G[i][j].x(),t)){
      push(s,i); push(G[i][j].x(),t);
      ans[i][j].x()+=1;
    }else{
      push(G[i][j].x(),i);
      ans[i][j].x()+=1;
    }
  }
  vii ans2(m,pii(0,0));
  FOR(i,n) FOR(j,G[i].size()) ans2[OF[i][j]] = ans[i][j];
  cout << nmc << endl;
  FOR(i,m) {
    cout << ans2[i].x() << " " << ans2[i].y() << '\n';
  }
  cout << flush;
  return 0;
}