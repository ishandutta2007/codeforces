#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
#endif
#ifdef ONLINE_JUDGE
#define NDEBUG 1
#endif
#include <stdio.h>
#include <bits/stdc++.h>

#define DESTRUCT2(p, a, b)                      \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);

#define DESTRUCT3(p, a, b, c)                   \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);                           \
  auto c = get<2>(p);

#define DESTRUCT4(p, a, b, c, d)                \
  auto a = get<0>(p);                           \
  auto b = get<1>(p);                           \
  auto c = get<2>(p);                           \
  auto d = get<3>(p);

#define FOR(i, n)     for(lli i = 0; i < (lli)(n); ++i)
#define FORU(i, j, k) for(lli i = (j); i <= (lli)(k); ++i)
#define FORD(i, j, k) for(lli i = (j); i >= (lli)(k); --i)

#define SQ(x) ((x)*(x))

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

using namespace std;

template<typename... As>
struct tpl : public std::tuple<As...> {
  using std::tuple<As...>::tuple;
  tpl(){}
  tpl(std::tuple<As...> const& b) { std::tuple<As...>::operator=(b); }

  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type const&
  x() const { return get<0>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type&
  x() { return get<0>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type const&
  y() const { return get<1>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type&
  y() { return get<1>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type const&
  z() const { return get<2>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type&
  z() { return get<2>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type const&
  w() const { return get<3>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type&
  w() { return get<3>(*this); }
};

using lli   = long long int;
using llu   = long long unsigned;

using pii   = tpl<lli, lli>;
using piii  = tpl<lli, lli, lli>;
using piiii = tpl<lli, lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

template<size_t... I>
struct my_index_sequence {
  using type = my_index_sequence;
  static constexpr array<size_t, sizeof...(I)> value = { {I...} };
};

namespace my_index_sequence_detail {
  template<typename I, typename J> struct concat;
  template<size_t... I, size_t... J>
  struct concat<my_index_sequence<I...>, my_index_sequence<J...> > :
    my_index_sequence<I..., (sizeof...(I)+J)...> { };
  template<size_t N> struct make_index_sequence :
    concat<typename make_index_sequence<N/2>::type, typename make_index_sequence<N-N/2>::type>::type { };
  template <> struct make_index_sequence<0> : my_index_sequence<>{};
  template <> struct make_index_sequence<1> : my_index_sequence<0>{};
}

template<class... A>
using my_index_sequence_for = typename my_index_sequence_detail::make_index_sequence<sizeof...(A)>::type;

template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, my_index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tpl<A...> const& a);
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
ostream& operator<<(ostream& s, tpl<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

//------------------------------------------------------------------------------

// --- BEGIN SNIPPET SEGMENT TREE ---

struct segment_tree {

  struct node {
    node(){}
    lli sum=0;
    lli delta=0;

    void combine(node &a, node& b) {
      sum = a.sum + b.sum;
      delta = 0;
    }
  };

  int n;
  vector<node> A;
  segment_tree(){}
  segment_tree(int n_) : n((int)1<<(int)(log2(n_)+1)), A(2*n) { }

  void update(int i) {
    if(i < n) {
      A[i].combine(A[2*i],A[2*i+1]);
    }
  }

  void build(){
    FORD(i,n-1,1) update(i);
  }

  void push(int i, int a, int b){
    if(i < n){
      int c = (a+b)/2;
      if(A[i].delta){
        add__(2*i  , a,   c, A[i].delta);
        add__(2*i+1, c+1, b, A[i].delta);
        A[i].delta = 0;
      }
    }
  }

  void add__(int i, int a, int b, lli v){
    A[i].sum   += v * (b-a+1);
    A[i].delta += v;
  }

  void add_(int i, int a, int b, int l, int r, lli v) {
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      add__(i, a, b, v);
      return;
    }
    push(i,a,b);
    int c = (a+b)/2;
    add_(2*i  , a  , c, l, r, v);
    add_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void add(int l, int r, lli v){
    add_(1, 0, n-1, l, r, v);
  }

  lli get_(int i, int a, int b, int l, int r) {
    if(l > b) return 0;
    if(r < a) return 0;
    if(l <= a && b <= r){
      return A[i].sum;
    }
    push(i,a,b);
    int c = (a+b)/2;
    return get_(2*i  , a  , c, l, r)+get_(2*i+1, c+1, b, l, r);
  }

  lli get(int l, int r){
    return get_(1, 0, n-1, l, r);
  }
};


// --- END SNIPPET SEGMENT TREE ---


// --- BEGIN SNIPPET TREE ---

#define WITH_HLD 1

struct treechain {
  int root = -1;
  int size = 0;
  vi  nodes;

  treechain() { }

#ifdef WITH_HLD
  using segment = segment_tree; // segment tree / bit / other
  segment A;
  void build(){ A = segment(size); /* make segment tree */ }
#else
  void build(){ }
#endif
};

struct tree {
  int n;
  vvi G;

  int root;
  vi parent;
  vi depth;
  vi size;
  vi order, rorder;
  vii eorder;

  vector<treechain> chains;
  vector<int>       chain;
  vector<int>       chainIx;

  tree(int n_) : n(n_), G(n) { }

  void from_parent(){
    FOR(i,n) {
      int p; cin>>p; --p;
      if(p != -1) G[p].pb(i);
      else root=i;
    }
  }

  void read_graph(istream& input = cin) {
    FOR(i, n-1) {
      int u, v; input >> u >> v;
      u -= 1; v -= 1;
      G[u].pb(v); G[v].pb(u);
    }
  }

  void calcparent() {
    if(parent.empty()) {
      parent.assign(n, -1);
      order.clear();
      vi E(n, 0);
      vector<int> Q; Q.pb(root);
      while(!Q.empty()) {
        int i = Q.back(); Q.pop_back();
        order.pb(i);
        E[i] = 1;
        for(auto j : G[i]) if(!E[j]) {
            parent[j] = i;
            Q.pb(j);
          }
      }
      rorder = order;
      reverse(all(rorder));
    }
  }

  void calcsize() {
    calcparent();
    if(size.empty()) {
      size.assign(n, 1);
      for(auto i : rorder) if(parent[i]!=-1) size[parent[i]] += size[i];
    }
  }

  void calcdepth() {
    calcparent();
    if(depth.empty()) {
      depth.assign(n, 0);
      for(auto i : order) if(parent[i] != -1) depth[i] = depth[parent[i]] + 1;
    }
  }

  void calchld() {
    if(chains.empty()){
      calcsize();
      calcdepth();

      chain.assign(n, -1);
      for(auto i : rorder) {
        int best = -1;
        for(auto j : G[i]) if(j != parent[i]) {
            if(best == -1 || size[j] > size[best]) best = j;
          }
        if(best == -1) {
          chain[i] = chains.size();
          chains.eb();
        }else{
          chain[i] = chain[best];
        }
        chains[chain[i]].size += 1;
      }

      chainIx.assign(n, -1);
      for(auto i : order) {
        if(parent[i]==-1 || chain[i] != chain[parent[i]]) chains[chain[i]].root = i;
        chainIx[i] = chains[chain[i]].nodes.size();
        chains[chain[i]].nodes.pb(i);
      };

      for(auto& c : chains) c.build();
    }
  }

  // O(log n) lca
  int lca(int a, int b) {
    calchld();
    while(chain[a] != chain[b]) {
      if(depth[chains[chain[a]].root]>depth[chains[chain[b]].root]) {
        a = parent[chains[chain[a]].root];
      }else{
        b = parent[chains[chain[b]].root];
      }
    }
    if(depth[a]<depth[b]) return a; else return b;
  }

  int dist(int a, int b) {
    calchld();
    return depth[a]+depth[b]-2*depth[lca(a, b)];
  }

#ifdef WITH_HLD
  // arguments to f :
  // segment, segment range, range in path from a to b (a = 0, b = dist(a, b))
  // the segment range is increasing
  // the range in path can be decreasing
  // O (log n)
  void hld_query(int a, int b, function<void(treechain::segment&, int, int)> const& f) {
    int from = 0, to = dist(a, b);
    while(chain[a] != chain[b]) {
      if(depth[chains[chain[a]].root]>depth[chains[chain[b]].root]) {
        int a_ = parent[chains[chain[a]].root];
        int d = depth[a]-depth[a_];
        f(chains[chain[a]].A, 0, chainIx[a]);
        from += d;
        a = a_;
      }else{
        int b_ = parent[chains[chain[b]].root];
        int d = depth[b]-depth[b_];
        f(chains[chain[b]].A, 0, chainIx[b]);
        to -= d;
        b = b_;
      }
    }
    if(depth[a]==depth[b]) {
      f(chains[chain[a]].A, chainIx[a], chainIx[a]);
    }else if(depth[a]<depth[b]) {
      f(chains[chain[a]].A, chainIx[a], chainIx[b]);
    }else{
      f(chains[chain[a]].A, chainIx[b], chainIx[a]);
    }
  }
#endif
};

// --- END SNIPPET TREE ---


const int N = 500000;
// int parent[N];

// vi brute(int root, vvi const& G) {
//   int n=G.size();
//   vi ANS0(n);
//   vvi A;
//   function<void(int,int)> dfs = [&](int i, int d) {
//     while(d>=(int)A.size()) A.emplace_back();
//     if(i != root) A[d].pb(i);
//     for(int j:G[i]) dfs(j,d+1);
//   };
//   dfs(root,0);
//   vi V(n);
//   for(auto const& v : A) {
//     for(int i:v){
//       int u=parent[i];
//       while(u!=-1) {
//         V[u]++;
//         u=parent[u];
//       }
//     }
//     for(int i:v) {
//       int u=parent[i];
//       while(u!=-1){
//         ANS0[i]+=V[u];
//         u=parent[u];
//       }
//     }
//   }
//   return ANS0;
// }

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  tree tr(n); tr.from_parent();
  tr.calchld();
  vvi A;
  int root = tr.root;
  function<void(int,int)> dfs = [&](int i, int d) {
    while(d>=(int)A.size()) A.emplace_back();
    if(i != root) A[d].pb(i);
    for(int j:tr.G[i]) dfs(j,d+1);
  };
  dfs(root,0);
  vi ANS(n);
  for(auto const& v : A) {
    for(int i : v) {
      tr.hld_query(root,tr.parent[i],[&](segment_tree& st, int l, int r){ st.add(l,r,1); });
    }
    for(int i : v) {
      tr.hld_query(root,tr.parent[i],[&](segment_tree& st, int l, int r){ ANS[i]+=st.get(l,r); });
    }
  }
  FOR(i,n) cout << ANS[i] << ' '; cout << endl;

  // vvi G(n);
  // int root=-1;

  // root=0; parent[root]=-1;
  // FORU(i,1,n-1) {
  //   int p = rand()%i;
  //   parent[i]=p;
  //   G[p].pb(i);
  // }
  // cout << G << endl;

  // // FORU(i,0,n-1) {
  // //   int p; cin>>p; --p;
  // //   parent[i] = p;
  // //   if(p==-1) root=i;
  // //   else G[p].pb(i);
  // // }

  // vi ANS0 = brute(root,G);
  // cout << ANS0 << endl;

  // int cur=0; vi tin(n),tout(n);
  // function<void(int,int)> dfs = [&](int i, int d) {
  //   tin[i] = cur++;
  //   while(d>=(int)A.size()) A.emplace_back();
  //   if(i != root) A[d].pb(i);
  //   for(int j:G[i]) dfs(j,d+1);
  //   tout[i] = cur++;
  // };
  // dfs(root,0);
  // segment_tree st(cur+16);
  // FOR(i,n) st.A[st.n+tin[i]].mult=1;
  // FOR(i,n) st.A[st.n+tout[i]].mult=-1;
  // st.build();
  // vi ANS(n);
  // for(auto const& v : A) {
  //   for(int i : v) {
  //     st.add(tin[root],tin[parent[i]],1);
  //     // st.add(tout[parent[i]],tout[root],1);
  //     cout << i << endl;
  //     FOR(i,n+n) cout << st.get(i,i) << ' '; cout << endl;
  //   }
  //   FOR(i,n+n) cout << st.get(i,i) << ' '; cout << endl;
  //   for(int i : v) {
  //     ANS[i] = st.get(tin[root],tin[parent[i]]);
  //   }
  // }
  // cerr << ANS << " " << ANS0 << endl;
  // assert(ANS == ANS0);
  return 0;
}