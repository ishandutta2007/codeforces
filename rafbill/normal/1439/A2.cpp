


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

bool A[100][100];

void solve(){
  int n,m; cin>>n>>m;
  int nm = n*m;
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) { char c; cin>>c; A[i][j] = (c=='1'); }
  vector<tuple<pii,pii,pii>> ans;
  for(li i = 0; i < (li)(n-2); ++i) {
    for(li j = 0; j < (li)(m-1); ++j) {
      if(A[i][j]) {
        if(A[i][j+1]) {
          A[i][j]^=1;
          A[i][j+1]^=1;
          A[i+1][j]^=1;
          ans.emplace_back(pii{i,j},pii{i,j+1},pii{i+1,j});
        }else{
          A[i][j]^=1;
          A[i+1][j]^=1;
          A[i+1][j+1]^=1;
          ans.emplace_back(pii{i,j},pii{i+1,j},pii{i+1,j+1});
        }
      }else{
        if(A[i][j+1]) {
          A[i][j+1]^=1;
          A[i+1][j]^=1;
          A[i+1][j+1]^=1;
          ans.emplace_back(pii{i,j+1},pii{i+1,j},pii{i+1,j+1});
        }
      }
    }
  }
  for(li i = (n-2); i <= (li)(n-2); ++i) {
    for(li j = 0; j < (li)(m-2); ++j) {
      if(A[i][j]) {
        if(A[i+1][j]) {
          A[i][j]^=1;
          A[i][j+1]^=1;
          A[i+1][j]^=1;
          ans.emplace_back(pii{i,j},pii{i,j+1},pii{i+1,j});
        }else{
          A[i][j]^=1;
          A[i][j+1]^=1;
          A[i+1][j+1]^=1;
          ans.emplace_back(pii{i,j},pii{i,j+1},pii{i+1,j+1});
        }
      }else{
        if(A[i+1][j]) {
          A[i][j+1]^=1;
          A[i+1][j]^=1;
          A[i+1][j+1]^=1;
          ans.emplace_back(pii{i,j+1},pii{i+1,j},pii{i+1,j+1});
        }
      }
    }
  }






  vii L,R;
  for(li i = (n-2); i <= (li)(n-1); ++i) for(li j = (m-2); j <= (li)(m-1); ++j) {
    if(A[i][j]) L.emplace_back(i,j);
    else R.emplace_back(i,j);
  }
  while(L.size() != 0) {
    if(L.size() == 1) {
      ans.emplace_back(L[0], R[1], R[2]);
      vii XL,XR;
      for(li k = 0; k < (li)(1); ++k) { XR.push_back(L.back()); L.pop_back(); }
      for(li k = 0; k < (li)(2); ++k) { XL.push_back(R.back()); R.pop_back(); }
      L.insert(end(L),begin(XL), end(XL));
      R.insert(end(R),begin(XR), end(XR));
    }
    if(L.size() == 2) {
      ans.emplace_back(L[1], R[0], R[1]);
      vii XL,XR;
      for(li k = 0; k < (li)(1); ++k) { XR.push_back(L.back()); L.pop_back(); }
      for(li k = 0; k < (li)(2); ++k) { XL.push_back(R.back()); R.pop_back(); }
      L.insert(end(L),begin(XL), end(XL));
      R.insert(end(R),begin(XR), end(XR));
    }
    if(L.size() == 3) {
      ans.emplace_back(L[0],L[1],L[2]);
      for(li k = 0; k < (li)(3); ++k) { R.push_back(L.back()); L.pop_back(); }
    }
    if(L.size() == 4) {
      ans.emplace_back(L[1],L[2],L[3]);
      for(li k = 0; k < (li)(3); ++k) { R.push_back(L.back()); L.pop_back(); }
    }
  }
  cout << ans.size() << endl;
  for(auto p : ans) {
    pii x,y,z; tie(x,y,z) = p;
    cout << (x^xx)+1 << ' ' << (x^yy)+1 << ' ';
    cout << (y^xx)+1 << ' ' << (y^yy)+1 << ' ';
    cout << (z^xx)+1 << ' ' << (z^yy)+1 << ' ';
    cout << '\n';
  }
  cout << flush;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int t; cin>>t;
  for(li i = 0; i < (li)(t); ++i)solve();

  return 0;
}