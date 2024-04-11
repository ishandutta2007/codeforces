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

using lli   = int;
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

// --- BEGIN SNIPPET SEGMENT TREE ---

struct segment_tree {

  struct node {
    node(){}
    lli gcd;
    void combine(node &a, node& b) {
      gcd = __gcd(a.gcd,b.gcd);
    }
  };

  lli n;
  vector<node> A;
  segment_tree(lli n_) : n((lli)1<<(lli)(log2(n_)+1)), A(2*n) { }

  void build(){
    FORD(i,n-1,1) update(i);
  }

  void update(lli i) {
    if(i < n) {
      A[i].combine(A[2*i],A[2*i+1]);
    }
  }

  void set__(lli i, lli, lli, lli v){
    A[i].gcd = v;
  }

  void set_(lli i, lli a, lli b, lli l, lli r, lli v) {
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      set__(i, a, b, v);
      return;
    }
    lli c = (a+b)/2;
    set_(2*i  , a  , c, l, r, v);
    set_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void set(lli l, lli r, lli v){
    assert(l == r);
    set_(1, 0, n-1, l, r, v);
  }

  // node get_(lli i, lli a, lli b, lli l, lli r) {
  //   if(l > b) return node();
  //   if(r < a) return node();
  //   if(l <= a && b <= r){
  //     return A[i];
  //   }
  //   push(i,a,b);
  //   lli c = (a+b)/2;
  //   node ar = get_(2*i  , a  , c, l, r);
  //   node br = get_(2*i+1, c+1, b, l, r);
  //   node res;
  //   res.combine(ar,br);
  //   return res;
  // }

  // lli get(lli l, lli r){
  //   node a = get_(1, 0, n-1, l, r);
  //   return a.gcd;
  // }

  // lli query2(lli i, lli a, lli b, lli x) {
  //   if(A[i].gcd % x == 0) return 0;
  //   if(a == b) {
  //     return 1;
  //   }
  //   lli c = (a+b)/2;
  //   lli r = 0;
  //   r += query2(2*i  , a  , c, x);
  //   if(r <= 1)
  //     r += query2(2*i+1, c+1, b, x);
  //   return r;
  // }

  lli query_(lli i, lli a, lli b, lli l, lli r, lli x) {
    if(l > b) return 0;
    if(r < a) return 0;
    if(l <= a && b <= r){
      if(A[i].gcd % x == 0) return 0;
      if(a == b) return 1;
      lli c = (a+b)/2;
      lli rr = query_(2*i  , a  , c, l, r, x);
      if(rr <= 1) { rr += query_(2*i+1, c+1, b, l, r, x); }
      return rr;
    }else{
      lli c = (a+b)/2;
      lli rr = query_(2*i  , a  , c, l, r, x);
      if(rr <= 1) { rr += query_(2*i+1, c+1, b, l, r, x); }
      return rr;
    }
  }

  bool query(lli l, lli r, lli x){
    lli rr = query_(1, 0, n-1, l, r, x);
    return rr <= 1;
  }
};


// --- END SNIPPET SEGMENT TREE ---


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n; cin>>n;
  vi A(n);
  FOR(i,n) cin>>A[i];
  segment_tree st(n+16);
  FOR(i,n) st.A[st.n+i].gcd = A[i];
  st.build();
  lli q; cin>>q;
  FOR(q_,q) {
    lli ty; cin>>ty;
    if(ty == 1) {
      lli l,r,x; cin>>l>>r>>x;
      --l; --r;
      if(st.query(l,r,x)) {
        printf("YES\n");
      }else{
        printf("NO\n");
      }
    }else{
      lli i, y; cin>>i>>y; --i;
      st.set(i,i,y);
    }
  }
  return 0;
}