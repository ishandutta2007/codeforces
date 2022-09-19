


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

const int K = 16000;
const int HK = 8000;
bitset<K+1> dp[1001];
int from[1001][K+1];

tuple<vi,vi> knap(vi X) {
  sort(begin(X), end(X)); reverse(begin(X), end(X));
  int n = X.size();
  for(li i = 0; i < (li)(n+1); ++i) dp[i] = 0;
  dp[0][HK] = 1;
  for(li i = 0; i < (li)(n); ++i) {
    for(li j = 0; j < (li)(K+1); ++j) if(dp[i][j]) {
      if(j >= X[i]) { dp[i+1][j-X[i]] = 1; from[i+1][j-X[i]] = j; }
      if(j + X[i] <= K) { dp[i+1][j+X[i]] = 1; from[i+1][j+X[i]] = j; }
    }
  }
  if(!dp[n][HK]) return make_tuple(vi(),vi());
  int y = HK;
  vi L, R;
  for(li i = (n); i >= (li)(1); --i) {
    if(from[i][y] < y) {
      L.emplace_back(y - from[i][y]);
    }else{
      R.emplace_back(from[i][y] - y);
    }
    y = from[i][y];
  }
  return make_tuple(L,R);
}

void solve(){
  int h; cin>>h;
  vi A(h); for(li i = 0; i < (li)(h); ++i) cin>>A[i];
  int v; cin>>v;
  vi B(v); for(li i = 0; i < (li)(v); ++i) cin>>B[i];
  if(h != v) {
    cout << "NO" << '\n';
    return;
  }
  vi LA, RA; tie(LA, RA) = knap(A);
  vi LB, RB; tie(LB, RB) = knap(B);
  if(LA.empty() || LB.empty()) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << endl;
  if(LA.size() <= LB.size()) {
    int x=0,y=0;
    int l1 = LA.size();
    int l2 = LB.size()-l1;
    int l3 = RB.size();
    sort(begin(LA), end(LA), greater<li>());
    sort(begin(LB), end(LB), less<li>());
    sort(begin(RA), end(RA), greater<li>());
    sort(begin(RB), end(RB), less<li>());
    for(li i = 0; i < (li)(l1); ++i) {
      x += LA[i];
      cout << x << ' ' << y << '\n';
      y += LB[i];
      cout << x << ' ' << y << '\n';
    }
    for(li i = 0; i < (li)(l2); ++i) {
      x -= RA[i];
      cout << x << ' ' << y << '\n';
      y += LB[l1+i];
      cout << x << ' ' << y << '\n';
    }
    for(li i = 0; i < (li)(l3); ++i) {
      x -= RA[l2+i];
      cout << x << ' ' << y << '\n';
      y -= RB[i];
      cout << x << ' ' << y << '\n';
    }
  }else{
    int x=0,y=0;
    int l1 = LB.size();
    int l2 = LA.size()-l1;
    int l3 = RA.size();
    sort(begin(LB), end(LB), greater<li>());
    sort(begin(LA), end(LA), less<li>());
    sort(begin(RB), end(RB), greater<li>());
    sort(begin(RA), end(RA), less<li>());
    for(li i = 0; i < (li)(l1); ++i) {
      y += LB[i];
      cout << x << ' ' << y << '\n';
      x += LA[i];
      cout << x << ' ' << y << '\n';
    }
    for(li i = 0; i < (li)(l2); ++i) {
      y -= RB[i];
      cout << x << ' ' << y << '\n';
      x += LA[l1+i];
      cout << x << ' ' << y << '\n';
    }
    for(li i = 0; i < (li)(l3); ++i) {
      y -= RB[l2+i];
      cout << x << ' ' << y << '\n';
      x -= RA[i];
      cout << x << ' ' << y << '\n';
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int t; cin>>t;
  for(li i = 0; i < (li)(t); ++i)solve();

  return 0;
}