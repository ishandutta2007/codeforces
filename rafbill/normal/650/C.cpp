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

//------------------------------------------------------------------------------

struct uf{
  vi A;
  uf(lli n) : A(n){ FOR(i, n) A[i] = i; }
  lli find(lli a) {
    return A[a] == a ? a : A[a] = find(A[a]);
  }
  void unite(lli a, lli b) {
    A[find(a)] = find(b);
  }
};

int main(int, char**){
  ios::sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vvi A(n, vi(m)); FOR(i, n) FOR(j, m) cin >> A[i][j];

  auto o = [&](int i, int j){ int r = i*m+j; return r; };
  uf U(n*m);
  vector<unordered_set<lli>> G(n*m);

  FOR(i, n) {
    vi I(m); iota(all(I), 0);
    sort(all(I), [&](int a, int b){
        return A[i][a] < A[i][b];
      });
    FOR(j, m-1) if(A[i][I[j]] == A[i][I[j+1]]) U.unite(o(i, I[j]), o(i, I[j+1]));
  }

  FOR(j, m) {
    vi I(n); iota(all(I), 0);
    sort(all(I), [&](int a, int b){
        return A[a][j] < A[b][j];
      });
    FOR(i, n-1) if(A[I[i]][j] == A[I[i+1]][j]) U.unite(o(I[i], j), o(I[i+1], j));
  }

  FOR(i, n) {
    vi I(m); iota(all(I), 0);
    sort(all(I), [&](int a, int b){
        return A[i][a] < A[i][b];
      });
    FOR(j, m-1) if(A[i][I[j]] != A[i][I[j+1]]) G[U.find(o(i, I[j]))].insert(U.find(o(i, I[j+1])));
  }

  FOR(j, m) {
    vi I(n); iota(all(I), 0);
    sort(all(I), [&](int a, int b){
        return A[a][j] < A[b][j];
      });
    FOR(i, n-1) if(A[I[i]][j] != A[I[i+1]][j]) G[U.find(o(I[i], j))].insert(U.find(o(I[i+1], j)));
  }

  vvi RG(n*m);
  FOR(i, n*m) if(U.find(i) == i) for(auto j : G[i]) RG[j].pb(i);

  int a = n*m;
  vi E(a);
  vi stack;
  function<void(int)> dfs = [&](int i){
    E[i] = 1;
    for(auto j : G[i]) if(!E[j]) {
        dfs(j);
      }
    stack.pb(i);
  };
  FOR(i, a) if(!E[i] && U.find(i) == i) dfs(i);

  vi AS(n*m);
  while(!stack.empty()) {
    int i = stack.back(); stack.pop_back();
    int mx = 0;
    for(auto j : RG[i]) {
      mx = max<int>(mx, AS[j]);
    }
    AS[i] = mx+1;
  }

  FOR(i, n) {
    FOR(j, m) cout << AS[U.find(o(i, j))] << ' ';
    cout << '\n';
  }
  cout << flush;

  return 0;
}