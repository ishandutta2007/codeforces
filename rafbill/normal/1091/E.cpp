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

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n; cin>>n;
  vi D(n);
  FOR(i,n) cin>>D[i];
  sort(all(D));
  reverse(all(D));
  vi S(n+1);
  FOR(i,n) S[i+1] = S[i]+D[i];

  lli p = 0;
  FOR(i,n) p = (p+D[i])%2;

  vi vm0(n+1);
  vi vm1(n+1);

  { multiset<lli> ubD;
    lli subD = 0;
    lli nubD = 0;

    FORD(k,n,0) {
      while(!ubD.empty() && *ubD.rbegin() > k+1) {
        nubD += 1;
        subD -= *ubD.rbegin();
        ubD.erase(ubD.find(*ubD.rbegin()));
      }
      vm0[k] = k*(k+1) + subD + (k+1)*nubD;
      if(k) {
        ubD.insert(D[k-1]);
        subD += D[k-1];
      }
    }
  }

  { multiset<lli> ubD;
    lli subD = 0;
    lli nubD = 0;

    FORD(k,n,0) {
      while(!ubD.empty() && *ubD.rbegin() > k) {
        nubD += 1;
        subD -= *ubD.rbegin();
        ubD.erase(ubD.find(*ubD.rbegin()));
      }
      vm1[k] = k*(k-1) + subD + k*nubD;
      if(k) {
        ubD.insert(D[k-1]);
        subD += D[k-1];
      }
    }
  }

  vi lbs(n+1, 0), ubs(n+1, n);
  { lli a = n;
    FORD(k,n+1,1) {
      a = min(a, vm0[k-1] - S[k-1]);
      ubs[k-1] = a;
    }
  }

  { lli a = 0;
    FORU(k,1,n) {
      if(k < S[k] - vm1[k]) {
        a = n+1;
      }else{
        a = max(a, S[k]-vm1[k]);
      }
      lbs[k] = a;
    }
  }

  // cout << vm0 << endl;
  // cout << vm1 << endl;

  set<lli> OK;

  FORU(k,0,n) {
    // lli lb = 0, ub = n;
    // FORU(k2,1,n+1) {
    //   if(k2 > k) {
    //     // S[k2-1] + d <= k2*(k2-1) + vm[k2];
    //     // d <= k2*(k2-1) + vm[k2] - S[k2-1];
    //     ub = min(ub, vm0[k2-1] - S[k2-1]);
    //   } else {
    //     // S[k2] <= k2*(k2-1) + vm[k2+1] + min(k2, d);
    //     // min(k2, d) >= S[k2] - k2*(k2-1) - vm[k2+1];
    //     if(k2 < S[k2] - vm1[k2]) {
    //       lb = n+1;
    //     } else {
    //       lb = max(lb, S[k2] - vm1[k2]);
    //     }
    //   }
    // }

    // if(k != n) lb = max(lb, D[k]+1);
    // if((lb^p)&1) lb += 1;
    // if(k) ub = min(ub, D[k-1]);
    // if((ub^p)&1) ub -= 1;

    if(k != n) lbs[k] = max(lbs[k], D[k]+1);
    if((lbs[k]^p)&1) lbs[k] += 1;
    if(k) ubs[k] = min(ubs[k], D[k-1]);
    if((ubs[k]^p)&1) ubs[k] -= 1;

    // cout << mt(lb,ub) << " " << mt(lbs[k],ubs[k]) << endl;
    // assert(mt(lb,ub) == mt(lbs[k],ubs[k]));

    while(lbs[k] <= ubs[k]) {
      OK.insert(lbs[k]);
      lbs[k] += 2;
    }
  }

  if(OK.empty()) cout << -1 << endl;
  else {
    for(auto x : OK) cout << x << ' ';
    cout << endl;
  }

  return 0;
}