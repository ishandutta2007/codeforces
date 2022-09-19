


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



template<class T = li, class PLUS = plus<T>, class MINUS = minus<T>>
struct BIT {
  T zero;
  vector<T> A;
  BIT(li n, T zero_ = T()) : zero(zero_), A(n+1, zero){ }

  T get(T i){
    i += 1;
    T r = zero;
    for(; i > 0; i -= i &-i){
      r = PLUS()(r, A[i]);
    }
    return r;
  }

  T getRange(T l, T r) {
    T ans = get(r);
    if(l) ans = MINUS()(ans, get(l-1));
    return ans;
  }

  void add(T i, T v){
    i += 1;
    for(; i < (T)A.size(); i += i & -i){
      A[i] = PLUS()(A[i],v);
    }
  }
};


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



namespace link_cut {




  struct node {
    node(){ }

    node(li cost_, li edge_) : cost(make_tuple(cost_, edge_)){
      mcost = cost;
    }
    pii cost;
    pii mcost;

    node *p = 0, *cs[2] = {0, 0};
    bool isroot() const { return !p||(this!=p->cs[0]&&this!=p->cs[1]); }
    li dir() const { return this==p->cs[1]; }

    bool flip = 0;
  };

  void push(node* n){
    if(n->flip){
      swap(n->cs[0], n->cs[1]);
      for(li i = 0; i < (li)(2); ++i) if(n->cs[i]) n->cs[i]->flip ^= 1;
      n->flip = 0;
    }
  }

  void update(node* n){
    if(n){
      n->mcost = n->cost;
      for(li i = 0; i < (li)(2); ++i) if(n->cs[i]) n->mcost = max(n->mcost, n->cs[i]->mcost);
    }
  }

  void rotate(node* n){
    li d = n->dir();
    node *p = n->p, *b = n->cs[1-d];
    if(!p->isroot()) p->p->cs[p->dir()] = n;
    n->p = p->p;
    n->cs[1-d] = p; p->p = n;
    p->cs[d] = b; if(b) b->p = p;
    update(n); update(p); update(n->p);
  }

  void splay(node* n){
    push(n);
    while(!n->isroot()){
      if(n->p->p) push(n->p->p);
      push(n->p); push(n);
      if(n->p->isroot()) {
        rotate(n);
      } else if(n->dir() == n->p->dir()) {
        rotate(n->p); rotate(n);
      }else{
        rotate(n); rotate(n);
      }
    }
  }

  node* leftmost(node* n){
    while(n->cs[0]) n = n->cs[0];
    return n;
  }

  void splice(node* x){
    push(x->p);
    x->p->cs[1] = x;
    update(x->p);
  }

  void expose(node* x){
    { node* y = x; while(y) { splay(y); y = y->p; } }
    { node* y = x; while(y->p) { splice(y); y = y->p; }}
    splay(x);
  }

  void evert(node* n){
    expose(n);
    if(n->cs[0]){
      n->cs[0]->flip ^= 1;
      n->cs[0] = 0;
      update(n);
    }
  }

  void changecost(node* n, li newcost) {
    evert(n); expose(n);
    get<0>(n->cost) = newcost;
    update(n);
  }

  void link(node* x, node* y){
    evert(y); y->p = x;
  }

  void cut(node* x, node* y){
    evert(x); expose(y);
    y->cs[0] = 0; x->p = 0;
    update(y);
  }

  pii path(node* x, node* y){
    if(x == y) {
      return y->cost;
    }
    evert(x);
    expose(y);
    return max(y->cs[0]->mcost, y->cost);
  }

}




void solve(){
  li n; cin>>n;

  vi A(n,-1);
  vvi G(n);
  vi B(n,-1);
  vvi H(n);

  for(li i = 0; i < (li)(n-1); ++i) {
    cin>>A[i+1]; A[i+1]--;

    G[A[i+1]].push_back(i+1);
  }
  vector<link_cut::node> V(n), E(n-1);

  for(li i = 0; i < (li)(n); ++i) {
    V[i] = link_cut::node(-1, i);
  }

  for(li i = 0; i < (li)(n-1); ++i) {
    cin>>B[i+1]; B[i+1]--;

    H[B[i+1]].push_back(i+1);

    E[i] = link_cut::node(-1, -1);
    link_cut::link(&E[i], &V[i+1]);
    link_cut::link(&E[i], &V[B[i+1]]);
  }


  vi szb(n, 0);
  vi depth(n, 0);
  vi liime(n);
  vi outtime(n);
  li curtime = 0;
  auto dfsB = letrec([&](auto dfsB, li i, li d) -> void {
    depth[i] = d;
    liime[i] = curtime;
    curtime += 1;

    szb[i] = 1;
    for(li j : H[i]) {
      dfsB(j, d+1);
      szb[i] += szb[j];
    }

    outtime[i] = curtime;
    curtime += 1;
  });
  dfsB(0,0);

  BIT<li> bit(2*n+10);

  li cur = 0;
  auto addv = [&](li i) {
    if(bit.getRange(liime[i], outtime[i]) == 0) {

      li d, j; tie(d,j) = link_cut::path(&V[0], &V[i]);
      if(d == -1) {
        cur++;
      } else {
        if(bit.getRange(liime[j]+1, outtime[j]) != 0) {
          cur++;
        }
      }
    }
    bit.add(liime[i], 1);
    link_cut::changecost(&V[i], depth[i]);
  };
  auto remv = [&](li i) {
    bit.add(liime[i], -1);
    link_cut::changecost(&V[i], -1);

    if(bit.getRange(liime[i], outtime[i]) == 0) {
      li d, j; tie(d,j) = link_cut::path(&V[0], &V[i]);
      if(d == -1) {
        cur--;
      } else {
        if(bit.getRange(liime[j]+1, outtime[j]) != 0) {
          cur--;
        }
      }
    }
  };

  li ans = 0;
  auto dfs = letrec([&](auto dfs, li i) -> void {
    addv(i);

    ans = max(ans, cur);
    for(li j : G[i]) {
      dfs(j);
    }
    remv(i);

  });
  dfs(0);

  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int t; cin>>t;
  for(li i = 0; i < (li)(t); ++i) solve();
  cout << flush;
  return 0;
}