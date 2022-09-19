


 #include <stdio.h>
 #include <bits/stdc++.h>






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


int ilog2(int x){ return 31 - __builtin_clz(x); }

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

  int query(int a, int b){
    int d = b-a+1;
    int ld = ilog2(d);
    if(cmp(A[B[ld][a]], A[B[ld][b+1-(1<<ld)]])) {
      return B[ld][a];
    }else{
      return B[ld][b+1-(1<<ld)];
    }
  }
};

struct tree {
  int n, ln;
  int root;

  vector<int> parent;
  vector<vector<int>> cs;
  vector<int> dfs, rdfs;

  vector<int> size, depth;

  vector<vector<int>> lparent;

  vector<int> time_in, time_out;
  vector<int> euler_tour, euler_in;

  rmq<int> lca_rmq;

  template<typename T>
  using lsum = vector<vector<T>>;

  tree() = default;

  void reset() { *this = tree(); }

  void from_graph(int n_, vvi const& G, int root_ = 0) {
    assert(n_ == (int)G.size());
    reset();

    n = n_;
    ln = ilog2(n) + 1;
    root = root_;

    parent.assign(n, -1);
    cs.assign(n, vector<int>());
    dfs.reserve(n);
    rdfs.reserve(n);

    { vector<int> E(n, 0);
      vector<int> Q; Q.push_back(root);
      while(!Q.empty()) {
        int i = Q.back(); Q.pop_back();
        E[i] = 1;
        rdfs.emplace_back(i);
        for(int j : G[i]) if(!E[j]) {
            parent[j] = i;
            cs[i].push_back(j);
            Q.push_back(j);
          }
      }
      for(li i = (n-1); i >= (li)(0); --i) dfs.push_back(rdfs[i]);
    }
  }

  void from_parents(int n_, vector<int> const& parent_) {
    reset();

    vvi G(n_);
    for(li i = 0; i < (li)(n_-1); ++i) {
      G[i+1].push_back(parent_[i]);
      G[parent_[i]].push_back(i+1);
    }

    from_graph(n_, G);
  }

  void calc_size() {
    if(!size.empty()) return;
    size.assign(n,0);
    for (int i : dfs) {
      size[i] = 1;
      for (int j : cs[i]) {
        size[i] += size[j];
      }
    }
  }

  void calc_depth() {
    if(!depth.empty()) return;
    depth.assign(n, 0);
    for(int i : rdfs) {
      if(i == root) depth[i] = 0;
      else depth[i] = 1 + depth[parent[i]];
    }
  }

  void calc_lparent(){
    if(!lparent.empty()) return;
    lparent.assign(ln, vector<int>(n, -1));
    for(li i = 0; i < (li)(n); ++i) lparent[0][i] = parent[i];
    for(li j = 0; j < (li)(ln-1); ++j) for(li i = 0; i < (li)(n); ++i) {
      if (lparent[j][i] != -1) lparent[j+1][i] = lparent[j][lparent[j][i]];
    }
  }

  void do_dfs(function<void(int)> at_in,
              function<void(int,int)> child_in,
              function<void(int,int)> child_out,
              function<void(int)> at_out) {
    vector<int> Q; Q.push_back(2*root+0);
    while(!Q.empty()) {
      int i = Q.back(); Q.pop_back();
      int ty = (i&1); i /= 2;
      if(ty == 0) {
        if(parent[i] != -1) child_in(parent[i],i);
        at_in(i);
        Q.push_back(2*i+1);
        for(int j : cs[i]) Q.push_back(2*j+0);
      }else{
        at_out(i);
        if(parent[i] != -1) child_out(parent[i],i);
      }
    }
  }

  void calc_euler_tour() {
    if(!time_in.empty()) return;
    int time = 0;
    euler_tour.reserve(2*n);
    euler_in.assign(n, 0);
    time_in.assign(n, 0);
    time_out.assign(n, 0);
    do_dfs([&](int i) {
      time_in[i] = time;
      euler_in[i] = euler_tour.size();
      euler_tour.emplace_back(i);
      time++;
    }, [](int,int){},
      [&](int i,int){
        euler_tour.emplace_back(i);
      },
      [&](int i){
        time_out[i] = time;
      });
  }

  void calc_lca() {
    if(lca_rmq.n != 0) return;
    calc_euler_tour();
    lca_rmq = rmq<int>(euler_tour);
  }

  int lca(int u, int v) {
    calc_lca();
    int a = euler_in[u], b = euler_in[v];
    if(a>b) swap(a,b);
    return euler_tour[lca_rmq.query(a,b)];
  }



