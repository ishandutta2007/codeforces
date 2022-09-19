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

char A[60][60];

// --- BEGIN SNIPPET UNION FIND ---

struct union_find {
  vi A;
  vvi S;

  union_find(lli n = 0) : A(n), S(n) {
    iota(all(A), 0);
    FOR(i,n) S[i].pb(i);
  }

  lli addNode() {
    A.pb(A.size());
    return A.size()-1;
  }

  lli find(lli a) {
    return A[a] == a ? a : A[a] = find(A[a]);
  }

  void unite(lli a, lli b) {
    a = find(a); b = find(b);
    if(a!=b) {
      A[a] = b;
      S[b].insert(end(S[b]),all(S[a]));
    }
  }
};

// --- END SNIPPET UNION FIND ---

int G[60];

void fail(){
  cout << -1 << endl;
  exit(0);
}

const int MAXM = 23;
const lli MOD = 568093699;
lli P[1<<MAXM];
lli Q[1<<MAXM];
lli Q2[1<<MAXM];

void transform(int size, lli *P, bool inv) {
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

lli transformv0(int size, lli *P) {
  for(int len = 1; 2 * len <= size; len <<= 1) {
    for(int i = 0; i < size; i += 2 * len) {
      lli u = P[i];
      lli v = P[i + len];
      P[i] = (v-u+MOD) % MOD;
      P[i + len] = u;
    }
  }
  return P[0];
}


int main(){
  int n; cin>>n;
  FOR(i,n) FOR(j,n) {
    cin>>A[i][j];
  }
  // int n = 47;
  // FOR(i,n) FOR(j,n) {
  //   if(i==j) A[i][j]='-';
  //   else if((i^1)==j) A[i][j]='A';
  //   else A[i][j] = 'X';
  // }

  union_find uf(n);
  FOR(i,n) FOR(j,i) if(A[i][j] == 'A') uf.unite(i,j);
  vi B;
  lli ans=0;
  FOR(i,n) if(uf.find(i) == i) {
    if(uf.S[i].size() == 1){
      ans += 1;
    }else{
      ans += uf.S[i].size();
      B.pb(i);
    }
  }
  int m = B.size();
  FOR(i,m) for(int j : uf.S[B[i]]) for(int k : uf.S[B[i]]) {
      if(A[j][k] == 'X') fail();
    }
  FOR(i,m) FOR(j,i) {
    G[i] |= (1<<j);
    G[j] |= (1<<i);
    for(int a : uf.S[B[i]]) for(int b : uf.S[B[j]]) if(A[a][b] == 'X') {
          G[i] &= ~(1<<j);
          G[j] &= ~(1<<i);
        }
  }

  if(m == 0) {
    cout << ans-1 << endl;
    return 0;
  }

  function<void(int,int,int)> bt = [&](int i, int mask, int pos) {
    if(i == m) {
      P[(mask)^((1<<m)-1)] = 1;
      return;
    }
    if(pos&(1<<i)) {
      bt(i+1, mask|(1<<i), pos&G[i]);
    }
    bt(i+1, mask, pos);
  };
  bt(0,0,(1<<m)-1);
  FOR(i,1<<m) Q[i] = 1;
  transform(1<<m, P, 0);

  int maxk=0;
  while(1) {
    FOR(i,1<<m) Q2[i] = Q[i];
    // transform(1<<m, Q2, 1);
    if(transformv0(1<<m,Q2)) {
      cout << ans-1+maxk << endl;
      return 0;
    }
    maxk+=1;
    FOR(i,1<<m) Q[i] = (Q[i]*P[i])%MOD;
  }

  return 0;
}