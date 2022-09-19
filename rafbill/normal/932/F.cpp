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

using line_t = long long int; // double;
const line_t is_query = -(1ll<<63); // -1e18;

struct Line {
	line_t m, b;
	mutable function<const Line*()> succ;
	bool operator<(const Line& rhs) const {
		if (rhs.b != is_query) return m < rhs.m;
		const Line* s = succ();
		if (!s) return 0;
		line_t x = rhs.m;
		return (long double)(b - s->b) < (long double)(s->m - m) * (long double)x;
	}
};

struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
	bool bad(iterator y) {
		auto z = next(y);
		if (y == begin()) {
			if (z == end()) return 0;
			return y->m == z->m && y->b <= z->b;
		}
		auto x = prev(y);
		if (z == end()) return y->m == x->m && y->b <= x->b;
		return (long double)(x->b - y->b)*(long double)(z->m - y->m) >= (long double)(y->b - z->b)*(long double)(y->m - x->m);
	}
	void insert_line(line_t m, line_t b) {
		auto y = insert({ m, b });
		y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
		if (bad(y)) { erase(y); return; }
		while (next(y) != end() && bad(next(y))) erase(next(y));
		while (y != begin() && bad(prev(y))) erase(prev(y));
	}
	line_t query(line_t x) {
		auto l = *lower_bound((Line) { x, is_query });
		return l.m * x + l.b;
	}
};

const int N = 1e5+16;
HullDynamic* H[N];
vector<pii>* S[N];
lli sz[N];
lli ans[N];
lli ans2[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vi A(n),B(n);

#ifdef LOCAL
  FOR(i,n) A[i] = -100000;
  FOR(i,n) B[i] = 100000;

#else
  FOR(i,n) cin>>A[i];
  FOR(i,n) cin>>B[i];
#endif

  vvi G(n);
#ifdef LOCAL
  FOR(i,n-1) G[i].pb(i+1);
  FOR(i,n-1) G[i+1].pb(i);
#else
  FOR(i,n-1) {
    lli u,v; cin>>u>>v;
    u--; v--;
    G[u].pb(v);
    G[v].pb(u);
  }
#endif

  // function<lli(lli,lli,lli)> dfs2 = [&](lli i, lli p, lli a) -> lli {
  //   lli ans = a * B[i] + ans2[i];
  //   for(int j : G[i]) if(j!=p) {
  //       ans = min(ans,dfs2(j,i,a));
  //     }
  //   return ans;
  // };

  // function<void(lli,lli)> dfs3 = [&](lli i, lli p) {
  //   ans2[i] = (1ll<<60);
  //   for(lli j : G[i]) if(j != p) {
  //       dfs3(j,i);
  //       ans2[i] = min(ans2[i], dfs2(j,i,A[i]));
  //     }
  //   if(p!=-1&&G[i].size()==1) ans2[i]=0;
  // };
  // dfs3(0,-1);

  function<void(lli,lli)> dfs = [&](lli i, lli p) {
    sz[i]=1;
    lli bc = -1;
    for(lli j : G[i]) if(j != p) {
        dfs(j,i);
        sz[i] += sz[j];
        if(bc==-1||sz[j]>sz[bc])bc=j;
      }
    if(bc != -1) {
      H[i] = H[bc];
      S[i] = S[bc];
      for(lli j : G[i]) if(j!=p&&j!=bc) {
          for(auto const& l : *S[j]) {
            S[i]->pb(l);
            H[i]->insert_line(l.x(),l.y());
          }
        }
      ans[i] = -H[i]->query(A[i]);
    }else{
      ans[i] = 0;
      H[i] = new HullDynamic;
      S[i] = new vector<pii>;
    }
    H[i]->insert_line(-B[i], -ans[i]);
    S[i]->eb(-B[i], -ans[i]);
  };
  dfs(0,-1);

  FOR(i,n) cout << ans[i] << ' ';
  cout << endl;
  // FOR(i,n) cout << ans2[i] << ' ';
  // cout << endl;
  // FOR(i,n) assert(ans[i] == ans2[i]);

  return 0;
}