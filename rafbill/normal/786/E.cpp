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

using lli   = int;
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

// --- BEGIN SNIPPET MAX FLOW DINIC ---

// const int infinity = numeric_limits<int>::max();
// struct MaxFlow {

//   struct edge {
//     edge(int to_, int c_) : to(to_), c(c_), f(0){ }
//     int to, c, f;
//     edge* rev;
//   };

//   vector<vector<edge*>> G;

//   MaxFlow(int n = 0) : G(n){ }

//   int addNode() {
//     G.eb();
//     return G.size()-1;
//   }

//   edge* addEdge(int a, int b, int c){
//     edge* e1 = new edge(b, c);
//     edge* e2 = new edge(a, 0);
//     e1->rev = e2; e2->rev = e1;
//     G[a].pb(e1); G[b].pb(e2);
//     return e1;
//   }

//   vector<edge*> get_minimum_cut(int S){
//     int n=G.size();
//     vi E(n);
//     function<void(int)> dfs = [&](int i){
//       if(E[i]) return;
//       E[i]=1;
//       for(edge* e : G[i]) if(e->f<e->c) dfs(e->to);
//     };
//     dfs(S);
//     vector<edge*> R;
//     FOR(i,n) if(E[i]) for(edge* e : G[i]) if(!E[e->to]) R.pb(e);
//     return R;
//   }

//   int flow(int S, int T){
//     int N = G.size();
//     int f = 0;
//     vi D, W;
//     while(1){
//       // bfs
//       D.assign(N, -1);
//       queue<int> Q; Q.push(S); D[S] = 0;
//       while(!Q.empty()){
//         int i = Q.front(); Q.pop();
//         if(i == T) break;
//         for(edge *e : G[i]) if(e->c > e->f && D[e->to] == -1){
//             D[e->to] = D[i] + 1;
//             Q.push(e->to);
//           }
//       }
//       if(D[T] == -1) return f;
//       // dfs
//       W.assign(N, 0);
//       function<int(int, int)> dfs = [&](int i, int f){
//         if(i == T) return f;
//         int cf = 0;
//         for(; W[i] < (int)G[i].size(); W[i]++) {
//           edge *e = G[i][W[i]];
//           if(e->c > e->f && D[e->to] == D[i] + 1){
//             int df = dfs(e->to, min(f, e->c - e->f));
//             if(df > 0){
//               cf += df;
//               f -= df;
//               e->f += df;
//               e->rev->f -= df;
//             }
//           }
//         }
//         return cf;
//       };
//       while(int df = dfs(S, infinity)) f += df;
//     }
//   }
// };

// // --- END SNIPPET MAX FLOW DINIC ---

// --- BEGIN SNIPPET MAX FLOW PUSH RELABEL ---

struct MaxFlow {
  struct edge {
    lli from, to, cap, flow, index;
    edge(lli from, lli to, lli cap, lli flow, lli index) :
      from(from), to(to), cap(cap), flow(flow), index(index) {}
  };

  lli N;
  vector<vector<edge> > G;
  vector<lli> excess;
  vector<lli> dist, active, count;
  queue<lli> Q;

