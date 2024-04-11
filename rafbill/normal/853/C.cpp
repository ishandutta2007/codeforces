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

using pii   = tpl<int, int>;
using piii  = tpl<int, int, int>;
using piiii = tpl<int, int, int, int>;
using vi    = vector<int>;
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

// struct s1d {
//   struct node {
//     node(){}
//     int value=0;
//     int from=1e17, to=1e17;
//   };
//   int n; vector<node> A;
//   s1d(){}
//   s1d(map<int,int> data) : n(1ll<<((int)(1+log2(data.size()+1)))) {
//     while(n&&(n/2)>=(int)data.size()) n/=2;
//     A.resize(2*n);
//     int cur=0;
//     for(auto const& p:data){

//       A[n+cur].value = p.second;
//       A[n+cur].from = A[n+cur].to = p.first;
//       cur++;
//     }
//     build();
//   }
//   void build(){
//     FORD(i,n-1,1) update(i);
//   }
//   void update(int i){
//     A[i].value=A[2*i].value+A[2*i+1].value;
//     A[i].from=A[2*i].from;
//     A[i].to=A[2*i+1].to;
//   }

//   void add0(int i, int x) {
//     if(A[i].from>x) return;
//     if(A[i].to<x) return;
//     A[i].value += 1;
//     if(i<n){
//       add0(2*i,x);
//       add0(2*i+1,x);
//     }
//   }
//   void add(int x){
//     add0(1,x);
//     assert(A[1].value>0);
//   }
//   int query0(int i, int x0, int x1) {
//     if(A[i].from>x1) return 0;
//     if(A[i].to<x0) return 0;
//     if(x0<=A[i].from && A[i].to <=x1) return A[i].value;
//     return query0(2*i,x0,x1)+query0(2*i+1,x0,x1);
//   }
//   int query(int x0, int x1) {
//     return query0(1,x0,x1);
//   }


// };

// struct s2d {
//   struct node {
//     node(){}
//     map<int,int> data;
//     s1d value;
//     int from=1e17, to=1e17;
//   };
//   int n; vector<node> A;
//   s2d(map<int,map<int,int> > &&data) : n(1ll<<((int)(1+log2(data.size()+1)))), A(2*n) {
//     int cur=0;
//     for(auto const& p:data){
//       A[n+cur].data = p.second;
//       A[n+cur].value = s1d(p.second);
//       A[n+cur].from = A[n+cur].to = p.first;
//       cur++;
//     }
//     build();
//   }
//   void build(){
//     FORD(i,n-1,1) {
//       update(i);
//     }
//   }
//   void update(int i){
//     A[i].data=A[2*i].data;
//     for(auto p : A[2*i+1].data) { A[i].data[p.first]+=p.second; }
//     A[2*i].data.clear();
//     A[2*i+1].data.clear();
//     A[i].value = s1d(A[i].data);
//     A[i].from=A[2*i].from;
//     A[i].to=A[2*i+1].to;
//   }
//   void add0(int i, int x, int y) {
//     if(A[i].from>x) return;
//     if(A[i].to<x) return;
//     A[i].value.add(y);
//     if(i<n){
//       add0(2*i,x,y);
//       add0(2*i+1,x,y);
//     }
//   }
//   void add(int x, int y){
//     add0(1,x,y);
//   }
//   int query0(int i, int x0, int x1, int y0, int y1) {
//     if(A[i].from>x1) return 0;
//     if(A[i].to<x0) return 0;
//     if(x0<=A[i].from && A[i].to <=x1) {
//       return A[i].value.query(y0,y1);
//     }
//     return query0(2*i,x0,x1,y0,y1)+query0(2*i+1,x0,x1,y0,y1);
//   }
//   int query(int x0, int x1, int y0, int y1) {
//     return query0(1,x0,x1,y0,y1);
//   }
// };

// --- END SNIPPET 2D SEGMENT TREE ---

// --- BEGIN SNIPPET WAVELET TREE ---

// DO NOT USE mi=(lo+hi)/2
#define WT_WITH_TOOGLE 0
struct wavelet_tree {
  int lo=0, hi=0;
  wavelet_tree *l = 0, *r = 0;
  vector<int> b;
#if WT_WITH_TOOGLE
  vector<int> ac;
  BIT         ab;
#endif

  wavelet_tree() = default;

  ~wavelet_tree(){
    if(l) delete l;
    if(r) delete r;
  }

  wavelet_tree(vector<int> A) : wavelet_tree(begin(A),end(A),*min_element(all(A)),*max_element(all(A))) { }
  wavelet_tree(vector<lli> A) : wavelet_tree(begin(A),end(A),*min_element(all(A)),*max_element(all(A))) { }

  template<typename IT>
  wavelet_tree(IT from, IT to, int lo_, int hi_) {
    lo=lo_; hi=hi_;
    int mi = lo + (hi-lo)/2;
    auto f = [&](int x) { return x <= mi; };
    b.reserve(distance(from,to)+1); b.pb(0);
    for(auto it = from; it != to; ++it) b.pb(b.back() + f(*it));
#if WT_WITH_TOOGLE
    ac.assign(distance(from,to)+1,1);
    ab = BIT(distance(from,to)+2); FOR(i,distance(from,to)) ab.add(1+i,f(*(from+i)));
#endif
    auto mit = stable_partition(from,to,f);
    if(lo == hi || from == to) return;
    l = new wavelet_tree(from,mit,lo,mi);
    r = new wavelet_tree(mit,to,mi+1,hi);
  }

