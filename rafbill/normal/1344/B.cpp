


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

const int N = 1000;
bool A[N][N];
bool S[N][N];
int ES[N][N];

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
void fail(){
  cout << -1 << endl;
  exit(0);
}



struct union_find {
  vi A;

  union_find(li n = 0) : A(n) {
    iota(begin(A), end(A), 0);
  }

  li addNode() {
    A.push_back(A.size());
    return A.size()-1;
  }

  li find(li a) {
    return A[a] == a ? a : A[a] = find(A[a]);
  }

  void unite(li a, li b) {
    a = find(a); b = find(b);
    A[a] = b;
  }
};




int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m; cin>>n>>m;
  for(li i = 0; i < (li)(n); ++i) {
    for(li j = 0; j < (li)(m); ++j) {
      char c; cin>>c;
      A[i][j] = c == '#';
      S[i][j] = A[i][j];
    }
  }

  for(li i = 0; i < (li)(n); ++i) {
    int state = 0;
    bool ok = 1;
    for(li j = 0; j < (li)(m); ++j) {
      if(state == 0 && A[i][j]) state = 1;
      if(state == 1 && !A[i][j]) state = 2;
      if(state == 2 && A[i][j]) ok = 0;
    }
    if(!ok) for(li j = 0; j < (li)(m); ++j) S[i][j] = 0;
  }
  for(li j = 0; j < (li)(m); ++j) {
    int state = 0;
    bool ok = 1;
    for(li i = 0; i < (li)(n); ++i) {
      if(state == 0 && A[i][j]) state = 1;
      if(state == 1 && !A[i][j]) state = 2;
      if(state == 2 && A[i][j]) ok = 0;
    }
    if(!ok) for(li i = 0; i < (li)(n); ++i) S[i][j] = 0;
  }

  for(li i = 0; i < (li)(n); ++i) {
    bool e = 1;
    for(li j = 0; j < (li)(m); ++j) if(A[i][j]) e = 0;
    if(e) for(li j = 0; j < (li)(m); ++j) ES[i][j] += 1;
  }
  for(li j = 0; j < (li)(m); ++j) {
    bool e = 1;
    for(li i = 0; i < (li)(n); ++i) if(A[i][j]) e = 0;
    if(e) for(li i = 0; i < (li)(n); ++i) ES[i][j] += 1;
  }
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) if(ES[i][j] == 2) S[i][j] = 1;

  for(li i = 0; i < (li)(n); ++i) {
    bool e = 1;
    for(li j = 0; j < (li)(m); ++j) if(S[i][j]) e = 0;
    if(e) fail();
  }
  for(li j = 0; j < (li)(m); ++j) {
    bool e = 1;
    for(li i = 0; i < (li)(n); ++i) if(S[i][j]) e = 0;
    if(e) fail();
  }
  union_find uf(n*m);
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) if(A[i][j]) {
    for(li d = 0; d < (li)(4); ++d) {
      int i_=i+dx[d];
      int j_=j+dy[d];
      if(i_<0||j_<0||i_==n||j_==m) continue;
      if(A[i_][j_]) {
        uf.unite(i*m+j, i_*m+j_);
      }
    }
  }
  int ans = 0;
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) if(A[i][j] && uf.find(i*m+j) == i*m+j) ans++;
  cout << ans << endl;

  return 0;
}