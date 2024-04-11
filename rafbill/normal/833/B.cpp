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

//------------------------------------------------------------------------------

struct node {
  int l,r;
  int v;
};

node pool[2000000]; int nnode=0;

int make(int l, int r) {
  int i = nnode++;
  if(l == r) {
    pool[i].l=pool[i].r=-1;
    pool[i].v=0;
    return i;
  } else {
    int m=(l+r)/2;
    pool[i].l = make(l,m);
    pool[i].r = make(m+1,r);
    pool[i].v = pool[pool[i].l].v + pool[pool[i].r].v;
    return i;
  }
}

void update(int i) {
  pool[i].v = pool[pool[i].l].v + pool[pool[i].r].v;
}

int add(int i, int l, int r, int x, int y) {
  int j = nnode++;
  pool[j] = pool[i];
  if(l == r) {
    pool[j].v += y;
    return j;
  }else{
    int m=(l+r)/2;
    if(x<=m) {
      pool[j].l = add(pool[j].l,l,m,x,y);
    }else{
      pool[j].r = add(pool[j].r,m+1,r,x,y);
    }
    update(j);
    return j;
  }
}

int get(int i, int l, int r, int a, int b, int acc) {
  if(a>r || b<l) return acc;
  if(a<=l && r<=b) return acc+pool[i].v;
  int m=(l+r)/2;
  return get(pool[i].l,l,m,a,b,get(pool[i].r,m+1,r,a,b,acc));
}


const int N = 50000;
int roots[N];

const int K = 60;

int n;
int A[N];
int dp[K][N];
int nxt[N];

void calc(int i,int l,int r,int optL,int optR){
  int m = (l+r)/2;
  int optM=optL; int curval=0;
  int base = get(roots[m],0,n-1,min(m-1,optR),m-1,0);
  { int val = dp[i][min(m-1,optR)] + base;
    if(val >= curval) { curval = val; optM = min(m-1,optR); }
  }
  FORD(k, min(m-1,optR)-1, optL){
    if(nxt[k] > m-1) base += 1;
    int val = dp[i][k] + base;
    if(val >= curval) { curval = val; optM = k; }
  }
  dp[i+1][m] = curval;
  if(l==r) return;
  calc(i,l,m,optL,optM);
  calc(i,m+1,r,optM,optR);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int k;

  cin>>n>>k;
  FOR(i,n) cin>>A[i];

  // n=35000; k=50;
  // FOR(i,n) A[i]=rand();

  { map<int,int> ALLX;
    FOR(i,n) { if(!ALLX.count(A[i])) { int j = ALLX.size(); ALLX[A[i]] = j; }}
    FOR(i,n) A[i] = ALLX[A[i]];
  }

  roots[0] = make(0,n-1);
  vi last(n,-1);
  FOR(i,n) nxt[i] = n+16;
  FOR(i,n) {
    int tr = roots[i];
    if(last[A[i]] != -1) {
      nxt[last[A[i]]] = i;
      tr = add(tr,0,n-1,last[A[i]],-1);
    }
    last[A[i]]=i;
    roots[i+1] = add(tr,0,n-1,i,1);
  }

  FOR(i,k) {
    calc(i,0,n,0,n-1);
  }
  cout << dp[k][n] << endl;
  return 0;
}