#ifndef __clang__
#pragma GCC optimize "-O3"
#pragma GCC target "tune=native"
#endif
#ifdef ONLINE_JUDGE
#define NDEBUG 1
#endif
#include <stdio.h>
#include <bits/stdc++.h>
using lli=long long int;
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

namespace std {
  namespace {
    template <class T>
    inline void hash_combine(size_t& seed, T const& v) {
      seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
    template <class Tuple, size_t Index = tuple_size<Tuple>::value - 1>
    struct HashValueImpl {
      static void apply(size_t& seed, Tuple const& tuple) {
        HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
        hash_combine(seed, get<Index>(tuple));
      }
    };
    template <class Tuple>
    struct HashValueImpl<Tuple, 0> {
      static void apply(size_t& seed, Tuple const& tuple) {
        hash_combine(seed, get<0>(tuple));
      }
    };
  }
  template <typename ... TT>
  struct hash<tuple<TT...>> {
    size_t operator()(tuple<TT...> const& tt) const {
      size_t seed = 0;
      HashValueImpl<tuple<TT...> >::apply(seed, tt);
      return seed;
    }
  };
  template <typename ... TT>
  struct hash<tpl<TT...>> {
    size_t operator()(tpl<TT...> const& tt) const {
      size_t seed = 0;
      HashValueImpl<tuple<TT...> >::apply(seed, tt);
      return seed;
    }
  };
}

//------------------------------------------------------------------------------

// --- BEGIN SNIPPET 2D SEGMENT TREE ---

struct s1d {
  struct node {
    node(){}
    lli value=0;
    int from=1e7, to=1e7;
  };
  lli n; vector<node> A;
  s1d(){}
  s1d(map<int,lli> const& data) : n(1ll<<((lli)(1+log2(data.size()+1)))) {
    while((n/2)>(lli)data.size()) n/=2;
    A.resize(2*n);
    lli cur=0;
    for(auto const& p:data){
      A[n+cur].value = p.second;
      A[n+cur].from = A[n+cur].to = p.first;
      cur++;
    }
    build();
  }
  void build(){
    FORD(i,n-1,1) update(i);
  }
  void update(lli i){
    A[i].value=A[2*i].value+A[2*i+1].value;
    A[i].from=A[2*i].from;
    A[i].to=A[2*i+1].to;
  }

  void add0(lli i, lli x, lli v) {
    if(A[i].from>x) return;
    if(A[i].to<x) return;
    A[i].value += v;
    if(i<n){
      add0(2*i,x,v);
      add0(2*i+1,x,v);
    }
  }
  void add(lli x,lli v){
    add0(1,x,v);
  }
  lli query0(lli i, lli x0, lli x1) {
    if(A[i].from>x1) return 0;
    if(A[i].to<x0) return 0;
    if(x0<=A[i].from && A[i].to <=x1) return A[i].value;
    return query0(2*i,x0,x1)+query0(2*i+1,x0,x1);
  }
  lli query(lli x0, lli x1) {
    return query0(1,x0,x1);
  }


};

struct s2d {
  struct node {
    node(){}
    map<int,lli> data;
    s1d value;
    int from=1e7, to=1e7;
  };
  lli n; vector<node> A;
  s2d(){}
  s2d(map<int,map<int,lli> > const& data) : n(1ll<<((lli)(1+log2(data.size()+1)))) {
    while((n/2)>(lli)(data.size())) n/=2;
    // while(n&&(n/4)>=(lli)data.size()) n/=2;
    A.resize(2*n);
    lli cur=0;
    for(auto const& p:data){
      A[n+cur].data = p.second;
      A[n+cur].value = s1d(p.second);
      A[n+cur].from = A[n+cur].to = p.first;
      cur++;
    }
    build();
  }
  void build(){
    FORD(i,n-1,1) {
      update(i);
    }
    A[1].data.clear();
  }
  void update(lli i){
    A[i].data=A[2*i].data;
    for(auto p : A[2*i+1].data) { A[i].data[p.first]+=p.second; }
    A[2*i].data.clear();
    A[2*i+1].data.clear();
    A[i].value = s1d(A[i].data);
    A[i].from=A[2*i].from;
    A[i].to=A[2*i+1].to;
  }
  void add0(lli i, lli x, lli y, lli v) {
    if(A[i].from>x) return;
    if(A[i].to<x) return;
    A[i].value.add(y,v);
    if(i<n){
      add0(2*i,x,y,v);
      add0(2*i+1,x,y,v);
    }
  }
  void add(lli x, lli y, lli v){
    add0(1,x,y,v);
  }
  lli query0(lli i, lli x0, lli x1, lli y0, lli y1) {
    if(A[i].from>x1) return 0;
    if(A[i].to<x0) return 0;
    if(x0<=A[i].from && A[i].to <=x1) {
      return A[i].value.query(y0,y1);
    }
    return query0(2*i,x0,x1,y0,y1)+query0(2*i+1,x0,x1,y0,y1);
  }
  lli query(lli x0, lli x1, lli y0, lli y1) {
    return query0(1,x0,x1,y0,y1);
  }
};


// --- BEGIN SNIPPET TREAP ---

struct treap;
using treap_ptr = treap*;

struct treap {
  treap(lli x_) : l(0), r(0), heap(rand()*RAND_MAX+rand()), x(x_), size(1){ }
  treap_ptr l, r;
  lli heap;

