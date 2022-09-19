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

// template<typename... As>
// struct tpl : public std::tuple<As...> {
//   using std::tuple<As...>::tuple;
//   tpl(std::tuple<As...> const& b) { std::tuple<As...>::operator=(b); }

//   template<typename T = tuple<As...> >
//   typename tuple_element<0, T>::type const&
//   x() const { return get<0>(*this); }
//   template<typename T = tuple<As...> >
//   typename tuple_element<0, T>::type&
//   x() { return get<0>(*this); }

//   template<typename T = tuple<As...> >
//   typename tuple_element<1, T>::type const&
//   y() const { return get<1>(*this); }
//   template<typename T = tuple<As...> >
//   typename tuple_element<1, T>::type&
//   y() { return get<1>(*this); }

//   template<typename T = tuple<As...> >
//   typename tuple_element<2, T>::type const&
//   z() const { return get<2>(*this); }
//   template<typename T = tuple<As...> >
//   typename tuple_element<2, T>::type&
//   z() { return get<2>(*this); }

//   template<typename T = tuple<As...> >
//   typename tuple_element<3, T>::type const&
//   w() const { return get<3>(*this); }
//   template<typename T = tuple<As...> >
//   typename tuple_element<3, T>::type&
//   w() { return get<3>(*this); }
// };

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
ostream& operator<<(ostream& s, tuple<A...> const& a);
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
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

//------------------------------------------------------------------------------

const int N=50000;

#ifdef LOCAL

lli start;
pii data[N];
void gen(){
  vi A(N); FOR(i,N) A[i] = 1+rand(); sort(all(A));
  vi I(N); iota(all(I),0); random_shuffle(all(I));
  start = I[0];
  FOR(i,N) {
    data[I[i]] = mt(A[i], (i==N-1)?-1:I[i+1]);
  }
}

pii query(lli i) {
  assert(0<=i&&i<N);
  return data[i];
}

#else

pii query(lli i) {
  cout << "? " << i+1 << endl << flush;
  lli val,nxt; cin>>val>>nxt;
  return mt(val,(nxt==-1)?-1:(nxt-1));
}

#endif

lli nqu=0;
map<lli,pii> cacheM;
pii qcache(lli i) {
  if(!cacheM.count(i)) {
    nqu+=1;
    cacheM[i] = query(i);
  }
  return cacheM[i];
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
  srand(time(0));
  gen();
  lli n = N;
  lli st = start;
  lli x = 1+rand();
#else
  lli n,st,x;
  cin>>n>>st>>x;
  st--;
#endif

  srand(time(0));
  vi I(n); iota(all(I),0); random_shuffle(all(I));
  vi E(n);
  I.pb(st);

  { auto p = qcache(st);
    if(get<0>(p) >= x) {
      cout << "! " << get<0>(p) << endl;
      return 0;
    }
  }

  map<lli,lli> M;
  FOR(k,1200) {
    if(I.empty()) break;
    lli i = I.back(); I.pop_back();
    if(E[i]) {k-=1; continue;}
    auto p = qcache(i);
    lli val,nxt; tie(val,nxt) = p;
    E[i] = 1; if(nxt != -1) E[nxt] = 1;
    M[val] = i;
  }

  lli lst = st;
  for(auto p : M) if(p.first < x) lst = p.second;
  while(1) {
    lli val,nxt; tie(val,nxt) = qcache(lst);
    if(val >= x) {
      cout << "! " << val << endl;
      return 0;
    }
    if(nxt == -1) {
      cout << "! " << -1 << endl;
      return 0;
    }
    assert(lst!=nxt);
    lst=nxt;
  }

  return 0;
}