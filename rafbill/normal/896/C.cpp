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

struct segment_tree {

  struct node {
    node(){}
    node(lli v) { minV = maxV = v; delta=0; deltaSet = -1; }
    lli minV=0, maxV=0;
    lli delta=0;
    lli deltaSet=-1;

    void combine(node &a, node& b) {
      minV = min(a.minV, b.minV);
      maxV = max(a.maxV, b.maxV);

      delta=0;
      deltaSet=-1;
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
      if(A[i].deltaSet != -1) {
        set__(2*i,a,c,A[i].deltaSet);
        set__(2*i+1,c+1,b,A[i].deltaSet);
        A[i].delta = 0;
        A[i].deltaSet = -1;
      }else if(A[i].delta){
        add__(2*i  , a,   c, A[i].delta);
        add__(2*i+1, c+1, b, A[i].delta);
        A[i].delta = 0;
      }
    }
  }

  void add__(int i, int , int , lli v){
    A[i].minV += v;
    A[i].maxV += v;
    A[i].delta += v;
    if(A[i].deltaSet != -1) A[i].deltaSet += v;
  }

  void add_(int i, int a, int b, int l, int r, lli v) {
    if(l > b) return;
    if(r < a) return;
    push(i,a,b);
    if(l <= a && b <= r){
      add__(i, a, b, v);
      return;
    }
    int c = (a+b)/2;
    add_(2*i  , a  , c, l, r, v);
    add_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void add(int l, int r, lli v){
    add_(1, 0, n-1, l, r, v);
  }

  void set__(int i, int , int , lli v){
    A[i].minV = v;
    A[i].maxV = v;
    A[i].delta = 0;
    A[i].deltaSet = v;
  }

  void set_(int i, int a, int b, int l, int r, lli v) {
    if(l > b) return;
    if(r < a) return;
    push(i,a,b);
    if(l <= a && b <= r){
      set__(i, a, b, v);
      return;
    }
    int c = (a+b)/2;
    set_(2*i  , a  , c, l, r, v);
    set_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void set(int l, int r, lli v){
    set_(1, 0, n-1, l, r, v);
  }


  void iter_(int i, int a, int b, int l, int r, function<void(lli,lli)> f) {
    if(l > b) return;
    if(r < a) return;
    push(i,a,b);
    if(l <= a && b <= r && A[i].minV == A[i].maxV){
      f(A[i].minV, b-a+1);
      return;
    }
    int c = (a+b)/2;
    iter_(2*i  , a  , c, l, r, f);
    iter_(2*i+1, c+1, b, l, r, f);
  }

  void iter(int l, int r, function<void(lli,lli)> f){
    iter_(1, 0, n-1, l, r, f);
  }
};


// --- END SNIPPET SEGMENT TREE ---


const lli MOD = 1e9+7;

lli seed;
lli rnd(){
  lli r=seed;
  seed = (seed*7+13)%MOD;
  return r;
}

const int N = 1e5;
lli A[N];

inline lli fexp(lli a, lli b, lli m) {
  a %= m;
  lli r = 1;
  while(b){
    if(b&1) r = (r*a)%m;
    a = (a*a)%m;
    b /= 2;
  }
  return r;
}


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n,m,vm; cin>>n>>m>>seed>>vm;
  FOR(i,n) A[i] = (rnd()%vm)+1;
  segment_tree st(n);
  FOR(i,n) st.A[st.n+i] = segment_tree::node(A[i]);
  st.build();



  FOR(i,m) {
    int op = rnd()%4;
    lli l = rnd()%n;
    lli r = rnd()%n;
    lli x=-1, y=-1;
    if(l>r) swap(l,r);
    if(op == 2) {
      x = (rnd()%(r-l+1))+1;
    }else{
      x = (rnd()%vm)+1;
    }
    if(op == 3) y = (rnd()%vm)+1;

    if(op == 0) {
      st.add(l,r,x);
    }else if(op==1) {
      st.set(l,r,x);
    }else if(op==2) {
      map<lli,lli> M;
      st.iter(l,r,[&](lli a, lli b) { M[a]+=b; });
      for(auto p : M) {
        x -= p.second;
        if(x<=0) {
          cout << p.first << '\n';
          break;
        }
      }
    }else{
      lli ans=0;
      st.iter(l,r,[&](lli a, lli b) { (ans += b%y*fexp(a,x,y)%y)%=y; });
      if(ans < 0) ans += y;
      cout << ans << '\n';
    }

  }
  return 0;
}