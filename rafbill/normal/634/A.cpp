#pragma GCC optimize ("-O3")
#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/stdc++.h>

#define FOR(i, n)     for(int i = 0; i < (int)(n); ++i)
#define FORU(i, j, k) for(int i = (j); i <= (int)(k); ++i)
#define FORD(i, j, k) for(int i = (j); i >= (int)(k); --i)

#define DESTRUCT2(t, x, y)                      \
  auto&& x = get<0>(t);                         \
  auto&& y = get<1>(t);

#define DESTRUCT3(t, x, y, z)                   \
  auto&& x = get<0>(t);                         \
  auto&& y = get<1>(t);                         \
  auto&& z = get<2>(t);

#define DESTRUCT4(t, x, y, z, w)                \
  auto&& x = get<0>(t);                         \
  auto&& y = get<1>(t);                         \
  auto&& z = get<2>(t);                         \
  auto&& w = get<3>(t);

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

//------------------------------------------------------------------------------

using namespace std;
using lli = long long int;

using pii   = tuple<int, int>;
using piii  = tuple<int, int, int>;
using vi    = vector<int>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;

//------------------------------------------------------------------------------

template<lli... I>
struct my_index_sequence {
  using type = my_index_sequence;
  static constexpr array<lli, sizeof...(I)> value = { I... };
};

namespace my_index_sequence_detail {
  template<typename I, typename J> struct concat;
  template<lli... I, lli... J>
  struct concat<my_index_sequence<I...>, my_index_sequence<J...>> :
    my_index_sequence<I..., (sizeof...(I)+J)...> { };
  template<lli N> struct make_index_sequence :
    concat<typename make_index_sequence<N/2>::type, typename make_index_sequence<N-N/2>::type>::type { };
  template <> struct make_index_sequence<0> : my_index_sequence<>{};
  template <> struct make_index_sequence<1> : my_index_sequence<0>{};
}

template<class... A>
using my_index_sequence_for = typename my_index_sequence_detail::make_index_sequence<sizeof...(A)>::type;

template<class T, lli... I>
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
  return s << "(" << X(a) << ", " << Y(a) << ")";
}

template<class T, lli I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

//------------------------------------------------------------------------------

int main(int, char**){
  ios::sync_with_stdio(0);
  lli n; cin >> n;
  vi A, B;
  FOR(i, n) { lli x; cin >> x; if(x!=0) A.pb(x); }
  FOR(i, n) { lli x; cin >> x; if(x!=0) B.pb(x); }
  lli j = 0;
  while(B[j] != A[0]) j += 1;
  FOR(i, n-1) if(A[i] != B[(i+j)%(n-1)]) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}