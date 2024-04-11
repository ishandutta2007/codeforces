


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



template<li M = 998244353>
struct factorials {
  vector<Zn<M>> F, IF;

  factorials() {
    F.emplace_back(1); IF.emplace_back(1);
  }

  factorials(int n) {
    F.emplace_back(1); IF.emplace_back(1);
    reserve(n);
  }

  void reserve(int n) {
    if((int)F.size() > n) return;
    smax<int>(n, 2*F.size());
    int a = F.size();
    F.resize(n+1);
    for(li i = (a); i <= (li)(n); ++i) F[i] = i * F[i-1];
    IF.resize(n+1);
    IF[n] = 1/F[n];
    for(li i = (n-1); i >= (li)(a); --i) IF[i] = IF[i+1] * (i+1);
  }

  Zn<M> operator[](int n) {
    reserve(n+1);
    return F[n];
  }

  Zn<M> I(int n) {
    reserve(n+1);
    return IF[n];
  }
};

template<li M = 998244353>
static factorials<M> Factorials;

template<li M = 998244353>
Zn<M> Fact(int n) { return Factorials<M>[n]; }

template<li M = 998244353>
Zn<M> IFact(int n) { return Factorials<M>.I(n); }

template<li M = 998244353>
Zn<M> SmallInv(int n) {
  assert(n>=1);
  return IFact(n)*Fact(n-1);
}

template<li M = 998244353>
Zn<M> cnk(int n, int k) {
  if(k < 0 || k > n) return 0;
  return Fact(n) * IFact(k) * IFact(n-k);
}

template<li M = 998244353>
struct BinomialRow {
  Zn<M> N;
  vector<Zn<M>> A;

  BinomialRow(Zn<M> N_) {
    N = N_;
    A.emplace_back(1);
  }

  void reserve(int k) {
    if(k < (int)A.size()) return;
    int i = A.size()-1;
    A.resize(k+1);
    for(; i <= k; ++i) {
      A[i+1] = A[i] * (N - i) * SmallInv(i+1);
    }
  }

  Zn<M> operator[](int k) {
    if(k >= (int)A.size()) reserve(k);
    return A[k];
  }
};


template<li M>
struct with_ntt {
  static bool has_ntt;
  static Zn<M> prim_root;
  static int MAXN;
  static vector<vector<int>> roots;
  static vector<vector<int>> rroots;

  static void calc_roots(int N) {
    for(;MAXN <= N; MAXN *= 2) {
      li h = pow(prim_root, (998244353 -1)/MAXN).value;
      li ih = (1/Zn<M>(h)).value;
      li w = 1;
      roots.emplace_back(vector<int>(MAXN));
      for(li i = 0; i < (li)(MAXN); ++i) {
        roots.back()[i] = w;
        w = (w*h)%M;
      }
      w = 1;
      rroots.emplace_back(vector<int>(MAXN));
      for(li i = 0; i < (li)(MAXN); ++i) {
        rroots.back()[i] = w;
        w = (w*ih)%M;
      }
    }
  }

  static void ntt(int N, vector<int>& a, bool reverse) {
    assert((N & (N - 1)) == 0);
    calc_roots(N);
    vector<vector<int>> const& aroots = reverse ? rroots : roots;

    for(int m = N; m >= 2; m /= 2){
      int mh = m/2;
      int im = ilog2(mh)+1;
      vector<int> const& aroots0 = aroots[im];
      for(int j = 0; j < N; j += m){
        for(li i = 0; i < (li)(mh); ++i){
          li w = aroots0[i];
          li x = (a[i+j]+a[i+j+mh]);
          if(x >= M) x -= M;
          li y = ((M+a[i+j]-a[i+j+mh]) * w) % M;
          a[i+j] = x;
          a[i+j+mh] = y;
        }
      }
    }

    int i = 0;
    for(li j = (1); j <= (li)(N-2); ++j){
      for(int k = N/2; k > (i^=k); k /= 2);
      if(j<i) swap(a[i],a[j]);
    }
    if(reverse) {
      li IN = (1/Zn<M>(N)).value;
      for(li j = 0; j < (li)(N); ++j) a[j] = ((li)a[j]*IN) % M;
    }
  }
};

