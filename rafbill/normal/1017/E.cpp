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

using pt = pii;
pt operator-(pt const& a, pt const& b) {
  return pt(a.x()-b.x(),a.y()-b.y());
}
lli dot(pt const& a, pt const& b) {
  return a.x()*b.x() + a.y()*b.y();
}
lli det(pt const& a, pt const& b) {
  return a.x()*b.y() - a.y()*b.x();
}

void add_point(vector<pt> &s, int sign, pt p) {
  while(s.size() >= 2 &&
        det((*(s.end()-2))-s.back(), p-s.back())*sign >= 0){
    s.pop_back();
  }
  s.push_back(p);
}

vector<pt> convex_hull(vector<pt> A){
  if (A.size() <= 2) return A;
  vector<pt> c[2];
  sort(A.begin(), A.end());
  FOR(i, 2) for(pt p : A) add_point(c[i], 2 * i - 1, p);
  c[0].insert(c[0].end(), c[1].rbegin() + 1, c[1].rend() - 1);
  return c[0];
}

using angle = tpl<pt,pt>;
#define SQ(x) ((x)*(x))
lli dist2(pt const& a, pt const& b) {
  return SQ(a.x()-b.x())+SQ(a.y()-b.y());
}

lli sgn(lli a) {
  if(a<0) return -1;
  if(a==0) return 0;
  if(a>0) return 1;
  assert(0);
}

#define PI 3.141592653589793
const long double eps = 1e-14;

bool angle_eq(angle const& aa, angle const& b) {
  pt p0,p1;
  pt q0,q1;
  tie(p0,p1) = aa;
  tie(q0,q1) = b;
  complex<long double> p0_(p0.x(),p0.y());
  complex<long double> p1_(p1.x(),p1.y());
  complex<long double> q0_(q0.x(),q0.y());
  complex<long double> q1_(q1.x(),q1.y());
  long double a = ::arg(p0_)-::arg(p1_)-::arg(q0_)+::arg(q1_);
  while(a<0) a += 2*PI;
  while(a>2*PI-eps) a -= 2*PI;
  return abs(a) <= eps;
}

using elem = tpl<angle,lli>;
bool elem_eq(elem const& a, elem const& b) {
  if(a.y() != b.y()) return false;
  return angle_eq(a.x(),b.x());
}

vector<tpl<angle,lli>> poly_sequence(vector<pt> const& A) {
  int n = A.size();
  vector<tpl<angle,lli>> V;
  FOR(i,n) {
    pt p = A[i];
    pt q0 = A[(i-1+n)%n];
    pt q1 = A[(i+1)%n];
    V.eb(mt(mt(q0-p,q1-p), dist2(p,q1)));
  }
  return V;
}

vi kmp_build(vector<elem> const& s){
  int n = s.size();
  vi T(n+1);
  T[0] = -1;
  FOR(i, n) {
    int b = T[i];
    while(b != -1 && !elem_eq(s[i], s[b])) b = T[b];
    T[i+1] = b+1;
  }
  return T;
}

int kmp_next(vector<elem> const& s, vi const& T, int i, elem x){
  while(i != -1 && !elem_eq(x, s[i])) i = T[i];
  return i+1;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m; cin>>n>>m;
  vector<pt> A,B;
  FOR(i,n) { lli x,y; cin>>x>>y; A.eb(x,y); }
  A = convex_hull(A);
  FOR(i,m) { lli x,y; cin>>x>>y; B.eb(x,y); }
  B = convex_hull(B);
  if((int)A.size() == (int)B.size()) {
    auto va = poly_sequence(A), vb = poly_sequence(B);
    auto T = kmp_build(va);
    int ST = 0;
    FOR(k,2) for(auto const& x : vb) {
      ST = kmp_next(va,T,ST,x);
      if(ST == (int)va.size()) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}