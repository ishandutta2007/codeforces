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

int dec(char c) {
  if(c=='A') return 0;
  if(c=='G') return 1;
  if(c=='T') return 2;
  if(c=='C') return 3;
  assert(0);
}

char enc(int i) {
  return "AGTC"[i];
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m; cin>>n>>m;
  vector<vector<char>> A(n,vector<char>(m));
  FOR(i,n) FOR(j,m) {
    char c;
    cin>>c;
    A[i][j]=dec(c);
    //   A[i][j] = rand()%4;
  }
  vector<char> I = {0,1,2,3};
  vector<vector<char>> B;
  lli ans = 1e9;
  do {
    if(I[0]<I[1] && I[2]<I[3]) {
      { lli cost = 0;
        vector<vector<char>> C(n,vector<char>(m));
        FOR(i,n) {
          int c0=0,c1=0;
          FOR(j,m) {
            if(A[i][j] != I[2*(i&1)+(j&1)]) c0++;
            if(A[i][j] != I[2*(i&1)+((j^1)&1)]) c1++;
          }
          cost += min(c0,c1);
          if(c0<c1) {
            FOR(j,m) C[i][j] = I[2*(i&1)+(j&1)];
          } else {
            FOR(j,m) C[i][j] = I[2*(i&1)+((j^1)&1)];
          }
        }
        if(cost<ans) {
          ans=cost;
          B=C;
        }
      }
      { lli cost = 0;
        vector<vector<char>> C(n,vector<char>(m));
        FOR(j,m) {
          int c0=0,c1=0;
          FOR(i,n) {
            if(A[i][j] != I[(i&1)+2*(j&1)]) c0++;
            if(A[i][j] != I[((i^1)&1)+2*(j&1)]) c1++;
          }
          cost += min(c0,c1);
          if(c0<c1) {
            FOR(i,n) C[i][j] = I[(i&1)+2*(j&1)];
          } else {
            FOR(i,n) C[i][j] = I[((i^1)&1)+2*(j&1)];
          }
        }
        if(cost<ans) {
          ans=cost;
          B=C;
        }
      }
    }
  } while(next_permutation(all(I)));
  FOR(i,n) {
    FOR(j,m) cout << enc(B[i][j]);
    cout << endl;
  }
  // cerr << ans << endl;
  return 0;
}