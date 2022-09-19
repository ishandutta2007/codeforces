#include <stdio.h>
#include <bits/stdc++.h>

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
  tpl(){}
  tpl(std::tuple<As...> const& b) { std::tuple<As...>::operator=(b); }

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

//------------------------------------------------------------------------------

const lli MOD = 998244353;

inline lli fexp(lli a, lli b, lli m=MOD) {
  lli r = 1;
  while(b){
    if(b&1) r = (r*a)%m;
    a = (a*a)%m;
    b /= 2;
  }
  return r;
}

inline lli invmod(lli a, lli m=MOD) {
  return fexp(a, m-2, m);
}

lli nmod(lli x) { return (x%MOD+MOD)%MOD; }

void fwht(lli *data, int dim) {
  for(int len = 1; 2 * len <= dim; len <<= 1) {
    for(int i = 0; i < dim; i += 2 * len) {
      for(int j = 0; j < len; j++) {
        lli a = data[i + j];
        lli b = data[i + j + len];
        data[i + j] = (a + b) % MOD;
        data[i + j + len] = (MOD + a - b) % MOD;
      }
    }
  }
}

lli dat[1<<17];

const int N = 2e5;
const int nr = 3;
lli a[N][nr];
lli db[1<<(nr-1)][1<<17];
lli ff[1<<(nr-1)];

const lli i2 = 499122177;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli inr = 1;
  FOR(j,nr-1) inr = inr*i2%MOD;
  int n; cin>>n;
  lli k; cin>>k;
  vi r(nr); FOR(i,nr) cin>>r[i];
  lli shift=0;

  FOR(i,n) {
    FOR(j,nr) cin>>a[i][j];
    shift ^= a[i][nr-1];
    FOR(j,nr-1) a[i][j] ^= a[i][nr-1];
  }

  FOR(m,1<<(nr-1)) {
    FOR(i,n) {
      lli x = 0;
      FOR(j,nr-1) if(m&(1<<j)) x ^= a[i][j];
      db[m][x] += 1;
    }
    fwht(db[m], 1<<k);
  }
  FOR(i,1<<k) {
    FOR(m,1<<(nr-1)) ff[m] = db[m][i];
    fwht(ff, 1<<(nr-1));
    dat[i] = 1;
    FOR(m,1<<(nr-1)) {
      lli x = r[nr-1];
      FOR(j,nr-1) x += (m&(1<<j))?-r[j]:r[j];
      (dat[i] *= fexp(nmod(x), (ff[m] * inr) % MOD)) %= MOD;
    }
  }

  fwht(dat, 1<<k);
  FOR(i,1<<k) (dat[i] *= fexp(i2,k)) %= MOD;
  FOR(i,1<<k) cout << dat[i^shift] << ' ';
  cout << endl;

  return 0;
}