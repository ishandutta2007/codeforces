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

// --- BEGIN SNIPPET SEGMENT TREE ---

struct segment_tree {

  struct node {
    node(){
      FOR(i,10) masks[i]=0;
      FOR(i,10) rename[i]=i;
    }
    array<lli,10> masks;
    bool dirty = 0;
    array<lli,10> rename;

    lli sum() {
      lli ans=0;
      FOR(i,10) ans += i*masks[i];
      return ans;
    }

    void combine(node &a, node& b) {
      dirty=0;
      FOR(i,10) rename[i] = i;
      FOR(i,10) masks[i] = a.masks[i] + b.masks[i];
    }
  };

  lli n;
  vector<node> A;
  segment_tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n) { }

  void update(lli i) {
    if(i < n) {
      A[i].combine(A[2*i],A[2*i+1]);
    }
  }

  void build(){
    FORD(i,n-1,1) update(i);
  }

  void push(lli i){
    if(i < n){
      if(A[i].dirty) {
        rename___(2*i,A[i].rename);
        rename___(2*i+1,A[i].rename);
        // FOR(j,10) if(A[i].rename[j]!=j) {
        //   rename__(2*i  , j, A[i].rename[j]);
        //   rename__(2*i+1, j, A[i].rename[j]);
        //   A[i].rename[j]=j;
        // }
        FOR(j,10) A[i].rename[j]=j;
        A[i].dirty = 0;
      }
    }
  }

  void pushall(lli i) {
    push(i);
    if(i<n) { pushall(2*i); pushall(2*i+1); }
  }

  void rename___(lli i, array<lli,10> ar){
    FOR(j,10) A[i].rename[j] = ar[A[i].rename[j]];
    auto omasks = A[i].masks;
    FOR(j,10) A[i].masks[j]=0;
    FOR(j,10) A[i].masks[ar[j]] += omasks[j];
    A[i].dirty=1;
    if(i>=n) {
      A[i].dirty=0;
      FOR(j,10) A[i].rename[j]=j;
    }
  }

  void rename__(lli i, lli a, lli b){
    array<lli,10> ar; FOR(i,10) ar[i] = i; ar[a]=b;
    push(i);
    rename___(i,ar);
  }

  void rename_(lli i, lli a, lli b, lli l, lli r, lli from, lli to) {
    if(l > b) return;
    if(r < a) return;
    push(i);
    if(l <= a && b <= r){
      rename__(i, from, to);
      return;
    }
    lli c = (a+b)/2;
    rename_(2*i  , a  , c, l, r, from, to);
    rename_(2*i+1, c+1, b, l, r, from, to);
    update(i);
  }

  void rename(lli l, lli r, lli from, lli to){
    rename_(1, 0, n-1, l, r, from, to);
  }

  lli get_(lli i, lli a, lli b, lli l, lli r) {
    if(l > b) return 0;
    if(r < a) return 0;
    push(i);
    if(l <= a && b <= r){
      return A[i].sum();
    }
    lli c = (a+b)/2;
    lli ans= get_(2*i  , a  , c, l, r) +
      get_(2*i+1, c+1, b, l, r);
    update(i);
    return ans;
  }

  lli get(lli l, lli r){
    return get_(1, 0, n-1, l, r);
  }
};


// --- END SNIPPET SEGMENT TREE ---

#ifdef LOCAL
string replace(string a, lli x, lli y) {
  for(char& c : a) if(c==x) c=y;
  return a;
}
string all[1001];
lli val(string a) {
  reverse(all(a));
  lli p=1;
  lli s=0;
  for(char c:a) {
    s += (c-'0')*p;
    p*=10;
  }
  return s;
}
#endif

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n, q;
  srand(43);
#ifndef LOCAL
  cin>>n>>q;
#else
  n=100000;
  q=100000;
#endif
  segment_tree t(n);
  FOR(i,n) {
    string s;
#ifndef LOCAL
    cin >> s;
#else
    s+='1'; FOR(i,2) s += '0'+rand()%10;
#endif
    reverse(all(s)); lli p=1;
    for(char c : s) {
      t.A[t.n+i].masks[c-'0'] += p;
      p *= 10;
    }
  }
  t.build();
  FOR(q_,q) {
    lli ty;
#ifndef LOCAL
    cin>>ty;
#else
    ty=1+rand()%2;
#endif
    if(ty==1) {
      lli l,r,a,b;
#ifndef LOCAL
      cin>>l>>r>>a>>b; --l; --r;
#else
      l=rand()%n;
      r=rand()%n;
      if(l>r) swap(l,r);
      a=b=0;
      while(a==b) {
        a=rand()%10;
        b=1+rand()%9;
      }
      //FORU(i,l,r) all[i]=replace(all[i],'0'+a,'0'+b);
#endif
      t.rename(l,r,a,b);
    }else{
      lli l,r;
#ifndef LOCAL
      cin>>l>>r; --l; --r;
#else
      l=rand()%n;
      r=rand()%n;
      if(l>r) swap(l,r);
      //lli ans0=0; FORU(i,l,r) ans0 += val(all[i]);
#endif
      lli ans=t.get(l,r);
      // if(ans != ans0) {
      //   cout << ans << ' ' << ans0 << endl;
      // }
      // assert(ans0==ans);
      cout << ans << '\n';
    }
    // FOR(i,n) assert(val(all[i]) == t.get(i,i));
  }
  cout << flush;
  return 0;
}