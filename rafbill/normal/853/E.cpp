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

void readii(pii& p) { cin>>p.x()>>p.y(); }

using rational = double;
const rational EPS = 1e-9;

// struct rational {
//   rational() : x(0),y(1){ }
//   rational(lli a) : x(a), y(1){}
//   rational(lli a, lli b) {
//     lli g = __gcd(a,b);
//     a/=g; b/=g;
//     if(b<0) { a*=-1; b*=-1; }
//     x=a; y=b;
//   }
//   rational operator+(rational const& b) const {
//     return rational(x*b.y+y*b.x,y*b.y);
//   }
//   rational operator-(rational const& b) const {
//     return rational(x*b.y-y*b.x,y*b.y);
//   }
//   rational operator*(rational const& b) const {
//     return rational(x*b.x,y*b.y);
//   }
//   rational operator/(rational const& b) const {
//     return rational(x*b.y,y*b.x);
//   }
//   bool operator<(rational const& o) const {
//     return x*o.y<o.x*y;
//   }
//   bool operator<=(rational const& o) const {
//     return x*o.y<=o.x*y;
//   }

//   long double dbl() const { return (long double)x/(long double)y; }
//   lli x,y;
// };
// const rational EPS(0,1);

// ostream& operator<<(ostream& s, rational const& r) {
//   return s << r.x << "/" << r.y;
// }

struct BIT {
  vi A;
  BIT(lli n) : A(n+1){ }

  lli get(lli i){
    if(i<0) return 0;
    i += 1;
    lli r = 0;
    for(; i > 0; i -= i &-i){
      r += A[i];
    }
    return r;
  }

  lli getR(lli l, lli r) {
    lli ans = get(r);
    if(l) ans -= get(l-1);
    return ans;
  }

  void add(lli i, lli v){
    if(i<0) return;
    i += 1;
    for(; i < (lli)A.size(); i += i & -i){
      A[i] += v;
    }
  }
};

// --- END SNIPPET BINARY INDEXED TREE ---


const int N = 100000;
pii F[N];
lli A[N];
pii Q[N];
lli T[N];
lli ANS[N];

template<class T>
tpl<T,T> operator+(tpl<T,T> const& a, tpl<T,T> const& b) {
  return tpl<T,T>(a.x()+b.x(),a.y()+b.y());
}

template<class T>
tpl<T,T> operator-(tpl<T,T> const& a, tpl<T,T> const& b) {
  return tpl<T,T>(a.x()-b.x(),a.y()-b.y());
}

template<class T>
T dot(tpl<T,T> const& a, tpl<T,T> const& b) {
  return a.x()*b.x()+a.y()*b.y();
}

template<class T>
T det(tpl<T,T> const& a, tpl<T,T> const& b) {
  return a.x()*b.y()-a.y()*b.x();
}

lli ata[2][N];
lli atb[2][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  lli k,n,q; cin>>k>>n>>q;
  vector<tpl<rational,rational>> P;
  { vector<tpl<rational,rational>> P2;
    FOR(i,k) {
      lli x,y;
#ifdef LOCAL
      x=rand()%1000; y=rand()%1000;
#else
      cin>>x>>y;
#endif
      P2.pb(tpl<rational,rational>(2*x,2*y));
      P2.pb(tpl<rational,rational>(-2*x,-2*y));
    }
    // sort(all(P2), [&](auto const& a, auto const& b) { return atan2(a.y().dbl(),a.x().dbl())<atan2(b.y().dbl(),b.x().dbl()); });
    sort(all(P2), [&](auto const& a, auto const& b) { return atan2(a.y(),a.x())<atan2(b.y(),b.x()); });
    P.pb(mt(0,0));
    FOR(i,2*k-1) P.pb(P.back() + P2[i]);
    tpl<rational,rational> center;
    FOR(i,2*k) center = center + P[i];
    center.x() = center.x()/rational(P.size()); center.y() = center.y()/rational(P.size());
    FOR(i,2*k) P[i] = P[i] - center;
  }
  //
  map<pii,lli> XX;
  FOR(i,n) {
#ifdef LOCAL
    F[i] = mt(rand()%1000000,rand()%1000000); A[i] = 1+rand()%100;
#else
    readii(F[i]); cin>>A[i];
#endif
    XX[F[i]]+=A[i];
  }
  FOR(i,q) {
#ifdef LOCAL
    Q[i] = mt(rand()%1000000,rand()%1000000); T[i] = 1+rand()%5;
#else
    readii(Q[i]); cin>>T[i];
#endif
    ANS[i] += XX[Q[i]];
  }
  //
  FOR(k_,2*k) {
    auto p0 = P[k_], p1 = P[(k_+1)%(2*k)];
    auto dt = det(p0,p1);
    vector<tpl<rational,rational,rational,lli,lli>> pts;
    vector<tpl<rational,rational,rational,lli>> qs;
    vector<tpl<rational,rational,lli,lli>> pts2;
    vector<tpl<rational,rational,lli>> qs2;
    vector<tpl<rational,lli,lli> > as,bs;
    FOR(i,n) {
      rational a = (p1.y() * F[i].x() - p1.x() * F[i].y()) / dt;
      rational b = (p0.x() * F[i].y() - p0.y() * F[i].x()) / dt;
      as.pb(mt(a,0,i)); bs.pb(mt(b,1,i));
      pts.pb(mt(a+b,a,b,i,A[i]));
      pts2.pb(mt(a,b,i,A[i]));
    }
    FOR(i,q) {
      rational a = (p1.y() * Q[i].x() - p1.x() * Q[i].y()) / dt;
      rational b = (p0.x() * Q[i].y() - p0.y() * Q[i].x()) / dt;
      as.pb(mt(a,1,i)); bs.pb(mt(b,0,i));
      qs.pb(mt(a+b+T[i],a,b,i));
      qs2.pb(mt(a,b,i));
    }
    sort(all(as)); sort(all(bs));
    FOR(i,as.size()) ata[as[i].y()][as[i].z()]=i;
    FOR(i,bs.size()) atb[bs[i].y()][bs[i].z()]=i;

    // Sweep 1
    sort(all(pts)); sort(all(qs));
    lli pts_i = 0;
    lli allV = 0;
    BIT ta(as.size()+1), tb(bs.size()+1);
    for(auto const& ev : qs) {
      rational ab,a,b; lli i; tie(ab,a,b,i) = ev;
      while(pts_i<(lli)pts.size() && pts[pts_i].x() <= ab+EPS) {
        rational a,b; lli j,x; tie(ignore,a,b,j,x) = pts[pts_i];
        ta.add(ata[0][j],x);
        tb.add(atb[1][j],x);
        allV += x;
        pts_i++;
      }
      ANS[i] += allV;
      ANS[i] -= ta.get(ata[1][i]);
      ANS[i] -= tb.get(atb[0][i]);
    }
    // Sweep 2
    sort(all(pts2)); sort(all(qs2));
    pts_i = 0;
    BIT ts(bs.size()+1);
    for(auto const& ev : qs2) {
      rational a,b; lli i; tie(a,b,i) = ev;
      while(pts_i<(lli)pts2.size() && pts2[pts_i].x() <= a+EPS) {
        rational b; lli j,x; tie(ignore,b,j,x) = pts2[pts_i];
        ts.add(atb[1][j],x);
        pts_i++;
      }
      ANS[i] += ts.get(atb[0][i]);
    }
  }
  //
  FOR(i,q) cout << ANS[i] << '\n';
  cout << flush;
  exit(0);
  return 0;
}