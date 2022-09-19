



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

const li N = 333'333;
const li LN = 19;

li lpar[LN][N];
li lmax[LN][N];
li depth[N];

pii lca(int i, int j) {
  li r = -1;
  if(depth[i] < depth[j]) swap(i,j);
  for(li k = (LN-1); k >= (li)(0); --k) if(depth[i]-(1ll<<k) >= depth[j]) {
    smax(r, lmax[k][i]); i = lpar[k][i];
  }
  if(i == j) {
    return make_tuple(i,r);
  }
  for(li k = (LN-1); k >= (li)(0); --k) if(lpar[k][i] != lpar[k][j]) {
    r=max({r,lmax[k][i],lmax[k][j]});
    i = lpar[k][i];
    j = lpar[k][j];
  }
  r = max({r,lmax[0][i],lmax[0][j]});
  i = lpar[0][i];
  j = lpar[0][j];
  return make_tuple(i,r);
}

struct node {
  li allI;
  li allMx;

  li i, mx;

  bool dirty = 0;

  node() {
    allI = -1;
    allMx = -1;
    i = -1;
    mx = -1;
  }

  void enable() {
    i = allI; mx = allMx;
    dirty = 1;
  }

  void disable() {
    i = -1; mx = -1;
    dirty = 0;
  }

  void combineBuild(node const& a, node const& b){
    if(a.allI == -1) {
      allI = b.allI; allMx = b.allMx;
    }else if(b.allI == -1) {
      allI = a.allI; allMx = a.allMx;
    }else{
      tie(allI,allMx) = lca(a.allI,b.allI);
      allMx = max({allMx, a.allMx, b.allMx});
    }
  }

  void combine(node const& a, node const& b){
    if(a.i == -1) {
      i = b.i; mx = b.mx;
    }else if(b.i == -1) {
      i = a.i; mx = a.mx;
    }else{
      tie(i,mx) = lca(a.i,b.i);
      mx = max({mx, a.mx, b.mx});
    }
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
      A[i].combineBuild(A[2*i], A[2*i+1]);
    }
  }
  void update(li i) {
    if(i < n) A[i].combine(A[2*i], A[2*i+1]);
  }
  void push(li i){
    if(i<n&&A[i].dirty) {
      A[2*i].enable();
      A[2*i+1].enable();
      A[i].dirty = 0;
    }
  }

  void enable_(int i, int a, int b, int l, int r) {
    if(l <= a && b <= r) {
      A[i].enable();
      return;
    }
    if(i >= n) return;
    if(A[i].dirty) return;
    int c = (a + b) / 2;
    if(r <= c) {
      enable_(2 * i, a, c, l, r);
    } else if(l >= c + 1) {
      enable_(2 * i + 1, c + 1, b, l, r);
    } else {
      enable_(2 * i, a, c, l, r);
      enable_(2 * i + 1, c + 1, b, l, r);
    }
    update(i);
  }

  void enable(int l, int r) {
    return enable_(1, 0, n - 1, l, r);
  }

  void disable_(int i, int a, int b, int l, int r) {
    if(A[i].i == -1) return;
    if(l <= a && b <= r) {
      A[i].disable();
    }
    if(i >= n) return;
    push(i);
    int c = (a + b) / 2;
    if(r <= c) {
      disable_(2 * i, a, c, l, r);
    } else if(l >= c + 1) {
      disable_(2 * i + 1, c + 1, b, l, r);
    } else {
      disable_(2 * i, a, c, l, r);
      disable_(2 * i + 1, c + 1, b, l, r);
    }
    update(i);
  }

  void disable(int l, int r) {
    return disable_(1, 0, n - 1, l, r);
  }
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,q; cin>>n>>q;

  vi E(n-1);
  vi W(n-1);
  vvi G(n);
  for(li i = 0; i < (li)(n-1); ++i) {
    li u,v,w;





    cin>>u>>v>>w;
    --u; --v;

    E[i] = u^v;
    W[i] = w;
    G[u].emplace_back(i);
    G[v].emplace_back(i);
  }

  auto dfs = letrec([&](auto dfs, int i, int p) -> void {
    lpar[0][i] = p;
    depth[i] = p==-1?0:1+depth[p];
    for(int e : G[i]) if(int j = E[e]^i;1) if(j != p) {
        lmax[0][j] = W[e];
        dfs(j,i);
      }
  });
  dfs(0,-1);

  for(li k = 0; k < (li)(LN-1); ++k) for(li i = 0; i < (li)(n); ++i) {
    if(lpar[k][i] == -1) {
      lpar[k+1][i] = -1;
    }else{
      lpar[k+1][i] = lpar[k][lpar[k][i]];
      lmax[k+1][i] = max(lmax[k][i],lmax[k][lpar[k][i]]);
    }
  }

  segt st(n);
  for(li i = 0; i < (li)(n); ++i) st.A[st.n+i].allI = i;
  st.build();

  for(li q_ = 0; q_ < (li)(q); ++q_) {
    li ty;



    cin>>ty;

    if(ty == 1) {



      li l,r; cin>>l>>r;
      --l; --r;

      st.disable(l,r);
      st.enable(l,r);
    }else if(ty == 2) {



      li l,r; cin>>l>>r;
      --l; --r;

      st.disable(l,r);
    }else{



      li x; cin>>x; --x;


      auto r = st.A[1];
      li ans = r.mx;
      if(r.i != -1) smax(ans, lca(x,r.i)%yy);
      cout << ans << '\n';
    }
  }
  cout << flush;

  return 0;
}