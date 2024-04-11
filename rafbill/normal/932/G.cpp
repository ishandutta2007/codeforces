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


// Palindromic tree
// 0 is the odd palindrome with size -1, 1 is the empty even palindrome

const int N = 1e6+128;

map<int,int> to[N]; // Children
int link[N];        // Parent
int diff[N];        // Length difference with the parent
int slink[N];       // Link to the first parent of a different series
                    // A series is a sequence of palindrome with constant size difference
                    // The path to the root through slink has size O(log n)
int len[N];         // Node palindrome length
int last[N];        // Nodes of prefixes of s
int n, m;           // String size, tree size
int s[N];           // String

void init() {
  link[0] = link[1] = 0;
  last[0] = 0;
  len[0] = -1; len[1] = 0;
  diff[0] = diff[1] = -1;
  slink[0] = slink[1] = -1;
  n = 0; m = 2;
}

void add(int x) {
  s[n] = x; n += 1;
  last[n] = last[n-1];
  for(;;last[n] = link[last[n]]) {
    if(s[n-2-len[last[n]]] == x) {
      if(!to[last[n]].count(x)) {
        int v = m; m++;
        to[last[n]][x] = v;
        len[v] = len[last[n]]+2;
        if(len[v] == 1) {
          link[v] = 1;
        } else {
          link[v] = link[last[n]];
          while(s[n-2-len[link[v]]] != x) link[v] = link[link[v]];
          link[v] = to[link[v]][x];
        }
        diff[v] = len[v] - len[link[v]];
        if(diff[v] == diff[link[v]]) {
          slink[v] = slink[link[v]];
        }else{
          slink[v] = link[v];
        }
        last[n] = v;
      }else{
        last[n] = to[last[n]][x];
      }
      return;
    }
  }
}

const lli MOD = 1e9+7;

lli nmod(lli x) { return (x%MOD+MOD)%MOD; }

struct Zn {
  lli x;
  Zn() : x(0){}
  Zn(lli x_) : x(x_) {
    x %= MOD;
    if(x<0) x = (x+MOD)%MOD;
  }

  Zn operator+(Zn const& o) const { return Zn(x+o.x); }
  Zn operator-(Zn const& o) const { return Zn(x-o.x); }
  Zn operator*(Zn const& o) const { return Zn(x*o.x); }

  Zn& operator+=(Zn const& o) { return *this = *this+o; }
  Zn& operator-=(Zn const& o) { return *this = *this-o; }
  Zn& operator*=(Zn const& o) { return *this = *this*o; }
};

Zn dp[N];
Zn ans[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin>>s;
  int n = s.size();
  init();
  string t;
  FOR(i,n/2) { t.pb(s[i]); t.pb(s[s.size()-1-i]); }

  ans[0]=1;
  dp[0]=dp[1]=0;

  FOR(i,n) {
    add(t[i]);
    ans[i+1] = 0;
    for(int v = last[i+1]; v > 1; v = slink[v]) {
      dp[v] = 0;
      if(((i+1) - (len[slink[v]]+diff[v]))%2 == 0) {
        dp[v] = ans[(i+1) - (len[slink[v]]+diff[v])];
      }
      if(diff[v] == diff[link[v]]) dp[v] += dp[link[v]];
      if((i+1)%2==0) ans[i+1] += dp[v];
    }
  }
  cout << ans[n].x << endl;
  return 0;
}