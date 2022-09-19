



 #include <stdio.h>
 #include <bits/stdc++.h>




using namespace std;





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

struct empty_t {};



int ilog2(int x){ return 31 - __builtin_clz(x); }

template <class T>
struct identity : std::unary_function <T, T> {
  T operator() (const T& x) const {return x;}
};

template<class T>
T& smin(T& x, T const& y) { x = min(x,y); }

template <class T>
T& smax(T& x, T const& y) { x = max(x, y); }



struct tree {
  int n, ln;
  int root;

  vector<int> parent;
  vector<vector<int>> cs;
  vector<int> dfs, rdfs;

  vector<int> size, depth;

  vector<vector<int>> lparent;

  vector<int> time_in, time_out;

  template<typename T>
  using lsum = vector<vector<T>>;

  tree() = default;

  void reset() { *this = tree(); }

  void from_graph(int n_, vvi const& G, int root_ = 0) {
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

  void from_parents(int n_, vector<int> const& parent_, int root_ = 0) {
    reset();

    n = n_;
    ln = ilog2(n)+1;
    root = root_;

    parent = parent_;
    for(li i = 0; i < (li)(n); ++i) if(parent[i] != -1) cs[parent[i]].push_back(i);

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
    time_in.assign(n, 0);
    time_out.assign(n, 0);
    do_dfs([&](int i) {
             time_in[i] = time;
             time++;
           }, [](int,int){}, [](int,int){},
      [&](int i){
        time_out[i] = time;
      });
  }

  int lca(int u, int v) const {
    assert(!lparent.empty());
    assert(!depth.empty());
    if(depth[u]<depth[v]) swap(u,v);
    for(li k = (ln-1); k >= (li)(0); --k) if(depth[u] - (1<<k) >= depth[v]) u = lparent[k][u];
    if(u == v) return u;
    for(li k = (ln-1); k >= (li)(0); --k) if(depth[u]>=(1<<k)) {
      if(lparent[k][u] != lparent[k][v]) {
        u = lparent[k][v];
        v = lparent[k][v];
      }
    }
    return lparent[0][u];
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
    assert(!lparent.empty());
    vector<vector<T>> wsum(ln, vector<T>(n, T()));
    for(li i = 0; i < (li)(n); ++i) wsum[0][i] = w[i];
    for(li j = (1); j <= (li)(ln-1); ++j) for(li i = 0; i < (li)(n); ++i) {
      if(lparent[j+1][i] != -1) wsum[j+1][i] = O()(wsum[j][i], wsum[j][lparent[j][i]]);
    }
    return wsum;
  }

  template<class T, class O = std::plus<T>>
  T lwsum_path(vector<vector<T>> const& lwsum, int u, int v) {
    assert(!lwsum.empty());
    assert(!lparent.empty());
    assert(!depth.empty());
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



const li N = 300000;

vi *co0[N], *co1[N];

li wei[N];

inline li getco0(li i, li x) { return x<(int)co0[i]->size() ? (*co0[i])[x] : 0; }
inline li getco1(li i, li x) { return x<(int)co1[i]->size() ? (*co1[i])[x] : getco0(i,x); }

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  vvi G(n); vvii GW(n);
  for(li i = 0; i < (li)(n-1); ++i) {
    li a,b,c; cin>>a>>b>>c;
    --a; --b;
    G[a].emplace_back(b); G[b].emplace_back(a);
    GW[a].emplace_back(b,c); GW[b].emplace_back(a,c);
  }

  tree t;
  t.from_graph(n, G);

  for(li i = 0; i < (li)(n); ++i) for(auto jc : GW[i]) {
    li j,c; tie(j,c) = jc;
    if(j == t.parent[i]) wei[i] = c;
  }
  wei[0] = 1ll<<50;

  t.calc_size();
  t.calc_depth();

  for(int i : t.dfs) {
    if(t.size[i] == 1) {
      co0[i] = new vi;
      co1[i] = new vi;
      co0[i]->emplace_back(wei[i]);
      co1[i]->emplace_back(0);
    }else{
      vector<int> cs = t.cs[i];
      li d = G[i].size();
      int big = cs[0];
      for(int j : cs) if(co0[j]->size()>co0[big]->size()) big = j;
      for(li j = 0; j < (li)(cs.size()); ++j) if(cs[j] == big) { swap(cs[j],cs.back()); cs.pop_back(); }
      co0[i] = co0[big];
      co1[i] = new vi;

    multiset<li> bdelta_left, bdelta_right;
    li sum_left = 0;
    auto get_bdelta = [&](int cnt) {
      while((int)bdelta_left.size() < cnt) {
        auto it = bdelta_right.begin();
        bdelta_left.insert(*it);
        sum_left += *it;
        bdelta_right.erase(it);
      }
      while((int)bdelta_left.size() > cnt) {
        auto it = bdelta_left.rbegin();
        bdelta_right.insert(*it);
        sum_left -= *it;
        bdelta_left.erase(--it.base());
      }
      return sum_left;
    };

    for(li x = (0); x <= (li)(d); ++x) {
      for(li j = 0; j < (li)(cs.size()); ++j) if((int)co0[cs[j]]->size() == x) {
        bdelta_left.insert(wei[cs[j]]);
        sum_left += wei[cs[j]];
        get_bdelta(bdelta_left.size()-1);

        swap(cs[j],cs.back());
        cs.pop_back();
        --j;
      }
      li base = 0;

      vi deltas;
      for(li j = 0; j < (li)(cs.size()); ++j) {
        li c0 = getco0(cs[j],x);
        li c1 = getco1(cs[j],x);
        base += c0;
        deltas.emplace_back(c1-c0+wei[cs[j]]);
      }
      { li c0 = getco0(big,x);
        li c1 = getco1(big,x);
        base += c0;
        deltas.emplace_back(c1-c0+wei[big]);
      }
      deltas.emplace_back(1ll<<50);
      sort(begin(deltas), end(deltas));

      li c1 = 1ll<<50;
      li c0 = 1ll<<50;
      li c1tmp = base;
      { int j = 0;
        if(d == x) c1 = base;
        if(d != x && d-x-1 <= (int)bdelta_left.size()+(int)bdelta_right.size()) c1 = min(c1, c1tmp + get_bdelta(d-x-1));
        if(d-x <= (int)bdelta_left.size()+(int)bdelta_right.size()) c0 = min(c0, c1tmp + get_bdelta(d-x));
        while(j < d-x && j < (int)deltas.size()) {
          c1tmp += deltas[j];
          j++;
          if(d-x-1-j >= 0 && d-x-1-j <= (int)bdelta_left.size()+(int)bdelta_right.size()) c1 = min(c1, c1tmp + get_bdelta(d-x-1-j));
          if(d-x-j <= (int)bdelta_left.size()+(int)bdelta_right.size()) c0 = min(c0, c1tmp + get_bdelta(d-x-j));
        }
      }

      c0 = min(1ll<<50,c0);
      c1 = min(1ll<<50,c1);
      c0 = min(c0,c1+wei[i]);

      if(x==(int)co0[i]->size()) co0[i]->emplace_back();
      if(x==(int)co1[i]->size()) co1[i]->emplace_back();
      (*co0[i])[x] = c0;
      (*co1[i])[x] = c1;
    }

    for(int j : cs) for(li x = (d+1); x <= (li)((int)co0[j]->size()-1); ++x) (*co0[i])[x] += (*co0[j])[x];
    }
  }

  for(li i = 0; i < (li)(n); ++i) {
    cout << (i<(int)co0[0]->size()?(*co0[0])[i]:0) << ' ';
  }
  cout << endl;
  return 0;
}