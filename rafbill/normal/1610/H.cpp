


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



template<class T = li, class PLUS = plus<T>, class MINUS = minus<T>>
struct BIT {
  T zero;
  PLUS plus;

  vector<T> A;
  BIT(li n, T zero_ = T(), PLUS&& plus_ = PLUS()) : zero(zero_), plus(plus_), A(n+1, zero){ }

  T get(li i){
    i += 1;
    T r = zero;
    for(; i > 0; i -= i &-i){
      r = plus(r, A[i]);
    }
    return r;
  }

  void add(li i, T v){
    i += 1;
    for(; i < (li)A.size(); i += i & -i){
      A[i] = plus(A[i],v);
    }
  }
};


const li N = 333'333;
const li LN = 20;

li lpar[LN][N];
li depth[N];
li intime[N];
li outtime[N];

void fail() {
  cout << -1 << endl;
  exit(0);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  li n,m; cin>>n>>m;

  lpar[0][0] = -1;
  vvi G(n);
  for(li i = 0; i < (li)(n-1); ++i) { li p; cin >> p; G[p-1].emplace_back(i+1); lpar[0][i+1] = p-1; }


  for(li j = 0; j < (li)(LN-1); ++j) for(li i = 0; i < (li)(n); ++i) {
    if(lpar[j][i] != -1) { lpar[j+1][i] = lpar[j][lpar[j][i]]; }
    else lpar[j+1][i] = -1;
  }

  int oauzrg = 0;
  auto dfs = letrec([&](auto dfs, int i) -> void {
    intime[i] = oauzrg++;
    depth[i] = lpar[0][i] == -1 ? 0 : 1+depth[lpar[0][i]];
    for(int j : G[i]) dfs(j);
    outtime[i] = oauzrg++;
  });
  dfs(0);

  BIT<li> bit(oauzrg+16);

  auto lca = [&](int i, int j) -> int {
    for(li k = (LN-1); k >= (li)(0); --k) if(depth[i]-(1<<k) >= depth[j]) { i = lpar[k][i]; }
    for(li k = (LN-1); k >= (li)(0); --k) if(depth[j]-(1<<k) >= depth[i]) { j = lpar[k][j]; }
    if(i == j) return i;
    for(li k = (LN-1); k >= (li)(0); --k) if(lpar[k][i] != lpar[k][j]) { i = lpar[k][i]; j = lpar[k][j]; }
    return lpar[0][i];
  };

  auto subtree = [&](int j, int i) -> int {
    for(li k = (LN-1); k >= (li)(0); --k) if(depth[i]-(1<<k) > depth[j]) { i = lpar[k][i]; }
    return i;
  };


  vvi at(n);
  vii rem;

  for(li i = 0; i < (li)(m); ++i) {
    int u,v; cin>>u>>v;
    --u; --v;
    if(depth[u] > depth[v]) swap(u,v);
    int l = lca(u,v);
    if(l == u) {
      at[u].emplace_back(v);
    }else{
      rem.emplace_back(u,v);
    }
  }

  li ans = 0;
  auto dfs0 = letrec([&](auto dfs0, int i) -> void {
    for(int j : G[i]) dfs0(j);
    for(auto j : at[i]) {
      int i2 = subtree(i,j);
      if(i2 == j) fail();


      int count = (bit.get(outtime[i2]+1) - bit.get(intime[i2]))
        - (bit.get(outtime[j]+1) - bit.get(intime[j]));
      if(count == 0) {
        bit.add(intime[i2]+1,1);

        ans += 1;
      }
    }
  });
  dfs0(0);

  bool need = 0;
  for(auto uv : rem) {
    int u,v; tie(u,v) = uv;
    int count = ans - (bit.get(outtime[u]+1)-bit.get(intime[u]))
      - (bit.get(outtime[v]+1)-bit.get(intime[v]));
    if(count == 0) {
      need = 1;
    }
  }

  cout << ans+(need?1:0) << endl;

  return 0;
}