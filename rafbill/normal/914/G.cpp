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

const lli MOD = 1e9+7;

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

// --- BEGIN SNIPPET FWHT ---

void fwht(lli *data, int dim) {
  for (int len = 1; 2 * len <= dim; len <<= 1) {
    for (int i = 0; i < dim; i += 2 * len) {
      for (int j = 0; j < len; j++) {
        lli a = data[i + j];
        lli b = data[i + j + len];
        data[i + j] = (a + b) % MOD;
        data[i + j + len] = (MOD + a - b) % MOD;
      }
    }
  }
}


// void fwht(lli *data, int dim) {
//   for(int len = 1; 2 * len <= dim; len <<= 1) {
//     for(int i = 0; i < dim; i += 2 * len) {
//       for(int j = 0; j < len; j++) {
//         lli a = data[i + j];
//         lli b = data[i + j + len];
//         data[i + j] = (a + b) % MOD;
//         data[i + j + len] = (MOD + a - b) % MOD;
//       }
//     }
//   }
// }


void transform_and(int size, lli *P, bool inv) {
  for(int len = 1; 2 * len <= size; len <<= 1) {
    for(int i = 0; i < size; i += 2 * len) {
      for(int j = 0; j < len; j++) {
        lli u = P[i + j];
        lli v = P[i + len + j];

        if (!inv) {
          P[i + j] = v;
          P[i + len + j] = (u + v) % MOD;
        } else {
          P[i + j] = (v-u+MOD) % MOD;
          P[i + len + j] = u;
        }
      }
    }
  }
}

// --- END SNIPPET FWHT ---


const int N = 17;

lli fib[(1<<N)+10];

lli tmp1[1<<N], tmp2[1<<N], tmp3[1<<N];

lli a[1<<N];
lli a1[1<<N];
lli a2[1<<N];
lli a3[1<<N];

lli b1[1<<N];
lli b2[1<<N];
lli b3[1<<N];

lli a123[1<<N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  fib[0] = 0; fib[1] = 1;
  FOR(i,1<<N) fib[2+i] = (fib[i]+fib[1+i])%MOD;

  // FOR(i,1<<N) fib[i] = 1;

  int nn; cin>>nn;
  vi s(nn);
  FOR(i,nn) {
    int x; cin>>x; a[x] += 1;
    s[i] = x;
  }

  // for(auto a : s) for(auto b : s) if((a&b)==0) r1[a|b]++;
  // for(auto a : s) r2[a]++;
  // for(auto a : s) for(auto b : s) r3[a^b]++;

  // a1
  // FOR(i,1<<N) tmp1[i] = a[i];
  // FOR(i,1<<N) if(i<((~i)&((1<<N)-1))) swap(tmp1[i],tmp1[(~i)&((1<<N)-1)]);
  // transform_and(1<<N, tmp1, 0);
  // FOR(i,1<<N) tmp1[i] = (tmp1[i]*tmp1[i]) % MOD;
  // transform_and(1<<N, tmp1, 1);
  // FOR(i,1<<N) if(i<((~i)&((1<<N)-1))) swap(tmp1[i],tmp1[(~i)&((1<<N)-1)]);
  for (int mask = 0; mask < (1<<N); mask++){
    for(int i = mask; i > 0; i = (i-1) & mask){
      (a1[mask] += a[i]*a[mask^i]) %= MOD;
    }
    (a1[mask] += a[0] * a[mask]) %= MOD;
  }
  FOR(i,1<<N) a1[i] = (a1[i] * fib[i]) % MOD;
  // a2
  FOR(i,1<<N) a2[i] = (a[i] * fib[i]) % MOD;
  // a3

  FOR(i,1<<N) tmp1[i] = a[i];
  fwht(tmp1, 1<<N);
  FOR(i,1<<N) tmp1[i] = (tmp1[i]*tmp1[i]) % MOD;
  fwht(tmp1, 1<<N);
  lli im = invmod(1<<N);
  FOR(i,1<<N) a3[i] = (tmp1[i] * fib[i] % MOD * im) % MOD;

  // cout << "a, a1, a2, a3" << endl;
  // FOR(i,1<<N) cout << a[i] << ' '; cout << endl;
  // FOR(i,1<<N) cout << a1[i] << ' '; cout << endl;
  // FOR(i,1<<N) cout << a2[i] << ' '; cout << endl;
  // FOR(i,1<<N) cout << a3[i] << ' '; cout << endl;
  // FOR(i,1<<N) cout << r1[i] << ' '; cout << endl;
  // FOR(i,1<<N) cout << r2[i] << ' '; cout << endl;
  // FOR(i,1<<N) cout << r3[i] << ' '; cout << endl;


  // b1,b2,b3
  FOR(i,1<<N) b1[i] = a1[i];
  FOR(i,1<<N) b2[i] = a2[i];
  FOR(i,1<<N) b3[i] = a3[i];
  transform_and(1<<N, b1, 0);
  transform_and(1<<N, b2, 0);
  transform_and(1<<N, b3, 0);
  FOR(i,1<<N) a123[i] = (b1[i]*b2[i]%MOD*b3[i]%MOD);
  transform_and(1<<N, a123, 1);

  // cout << "sol" << endl;
  // for(lli a : s) for(lli b : s) for(lli c : s) for(lli d : s) for(lli e : s) r123[(a|b)&c&(d^e)] += 1;

  // FOR(i,1<<N) cout << a123[i] << ' '; cout << endl;
  // FOR(i,1<<N) cout << r123[i] << ' '; cout << endl;

  lli ans = 0;
  FOR(i,N) (ans += a123[1<<i]) %= MOD;
  cout << ans << endl;
  return 0;
}