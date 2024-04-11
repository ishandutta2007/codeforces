


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

const int N = 100;
int A[N][N];
int B[N][N];
int KN[N][N];

int query_(int X[N][N], int i0, int j0, int i, int j) {
  if(X[i][j] != X[i0][j0]) return 0;
  if(X[i0+1][j0] == X[i0+1][j0+1]) return 1;
  if(X[i0][j0+1] == X[i0+1][j0+1]) return 1;
  if(X[i-1][j] == X[i-1][j-1]) return 1;
  if(X[i][j-1] == X[i-1][j-1]) return 1;
  return 0;
}
int query(int i0, int j0, int i, int j) {
  cout << "? " << (1+i0) << ' ' << (1+j0) << ' ' << (1+i) << ' ' << (1+j) << endl << flush;
  int x; cin>>x;
  return x;
}
int query2(int i0, int j0, int i, int j) {
  cout << "? " << (1+i0) << ' ' << (1+j0) << ' ' << (1+i) << ' ' << (1+j) << endl << flush;
  int x; cin>>x;
  return x;
}


int main(){
  srand(time(0));
  int n; cin>>n;
  A[0][0] = 1;
  A[n-1][n-1] = 0;

  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(n); ++j) if(make_tuple(i,j) != make_tuple(0,0) && make_tuple(i,j) != make_tuple(n-1,n-1) && (i+j)%2 == 0) {
    int i0 = i, j0 = j;
    if(i0 >= 2) i0 -= 2;
    else if(j0 >= 2) j0 -= 2;
    else { i0 -= 1; j0 -= 1; }
    A[i][j] = query(i0,j0,i,j);
    A[i][j] ^= A[i0][j0]^1;
  }

  KN[1][0] = 1;
  for(li kk = 0; kk < (li)(n); ++kk) for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(n); ++j) if(make_tuple(i,j) != make_tuple(0,0) && make_tuple(i,j) != make_tuple(n-1,n-1) && (i+j)%2 == 1) {
    auto test = [&](int i0, int j0) {
      if(KN[i][j]&&KN[i0][j0]) return;
      if(!KN[i][j]&&!KN[i0][j0]) return;

      int ok = query(i0,j0,i,j);
      if(KN[i0][j0]) {
        A[i][j] = ok^A[i0][j0]^1;
      }else if(KN[i][j]) {
        A[i0][j0] = ok^A[i][j]^1;
      }
      KN[i0][j0] = 1;
      KN[i][j] = 1;
    };
    if(i >= 2) test(i-2,j);
    if(j >= 2) test(i,j-2);
    if(i>=1&&j>=1) test(i-1,j-1);
  }

  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(n); ++j) {
    B[i][j]=A[i][j];
    if((i+j)%2==1) B[i][j]^=1;
  }

  bool isA = true;

  for(li i0 = 0; i0 < (li)(n-2); ++i0) for(li j0 = 0; j0 < (li)(n-1); ++j0) {
    if(query_(A,i0,j0,i0+2,j0+1) != query_(B,i0,j0,i0+2,j0+1)) {

      isA = query_(A,i0,j0,i0+2,j0+1) == query2(i0,j0,i0+2,j0+1);
      goto lend;
    }
  }
  for(li i0 = 0; i0 < (li)(n-1); ++i0) for(li j0 = 0; j0 < (li)(n-2); ++j0) {
    if(query_(A,i0,j0,i0+1,j0+2) != query_(B,i0,j0,i0+1,j0+2)) {
      isA = query_(A,i0,j0,i0+1,j0+2) == query2(i0,j0,i0+1,j0+2);
      goto lend;
    }
  }
  assert(false);

  lend:;
  cout << '!' << endl;
  if(isA) {
    for(li i = 0; i < (li)(n); ++i) {
      for(li j = 0; j < (li)(n); ++j) cout << A[i][j];
      cout << endl;
    }
  }else{
    for(li i = 0; i < (li)(n); ++i) {
      for(li j = 0; j < (li)(n); ++j) cout << B[i][j];
      cout << endl;
    }
  }

  return 0;
}