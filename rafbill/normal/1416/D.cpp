


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

struct union_find {
  vi A, S;
  vector<set<int>> V;
  vii H;

  union_find(li n = 0) : A(n), S(n, 1), V(n) {
    iota(begin(A), end(A), 0);
  }

  li find(li a) {
    return A[a] == a ? a : find(A[a]);
  }


  void merge(li a, li b) {

    H.emplace_back(a, b);
    A[a] = b;
    S[b] += S[a];
    for(int x : V[a]) V[b].insert(x);
  }

  void unmerge(li a, li b) {
    A[a] = a;
    S[b] -= S[a];
    vi R;
    for(int x : V[a]) {
      if(!V[b].count(x)) R.push_back(x);
      V[b].erase(x);
    }
    for(int x : R) V[a].erase(x);
  }

  void rollback(int to) {
    while((int)H.size() > to) {
      li a, b; tie(a, b) = H.back();
      unmerge(a, b);
      H.pop_back();
    }
  }

  void unite(li a, li b) {
    a = find(a); b = find(b);
    if(a != b) {
      if(S[a] < S[b]) {
        merge(a, b);
      }else{
        merge(b, a);
      }
    }
  }
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m,q; cin>>n>>m>>q;
  vi P(n); for(li i = 0; i < (li)(n); ++i) cin>>P[i];
  vii E(m);
  for(li i = 0; i < (li)(m); ++i) { li a, b; cin>>a>>b; --a; --b; E[i] = make_tuple(a,b); }
  vi live(m, 1);
  vi ty(q);
  vi Q(q);
  vi hat(q);
  for(li i = 0; i < (li)(q); ++i) {
    cin>>ty[i];
    if(ty[i] == 1) {
      cin>>Q[i]; Q[i]--;

    }else{
      cin>>Q[i]; Q[i]--;
      live[Q[i]] = 0;
    }
  }

  union_find uf(n);
  for(li i = 0; i < (li)(n); ++i) uf.V[i].insert(P[i]);
  for(li i = 0; i < (li)(m); ++i) if(live[i]) {
    li a,b; tie(a,b) = E[i];
    uf.unite(a,b);

  }

  for(li i = (q-1); i >= (li)(0); --i) {
    hat[i] = uf.H.size();
    if(ty[i] == 2) {
      li a, b; tie(a, b) = E[Q[i]];
      uf.unite(a, b);

    }
  }

  for(li i = 0; i < (li)(q); ++i) {
    if(ty[i] == 1) {
      li a = Q[i];
      a = uf.find(a);
      if(!uf.V[a].empty()) {
        li b = *uf.V[a].rbegin();
        uf.V[a].erase(b);
        cout << b << '\n';
      }else{
        cout << 0 << '\n';
      }
    }
    uf.rollback(hat[i]);
  }
  cout << flush;

  return 0;
}