template<li M>
int with_ntt<M>::MAXN = 1;

template<li M>
vector<vector<int>> with_ntt<M>::roots;

template<li M>
vector<vector<int>> with_ntt<M>::rroots;

template<li M>
Zn<M> with_ntt<M>::prim_root = 0;

template<li M>
bool with_ntt<M>::has_ntt = false;

template<>
bool with_ntt<119*(1<<23) + 1>::has_ntt = true;
template<>
Zn<119*(1<<23) + 1> with_ntt<119*(1<<23) + 1>::prim_root = 15311432;

template<li M = 998244353>
struct polymod {
  vector<Zn<M>> A;

  polymod() { }

  polymod(int const& x) {
    A = {x};
  }

  polymod(li const& x) {
    A = {x};
  }

  polymod(Zn<M> const& x) {
    A = {x};
  }

  polymod(vector<Zn<M>> const& A_) {
    A = A_;
  }

  void truncate() {
    while(!A.empty() && A.back() == 0) A.pop_back();
  }

  void truncate(int n) {
    while(!A.empty() && (A.back() == 0 || (int)A.size() > n)) A.pop_back();
  }

  Zn<M>& operator[](int i) {
    while(i >= (int)A.size()) A.push_back(0);
    return A[i];
  }

  Zn<M> operator[](int i) const {
    return i<(int)A.size()?A[i]:0;
  }

  int degree() {
    truncate();
    return (int)A.size() - 1;
  }

  polymod& operator+=(polymod const& o) {
    int n = max(A.size(), o.A.size());
    A.resize(n, 0);
    for(li i = 0; i < (li)(o.A.size()); ++i) A[i] += o.A[i];
    truncate();
    return *this;
  }

  polymod operator+(polymod const& o) const {
    polymod r = *this;
    r += o;
    return r;
  }

  polymod& operator-=(polymod const& o) {
    int n = max(A.size(), o.A.size());
    A.resize(n, 0);
    for(li i = 0; i < (li)(o.A.size()); ++i) A[i] -= o.A[i];
    truncate();
    return *this;
  }

  polymod operator-(polymod const& o) const {
    polymod r = *this;
    r -= o;
    return r;
  }

  bool operator==(polymod const& o) const {
    int mi = min(A.size(),o.A.size());
    for(li i = 0; i < (li)(mi); ++i) if(A[i] != o.A[i]) return false;
    for(li i = (mi); i <= (li)(A.size()-1); ++i) if(A[i] != 0) return false;
    for(li i = (mi); i <= (li)(o.A.size()-1); ++i) if(o.A[i] != 0) return false;
    return true;
  }

  static void karatsuba_mul(li const* a, li const* b, li* c1, li* c2, li* d1, li* d2, int n) {
    if(n <= 8) {
      for(li i = 0; i < (li)(2*n); ++i) c1[i] = 0;
      for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(n); ++j) {
        c1[i+j] += a[i] * b[j];
        c1[i+j] %= M;
      }
      return;
    }

