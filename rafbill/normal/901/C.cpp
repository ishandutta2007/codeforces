#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
#endif
#ifdef ONLINE_JUDGE
#define NDEBUG 1
#endif
#include <stdio.h>
#include <bits/stdc++.h>

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

// --- BEGIN SNIPPET LINK CUT TREE ---

namespace link_cut {

  // change min to change augmentation
  // create edge-node to augment edges

  struct node {
    node(){ }

    node(lli cost_) : cost(cost_){
      mcost = cost;
    }
    lli cost;
    lli mcost;

    node *p = 0, *cs[2] = {0, 0};
    bool isroot() const { return !p||(this!=p->cs[0]&&this!=p->cs[1]); }
    lli  dir() const { return this==p->cs[1]; }

    bool flip = 0;
  };

  void push(node* n){
    if(n->flip){
      swap(n->cs[0], n->cs[1]);
      FOR(i, 2) if(n->cs[i]) n->cs[i]->flip ^= 1;
      n->flip = 0;
    }
  }

  void update(node* n){
    if(n){
      n->mcost = n->cost;
      FOR(i, 2) if(n->cs[i]) n->mcost = min(n->mcost, n->cs[i]->mcost);
    }
  }

  void rotate(node* n){
    lli d = n->dir();
    node *p = n->p, *b = n->cs[1-d];
    if(!p->isroot()) p->p->cs[p->dir()] = n;
    n->p = p->p;
    n->cs[1-d] = p; p->p = n;
    p->cs[d] = b; if(b) b->p = p;
    update(n); update(p); update(n->p);
  }

  void splay(node* n){
    push(n);
    while(!n->isroot()){
      if(n->p->p) push(n->p->p);
      push(n->p); push(n);
      if(n->p->isroot()) {
        rotate(n);
      } else if(n->dir() == n->p->dir()) {
        rotate(n->p); rotate(n);
      }else{
        rotate(n); rotate(n);
      }
    }
  }

  node* leftmost(node* n){
    while(n->cs[0]) n = n->cs[0];
    return n;
  }

  void splice(node* x){
    push(x->p);
    x->p->cs[1] = x;
    update(x->p);
  }

  void expose(node* x){
    { node* y = x; while(y) { splay(y); y = y->p; } }
    { node* y = x; while(y->p) { splice(y); y = y->p; }}
    splay(x);
  }

  void evert(node* n){
    expose(n);
    if(n->cs[0]){
      n->cs[0]->flip ^= 1;
      n->cs[0] = 0;
      update(n);
    }
  }

  void link(node* x, node* y){
    evert(y); y->p = x;
  }

  void cut(node* x, node* y){
    evert(x); expose(y);
    y->cs[0] = 0; x->p = 0;
    update(y);
  }

  node* root(node* n) {
    expose(n); return leftmost(n);
  }

  lli path(node* x, node* y){
    evert(x);
    expose(y);
    return min(y->cs[0]->mcost, y->cost);
  }

}

// --- END SNIPPET LINK CUT TREE ---

const lli N = 500000;
link_cut::node A[N];
link_cut::node E[N];
lli F[N];
lli SF[N+1];
lli R[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n,m; cin>>n>>m;
  vvii G(n);
  FOR(i,m){
    lli u,v; cin>>u>>v;
    --u; --v;
    G[u].pb(mt(v,i));
    G[v].pb(mt(u,i));
  }
  FOR(i,n) {
    A[i] = link_cut::node(i);
  }

  vi AC(n);
  vi EE(n);
  vi C;
  function<void(lli,lli)> dfs = [&](lli i, lli p) {
    EE[i]=1;
    AC[i]=1;
    C.pb(i);
    for(auto e_ : G[i]) {
      lli j,e; tie(j,e) = e_;
      if(j == p) continue;
      if(AC[j]) {
        set<lli> cc;
        lli k = C.size()-1;
        while(1) {
          cc.insert(C[k]);
          if(C[k] == j) break;
          --k;
        }
        lli u=*cc.begin(),v=*cc.rbegin();
        F[v] = max(F[v],u+1);
        // cycle
      }
      if(!EE[j]) dfs(j,i);
    }
    C.pop_back();
    AC[i]=0;
  };
  FOR(i,n) if(!EE[i]) dfs(i,-1);

  FOR(i,n-1) F[i+1] = max(F[i],F[i+1]);

  // lli from = 0;
  // set<lli> curG;
  // auto rem = [&](lli i) {
  //   for(auto e_ : G[i]) {
  //     lli j,e; tie(j,e) = e_;
  //     if(!curG.count(j)) continue;
  //     link_cut::cut(&A[i],&E[e]);
  //     link_cut::cut(&A[j],&E[e]);
  //   }
  //   curG.erase(i);
  //   from = max(from,i+1);
  // };

  // auto add = [&](lli i) {
  //   for(auto e_ : G[i]) {
  //     lli j,e; tie(j,e) = e_;
  //     if(j>i) continue;
  //     if(!curG.count(j)) continue;
  //     if(link_cut::root(&A[i]) == link_cut::root(&A[j])) {
  //       auto v = link_cut::path(&A[i],&A[j]);
  //       if(v <= j) rem(v);
  //       else rem(j);
  //     }
  //     if(curG.count(j)){
  //       E[e] = link_cut::node(n+1);
  //       link_cut::link(&A[i],&E[e]);
  //       link_cut::link(&A[j],&E[e]);
  //     }
  //   }
  //   curG.insert(i);
  // };

  // FOR(i,n) {
  //   add(i);
  //   F[i] = from;
  // }

  FOR(i,n) {
    R[i] = (i==0?0:R[i-1]);
    while(R[i] < n && F[R[i]] <= i) R[i]++;
  }

  FOR(i,n) SF[i+1] = SF[i]+(i-F[i]+1);

  // cout << vi(F,F+n) << endl;
  // cout << vi(R,R+n) << endl;

  lli q; cin>>q;
  vi ANS(q);
  FOR(i,q) {
    lli l,r; cin>>l>>r;
    --l; --r;
    lli t = min(r+1,R[l]);
    lli a = 0;
    a += ((t-l)*(t-l+1))/2;
    if(t <= r) a += (SF[r+1]-SF[t]);
    cout << a << '\n';
  }
  cout << flush;

  return 0;
}