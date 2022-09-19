


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

li f2(li n) {
  return n*(n+1)/2;
}

const li INFTY = 1e8;

struct node {
  li val, sz;
  li fr, to;
  li delta;
  li sum;

  void set(li i, li x) {
    val=i;
    sz=1;
    fr=to=x;
    sum=x;
    delta=0;
  }

  void combine(node const& a, node const& b) {
    sz = a.sz+b.sz;
    fr = a.fr;
    to = b.sz==0?a.to:b.to;
    delta=0;
    sum=a.sum+b.sum;
  }
};

struct st {
  st() = default;
  st(int n_) : n(2 << ilog2(n_)), A(2 * n) {}

  int n;
  vector<node> A;

  void build() {
    for(li i = (n-1); i >= (li)(1); --i) update(i);
  }
  void update(li i) {
    if(i < n) A[i].combine(A[2*i], A[2*i+1]);
  }
  void push(li i) {
    if(i< n && A[i].delta) {
      add__(2*i, A[i].delta);
      add__(2*i+1, A[i].delta);
      A[i].delta=0;
    }
  }

  void add__(li i, li dx) {
    A[i].fr += dx;
    A[i].to += dx;
    A[i].sum += dx*A[i].sz;
    A[i].delta += dx;
  }

  void add_(int i, int a, int b, int l, int r, li dx) {
    if(l > b || r < a) return;
    push(i);
    if(l <= a && b <= r) {
      add__(i,dx);
      return;
    }
    int c = (a + b) / 2;
    add_(2 * i, a, c, l,r,dx);
    add_(2 * i + 1, c + 1, b, l,r,dx);
    update(i);
  }

  void add(li l, li r, li dx) {
    add_(1, 0, n - 1, l,r, dx);
  }

  li qu_(int i, int a, int b, li x) {
    if(a == b) return A[i].val;
    push(i);
    int c = (a+b)/2;
    if(A[2*i].to >= x) return qu_(2*i,a,c, x);
    else return qu_(2*i+1,c+1,b,x);
  }

  li query(li x) {
    if(A[1].to < x) return -1;
    return qu_(1, 0, n - 1, x);
  }


  li qusum_(int i, int a, int b, int l, int r) {
    if(l > b || r < a) return 0;
    push(i);
    if(l <= a && b <= r) {
      return A[i].sum;
    }
    int c = (a + b) / 2;
    return qusum_(2 * i, a, c, l,r) + qusum_(2 * i + 1, c + 1, b, l,r);
  }

  li qusum(li l, li r) {
    return qusum_(1, 0, n - 1, l,r);
  }

};

const li N = 111'111;
li n,m;
li A[N], B[N];
li suma, sumb;

st ST;

li getb(li x) {
  if(x==0) return B[0];
  else return B[0]+ST.qusum(0,x-1);
}

li solve() {
  li r = suma+sumb;
  li i = 0;
  li j = 0;
  while(i < n-1) {
    li to = ST.query(A[i+1]-A[i]);
    if(to == -1) to = m-1;
    r += (to-j)*A[i];
    j = to;
    r += getb(j);
    i++;
  }
  r += (m-j-1)*A[i];

  return r;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li q; cin>>n>>m>>q;
  for(li i = 0; i < (li)(n); ++i) cin>>A[i];
  for(li i = 0; i < (li)(m); ++i) cin>>B[i];

  suma=accumulate(A,A+n,0ll);
  sumb=accumulate(B,B+m,0ll);

  vi DB(m-1);
  for(li i = 0; i < (li)(m-1); ++i) DB[i] = B[i+1]-B[i];

  ST = st(m);
  for(li i = 0; i < (li)(m-1); ++i) ST.A[ST.n+i].set(i,DB[i]);
  ST.build();

  for(li q_ = 0; q_ < (li)(q); ++q_) {
    li ty,k,d; cin>>ty>>k>>d;

    if(ty == 1) {
      for(li i = 0; i < (li)(k); ++i) A[n-1-i] += (k-i)*d;
      suma += d*f2(k);
    }else{
      sumb += d*f2(k);

      ST.add(m-k-1,m-1, d);
      if(k==m) B[0] += d;


    }

    li r = solve();
    cout << r << '\n';
  }

  return 0;
}