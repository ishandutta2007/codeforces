#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
#endif
#ifdef ONLINE_JUDGE
#define NDEBUG 1
#endif
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

long double eps = 1e-10;
using cpx = complex<long double>;
struct ci {
  lli x,y,r;
  void re(){
    cin>>x>>y>>r;
  }
  bool inter(ci const& o) const {
    lli d = SQ(x-o.x)+SQ(y-o.y);
    return SQ(abs(r-o.r)) <= d && d <= SQ(abs(r+o.r));
  }
  bool dinter(ci const& o)  const{
    lli d = SQ(x-o.x)+SQ(y-o.y);
    return SQ(r-o.r) < d && d < SQ(r+o.r);
  }
  cpx pt() const { return cpx(x,y); }

  vector<cpx> inters(ci const& o) const {
    if(!inter(o)) return {};
    long double d = sqrt(SQ(x-o.x)+SQ(y-o.y));
    long double x = (d*d-o.r*o.r+r*r)/2./d;
    if(!dinter(o)) return {(o.pt()-pt())*x/d};
    long double y = sqrt(r*r-x*x);
    auto p = (o.pt()-pt())/d;
    return {x*p+cpx(0,1)*y*p,x*p-cpx(0,1)*y*p};
  }
};

vector<cpx> mer(vector<cpx> a, vector<cpx> b) {
  for(auto p : b) {
    for(auto q : a) if(abs(p-q) < eps) goto l1;
    a.pb(p);
  l1:;
  }
  return a;
}

lli solve1(ci const&) {
  return 2;
}

lli solve2(ci const& a, ci const& b) {
  return a.dinter(b)?4:3;
}

lli solve3(ci* cs) {
  FOR(i,3) {
    if(!cs[i].inter(cs[(i+1)%3]) && !cs[i].inter(cs[(i+2)%3])) {
      return 1+solve2(cs[(i+1)%3], cs[(i+2)%3]);
    }
  }
  lli ans = 4;
  auto v1 = cs[0].inters(cs[1]);
  auto v2 = mer(cs[2].inters(cs[0]), cs[2].inters(cs[1]));
  ans += v1.size() + v2.size()-2;
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  ci cs[3];
  FOR(i,n) cs[i].re();
  if(n == 1) cout << solve1(cs[0]) << endl;
  else if(n == 2) cout << solve2(cs[0],cs[1]) << endl;
  else{
    cout << solve3(cs) << endl;
  }
  return 0;
}