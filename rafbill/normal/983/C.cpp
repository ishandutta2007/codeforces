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

const int F = 9;
const int S = 4;
const int NM = 715;
vector<vector<int>> ms;
map<vector<int>,int> gms;
int then[NM][F];
lli dp[2][F][NM];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> curm;
  function<void(int)> bt = [&](int i) {
    if(i==F) {
      int ix = ms.size();
      gms[curm] = ix;
      ms.pb(curm);
      return;
    }
    bt(i+1);
    if(curm.size() < S) {
      curm.pb(i);
      bt(i);
      curm.pop_back();
    }
  };
  bt(0);
  assert(ms.size() == NM);

  FOR(i,NM) FOR(f,F) {
    vector<int> m = ms[i];
    m.pb(f); sort(all(m));
    then[i][f] = gms.count(m) ? gms[m] : -1;
  }

  FOR(i,2) FOR(j,F) FOR(k,NM) dp[i][j][k] = (1ll<<30);
  FOR(k,F) dp[0][k][0] = k;

  int n; cin>>n;
  FOR(i,n) {
    int a,b; cin>>a>>b; --a; --b;
    FOR(j,F) FOR(k,NM) dp[1][j][k] = (1ll<<30);
    FOR(j,NM) if(then[j][b] != -1) {
      dp[1][a][then[j][b]] = min(dp[1][a][then[j][b]], dp[0][a][j]);
    }
    FOR(j,F) FOR(k,NM) dp[0][j][k] = dp[1][j][k];
    FORD(sz,S,0) {
      FOR(j,NM) if((int)ms[j].size() == sz) {
        FOR(k,F) if(then[j][k] != -1) {
          dp[0][k][j] = min(dp[0][k][j], dp[0][k][then[j][k]]);
        }
      }
      FOR(j,NM) if((int)ms[j].size() == sz) {
        FOR(k1,F) FOR(k2,F) dp[0][k1][j] = min(dp[0][k1][j], dp[0][k2][j] + abs(k1-k2));
      }
    }

    // FOR(j,NM) FOR(k,F) {
    //   cout << ms[j] << " " << k << " " << dp[1][k][j] << endl;
    // }
    // FOR(j,NM) FOR(k,F) if(dp[0][k][j] < (1ll<<30)) {
    //   cout << ms[j] << " " << k << " " << dp[0][k][j] << endl;
    // }
  }

  lli ans = 1ll<<30;
  FOR(k,F) ans = min(ans, dp[0][k][0]);
  cout << ans+2*n << endl;
  return 0;
}