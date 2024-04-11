



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



using li = int;
using lu = unsigned;
using ld = double;






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

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

using vvvi = vector<vvi>;
using vvvii = vector<vvii>;
using vvviii = vector<vviii>;

int n,m,k;
vvvi E;
vvvi C;
vvviii G[6];
vvi IN[6];

piii find(int d, int x, int y, int z) {
  if(x<0||y<0||z<0||x>=n||y>=m||z>=k) return make_tuple(-1,-1,-1);
  int x2,y2,z2; tie(x2,y2,z2) = G[d][x][y][z];
  if(!E[x2][y2][z2]) {
    return G[d][x][y][z] = find(d,x+dx[d],y+dy[d],z+dz[d]);
  }else{
    return make_tuple(x2,y2,z2);
  }
}

void fail(){
  cout << -1 << endl;
  exit(0);
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m>>k;

  IN[0] = vvi(m,vi(k));
  IN[1] = vvi(m,vi(k));
  IN[2] = vvi(n,vi(k));
  IN[3] = vvi(n,vi(k));
  IN[4] = vvi(n,vi(m));
  IN[5] = vvi(n,vi(m));
  for(li i = 0; i < (li)(m); ++i) for(li j = 0; j < (li)(k); ++j) cin>>IN[0][i][j];
  for(li i = 0; i < (li)(m); ++i) for(li j = 0; j < (li)(k); ++j) cin>>IN[1][i][j];
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(k); ++j) cin>>IN[2][i][j];
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(k); ++j) cin>>IN[3][i][j];
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) cin>>IN[4][i][j];
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(m); ++j) cin>>IN[5][i][j];

  E = vvvi(n,vvi(m,vi(k, 1)));
  C = vvvi(n,vvi(m,vi(k, -1)));
  for(li d = 0; d < (li)(6); ++d) G[d] = vvviii(n,vviii(m,viii(k)));
  for(li d = 0; d < (li)(6); ++d) for(li x = 0; x < (li)(n); ++x) for(li y = 0; y < (li)(m); ++y) for(li z = 0; z < (li)(k); ++z) G[d][x][y][z] = make_tuple(x,y,z);

  vector<tuple<li,li,li,li,li>> Q;
  for(li y = 0; y < (li)(m); ++y) for(li z = 0; z < (li)(k); ++z) {
    if(IN[0][y][z] == 0) for(li x = 0; x < (li)(n); ++x) E[x][y][z] = 0;
    else Q.emplace_back(0,0,y,z,IN[0][y][z]);
  }
  for(li y = 0; y < (li)(m); ++y) for(li z = 0; z < (li)(k); ++z) {
    if(IN[1][y][z] == 0) for(li x = 0; x < (li)(n); ++x) E[x][y][z] = 0;
    else Q.emplace_back(1,n-1,y,z,IN[1][y][z]);
  }
  for(li x = 0; x < (li)(n); ++x) for(li z = 0; z < (li)(k); ++z) {
    if(IN[2][x][z] == 0) for(li y = 0; y < (li)(m); ++y) E[x][y][z] = 0;
    else Q.emplace_back(2,x,0,z,IN[2][x][z]);
  }
  for(li x = 0; x < (li)(n); ++x) for(li z = 0; z < (li)(k); ++z) {
    if(IN[3][x][z] == 0) for(li y = 0; y < (li)(m); ++y) E[x][y][z] = 0;
    else Q.emplace_back(3,x,m-1,z,IN[3][x][z]);
  }
  for(li x = 0; x < (li)(n); ++x) for(li y = 0; y < (li)(m); ++y) {
    if(IN[4][x][y] == 0) for(li z = 0; z < (li)(k); ++z) E[x][y][z] = 0;
    else Q.emplace_back(4,x,y,0,IN[4][x][y]);
  }
  for(li x = 0; x < (li)(n); ++x) for(li y = 0; y < (li)(m); ++y) {
    if(IN[5][x][y] == 0) for(li z = 0; z < (li)(k); ++z) E[x][y][z] = 0;
    else Q.emplace_back(5,x,y,k-1,IN[5][x][y]);
  }

  while(!Q.empty()) {
    int d,x,y,z,c; tie(d,x,y,z,c) = Q.back(); Q.pop_back();
    int x2,y2,z2; tie(x2,y2,z2) = find(d,x,y,z);
    if(x2 == -1) fail();
    assert(E[x2][y2][z2]);
    if(C[x2][y2][z2] == -1 || C[x2][y2][z2] == c) {
      C[x2][y2][z2] = c;
      continue;
    }
    E[x2][y2][z2] = 0; C[x2][y2][z2] = 0;
    Q.emplace_back(0,0,y2,z2, IN[0][y2][z2]);
    Q.emplace_back(1,n-1,y2,z2,IN[1][y2][z2]);
    Q.emplace_back(2,x2,0,z2, IN[2][x2][z2]);
    Q.emplace_back(3,x2,m-1,z2,IN[3][x2][z2]);
    Q.emplace_back(4,x2,y2,0, IN[4][x2][y2]);
    Q.emplace_back(5,x2,y2,k-1,IN[5][x2][y2]);
  }

  for(li x = 0; x < (li)(n); ++x) {
    for(li y = 0; y < (li)(m); ++y) {
      for(li z = 0; z < (li)(k); ++z) cout << max(0,C[x][y][z]) << ' ';
      cout << '\n';
    }
    cout << '\n';
  }
  cout << endl;

  return 0;
}