  lli x;

  lli size;

  static lli get_size(treap_ptr a){ return a?a->size:0; }

  static void update(treap_ptr a){
    if(a){
      a->size = 1;
      if(a->l) a->size += a->l->size;
      if(a->r) a->size += a->r->size;
    }
  }

  static void push(treap_ptr){ }

  static treap_ptr merge(treap_ptr a, treap_ptr b){
    if(a == 0) return b;
    if(b == 0) return a;
    push(a); push(b);
    if(a->heap < b->heap){
      a->r = merge(a->r, b);
      update(a);
      return a;
    }else{
      b->l = merge(a, b->l);
      update(b);
      return b;
    }
  }

  static tpl<treap_ptr, treap_ptr> split_key(treap_ptr a, lli x){
    if(a == 0) return mt(nullptr, nullptr);
    push(a);
    if(x <= a->x){
      auto p = split_key(a->l, x);
      a->l = p.y();
      update(a);
      return mt(p.x(), a);
    }else{
      auto p = split_key(a->r, x);
      a->r = p.x();
      update(a);
      return mt(a, p.y());
    }
  }

  static tpl<treap_ptr, treap_ptr> split_pos(treap_ptr a, lli i){
    if(a == 0) return mt(nullptr, nullptr);
    push(a);
    if(i <= get_size(a->l)){
      auto p = split_pos(a->l, i);
      a->l = p.y();
      update(a);
      return mt(p.x(), a);
    }else{
      auto p = split_pos(a->r, i - get_size(a->l) - 1);
      a->r = p.x();
      update(a);
      return mt(a, p.y());
    }
  }

  static treap_ptr insert_key(treap_ptr a, lli x){
    auto p = split_key(a, x);
    return merge(merge(p.x(), new treap(x)), p.y());
  }

  static treap_ptr insert_pos(treap_ptr a, lli i, lli x){
    auto p = split_pos(a, i);
    return merge(merge(p.x(), new treap(x)), p.y());
  }

  static lli first_val(treap_ptr a) {
    assert(a);
    if(a->l) return first_val(a->l);
    return a->x;
  }

  static lli last_val(treap_ptr a) {
    assert(a);
    if(a->r) return last_val(a->r);
    return a->x;
  }