  MaxFlow(lli N = 0) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) { }

  lli addNode() {
    N += 1;
    G.eb(); excess.eb(); dist.eb(); active.eb(); count.eb(); count.eb();
    return N-1;
  }

  pii addedge(lli from, lli to, lli cap) {
    G[from].push_back(edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(edge(to, from, 0, 0, G[from].size() - 1));
    return mt(from,G[from].size()-1);
  }

  void enqueue(lli v) {
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
  }

  void push(edge &e) {
    lli amt = min(excess[e.from], e.cap - e.flow);
    if(dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    enqueue(e.to);
  }

  void gap(lli k) {
    FOR(v, N) {
      if(dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      enqueue(v);
    }
  }

  void relabel(lli v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for(edge& e : G[v]) if(e.cap - e.flow > 0) {
        dist[v] = min(dist[v], dist[e.to] + 1);
      }
    count[dist[v]]++;
    enqueue(v);
  }

  void discharge(lli v) {
    for(lli i = 0; excess[v] > 0 && i < (lli)G[v].size(); ++i) push(G[v][i]);
    if(excess[v] > 0) {
      if(count[dist[v]] == 1) {
        gap(dist[v]);
      } else {
        relabel(v);
      }
    }
  }

  lli flow(lli s, lli t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for(edge& e : G[s]) {
      excess[s] += e.cap;
      push(e);
    }
    while (!Q.empty()) {
      lli v = Q.front();
      Q.pop();
      active[v] = false;
      discharge(v);
    }
    lli totflow = 0;
    for(edge& e : G[s]) totflow += e.flow;
    return totflow;
  }

  vector<pii> get_minimum_cut(int S){
    int n=G.size();
    vi E(n);
    function<void(int)> dfs = [&](int i){
      if(E[i]) return;
      E[i]=1;
      for(edge const& e : G[i]) if(e.flow<e.cap) dfs(e.to);
    };
    dfs(S);
    vector<pii> R;
    FOR(i,n) if(E[i]) FOR(j,G[i].size()) if(!E[G[i][j].to]) R.pb(mt(i,j));
    return R;
  }


};

// --- END SNIPPET MAX FLOW PUSH RELABEL ---


const int K=15;
int A[(1<<K)][K];
int depth[1<<K];
int parent[1<<K][K];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m; cin>>n>>m;
  vvi G(n);
  map<pii,int> ixs;
  FOR(i,n-1) {
    int u,v; cin>>u>>v; --u; --v; G[u].pb(v); G[v].pb(u);
    ixs[mt(u,v)]=i;
    ixs[mt(v,u)]=i;
  }
  function<void(int,int,int)> dfs = [&](int i, int p, int d){
    depth[i]=d;
    parent[i][0]=p;
    for(int j : G[i]) if(j!=p) dfs(j,i,d+1);
  };
  dfs(0,-1,0);
  FOR(i,K-1) FOR(j,n) if(depth[j] >= (1<<(i+1))) parent[j][i+1]=parent[parent[j][i]][i];

  MaxFlow flow; int S=flow.addNode(),T=flow.addNode();
  FOR(i,n) FOR(j,K) A[i][j]=flow.addNode();
  map<pii, int> ANS0;
  map<pii, int> ANS1;
  FOR(i,n) if(i) { auto e = flow.addedge(A[i][0],T,1); ANS0[e] = ixs[mt(i,parent[i][0])]; }
  FOR(i,K-1) FOR(j,n) if(depth[j] >= (1<<(i+1))) {
    flow.addedge(A[j][i+1], A[j][i], (1<<26));
    flow.addedge(A[j][i+1], A[parent[j][i]][i], (1<<26));
  }
  FOR(i,m) {
    int x=0, y=0; cin>>x>>y; --x; --y;
    int no=flow.addNode();
    auto e = flow.addedge(S,no,1); ANS1[e]=i;
    if(depth[x]<depth[y]) swap(x,y);
    FORD(i,K-1,0) if(depth[x]>=depth[y]+(1<<i)) {
      flow.addedge(no,A[x][i],(1<<26));
      x = parent[x][i];
    }
    if(x==y) continue;
    FORD(i,K-1,0) if(depth[x]>=(1<<i) && parent[x][i] != parent[y][i]) {
      flow.addedge(no,A[x][i],(1<<26));
      flow.addedge(no,A[y][i],(1<<26));
      x=parent[x][i];
      y=parent[y][i];
    }
    flow.addedge(no,A[x][0],(1<<26));
    flow.addedge(no,A[y][0],(1<<26));
  }
  int f=flow.flow(S,T);
  cout << f << endl;
  auto ct = flow.get_minimum_cut(S);
  vi a0,a1;
  for(auto e : ct) {
    if(ANS0.count(e)) a0.pb(ANS0[e]);
    if(ANS1.count(e)) a1.pb(ANS1[e]);
  }
  sort(all(a0));
  sort(all(a1));
  cout << a1.size(); for(int i : a1) cout << ' ' << i+1; cout << endl;
  cout << a0.size(); for(int i : a0) cout << ' ' << i+1; cout << endl;

  return 0;
}