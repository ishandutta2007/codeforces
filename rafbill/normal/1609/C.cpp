


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


struct primes_s {
  vector<int> primes;

  vector<bool> vsieve;
  vector<int> vtotient;
  vector<int> vmoebius;

  primes_s() {
    reserveSieve(16);
  }

  void reserveSieve(int n) {
    if((int)vsieve.size() > n) return;
    n = max<int>(n, 2*vsieve.size());
    int a = vsieve.size();
    vsieve.resize(n, 1); vsieve[0] = vsieve[1] = 0;
    for(li i = (2); i <= (li)(a-1); ++i) if(vsieve[i]) {
      for(int k = i * ((a+i-1)/i); k < n; k += i) vsieve[k] = 0;
    }
    for(li i = (max(2,a)); i <= (li)(n-1); ++i) if(vsieve[i]) {
      primes.push_back(i);
      for(int k = 2*i; k < n; k += i) vsieve[k] = 0;
    }
  }

  void reserveTotient(int n) {
    if((int)vtotient.size() > n) return;
    n = max<int>(n, 2*vtotient.size());
    reserveSieve(n);
    int a = vtotient.size();
    vtotient.resize(n, 1); vtotient[0] = 0; vtotient[1] = 1;
    for(li i = (2); i <= (li)(a-1); ++i) if(vsieve[i]) {
      for(li k = i * ((a+i-1)/i); k < n; k += i) {
          vtotient[k] *= i-1;
        }
      for(li j = i * i; j < n; j *= i) {
        for(li k = j * ((a+j-1)/j); k < n; k += j) {
          vtotient[k] *= i;
        }
      }
    }
    for(li i = (max(2,a)); i <= (li)(n-1); ++i) if(vsieve[i]) {
      for(li k = i; k < n; k += i) {
        vtotient[k] *= (i-1);
      }
      for(li j = i * i; j < n; j *= i) {
        for(li k = j; k < n; k += j) {
          vtotient[k] *= i;
        }
      }
    }
  }

  void reserveMoebius(int n) {
    if((int)vmoebius.size() > n) return;
    n = max<int>(n, 2*vmoebius.size());
    reserveSieve(n);
    int a = vmoebius.size();
    vmoebius.resize(n, 1); vmoebius[0] = 0; vmoebius[1] = 1;
    for(li i = (2); i <= (li)(a-1); ++i) if(vsieve[i]) {
      for(li k = i * ((a+i-1)/i); k < n; k += i) {
          vmoebius[k] *= -1;
        }
      if(i*i < n) {
        for(li k = (i*i) * ((a+(i*i)-1)/(i*i)); k < n; k += i*i) {
          vmoebius[k] = 0;
        }
      }
    }
    for(li i = (max(2,a)); i <= (li)(n-1); ++i) if(vsieve[i]) {
      for(li k = i; k < n; k += i) {
        vmoebius[k] *= -1;
      }
      if(i*i < n) {
        for(li k = i*i; k < n; k += i*i) {
          vmoebius[k] = 0;
        }
      }
    }
  }

  bool is_prime(int n) {
    reserveSieve(n+1);
    return vsieve[n];
  }

  int nth_prime(int n) {
    while(n >= (int)primes.size()) reserveSieve(2*vsieve.size());
    return primes[n];
  }

  int totient(int n) {
    reserveTotient(n+1);
    return vtotient[n];
  }

  int moebius(int n) {
    reserveMoebius(n+1);
    return vmoebius[n];
  }

} primes;

void solve(){
  li n,e; cin>>n>>e;
  vi A(n);
  for(li i = 0; i < (li)(n); ++i) cin>>A[i];


  li ans = 0;
  for(li b = 0; b < (li)(e); ++b) {
    vi C;
    for(li x = b; x < n; x += e) C.emplace_back(x);
    int nc = C.size();
    for(li i = 0; i < (li)(nc); ++i) if(primes.is_prime(A[C[i]])) {
      int j = i; while(j-1 >= 0 && A[C[j-1]]==1) j--;
      int k = i; while(k+1 < nc && A[C[k+1]]==1) k++;
      ans += (k-i+1)*(i-j+1)-1;
    }
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  primes.reserveSieve(1'111'111);
  li t; cin>>t; for(li t_ = 0; t_ < (li)(t); ++t_) solve();

  return 0;
}