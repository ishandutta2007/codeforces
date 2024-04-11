


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



template<li M = 998244353>
struct Zn {
  static_assert(M > 2, "M > 2");
  static_assert(M < (1ll<<31), "M < (1ll<<31)");
  int value;

  Zn() : value(0) { }

  Zn(int x) : value(x%M) {
    if(value < 0) value += M;
  }

  Zn(li x) : value(x%M) {
    if(value < 0) value += M;
  }

  Zn& operator+=(Zn const& o) {
    value += o.value;
    if(value >= M) value -= M;
    return *this;
  }

  Zn& operator-=(Zn const& o) {
    value += M - o.value;
    if(value >= M) value -= M;
    return *this;
  }

  Zn& operator*=(Zn const& o) {
    value = ((li)value*(li)o.value)%M;
    return *this;
  }

  Zn& operator/=(Zn const& o) {
    return operator*=(o.inverse());
  }

  Zn operator-() const { Zn r; r.value = value ? M-value : 0; return r; }
  Zn operator+(Zn const& o) const { Zn r; r.value = value+o.value; if(r.value>=M) r.value -= M; return r; }
  Zn operator-(Zn const& o) const { Zn r; r.value = value+M-o.value; if(r.value>=M) r.value -= M; return r; }
  Zn operator*(Zn const& o) const { return Zn((li)value * (li)o.value); }
  Zn operator/(Zn const& o) const { Zn a = *this; a /= o; return a; }

  Zn inverse() const {
    int a = value, b = M, u = 0, v = 1;
    while (a != 0) {
      int t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    return Zn(u);
  }

  bool operator==(Zn const& o) const { return value == o.value; }
  bool operator!=(Zn const& o) const { return value != o.value; }
  bool operator<(Zn const& o) const { return value < o.value; }
  bool operator>(Zn const& o) const { return value > o.value; }
  bool operator<=(Zn const& o) const { return value <= o.value; }
  bool operator>=(Zn const& o) const { return value >= o.value; }
};

template<li M>
Zn<M> pow(Zn<M> a, li b) {
  Zn<M> r = 1;
  while(b){
    if(b&1) r = r*a;
    a = a * a;
    b /= 2;
  }
  return r;
}

template<li M>
Zn<M> operator+(int const& x, Zn<M> const& o) { return Zn<M>(x) + o; }
template<li M>
Zn<M> operator+(li const& x, Zn<M> const& o) { return Zn<M>(x) + o; }

template<li M>
Zn<M> operator*(int const& x, Zn<M> const& o) { return Zn<M>(x) * o; }
template<li M>
Zn<M> operator*(li const& x, Zn<M> const& o) { return Zn<M>(x) * o; }

template<li M>
Zn<M> operator/(int const& x, Zn<M> const& o) { return Zn<M>(x) / o; }
template<li M>
Zn<M> operator/(li const& x, Zn<M> const& o) { return Zn<M>(x) / o; }


template<li M>
ostream& operator<<(ostream& ss, Zn<M> const& a) {
  return ss << a.value;
}

template<li M>
istream& operator>>(istream& ss, Zn<M> &a) {
  li x; ss>>x;
  a = Zn<M>(x);
  return ss;
}


template<int N>
struct smatrixZ2 {
  bitset<N> A[N];

  smatrixZ2() { }

  smatrixZ2(int x) {
    for(li i = 0; i < (li)(N); ++i) A[i][i] = x;
  }

  bitset<N> const& operator[](int i) const { return A[i]; }
  bitset<N>& operator[](int i) { return A[i]; }

  smatrixZ2& operator+=(smatrixZ2 const& o) {
    for(li i = 0; i < (li)(N); ++i) A[i] ^= o[i];
    return *this;
  }

  smatrixZ2 operator+(smatrixZ2 const& o) const {
    smatrixZ2 r = *this;
    r += o;
    return r;
  }

  smatrixZ2& operator-=(smatrixZ2 const& o) { return operator+(o); }
  smatrixZ2 operator-(smatrixZ2 const& o) const { return operator+(*this,o); }

  smatrixZ2& operator*=(smatrixZ2 const& o) const {
    static smatrixZ2 r;
    r.reset();
    for(li i = 0; i < (li)(N); ++i) for(li j = 0; j < (li)(N); ++j) if(A[i][j]) r[i] ^= o[j];
    return *this = r;
  }

  smatrixZ2 operator*(smatrixZ2 const& o) const {
    smatrixZ2 r;
    for(li i = 0; i < (li)(N); ++i) for(li j = 0; j < (li)(N); ++j) if(A[i][j]) r[i] ^= o[j];
    return r;
  }
};

template<int N>
ostream operator<<(ostream& os, smatrixZ2<N> const& a) {
  for(li i = 0; i < (li)(N); ++i) os << a[i] << '\n';
  return os;
}

template<int N>
smatrixZ2<N> pow(smatrixZ2<N> a, li b) {
  smatrixZ2<N> r = 1;
  while(b){
    if(b&1) r = r * a;
    a = a * a;
    b /= 2;
  }
  return r;
}

template<class T, int N>
struct svector {
  array<T,N> A;

  svector() { reset(); }

  svector(T const& x) {
    for(li i = 0; i < (li)(N); ++i) A[i] = x;
  }

  void reset() {
    for(li i = 0; i < (li)(N); ++i) A[i] = T();
  }

  T const& operator[](int i) const { return A[i]; }
  T& operator[](int i) { return A[i]; }
};

template<class T, int N>
struct smatrix {
  array<T,N> A[N];

  smatrix() { reset(); }

  smatrix(T const& x) {
    for(li i = 0; i < (li)(N); ++i) A[i][i] = x;
  }

