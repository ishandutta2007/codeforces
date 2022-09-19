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

// --- BEGIN SNIPPET PRIMES ---

const lli MAXPRIME = 1e7+16;
lli divs[MAXPRIME+1];
bool sieve[MAXPRIME+1];
lli mo[MAXPRIME+1];

void calcPrimes(){
  FORU(i, 2, MAXPRIME) sieve[i]=1;
  FORU(i, 1, MAXPRIME) mo[i]=1;
  FORU(i, 1, MAXPRIME) divs[i]=-1;
  FORU(i, 2, MAXPRIME) if(sieve[i]) {
    mo[i]=-1; divs[i] = i;
    lli k=2;
    while(i*k<=MAXPRIME) { if(divs[i*k]==-1) divs[i*k] = i; sieve[i*k] = 0; mo[i*k]*=-1; if(k%i==0) mo[i*k]=0; k += 1; }
  }
}

// --- END SNIPPET PRIMES ---

map<lli,lli> brute(lli n) {
  map<lli,lli> R;
  vvi G(n+1);
  FORU(i,1,n) FORU(j,1,n) if(__gcd(i,j) != 1) G[i].pb(j);
  FORU(i,1,n) {
    vi E(n+1,0);
    vi D(n+1,1e10);
    deque<lli> Q; D[i]=0; Q.push_back(i); E[i]=1;
    while(!Q.empty()) {
      int j = Q.front(); Q.pop_front();
      for(int k : G[j]) if(!E[k]) {
          E[k] = 1;
          D[k] = D[j]+1;
          Q.push_back(k);
        }
    }
    FORU(j,i+1,n) R[D[j]]++;
  }
  return R;
}

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
  calcPrimes();
  lli n; cin>>n;

  lli anstot = 0;
  FORU(i,2,n) if(!sieve[i] || i <= n/2) anstot += 1;
  anstot = (anstot*(anstot-1))/2;

  lli ans1 = 0, ans2= 0;
  FORU(i,2,n) {
    lli x = n/i;
    lli y = (x*(x-1))/2;
    ans1 += -mo[i]*y;
  }

  vi V(n+1);
  FORU(i,2,n) {
    V[divs[i]]++;
  }
  BIT bit(n+10);
  FORD(i,n,2) if(sieve[i]) {
    ans2 += V[i]*bit.get(n/i);
    ans2 += (V[i]*(V[i]-1))/2;
    bit.add(i,V[i]);
  }
  ans2 -= ans1;


  lli ans3 = anstot-ans1-ans2;

  cout << ans1+2*ans2+3*ans3 << endl;

  // cout << mt(ans1,ans2,ans3) << endl;
  // cout << brute(n) << endl;

  // lli ans2 = 0;
  // FORU(i,1,n) {
  //   if(i*i>n) break;
  //   if(sieve[i]) {
  //     FORU(j,i+1,n) {
  //       if(i*j>n) break;
  //       if(sieve[j]) {
  //         ans2 += cnt1[i] * cnt1[j];
  //         cout << mt(i,j) << endl;
  //       }
  //     }
  //   }
  // }
  // // FORU(i,1,n) if(sieve[i]) {
  // //   lli nq = min(i-1,n/i);
  // //   cout << i << " " << cnt0[nq] << " " << cnt1[i] << " " << (n/i)-cnt1[i] << endl;
  // //   ans2 += (cnt0[nq] - ((n/i)-cnt1[i])) * cnt1[i];
  // // }
  // cout << ans2 << endl;



  return 0;
}