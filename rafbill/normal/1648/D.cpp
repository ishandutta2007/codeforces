


 #include <stdio.h>
 #include <bits/stdc++.h>
 #include <ext/pb_ds/assoc_container.hpp>






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

struct uint64_hash {
  static inline uint64_t rotr(uint64_t x, unsigned k) {
    return (x >> k) | (x << (8U * sizeof(uint64_t) - k));
  }

  static inline uint64_t hash_int(uint64_t x) noexcept {
    auto h1 = x * (uint64_t)(0xA24BAED4963EE407);
    auto h2 = rotr(x, 32U) * (uint64_t)(0x9FB21C651E98DF25);
    auto h = rotr(h1 + h2, 32U);
    return h;
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    return hash_int(x + FIXED_RANDOM);
  }
};

template <typename K, typename V, typename Hash = uint64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
template <typename K, typename Hash = uint64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

struct empty_t {};

namespace tuple_access {
  struct xx_t {} xx;
  struct yy_t {} yy;
  struct zz_t {} zz;
  struct ww_t {} ww;

  template<class T>
  auto operator%(T&& v, xx_t) -> decltype(get<0>(forward<T>(v))) { return get<0>(forward<T>(v)); }
  template<class T>
  auto operator%(T&& v, yy_t) -> decltype(get<1>(forward<T>(v))) { return get<1>(forward<T>(v)); }
  template<class T>
  auto operator%(T&& v, zz_t) -> decltype(get<2>(forward<T>(v))) { return get<2>(forward<T>(v)); }
  template<class T>
  auto operator%(T&& v, ww_t) -> decltype(get<3>(forward<T>(v))) { return get<3>(forward<T>(v)); }
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

template<class Fun>
class letrec_memo_result {
  Fun fun_;
  public:
    template<class T>
    explicit letrec_memo_result(T &&fun): fun_(forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args const&... args) {
      static map<tuple<Args...>, decltype(fun_(ref(*this), args...))> M;
      auto key = make_tuple(args...);
      auto it = M.find(key);
      if(it != M.end()) return it->second;
      auto r = fun_(ref(*this), args...);
      M[key] = r;
      return r;
    }
};

template<class Fun>
decltype(auto) letrec_memo(Fun &&fun) {
  return letrec_memo_result<decay_t<Fun>>(forward<Fun>(fun));
}

int ilog2(int x){ return 31 - __builtin_clz(x); }

li ilog2(li x){ return 63 - __builtin_clzll(x); }

li ctz(li x) { return __builtin_ctzll(x); }
li clz(li x) { return __builtin_clzll(x); }
li popcount(li x) { return __builtin_popcountll(x); }
li getbit(li x, li i){ return (x>>i)&1; }
li setbit(li x, li i) { return x|(1ll<<i); }
li unsetbit(li x, li i) { return x&~(1ll<<i); }

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

const li N = 555'555;

li A[3][N];
li S[3][N];

const li infty = 1e17;

struct node {
  li count;
  li value;
  li mincost;

  li delta;
  li maxWith;

  node() {
    count = 0;
    value = -infty;
    mincost = 1e9;
    delta = 0;
    maxWith = -infty;
  }
  void combine(node const& a, node const& b){
    count = a.count + b.count;
    value = max(a.value, b.value);
    if(a.count&&b.count) mincost = min(a.mincost, b.mincost);
    else if(a.count) mincost = a.mincost;
    else if(b.count) mincost = b.mincost;
    else mincost = 1e9;
    delta = 0;
    maxWith = -infty;
  }
};

struct segt {
  segt() = default;
  segt(int n_) : n(2 << ilog2(n_)), A(2 * n) {}

  int n;
  vector<node> A;

  void build() {
    for(li i = (n-1); i >= (li)(1); --i) updateBuild(i);
  }
  void updateBuild(li i) {
    if(i < n) {
      A[i].combine(A[2*i], A[2*i+1]);
    }
  }
  void update(li i) {
    if(i < n) A[i].combine(A[2*i], A[2*i+1]);
  }

  void push(li i) {
    if(i<n){
      if(A[i].delta) {
        add__(2*i, A[i].delta);
        add__(2*i+1, A[i].delta);
        A[i].delta = 0;
      }
      maxWith__(2*i, A[i].maxWith);
      maxWith__(2*i+1, A[i].maxWith);
    }
  }

  void enable_(int i, int a, int b, int x) {
    if(a == b) {
      A[i].count = 1;
      return;
    }
    push(i);
    int c = (a + b) / 2;
    if(x <= c) {
      enable_(2 * i, a, c, x);
    } else if(x >= c + 1) {
      enable_(2 * i + 1, c + 1, b, x);
    }
    update(i);
  }

  void enable(int x) {
    return enable_(1, 0, n - 1, x);
  }

  void disable_(int i, int a, int b, int x) {
    if(a == b) {
      A[i].count = 0;
      A[i].value = -infty;
      return;
    }
    push(i);
    int c = (a + b) / 2;
    if(x <= c) {
      disable_(2 * i, a, c, x);
    } else if(x >= c + 1) {
      disable_(2 * i + 1, c + 1, b, x);
    }
    update(i);
  }

  void disable(int x) {
    return disable_(1, 0, n - 1, x);
  }

  void add__(int i, li d) {
    if(A[i].count) A[i].value += d;
    A[i].delta += d;
    A[i].maxWith += d;
  }

  void add(li d) {
    add__(1,d);
  }

  li query() {
    return A[1].count ? A[1].value : -infty;
  }

  void maxWith__(li i, li d){
    A[i].maxWith = max(A[i].maxWith, d);
    if(A[i].count) A[i].value = max(A[i].value, d - A[i].mincost);
  }
  void maxWith(li d){
    maxWith__(1,d);
  }
};


int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,q; cin>>n>>q;
  for(li i = 0; i < (li)(3); ++i) for(li j = 0; j < (li)(n); ++j) cin>>A[i][j];
  for(li i = 0; i < (li)(3); ++i) for(li j = 0; j < (li)(n); ++j) S[i][j+1] = S[i][j]+A[i][j];

  vi K(q);
  vector<vi> OP(n),CL(n);
  for(li i = 0; i < (li)(q); ++i) {
    li l,r; cin>>l>>r>>K[i];
    --l; --r;
    OP[l].emplace_back(i);
    CL[r].emplace_back(i);
  }

  segt st(q);
  for(li i = 0; i < (li)(q); ++i) st.A[st.n+i].mincost = K[i];
  st.build();

  li ans = -infty;
  li last = -infty;
  for(li i = 0; i < (li)(n); ++i) {
    for(int j : OP[i]) {
      st.enable(j);
    }
    st.maxWith(S[0][i+1]);
    st.maxWith(last);
    st.add(A[1][i]);

    last = st.query();
    smax(ans, last + S[2][n] - S[2][i]);

    for(int j : CL[i]) {
      st.disable(j);
    }
  }

  cout << ans << endl;

  return 0;
}