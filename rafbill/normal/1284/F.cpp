


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



namespace link_cut {

  pii amin(pii a, pii b) {
    if((a^xx) <= (b^xx)) return a;
    else return b;
  }




  struct node {
    node(){ }

    node(li cost_, li edge_) : cost(make_tuple(cost_, edge_)){
      mcost[0] = mcost[1] = cost;
    }
    pii cost;
    pii mcost[2];

    node *p = 0, *cs[2] = {0, 0};
    bool isroot() const { return !p||(this!=p->cs[0]&&this!=p->cs[1]); }
    li dir() const { return this==p->cs[1]; }

    bool flip = 0;
  };

  void push(node* n){
    if(n->flip){
      swap(n->cs[0], n->cs[1]);
      swap(n->mcost[0], n->mcost[1]);
      for(li i = 0; i < (li)(2); ++i) if(n->cs[i]) n->cs[i]->flip ^= 1;
      n->flip = 0;
    }
  }

  void update(node* n){
    if(n){
      n->mcost[0] = n->mcost[1] = n->cost;
      if(n->cs[0]) {
        push(n->cs[0]);
        n->mcost[0] = amin(n->cs[0]->mcost[0], n->mcost[0]);
        n->mcost[1] = amin(n->mcost[1], n->cs[0]->mcost[1]); }
      if(n->cs[1]) {
        push(n->cs[1]);
        n->mcost[0] = amin(n->mcost[0], n->cs[1]->mcost[0]);
        n->mcost[1] = amin(n->cs[1]->mcost[1], n->mcost[1]); }
    }
  }

  void rotate(node* n){
    li d = n->dir();
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

  pii path(node* x, node* y){
    evert(x);
    expose(y);
    push(y);
    return make_tuple(get<1>(amin(y->cs[0]->mcost[0], y->cost)), get<1>(amin(y->cost, y->cs[0]->mcost[1])));
  }

}




const li N = 3e5;

link_cut::node A[N];
link_cut::node E[N];

const li LN = 20;
li lparent[LN][N];
li depth[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n; cin>>n;
  vvi G(n),H(n);
  for(li i = 0; i < (li)(n); ++i) A[i] = link_cut::node(1e8, -1);
  vii ES(n-1);
  for(li i = 0; i < (li)(n-1); ++i) {
    li a,b; cin>>a>>b;
    --a;--b;
    G[a].push_back(b); G[b].push_back(a);
    ES[i] = make_tuple(a,b);
    E[i] = link_cut::node(0,i);
    link_cut::link(&A[a],&E[i]);
    link_cut::link(&A[b],&E[i]);
  }
  for(li i = 0; i < (li)(n-1); ++i) {
    li a,b; cin>>a>>b;
    --a;--b;
    H[a].push_back(b); H[b].push_back(a);
  }

  function<void(int,int,int)> dfs0 = [&](int i, int p, li dp){
    depth[i] = dp;
    lparent[0][i] = p;
    for(int j : G[i]) if(j != p) dfs0(j,i,dp+1);
  };
  dfs0(0,-1,0);
  for(li i = 0; i < (li)(LN-1); ++i)for(li j = 0; j < (li)(N); ++j) {
    lparent[i+1][j] = lparent[i][j] != -1 ? lparent[i][lparent[i][j]] : -1;
  }

  function<li(li,li)> dist = [&](li u, li v) {
    if(depth[u]<depth[v]) swap(u,v);
    li r = 0;
    for(li k = (LN-1); k >= (li)(0); --k) if(depth[u]-(1ll<<k) >= depth[v]) {
      u = lparent[k][u];
      r += (1ll<<k);
    }
    if(u == v) return r;
    for(li k = (LN-1); k >= (li)(0); --k) if(lparent[k][u] != lparent[k][v]) {
      r += 2*(1ll<<k);
      u=lparent[k][u];
      v=lparent[k][v];
    }
    return r+2;
  };

  cout << n-1 << endl;
  function<void(li,li)> dfs = [&](li i, li p) {
    for(li j : H[i]) if(j != p) {
      dfs(j,i);
    }
    if(p != -1) {
      li j,k; tie(j, k) = link_cut::path(&A[i],&A[p]);

      li a,b; tie(a,b) = ES[j];
      li c,d; tie(c,d) = ES[k];
      if(min(dist(a,i),dist(b,i)) < min(dist(c,i),dist(d,i))) {
        cout << a+1 << " " << b+1 << " " << i+1 << " " << p+1 << '\n';
        link_cut::expose(&E[j]);
        E[j].cost = make_tuple(1,j);
        link_cut::update(&E[j]);
      }else{
        cout << c+1 << " " << d+1 << " " << i+1 << " " << p+1 << '\n';
        link_cut::expose(&E[k]);
        E[k].cost = make_tuple(1,j);
        link_cut::update(&E[k]);
      }
    }
  };
  dfs(0,-1);
  cout << flush;

  return 0;
}