  static void iterate(treap_ptr a, function<void(lli)> f) {
    if(!a) return;
    iterate(a->l,f);
    f(a->x);
    iterate(a->r,f);
  }
};

// --- END SNIPPET TREAP ---


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli n,m; cin>>n>>m;
  map<int,map<int,lli>> data;
  vector<map<int,map<int,lli>>> segs(m+10);
  vi A(n);
#ifdef LOCAL
  FOR(i,n) A[i] = 1+(i%(n/2));
#else
  FOR(i,n) cin >> A[i];
#endif
  vi TL(n,0), TR(n,0);
  vector<tpl<lli,lli,lli>> QS;
  vector<treap_ptr> TS(n+10,nullptr);
  FOR(i,n) {
    lli x = A[i];
    TS[x] = treap::merge(TS[x], new treap(i));
  }
#ifdef LOCAL
  vector<lli> ANS2;
#endif
  FORU(i,1,m) {
    lli ty;
#ifdef LOCAL
    ty = 1+rand()%2;
#else
    cin>>ty;
#endif
    if(ty==1) {
      lli ix,x;
#ifdef LOCAL
      ix = 1+rand()%n; x = 1+rand()%n;
#else
      cin>>ix>>x;
#endif
      --ix;

      if(A[ix] != x) {
        { treap_ptr t0 = TS[A[ix]];
          auto p = treap::split_key(t0,ix);
          auto q = treap::split_pos(p.y(),1);
          if(p.x()) {
            lli y = treap::last_val(p.x());
            assert(y<ix);
            lli t = max(TR[y],TL[ix]);
            data[y][ix]=0;
            segs[t][y][ix] += (ix-y);
            segs[i][y][ix] -= (ix-y);
#ifdef LOCAL
            // cerr << "seg " << y << " " << ix << endl;
#endif
            TR[y]=i;
          }
          if(q.y()) {
            lli y = treap::first_val(q.y());
            assert(y>ix);
            lli t = max(TL[y],TR[ix]);
            data[ix][y]=0;
            segs[t][ix][y] += (y-ix);
            segs[i][ix][y] -= (y-ix);
#ifdef LOCAL
            // cerr << "seg " << ix << " " << y << endl;
#endif
            TL[y]=i;
          }
          TS[A[ix]] = treap::merge(p.x(),q.y());
        }
        { treap_ptr t1 = TS[x];
          auto p = treap::split_key(t1,ix);
          if(p.x() && p.y()){
            lli y0 = treap::last_val(p.x());
            lli y1 = treap::first_val(p.y());
            lli t = max(TR[y0],TL[y1]);
            data[y0][y1]=0;
            segs[t][y0][y1] += (y1-y0);
            segs[i][y0][y1] -= (y1-y0);
#ifdef LOCAL
            // cerr << "seg " << y0 << " " << y1 << endl;
#endif
            TR[y0]=TL[y1]=i;
          }
          TS[x] = treap::merge(p.x(), treap::merge(new treap(ix), p.y()));
        }
        TL[ix]=TR[ix]=i; A[ix]=x;
      }
    }else{
      lli l,r;
#ifdef LOCAL
      l = 1+rand()%n; r = 1+rand()%n; if(l>r) swap(l,r);
#else
      cin>>l>>r;
#endif
      --l; --r;
      QS.pb(mt(l,r,i));
#ifdef LOCAL
      vi last(n+10,-1);
      lli cur=0;
      FOR(i,n) {
        if(last[A[i]]>=l && i<=r) {
          cur += (lli)(i-last[A[i]]);
        }
        last[A[i]]=i;
      }
      ANS2.pb(cur);
#endif
    }
  }
  FOR(i,n+10) {
    lli last = -1;
    treap::iterate(TS[i], [&](lli y){
        if(last!=-1) {
          lli t = max(TR[last],TL[y]);
          data[last][y]=0;
          segs[t][last][y] += (y-last);
        }
        last=y;
      });
  }
  s2d st(data);
  vector<lli> ANS;
  lli lt=0;
  for(auto const& q : QS) {
    lli l,r,t; tie(l,r,t) = q;
    while(lt<=t) {
      for(auto const& p : segs[lt]) for(auto const& q : p.second) {
          st.add(p.first, q.first, q.second);
        }
      lt += 1;
    }
    ANS.pb(st.query(l,r,l,r));
  }
#ifdef LOCAL
  // cout << data << endl;
  cout << ANS << endl;
  // cout << ANS2 << endl;
  assert(ANS==ANS2);
  cout << "ok" << endl;
#else
  for(lli x : ANS) cout << x << '\n';
  cout << flush;
#endif

  return 0;
}