


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
Zn<M> invcnk(int n, int k) {
  if(k < 0 || k > n) return 0;
  return IFact(n) * Fact(k) * Fact(n-k);
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



struct BIT {
  vector<li> A;
  BIT(li n) : A(n+1, 0ll){ }

  li get(li i){
    i += 1;
    li r = 0;
    for(; i > 0; i -= i&-i) {
      r += A[i];
    }
    return r;
  }

  li getRange(li l, li r) {
    li ans = get(r);
    if(l) ans = ans - get(l-1);
    return ans;
  }

  void add(li i, li v){
    i += 1;
    for(; i < (li)A.size(); i += i&-i){
      A[i] += v;
    }
  }
};

using ZN = Zn<998244353>;

const int A = 222'222;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,m; cin>>n>>m;
  vi S(n),T(m);
  for(li i = 0; i < (li)(n); ++i) cin>>S[i];
  for(li i = 0; i < (li)(m); ++i) cin>>T[i];

  vi cnt(A); for(li i = 0; i < (li)(n); ++i) cnt[S[i]]++;
  BIT bit(A);
  for(li i = 0; i < (li)(n); ++i) bit.add(S[i], 1);

  ZN ans = 0;
  ZN pfact = 1;
  for(li i = 0; i < (li)(A); ++i) pfact *= IFact(cnt[i]);

  for(li i = 0; i < (li)(m); ++i) {
    if(i == n) {
      ans += 1;
      break;
    }
    ans += ZN(bit.getRange(0,T[i]-1)) * Fact(n-1-i) * pfact;
    if(!cnt[T[i]]) break;
    pfact *= Fact(cnt[T[i]]);
    cnt[T[i]]--;
    pfact *= IFact(cnt[T[i]]);
    bit.add(T[i], -1);
  }

  cout << ans << endl;

  return 0;
}