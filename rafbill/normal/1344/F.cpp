


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

const int N = 4000;
const int M = 12001;
int ix[N][3];



template<int N>
struct gauss {
  bitset<N> A[N];
  int V[N]; int nv=0;
  bitset<N> B[N];

  gauss() { reset(); }
  void reset() {

    for(li i = 0; i < (li)(N); ++i) A[i].reset();
    nv=0;
    for(li i = 0; i < (li)(N); ++i) B[i].reset();
  }


  void add(int id, bitset<N> x) {
    if(nv == N) return;
    bitset<N> y; y[nv]=1;
    for(li i = 0; i < (li)(N); ++i) if(x[i]) {
      if(A[i][i]) { x ^= A[i]; y ^= B[i]; }
      else { A[i] = x; V[nv++] = id; B[i] = y; return; }
    }
  }




  bool solve(bitset<N> x, bitset<N> &y){
    y.reset();
    for(li i = 0; i < (li)(N); ++i) if(x[i]&&A[i][i]) {
      x ^= A[i];
      y ^= B[i];
    }
    if(x.any()) return false;
    return true;
  }
};







gauss<M> G;
bool solve(vector<bitset<M> > M1, bitset<M> X, vi &Y) {
  Y.clear();
  for(li i = 0; i < (li)(M1.size()); ++i) {
    G.add(i, M1[i]);
  }
  bitset<M> y;
  if(!G.solve(X,y)) return false;
  for(li i = 0; i < (li)(N); ++i) if(y[i]) Y.push_back(G.V[i]);
  return true;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n, k; cin>>n>>k;

  vector<tuple<bitset<M>, bool>> V;

  for(li i = 0; i < (li)(n); ++i) {
    for(li j = 0; j < (li)(3); ++j) ix[i][j] = i*3+j;
    bitset<M> x = 0;
    for(li j = 0; j < (li)(3); ++j) x[ix[i][j]] = 1;
    V.emplace_back(x, 0);
  }

  for(li k_ = 0; k_ < (li)(k); ++k_) {
    string s; cin>>s;
    int m; cin>>m;
    vi A(m);
    for(li i = 0; i < (li)(m); ++i) { cin>>A[i]; A[i]--; }
    if(s == "mix") {
      char c; cin>>c;
      array<bool, 3> y;
      if(c == 'R') { y = {0,1,1}; }
      if(c == 'Y') { y = {1,0,1}; }
      if(c == 'B') { y = {1,1,0}; }
      if(c == 'W') { y = {0,0,0}; }
      for(li j = 0; j < (li)(3); ++j) {
        bitset<M> x = 0;
        for(int i : A) x[ix[i][j]] = 1;
        V.emplace_back(x, y[j]);
      }


    }else if(s == "RY") {
      for(auto i : A) swap(ix[i][0], ix[i][1]);
    }else if(s == "RB") {
      for(auto i : A) swap(ix[i][0], ix[i][2]);
    }else if(s == "YB") {
      for(auto i : A) swap(ix[i][1], ix[i][2]);
    }
  }

  vector<bitset<M> > VT(3*n);
  bitset<M> X;
  for(li i = 0; i < (li)(V.size()); ++i) {
    X[i] = get<1>(V[i]);
    for(li j = 0; j < (li)(3*n); ++j) {
      VT[j][i] = get<0>(V[i])[j];
    }
  }
  vi Y;
  if(solve(VT, X, Y)) {
    vector<int> Z(3*n);
    for(int i : Y) Z[i] = 1;
    cout << "YES" << endl;
    for(li i = 0; i < (li)(n); ++i) {
      if(Z[3*i+1] && Z[3*i+2]) cout << 'R';
      else if(Z[3*i+0] && Z[3*i+2]) cout << 'Y';
      else if(Z[3*i+0] && Z[3*i+1]) cout << 'B';
      else cout << '.';
    }
    cout << endl;
  }else{
    cout << "NO" << endl;
  }
;



  return 0;
}