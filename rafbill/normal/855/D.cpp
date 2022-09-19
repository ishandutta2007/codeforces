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

const lli N=2e5;
const lli LN=20;
lli TY[LN][N];
lli parent[LN][N];
lli depth[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n; cin>>n;
  parent[0][0]=-1; TY[0][0]=-1; depth[0]=0;
  FORU(i,0,n-1) {
    lli p,ty;

    cin>>p>>ty; --p;


    if(i) {
      // p=rand()%i;
      // ty = rand()%2;

      depth[i]=depth[p]+1;
      parent[0][i]=p;
      TY[0][i] = ty;
    }
  }

  FOR(i,LN-1) FOR(j,n) {
    if(parent[i][j] != -1) {
      parent[i+1][j] = parent[i][parent[i][j]];
      if(TY[i][parent[i][j]] == TY[i][j]) TY[i+1][j] = TY[i][j];
      else TY[i+1][j]=-1;
    }
    else parent[i+1][j] = TY[i+1][j] = -1;
  }

  function<lli(lli,lli)> lca = [&](lli i, lli j) {
    if(depth[i]<depth[j]) swap(i,j);
    FORD(k,LN-1,0) if(depth[i]-(1ll<<k) >= depth[j]) {
      i = parent[k][i];
    }
    if(i==j) return i;
    FORD(k,LN-1,0) if(depth[i]>=(1<<k)) {
      if(parent[k][i] != parent[k][j]) {
        i=parent[k][i];
        j=parent[k][j];
      }
    }
    return parent[0][i];
  };

  function<bool(lli,lli,lli)> check = [&](lli i, lli j, lli ty) {
    if(i==j) return false;
    if(j != lca(i,j)) return false;
    FORD(k,LN-1,0) if(depth[i]-(1<<k) >= depth[j]) {
      if(ty != TY[k][i]) ty = -1;
      i=parent[k][i];
    }
    assert(i == j);
    return ty != -1;
  };

  lli q; cin>>q;
  FOR(q_,q) {
    lli ty,u,v;

    cin>>ty>>u>>v; --u; --v;

    // ty = 1+rand()%2;
    // u=rand()%n;
    // v=rand()%n;

    if(ty == 1) {
      cout << (check(v,u,0)?"YES":"NO") << '\n';
    }else{
      lli l=lca(u,v);
      cout << (((u==l||check(u,l,0))&&check(v,l,1))?"YES":"NO") << '\n';
    }
  }
  cout << flush;

  return 0;
}