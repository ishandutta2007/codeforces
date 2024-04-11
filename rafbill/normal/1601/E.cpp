


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



template<class T, class Compare = std::less<T>>
struct rmq {
  vector<T> A;
  Compare cmp;
  int n, ln;
  vector<vector<int>> B;

  rmq() = default;

  rmq(vector<T> const& A_, Compare const& cmp_ = Compare()) : A(A_) {
    cmp = cmp_;
    n = A.size();
    ln = ilog2(n)+1;
    B.assign(ln, vector<int>(n, -1));
    iota(begin(B[0]), end(B[0]),0);
    for(li j = 0; j < (li)(ln-1); ++j) for(li i = 0; i < (li)(n+1-(1<<(j+1))); ++i) {
      if(cmp(A[B[j][i]], A[B[j][i+(1<<j)]])) {
        B[j+1][i] = B[j][i];
      } else {
        B[j+1][i] = B[j][i+(1<<j)];
      }
    }
  }

  int queryIx(int a, int b){
    int d = b-a+1;
    int ld = ilog2(d);
    if(cmp(A[B[ld][a]], A[B[ld][b+1-(1<<ld)]])) {
      return B[ld][a];
    }else{
      return B[ld][b+1-(1<<ld)];
    }
  }

  T query(int a, int b){
    return A[queryIx(a,b)];
  }
};



const li infty = 1e16;

struct segment_tree {

  struct node {
    node(){
      maxVal = infty;
      maxCnt = 1;
      sndMax = -1;
      sum = 0;
      delta = infty;
    }
    li maxVal, maxCnt;
    li sndMax;
    li sum;
    li delta;

    void combine(node &a, node& b) {
      maxVal = max(a.maxVal, b.maxVal);
      maxCnt = 0;
      if(maxVal == a.maxVal) maxCnt += a.maxCnt;
      if(maxVal == b.maxVal) maxCnt += b.maxCnt;
      sndMax = max(a.sndMax,b.sndMax);
      if(maxVal != a.maxVal) sndMax = max(sndMax,a.maxVal);
      if(maxVal != b.maxVal) sndMax = max(sndMax,b.maxVal);
      sum = a.sum+b.sum;
    }
  };

  int n;
  vector<node> A;
  segment_tree() = default;
  segment_tree(int n_) : n((int)1<<(int)(log2(n_)+1)), A(2*n) {
    build();
  }

  void update(int i) {
    if(i < n) {
      A[i].combine(A[2*i],A[2*i+1]);
    }
  }

  void build(){
    for(li i = (n-1); i >= (li)(1); --i) update(i);
  }

  void push(int i, int a, int b){
    if(i < n){
      int c = (a+b)/2;
      if(A[i].delta != infty) {
        setr__(2*i,a,c,A[i].delta);
        setr__(2*i+1,c+1,b,A[i].delta);
        A[i].delta = infty;
      }
    }
  }
  void setr__(int i, int a, int b, li v){
    if(v >= A[i].maxVal) return;
    if(v >= A[i].sndMax) {
      if(A[i].maxVal != infty) {
        A[i].sum -= A[i].maxCnt * A[i].maxVal;
      }
      A[i].maxVal = v;
      A[i].sum += A[i].maxCnt * A[i].maxVal;
      A[i].delta = v;
      return;
    }
    assert(i<n);
    setr___(i,a,b,a,b,v);
  }

  void setr___(int i, int a, int b, li l, li r, li v) {
    int c = (a+b)/2;
    setr_(2*i , a , c, l, r, v);
    setr_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void setr_(int i, int a, int b, int l, int r, li v) {
    if(l > b) return;
    if(r < a) return;
    push(i,a,b);
    if(l <= a && b <= r) { setr__(i, a, b, v); return; }
    setr___(i,a,b,l,r,v);
  }


  void setr(int l, int r, li v){
    setr_(1, 0, n-1, l, r, v);
  }

  li get_(int i, int a, int b, int l, int r) {
    if(l > b) return 0;
    if(r < a) return 0;
    push(i,a,b);
    if(l <= a && b <= r){
      return A[i].sum;
    }
    int c = (a+b)/2;
    return get_(2*i , a , c, l, r) + get_(2*i+1, c+1, b, l, r);
  }


  li get(int l, int r){
    return get_(1, 0, n-1, l, r);
  }
};



struct query {
  li l, r, i;
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,q,k; cin>>n>>q>>k;
  vi A(n); for(li i = 0; i < (li)(n); ++i) cin>>A[i];

  rmq<li> R(A);

  vector<query> Q(q);
  vvi at(n);

  for(li i = 0; i < (li)(q); ++i) {
    li l,r; cin>>l>>r;
    --l; --r;
    auto qu = query { l,r,i };
    Q[i] = qu;
    at[l].emplace_back(i);
  }

  vi ans(q,-1);

  vector<segment_tree> S;
  for(li i = 0; i < (li)(k); ++i) S.emplace_back((n/k)+4);

  for(li i = (n-1); i >= (li)(0); --i) {
    int ik = i%k;
    int jk = i/k;

    li v = R.query(i, min(i+k-1, n-1));

    S[ik].setr(jk, jk, A[i]);
    S[ik].setr(jk+1, (n/k)+3, v);

    for(li qi : at[i]) {
      li r = Q[qi].r;
      li sz = r-i+1;
      li cnt = (sz+k-1)/k;
      ans[qi] = S[ik].get(jk, jk+cnt-1);
    }
  }

  for(li i = 0; i < (li)(q); ++i) cout << ans[i] << '\n';
  cout << flush;

  return 0;
}