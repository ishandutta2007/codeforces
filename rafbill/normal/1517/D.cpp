


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

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

li W[500][500][4];

li Q[11][500][500];

li pre[500][500];
li ans[500][500];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,m,k; cin>>n>>m>>k;

  if(k%2!=0) {
    for(li i = 0; i < (li)(n); ++i){
      for(li j = 0; j < (li)(m); ++j) cout << -1 << ' ';
      cout << endl;
    }
    return 0;
  }

  k /= 2;

  for(li i = 0; i < (li)(n); ++i) {
    for(li j = 0; j < (li)(m-1); ++j) {
      li d; cin>>d;
      W[i][j+1][1] =W[i][j][3] = d;
    }
  }

  for(li i = 0; i < (li)(n-1); ++i) {
    for(li j = 0; j < (li)(m); ++j) {
      li d; cin>>d;
      W[i+1][j][0] = W[i][j][2] = d;
    }
  }

  li k1 = (k/2);
  li k2 = ((k+1)/2);

  for(li i0 = 0; i0 < (li)(n); ++i0) for(li j0 = 0; j0 < (li)(m); ++j0) {
    Q[0][i0][j0] = 0;
    for(li ix = 0; ix < (li)(k1); ++ix) {
      for(li i = (i0-ix-1); i <= (li)(i0+ix+1); ++i) for(li j = (j0-ix-1); j <= (li)(j0+ix+1); ++j) if(abs(i0-i)+abs(j0-j) <= ix+1) {
        if(i<0||j<0||i>=n||j>=m) continue;
        Q[ix+1][i][j] = 1ll<<62;
      }
      for(li i = (i0-ix); i <= (li)(i0+ix); ++i) for(li j = (j0-ix); j <= (li)(j0+ix); ++j) if(abs(i0-i)+abs(j0-j) <= ix) {
        if(i<0||j<0||i>=n||j>=m) continue;
        for(li d = 0; d < (li)(4); ++d) {
          li i2 = i+dx[d];
          li j2 = j+dy[d];
          if(i2<0||j2<0||i2==n||j2==m) continue;
          li co2 = Q[ix][i][j]+W[i][j][d];
          smin(Q[ix+1][i2][j2], co2);
        }
      }
    }
    pre[i0][j0] = 1ll<<62;
    for(li i = (i0-k1); i <= (li)(i0+k1); ++i) for(li j = (j0-k1); j <= (li)(j0+k1); ++j) if(abs(i0-i)+abs(j0-j) <= k1) {
      if(i<0||j<0||i>=n||j>=m) continue;
      smin(pre[i0][j0], Q[k1][i][j]);
    }
  }

  for(li i0 = 0; i0 < (li)(n); ++i0) {
    for(li j0 = 0; j0 < (li)(m); ++j0) {
      Q[0][i0][j0] = 0;
      for(li ix = 0; ix < (li)(k2); ++ix) {
        for(li i = (i0-ix-1); i <= (li)(i0+ix+1); ++i) for(li j = (j0-ix-1); j <= (li)(j0+ix+1); ++j) if(abs(i0-i)+abs(j0-j) <= ix+1) {
          if(i<0||j<0||i>=n||j>=m) continue;
          Q[ix+1][i][j] = 1ll<<62;
        }
        for(li i = (i0-ix); i <= (li)(i0+ix); ++i) for(li j = (j0-ix); j <= (li)(j0+ix); ++j) if(abs(i0-i)+abs(j0-j) <= ix) {
          if(i<0||j<0||i>=n||j>=m) continue;
          for(li d = 0; d < (li)(4); ++d) {
            li i2 = i+dx[d];
            li j2 = j+dy[d];
            if(i2<0||j2<0||i2==n||j2==m) continue;
            li co2 = Q[ix][i][j]+W[i][j][d];
            smin(Q[ix+1][i2][j2], co2);
          }
        }
      }
      ans[i0][j0] = 1ll<<62;
      for(li i = (i0-k2); i <= (li)(i0+k2); ++i) for(li j = (j0-k2); j <= (li)(j0+k2); ++j) if(abs(i0-i)+abs(j0-j) <= k2) {
        if(i<0||j<0||i>=n||j>=m) continue;
        smin(ans[i0][j0], Q[k2][i][j] + pre[i][j]);
      }
      cout << 2*ans[i0][j0] << ' ';
    }
    cout << endl;
  }

  return 0;
}