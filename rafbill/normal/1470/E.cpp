


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

const int N = 55'555;
const int LN = 17;
const int C = 4;
const li INF = 1'100'000'000'000'000'000ll;

static struct {
  int sz = 0;
  tuple<int,int> A[C+1];
} G[C+1][N+1];
tuple<int,int, li> LTO[LN][C+1][N+1];
li PA[C+1][N+1];

void solve(){
  int n,c,q; scanf("%d%d%d", &n, &c, &q);
  vector<int> P(n); for(li i = 0; i < (li)(n); ++i) { scanf("%d", &P[i]); P[i]--; }


  for(li i = 0; i < (li)(c+1); ++i) for(li j = 0; j < (li)(n+1); ++j) G[i][j].sz = 0;
  for(li i = 0; i < (li)(c+1); ++i) for(li j = 0; j < (li)(n); ++j) {
    for(li k = (0); k <= (li)(i); ++k) {
      if(j+1+k > n) continue;
      G[i][j].A[G[i][j].sz++] = make_tuple(i-k, j+1+k);
    }
    sort(G[i][j].A, G[i][j].A+G[i][j].sz, [&](tuple<int,int> const& ax, tuple<int,int> const& by) {
      li a,x,b,y;
      tie(a,x) = ax;
      tie(b,y) = by;
      return P[x-1] < P[y-1];
    });
  }

  for(li i = 0; i < (li)(c+1); ++i) PA[i][n] = 1;
  for(li i = 0; i < (li)(c+1); ++i) for(li j = (n-1); j >= (li)(0); --j) {
    PA[i][j] = 0;
    for(li iax = 0; iax < (li)(G[i][j].sz); ++iax) {
      int a,x; tie(a,x) = G[i][j].A[iax];
      PA[i][j] += PA[a][x];
      smin(PA[i][j], INF);
    }
  }

  for(li k = 0; k < (li)(LN); ++k) for(li i = 0; i < (li)(c+1); ++i) { LTO[k][i][n] = make_tuple(-1,-1,INF); }
  for(li i = 0; i < (li)(c+1); ++i) for(li j = 0; j < (li)(n); ++j) {
    li cur = 0;
    for(li iax = 0; iax < (li)(G[i][j].sz); ++iax) {
      int a,x; tie(a,x) = G[i][j].A[iax];
      if(a == i) {
        LTO[0][i][j] = make_tuple(a,x,cur);
        break;
      }
      cur += PA[a][x];
      smin(cur, INF);
    }
  }
  for(li k = 0; k < (li)(LN-1); ++k) for(li i = 0; i < (li)(c+1); ++i) for(li j = 0; j < (li)(n); ++j) if(LTO[k][i][j] != make_tuple(-1,-1,INF)) {
    int a,x; li z; tie(a,x,z) = LTO[k][i][j];
    int b,y; li w; tie(b,y,w) = LTO[k][a][x];
    LTO[k+1][i][j] = make_tuple(b,y,min(w+z, INF));
  }else{
    LTO[k+1][i][j] = make_tuple(-1,-1,INF);
  }

  for(li q_ = 0; q_ < (li)(q); ++q_) {
    li i,j;
    scanf("%lld%lld", &i, &j);
    --i; --j;







    int a = c;
    int x = 0;
    vector<tuple<int,int>> revs;
    if(j >= PA[a][x]) {
      printf("-1\n");
      continue;
    }
    int nop = 0;
    while(1) {
      nop++;
      for(li k = (LN-1); k >= (li)(0); --k) {
        int b,y; li z; tie(b,y,z) = LTO[k][a][x];
        if(z <= j && j-z < PA[b][y]) {
          j -= z;
          a = b; x = y;
        }
      }
      if(x == n) break;
      for(li iby = 0; iby < (li)(G[a][x].sz); ++iby) {
        int b,y; tie(b,y) = G[a][x].A[iby];
        if(PA[b][y] <= j) {
          j -= PA[b][y];
        } else {
          revs.emplace_back(x,y);
          a = b; x = y;
          break;
        }
      }
    }
    for(auto p : revs) { int a,b;tie(a,b) = p;reverse(begin(P)+a,begin(P)+b); }
    printf("%d\n", P[i]+1);
    for(auto p : revs) { int a,b;tie(a,b) = p;reverse(begin(P)+a,begin(P)+b); }
  }
}

int main(){
  int t;scanf("%d", &t);for(li i = 0; i < (li)(t); ++i)solve();cout << flush;

  return 0;
}