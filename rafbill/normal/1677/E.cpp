


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

int64_t random(int64_t r) {
  return xorshift128_s.xorshift128()%r;
}

int64_t random(int64_t l, int64_t r) {
  return l + random(r-l+1);
}

ld randomDouble() {
  return (ld)random(2147483648) / 2147483648.0;
}

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

vi solve(li n, li q, vi const& P, vii const& Q) {
  vi IP(n+1);
  for(li i = (1); i <= (li)(n); ++i) IP[P[i]] = i;

  vi L(n+1,0), R(n+1,n+1);

  { vi stk;
    for(li i = (1); i <= (li)(n); ++i) {
      while(!stk.empty() && P[stk.back()] < P[i]) {
        R[stk.back()] = i;
        stk.pop_back();
      }
      stk.push_back(i);
    }
  }

  { vi stk;
    for(li i = (n); i >= (li)(1); --i) {
      while(!stk.empty() && P[stk.back()] < P[i]) {
        L[stk.back()] = i;
        stk.pop_back();
      }
      stk.push_back(i);
    }
  }


  vvii at00(n+2);
  vvii at01(n+2);
  vvii at02(n+2);
  vvii at03(n+2);

  vvii at10(n+2);
  vvii at11(n+2);

  vvii at20(n+2);
  vvii at21(n+2);

  vvii at30(n+2);

  auto add0 = [&](li x, li y, li v0, li v1, li v2, li v3) {
    at00[y].emplace_back(x,v0);
    at01[y].emplace_back(x,v1);
    at02[y].emplace_back(x,v2);
    at03[y].emplace_back(x,v3);
  };

  auto add1 = [&](li x, li y, li v0, li v1) {
    at10[y].emplace_back(x,v0);
    at11[y].emplace_back(x,v1);
  };

  auto add2 = [&](li x, li y, li v0, li v1) {
    at20[y].emplace_back(x,v0);
    at21[y].emplace_back(x,v1);
  };

  auto add3 = [&](li x, li y, li v0) {
    at30[y].emplace_back(x,v0);
  };

  vvii to_add(n+1);

  auto add = [&](li xy, li x, li y) {
    assert(xy != 0 && x != 0 && y != 0);
    if(x > y) swap(x,y);
    x = min(x,xy);
    y = max(y,xy);
    to_add[xy].emplace_back(x,y);
  };

  auto radd = [&](li xy, li x, li y) {
    if(L[xy] >= x || R[xy] <= y) return;
    add0(x, y , 1, x, y, x*y);
    add0(L[xy],y ,-1,-x,-y,-x*y);
    add0(x, R[xy] ,-1,-x,-y,-x*y);
    add0(L[xy],R[xy] , 1, x, y, x*y);

    add1(L[xy],y, 1*(x-L[xy]), y*(x-L[xy]));
    add1(L[xy],R[xy], -1*(x-L[xy]),-y*(x-L[xy]));


    add2(x, R[xy], 1*(R[xy]-y), x*(R[xy]-y));
    add2(L[xy],R[xy], -1*(R[xy]-y),-x*(R[xy]-y));

    add3(L[xy],R[xy], (x-L[xy])*(R[xy]-y));
  };

  for(li x = (1); x <= (li)(n); ++x) for(li y = 1; x*y <= n; y += 1) if(x < y) {
      add(IP[x*y],IP[x],IP[y]);
    }

  for(li xy = (1); xy <= (li)(n); ++xy) {
    sort(begin(to_add[xy]), end(to_add[xy]), [&](auto p1, auto p2) { return get<1>(p1) < get<1>(p2); });
    for(auto [x,y] : to_add[xy]) {
      radd(xy,x,y);
      L[xy] = max(L[xy],x);
    }
  }

  vvii qat(n+2);
  for(li q_ = 0; q_ < (li)(q); ++q_) {
    li l,r; tie(l,r) = Q[q_];
    qat[r].emplace_back(l,q_);
  }

  BIT bit00(n+16);
  BIT bit01(n+16);
  BIT bit02(n+16);
  BIT bit03(n+16);
  BIT bit10(n+16);
  BIT bit11(n+16);
  BIT bit20(n+16);
  BIT bit21(n+16);
  BIT bit30(n+16);

  vi ans(q);

  for(li r = 0; r < (li)(n+2); ++r) {
    for(auto [l,v] : at00[r]) bit00.add(n+2-l, v);
    for(auto [l,v] : at01[r]) bit01.add(n+2-l, v);
    for(auto [l,v] : at02[r]) bit02.add(n+2-l, v);
    for(auto [l,v] : at03[r]) bit03.add(n+2-l, v);
    for(auto [l,v] : at10[r]) bit10.add(n+2-l, v);
    for(auto [l,v] : at11[r]) bit11.add(n+2-l, v);
    for(auto [l,v] : at20[r]) bit20.add(n+2-l, v);
    for(auto [l,v] : at21[r]) bit21.add(n+2-l, v);
    for(auto [l,v] : at30[r]) bit30.add(n+2-l, v);
    for(auto [l,qi] : qat[r]) {
      li v00 = bit00.get(n+2-l);
      li v01 = bit01.get(n+2-l);
      li v02 = bit02.get(n+2-l);
      li v03 = bit03.get(n+2-l);
      li v10 = bit10.get(n+2-l);
      li v11 = bit11.get(n+2-l);
      li v20 = bit20.get(n+2-l);
      li v21 = bit21.get(n+2-l);
      li v30 = bit30.get(n+2-l);
      ans[qi] = 0
        + v00 * (r+1)*(1-l)
        + v01 * (r+1)
        - v02 * (1-l)
        - v03

        + v10 * (r+1)
        - v11

        + v20 * (1-l)
        + v21

        + v30
        ;
    }
  }
  return ans;
}

vi brute(li n, li q, vi const& P, vii const& Q) {
  vi ans(q);
  vvi ans2(n+1,vi(n+1));
  for(li l = (1); l <= (li)(n); ++l) for(li r = (l); r <= (li)(n); ++r) {
    for(li x = (l); x <= (li)(r); ++x) for(li y = (x+1); y <= (li)(r); ++y) {
      int mx = *max_element(begin(P)+x,begin(P)+y+1);
      bool ok = 0;
      for(li z1 = (x); z1 <= (li)(y); ++z1) for(li z2 = (z1+1); z2 <= (li)(y); ++z2) if(P[z1]*P[z2] == mx) ok = 1;
      if(ok) ans2[l][r] += 1;
    }
  }

  for(li qi = 0; qi < (li)(q); ++qi) {
    li l,r; tie(l,r) = Q[qi];
    ans[qi] = ans2[l][r];
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  li n,q; cin>>n>>q;
  vi P(n+1); for(li i = 0; i < (li)(n); ++i) cin>>P[i+1];
  vii Q(q);
  for(li i = 0; i < (li)(q); ++i) {li l,r; cin>>l>>r; Q[i] = make_tuple(l,r);}

  vi ans = solve(n,q,P,Q);





  for(li i = 0; i < (li)(q); ++i){
    cout << ans[i] << '\n';
  }
  cout << flush;



  return 0;
}