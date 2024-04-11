


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


static struct {
  uint32_t x = 1, y = 2, z = 3, w = 4;

  inline void reset(uint32_t seed) {
    x = seed; y = seed+1; z = seed+2; w = seed+3;
  }

  inline uint32_t xorshift128() {
    uint32_t t = x;
    t ^= t << 11;
    t ^= t >> 8;
    x = y; y = z; z = w;
    w ^= w >> 19;
    w ^= t;
    return w;
  }
} xorshift128_s;

void random_reset(li seed = chrono::steady_clock::now().time_since_epoch().count()) { xorshift128_s.reset(seed); }

li random(li r) {
  return xorshift128_s.xorshift128()%r;
}

li random(li l, li r) {
  return l + random(r-l+1);
}

ld randomDouble() {
  return (ld)random(2147483648) / 2147483648.0;
}

bitset<60> G[60];
bitset<60> Y[60];
int from[60];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  random_reset();

  set<li> OPS;
  vector<tuple<char, li, li>> ans;
  auto add_xor = [&](li a, li b) {
    if(!OPS.count(a^b)) {



      OPS.insert(a^b); ans.emplace_back('^', a, b);
    }
  };

  auto add_plus = [&](li a, li b) {
    if(!OPS.count(a+b)) {



      OPS.insert(a+b); ans.emplace_back('+', a, b);
    }
  };

  for(li i = 0; i < (li)(60); ++i) G[i] = 0;
  auto add = [&](li x)-> bool {
    bitset<60> b(x);
    bitset<60> y(0);
    for(li i = 0; i < (li)(60); ++i) if(b[i]) {
      if(G[i][i]) {
        add_xor(b.to_ullong(), G[i].to_ullong());
        b ^= G[i];
      }else{
        G[i] = b;
        return true;
      }
    }
    return false;
  };

  li x; cin>>x;
  if(x%2 == 0) return 0;
  OPS.insert(x);
  add(x);
  add_xor(x, x);
  while(1) {
    bool ok = 1;
    bitset<60> b(1);
    bitset<60> y(0);
    for(li i = 0; i < (li)(60); ++i) if(b[i]) {
      if(G[i][i]) {
        add_xor(y.to_ullong(), G[i].to_ullong());
        b ^= G[i];
        y ^= G[i];
      }else{
        ok = 0;
        break;
      }
    }
    if(ok) {
      break;
    }

    while(1) {
      auto a = bitset<60>(random(1ll<<60));
      auto b = bitset<60>(random(1ll<<60));
      li av = 0; for(li i = 0; i < (li)(60); ++i) if(a[i] && G[i][i]) { add_xor(av, G[i].to_ullong()); av ^= G[i].to_ullong(); }
      li bv = 0; for(li i = 0; i < (li)(60); ++i) if(b[i] && G[i][i]) { add_xor(bv, G[i].to_ullong()); bv ^= G[i].to_ullong(); }
      add_plus(av, bv);
      if((av+bv) < (1ll<<60) && add(av+bv)) {
        break;
      }
    }
  }

  if(ans.size() > 100'000) {
    while(1) cout << "BAD" << endl;
  }
  cout << ans.size() << endl;
  for(auto p : ans) {
    char c; li a, b; tie(c, a, b) = p;
    cout << a << ' ' << c << ' ' << b << '\n';
  }
  cout << flush;


  return 0;
}