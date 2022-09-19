


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

vi solve(li n, li m, viii alles){
  vector<hash_set<li>> G(n);
  viii E;

  vvii H(n);

  vi par2(n);
  for(li i = 0; i < (li)(n); ++i) par2[i] = i;
  vvi T(n);
  for(li i = 0; i < (li)(n); ++i) T[i].emplace_back(i);
  auto find2 = letrec([&](auto find2, li u) -> li {
    return u==par2[u]?u:par2[u]=find2(par2[u]);
  });
  auto unite2 = [&](li w, li u, li v) {
    if(find2(u)==find2(v)) return;
    H[u].emplace_back(v,w);
    H[v].emplace_back(u,w);
    u=find2(u);
    v=find2(v);
    if(T[u].size() > T[v].size()) swap(u,v);
    T[v].insert(end(T[v]),begin(T[u]), end(T[u]));
    par2[u]=v;
  };

  vi par(n);
  for(li i = 0; i < (li)(n); ++i) par[i] = i;
  vvi S(n);
  for(li i = 0; i < (li)(n); ++i) S[i].emplace_back(i);
  auto find = letrec([&](auto find, li u) -> li {
    return u==par[u]?u:par[u]=find(par[u]);
  });
  auto unite = [&](li w, li u, li v) {
    if(find(u)==find(v)) return;
    u=find(u);
    v=find(v);

    par[u] = v;
    auto& Su = S[u];
    auto& Sv = S[v];

    for(li i : Su) for(li j : Sv) if(find2(i) != find2(j)) {
          for(li a : T[i]) for(li b : T[j]) {
              if(G[a].find(b) == G[a].end()) {
                unite2(w,a,b);
                goto l0;
              }
            }
        l0:;
      }

    vi Suv;
    for(li i : Su) if(find2(i)==i) Suv.push_back(i);
    for(li i : Sv) if(find2(i)==i) Suv.push_back(i);
    S[v] = move(Suv);
  };

  vii ES(m);

  for(li i = 0; i < (li)(m); ++i) {
    li u,v,w; tie(u,v,w) = alles[i];
    ES[i] = make_tuple(u,v);
    G[u].insert(v);
    G[v].insert(u);
    E.emplace_back(w,u,v);
  }
  sort(begin(E), end(E));
  for(auto wuv : E) {
    li w,u,v; tie(w,u,v) = wuv;
    unite(w, u,v);
  }

  vi depth(n);
  vvi lpar(20, vi(n, -1));
  vvi lsum(20, vi(n, -1));
  auto dfs = letrec([&](auto dfs, li i, li p, li sm) -> void{
    depth[i] = p==-1?0:1+depth[p];
    lpar[0][i] = p;
    lsum[0][i] = sm;
    for(auto e : H[i]) {
      li j,w; tie(j,w) = e;
      if(j==p)continue;
      dfs(j,i,w);
    }
  });
  dfs(0,-1,0);



  for(li i = 0; i < (li)(19); ++i) for(li j = 0; j < (li)(n); ++j) {
    if(lpar[i][j] != -1) {
      lpar[i+1][j] = lpar[i][lpar[i][j]];
      lsum[i+1][j] = max(lsum[i][j], lsum[i][lpar[i][j]]);
    }
  }

  auto query = [&](li i, li j) -> li {
    li r = -1;
    if(depth[i] < depth[j]) swap(i,j);
    for(li k = (19); k >= (li)(0); --k) if(depth[i] - (1<<k) >= depth[j]) {
      smax(r, lsum[k][i]);
      i=lpar[k][i];
    }
    for(li k = (19); k >= (li)(0); --k) if(depth[j] - (1<<k) >= depth[i]) {
      smax(r, lsum[k][j]);
      j=lpar[k][j];
    }

    if(i==j) return r;
    for(li k = (19); k >= (li)(0); --k) if(lpar[k][i] != lpar[k][j]) {
      smax(r,lsum[k][i]);
      i=lpar[k][i];
      smax(r,lsum[k][j]);
      j=lpar[k][j];
    }
    smax(r, lsum[0][i]);
    smax(r, lsum[0][j]);
    return r;
  };
  vi sol;
  for(auto e : ES) {
    li u,v; tie(u,v) = e;
    sol.emplace_back(query(u,v));
  }
  return sol;
}

