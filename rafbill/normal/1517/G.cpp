#pragma GCC optimize ("O3,inline,omit-frame-pointer,no-asynchronous-unwind-tables,fast-math")




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



const li infinity = numeric_limits<li>::max();
struct MaxFlow {

  struct edge {
    edge(li to_, li c_) : to(to_), c(c_), f(0){ }
    li to, c, f;
    edge* rev;
  };

  vector<vector<edge*>> G;

  MaxFlow(li n = 0) : G(n){ }

  li addNode() {
    G.emplace_back();
    return G.size()-1;
  }

  edge* addEdge(li a, li b, li c){
    edge* e1 = new edge(b, c);
    edge* e2 = new edge(a, 0);
    e1->rev = e2; e2->rev = e1;
    G[a].push_back(e1); G[b].push_back(e2);
    return e1;
  }

  vector<edge*> get_minimum_cut(li S){
    int n=G.size();
    vi E(n);
    function<void(int)> dfs = [&](int i){
      if(E[i]) return;
      E[i]=1;
      for(edge* e : G[i]) if(e->f<e->c) dfs(e->to);
    };
    dfs(S);
    vector<edge*> R;
    for(li i = 0; i < (li)(n); ++i) if(E[i]) for(edge* e : G[i]) if(!E[e->to]) R.push_back(e);
    return R;
  }

  li flow(li S, li T){
    li N = G.size();
    li f = 0;
    vi D, W;
    while(1){

      D.assign(N, -1);
      queue<li> Q; Q.push(S); D[S] = 0;
      while(!Q.empty()){
        li i = Q.front(); Q.pop();
        if(i == T) break;
        for(edge *e : G[i]) if(e->c > e->f && D[e->to] == -1){
            D[e->to] = D[i] + 1;
            Q.push(e->to);
          }
      }
      if(D[T] == -1) return f;

      W.assign(N, 0);
      function<li(li, li)> dfs = [&](li i, li f){
        if(i == T) return f;
        li cf = 0;
        for(; W[i] < (li)G[i].size(); W[i]++) {
          edge *e = G[i][W[i]];
          if(e->c > e->f && D[e->to] == D[i] + 1){
            li df = dfs(e->to, min(f, e->c - e->f));
            if(df > 0){
              cf += df;
              f -= df;
              e->f += df;
              e->rev->f -= df;
            }
          }
        }
        return cf;
      };
      while(li df = dfs(S, infinity)) f += df;
    }
  }
};




li ty(li x, li y) {
  if(y&1) {
    if(x&1) return 3;
    else return 2;
  }else{
    if(x&1) return 0;
    else return 1;
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);





  li n; cin>>n;
  map<pii, li> A;
  vi W(n);
  li s = 0;
  for(li i = 0; i < (li)(n); ++i) {
    li x,y,w; cin>>x>>y>>w;
    x += 1'000'000'000ll;
    y += 1'000'000'000ll;
    A[make_tuple(x,y)] = i;
    W[i] = w;
    s += w;
  }


  MaxFlow G(2*n+2);
  li S = 2*n, T = 2*n+1;

  for(auto const& p : A) {
    li x,y; tie(x,y) = p.first;
    li i = p.second;

    G.addEdge(2*i, 2*i+1, W[i]);

    if(ty(x,y) == 0) G.addEdge(S, 2*i, infinity);
    if(ty(x,y) == 3) G.addEdge(2*i+1, T, infinity);

    for(li x2 = (x-1); x2 <= (li)(x+1); ++x2) for(li y2 = (y-1); y2 <= (li)(y+1); ++y2) if(make_tuple(x,y) != make_tuple(x2,y2) && ty(x2,y2) == 1+ty(x,y) && A.count(make_tuple(x2,y2))) {
      li j = A[make_tuple(x2,y2)];
      G.addEdge(2*i+1, 2*j, infinity);
    }
  }

  li r = G.flow(S, T);
  cout << s-r << endl;

  return 0;
}