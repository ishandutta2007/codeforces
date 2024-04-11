



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



using li = int;
using lu = unsigned;
using ld = double;






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

template<class Fun>
class y_combinator_result {
  Fun fun_;
  public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
      return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

struct node {
  int sum = 0, sxor = 0;
  array<int, 2> lmx;

  node() {
    sum = 0;
    sxor = 0;
    lmx[0] = 0;
    lmx[1] = -(1<<20);
  }
  node(int v1, int v2) {
    sum = v1;
    sxor = v2;
    lmx[0] = max(0, (v2 == 0) ? v1 : 0);
    lmx[1] = v2 ? v1 : -(1<<20);
  }

  void combine(node const& a, node const& b) {
    sum = a.sum + b.sum;
    sxor = a.sxor ^ b.sxor;
    for(li i = 0; i < (li)(2); ++i) lmx[i] = max(a.lmx[i], a.sum + b.lmx[i^a.sxor]);
  }
};



struct segment_tree {
  int n;
  vector<node> A;
  segment_tree(){}
  segment_tree(int n_) : n((int)1<<(int)(log2(n_)+1)), A(2*n) { }

  void update(int i) {
    if(i < n) {
      A[i].combine(A[2*i],A[2*i+1]);
    }
  }

  void build() {
    for(li i = (n-1); i >= (li)(1); --i) update(i);
  }

  void set_(int i, int a, int b, int x, int v1, int v2) {
    if(x > b || x < a) return;
    if(a == b){
      A[i] = node(v1, v2);
      return;
    }
    int c = (a+b)/2;
    if(x <= c) set_(2*i , a , c, x, v1, v2);
    else set_(2*i+1, c+1, b, x, v1, v2);
    update(i);
  }

  void set(int x, int v1, int v2){
    set_(1, 0, n-1, x, v1, v2);
  }

  node get_(int i, int a, int b, int l, int r) {
    if(l > b || r < a) return node();
    if(l <= a && b <= r) return A[i];
    int c = (a+b)/2;
    node ar = get_(2*i , a , c, l, r);
    node br = get_(2*i+1, c+1, b, l, r);
    node res;
    res.combine(ar,br);
    return res;
  }

  node get(int l, int r){
    return get_(1, 0, n-1, l, r);
  }
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  srand(42);

  int n; cin>>n;

  vi T0(n-1);
  vvii G(n);
  vi U(n-1), V(n-1);

  for(li i = 0; i < (li)(n-1); ++i) {





    int u,v,t; cin>>u>>v>>t;
    --u; --v;


    U[i] = u;
    V[i] = v;
    T0[i] = t;
    G[u].emplace_back(v, i);
    G[v].emplace_back(u, i);
  }

  auto dfs = y_combinator([&](auto self, int i, int p, int d, int& md, int& u) -> void {
    if(d > md) { md = d; u = i; }
    for(auto je : G[i]) {
      int j; tie(j, ignore) = je;
      if(j == p) continue;
      self(j, i, d+1, md, u);
    }
  });
  int md = -1; int u[2];
  dfs(0, -1, 0, md, u[0]);
  md = -1;
  dfs(u[0], -1, 0, md, u[1]);

  int q; cin>>q;
  vi Q(q);
  for(li q_ = 0; q_ < (li)(q); ++q_) {



    int i; cin>>i; --i;

    Q[q_] = i;
  }

  vi ans(q);

  for(li ix = 0; ix < (li)(2); ++ix) {
    int time = 0;
    vi intime(n), outtime(n);
    vi W1, W2;
    vi T = T0;

    auto dfs = y_combinator([&](auto dfs, int i, int p, int w) -> void {
      intime[i] = time;
      W1.emplace_back((w == -1) ? 0 : 1);
      W2.emplace_back((w == -1) ? 0 : w);
      time++;

      for(auto je : G[i]) {
        int j, e; tie(j, e) = je;
        if(j == p) continue;
        dfs(j, i, T[e]);
      }

      outtime[i] = time;
      W1.emplace_back((w == -1) ? 0 : -1);
      W2.emplace_back((w == -1) ? 0 : w);
      time++;
    });
    dfs(u[ix], -1, -1);

    segment_tree st(time);
    for(li i = 0; i < (li)(time); ++i) st.A[st.n+i] = node(W1[i], W2[i]);
    st.build();

    for(li i = 0; i < (li)(q); ++i) {
      int u = U[Q[i]], v = V[Q[i]];
      if(intime[u] > intime[v]) swap(u,v);
      T[Q[i]] ^= 1;
      st.set(intime[v], 1, T[Q[i]]);
      st.set(outtime[v], -1, T[Q[i]]);

      auto n = st.get(0, time-1);
      ans[i] = max<li>(ans[i], n.lmx[0]);
    }
  }

  for(li i = 0; i < (li)(q); ++i) cout << ans[i] << '\n';
  cout << flush;

  return 0;
}