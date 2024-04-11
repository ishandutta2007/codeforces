


 #include <stdio.h>
 #include <bits/stdc++.h>






using namespace std;




template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, deque<T> const& a) { return print_collection(s, a); }
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
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}


static inline void debug_impl_seq() {
  cerr << "}";
}

template <class T, class... V>
void debug_impl_seq(T const& t, V const&... v) {
  cerr << t;
  if(sizeof...(v)) { cerr << ", "; }
  debug_impl_seq(v...);
}







using li = long long int;
using lu = long long unsigned;
using ld = long double;


using pii = tuple<li, li>;
using piii = tuple<li, li, li>;
using piiii = tuple<li, li, li, li>;
using vi = vector<li>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

struct empty_t {};



namespace tuple_access {

  struct xx_t {} xx;
  struct yy_t {} yy;
  struct zz_t {} zz;
  struct ww_t {} ww;

  template<class T>
  typename tuple_element<0,T>::type& operator^(T& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type const& operator^(T const& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type&& operator^(T&& v, xx_t) { return get<0>(v); }

  template<class T>
  typename tuple_element<1,T>::type& operator^(T& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type const& operator^(T const& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type&& operator^(T&& v, yy_t) { return get<1>(v); }

  template<class T>
  typename tuple_element<2,T>::type& operator^(T& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type const& operator^(T const& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type&& operator^(T&& v, zz_t) { return get<2>(v); }

  template<class T>
  typename tuple_element<3,T>::type& operator^(T& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type const& operator^(T const& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type&& operator^(T&& v, ww_t) { return get<3>(v); }
}
using namespace tuple_access;


int ilog2(int x){ return 31 - __builtin_clz(x); }

template <class T>
struct identity : std::unary_function <T, T> {
  T operator() (const T& x) const {return x;}
};

template<class T>
T& smin(T& x, T const& y) { x = min(x,y); return x; }

template <class T>
T& smax(T& x, T const& y) { x = max(x, y); return x; }


template<typename T>
T isqrt(T const&x){
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(sqrtl(x));
  while(ret>0 && ret*ret>x) --ret;
  while(x-ret*ret>2*ret) ++ret;
  return ret;
}

template<typename T>
T icbrt(T const&x) {
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(cbrt(x));
  while(ret>0 && ret*ret*ret>x) --ret;
  while(x-ret*ret*ret>3*ret*(ret+1)) ++ret;
  return ret;
}

const li infty = 1e16;

struct segment_tree {

  struct node {
    node(){
      value = make_tuple(infty, 0);
      delta = 0;
    }
    pii value;
    li delta;

    void combine(node &a, node& b) {
      value = min(a.value, b.value);
      delta = 0;
    }
  };

  int n;
  vector<node> A;
  segment_tree(int n_) : n((int)1<<(int)(log2(n_)+1)), A(2*n) {
    build();
  }

  void update(int i) {
    if(i < n) {
      A[i].combine(A[2*i],A[2*i+1]);
    }
  }

  void build(){
    for(li i = (n-1); i >= (li)(1); --i) update(i);
  }

  void push(int i, int a, int b){
    if(i < n){
      int c = (a+b)/2;
      if(A[i].delta != infty) {
        addr__(2*i,a,c,A[i].delta);
        addr__(2*i+1,c+1,b,A[i].delta);
        A[i].delta = 0;
      }
    }
  }

  void addr__(int i, int a, int b, li v){
    ::get<0>(A[i].value) += v;
    A[i].delta += v;
  }

  void addr_(int i, int a, int b, int l, int r, li v) {
    if(l > b) return;
    if(r < a) return;
    push(i,a,b);
    if(l <= a && b <= r) { addr__(i, a, b, v); return; }
    int c = (a+b)/2;
    addr_(2*i , a , c, l, r, v);
    addr_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void addr(int l, int r, li v){
    addr_(1, 0, n-1, l, r, v);
  }

  pii get_(int i, int a, int b, int l, int r) {
    if(l > b) return pii(infty, 0);
    if(r < a) return pii(infty, 0);
    push(i,a,b);
    if(l <= a && b <= r){
      return A[i].value;
    }
    int c = (a+b)/2;
    return min(get_(2*i , a , c, l, r), get_(2*i+1, c+1, b, l, r));
  }

  pii get(int l, int r){
    return get_(1, 0, n-1, l, r);
  }
};



struct BIT {
  vi A;
  BIT(li n) : A(n+1){ }

  li get(li i){
    i += 1;
    li r = 0;
    for(; i > 0; i -= i &-i){
      r += A[i];
    }
    return r;
  }

  li getR(li l, li r) {
    li ans = get(r);
    if(l) ans -= get(l-1);
    return ans;
  }

  void add(li i, li v){
    i += 1;
    for(; i < (li)A.size(); i += i & -i){
      A[i] += v;
    }
  }
};




int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,q; cin>>n>>q;
  vi A(n); for(li i = 0; i < (li)(n); ++i) cin>>A[i];

  BIT bit(n+1);
  vi E(n, 0);

  segment_tree st(n);
  int nr = 0;
  for(li i = 0; i < (li)(n); ++i) if(A[i] <= i+1) {
    if(A[i]+nr >= i+1) {
      E[i] = 1;
      st.A[st.n+i].value = make_tuple(A[i]+nr - (i+1), i);
      nr++;
      bit.add(i, 1);
    }
  }
  st.build();

  vi ans(q);
  vector<vector<tuple<int, int>>> qs(n);

  for(li iq = 0; iq < (li)(q); ++iq) {
    int x,y; cin>>x>>y;
    int l = x;
    int r = n-1-y;
    qs[l].emplace_back(r,iq);
  }

  for(li l = 0; l < (li)(n); ++l) {
    for(auto riq : qs[l]) {
      int r, iq; tie(r,iq) = riq;
      ans[iq] = bit.get(r);
    }
    if(E[l]) {
      E[l] = 0;
      bit.add(l, -1);
      st.addr(l,l,infty);
      st.addr(l,n-1,-1);
      while(1) {
        int v,i; tie(v,i) = st.get(0,n-1);
        if(v >= 0) break;
        E[i] = 0;
        bit.add(i, -1);
        st.addr(i,i,infty);
        st.addr(i,n-1,-1);
      }
    }
  }

  for(li i = 0; i < (li)(q); ++i) {
    cout << ans[i] << '\n';
  }
  cout << endl;

  return 0;
}