vi brute(li n, li m, viii alles){
  vvii G(n);
  vector<hash_set<li>> GG(n);

  viii FS;
  {
    vi par(n);
    for(li i = 0; i < (li)(n); ++i) par[i] = i;
    auto find = letrec([&](auto find, li u) -> li {
      return u==par[u]?u:par[u]=find(par[u]);
    });
    auto unite = [&](li w, li u, li v) {
      if(find(u)==find(v)) return;
      G[u].emplace_back(v,w);
      G[v].emplace_back(u,w);
      u=find(u);
      v=find(v);
      par[u]=v;
    };

    viii E;
    for(li i = 0; i < (li)(m); ++i) {
      li u,v,w; tie(u,v,w) = alles[i];
      GG[u].insert(v);
      GG[v].insert(u);
      E.emplace_back(w,u,v);
    }
    sort(begin(E), end(E));
    for(auto wuv : E) {
      li w,u,v; tie(w,u,v) = wuv;
      unite(w, u,v);
    }

    vi depth(n);
    vvi lpar(20, vi(n, -1));
    vvi lsum(20, vi(n, -1));
    auto dfs = letrec([&](auto dfs, li i, li p, li sm) -> void{
      depth[i] = p==-1?0:1+depth[p];
      lpar[0][i] = p;
      lsum[0][i] = sm;
      for(auto e : G[i]) {
        li j,w; tie(j,w) = e;
        if(j==p)continue;
        dfs(j,i,w);
      }
    });
    dfs(0,-1,0);
    for(li i = 0; i < (li)(19); ++i) for(li j = 0; j < (li)(n); ++j) {
      if(lpar[i][j] != -1) {
        lpar[i+1][j] = lpar[i][lpar[i][j]];
        lsum[i+1][j] = max(lsum[i][j], lsum[i][lpar[i][j]]);
      }
    }
    auto query = [&](li i, li j) -> li {
      li r = -1;
      if(depth[i] < depth[j]) swap(i,j);
      for(li k = (19); k >= (li)(0); --k) if(depth[i] - (1<<k) >= depth[j]) {
        smax(r, lsum[k][i]);
        i=lpar[k][i];
      }
      if(i==j) return r;
      for(li k = (19); k >= (li)(0); --k) if(lpar[k][i] != lpar[k][j]) {
        smax(r,lsum[k][i]);
        i=lpar[k][i];
        smax(r,lsum[k][j]);
        j=lpar[k][j];
      }
      smax(r, lsum[0][i]);
      smax(r, lsum[0][j]);
      return r;
    };

    for(li i = 0; i < (li)(n); ++i) for(li j = (i+1); j <= (li)(n-1); ++j) if(GG[i].find(j) == GG[i].end()) {
      FS.emplace_back(query(i,j),i,j);
    }
    sort(begin(FS), end(FS));
  }

  vvii H(n);
  vi par(n);
  for(li i = 0; i < (li)(n); ++i) par[i] = i;
  auto find = letrec([&](auto find, li u) -> li {
    return u==par[u]?u:par[u]=find(par[u]);
  });
  auto unite = [&](li w, li u, li v) {
    if(find(u)==find(v)) return;
    H[u].emplace_back(v,w);
    H[v].emplace_back(u,w);
    u=find(u);
    v=find(v);
    par[u]=v;
  };

  viii E;
  for(auto p : FS){
    li u,v,w; tie(w,u,v) = p;
    E.emplace_back(w,u,v);
  }
  sort(begin(E), end(E));
  for(auto wuv : E) {
    li w,u,v; tie(w,u,v) = wuv;
    unite(w, u,v);
  }


  vi depth(n);
  vvi lpar(20, vi(n, -1));
  vvi lsum(20, vi(n, -1));
  auto dfs = letrec([&](auto dfs, li i, li p, li sm) -> void{
    depth[i] = p==-1?0:1+depth[p];
    lpar[0][i] = p;
    lsum[0][i] = sm;
    for(auto e : H[i]) {
      li j,w; tie(j,w) = e;
      if(j==p)continue;
      dfs(j,i,w);
    }
  });
  dfs(0,-1,0);
  for(li i = 0; i < (li)(19); ++i) for(li j = 0; j < (li)(n); ++j) {
    if(lpar[i][j] != -1) {
      lpar[i+1][j] = lpar[i][lpar[i][j]];
      lsum[i+1][j] = max(lsum[i][j], lsum[i][lpar[i][j]]);
    }
  }
  auto query = [&](li i, li j) -> li {
    li r = -1;
    if(depth[i] < depth[j]) swap(i,j);
    for(li k = (19); k >= (li)(0); --k) if(depth[i] - (1<<k) >= depth[j]) {
      smax(r, lsum[k][i]);
      i=lpar[k][i];
    }
    if(i==j) return r;
    for(li k = (19); k >= (li)(0); --k) if(lpar[k][i] != lpar[k][j]) {
      smax(r,lsum[k][i]);
      i=lpar[k][i];
      smax(r,lsum[k][j]);
      j=lpar[k][j];
    }
    smax(r, lsum[0][i]);
    smax(r, lsum[0][j]);
    return r;
  };

  vi sol;
  for(auto p : alles) {
    li u,v; tie(u,v,ignore) = p;
    sol.emplace_back(query(u,v));
  }
  return sol;
}

void solve0(){
  li n,m; cin>>n>>m;
  viii alles;
  for(li i = 0; i < (li)(m); ++i) {
    li u,v,w;
    cin>>u>>v>>w;
    --u; --v;
    alles.emplace_back(u,v,w);
  }
  vi sol;
  sol = solve(n,m,alles);
  for(li x : sol) cout << x << ' ';
  cout << '\n';
}
int main(){
  ios::sync_with_stdio(0); cin.tie(0);






  li t; cin>>t; for(li t_ = 0; t_ < (li)(t); ++t_) {

    solve0();
  }
  cout << flush;

  return 0;
}