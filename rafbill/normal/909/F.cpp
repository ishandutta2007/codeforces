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

void print(vi I) {
  if(I.empty()) {
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    for(int i : I) cout << i << ' ';
    cout << endl;
  }
}

map<int,vi> ANS;

vi solvep(int n) {
  if(n <= 8) {
    vi I(n); iota(all(I),1);
    do {
      bool ok = 1;
      FOR(i,n) if(I[i] == i+1 || ((i+1)&I[i]) != 0) ok = 0;
      if(ok) return I;
    } while(next_permutation(all(I)));
    return vi();
  }
  if(n&1) return vi();
  if(ANS.count(n)) return ANS[n];
  int j = 0; while((1<<(j+1)) < n) j++;
  vi R(n); iota(all(R),1);
  int sz = 1<<j;
  vi I = solvep(sz);
  vi J = solvep(n-sz);
  FOR(i,sz) R[i] = I[i];
  FOR(i,n-sz) R[sz+i] = sz+J[i];
  vi RR(n+1); FOR(i,n) RR[R[i]] = i;
  FOR(i,n-sz) {
    swap(R[RR[i+1]], R[RR[sz+i+1]]);
  }
  if(n==((1<<(j+1)))) swap(R[sz-2],R[n-2]);
  if(n==((1<<(j+1)))) swap(R[sz-1],R[n-1]);
  ANS[n] = R;
  return R;
}

vi solveq(int n) {
  if(n <= 10) {
    vi I(n); iota(all(I),1);
    do {
      bool ok = 1;
      FOR(i,n) if(I[i] == i+1 || ((i+1)&I[i]) == 0) ok = 0;
      if(ok) return I;
    } while(next_permutation(all(I)));
    return vi();
  }
  vvi A(20);
  FORU(i,1,n) {
    FOR(j,20) if(i&(1<<j)) A[j].pb(i);
  }
  while(A.back().empty()) A.pop_back();
  int m = A.size();
  sort(all(A), [&](auto const& a, auto const& b) { return a.size() > b.size(); });
  FOR(j,m) sort(all(A[j]), [&](int a, int b) { return __builtin_popcount(a) < __builtin_popcount(b); });
  vi E(n+1,0);
  vvi B(m);
  FOR(j,m) {
    int r = 2;
    for(int i : A[j]) {
      if(!E[i]) {
        E[i] = 1;
        B[j].pb(i);
        --r;
        if(r == 0) break;
      }
    }
    if(r != 0) return vi();
  }
  FOR(j,m) for(int i : A[j]) if(!E[i]) { B[j].pb(i); E[i] = 1; }
  vi ANS(n);
  FOR(j,m) FOR(i,B[j].size()) { ANS[B[j][i]-1] = B[j][(i+1)%B[j].size()]; }
  return ANS;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  // print(solvep(8));
  // print(solvep(10));
  // FORU(i,11,333) {
  //   cout << i << endl;
  //   if(!solvep(i).empty()) cout << i << endl;
  // }
   int n; cin>>n;
   vi A = solvep(n);
   vi B = solveq(n);
   print(A);
   print(B);
  return 0;
}