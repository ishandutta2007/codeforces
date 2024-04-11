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

// --- BEGIN SNIPPET BINARY INDEXED TREE ---

struct BIT {
  vi A;
  BIT() = default;
  BIT(lli n) : A(n+1){ }

  void assign(lli n){
    A.assign(n+1,0);
  }

  lli get(lli i){
    i += 1;
    lli r = 0;
    for(; i > 0; i -= i &-i){
      r += A[i];
    }
    return r;
  }

  void add(lli i, lli v){
    i += 1;
    for(; i < (lli)A.size(); i += i & -i){
      A[i] += v;
    }
  }
};

// --- END SNIPPET BINARY INDEXED TREE ---

int dcd(char c){
  if(c=='A') return 0;
  if(c=='T') return 1;
  if(c=='G') return 2;
  if(c=='C') return 3;
  assert(0);
}

const char* AS = "ACTG";
BIT bits[4][11][11];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

#ifndef LOCAL
  string s; cin >> s;
  lli q; cin >> q;
  lli n=s.size();
#else
  int n=100000;
  string s;
  FOR(i,n) s.pb(AS[rand()%4]);
  lli q=100000;
#endif

  FOR(a,4) FORU(i,1,10) FOR(j,i) bits[a][i][j].assign((n/i) + 1);
  FOR(i,n) {
    lli c=dcd(s[i]);
    FORU(e,1,10) {
      bits[c][e][i%e].add(i/e,1);
    }
  }
  FOR(q_,q) {
    lli ty;
#ifndef LOCAL
    cin >> ty;
#else
    ty = 1+rand()%2;
#endif
    if(ty == 1) {
      lli x; char c_;
#ifndef LOCAL
      cin>>x>>c_; x--;
#else
      x = rand()%n;
      c_ = AS[rand()%4];
#endif
      lli c0=dcd(s[x]), c1=dcd(c_);
      FORU(e,1,10) {
        bits[c0][e][x%e].add(x/e,-1);
        bits[c1][e][x%e].add(x/e,1);
      }
      s[x]=c_;
    }else{
#ifndef LOCAL
      lli l,r; cin>>l>>r; --l; --r;
      string t; cin >> t;
#else
      lli l = rand()%n, r = rand()%n;
      if(l>r) swap(l,r);
      int tsz = 1+rand()%10;
      string t; FOR(i,tsz) t.pb(AS[rand()%4]);
#endif
      lli from=l;
      lli sz=t.size();
      lli ans=0;
      // lli ans1=0;
      // { lli l0=l;
      //   while(l0<=r) {
      //     if(t[(l0-from)%sz] == s[l0]) ans1 += 1;
      //     l0 += 1;
      //   }
      // }
      if(r-l <= 13) {
        while(l<=r) {
          if(t[(l-from)%sz] == s[l]) ans += 1;
          l += 1;
        }
      }else{
        while(l%sz != 0) {
          if(t[(l-from)%sz] == s[l]) ans += 1;
          l += 1;
        }
        while(r%sz != sz-1) {
          if(t[(r-from)%sz] == s[r]) ans += 1;
          r -= 1;
        }
        int a0 = l/sz, a1 = r/sz;
        FOR(i,sz) {
          int c = dcd(t[i]);
          ans += bits[c][sz][(from+i)%sz].get(a1);
          if(a0) ans -= bits[c][sz][(from+i)%sz].get(a0-1);
        }
      }
      // if(ans != ans1) {
      //   cout << s << endl;
      //   cout << t << endl;
      //   cout << ans << " " << ans1 << endl;
      //   exit(0);
      // }
      cout << ans << '\n';
    }
  }
  cout << flush;
  return 0;
}