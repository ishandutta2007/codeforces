


 #include <stdio.h>
 #include <bits/extc++.h>





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

li M=2;

struct Zn {
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

Zn pow(Zn a, li b) {
  Zn r = 1;
  while(b){
    if(b&1) r = r*a;
    a = a * a;
    b /= 2;
  }
  return r;
}

Zn operator+(int const& x, Zn const& o) { return Zn(x) + o; }
Zn operator+(li const& x, Zn const& o) { return Zn(x) + o; }

Zn operator*(int const& x, Zn const& o) { return Zn(x) * o; }
Zn operator*(li const& x, Zn const& o) { return Zn(x) * o; }

Zn operator/(int const& x, Zn const& o) { return Zn(x) / o; }
Zn operator/(li const& x, Zn const& o) { return Zn(x) / o; }

struct factorials {
  vector<Zn> F, IF;

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

  Zn operator[](int n) {
    reserve(n+1);
    return F[n];
  }

  Zn I(int n) {
    reserve(n+1);
    return IF[n];
  }
};

static factorials Factorials;

Zn Fact(int n) { return Factorials[n]; }

Zn IFact(int n) { return Factorials.I(n); }

Zn SmallInv(int n) {
  assert(n>=1);
  return IFact(n)*Fact(n-1);
}

Zn cnk(int n, int k) {
  if(k < 0 || k > n) return 0;
  return Fact(n) * IFact(k) * IFact(n-k);
}

struct BinomialRow {
  Zn N;
  vector<Zn> A;

  BinomialRow(Zn N_) {
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

  Zn operator[](int k) {
    if(k >= (int)A.size()) reserve(k);
    return A[k];
  }
};

const int N = 555;
Zn dp1[N];
Zn dp2[N];
Zn dp3[N][N];
Zn dp4[N][N];

Zn f2(Zn x) {
  return x*(x+1)/2;
}

Zn cnkm[N][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m; cin>>m>>n>>M;

  for(li i = 0; i < (li)(N); ++i) for(li j = 0; j < (li)(i+1); ++j) cnkm[i][j] = cnk(i,j);

  dp1[0] = 1;
  for(li i = (1); i <= (li)(n); ++i) for(li j = 0; j < (li)(i); ++j) {
    dp1[i] += dp1[j] * dp1[i-1-j] * cnkm[i-1][j] * (j + (i-1-j) + 2);
  }



  dp2[0] = 0;
  for(li i = (1); i <= (li)(n); ++i) for(li j = 0; j < (li)(i); ++j) {
    dp2[i] += dp1[j] * dp1[i-1-j] * cnkm[i-1][j] * (f2(j) + f2(i-1-j));
    dp2[i] += (dp1[j] * dp2[i-1-j] + dp2[j] * dp1[i-1-j]) * cnkm[i-1][j] * (j + (i-1-j) + 2);
  }

  for(li i = 0; i < (li)(m+1); ++i) dp3[i][0] = 1;
  for(li i = (1); i <= (li)(m); ++i) for(li j = (1); j <= (li)(i); ++j) {
    dp3[i][j] += dp3[i-1][j];
    for(li l = (1); l <= (li)(j-1); ++l) {
      dp3[i][j] += dp1[l] * dp3[i-l-1][j-l] * cnkm[j][l];
    }
    dp3[i][j] += dp1[j];
  }

  for(li i = 0; i < (li)(m+1); ++i) dp4[i][0] = 0;
  for(li i = (1); i <= (li)(m); ++i) for(li j = (1); j <= (li)(i); ++j) {
    dp4[i][j] += dp4[i-1][j];

    for(li l = (1); l <= (li)(j-1); ++l) {
      dp4[i][j] += (dp1[l] * dp4[i-l-1][j-l] + dp2[l] * dp3[i-l-1][j-l]) * cnkm[j][l];
    }

    dp4[i][j] += dp2[j];
  }





  cout << dp4[m][n].value << endl;

  return 0;
}