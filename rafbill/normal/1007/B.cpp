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

const int N = 2e5;
bool sieve[N+1];
lli ndiv[N+1];

lli brute(array<lli,3> A) {
  sort(all(A));
  lli n = A[2];
  lli cnt=0;
  FORU(a,1,n) FORU(b,a,n) FORU(c,b,n) {
    vi B = {a,b,c};
    vi I(3); iota(all(I),0);
    bool lok = 0;
    do {
      bool ok = 1;
      FOR(i,3) if(A[i]%B[I[i]] != 0) ok = 0;
      if(ok) lok=1;
    } while(next_permutation(all(I)));
    if(lok) {
      cnt++;
    }
  }
  return cnt;
}

lli nok3[8][8][8];

lli solve(array<lli,3> a) {
  lli pre[8];
  FORD(m,7,1) {
    lli g = 0;
    FOR(i,3) if(m&(1<<i)) {
      if(g==0) g = a[i];
      else g = __gcd(g,a[i]);
    }
    pre[m] = ndiv[g];
    FORD(mm,7,m+1) if((mm&m) == m) pre[m] -= pre[mm];
  }
  lli cnts[7];
  FOR(i,7) cnts[i] = 0;

  FORU(xa,1,7) if(xa&(1<<0))
    FORU(xb,1,7) if(xb&(1<<1))
      FORU(xc,1,7) if(xc&(1<<2)) {
        lli cur = pre[xa]*(pre[xb] - (xa==xb)) * (pre[xc] - (xa==xc) - (xb==xc));
        // vi I(3); iota(all(I),0);
        // lli nok = 0;
        // do {
        //   array<lli,3> A = {xa,xb,xc};
        //   array<lli,3> B;
        //   FOR(i,3) B[i] = A[I[i]];
        //   bool cok=1;
        //   FOR(i,3) if(!(B[i]&(1<<i))) cok=0;
        //   if(cok) {
        //     nok++;
        //   }
        // } while(next_permutation(all(I)));
        cnts[nok3[xa][xb][xc]] += cur;
      }

  auto test2 = [&](int x, int y, int z) {
    FORU(xab,1,7) if((xab&(1<<x)) && (xab&(1<<y)))
      FORU(xc,1,7) if(xc&(1<<z)) {
        lli cur = pre[xab]*(pre[xc] - (xab==xc));
        lli nok = 0;
        if((xab & ((1<<0)|(1<<1))) == ((1<<0)|(1<<1)) && (xc & (1<<2))) nok++;
        if((xab & ((1<<2)|(1<<0))) == ((1<<2)|(1<<0)) && (xc & (1<<1))) nok++;
        if((xab & ((1<<2)|(1<<1))) == ((1<<2)|(1<<1)) && (xc & (1<<0))) nok++;
        cnts[nok] += cur;
      }
  };
  test2(0,1,2);
  test2(0,2,1);
  test2(1,2,0);
  cnts[1] += pre[7];

  lli ans=0;
  FORU(i,1,6) {
    assert(cnts[i]%i==0);
    ans += cnts[i]/i;
  }
  return ans;
}

int main(){
  FORU(i,1,N) ndiv[i] = 1;
  FORU(i,2,N) sieve[i] = 1;
  FORU(i,2,N) if(sieve[i]) {
    for(int k = 2; k*i <= N; ++k) sieve[k*i] = 0;
    for(lli p = i, c = 1; p <= N; p *= i, c += 1) {
      for(int k = 1; k*p <= N; ++k) {
        ndiv[k*p] /= c;
        ndiv[k*p] *= (c+1);
      }
    }
  }

  FORU(xa,1,7) if(xa&(1<<0))
    FORU(xb,1,7) if(xb&(1<<1))
      FORU(xc,1,7) if(xc&(1<<2)) {
        vi I(3); iota(all(I),0);
        nok3[xa][xb][xc] = 0;
        do {
          array<lli,3> A = {xa,xb,xc};
          array<lli,3> B;
          FOR(i,3) B[i] = A[I[i]];
          bool cok=1;
          FOR(i,3) if(!(B[i]&(1<<i))) cok=0;
          if(cok) {
            nok3[xa][xb][xc]++;
          }
        } while(next_permutation(all(I)));
      }


  ios::sync_with_stdio(0); cin.tie(0);
  lli t; cin>>t;
  FOR(t_,t) {
    lli a,b,c;
    cin>>a>>b>>c;
    // a=rand()%(100000)+1;
    // b=rand()%(100000)+1;
    // c=rand()%(100000)+1;
    cout << solve({a,b,c}) << endl;
  }
  return 0;
}