  /*
   * tr.swap(i,A[i],A[i+1]); swap(A[i],A[i+1]) : swaps values at positions i and i+1
   */
  void swap(int i, int si, int sj) {
    if(si==sj) return;
    if(lo == hi) {
      return;
      assert(0);
    }else{
      int mi = lo + (hi-lo)/2;
      if(si<=mi&&sj<=mi){
#if WT_WITH_TOOGLE
        if(ac[i]&&!ac[i+1]) { ab.add(1+i,-1); ab.add(1+(i+1),1); }
        else if(!ac[i]&&ac[i+1]) { ab.add(1+i,1); ab.add(1+(i+1),-1); }
        ::swap(ac[i],ac[i+1]);
#endif
        l->swap(b[i],si,sj);
      }else if(si>mi&&sj>mi){
#if WT_WITH_TOOGLE
        ::swap(ac[i],ac[i+1]);
#endif
        r->swap(i-b[i],si,sj);
      }else if(si<=mi){
#if WT_WITH_TOOGLE
        if(ac[i]) { ab.add(1+i,-1); ab.add(1+(i+1),1); }
        ::swap(ac[i],ac[i+1]);
#endif
        b[i+1] -= 1;
      }else{
#if WT_WITH_TOOGLE
        if(ac[i+1]){ ab.add(1+(i+1),-1); ab.add(1+i, 1); }
        ::swap(ac[i],ac[i+1]);
#endif
        b[i+1] += 1;
      }
    }
  }

  /*
   * tr.toogle(i,A[i]) : toogles value at position i
   */
#if WT_WITH_TOOGLE
  void toogle(int i, int si) {
    ac[i] ^= 1;
    if(ac[i]) ab.add(1+i,1);
    else ab.add(1+i,-1);
    if(lo==hi) {
    }else{
      int mi = lo + (hi-lo)/2;
      if(si<=mi){
        l->toogle(b[i],si);
      }else{
        r->toogle(i-b[i],si);
      }
    }
  }
#endif

  /*
   * kth(l,r,k) : k-th value of sorted subsequence A[l]...A[r]
   */
  int kth(int l, int r, int k) {
    assert(l <= r);
    assert(k < r-l+1);
    if(lo == hi) return lo;
#if WT_WITH_TOOGLE
    int inleft = ab.getR(l+1,r+1);
#else
    int inleft = b[r+1]-b[l];
#endif
    if(k < inleft) return this->l->kth(b[l],b[r+1]-1,k);
    else return this->r->kth(l-b[l],r-b[r+1],k-inleft);
  }

  /*
   * cnt(l,r,y) : number of occurences of y in A[l]..A[r]
   */
  int cnt(int l, int r, int y) {
    if(l>r) return 0;
    if(lo == hi) {
      if(lo == y) {
#if WT_WITH_TOOGLE
        return ab.getR(1+l,1+r);
#else
        return b[r+1]-b[l];
#endif
      }else{
        return 0;
      }
    }else{
      int mi = lo + (hi-lo)/2;
      if(y<=mi) {
        return this->l->cnt(b[l],b[r+1]-1,y);
      }else{
        return this->r->cnt(l-b[l],r-b[r+1],y);
      }
    }
  }

  int allR(int l, int r) {
    if(l>r) return 0;
    return r-l+1;
  }

  int cntR(int l, int r, int y) {
    if(l>r) return 0;
    if(hi<=y) return r-l+1;
    if(y<lo) return 0;
    int mi = lo + (hi-lo)/2;
    if(y<=mi) {
      return this->l->cntR(b[l],b[r+1]-1,y);
    }else{
      return this->l->allR(b[l],b[r+1]-1)+this->r->cntR(l-b[l],r-b[r+1],y);
    }
  }

};

// --- END SNIPPET WAVELET TREE ---

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q; cin>>n>>q;
  map<int,map<int,int>> data;
  vi ps;
  FOR(i,n) {
    int p; cin>>p;
    // data[i+1][p] = 1;
    ps.pb(p-1);
  }
  wavelet_tree wt(ps);
  auto q0 = [&](int x, int y) -> int {
    if(x<0||y<0) return 0;
    return wt.cntR(0,x,y);
  };
  auto query = [&](int x1,int y1,int x2,int y2) -> int {
    if(x2<x1) return 0;
    if(y2<y1) return 0;
    return wt.cntR(x1,x2,y2) - (y1==0?0:wt.cntR(x1,x2,y1-1));
  };
  // s2d tr(move(data));
  set<tpl<int,int,int,int>> ss;
  FOR(i,3) FOR(j,3) FOR(i2,3) FOR(j2,3) if(mt(i,j)!=mt(i2,j2)){
    if((i<=1&&1<=i2)||(i2<=1&&1<=i)) {
      if((j<=1&&1<=j2)) {
        if(!ss.count(mt(i2,j2,i,j)))
          ss.insert(mt(i,j,i2,j2));
      }
    }
  }
  FOR(q_,q) {
    int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
    --x1; --y1; --x2; --y2;
    int T[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    FOR(i,3) { FOR(j,3) {
        int a,b,c,d;
        if(i==0) { a=0; b=x1-1; }
        if(i==1) { a=x1; b=x2; }
        if(i==2) { a=x2+1; b=n-1; }
        if(j==0) { c=0; d=y1-1; }
        if(j==1) { c=y1; d=y2; }
        if(j==2) { c=y2+1; d=n-1; }
        T[i][j] = query(a,c,b,d);
      }
    }
    lli inside = T[1][1];
    lli ans = (inside*(inside-1))/2;
    for(auto s:ss) {
      int i,j,i2,j2;
      tie(i,j,i2,j2)=s;
      ans += (lli)((lli)T[i][j]*(lli)T[i2][j2]);
    }

    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}