#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
#endif
#ifdef ONLINE_JUDGE
#define NDEBUG 1
#endif
#include <stdio.h>
#include <bits/stdc++.h>

#define DESTRUCT2(p, a, b)                      \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);

#define DESTRUCT3(p, a, b, c)                   \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);                           \
  auto c = get<2>(p);

#define DESTRUCT4(p, a, b, c, d)                \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);                           \
  auto c = get<2>(p);                           \
  auto d = get<3>(p);

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

// --- BEGIN SNIPPET SUFFIX ARRAY ---

template<typename T>
struct SA {
  T &S;
  int N;
  vi sa, isa, pos, tmp, lcp;

  SA(T &S_) : S(S_), N(S_.size()), sa(N), pos(N+1), tmp(N+1), lcp(N) {
    FOR(i, N) sa[i] = i, pos[i] = S[i];
    for(int gap = 1;; gap *= 2) {
      auto sufCmp = [&](int i, int j) {
        if(pos[i] != pos[j]) return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i<N && j<N) ? pos[i]<pos[j] : i>j;
      };
      sort(all(sa), sufCmp);
      FOR(i, N-1) tmp[i+1] = tmp[i] + sufCmp(sa[i], sa[i+1]);
      FOR(i, N) pos[sa[i]] = tmp[i];
      if(tmp[N-1] == N-1) break;
    }
    isa.resize(N);
    FOR(i, N) isa[sa[i]] = i;
    for(int i = 0, k = 0; i < N; ++i) if(pos[i] != N-1) {
        for(int j = sa[pos[i]+1]; i+k<(int)S.size() && j+k<(int)S.size() && S[i+k] == S[j+k];) k += 1;
        lcp[pos[i]] = k;
        if(k) k -= 1;
      }
  }
};

// --- END SNIPPET SUFFIX ARRAY ---


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n; cin>>n;
  vector<string> s(n);
  vector<tpl<int,string>> ans(n);
  FOR(i,n) cin>>s[i];
  // FOR(i,n) {
  //   s[i] = to_string(i);
  //   while(s[i].size()<9) s[i] = string("0")+s[i];
  // }
  FOR(i,n) ans[i] = mt(9,s[i]);
  unordered_map<string,unordered_set<int>> cnt;
  FOR(i,n) {
    FOR(j,9) FORU(k,j,8) {
      cnt[s[i].substr(j,k-j+1)].insert(i);
    }
  }
  FOR(i,n) {
    FOR(j,9) FORU(k,j,8) {
      if(cnt[s[i].substr(j,k-j+1)].size() == 1) {
        ans[i] = min(ans[i],tpl<int,string>(k-j+1,s[i].substr(j,k-j+1)));
      }
    }
  }
  // string t;
  // vi at;
  // FOR(i,n) {FOR(j,9) at.pb(i); t += s[i]; t += '$';at.pb(-1);}
  // SA<string> sa(t);
  // FOR(i,at.size()) if(at[i]!=-1) {
  //   lli j = sa.sa[i];
  //   lli j0 = j;
  //   lli cans = 9;
  //   while(j0 && at[sa.isa[j0-1]] == at[i]) {
  //     j0 -= 1;
  //     cans = min(cans,sa.lcp[j0]);
  //   }
  //   lli j1 = j;
  //   while(j1+1 < n && at[sa.isa[j1+1]] == at[i]) {
  //     cans = min(cans,sa.lcp[j1]);
  //     j1 += 1;
  //   }
  //   if(j0 && at[sa.isa[j0-1]] != -1) cans = min(cans, sa.lcp[j0-1]);
  //   if(j1+1<n && at[sa.isa[j1+1]] != -1) cans = min(cans,sa.lcp[j1]);
  //   string cc;
  //   FOR(k,cans+1) {cc += }
  //     ans[at[i]] = min(ans[at[i]],mt(cans+1,cc));
  // l1:;
  // }
  FOR(i,n) cout << ans[i].y() << '\n';
  cout << flush;
  return 0;
}