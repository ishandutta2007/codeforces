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

struct fn {
  fn() : a(0), b(-(1ll<<60)) { }
  fn(long double a_, long double b_) : a(a_), b(b_) { }
  long double a, b;

  long double operator()(long double x) const {
    return a*(long double)x + b; }
  };

struct LiChao {
  lli lo, hi, mi;
  fn f;
  LiChao *l, *r;

  LiChao(lli lo_, lli hi_, fn f_) : lo(lo_), hi(hi_), f(f_) {
    mi = lo+(hi-lo)/2;
    l = r = 0;
  }

  LiChao& left() {
    if(!l) l = new LiChao(lo, mi, fn());
    return *l;
  }

  LiChao& right() {
    if(!r) r = new LiChao(mi+1, hi, fn());
    return *r;
  }

  void add(fn g) {
    auto fl = f(lo), fr = f(hi);
    auto gl = g(lo), gr = g(hi);
    if(fl >= gl && fr >= gr) return; // Always worse
    if(fl < gl && fr < gr) { f = g; return; } // Always better
    if(fl < gl) swap(f, g); // Trick to know if the intersection is before/after mi
    if(f(mi) > g(mi)) right().add(g);
    else { swap(f,g); left().add(g); }
  }

  pii qu(lli x) {
    pii cur = mt(f(x),-f.a); // mt(f(x),f.a);
    if(lo == hi) return cur;
    if(x > mi) { return r?max(cur,right().qu(x)):cur; }
    else { return l?max(cur,left().qu(x)):cur; }
  }
};


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n,m; cin>>n>>m;

  lli totalSize = n;
  LiChao HD(-(lli)(1ll<<60),(lli)(1ll<<60),fn());
  // HullDynamic HD;
  HD.add(fn(0,0));
  // HD.insert_line(0,0);
  lli b = 0, s = 0;

  auto print = [&](){
    lli i; lli l;
    tie(l,i) = HD.qu(-s);
    cout << (-i)+1 << " " << b-l << endl;
  };

  FOR(q_,m) {
    int ty; cin>>ty;
    if(ty == 1) {
      lli k; cin>>k;
      totalSize += k;
      b=0; s=0;
      HD = LiChao(-(lli)(1ll<<60),(lli)(1ll<<60),fn());
      HD.add(fn(0,0));
    } else if(ty == 2) {
      lli k; cin>>k;
      HD.add(fn(totalSize, b+totalSize*s));
      totalSize += k;
    } else {
      lli b_,s_; cin>>b_>>s_;
      b+=b_;
      s+=s_;
    }
    print();
  }
  return 0;
}