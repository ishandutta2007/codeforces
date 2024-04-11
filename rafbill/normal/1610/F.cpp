



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




using li = int;
using lu = unsigned;
using ld = double;






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
void filter(vector<T>& A, F&& f) {
  auto B = A;
  A.clear();
  for(auto x : B) if(f(x)) A.emplace_back(x);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,m; cin>>n>>m;
  int m0 = m;
  vi fr0(m);

  vi active(m, 1);
  vi fr(m,-1);
  vvii G1(n), G2(n);
  for(li i = 0; i < (li)(m); ++i) {
    li u,v,w; cin>>u>>v>>w;
    --u; --v;
    fr0[i] = u;
    if(w==1) {
      G1[u].emplace_back(v,i);
      G1[v].emplace_back(u,i);
    }else{
      G2[u].emplace_back(v,i);
      G2[v].emplace_back(u,i);
    }
  }

  vector<tuple<int,int,pii,pii,int>> stk;

  vi acn(n,1);
  vi Q;for(li i = 0; i < (li)(n); ++i) Q.emplace_back(i);
  auto push = [&](int i) {
    if(!acn[i]) { acn[i]=1; Q.push_back(i); }
  };
  while(!Q.empty()) {
    int i = Q.back(); Q.pop_back();
    while(G1[i].size() >= 2) {
      if(!active[G1[i][G1[i].size()-1]%yy]) {
        G1[i].pop_back(); continue;
      }
      if(!active[G1[i][G1[i].size()-2]%yy]) {
        swap(G1[i][G1[i].size()-1], G1[i][G1[i].size()-2]);
        G1[i].pop_back();
        continue;
      }

      auto e1 = G1[i].back(); G1[i].pop_back();
      auto e2 = G1[i].back(); G1[i].pop_back();

      active[e1%yy] = 0;
      active[e2%yy] = 0;

      if(e1%xx == e2%xx) {
        fr[e1%yy] = i;
        fr[e2%yy] = e2%xx;
      }else{
        stk.emplace_back(2,i,e1,e2,m);
        G1[e1%xx].emplace_back(e2%xx, m);
        G1[e2%xx].emplace_back(e1%xx, m);

        m += 1;
        active.emplace_back(1);
        fr.emplace_back(-1);

        push(e1%xx);
        push(e2%xx);
      }

    }

    while(G2[i].size() >= 2) {
      if(!active[G2[i][G2[i].size()-1]%yy]) {
        G2[i].pop_back(); continue;
      }
      if(!active[G2[i][G2[i].size()-2]%yy]) {
        swap(G2[i][G2[i].size()-1], G2[i][G2[i].size()-2]);
        G2[i].pop_back();
        continue;
      }

      auto e1 = G2[i].back(); G2[i].pop_back();
      auto e2 = G2[i].back(); G2[i].pop_back();

      active[e1%yy] = 0;
      active[e2%yy] = 0;

      if(e1%xx == e2%xx) {
        fr[e1%yy] = i;
        fr[e2%yy] = e2%xx;
      }else{
        stk.emplace_back(2,i,e1,e2,m);
        G2[e1%xx].emplace_back(e2%xx, m);
        G2[e2%xx].emplace_back(e1%xx, m);

        m += 1;
        active.emplace_back(1);
        fr.emplace_back(-1);

        push(e1%xx);
        push(e2%xx);
      }
    }

  }

  for(li i = 0; i < (li)(n); ++i) {
    filter(G1[i], [&](auto a) { return active[a%yy]; });
    filter(G2[i], [&](auto a) { return active[a%yy]; });
  }

  { li ans = 0;
    for(li i = 0; i < (li)(n); ++i) if(G1[i].size()) ans+=1;
    cout << ans << endl;
  }

  vi vis(n,0);
  for(li i = 0; i < (li)(n); ++i) if(!vis[i] && (G1[i].size()+G2[i].size()) == 1) {
    for(int j = i; ; ) {
      vis[j] = 1;
      if(G1[j].size() && !vis[G1[j][0]%xx]) { fr[G1[j][0]%yy] = j; j = G1[j][0]%xx; }
      else if(G2[j].size() && !vis[G2[j][0]%xx]) { fr[G2[j][0]%yy] = j; j = G2[j][0]%xx; }
      else break;
    }
  }

  for(li i = 0; i < (li)(n); ++i) if(!vis[i] && (G1[i].size() + G2[i].size()) == 2) {
    for(int j = i, p = 0; ;) {
      if(p == 0) { fr[G1[j][0]%yy] = j; j = G1[j][0]%xx; p = 1; }
      else { fr[G2[j][0]%yy] = j; j = G2[j][0]%xx; p = 0; }
      if(j == i) break;
    }
  }

  while(!stk.empty()) {
    int w;
    int i;
    pii e1,e2;
    int ix;
    tie(w,i,e1,e2,ix) = stk.back();
    stk.pop_back();

    if(fr[ix] == (e1%xx)) {
      fr[e1%yy] = e1%xx;
      fr[e2%yy] = i;
    }else{
      fr[e2%yy] = e2%xx;
      fr[e1%yy] = i;
    }
  }

  for(li i = 0; i < (li)(m0); ++i) {
    bool b = (fr[i] == fr0[i]);
    cout << (b?1:2);
  }
  cout << endl;

  return 0;
}