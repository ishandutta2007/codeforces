


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

const int N = 3000;
li x[N], y[N];

li sgn(li x) {
  if(x == 0) return 0;
  if(x>0) return 1;
  return -1;
}

li det(li x1, li y1, li x2, li y2) { return x1*y2-x2*y1; }

bool cmp(li x1, li y1, li x2, li y2) {
  if(y1 == 0) {
    if(x1 > 0) return true;
    else return y2 > 0;
  }
  if(y2 == 0) {
    if(x2 > 0) return false;
    else return y1 < 0;
  }
  if(sgn(y1) != sgn(y2)) return sgn(y1)<sgn(y2);
  return det(x1,y1,x2,y2) < 0;
}

li f3(li x) {
  return x*(x-1)*(x-2)/6;
}

li f4(li x) {
  return x*(x-1)*(x-2)*(x-3)/24;
}


int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n; cin>>n;
  for(li i = 0; i < (li)(n); ++i) cin>>x[i]>>y[i];
  li ans = 0;

  for(li i = 0; i < (li)(n); ++i) {
    li lans = f4(n-1);
    using T = tuple<li,li,li,li>;
    vector<T> evs;
    for(li j = 0; j < (li)(n); ++j) if(j != i) { evs.emplace_back(j,0,x[j]-x[i],y[j]-y[i]); evs.emplace_back(j,1,x[i]-x[j],y[i]-y[j]); }
    sort(begin(evs), end(evs), [&](T const& a, T const &b) { return cmp(a^zz,a^ww,b^zz,b^ww); });
    vi S(2*n-1);
    vi L(n),R(n);
    for(li j = 0; j < (li)(2*n-2); ++j) {
      if((evs[j]^yy) == 0) { S[j+1] = S[j]+1; L[evs[j]^xx] = j; }
      else { S[j+1] = S[j]; R[evs[j]^xx] = j; }
    }
    for(li j = 0; j < (li)(n); ++j) if(i != j) {
      if(L[j]<R[j]) {
        li cnt = S[R[j]]-S[L[j]]-1;
        lans -= f3(cnt);
      } else {
        li cnt = (n-2)-(S[L[j]]-S[R[j]]);
        lans -= f3(cnt);
      }
    }
    ans += lans;
  }

  cout << ans << endl;

  return 0;
}