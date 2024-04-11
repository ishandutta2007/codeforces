


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

const int N = 222'222;
const int LN = 20;

li E[N];
li uf[N];
li uf_v[N];
li uf_ine[N];

li depth[N];
li lparent[LN][N];
li ltoll[LN][N];

li query(li i, li j) {
  li r = 0;
  for(li k = (LN-1); k >= (li)(0); --k) if(depth[i]-(1ll<<k) >= depth[j]) {
    smax(r, ltoll[k][i]); i=lparent[k][i];
  }
  for(li k = (LN-1); k >= (li)(0); --k) if(depth[j]-(1ll<<k) >= depth[i]) {
    smax(r, ltoll[k][j]); j=lparent[k][j];
  }
  if(i == j) return r;
  for(li k = (LN-1); k >= (li)(0); --k) if(lparent[k][i] != lparent[k][j]) {
    smax(r, ltoll[k][i]); i=lparent[k][i];
    smax(r, ltoll[k][j]); j=lparent[k][j];
  }
  for(li k = 0; k < (li)(1); ++k){
    smax(r, ltoll[k][i]); i=lparent[k][i];
    smax(r, ltoll[k][j]); j=lparent[k][j];
  }
  return r;
}

li find(li i) { return uf[i]==i?i:uf[i]=find(uf[i]); }

void unite(li i, li j){
  li ri = find(i);
  li rj = find(j);
  if(ri == rj) return;
  uf[ri] = rj;
  if(E[uf_v[ri]] > E[uf_v[rj]]) {
    uf_v[rj] = uf_v[ri];
    uf_ine[rj] = uf_ine[ri];
  } else if(E[uf_v[ri]] == E[uf_v[rj]]) {
    uf_ine[rj] = max({uf_ine[rj], uf_ine[ri],query(uf_v[rj],uf_v[ri])});
  }
}

struct edge {
  li fr, to, cap, toll;
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,q; cin>>n>>q;

  for(li i = 0; i < (li)(n); ++i) cin>>E[i];

  vector<edge> ES;
  vector<vector<edge>> G(n);
  for(li i = 0; i < (li)(n-1); ++i) {
    li a,b,c,t;
    cin>>a>>b>>c>>t;
    --a; --b;
    ES.push_back(edge{a,b,c,t});
    G[a].emplace_back(edge{a,b,c,t});
    G[b].emplace_back(edge{b,a,c,t});
  }

  auto dfs = letrec([&](auto dfs, int i, int p) -> void {
    depth[i] = (p==-1)?0:1+depth[p];
    lparent[0][i] = p;
    for(auto const& e : G[i]) if(e.to != p) {
        dfs(e.to,i);
        ltoll[0][e.to] = e.toll;
    }
  });
  dfs(0,-1);

  for(li i = 0; i < (li)(LN-1); ++i) {
    for(li j = 0; j < (li)(n); ++j) {
      if(lparent[i][j] != -1) {
        lparent[i+1][j] = lparent[i][lparent[i][j]];
        ltoll[i+1][j] = max(ltoll[i][j], ltoll[i][lparent[i][j]]);
      }else{
        lparent[i+1][j] = -1;
      }
    }
  }

  vector<tuple<li, li, li>> QS;
  for(li i = 0; i < (li)(q); ++i) {
    li v,x; cin>>v>>x;
    --x;
    QS.emplace_back(v,x,i);
  }
  sort(begin(QS), end(QS));

  for(li i = 0; i < (li)(n); ++i) {
    uf[i] = i;
    uf_v[i] = i;
  }

  vii ans(q);

  auto sol1 = [&](){
    li v,x,i; tie(v,x,i) = QS.back(); QS.pop_back();
    int rx = find(x);
    ans[i] = make_tuple(E[uf_v[rx]], max({uf_ine[rx], query(x, uf_v[rx])}));

  };

  sort(begin(ES), end(ES), [&](edge const& a, edge const& b) { return a.cap > b.cap; });
  for(auto const& e : ES) {
    while(!QS.empty() && (QS.back()%xx > e.cap)) sol1();

    unite(e.fr, e.to);
  }
  while(!QS.empty()) sol1();

  for(li i = 0; i < (li)(q); ++i) {
    li x,y; tie(x,y) = ans[i];
    cout << x << ' ' << y << '\n';
  }
  cout << flush;

  return 0;
}