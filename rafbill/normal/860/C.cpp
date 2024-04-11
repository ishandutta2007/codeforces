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

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  int ex = 0;
  unordered_set<string> a0,a1,a;
  FOR(i,n) {
    string s; int ty; cin>>s>>ty;
    if(ty==1) ex += 1;
    if(ty==1) a0.insert(s); else a1.insert(s);
    a.insert(s);
  }
  unordered_set<string> g0,g1,gs;
  FORU(i,1,ex) { g0.insert(to_string(i)); gs.insert(to_string(i)); }
  FORU(i,ex+1,n) { g1.insert(to_string(i)); g1.insert(to_string(i)); }
  int tmp = n+1;
  while(gs.count(to_string(tmp))) tmp+=1;
  unordered_set<string> free0 = g0, free1 = g1;
  for(auto const& s : a) free0.erase(s);
  for(auto const& s : a) free1.erase(s);
  for(auto const& s : g0) a0.erase(s);
  for(auto const& s : g1) a1.erase(s);
  int ans=0;
  ostringstream sans;
  unordered_set<string> ag0,ag1;
  for(auto const& s : a0) if(g1.count(s)) ag0.insert(s);
  for(auto const& s : a1) if(g0.count(s)) ag1.insert(s);
  if((!ag0.empty() || !ag1.empty())) {
    if(free0.empty() && free1.empty()){
      if(!ag0.empty()) {
        auto s = *begin(ag0);
        ag0.erase(s);
        ans++; sans << "move " << s << " " << to_string(tmp) << '\n';
        free1.insert(s);
        a0.erase(s);
        a0.insert(to_string(tmp));
      }else{
        auto s = *begin(ag1);
        ag1.erase(s);
        ans++; sans << "move " << s << " " << to_string(tmp) << '\n';
        free0.insert(s);
        a1.erase(s);
        a1.insert(to_string(tmp));
      }
    }
    while(!ag0.empty() || !ag1.empty()) {
      if(!ag0.empty() && !free0.empty()) {
        auto s = *begin(ag0), t = *begin(free0);
        a0.erase(s); ag0.erase(s); free0.erase(t); free1.insert(s);
        ans++; sans << "move " << s << " " << t << '\n';
      }
      if(!ag1.empty() && !free1.empty()) {
        auto s = *begin(ag1), t = *begin(free1);
        a1.erase(s); ag1.erase(s); free1.erase(t); free0.insert(s);
        ans++; sans << "move " << s << " " << t << '\n';
      }
    }
  }
  while(!a0.empty() || !a1.empty()) {
    if(!a0.empty() && !free0.empty()) {
      auto s = *begin(a0), t = *begin(free0);
      a0.erase(s); free0.erase(t);
      ans++; sans << "move " << s << " " << t << '\n';
    }
    if(!a1.empty() && !free1.empty()) {
      auto s = *begin(a1), t = *begin(free1);
      a1.erase(s); free1.erase(t);
      ans++; sans << "move " << s << " " << t << '\n';
    }
  }
  cout << ans << endl << sans.str() << flush;
  return 0;
}