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

// --- BEGIN SNIPPET BINARY INDEXED TREE ---

struct BIT {
  vi A;
  BIT(lli n) : A(n+1){ }

  lli get(lli i){
    i += 1;
    lli r = 0;
    for(; i > 0; i -= i &-i){
      r += A[i];
    }
    return r;
  }

  lli getR(lli l, lli r) {
    lli ans = get(r);
    if(l) ans -= get(l-1);
    return ans;
  }

  void add(lli i, lli v){
    i += 1;
    for(; i < (lli)A.size(); i += i & -i){
      A[i] += v;
    }
  }
};

// --- END SNIPPET BINARY INDEXED TREE ---


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n,d,b; cin>>n>>d>>b;
  vi A(n);
  FOR(i,n) cin>>A[i];
  lli okL=0,okR=0;

  lli l=0,r=n-1;
  lli ansa = 0, ansb = 0;

  FOR(step,n/2) {
    lli lto = step + (step+1)*d;
    lli rto = n-1-step - (step+1)*d;
    while(okL < b) {
      if(l == n) break;
      if(A[l] == 0) { l += 1; continue; }
      if(l > lto) break;
      lli v = min(b-okL,A[l]);
      okL += v; A[l] -= v;
    }
    if(okL == b) {
      okL = 0;
    }else{
      ansa += 1;
    }

    while(okR < b) {
      if(r == -1) break;
      if(A[r] == 0) { r -= 1; continue; }
      if(r < rto) break;
      lli v = min(b-okR,A[r]);
      okR += v; A[r] -= v;
    }
    if(okR == b) {
      okR = 0;
    }else{
      ansb += 1;
    }
  }
  cout << max(ansa,ansb) << endl;

  // auto solve = [&](vi A, lli tot, lli ncell){
  //   lli cur = 0;
  //   vi B(n);
  //   FOR(i,n) {
  //     lli v = min(tot-cur,A[i]);
  //     cur += v;
  //     B[i] = v;
  //   }
  //   vi S(n+1);
  //   FOR(i,n) S[i+1] = S[i]+B[i];
  //   vi C(n);
  //   lli last = 0;
  //   FOR(i,n) {
  //     lli nx = min(n,i+(i+1)*d+1);
  //     C[i] = S[nx] - S[last];
  //     last = nx;
  //   }
  //   lli ans = 0;
  //   FOR(i,ncell) {
  //     if(C[i] < b) {
  //       ans++;
  //     }else{
  //       C[i] -= b;
  //     }
  //     C[i+1] += C[i];
  //   }
  //   return ans;
  // };
  // lli ans = 0;
  // ans += solve(A,((n+1)/2)*b,(n+1)/2);
  // reverse(all(A));
  // ans += solve(A,(n/2)*b,n/2);
  // cout << ans << endl;
  return 0;
}