    karatsuba_mul(a, b, c1, c2, d1, d2, (n/2));
    karatsuba_mul(a+(n/2), b+(n/2), c1+n, c2+n, d1, d2, (n/2));
    for(li i = 0; i < (li)(n/2); ++i) {
      d1[i] = a[i]+a[(n/2)+i];
      if(d1[i] >= M) d1[i] -= M;
    }
    for(li i = 0; i < (li)(n/2); ++i) {
      d2[i] = b[i]+b[(n/2)+i];
      if(d2[i] >= M) d2[i] -= M;
    }
    karatsuba_mul(d1, d2, c2, c2+n, d1+(n/2), d2+(n/2), (n/2));
    for(li i = 0; i < (li)(n); ++i) d1[i] = M+M+c2[i]-c1[i]-c1[n+i];
    for(li i = 0; i < (li)(n); ++i) {
      c1[i+(n/2)] += d1[i];
      while(c1[i+(n/2)] >= M) c1[i+(n/2)] -= M;
    }
  }

  static polymod mul(polymod const& a, polymod const& b, int n) {
    if(with_ntt<M>::has_ntt) {
      int m = 1; while(m < min(2*n, (int)a.A.size()+(int)b.A.size())) m *= 2;
      static vector<int> aa, bb;
      if((int)aa.size() < m) aa.resize(m);
      if((int)bb.size() < m) bb.resize(m);
      memset(aa.data(), 0, m*sizeof(int));
      memset(bb.data(), 0, m*sizeof(int));
      for(li i = 0; i < (li)(min(n,(int)a.A.size())); ++i) aa[i] = a.A[i].value;
      for(li i = 0; i < (li)(min(n,(int)b.A.size())); ++i) bb[i] = b.A[i].value;
      with_ntt<M>::ntt(m,aa,0);
      with_ntt<M>::ntt(m,bb,0);
      for(li i = 0; i < (li)(m); ++i) aa[i] = ((li)aa[i]*(li)bb[i]) % M;
      with_ntt<M>::ntt(m,aa,1);
      polymod r;
      r.A.resize(min(n,m));
      for(li i = 0; i < (li)(min(n,m)); ++i) r.A[i] = aa[i];
      r.truncate(n);
      return r;
    }else{
      int m = 1;
      while(m < max((int)a.A.size(),(int)b.A.size())) m *= 2;
      static vector<li> aa, bb, c1, c2, d1, d2;
      if((int)aa.size() < m) aa.resize(m);
      if((int)bb.size() < m) bb.resize(m);
      if((int)c1.size() < 2*m) c1.resize(2*m);
      if((int)c2.size() < 2*m) c2.resize(2*m);
      if((int)d1.size() < m) d1.resize(m);
      if((int)d2.size() < m) d2.resize(m);
      memset(aa.data(), 0, m*sizeof(int));
      memset(bb.data(), 0, m*sizeof(int));
      for(li i = 0; i < (li)(min(n,(int)a.A.size())); ++i) aa[i] = a.A[i].value;
      for(li i = 0; i < (li)(min(n,(int)b.A.size())); ++i) bb[i] = b.A[i].value;
      karatsuba_mul(aa.data(),bb.data(),c1.data(),c2.data(),d1.data(),d2.data(),m);
      polymod rr; rr.A.resize(min(n,2*m));
      for(li i = 0; i < (li)(min(n,2*m)); ++i) rr.A[i] = c1[i];
      rr.truncate(n);
      return rr;
    }
  }

  polymod operator*(polymod const& o) const {
    return mul(*this, o, A.size() + o.A.size());
  }

  polymod& operator*=(polymod const& o) {
    return *this = (*this) * o;
  }

  polymod operator*(Zn<M> const& o) const {
    polymod r = *this; r *= o;
    return r;
  }

  polymod& operator*=(Zn<M> const& o) {
    for(li i = 0; i < (li)((int)A.size()); ++i) A[i] *= o;
    return *this;
  }

  polymod operator/(Zn<M> const& o) const {
    auto io = 1/o;
    polymod r = *this; r *= io;
    return r;
  }

  polymod& operator/=(Zn<M> const& o) {
    auto io = 1/o;
    for(li i = 0; i < (li)((int)A.size()); ++i) A[i] *= io;
    return *this;
  }

  static polymod inverse(polymod const& a, int n) {
    assert(a[0] != 0);
    polymod b = 1/a[0];
    int m = 1;
    while(m < n) {
      m *= 2; m = min(m, n);
      b = mul(b, polymod(2) - mul(a,b,m), m);
    }
    b.truncate(n);
    return b;
  }

  static polymod power(polymod a, int k, int n) {
    if(k == 1) return a;
    polymod r = 1;
    while(k) {
      if(k&1) r = mul(r,a,n);
      a = mul(a,a,n);
      k /= 2;
    }
    return r;
  }

  static polymod sqroot(polymod const& a, int n) {
    assert(a[0] == 1);
    polymod b = 1;
    polymod c = 1;
    int m = 1;
    while(m < n) {
      m *= 2; m = min(m, n);
      c = mul(c, polymod(2) - mul(b,c,m), m);
      b = (b + mul(a,c,m)) / Zn<M>(2);
      c = mul(c, polymod(2) - mul(b,c,m), m);
    }
    b.truncate(n);
    return b;
  }

  static polymod root(polymod const& a, int k, int n) {
    assert(a[0] == 1);
    polymod b = 1;
    polymod c = 1;
    int m = 1;
    while(m < n) {
      m *= 2; m = min(m, n);
      c = mul(c, polymod(2) - mul(b,c,m), m);
      auto ck = power(c, k, m) / Zn<M>(k);
      b = mul(b, polymod(Zn<M>(k-1)/Zn<M>(k)) + mul(a, ck, m), m);
      c = mul(c, polymod(2) - mul(b,c,m), m);
    }
    b.truncate(n);
    return b;
  }

  Zn<M> eval(Zn<M> x) {
    Zn<M> y = 1;
    Zn<M> z = 0;
    for(li i = 0; i < (li)(A.size()); ++i) {
      z += A[i] * y;
      y *= x;
    }
    return z;
  }


  static polymod interpolate(vector<Zn<M>> const& x, vector<Zn<M>> const& y) {
    assert(x.size() == y.size());
    polymod r;
    int n = x.size();
    for(li i = 0; i < (li)(n); ++i) {
      polymod a = Zn<M>(y[i]); Zn<M> b = 1;
      for(li j = 0; j < (li)(n); ++j) if(j != i) {
        polymod aa; aa[0] = -x[j]; aa[1] = 1;
        a *= aa;
        b *= (x[i]-x[j]);
      }
      a /= b;
      r += a;
    }
    return r;
  }

};

