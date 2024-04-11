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

void scc(vvi const& G, vvi& cs, vi& C) {
  int n = G.size();
  vvi G2(n); FOR(i, n) for(int j : G[i]) G2[j].pb(i);
  cs.clear(); C.assign(n, -1);
  vi A;
  vi E(n);
  function<void(int)> dfs = [&](int i) {
    if(E[i]) return;
    E[i] = 1;
    for(int j : G[i]) dfs(j);
    A.pb(i);
  };
  FOR(i, n) dfs(i);
  reverse(all(A));
  function<void(int, int)> dfs2 = [&](int i, int r) {
    if(C[i] == -1) {
      cs.back().pb(i); C[i] = r;
      for(int j : G2[i]) dfs2(j, r);
    }
  };
  for(int i : A) if(C[i] == -1) { cs.pb(vi{}); dfs2(i, cs.size()-1); }
}

struct union_find {
  vi A;

  union_find(lli n = 0) : A(n) {
    iota(all(A), 0);
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
    A[a] = b;
  }
};

const int N = 2e5;
bitset<50> A[N];
int dp[N][50];
int lastdate[N];
int date = 0;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,d; cin>>n>>m>>d;
  vvi G(n);
  FOR(i,m) {
    int u,v; cin>>u>>v;
    --u; --v;
    G[u].pb(v);
  }
  FOR(i,n) {
    FOR(j,d) {
      char c; cin>>c;
      if(c=='1') A[i][j]=1;
    }
  }
  vvi cs; vi C;
  scc(G,cs,C);
  vi cix(n);
  for(auto v : cs) FOR(i,v.size()) cix[v[i]] = i;

  FORD(j_,(int)cs.size()-1,0) {
    auto const& v = cs[j_];
    int nv = v.size();
    union_find uf(nv * d);
    for(int u : v) for(int w : G[u]) if(C[u] == C[w]) {
          FOR(a,d) uf.unite(cix[u]*d+a, cix[w]*d+(a+1)%d);
        }
    vvii cls(nv * d);
    FOR(i,v.size()) FOR(j,d) cls[uf.find(i*d+j)].eb(v[i],j);
    for(auto cl : cls) if(!cl.empty()) {
        date += 1;
        int to = 0;
        int sc = 0;
        for(auto uj : cl) {
          int u,j; tie(u,j) = uj;
          if(lastdate[u] != date && A[u][j]) {
            lastdate[u]=date;
            sc++;
          }
          for(int w : G[u]) if(C[u] != C[w]) {
              to = max(to, dp[w][(j+1)%d]);
            }
        }
        for(auto uj : cl) {
          int u,j; tie(u,j) = uj;
          dp[u][j] = to+sc;
        }
      }
  }
  cout << dp[0][0] << endl;
  return 0;
}