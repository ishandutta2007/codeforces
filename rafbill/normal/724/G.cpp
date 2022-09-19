#ifndef __clang__
#pragma GCC optimize ("-O3")
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
void prlli_tuple(ostream& s, T const& a, my_index_sequence<I...>){
  using swallow = lli[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& prlli_collection(ostream& s, T const& a){
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
  prlli_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  prlli_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return prlli_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return prlli_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return prlli_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return prlli_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return prlli_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return prlli_collection(s, a); }

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

const lli MOD=1e9+7;

struct gauss {
  lli A[64];
  lli R;
  void reset(){FOR(i,64)A[i]=0;R=0;}
  void add(lli x) {
    R|=x;
    FOR(i, 64) if(x&(1ll<<i)) {
      if(A[i]) x ^= A[i];
      else {A[i]=x; break;}
    }
  }
  lli count(){
    lli r=0; FOR(i,64) if(A[i]!=0) r+=1; return r;
  }
};

int main(int, char**){
  lli n,m; n=read_positive(); m = read_positive();
  vvii G(n);
  FOR(i, m) {
    lli u = read_positive()-1;
    lli v = read_positive()-1;
    lli s = read_positive();
    G[u].pb(mt(v,s));
    G[v].pb(mt(u,s));
  }
  vi E(n);
  vi S(n);
  lli CNT[64][2];
  gauss g;
  function<void(lli, lli)> dfs = [&](lli i, lli s){
    E[i]=1; S[i]=s;
    FOR(i,64) { CNT[i][s&(1ll<<i)?1:0]+=1; }
    for(auto p : G[i]) {
      lli j = p.x(), t=p.y();
      if(E[j]) {
        g.add(s^t^S[j]);
      }else{
        dfs(j, s^t);
      }
    }
  };
  lli ans=0;
  lli p2[65];
  p2[0]=1;FOR(i,64)p2[i+1]=(p2[i]*2)%MOD;
  auto mul = [&](lli a,lli b){return (a%MOD*b%MOD)%MOD;};
  FOR(i, n) if(!E[i]) {
    FOR(i,64)FOR(j,2) CNT[i][j]=0;
    g.reset();
    dfs(i, 0);
    lli c = g.count();
    FOR(i, 64) {
      if(g.R&(1ll<<i)) {
        ans += mul(CNT[i][0],mul(CNT[i][1], mul(p2[c-1], p2[i])));
        ans += mul(((CNT[i][0]*(CNT[i][0]-1)+CNT[i][1]*(CNT[i][1]-1))/2),mul(p2[c-1],p2[i]));
      }else{
        ans += mul(CNT[i][0],mul(CNT[i][1], mul(p2[c], p2[i])));
      }
      // ans += (CNT[i][0]+CNT[i][1])*CNT[i][1]*(1ll<<(lli)r);
      ans %= MOD;
      ans += MOD;
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}