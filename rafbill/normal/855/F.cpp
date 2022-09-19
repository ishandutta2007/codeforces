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

// --- BEGIN SNIPPET SEGMENT TREE ---

const lli infty = 1e15;

struct segment_tree {

  struct node {
    node(){
      maxVal = infty;
      maxCnt = 1;
      sndMax = -1;
      sum = 0;
      delta = infty;
    }
    lli maxVal, maxCnt;
    lli sndMax;
    lli sum;
    lli delta;

    void combine(node &a, node& b) {
      maxVal = max(a.maxVal, b.maxVal);
      maxCnt = 0;
      if(maxVal == a.maxVal) maxCnt += a.maxCnt;
      if(maxVal == b.maxVal) maxCnt += b.maxCnt;
      sndMax = max(a.sndMax,b.sndMax);
      if(maxVal != a.maxVal) sndMax = max(sndMax,a.maxVal);
      if(maxVal != b.maxVal) sndMax = max(sndMax,b.maxVal);
      sum = a.sum+b.sum;
    }
  };

  int n;
  vector<node> A;
  segment_tree(int n_) : n((int)1<<(int)(log2(n_)+1)), A(2*n) { }

  void update(int i) {
    if(i < n) {
      A[i].combine(A[2*i],A[2*i+1]);
    }
  }

  void build(){
    FORD(i,n-1,1) update(i);
  }

  void push(int i, int a, int b){
    if(i < n){
      int c = (a+b)/2;
      if(A[i].delta != infty) {
        setr__(2*i,a,c,A[i].delta);
        setr__(2*i+1,c+1,b,A[i].delta);
        A[i].delta = infty;
      }
    }
  }

  // void set__(int i, int, int, lli v){
  //   A[i].maxVal = v;
  //   A[i].sum = v;
  // }

  // void set_(int i, int a, int b, int l, lli v) {
  //   if(l > b) return;
  //   if(l < a) return;
  //   push(i,a,b);
  //   if(a == b){
  //     set__(i, a, b, v);
  //     return;
  //   }
  //   int c = (a+b)/2;
  //   set_(2*i  , a  , c, l, v);
  //   set_(2*i+1, c+1, b, l, v);
  //   update(i);
  // }

  // void set(int l, lli v){
  //   set_(1, 0, n-1, l, v);
  // }

  void setr__(int i, int a, int b, lli v){
    if(v >= A[i].maxVal) {A[i].delta = A[i].maxVal; return;}
    if(v >= A[i].sndMax) {
      if(A[i].maxVal != infty) {
        A[i].sum -= A[i].maxCnt * A[i].maxVal;
      }
      A[i].maxVal = v;
      A[i].sum += A[i].maxCnt * A[i].maxVal;
      A[i].delta = v;
      return;
    }
    assert(i<n);
    setr___(i,a,b,a,b,v);
  }

  void setr___(int i, int a, int b, lli l, lli r, lli v) {
    int c = (a+b)/2;
    setr_(2*i  , a  , c, l, r, v);
    setr_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void setr_(int i, int a, int b, int l, int r, lli v) {
    if(l > b) return;
    if(r < a) return;
    push(i,a,b);
    if(l <= a && b <= r) { setr__(i, a, b, v); return; }
    setr___(i,a,b,l,r,v);
  }

  void setr(int l, int r, lli v){
    setr_(1, 0, n-1, l, r, v);
  }

  lli get_(int i, int a, int b, int l, int r) {
    if(l > b) return 0;
    if(r < a) return 0;
    push(i,a,b);
    if(l <= a && b <= r){
      return A[i].sum;
    }
    int c = (a+b)/2;
    return get_(2*i  , a  , c, l, r) + get_(2*i+1, c+1, b, l, r);
  }

  lli get(int l, int r){
    return get_(1, 0, n-1, l, r);
  }
};


// --- END SNIPPET SEGMENT TREE ---

const int N = 100010;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  segment_tree st0(N+1), st1(N+1);
  segment_tree st00(N+1), st10(N+1);
  st0.build();
  st1.build();
  st00.build();
  st10.build();
  lli q; cin>>q;

  set<lli> s00,s01,s10,s11;
  FORU(i,1,100000) s00.insert(i);
  auto inRange = [&](set<lli> const& v, lli l, lli r) -> vi {
    auto it = v.lower_bound(l);
    vi rr;
    while(it != end(v) && *it <= r) {
      rr.pb(*it); ++it;
    }
    return rr;
  };

  FOR(q_,q) {
    lli ty; cin>>ty;
    if(ty == 1) {
      lli l,r,k; cin>>l>>r>>k; --r;
      if(k>0) {
        st0.setr(l,r,k);
        st00.setr(l,r,k);
        for(lli x : inRange(s00,l,r)) {
          s00.erase(x); s10.insert(x);
        }
        for(lli x : inRange(s01,l,r)) {
          s01.erase(x); s11.insert(x);
          st00.setr(x,x,0);
          st10.setr(x,x,0);
        }
      }else{
        st1.setr(l,r,-k);
        st10.setr(l,r,-k);
        for(lli x : inRange(s00,l,r)) {
          s00.erase(x); s01.insert(x);
        }
        for(lli x : inRange(s10,l,r)) {
          s10.erase(x); s11.insert(x);
          st00.setr(x,x,0);
          st10.setr(x,x,0);
        }
      }
    }else{
      lli l,r; cin>>l>>r; --r;
      cout << st0.get(l,r)+st1.get(l,r)-st00.get(l,r)-st10.get(l,r) << '\n';
    }
  }

  return 0;
}