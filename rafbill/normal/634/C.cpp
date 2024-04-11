#pragma GCC optimize ("-O3")
#define _GLIBCXX_USE_CXX11_ABI 0
#include <bits/stdc++.h>

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

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

using pii   = tuple<lli, lli>;
using piii  = tuple<lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;

//------------------------------------------------------------------------------

template<size_t...>
struct my_index_sequence {
  using type = my_index_sequence;
};

namespace my_index_sequence_detail {
  template<typename I, typename J> struct concat;
  template<size_t... I, size_t... J>
  struct concat<my_index_sequence<I...>, my_index_sequence<J...>> :
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

template<class T, size_t I>
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
struct node {
  node() { }
  lli sum  = 0;
  lli dsum = 0;
};

struct tree {
  lli n;
  vector<node> A;
  tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n) { }

  void push(lli i, lli a, lli b){
  }

  void update(lli i){
    A[i].sum = A[2*i].sum + A[2*i+1].sum;
  }

  void add__(lli i, lli a, lli b, lli v){
    A[i].sum = v;
  }

  void add_(lli i, lli a, lli b, lli l, lli r, lli v){
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      add__(i, a, b, v);
      return;
    }
    push(i, a, b);
    lli c = (a+b)/2;
    add_(2*i  , a  , c, l, r, v);
    add_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void add(lli l, lli r, lli v){
    add_(1, 0, n-1, l, r, v);
  }

  lli query_(lli i, lli a, lli b, lli l, lli r){
    if(l > b) return 0;
    if(r < a) return 0;
    if(l <= a && b <= r){
      return A[i].sum;
    }
    push(i, a, b);
    lli c = (a+b)/2;
    return query_(2*i  , a  , c, l, r) +
      query_(2*i+1, c+1, b, l, r);
  }

  lli query(lli l, lli r){
    if(r<l) return 0;
    return query_(1, 0, n-1, l, r);
  }
};

int main(int, char**){
  ios::sync_with_stdio(0);
  lli n, k, a, b, q; cin >> n >> k >> a >> b >> q;
  vi NO(n, 0);
  tree ta(n), tb(n);
  FOR(q_, q) {
    lli t; cin >> t;
    if(t == 1) {
      lli d, c; cin >> d >> c; d -= 1;
      NO[d] += c;
      tb.add(d, d, min(NO[d], b));
      ta.add(d, d, min(NO[d], a));
    }else{
      lli p; cin >> p; p -= 1;
      cout << tb.query(0, p-1) + ta.query(p+k, n-1) << endl;
    }
  }

  return 0;
}