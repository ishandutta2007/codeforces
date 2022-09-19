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

bool A[502][502];
lli B[502][502];
lli C[502][502];

// --- BEGIN SNIPPET UNION FIND ---

struct union_find {
  vi A, R;
  vi S;

  union_find(lli n = 0) : A(n), R(n, 0), S(n, 1) {
    iota(all(A), 0);
  }

  lli addNode() {
    A.pb(A.size());
    return A.size()-1;
  }

  lli find(lli a) {
    return A[a] == a ? a : A[a] = find(A[a]);
  }

  void unite(lli a, lli b) {
    a = find(a); b = find(b);
    if(a==b) return;
    if(R[a] < R[b]) {
      A[a] = b;
      S[b] += S[a];
    }else if(R[b] < R[a]) {
      A[b] = a;
      S[a] += S[b];
    } else {
      A[a] = b; R[b] += 1;
      S[b] += S[a];
    }
  }
};

// --- END SNIPPET UNION FIND ---


int main(int, char**){
  ios::sync_with_stdio(0);

  lli n, k; cin >> n >> k;
  lli ix = 0;
  FOR(i, n) FOR(j, n) {
    char c; cin >> c;
    A[i+1][j+1] = c == '.';
    B[i+1][j+1] = (A[i+1][j+1]?0:1)+B[i][j+1]+B[i+1][j]-B[i][j];
    C[i+1][j+1] = ix++;
  }
  union_find uf(ix);
  vi cnt(ix, 0);
  FOR(i, n) FOR(j, n) if(A[i+1][j+1]) {
    if(i!=n-1) if(A[i+2][j+1]) uf.unite(C[i+1][j+1], C[i+2][j+1]);
    if(j!=n-1) if(A[i+1][j+2]) uf.unite(C[i+1][j+1], C[i+1][j+2]);
  }

  auto rat = [&](lli i, lli j) {
    return B[i+k][j+k]-B[i][j+k]-B[i+k][j]+B[i][j];
  };

  lli cur = 0;
  auto add = [&](lli i, lli j){
    if(A[i][j]) {
      lli l = uf.find(C[i][j]);
      if(cnt[l] == 0) cur += uf.S[l];
      cnt[l] += 1;
    }
  };
  auto rem = [&](lli i, lli j){
    if(A[i][j]) {
      lli l = uf.find(C[i][j]);
      cnt[l] -= 1;
      if(cnt[l] == 0) cur -= uf.S[l];
    }
  };

  lli mx = 0;
  FOR(i, n-k+1) {
    cur = 0; cnt.assign(ix, 0);
    FOR(a, k+2) FOR(b, k+2) if((a>0&&a<k+1)||(b>0&&b<k+1)) add(i+a, b);
    mx = max(mx, cur+rat(i, 0));
    FOR(j, n-k) {
      FOR(a, k) {
        rem(i+1+a, j);
        add(i+1+a, j+k+2);
      }
      rem(i, j+1); rem(i+k+1, j+1);
      add(i, j+k+1); add(i+k+1, j+k+1);
      mx = max(mx, cur+rat(i, j+1));
    }
  }
  cout << mx << endl;

  return 0;
}