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

using M = vector<vector<lli>>;
const lli infty = (1ll<<60);

M zero(int sz) {
  M a(sz,vi(sz));
  FOR(i,sz) FOR(j,sz) a[i][j]=infty;
  return a;
}

M iden(int sz){
  M a = zero(sz);
  FOR(i,sz) a[i][i]=0;
  return a;
}

M mult(M a, M b) {
  M c = zero(a.size());
  FOR(i,a.size()) FOR(k,a.size()) if(a[i][k]<infty) FOR(j,a.size()) {
    c[i][j] = min(c[i][j], a[i][k]+b[k][j]);
  }
  return c;
}

vi multV(M a, vi b) {
  vi c(b.size(),infty);
  FOR(i,b.size()) {
    FOR(j,b.size()) c[i] = min(c[i],b[j]+a[j][i]);
  }
  return c;
}

M fexp(M a, lli b) {
  M r = iden(a.size());
  while(b){
    if(b&1) r = mult(r,a);
    a = mult(a,a);
    b /= 2;
  }
  return r;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli x,k,n,q; cin>>x>>k>>n>>q;
  vi C(k); FOR(i,k) cin>>C[i];

  vi states;
  vi iSts(1<<k,-1);
  FOR(i,1<<k) if(__builtin_popcount(i) == x) { iSts[i] = states.size(); states.pb(i); }

  vi S(states.size(), infty);
  S[iSts[(1<<x)-1]] = 0;
  int cur = 1;

  map<lli,lli> Q;
  FOR(q_,q) {
    lli p,w; cin>>p>>w;
    Q[p] = w;
  };

  M mat(states.size(),vi(states.size(),infty));
  FOR(m1_, states.size()) {
    int m1 = states[m1_];
    if(m1&1) {
      FOR(i,k) {
        int m2 = m1/2;
        if(m2&(1<<i)) continue;
        m2 |= (1<<i);
        mat[m1_][iSts[m2]] = min(mat[m1_][iSts[m2]], C[i]);
      }
    }else{
      mat[m1_][iSts[m1/2]] = min(mat[m1_][iSts[m1/2]], 0ll);
    }
  }

  auto adv = [&](){
    cur += 1;
    auto T = S; fill(all(T),infty);
    FOR(m1_, states.size()) {
      int m1 = states[m1_];
      lli co0 = S[m1_];
      if(m1&1) {
        FOR(i,k) {
          int m2 = m1/2;
          if(m2&(1<<i)) continue;
          m2 |= (1<<i);
          lli co = co0 + C[i];
          if(Q.count(cur+i)) co += Q[cur+i];
          T[iSts[m2]] = min(T[iSts[m2]], co);
        }
      }else{
        T[iSts[m1/2]] = min(T[iSts[m1/2]], co0);
      }
    }
    S = T;
  };

  for(auto const& q : Q) {
    lli p = q.first;
    if(cur+k < p) { S = multV(fexp(mat,p-(cur+k)),S); cur = p-k; }
    while(cur<p && cur+x-1<n) adv();
  }

  if(cur+x-1 < n) { S = multV(fexp(mat,n-(cur+x-1)),S); cur = n-(x-1); }

  cout << S[iSts[(1<<x)-1]] << endl;

  return 0;
}