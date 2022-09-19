


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


template<class Fun>
class letrec_result {
  Fun fun_;
  public:
    template<class T>
    explicit letrec_result(T &&fun): fun_(forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
      return fun_(ref(*this), forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) letrec(Fun &&fun) {
  return letrec_result<decay_t<Fun>>(forward<Fun>(fun));
}

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
 struct node {
    bool dirty = false;
    li value = 0;
    li sum = 0;
    li mn, mx = 0;

    node(){
    }

    node(li s){
      sum = s;
      mn = s;
      mx = s;
    }

    void combine(node &a, node& b) {
      sum = a.sum + b.sum;
      mn = min(a.mn, b.mn);
      mx = max(a.mx, b.mx);
    }
  };

struct segment_tree {

  li n;
  vector<node> A;
  segment_tree(li n_) : n((li)1<<(li)(log2(n_)+1)), A(2*n) {
    build();
  }

  void update(li i) {
    if(i < n) {
      A[i].combine(A[2*i],A[2*i+1]);
    }
  }

  void build(){
    for(li i = (n-1); i >= (li)(1); --i) update(i);
  }

  void push(li i, li a, li b){
    if(i < n){
      if(A[i].dirty) {
        li c = (a+b)/2;
        setr__(2*i, a, c, A[i].value);
        setr__(2*i+1, c+1, b, A[i].value);
        update(i);
        A[i].dirty = false;
      }
    }
  }

  void setr__(li i, li a, li b, li v){
    A[i].dirty = true;
    A[i].value = v;
    A[i].sum = (b-a+1) * v;
    A[i].mn = A[i].mx = v;
  }

  void setr_(li i, li a, li b, li l, li r, li v) {
    if(l > b) return;
    if(r < a) return;
    push(i,a,b);
    if(l <= a && b <= r) {
      if(A[i].mn >= v) return;
      if(A[i].mx <= v) {
        setr__(i, a, b, v);
        return;
      }
    }
    li c = (a+b)/2;
    setr_(2*i , a , c, l, r, v);
    setr_(2*i+1, c+1, b, l, r, v);
    update(i);
  }


  void setr(li l, li r, li v){
    setr_(1, 0, n-1, l, r, v);
  }


  pii solve_(li i, li a, li b, li l, li r, li y) {

    if(l > b || r < a) return make_tuple(y,0);
    push(i,a,b);
    if(l <= a && b <= r){
      if(A[i].sum <= y) {

        return make_tuple(y-A[i].sum, b-a+1);
      }else if(A[i].mn > y) {
        return make_tuple(y,0);
      }
    }
    li c = (a+b)/2;
    li yl, cntl; tie(yl, cntl) = solve_(2*i, a, c, l, r, y);
    li yr, cntr; tie(yr, cntr) = solve_(2*i+1, c+1, b, l, r, yl);

    return make_tuple(yr, cntl+cntr);
  }

  pii solve(li l, li r, li y){
    return solve_(1, 0, n-1, l, r, y);
  }
};



int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,q; cin>>n>>q;
  vi A(n);
  for(li i = 0; i < (li)(n); ++i) cin>>A[i];



  segment_tree st(n);
  for(li i = 0; i < (li)(n); ++i) st.A[st.n+i] = node(A[i]);
  st.build();

  for(li q_ = 0; q_ < (li)(q); ++q_) {
    li ty,x,y; cin>>ty>>x>>y;



    if(ty == 1) {
      st.setr(0, x-1, y);
    } else{
      pii ans = st.solve(x-1, n-1, y);
      cout << (ans^yy) << '\n';
    }
  }
  cout << flush;


  return 0;
}