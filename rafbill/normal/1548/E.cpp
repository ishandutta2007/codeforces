


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
  auto operator&(T&& v, xx_t) -> decltype(get<0>(forward<T>(v))) { return get<0>(forward<T>(v)); }
  template<class T>
  auto operator&(T&& v, yy_t) -> decltype(get<1>(forward<T>(v))) { return get<1>(forward<T>(v)); }
  template<class T>
  auto operator&(T&& v, zz_t) -> decltype(get<2>(forward<T>(v))) { return get<2>(forward<T>(v)); }
  template<class T>
  auto operator&(T&& v, ww_t) -> decltype(get<3>(forward<T>(v))) { return get<3>(forward<T>(v)); }
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


static struct xorshift128_t {
  uint32_t x, y, z, w;

  xorshift128_t() {
    reset(1);
  }

  inline void reset(uint64_t seed) {

    struct splitmix64_state {
      uint64_t s;

      uint64_t splitmix64() {
        uint64_t result = (s += 0x9E3779B97f4A7C15);
        result = (result ^ (result >> 30)) * 0xBF58476D1CE4E5B9;
        result = (result ^ (result >> 27)) * 0x94D049BB133111EB;
        return result ^ (result >> 31);
      }
    };

    splitmix64_state s { seed };

    x = (uint32_t)s.splitmix64();
    y = (uint32_t)s.splitmix64();
    z = (uint32_t)s.splitmix64();
    w = (uint32_t)s.splitmix64();
  }

  inline uint32_t xorshift128() {
    uint32_t t = x;
    t ^= t << 11;
    t ^= t >> 8;
    x = y; y = z; z = w;
    w ^= w >> 19;
    w ^= t;
    return w;
  }
} xorshift128_s;

void random_reset(li seed = chrono::steady_clock::now().time_since_epoch().count()) { xorshift128_s.reset(seed); }

uint32_t randomInt32() {
  return xorshift128_s.xorshift128();
}

uint64_t randomInt64() {
  return (((uint64_t)randomInt32())<<32ll) | ((uint64_t)randomInt32());
}

li random(li r) {
  return xorshift128_s.xorshift128()%r;
}

li random(li l, li r) {
  return l + random(r-l+1);
}

ld randomDouble() {
  return (ld)random(2147483648) / 2147483648.0;
}



template<class T = li, class PLUS = plus<T>, class MINUS = minus<T>>
struct BIT {
  T zero;
  PLUS plus;

  vector<T> A;
  BIT(li n, T zero_ = T(), PLUS&& plus_ = PLUS()) : zero(zero_), plus(plus_), A(n+1, zero){ }

  T get(T i){
    i += 1;
    T r = zero;
    for(; i > 0; i -= i &-i){
      r = plus(r, A[i]);
    }
    return r;
  }

  void add(T i, T v){
    i += 1;
    for(; i < (T)A.size(); i += i & -i){
      A[i] = plus(A[i],v);
    }
  }
};



template<class T, class Compare = std::less<T>>
struct rmq {
  vector<T> A;
  Compare cmp;
  int n, ln;
  vector<vector<int>> B;

  rmq() = default;

  rmq(vector<T> const& A_, Compare const& cmp_ = Compare()) : A(A_) {
    cmp = cmp_;
    n = A.size();
    ln = ilog2(n)+1;
    B.assign(ln, vector<int>(n, -1));
    iota(begin(B[0]), end(B[0]),0);
    for(li j = 0; j < (li)(ln-1); ++j) for(li i = 0; i < (li)(n+1-(1<<(j+1))); ++i) {
      if(cmp(A[B[j][i]], A[B[j][i+(1<<j)]])) {
        B[j+1][i] = B[j][i];
      } else {
        B[j+1][i] = B[j][i+(1<<j)];
      }
    }
  }

  int queryIx(int a, int b){
    int d = b-a+1;
    int ld = ilog2(d);
    if(cmp(A[B[ld][a]], A[B[ld][b+1-(1<<ld)]])) {
      return B[ld][a];
    }else{
      return B[ld][b+1-(1<<ld)];
    }
  }

  T query(int a, int b){
    return A[queryIx(a,b)];
  }
};

vi pre(li* X, int n) {
  vi O(n, 1ll<<40);

  rmq<li, greater<li>> RMQ(vi(X,X+n));
  vi I(n); iota(begin(I), end(I),0);
  sort(begin(I), end(I), [&](int i, int j){ return X[i]<X[j]; });
  vi J(n); for(li i = 0; i < (li)(n); ++i) J[I[i]] = i;

  BIT L(n, -1ll, [&](li x, li y) { return max(x,y); });
  for(li i = 0; i < (li)(n); ++i) {
    auto j = L.get(J[i]);
    if(j != -1ll){
      if(j+1 == i) O[i] = -(1ll<<40);
      else smin<li>(O[i], RMQ.query(j+1,i-1));
    }
    L.add(J[i], i);
  }

  BIT R(n, n+1, [&](li x, li y) { return min(x,y); });
  for(li i = (n-1); i >= (li)(0); --i) {
    auto j = R.get(J[i]);
    if(j != n+1){
      if(i+1 == j) O[i] = -(1ll<<40);
      else smin<li>(O[i], RMQ.query(i+1,j-1));
    }
    R.add(J[i], i);
  }

  return O;
}

