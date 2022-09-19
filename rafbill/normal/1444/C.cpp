


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

const int N = 555'555;
int link[N];
int color[N];
int sz[N];

vector<tuple<int,int>> Hlink, Hcolor, Hsz;

void set_link(int i, int x) {
  Hlink.emplace_back(i, link[i]);
  link[i] = x;
}

void set_color(int i, int x) {
  Hcolor.emplace_back(i, color[i]);
  color[i] = x;
}

void set_sz(int i, int x) {
  Hsz.emplace_back(i, sz[i]);
  sz[i] = x;
}

void resetH(){
  while(!Hlink.empty()) {
    int i,x; tie(i,x) = Hlink.back(); Hlink.pop_back();
    link[i] = x;
  }
  while(!Hcolor.empty()) {
    int i,x; tie(i,x) = Hcolor.back(); Hcolor.pop_back();
    color[i] = x;
  }
  while(!Hsz.empty()) {
    int i,x; tie(i,x) = Hsz.back(); Hsz.pop_back();
    sz[i] = x;
  }
}

void reset(int n) {
  for(li i = 0; i < (li)(n); ++i) {
    link[i] = i;
    color[i] = 0;
    sz[i] = 1;
  }
}

int find(int u) {
  if(u == link[u]) return u;
  int v = link[u];

  set_link(u, find(link[u]));

  set_color(u, color[u] ^ color[v]);
  return link[u];
}

bool unite(int u, int v) {
  int ru = find(u);
  int rv = find(v);
  if(ru != rv) {
    if(sz[ru] > sz[rv]) swap(ru,rv);
    set_link(ru, rv);
    set_color(ru, color[u]^1^color[v]);
    set_sz(rv, sz[ru]+sz[rv]);
    return 1;
  } else {
    return color[u] != color[v];
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  li n,m,k; cin>>n>>m>>k;
  reset(n);

  vi C(n);
  for(li i = 0; i < (li)(n); ++i) { cin>>C[i]; --C[i]; }
  vi E(k, 1);
  map<tuple<li, li>, vector<tuple<li,li>>> M;
  for(li m_ = 0; m_ < (li)(m); ++m_) {
    int u, v; cin>>u>>v;
    --u; --v;
    if(C[u] > C[v]) swap(u,v);
    if(C[u] == C[v]) {
      if(!unite(u, v)) E[C[u]] = 0;
    } else{
      M[make_tuple(C[u],C[v])].emplace_back(u,v);
    }
  }
  li nok = accumulate(begin(E), end(E), 0ll);

  for(li i = 0; i < (li)(n); ++i) find(i);

  li ans = nok * (nok-1) / 2;
  Hlink.clear(); Hcolor.clear(); Hsz.clear();
  for(auto const& p : M) {
    int cu, cv; tie(cu,cv) = p.first;
    if(!E[cu] || !E[cv]) continue;
    for(auto uv : p.second) {
      int u,v; tie(u,v) = uv;
      if(!unite(u,v)) {
        ans -= 1;
        break;
      }
    }
    resetH();
  }
  cout << ans << endl;

  return 0;
}