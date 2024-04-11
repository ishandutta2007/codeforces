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

// --- BEGIN SNIPPET MODULAR ---

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

struct Zn {
  lli x;
  Zn(lli x_) : x(x_) {
    x %= MOD;
    if(x<0) x = (x+MOD)%MOD;
  }

  Zn operator+(Zn const& o) const { return Zn(x+o.x); }
  Zn operator-(Zn const& o) const { return Zn(x-o.x); }
  Zn operator*(Zn const& o) const { return Zn(x*o.x); }

  Zn& operator+=(Zn const& o) { return *this = *this+o; }
  Zn& operator-=(Zn const& o) { return *this = *this-o; }
  Zn& operator*=(Zn const& o) { return *this = *this*o; }
};

pii egcd(lli a, lli b) {
  if(a%b==0) {
    return mt(0,1);
  }else{
    pii p = egcd(b,a%b);
    int u=p.x(), v=p.y();
    return mt(v, u-(a/b)*v);
  }
}

// solve x*a = b [mod m]
int solveInv(lli a, lli b, lli m) {
  if(b==0) return 0;
  pii p = egcd(a,m);
  lli g=__gcd(m,a);
  return (((b/g)*p.x())%m+m)%m;
}

// --- END SNIPPET MODULAR ---


// --- BEGIN SNIPPET NTT ---

// G = (primitive root ^ (1<<23))
template<lli MOD = 119*(1<<23) + 1, lli G = 15311432>
struct NTT {
  void ntt(vector<lli>& a, lli h){
    lli N = a.size();
    for(lli m = N; m >= 2; m /= 2){
      lli mh = m/2, w = 1;
      FOR(i, mh){
        for(lli j = i; j < N; j += m){
          lli k = j+mh;
          lli x = (a[j]-a[k]);
          a[j] += a[k];
          if(a[j] >= MOD) a[j] -= MOD;
          a[k] = (w*x) % MOD;
          if(a[k] < 0) a[k] += MOD;
        }
        w = (w*h) % MOD;
      }
      h = (h*h) % MOD;
    }
    lli i = 0;
    FORU(j, 1, N-2){
      for(lli k = N/2; k > (i^=k); k/=2);
      if(j<i) swap(a[i],a[j]);
    }
  }

  vector<lli> mult(vector<lli> a, vector<lli> b) {
    lli n = a.size() + b.size();
    lli N = 1;
    while(N < n) N *= 2;
    a.resize(N); b.resize(N);
    assert((MOD-1)%N==0);
    lli h=fexp(G, (MOD-1)/N, MOD);
    ntt(a,h); ntt(b,h);
    FOR(i,N) (a[i] *= b[i]) %= MOD;
    h = invmod(h,MOD);
    ntt(a,h);
    h = invmod(N,MOD);
    FOR(i,N) (a[i] *= h) %= MOD;
    while(!a.empty() && a.back() == 0) a.pop_back();
    return a;
  }
};

// --- END SNIPPET NTT ---

//           (1 1/2 1/3)
// P_{i+1} = (0 1/2 1/3) * P_i
//           (0 0   1/3)

//     (1 1 1)                  (1 -1 1)
// Q = (0 1 2) * D(1 1/2 1/3) * (0 1 -2)
//     (0 0 1)                  (0 0  1)

// (1 -2 1)
// (0 0 1)

// a_i = sum_{k=i..n} (-1)^(k-i) * choose(k,k-i) * b_k
// a_i = sum_{k=i..n} (-1)^(k-i) * k! / i! / (k-i)! * b_k

const int N = 1e5+1;
lli fact[N+1], ifact[N+1];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1; FOR(i,N) fact[i+1] = (fact[i]*(i+1))%MOD;
  ifact[N] = invmod(fact[N]);
  FORD(i,N-1,0) ifact[i] = (ifact[i+1]*(i+1))%MOD;

  lli n,m; cin>>n>>m;
  vi P(n+1); FOR(i,n+1) cin>>P[i];
  FOR(i,n+1) P[i] = (P[i]*fact[i]) % MOD;

  reverse(all(P));
  vi Q1(n+1);
  FOR(i,n+1) Q1[i] = ifact[i];

  auto P1 = NTT<>().mult(P,Q1);
  P1.resize(n+1);
  reverse(all(P1));
  FOR(i,n+1) P1[i] = nmod(P1[i] * ifact[i]);

  FOR(i,n+1) P1[i] = (P1[i] * fexp(invmod(i+1),m))%MOD;

  FOR(i,n+1) P1[i] = nmod(P1[i] * fact[i]);
  reverse(all(P1));
  FOR(i,n+1) Q1[i] = nmod(((i&1)?-1:1) * ifact[i]);

  P = NTT<>().mult(P1,Q1);
  P.resize(n+1);
  reverse(all(P));

  FOR(i,n+1) P[i] = nmod(P[i] * ifact[i]);

  FOR(i,n+1) cout << P[i] << ' ';
  cout << endl;

  return 0;
}