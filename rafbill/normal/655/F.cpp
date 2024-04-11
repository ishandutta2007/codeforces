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

int readint(FILE* file = stdin) {
  register int c = 0;
  while((c<'0' || c>'9') && c != '-') c = fgetc(file);
  int x = 0;
  bool neg = 0;
  if(c == '-') {
    neg = true;
    c = fgetc(file);
  }
  for(; c >= '0' && c <= '9'; c = fgetc(file)) {
    x = (x << 1) + (x << 3) + c - '0';
  }
  if(neg) x = -x;
  return x;
}

int readposint(FILE* file = stdin) {
  register int c = 0;
  while(c<'0' || c>'9') c = fgetc(file);
  int x = 0;
  for(; c >= '0' && c <= '9'; c = fgetc(file)) {
    x = (x << 1) + (x << 3) + c - '0';
  }
  return x;
}

//------------------------------------------------------------------------------

vi  primes;
lli sieve[1000001];
lli     C[1000001];

const lli MOD = 1e9+7;

lli fexp(lli a, lli n){
  if(n == 0) return 1;
  if(n == 1) return a;
  lli b = fexp(a, n/2);
  lli c = (b*b)%MOD;
  if(n%2) (c*=a)%=MOD;
  return c;
}

lli invmod(lli a){
  return fexp(a, MOD-2);
}

int main(int, char**){
  ios::sync_with_stdio(0);

  FORU(i, 2, 1000000) sieve[i] = 1;
  FORU(i, 2, 1000000) if(sieve[i]){
    primes.pb(i);
    lli k = 2;
    while(i*k<=1000000) { sieve[i*k] = 0; k += 1; }
  }

  FORU(i, 1, 1000000) C[i] = i;

  FORU(i, 1, 1000000) {
    lli k = 2;
    while(i*k<=1000000) { C[i*k] -= C[i]; k += 1; }
  }

  lli n, k, q; cin >> n >> k >> q;

  vi cnk(n+q+10);
  cnk[k] = 1;
  FORU(i, k+1, n+q+9) {
    cnk[i] = (((cnk[i-1] * i)%MOD) * invmod(i-k))%MOD;
  }

  lli r = 0;
  vi A(1000001, 0);
  auto add1 = [&](lli x){
    r -= C[x]*cnk[A[x]];
    A[x] += 1;
    r += C[x]*cnk[A[x]];
  };
  auto add = [&](lli x){
    add1(1);
    FORU(i, 2, 1000) {
      if(i*i > x) break;
      if(x%i==0&&x!=i) {
        add1(i);
        if(i*i != x) add1(x/i);
      }
    }
    if(x != 1) add1(x);
    r %= MOD;
    r += MOD;
    r %= MOD;
  };
  FOR(i, n) {
    lli x; cin >> x; add(x);
  }
  FOR(i, q) {
    lli x; cin >> x; add(x);
    printf("%lld\n", r);
  }
  cout << flush;

  return 0;
}