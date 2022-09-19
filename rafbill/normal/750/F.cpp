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


int nask=0;
#ifdef LOCAL

vvi T;
vi ask(int i){
  nask++;
  if(T[i].size() == 2) throw 0;
  return T[i];
}

#else

vi ask(int i){
  if(nask == 16) {
    cout << "! " << i+1 << endl << flush;
    throw 0;
  }
  nask++;
  cout << "? " << i+1 << endl << flush;
  int k; cin >> k;
  if(k==0) exit(0);
  vi ans(k); FOR(i,k) cin >> ans[i];
  FOR(i,k) ans[i]--;
  if(k == 2) {
    cout << "! " << i+1 << endl << flush;
    throw 0;
  }
  return ans;
}

#endif

void solve(){
  int h;
#ifdef LOCAL
  h = 2+rand()%6;
  vi I((1<<h)-1); iota(all(I),0); random_shuffle(all(I));
  T.clear(); T.resize((1<<h)-1);
  FOR(i,(1<<(h-1))-1) {
    T[I[i]].pb(I[(2*(i+1)-1)]); T[I[(2*(i+1)-1)]].pb(I[i]); T[I[i]].pb(I[(2*(i+1)-1)+1]); T[I[(2*(i+1)-1)+1]].pb(I[i]);
  }
  FOR(i,1<<(h-1)) sort(all(T[i]));
#else
  cin >> h;
#endif
  int m = (1<<h)-1;
  vi II(m); iota(all(II),0); random_shuffle(all(II));
  vi JJ(m); FOR(i,m) JJ[II[i]]=i;

  if(h==0) exit(0);
  vi E((1<<h)-1);
  vvi K((1<<h)-1);
  auto ask_ = [&](int i) {
    if(K[i].empty()) {
      K[i] = ask(II[i]);
      for(int&j:K[i]) j=JJ[j];
    }
    return K[i];
  };

  if((1<<h)-1 <= 17) FOR(i,(1<<h)-1) ask(i);

  int i=0;
  int h0=h-1;

  if(ask_(i).size() == 1) i = ask_(i)[0];
  if(ask_(i).size() != 1) {
    deque<int> P;
    P.pb(i);
    { int j = i;
      while(1) {
        E[j] = 1;
        K[j] = ask_(j);
        if(K[j].size() == 1) break;
        FOR(k,3) if(K[j][k]!=j && !E[K[j][k]]) { j = K[j][k]; break; }
        P.pb(j);
      }
    }
    { int j = i;
      while(1) {
        E[j] = 1;
        K[j] = ask_(j);
        if(K[j].size() == 1) break;
        FOR(k,3) if(K[j][k]!=j && !E[K[j][k]]) { j = K[j][k]; break; }
        P.push_front(j);
      }
    }
    int m = P.size();
    i = P[m/2];
    h0 = h-1-(m/2);
  }else{
    i = ask_(i)[0];
    E[i]=1;
    h0 = h-2;
  }

  while(h0 >= 3) {
    ask_(i);
    assert(ask_(i).size() == 3);
    int nex=0;
    FOR(j,3) if(E[ask_(i)[j]]) nex++;
    if(nex == 2) {
      FOR(j,3) if(!E[ask_(i)[j]]) { E[i]=1; i = ask_(i)[j]; E[i]=1; h0--; break; }
    }else{
      vi P; P.pb(i);
      int d = h-1-h0;
      { int j=-1; FOR(k,3) if(!E[K[i][k]]) { j = K[i][k]; break; }
        assert(j!=-1);
        while(1) {
          ask_(j);
          if(K[j].size() == 1) {
            E[P[1]]=1;
            FOR(j,3) if(!E[ask_(i)[j]]) { E[i]=1; i = ask_(i)[j]; E[i]=1; h0--; break; }
            break;
          }
          FOR(k,3) if(K[j][k] != P.back()) { P.pb(j); j = K[j][k]; break; }
          --d;
          if(d == 0) {
            E[P[1]]=1;
            i=P[1];
            h0--;
            break;
          }
        }
      }
    }
  }

  function<void(int, int)> dfs = [&](int i, int d){
    E[i]=1;
    ask_(i);
    if(d==0) return;
    for(int j : K[i]) if(!E[j]) dfs(j,d-1);
  };
  dfs(i,h0);

  assert(0);
}

int main(){
  srand(time(0));
  ios::sync_with_stdio(0);
  int t; cin >> t;
  FOR(i,t) {
    try{
      nask=0;
      solve();
    }catch(int){
    }
  }
  return 0;
}