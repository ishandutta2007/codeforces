


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
  typename tuple_element<0,T>::type& operator^(T& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type const& operator^(T const& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type&& operator^(T&& v, xx_t) { return get<0>(v); }

  template<class T>
  typename tuple_element<1,T>::type& operator^(T& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type const& operator^(T const& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type&& operator^(T&& v, yy_t) { return get<1>(v); }

  template<class T>
  typename tuple_element<2,T>::type& operator^(T& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type const& operator^(T const& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type&& operator^(T&& v, zz_t) { return get<2>(v); }

  template<class T>
  typename tuple_element<3,T>::type& operator^(T& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type const& operator^(T const& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type&& operator^(T&& v, ww_t) { return get<3>(v); }
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

const li N = 333'333;
const li LN = 20;

li parent[LN][N];
li depth[N];

li c_dist[LN][N];
li c_subroot[LN][N];

li centroid_sum[N];
li centroid_cnt[N];
li centroid_s_sum[LN][N];
li centroid_s_cnt[LN][N];

li vl[N];
li rl[N];
li vr[N];
li rr[N];
li sl[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n; cin>>n;
  li m = n+n-1;
  vvi G(m);
  for(li i = 0; i < (li)(n-1); ++i) {
    li u,v; cin>>u>>v;
    u--; v--;
    li w = n+i;
    G[u].push_back(w);
    G[w].push_back(u);
    G[v].push_back(w);
    G[w].push_back(v);
  }

  auto dfs0 = letrec([&](auto dfs0, li i, li p, li d) -> void {
    parent[0][i] = p;
    depth[i] = d;
    for(li j : G[i]) if(j != p){
        dfs0(j,i,d+1);
      }
  });
  dfs0(0,-1,0);
  for(li k = 0; k < (li)(LN-1); ++k) for(li i = 0; i < (li)(m); ++i) {
    if(parent[k][i] != -1) {
      parent[k+1][i] = parent[k][parent[k][i]];
    }else{
      parent[k+1][i] = -1;
    }
  }
  auto lca = [&](li i, li j){
    for(li k = (LN-1); k >= (li)(0); --k) if(depth[i] - (1<<k) >= depth[j]) i = parent[k][i];
    for(li k = (LN-1); k >= (li)(0); --k) if(depth[j] - (1<<k) >= depth[i]) j = parent[k][j];
    if(i == j) return i;
    for(li k = (LN-1); k >= (li)(0); --k) if(parent[k][i] != parent[k][j]) { i = parent[k][i]; j = parent[k][j]; }
    return parent[0][i];
  };
  auto dist = [&](li i, li j){
    li l = lca(i,j);
    return depth[i]+depth[j]-2*depth[l];
  };

  for(li l = 0; l < (li)(LN); ++l) for(li i = 0; i < (li)(n); ++i) c_subroot[l][i] = -1;

  vi CL(m,-1);
  vi CP(m,-1);
  { vi A(m,0);
    for(li l = 0; l < (li)(100); ++l){
      vi E = A;
      vi P(m);
      vi S(m,1);
      function<void(vi&, li,li)> dfs0 = [&](vi& C, li i,li p){
        E[i]=1; P[i]=p; C.push_back(i);
        for(li j : G[i]) if(!A[j] && j!=p) {
            dfs0(C,j,i);
            S[i]+=S[j];
          }
      };
      vi C;
      for(li i = 0; i < (li)(m); ++i) if(!E[i]) {
        C.clear();
        dfs0(C, i, -1);
        auto f = [&](li j){
          li r=0;
          for(auto k : G[j]) if(!A[k] && k!=P[j]) r=max<li>(r,S[k]);
          r=max<li>(r,S[i]-S[j]);
          return r;
        };
        li centroid=i; li best=f(i);
        for(li j : C) {
          li v=f(j); if(v<best) { centroid=j; best=v; }
        }
        A[centroid]=1;
        CL[centroid] = l;
        auto dfs1 = letrec([&](auto dfs1, li i, li p, li subroot) -> void {
          c_subroot[l][i] = subroot;
          for(int j : G[i]) if(!A[j] && j!=p) {
              dfs1(j,i,subroot==-1?j:subroot);
            }
        });
        dfs1(centroid, -1, -1);


        for(li j : C) if(j!=centroid) CP[j]=centroid;
      }
      for(li i = 0; i < (li)(m); ++i) if(!A[i]) goto l_beg;
      break;
    l_beg:;
    }
  }

  for(li i = 0; i < (li)(m); ++i) {
    for(int j = i, l = CL[i]; j != -1; j = CP[j], l -= 1) {
      c_dist[l][i] = dist(i,j);
    }
  }


  auto centroid_add = [&](int i) {
    for(int j = i, l = CL[i]; j != -1; j = CP[j], l -= 1) {
      centroid_sum[j] += c_dist[l][i];
      centroid_cnt[j] += 1;
      if(c_subroot[l][i] != -1) centroid_s_sum[l][c_subroot[l][i]] += c_dist[l][i];
      if(c_subroot[l][i] != -1) centroid_s_cnt[l][c_subroot[l][i]] += 1;
    }
  };
  auto centroid_rem = [&](int i) {
    for(int j = i, l = CL[i]; j != -1; j = CP[j], l -= 1) {
      centroid_sum[j] -= c_dist[l][i];
      centroid_cnt[j] -= 1;
      if(c_subroot[l][i] != -1) centroid_s_sum[l][c_subroot[l][i]] -= c_dist[l][i];
      if(c_subroot[l][i] != -1) centroid_s_cnt[l][c_subroot[l][i]] -= 1;
    }
  };
  auto centroid_get = [&](int i) {
    li ans = 0;
    for(int j = i, l = CL[i]; j != -1; j = CP[j], l -= 1) {
      if(c_subroot[l][i] != -1) centroid_sum[j] -= centroid_s_sum[l][c_subroot[l][i]];
      if(c_subroot[l][i] != -1) centroid_cnt[j] -= centroid_s_cnt[l][c_subroot[l][i]];
      ans += centroid_sum[j] + centroid_cnt[j] * c_dist[l][i];
      if(c_subroot[l][i] != -1) centroid_sum[j] += centroid_s_sum[l][c_subroot[l][i]];
      if(c_subroot[l][i] != -1) centroid_cnt[j] += centroid_s_cnt[l][c_subroot[l][i]];
    }
    return ans;
  };


  auto move_by = [&](int i, int j, int d) {
    int l = lca(i,j);
    int td = depth[i]+depth[j]-2*depth[l];
    assert(d <= td);
    if(d <= depth[i] - depth[l]) {
      for(li k = (LN-1); k >= (li)(0); --k) if((1<<k) <= d) { d -= (1<<k); i = parent[k][i]; }
      assert(i != -1);
      return i;
    }else{
      d = td - d;
      assert(d <= depth[j] - depth[l]);
      for(li k = (LN-1); k >= (li)(0); --k) if((1<<k) <= d) { d -= (1<<k); j = parent[k][j]; }
      assert(j != -1);
      return j;
    }
  };

  auto add = [&](li v, li r, li i) -> pii {
    if(dist(i,v) <= r) return make_tuple(v,r);
    r = (r + dist(i,v))/2;
    return make_tuple(move_by(i,v,r), r);
  };

  auto is_inc = [&](li v1, li r1, li v2, li r2) -> bool {
    assert(v1 != -1);
    assert(v2 != -1);
    return dist(v1, v2) + r1 <= r2;
  };

  li ans = 0;

  auto solve = letrec([&](auto solve, li l, li r) {
    if(l == r) return;
    li m = (l+r)/2;
    solve(l,m); solve(m+1,r);

    vl[m] = m; rl[m] = 0;
    for(li i = (m-1); i >= (li)(l); --i) tie(vl[i],rl[i]) = add(vl[i+1],rl[i+1],i);

    int t1 = m, t2 = m;

    sl[l] = 0;
    for(li i = (l); i <= (li)(m); ++i) sl[i+1] = sl[i] + rl[i];

    vr[m+1] = m+1; rr[m+1] = 0;
    for(li j = (m+1); j <= (li)(r); ++j) {
      if(j != m+1) tie(vr[j],rr[j]) = add(vr[j-1],rr[j-1],j);
      while(t1 >= l && !is_inc(vr[j],rr[j], vl[t1],rl[t1])) {
        centroid_add(vl[t1]);
        t1 -= 1;
      }
      while(t2 >= t1+1 && is_inc(vl[t2],rl[t2], vr[j],rr[j])) {
        centroid_rem(vl[t2]);
        t2 -= 1;
      }
      assert(t1 <= t2);
      ans += 2*(sl[t1+1] - sl[l]);

      ans += sl[t2+1] - sl[t1+1];
      ans += (t2-t1) * rr[j];
      ans += centroid_get(vr[j]);

      ans += 2*rr[j] * (m-t2);
    }

    while(t1 >= l) {
      centroid_add(vl[t1]);
      t1 -= 1;
    }
    while(t2 >= l) {
      centroid_rem(vl[t2]);
      t2 -= 1;
    }
  });

  solve(0,n-1);
  cout << ans/2 << endl;

  return 0;
}