template<li M>
ostream& operator<<(ostream& ss, polymod<M> const& a) {
  for(li i = 0; i < (li)((int)a.A.size()); ++i) if(a.A[i].value != 0) {
    ss << a.A[i] << " X^" << i;
    if(i+1 != (int)a.A.size()) ss << " + ";
  }
  return ss;
}

using ZN = Zn<>;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  li n; cin>>n;
  vector<string> A(n);
  for(li i = 0; i < (li)(n); ++i) cin>>A[i];

  ZN ans = 0;
  { bool ok = 1;
    for(li i = 0; i < (li)(n); ++i) if(A[i][0] == 'B' || A[i][1] == 'W') { ok = 0; }
    if(ok) ans += 1;
  }
  { bool ok = 1;
    for(li i = 0; i < (li)(n); ++i) if(A[i][0] == 'W' || A[i][1] == 'B') { ok = 0; }
    if(ok) ans += 1;
  }

  map<string, li> cnt;
  for(li i = 0; i < (li)(n); ++i) cnt[A[i]] += 1;

  li b0 = cnt["WW"];
  li b1 = cnt["BB"];
  li k0 = cnt["W?"]+cnt["?W"];
  li k1 = cnt["B?"]+cnt["?B"];
  li kp = cnt["??"];

  li c01 = cnt["WB"];
  li c10 = cnt["BW"];

  polymod PK0; PK0[0] = 1; PK0[1] = 1;
  auto QK0 = polymod<998244353>::power(PK0, k0, k0+1);
  polymod PK1; PK1[0] = 1; PK1[1] = 1;
  auto QK1 = polymod<998244353>::power(PK1, k1, k1+1);
  polymod PKp; PKp[0] = 1; PKp[1] = 2; PKp[2] = 1;
  auto QKp = polymod<998244353>::power(PKp, kp, 2*kp+4);

  auto V = QK0*QK1*QKp;
  int at = b1-b0 + k1+kp;
  if(at >= 0) ans += V[at];


  if(b0==0&&b1==0) {
    ans -= pow(ZN(2),kp);
  }
  cout << ans << endl;

  return 0;
}