  void reset() {
    for(li i = 0; i < (li)(N); ++i) for(li j = 0; j < (li)(N); ++j) A[i][j] = T();
  }

  array<T,N> const& operator[](int i) const { return A[i]; }
  array<T,N>& operator[](int i) { return A[i]; }

  smatrix& operator+=(smatrix const& o) {
    for(li i = 0; i < (li)(N); ++i) for(li j = 0; j < (li)(N); ++j) A[i][j] += o[i][j];
    return *this;
  }

  smatrix operator+(smatrix const& o) const {
    smatrix r = *this;
    r += o;
    return r;
  }

  smatrix& operator-=(smatrix const& o) {
    for(li i = 0; i < (li)(N); ++i) for(li j = 0; j < (li)(N); ++j) A[i][j] -= o[i][j];
    return *this;
  }

  smatrix operator-(smatrix const& o) const {
    smatrix r = *this;
    r -= o;
    return r;
  }

  smatrix& operator*=(smatrix const& o) const {
    static smatrix r;
    for(li i = 0; i < (li)(N); ++i) for(li j = 0; j < (li)(N); ++j) {
      r[i][j] = T();
      for(li k = 0; k < (li)(N); ++k) r[i][j] += A[i][k] * o[k][j];
    }
    return *this = r;
  }

  smatrix operator*(smatrix const& o) const {
    smatrix r;
    for(li i = 0; i < (li)(N); ++i) for(li j = 0; j < (li)(N); ++j) {
      r[i][j] = T();
      for(li k = 0; k < (li)(N); ++k) r[i][j] += A[i][k] * o[k][j];
    }
    return r;
  }

  svector<T,N> operator*(svector<T,N> const& x) const {
    svector<T,N> y;
    for(li i = 0; i < (li)(N); ++i) for(li j = 0; j < (li)(N); ++j) y[j] += x[i] * A[i][j];
    return y;
  }

  int inv() {
    int n = N;
    vi col(n);
    vector<vector<T>> tmp(n, vector<T>(n));
    for(li i = 0; i < (li)(n); ++i) tmp[i][i] = 1, col[i] = i;

    for(li i = 0; i < (li)(n); ++i) {
      int r = i, c = i;
      for(li j = (i); j <= (li)(n-1); ++j) for(li k = (i); k <= (li)(n-1); ++k) if (A[j][k].value) {
        r = j; c = k; goto found;
      }
      return i;
    found:
      A[i].swap(A[r]); tmp[i].swap(tmp[r]);
      for(li j = 0; j < (li)(n); ++j) swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
      swap(col[i], col[c]);
      T v = T(1)/A[i][i];
      for(li j = (i+1); j <= (li)(n-1); ++j) {
        T f = A[j][i] * v;
        A[j][i] = 0;
        for(li k = (i+1); k <= (li)(n-1); ++k) A[j][k] = (A[j][k] - f*A[i][k]);
        for(li k = (0); k <= (li)(n-1); ++k) tmp[j][k] = (tmp[j][k] - f*tmp[i][k]);
      }
      for(li j = (i+1); j <= (li)(n-1); ++j) A[i][j] = A[i][j] * v;
      for(li j = (0); j <= (li)(n-1); ++j) tmp[i][j] = tmp[i][j] * v;
      A[i][i] = 1;
    }

    for(li i = (n-1); i >= (li)(1); --i) for(li j = (0); j <= (li)(i-1); ++j) {
        T v = A[j][i];
        for(li k = (0); k <= (li)(n-1); ++k) tmp[j][k] = (tmp[j][k] - v*tmp[i][k]);
      }

    for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(n); ++j) A[col[i]][col[j]] = tmp[i][j];
    return n;
  }
};

template<class T, int N>
ostream operator<<(ostream& os, smatrix<T,N> const& a) {
  for(li i = 0; i < (li)(N); ++i) {
    for(li j = 0; j < (li)(N); ++j) os << a[i][j];
    os << '\n';
  }
  return os;
}

template<class T, int N>
smatrix<T,N> pow(smatrix<T,N> a, li b) {
  smatrix<T,N> r = T(1);
  while(b){
    if(b&1) r = r * a;
    a = a * a;
    b /= 2;
  }
  return r;
}

using ZN = Zn<998244353>;
using MN = smatrix<ZN, 512>;
vector<ZN> matMul(vector<vector<ZN>> const& A, vector<ZN> const& B) {
  int n = A.size();
  vector<ZN> R(n, 0);
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(n); ++j) R[j] += A[i][j] * B[i];
  return R;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m; cin>>n>>m;
  vvi G(n);
  for(li i = 0; i < (li)(m); ++i) {
    int u,v; cin>>u>>v;
    --u; --v;
    G[u].push_back(v);
  }

  vi A(n,-1);
  auto grundy = letrec([&](auto grundy, int i) -> void {
    if(A[i] != -1) return;
    set<int> C;
    for(int j : G[i]) { grundy(j); C.insert(A[j]); }
    A[i] = 0;
    while(C.count(A[i])) A[i]++;
  });
  for(li i = 0; i < (li)(n); ++i) grundy(i);

  li K = 512;
  vi cnt(K);
  for(li i = 0; i < (li)(n); ++i) cnt[A[i]]++;

  static MN M; M.reset();
  for(li i = 0; i < (li)(K); ++i) M[i][i] = ZN(1);
  for(li i = 0; i < (li)(K); ++i) for(li j = 0; j < (li)(K); ++j) M[i][i^j] -= ZN(cnt[j]) / ZN(1+n);

  M.inv();
  svector<ZN,512> B; B[0] = ZN(1)/ZN(1+n);
  auto R = M*B;
  cout << ZN(1)-R[0] << endl;







  return 0;
}