struct s1d {
  struct node {
    node(){}
    int value=0;
    li from=1e17, to=1e17;
  };
  int n; vector<node> A;
  s1d(){}
  s1d(map<li,li> data) : n(1ll<<((li)(1+log2(data.size()+1)))) {
    while(n&&(n/2)>=(int)data.size()) n/=2;
    A.resize(2*n);
    int cur=0;
    for(auto const& p:data){

      A[n+cur].value = p.second;
      A[n+cur].from = A[n+cur].to = p.first;
      cur++;
    }
    build();
  }
  void build(){
    for(li i = (n-1); i >= (li)(1); --i) update(i);
  }
  void update(int i){
    A[i].value=A[2*i].value+A[2*i+1].value;
    A[i].from=A[2*i].from;
    A[i].to=A[2*i+1].to;
  }

  void add0(int i, li x) {
    if(A[i].from>x) return;
    if(A[i].to<x) return;
    A[i].value += 1;
    if(i<n){
      add0(2*i,x);
      add0(2*i+1,x);
    }
  }
  void add(li x){
    add0(1,x);
    assert(A[1].value>0);
  }
  li query0(int i, li x0, li x1) {
    if(A[i].from>x1) return 0;
    if(A[i].to<x0) return 0;
    if(x0<=A[i].from && A[i].to <=x1) return A[i].value;
    return query0(2*i,x0,x1)+query0(2*i+1,x0,x1);
  }
  li query(li x0, li x1) {
    return query0(1,x0,x1);
  }


};

struct s2d {
  struct node {
    node(){}
    map<li,li> data;
    s1d value;
    li from=1e17, to=1e17;
  };
  int n; vector<node> A;
  s2d(map<li,map<li,li> > &&data) : n(1ll<<((li)(1+log2(data.size()+1)))), A(2*n) {
    int cur=0;
    for(auto const& p:data){
      A[n+cur].data = p.second;
      A[n+cur].value = s1d(p.second);
      A[n+cur].from = A[n+cur].to = p.first;
      cur++;
    }
    build();
  }
  void build(){
    for(li i = (n-1); i >= (li)(1); --i) {
      update(i);
    }
  }
  void update(int i){
    A[i].data=A[2*i].data;
    for(auto p : A[2*i+1].data) { A[i].data[p.first]+=p.second; }
    A[2*i].data.clear();
    A[2*i+1].data.clear();
    A[i].value = s1d(A[i].data);
    A[i].from=A[2*i].from;
    A[i].to=A[2*i+1].to;
  }
  void add0(int i, li x, li y) {
    if(A[i].from>x) return;
    if(A[i].to<x) return;
    A[i].value.add(y);
    if(i<n){
      add0(2*i,x,y);
      add0(2*i+1,x,y);
    }
  }
  void add(li x, li y){
    add0(1,x,y);
  }
  li query0(int i, li x0, li x1, li y0, li y1) {
    if(A[i].from>x1) return 0;
    if(A[i].to<x0) return 0;
    if(x0<=A[i].from && A[i].to <=x1) {
      return A[i].value.query(y0,y1);
    }
    return query0(2*i,x0,x1,y0,y1)+query0(2*i+1,x0,x1,y0,y1);
  }
  li query(li x0, li x1, li y0, li y1) {
    return query0(1,x0,x1,y0,y1);
  }
};

const li N = 222'222;
li A[N], B[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,m,x; cin>>n>>m>>x;



  for(li i = 0; i < (li)(n); ++i) cin>>A[i];
  for(li i = 0; i < (li)(m); ++i) cin>>B[i];

  vi XA = pre(A,n);
  vi XB = pre(B,m);

  li ans = 0;

  map<li,map<li,li>> data;
  for(li j = 0; j < (li)(m); ++j) if(XB[j] >= 0) data[XB[j]][B[j]] += 1;
  s2d st(move(data));

  vi IA(n); iota(begin(IA), end(IA),0); sort(begin(IA), end(IA), [&](int i, int j) { return A[i]<A[j]; });
  for(li i0 = (n-1); i0 >= (li)(0); --i0) {
    li i = IA[i0];
    if(x-XA[i]+1 <= x-A[i]) {
      ans += st.query(x-A[i]+1, 1ll<<50, x-XA[i]+1, x-A[i]);
    }

  }





  cout << ans << endl;

  return 0;
}