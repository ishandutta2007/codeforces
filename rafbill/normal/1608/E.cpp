


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

template<class T, class F>
vector<T> filter(vector<T> const& v, F&& f){
  vector<T> ret;
  for(auto const& t : v) if(f(t)) ret.emplace_back(t);
  return ret;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n; cin>>n;
  array<array<vii,3>, 2> XS;

  for(li i = 0; i < (li)(n); ++i) {
    li x,y,c; cin>>x>>y>>c;
    --c;
    XS[0][c].emplace_back(x,y);
    XS[1][c].emplace_back(x,y);
  }

  for(li c = 0; c < (li)(3); ++c) sort(begin(XS[0][c]), end(XS[0][c]), [&](auto a, auto b) { return a<b; });
  for(li c = 0; c < (li)(3); ++c) sort(begin(XS[1][c]), end(XS[1][c]), [&](auto a, auto b) { return (a%yy)<(b%yy); });

  auto test3 = [&](li k, li m, vii const& B, vii const& C) -> bool {
    if(k > (li)B.size()) return 0;
    if(((m>>1)&1) == 0) {
      { li x = B[k-1]%xx;
        auto C1 = filter(C, [&](auto p) { return (p%xx) > x;});
        if((li)C1.size() >= k) return 1;
      }
      { li x = B[(li)B.size()-k]%xx;
        auto C1 = filter(C, [&](auto p) { return (p%xx) < x;});
        if((li)C1.size() >= k) return 1;
      }
    }else{
      { li y = B[k-1]%yy;
        auto C1 = filter(C, [&](auto p) { return (p%yy) > y;});
        if((li)C1.size() >= k) return 1;
      }
      { li y = B[(li)B.size()-k]%yy;
        auto C1 = filter(C, [&](auto p) { return (p%yy) < y;});
        if((li)C1.size() >= k) return 1;
      }
    }
    return 0;
  };

  auto test2 = [&](li k, li m, vii const& A, vii const& B, vii const& C) -> bool {
    if((m&1) == 0) {
      { li x = A[k-1]%xx;
        auto B0 = filter(B, [&](auto p) { return (p%xx) > x; });
        auto C0 = filter(C, [&](auto p) { return (p%xx) > x; });
        if(test3(k,m,B0,C0)) return 1;
      }
      { li x = A[(li)A.size()-k]%xx;
        auto B0 = filter(B, [&](auto p) { return (p%xx) < x; });
        auto C0 = filter(C, [&](auto p) { return (p%xx) < x; });
        if(test3(k,m,B0,C0)) return 1;
      }
    }else{
      { li y = A[k-1]%yy;
        auto B0 = filter(B, [&](auto p) { return (p%yy) > y; });
        auto C0 = filter(C, [&](auto p) { return (p%yy) > y; });
        if(test3(k,m,B0,C0)) return 1;
      }
      { li y = A[(li)A.size()-k]%yy;
        auto B0 = filter(B, [&](auto p) { return (p%yy) < y; });
        auto C0 = filter(C, [&](auto p) { return (p%yy) < y; });
        if(test3(k,m,B0,C0)) return 1;
      }
    }
    return 0;
  };

  auto test = [&](li k) -> bool {
    vi I(3); iota(begin(I), end(I), 0);
    do {
      for(li m = 0; m < (li)(4); ++m) {
        if(test2(k, m, XS[m&1][I[0]], XS[(m>>1)&1][I[1]], XS[0][I[2]])) return true;
      }
    }while(next_permutation(begin(I), end(I)));
    return false;
  };

  li lo = 1, hi = n/3;
  while(lo != hi) {
    li mi = (lo+hi+1)/2;
    if(test(mi)) lo = mi;
    else hi = mi-1;
  }
  cout << 3*lo << endl;

  return 0;
}