  template<class T, class O = std::plus<T> >
  vector<T> calc_wsum(vector<T> const& w) {
    assert(w.size() == n);
    vector<T> wsum(n, T());
    for(int i : rdfs) {
      if(parent[i] != -1) wsum[i] = O()(wsum[parent[i]], w[i]);
      else wsum[i] = w[i];
    }
    return wsum;
  }

  template<class T, class O = std::plus<T>, class I = std::negate<T>>
  T wsum_path(vector<T> const& wsum, int u, int v) {
    assert(wsum.size() == n);
    int uv = lca(u,v);
    return O()(O()(wsum[u], wsum[v]), O()(I()(wsum[uv]), I()(wsum[uv])));
  }


  template<class T, class O = std::plus<T> >
  vector<vector<T>> calc_lwsum(vector<T> const& w) {
    assert(w.size() == n);
    calc_lparent();
    vector<vector<T>> wsum(ln, vector<T>(n, T()));
    for(li i = 0; i < (li)(n); ++i) wsum[0][i] = w[i];
    for(li j = (1); j <= (li)(ln-1); ++j) for(li i = 0; i < (li)(n); ++i) {
      if(lparent[j+1][i] != -1) wsum[j+1][i] = O()(wsum[j][i], wsum[j][lparent[j][i]]);
    }
    return wsum;
  }

  template<class T, class O = std::plus<T>>
  T lwsum_path(vector<vector<T>> const& lwsum, int u, int v) {
    calc_lparent();
    calc_depth();
    assert(!lwsum.empty());
    if(depth[u]<depth[v]) swap(u,v);
    T r = T();
    for(li k = (ln-1); k >= (li)(0); --k) if(depth[u] - (1<<k) >= depth[v]) {
      r = O()(r, lwsum[k][u]);
      u = lparent[k][u];
    }
    if(u == v) return r;
    for(li k = (ln-1); k >= (li)(0); --k) if(depth[u]>=(1<<k)) {
      if(lparent[k][u] != lparent[k][v]) {
        r = O()(r, lwsum[k][u]);
        u = lparent[k][v];
        r = O()(r, lwsum[k][v]);
        v = lparent[k][v];
      }
    }
    return r;
  }

};



int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vvii G(n);
  for(li i = 0; i < (li)(n-1); ++i) {
    li u,v,w; cin>>u>>v>>w;
    --u;--v;
    G[u].emplace_back(v,w);
    G[v].emplace_back(u,w);
  }
  for(li i = 0; i < (li)(n); ++i) if(G[i].size() == 2) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;

  viii ans;

  vvii lat(n);
  for(li i = 0; i < (li)(n); ++i) for(auto jw : G[i]) {
    li j,w; tie(j,w) = jw;
    function<int(int,int)> dfs = [&](int k, int p) {
      for(auto q : G[k]) if((q^xx) != p) {
          return dfs(q^xx,k);
            }
      return k;
    };
    lat[i].emplace_back(j,dfs(j,i));
  }
  auto ls = [&](int i, int j) {
    vi L;
    for(auto p : lat[i]) if((p^xx) != j) {
        L.emplace_back(p^yy);
        if(L.size() >= 2) return L;
      }
    return L;
  };

  for(li i = 0; i < (li)(n); ++i) for(auto jw : G[i]) {
    li j,w; tie(j,w) = jw;
    if(j<i) continue;
    if(G[i].size() == 1) {
      if(G[j].size() == 1) {
        ans.emplace_back(i,j,w);
      }else{
        vi B = ls(j,i);
        ans.emplace_back(i,B[0],w/2);
        ans.emplace_back(i,B[1],w/2);
        ans.emplace_back(B[0],B[1],-w/2);
      }
    }else if(G[j].size() == 1) {
        vi A = ls(i,j);
        ans.emplace_back(j,A[0],w/2);
        ans.emplace_back(j,A[1],w/2);
        ans.emplace_back(A[0],A[1],-w/2);
    }else{
      vi A = ls(i,j);
      vi B = ls(j,i);
      ans.emplace_back(A[0],B[0],w/2);
      ans.emplace_back(A[1],B[1],w/2);
      ans.emplace_back(A[0],A[1],-w/2);
      ans.emplace_back(B[0],B[1],-w/2);
    }
  }

  cout << ans.size() << endl;
  for(auto p : ans) {
    li i,j,w; tie(i,j,w) = p;
    cout << i+1 << " " << j+1 << " " << w << endl;
  }


  return 0;
}