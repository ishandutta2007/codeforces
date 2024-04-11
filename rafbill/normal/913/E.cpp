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

int de[256];
int dt[256];
int df[256];

string se[256];
string st[256];
string sf[256];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  FOR(i,256) de[i]=dt[i]=df[i] = 1<<20;
  { int x=0; FOR(i,8) if(i/4) x |= (1<<i);
    de[x]=dt[x]=df[x]=1; se[x]=st[x]=sf[x]="x";
    int y=0; FOR(i,8) if((i/2)%2) y |= (1<<i);
    de[y]=dt[y]=df[y]=1; se[y]=st[y]=sf[y]="y";
    int z=0; FOR(i,8) if(i%2) z |= (1<<i);
    de[z]=dt[z]=df[z]=1; se[z]=st[z]=sf[z]="z";
  }

  int m = 255;

  FORU(l,2,1000) {
    FOR(a,256) if(2+de[a] == l && l <= df[a]) {
      if(df[a] == l) sf[a] = min("(" + se[a] + ")", sf[a]);
      else sf[a] = "(" + se[a] + ")";
      df[a] = l;
    }
    FOR(a,256) if(1+df[a] == l && l <= df[(~a)&m]) {
      if(df[(~a)&m] == l) sf[(~a)&m] = min(sf[(~a)&m], "!"+sf[a]);
      else sf[(~a)&m] = "!" + sf[a];
      df[(~a)&m] = l;
    }
    FOR(a,256) if(df[a] == l && l <= dt[a]) {
      if(dt[a] == l) st[a] = min(st[a],sf[a]);
      else st[a] = sf[a];
      dt[a] = l;
    }
    FOR(a,256) FOR(b,256) if(dt[a]+df[b]+1 == l && l <= dt[a&b]) {
      if(dt[a&b] == l) st[a&b] = min(st[a&b], st[a] + '&' + sf[b]);
      else st[a&b] = st[a] + '&' + sf[b];
      dt[a&b] = l;
    }
    FOR(a,256) if(dt[a] == l && l <= de[a]) {
      if(de[a] == l) se[a] = min(se[a],st[a]);
      else se[a] = st[a];
      de[a] = l;
    }
    FOR(a,256) FOR(b,256) if(de[a]+dt[b]+1 == l && l <= de[a|b]) {
      if(de[a|b] == l) se[a|b] = min(se[a|b], se[a] + '|' + st[b]);
      else se[a|b] = se[a] + '|' + st[b];
      de[a|b] = l;
    }
  }

  int n; cin>>n;
  FOR(i,n) {
    string s; cin>>s;
    int x = 0; FOR(j,8) if(s[j]=='1') x |= (1<<j);
    cout << se[x] << '\n';
  }
  cout << flush;

  // priority_queue<tpl<int, int, string>> QE, QT, QF;
  // auto addE = [&](tpl<int, int, string> x) {
  //   if(x.x() < de[x.y()]) {
  //     de[x.y()] = x.x();
  //     se[x.y()] = x.z();
  //     QE.push(x);
  //   }
  // };
  // auto addT = [&](tpl<int, int, string> x) {
  //   addE(x);
  //   if(x.x() < dt[x.y()]) {
  //     dt[x.y()] = x.x();
  //     QT.push(x);
  //   }
  // };
  // auto addF = [&](tpl<int, int, string> x) {
  //   addT(x);
  //   if(x.x() < df[x.y()]) {
  //     df[x.y()] = x.x();
  //     QF.push(x);
  //   }
  // };
  // { int x=0; FOR(i,8) if(i/4) x |= (1<<i);
  //   addF(mt(0,x,"x"));
  //   int y=0; FOR(i,8) if((i/2)%2) y |= (1<<i);
  //   addF(mt(0,y,"y"));
  //   int z=0; FOR(i,8) z |= (1<<i);
  //   addF(mt(0,z,"z"));
  // }
  // FOR(l,5000) {
  // }
  return 0;
}