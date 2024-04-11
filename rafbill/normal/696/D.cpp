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

// --- BEGIN SNIPPET AHO CORASICK ---

template<class U>
struct aho_corasick {

  struct node {
    unordered_map<lli, lli> nexts;
    lli back;
    unordered_set<lli> ends;
  };

  vector<node> T;

  aho_corasick(vector<U> const& W){
    T.pb(node());
    FOR(i, W.size()){
      lli n = 0;
      for(lli c : W[i]){
        if(T[n].nexts.count(c) == 0){
          T[n].nexts[c] = T.size();
          T.pb(node());
        }
        n = T[n].nexts[c];
      }
      T[n].ends.insert(i);
    }
    // ---
    queue<lli> q; q.push(0);
    T[0].back = -1;
    while(!q.empty()){
      lli n = q.front(); q.pop();
      // Remove this line if only the largest match at each position is needed
      if(T[n].back != -1) for(auto i : T[T[n].back].ends) T[n].ends.insert(i);
      // ---
      for(auto p : T[n].nexts){
        lli b = T[n].back;
        while(b != -1 && T[b].nexts.count(p.first) == 0)
          b = T[b].back;
        T[p.second].back = (b==-1)?0:T[b].nexts[p.first];
        q.push(p.second);
      }
    }
  }

  lli next(lli S, lli x){
    while(S != -1 && T[S].nexts.count(x) == 0) S = T[S].back;
    return (S==-1)?0:T[S].nexts[x];
  }

  vi states(U const& A) {
    lli S = 0;
    vi R(A.size());
    FOR(i, A.size()){
      S = next(S, A[i]);
      R[i] = S; // occurences at i are aho.T[R[i]].ends
    }
    return R;
  }

};

// --- END SNIPPET AHO CORASICK ---

vvi multm(int m, vvi const& a, vvi const& b) {
  vvi c(m, vi(m, -999999999999999));
  FOR(i, m) FOR(j, m) FOR(k, m) c[i][j] = max(c[i][j], a[i][k]+b[k][j]);
  return c;
}

vvi fexp(int m, vvi M, lli b) {
  vvi x(m, vi(m, -999999999999999)); FOR(i, m) x[i][i] = 0;
  while(b>0) {
    if(b&1) x=multm(m, x, M);
    M=multm(m, M, M);
    b/=2;
  }
  return x;
}

int main(int, char**){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n, l; cin >> n >> l;
  vi A(n); FOR(i, n) cin >> A[i];
  vector<string> W(n); FOR(i, n) cin >> W[i];

  aho_corasick<string> ah(W);

  int m = ah.T.size();
  vi B(m, 0);
  FOR(i, m) for(int j : ah.T[i].ends) B[i] += A[j];
  vvi M(m, vi(m, -999999999999999));
  FOR(i, m) FOR(c, 26) {
    int j = ah.next(i, 'a'+c);
    M[i][j] = B[j];
  }

  vvi ML = fexp(m, M, l);
  lli r = 0;
  FOR(j, m) r = max(r, ML[0][j]);
  cout << r << endl;

  return 0;
}