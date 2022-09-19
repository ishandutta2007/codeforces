#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
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

using llu   = long long unsigned;

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

// --- BEGIN SNIPPET MAX FLOW PUSH RELABEL ---

struct MaxFlow {
  struct Edge {
    short from, to, index;
    int cap, flow;
    Edge(int from, int to, int cap, int flow, int index) :
      from(from), to(to), cap(cap), flow(flow), index(index) {}
  };

  int N;
  vector<vector<Edge> > G;
  vector<int> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  MaxFlow(int N = 0) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {
  }

  int addNode() {
    N += 1;
    G.eb(); excess.eb(); dist.eb(); active.eb(); count.eb(); count.eb();
    return N-1;
  }

  Edge* addEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    Edge* e = &G[from].back();
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    return e;
  }

  void enqueue(int v) {
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); }
  }

  void push(Edge &e) {
    int amt = min(excess[e.from], e.cap - e.flow);
    if(dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    enqueue(e.to);
  }

  void gap(int k) {
    FOR(v, N) {
      if(dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      enqueue(v);
    }
  }

  void relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for(Edge& e : G[v]) if(e.cap - e.flow > 0) {
        dist[v] = min(dist[v], dist[e.to] + 1);
      }
    count[dist[v]]++;
    enqueue(v);
  }

  void discharge(int v) {
    for(int i = 0; excess[v] > 0 && i < (int)G[v].size(); ++i) push(G[v][i]);
    if(excess[v] > 0) {
      if(count[dist[v]] == 1) {
        gap(dist[v]);
      } else {
        relabel(v);
      }
    }
  }

  int flow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for(Edge& e : G[s]) {
      excess[s] += e.cap;
      push(e);
    }
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      discharge(v);
    }
    int totflow = 0;
    for(Edge& e : G[s]) totflow += e.flow;
    return totflow;
  }
};

// // --- END SNIPPET MAX FLOW PUSH RELABEL ---


// --- BEGIN SNIPPET MAX FLOW DINIC ---

// struct MaxFlow {
//   const int infinity = numeric_limits<int>::max();

//   struct edge {
//     edge(int to_, int c_) : to(to_), c(c_), flow(0){ }
//     int to, c, flow;
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
//         if(i == T) break; //unchecked
//         for(edge *e : G[i]) if(e->c > e->flow && D[e->to] == -1){
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
//           if(e->c > e->flow && D[e->to] == D[i] + 1){
//             int df = dfs(e->to, min(f, e->c - e->flow));
//             if(df > 0){
//               cf += df;
//               f -= df;
//               e->flow += df;
//               e->rev->flow -= df;
//             }
//           }
//         }
//         return cf;
//       };
//       while(int df = dfs(S, infinity)) {
//         f += df;
//       }
//     }
//   }
// };

// --- END SNIPPET MAX FLOW DINIC ---

int A[3000];

char R[3000][3000];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin>>n>>m;
  int tot=n*(n-1);
  FOR(i,m) {
    cin >> A[i];
    tot-=A[i];
  }
  FORU(i,m,n-1) {
    A[i]=A[i-1];
  }
  if(tot<0) {
    cout << "no" << endl;
    return 0;
  }
  MaxFlow G(2+2*n+1);
  int S=0;
  int T=1;
  int T2=2+2*n;
  G.addEdge(T2,T,tot);
  FOR(i,n) {
    G.addEdge(S,2+i,2*(n-1-i));
    FORU(j,i,n-1) {
      G.addEdge(2+i,2+n+j,(i==j)?(2*(n-1)):2);
    }
    G.addEdge(2+n+i,(i<m)?T:T2,A[i]);
  }
  int f = G.flow(S,T);
  if(f != n*(n-1)) {
    cout << "no" << endl;
    return 0;
  }
  FOR(i,n) R[i][i]='X';
  FOR(i,n) for(auto const& e : G.G[2+i]) {
    int j = e.to - 2 - n;
    if(i==j) continue;
    if(!(j>=0&&j<n)) continue;
    //cerr << i << " " << j << " " << E[i][j].flow << endl;
    if(e.flow == 2) {
      R[i][j] = 'L'; R[j][i] = 'W';
    }else if(e.flow == 1) {
      R[i][j] = R[j][i] = 'D';
    }else{
      R[i][j] = 'W'; R[j][i] = 'L';
    }
  }
  cout << "yes" << endl;
  FOR(i,n) {
    FOR(j,n) {
      cout << R[i][j];
    }
    cout << '\n';
  }
  cout << flush;
  return 0;
}